
/* EMAX5 library                        */
/*         Copyright (C) 2013- by NAIST */
/*          Primary writer: Y.Nakashima */
/*                 nakashim@is.naist.jp */

volatile struct emax_info {
  Ull  reg_phys;     // kern-phys
  Ull  reg_vadr;     // not used
  Ull  reg_mmap;     // user-virt Contiguous 256K register space
  Ull  hpp_phys;     // kern-phys
  Ull  hpp_vadr;     // not used
  Ull  hpp_mmap;     // user-virt Contiguous 2GB space in high-2GB space
  Ull  acp_phys;     // kern-phys
  Ull  acp_vadr;     // not used
  Ull  acp_mmap;     // user-virt Contiguous 4MB space in low-2GB space
	             // 0x1fffff-0x000000: for conf[ 8KB] * 256sets
	             // 0x2fffff-0x200000: for lmmi[ 4KB] * 1set
        	     // 0x3fffff-0x300000: for regv[16KB] * 1set
  int driver_use_1;
  int driver_use_2;
} emax_info;

volatile Ull  acp_conf;                   /* acp_mmap+0x000000+8KB*i (L1miss*1回のためACPでOK) */
volatile Ull  acp_lmmi;                   /* acp_mmap+0x200000        L1=32KB */
volatile Ull  acp_regv;                   /* acp_mmap+0x304000        L1=32KB */
volatile struct {
  int v;   /* 0:acp_conf is empty, 1:copied from text to acp_conf */
  Ull top; /* conf_address in text-segment */
} acp_conf_tab[ACP_CONF_MAX];

#define ACP_BASE2_PHYS	 0x4fc00000
/*  ... for ARMSIML only */

#ifdef ARMZYNQ
/*******************************************************************************/
/******************************** ZYNQ-COMMON **********************************/
/*******************************************************************************/

#include <linux/ioctl.h>
#define EMAX_DEVNAME "/dev/emax5_zynq_drv"
int emax_fd;

struct emax_ioctlbuf {
  Ull phys_addr;
  Ull virt_addr;
} emax_ioctlbuf;

#define REG_BASE_PHYS	 0x0000000080000000LL
/*  ... fixed */
#define REG_BASE_SIZE	 0x0000000000040000LL
/*  ... 256KB */
#define HPP_BASE_PHYS	 0x0000000800000000LL
/*  ... fixed */
#define HPP_BASE_SIZE	 0x0000000080000000LL
/*  ... 2GB   */
#define ACP_BASE_SIZE	 0x0000000000400000LL
/*  ... 4MB   */

#define EXI_S_ADDR_RESET 0x0000000000030000LL
#define EXI_S_ADDR_CONF  0x0000000000030010LL
#define EXI_S_ADDR_LMMI  0x0000000000030018LL
#define EXI_S_ADDR_REGV  0x0000000000030020LL
#define EXI_S_ADDR_OFFS  0x0000000000030028LL
#define EXI_S_ADDR_MODE  0x0000000000030030LL
#define EXI_S_ADDR_STAT  0x0000000000030040LL

#define EMAX_IOC_MAGIC  60
/* Please use a different 8-bit number in your code */
#define EMAX_IORESET			_IO( EMAX_IOC_MAGIC, 0)
#define EMAX_GET_ACPMEM			_IOWR(EMAX_IOC_MAGIC,  1, unsigned long)
#define EMAX_IOC_MAXNR 2

emax5_open()
/* HPMを経由する制御レジスタにリセット送出 */
/* HPPを経由する画像メモリを仮想空間に写像 */
/* ACPを経由するconf/lmmi/regv空間を仮想空間に写像 */
{
  if ((emax_fd = open(EMAX_DEVNAME, O_RDWR|O_SYNC )) == -1) {
    printf("emax_open(): Invalid EMAX_DEVNAME: '%s'\n", EMAX_DEVNAME);
    return (NULL);
  }

  // mmap(cache-off) 4KB aligned
  emax_info.reg_phys = REG_BASE_PHYS;
  emax_info.reg_mmap = (Ull)mmap(0,REG_BASE_SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,emax_fd,REG_BASE_PHYS);
  *(Ull*)(emax_info.reg_mmap+EXI_S_ADDR_MODE)  = 0LL; // ★★★ CLEAR COMMAND
  *(Ull*)(emax_info.reg_mmap+EXI_S_ADDR_RESET) = 1LL; // ★★★ RESET EMAX5

  // mmap(cache-off) 4KB aligned
  emax_info.hpp_phys = HPP_BASE_PHYS;
  emax_info.hpp_mmap = (Ull)mmap(0,HPP_BASE_SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,emax_fd,HPP_BASE_PHYS);

  // mmap(cache-on)  4KB aligned
  emax_ioctlbuf.phys_addr = 0x0; // phys
  emax_ioctlbuf.virt_addr = 0x0; // virt
  ioctl(emax_fd, EMAX_GET_ACPMEM, &emax_ioctlbuf);//in driver:virt=(Ull*)kmalloc(ACP_MEM_SIZE(<=4MB),GFP_KERNEL);
  emax_info.acp_phys = emax_ioctlbuf.phys_addr;   //in driver:phys=(Ull)virt_to_phys(buf);
  emax_info.acp_mmap = (Ull)mmap(0,ACP_BASE_SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,emax_fd,emax_ioctlbuf.phys_addr);

  return (emax_fd);
}
#endif

/*******************************************************************************/
/******************************** EMAX5-START **********************************/
/*******************************************************************************/

/* lmmwb=0: if lmm never be written back to DDR */
emax5_start_with_keep_cache(Ull conf, Ull lmmi, Ull regv)
{
#ifdef ARMSIML
  emax_start_with_keep_cache(conf, lmmi, regv); /* start syscall EMAX5 */
#endif
#ifdef ARMZYNQ
  volatile Ull emax_status;

  *(Ull*)(emax_info.reg_mmap+EXI_S_ADDR_CONF) = emax_info.acp_phys+(conf-emax_info.acp_mmap);
  *(Ull*)(emax_info.reg_mmap+EXI_S_ADDR_LMMI) = emax_info.acp_phys+(lmmi-emax_info.acp_mmap);
  *(Ull*)(emax_info.reg_mmap+EXI_S_ADDR_REGV) = emax_info.acp_phys+(regv-emax_info.acp_mmap);
  *(Ull*)(emax_info.reg_mmap+EXI_S_ADDR_OFFS) = emax_info.hpp_phys - emax_info.hpp_mmap;
  *(Ull*)(emax_info.reg_mmap+EXI_S_ADDR_MODE) = 1LL;
  do {
    emax_status = *(Ull*)(emax_info.reg_mmap+EXI_S_ADDR_STAT);
  } while (emax_status != STATUS_IDLE);
#endif
}

/* lmmwb=1: if lmm may   be written back to DDR */
emax5_start_with_drain_cache(Ull conf, Ull lmmi, Ull regv)
{
#ifdef ARMSIML
  emax_start_with_drain_cache(conf, lmmi, regv); /* start syscall EMAX5 */
#endif
#ifdef ARMZYNQ
  volatile Ull emax_status;

  *(Ull*)(emax_info.reg_mmap+EXI_S_ADDR_CONF) = emax_info.acp_phys+(conf-emax_info.acp_mmap);
  *(Ull*)(emax_info.reg_mmap+EXI_S_ADDR_LMMI) = emax_info.acp_phys+(lmmi-emax_info.acp_mmap);
  *(Ull*)(emax_info.reg_mmap+EXI_S_ADDR_REGV) = emax_info.acp_phys+(regv-emax_info.acp_mmap);
  *(Ull*)(emax_info.reg_mmap+EXI_S_ADDR_OFFS) = emax_info.hpp_phys - emax_info.hpp_mmap;
  *(Ull*)(emax_info.reg_mmap+EXI_S_ADDR_MODE) = 1LL;
  do {
    emax_status = *(Ull*)(emax_info.reg_mmap+EXI_S_ADDR_STAT);
  } while (emax_status != STATUS_IDLE);
#endif
}

emax5_drain_dirty_lmm()
{
#ifdef ARMSIML
  emax_drain_dirty_lmm(); /* start syscall EMAX5 */
#endif
#ifdef ARMZYNQ
  volatile Ull emax_status;

  *(Ull*)(emax_info.reg_mmap+EXI_S_ADDR_OFFS) = emax_info.hpp_phys - emax_info.hpp_mmap;
  *(Ull*)(emax_info.reg_mmap+EXI_S_ADDR_MODE) = 2LL;
  do {
    emax_status = *(Ull*)(emax_info.reg_mmap+EXI_S_ADDR_STAT);
  } while (emax_status != STATUS_IDLE);
#endif
}

/*******************************************************************************/
/******************************** EMAX5 NCLIB (no conv-c2b)*********************/
/*******************************************************************************/

#define ad(a,b)   ((a)<(b)?(b)-(a):(a)-(b))
#define ss(a,b)   ((a)<(b)?   0   :(a)-(b))

void __attribute__((always_inline))
cex(Uint op_cx, Ull *ex, Ull c3, Ull c2, Ull c1, Ull c0, Ushort pattern)
{
  Uint index1, index0;

  switch (op_cx) {
  case OP_NOP:
    if (ex)
      *ex = 3; /* for bsim */
    break;
  case OP_CEXE:
    index1 = ((c3>>1&1)<<3)|((c2>>1&1)<<2)|((c1>>1&1)<<1)|(c0>>1&1);
    index0 = ((c3   &1)<<3)|((c2   &1)<<2)|((c1   &1)<<1)|(c0   &1);
    *ex = 0;
    if (pattern>>index1&1) *ex |= 2;
    if (pattern>>index0&1) *ex |= 1;
    break;
  default:
    printf("emax5lib: cex: undefined op_cx=%d\n", op_cx);
    break;
  }  
}

void __attribute__((always_inline))
ex4(Uint op_ex1, Ull *d, Ull *r1, Uint exp1, Ull *r2, Uint exp2, Ull *r3, Uint exp3, Uint op_ex2, Ull *r4, Uint op_ex3, Ull *r5)
{
  switch (op_ex1) {
  case OP_NOP:
  case OP_FMA:  /* 32bit*2 3in floating-point r1+r2*r3 */
  case OP_FAD:  /* 32bit*2 2in floating-point r1+r2 */
  case OP_FML:  /* 32bit*2 2in floating-point r1*r2 */
  case OP_ADD3: /* 32bit*2 3in fixed-point r1+(r2+r3) */
  case OP_SUB3: /* 32bit*2 3in fixed-point r1-(r2+r3) */
  case OP_ADD:  /* 32bit*2 2in fixed-point r1+r2 */
  case OP_SUB:  /* 32bit*2 2in fixed-point r1-r2 */
    break;
  default:
    printf("emax5lib: ex4: undefined op_ex1=%d\n", op_ex1);
    break;
  }

  exe(op_ex1, (d+0), *(r1+0), exp1, *(r2+0), exp2, *(r3+0), exp3, OP_NOP, 0LL, OP_NOP, 0LL);
  exe(op_ex1, (d+1), *(r1+1), exp1, *(r2+1), exp2, *(r3+1), exp3, OP_NOP, 0LL, OP_NOP, 0LL);
  exe(op_ex1, (d+2), *(r1+2), exp1, *(r2+2), exp2, *(r3+2), exp3, OP_NOP, 0LL, OP_NOP, 0LL);
  exe(op_ex1, (d+3), *(r1+3), exp1, *(r2+3), exp2, *(r3+3), exp3, OP_NOP, 0LL, OP_NOP, 0LL);

  switch (op_ex2) {
  case OP_NOP:
    break;
  default:
    printf("emax5lib: ex4: illegal op_ex2=%d\n", op_ex2);
    break;
  }

  switch (op_ex3) {
  case OP_NOP:
    break;
  default:
    printf("emax5lib: ex4: illegal op_ex3=%d\n", op_ex3);
    break;
  }
}

int __attribute__((always_inline))
exe(Uint op_ex1, Ull *d, Ull r1, Uint exp1, Ull r2, Uint exp2, Ull r3, Uint exp3, Uint op_ex2, Ull r4, Uint op_ex3, Ull r5)
{
  /* return 0:normal, 1:OP_WHILE breaks */
  union { Uint i; float f; } f3, f2, f1, f0;
  Ull t3, t2, t1, t0;
  Ull c1, c0;
  Ull ex1_outd;
  Ull ex2_outd;
  int retval = 0;

  switch (exp1) {
  case EXP_H3210:                                                                    break;
  case EXP_B7632: r1 = (r1>>8&0x00ff000000ff0000LL) | (r1>>16&0x000000ff000000ffLL); break;
  case EXP_B5410: r1 = (r1<<8&0x00ff000000ff0000LL) | (r1    &0x000000ff000000ffLL); break;
  }
  switch (exp2) {
  case EXP_H3210:                                                                    break;
  case EXP_B7632: r2 = (r2>>8&0x00ff000000ff0000LL) | (r2>>16&0x000000ff000000ffLL); break;
  case EXP_B5410: r2 = (r2<<8&0x00ff000000ff0000LL) | (r2    &0x000000ff000000ffLL); break;
  }
  switch (exp3) {
  case EXP_H3210:                                                                    break;
  case EXP_B7632: r3 = (r3>>8&0x00ff000000ff0000LL) | (r3>>16&0x000000ff000000ffLL); break;
  case EXP_B5410: r3 = (r3<<8&0x00ff000000ff0000LL) | (r3    &0x000000ff000000ffLL); break;
  }

  switch (op_ex1) {
  case OP_NOP:
    ex1_outd = r1;
    break;
  case OP_WHILE: /* emax5ncのlibとしては使用せず,bsim/emax5.cがsimlに使用 */
#if 1
    t0 = (r1&0x00000000ffffffffLL)+(r2&0x00000000ffffffffLL);
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = t0;
    if (t0==0) retval = 1;
#endif
    break;
  case OP_FMA: /* 32bit*2 3in floating-point r1+r2*r3 */
    /* *(double*)&ex1_outd = *(double*)&r1 + (*(double*)&r2 * *(double*)&r3);*/
    f1.i = (Uint)(r1>>32);
    f2.i = (Uint)(r2>>32);
    f3.i = (Uint)(r3>>32);
    f0.f = f1.f + (f2.f * f3.f);
    t2 = f0.i;
    f1.i = (Uint)(r1);
    f2.i = (Uint)(r2);
    f3.i = (Uint)(r3);
    f0.f = f1.f + (f2.f * f3.f);
    t0 = f0.i;
    ex1_outd = (t2<<32)|(t0);
    break;
  case OP_FAD: /* 32bit*2 3in floating-point r1+r2 */
    /* *(double*)&ex1_outd = *(double*)&r1 + *(double*)&r2;*/
    f1.i = (Uint)(r1>>32);
    f2.i = (Uint)(r2>>32);
    f0.f = f1.f + f2.f;
    t2 = f0.i;
    f1.i = (Uint)(r1);
    f2.i = (Uint)(r2);
    f0.f = f1.f + f2.f;
    t0 = f0.i;
    ex1_outd = (t2<<32)|(t0);
    break;
  case OP_FML: /* 32bit*2 3in floating-point r1*r2 */
    /* *(double*)&ex1_outd = *(double*)&r1 * *(double*)&r2;*/
    f1.i = (Uint)(r1>>32);
    f2.i = (Uint)(r2>>32);
    f0.f = f1.f * f2.f;
    t2 = f0.i;
    f1.i = (Uint)(r1);
    f2.i = (Uint)(r2);
    f0.f = f1.f * f2.f;
    t0 = f0.i;
    ex1_outd = (t2<<32)|(t0);
    break;
  case OP_ADD3: /* 32bit*2 3in integer add s1+(s2+s3) */
    t2 = (r1>>32&0x00000000ffffffffLL)+((r2>>32&0x00000000ffffffffLL)+(r3>>32&0x00000000ffffffffLL));
    t2 &= 0x00000000ffffffffLL;
    t0 = (r1    &0x00000000ffffffffLL)+((r2    &0x00000000ffffffffLL)+(r3    &0x00000000ffffffffLL));
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = (t2<<32)|(t0);
    break;
  case OP_SUB3: /* 32bit*2 3in integer subtract s1-(s2+s3) */
    t2 = (r1>>32&0x00000000ffffffffLL)-((r2>>32&0x00000000ffffffffLL)+(r3>>32&0x00000000ffffffffLL));
    t2 &= 0x00000000ffffffffLL;
    t0 = (r1    &0x00000000ffffffffLL)-((r2    &0x00000000ffffffffLL)+(r3    &0x00000000ffffffffLL));
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = (t2<<32)|(t0);
    break;
  case OP_ADD: /* 32bit*2 2in integer add s1+s2 */
    t2 = (r1>>32&0x00000000ffffffffLL)+(r2>>32&0x00000000ffffffffLL);
    t2 &= 0x00000000ffffffffLL;
    t0 = (r1    &0x00000000ffffffffLL)+(r2    &0x00000000ffffffffLL);
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = (t2<<32)|(t0);
    break;
  case OP_SUB: /* 32bit*2 2in integer subtract s1-s2 */
    t2 = (r1>>32&0x00000000ffffffffLL)-(r2>>32&0x00000000ffffffffLL);
    t2 &= 0x00000000ffffffffLL;
    t0 = (r1    &0x00000000ffffffffLL)-(r2    &0x00000000ffffffffLL);
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = (t2<<32)|(t0);
    break;
  case OP_CMP_EQ: /* 32bit*2 2in compare and set 1*2bit-CC */
    c1 = (r1>>32&0x00000000ffffffffLL) == (r2>>32&0x00000000ffffffffLL);
    c0 = (r1    &0x00000000ffffffffLL) == (r2    &0x00000000ffffffffLL);
    ex1_outd = (c1<<1)|c0;
    break;
  case OP_CMP_NE: /* 32bit*2 2in compare and set 1*2bit-CC */
    c1 = (r1>>32&0x00000000ffffffffLL) != (r2>>32&0x00000000ffffffffLL);
    c0 = (r1    &0x00000000ffffffffLL) != (r2    &0x00000000ffffffffLL);
    ex1_outd = (c1<<1)|c0;
    break;
  case OP_CMP_LT: /* 32bit*2 2in compare and set 1*2bit-CC */
    c1 = (r1>>32&0x00000000ffffffffLL) < (r2>>32&0x00000000ffffffffLL);
    c0 = (r1    &0x00000000ffffffffLL) < (r2    &0x00000000ffffffffLL);
    ex1_outd = (c1<<1)|c0;
    break;
  case OP_CMP_LE: /* 32bit*2 2in compare and set 1*2bit-CC */
    c1 = (r1>>32&0x00000000ffffffffLL) <= (r2>>32&0x00000000ffffffffLL);
    c0 = (r1    &0x00000000ffffffffLL) <= (r2    &0x00000000ffffffffLL);
    ex1_outd = (c1<<1)|c0;
    break;
  case OP_CMP_GT: /* 32bit*2 2in compare and set 1*2bit-CC */
    c1 = (r1>>32&0x00000000ffffffffLL) > (r2>>32&0x00000000ffffffffLL);
    c0 = (r1    &0x00000000ffffffffLL) > (r2    &0x00000000ffffffffLL);
    ex1_outd = (c1<<1)|c0;
    break;
  case OP_CMP_GE: /* 32bit*2 2in compare and set 1*2bit-CC */
    c1 = (r1>>32&0x00000000ffffffffLL) >= (r2>>32&0x00000000ffffffffLL);
    c0 = (r1    &0x00000000ffffffffLL) >= (r2    &0x00000000ffffffffLL);
    ex1_outd = (c1<<1)|c0;
    break;
  case OP_CMOV: /* 32bit*2 3in 2bit conditional move */
    c1 = r1>>1&1;
    c0 = r1   &1;
    t2 = c1 ? (r2&0xffffffff00000000LL) : (r3&0xffffffff00000000LL);
    t0 = c0 ? (r2&0x00000000ffffffffLL) : (r3&0x00000000ffffffffLL);
    ex1_outd = t2 | t0;
    break;
  case OP_CCAT: /* 32bit 2in s1<<32|s2 concatenate */
    ex1_outd = (r1<<32)|(r2);
    break;
  case OP_MAUH3: /* 16bit*4 3in r1.pos+(r2.pos+r3.pos) */
    t3 = (r1>>48&0x000000000000ffffLL)+((r2>>48&0x000000000000ffffLL)+(r3>>48&0x000000000000ffffLL));
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t2 = (r1>>32&0x000000000000ffffLL)+((r2>>32&0x000000000000ffffLL)+(r3>>32&0x000000000000ffffLL));
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t1 = (r1>>16&0x000000000000ffffLL)+((r2>>16&0x000000000000ffffLL)+(r3>>16&0x000000000000ffffLL));
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    t0 = (r1    &0x000000000000ffffLL)+((r2    &0x000000000000ffffLL)+(r3    &0x000000000000ffffLL));
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case OP_MAUH: /* 16bit*4 2in r1.pos+r2.pos */
    t3 = (r1>>48&0x000000000000ffffLL)+(r2>>48&0x000000000000ffffLL);
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t2 = (r1>>32&0x000000000000ffffLL)+(r2>>32&0x000000000000ffffLL);
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t1 = (r1>>16&0x000000000000ffffLL)+(r2>>16&0x000000000000ffffLL);
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    t0 = (r1    &0x000000000000ffffLL)+(r2    &0x000000000000ffffLL);
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case OP_MSUH3: /* 16bit*4 3in r1.pos-(r2.pos+r3.pos) */
    t3 = (r1>>48&0x000000000000ffffLL)-((r2>>48&0x000000000000ffffLL)+(r3>>48&0x000000000000ffffLL));
    if (t3 > 0x000000000000ffffLL) t3 = 0x0000000000000000LL;
    t2 = (r1>>32&0x000000000000ffffLL)-((r2>>32&0x000000000000ffffLL)+(r3>>32&0x000000000000ffffLL));
    if (t2 > 0x000000000000ffffLL) t2 = 0x0000000000000000LL;
    t1 = (r1>>16&0x000000000000ffffLL)-((r2>>16&0x000000000000ffffLL)+(r3>>16&0x000000000000ffffLL));
    if (t1 > 0x000000000000ffffLL) t1 = 0x0000000000000000LL;
    t0 = (r1    &0x000000000000ffffLL)-((r2    &0x000000000000ffffLL)+(r3    &0x000000000000ffffLL));
    if (t0 > 0x000000000000ffffLL) t0 = 0x0000000000000000LL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case OP_MSUH: /* 16bit*4 2in r1.pos-r2.pos */
    t3 = (r1>>48&0x000000000000ffffLL)-(r2>>48&0x000000000000ffffLL);
    if (t3 > 0x000000000000ffffLL) t3 = 0x0000000000000000LL;
    t2 = (r1>>32&0x000000000000ffffLL)-(r2>>32&0x000000000000ffffLL);
    if (t2 > 0x000000000000ffffLL) t2 = 0x0000000000000000LL;
    t1 = (r1>>16&0x000000000000ffffLL)-(r2>>16&0x000000000000ffffLL);
    if (t1 > 0x000000000000ffffLL) t1 = 0x0000000000000000LL;
    t0 = (r1    &0x000000000000ffffLL)-(r2    &0x000000000000ffffLL);
    if (t0 > 0x000000000000ffffLL) t0 = 0x0000000000000000LL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case OP_MLUH: /* (11bit*4)*9bit r1.pos*r2.pos */
    t3 = (r1>>48&0x00000000000007ffLL)*(r2&0x00000000000001ffLL);
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t2 = (r1>>32&0x00000000000007ffLL)*(r2&0x00000000000001ffLL);
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t1 = (r1>>16&0x00000000000007ffLL)*(r2&0x00000000000001ffLL);
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    t0 = (r1    &0x00000000000007ffLL)*(r2&0x00000000000001ffLL);
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case OP_MMRG: /* 8bit*2 3in r1.b4|r2.b4|r3.b4|0->w1, r1.b0|r2.b0|r3.b0|0->w0 */
    ex1_outd = ((r1&0x000000ff00000000LL)<<24) | ((r2&0x000000ff00000000LL)<<16) | ((r3&0x000000ff00000000LL)<<8)
             | ((r1&0x00000000000000ffLL)<<24) | ((r2&0x00000000000000ffLL)<<16) | ((r3&0x00000000000000ffLL)<<8);
    break;
  case OP_MSSAD: /* 16bit*4 8bit*8 2in r1.h3+df(r2.b7,r3.b7)+df(r2.b6,r3.b6)->d.h3
                                       r1.h2+df(r2.b5,r3.b5)+df(r2.b4,r3.b4)->d.h2
                                       r1.h1+df(r2.b3,r3.b3)+df(r2.b2,r3.b2)->d.h1
                                       r1.h0+df(r2.b1,r3.b1)+df(r2.b0,r3.b0)->d.h0 */
    t3 = (r1>>48&0x000000000000ffffLL) + ad(r2>>56&0x00000000000000ffLL, r3>>56&0x00000000000000ffLL) + ad(r2>>48&0x00000000000000ffLL, r3>>48&0x00000000000000ffLL);
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t2 = (r1>>32&0x000000000000ffffLL) + ad(r2>>40&0x00000000000000ffLL, r3>>40&0x00000000000000ffLL) + ad(r2>>32&0x00000000000000ffLL, r3>>32&0x00000000000000ffLL);
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t1 = (r1>>16&0x000000000000ffffLL) + ad(r2>>24&0x00000000000000ffLL, r3>>24&0x00000000000000ffLL) + ad(r2>>16&0x00000000000000ffLL, r3>>16&0x00000000000000ffLL);
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    t0 = (r1    &0x000000000000ffffLL) + ad(r2>> 8&0x00000000000000ffLL, r3>> 8&0x00000000000000ffLL) + ad(r2    &0x00000000000000ffLL, r3    &0x00000000000000ffLL);
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case OP_MSAD: /* 16bit*4 8bit*8 2in df(r1.b7,r2.b7)+df(r1.b6,r2.b6)->d.h3
                                      df(r1.b5,r2.b5)+df(r1.b4,r2.b4)->d.h2
                                      df(r1.b3,r2.b3)+df(r1.b2,r2.b2)->d.h1
                                      df(r1.b1,r2.b1)+df(r1.b0,r2.b0)->d.h0 */
    t3 = ad(r1>>56&0x00000000000000ffLL, r2>>56&0x00000000000000ffLL) + ad(r1>>48&0x00000000000000ffLL, r2>>48&0x00000000000000ffLL);
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t2 = ad(r1>>40&0x00000000000000ffLL, r2>>40&0x00000000000000ffLL) + ad(r1>>32&0x00000000000000ffLL, r2>>32&0x00000000000000ffLL);
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t1 = ad(r1>>24&0x00000000000000ffLL, r2>>24&0x00000000000000ffLL) + ad(r1>>16&0x00000000000000ffLL, r2>>16&0x00000000000000ffLL);
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    t0 = ad(r1>> 8&0x00000000000000ffLL, r2>> 8&0x00000000000000ffLL) + ad(r1    &0x00000000000000ffLL, r2    &0x00000000000000ffLL);
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case OP_MINL3: /* 16bit*4 3in (r3.h3<r3.h2)?r1.h3|r3.h3:r2.h3|r3.h2->d.w1
                                (r3.h1<r3.h0)?r1.h1|r3.h1:r2.h1|r3.h0->d.w0 */
    t3 = r3>>48&0x000000000000ffffLL;
    t2 = r3>>32&0x000000000000ffffLL;
    t1 = r3>>16&0x000000000000ffffLL;
    t0 = r3    &0x000000000000ffffLL;
    if (t3<t2) t2 = (r1&0xffff000000000000LL)|(r3>>16&0x0000ffff00000000LL);
    else       t2 = (r2&0xffff000000000000LL)|(r3    &0x0000ffff00000000LL);
    if (t1<t0) t0 = (r1&0x00000000ffff0000LL)|(r3>>16&0x000000000000ffffLL);
    else       t0 = (r2&0x00000000ffff0000LL)|(r3    &0x000000000000ffffLL);
    ex1_outd = t2 | t0;
    break;
  case OP_MINL: /* 16bit*4 2in (r1.h2<r2.h2)?r1.w1:r2.w1->d.w1
	                       (r1.h0<r2.h0)?r1.w0:r2.w0->d.w0 */
    if ((r1&0x0000ffff00000000LL)<(r2&0x0000ffff00000000LL)) t2 = r1&0xffffffff00000000LL;
    else                                                     t2 = r2&0xffffffff00000000LL;
    if ((r1&0x000000000000ffffLL)<(r2&0x000000000000ffffLL)) t0 = r1&0x00000000ffffffffLL;
    else                                                     t0 = r2&0x00000000ffffffffLL;
    ex1_outd = t2 | t0;
   break;
  case OP_MH2BW: /* 16bit*4 2in r1.b6|r1.b4|r2.b6|r2.b4|r1.b2|r1.b0|r2.b2|r2.b0 */
    ex1_outd = (((r1>>48&0x000000000000ff00LL) ? 255 : (r1>>48&0x00000000000000ffLL))<<56)
             | (((r1>>32&0x000000000000ff00LL) ? 255 : (r1>>32&0x00000000000000ffLL))<<48)
             | (((r2>>48&0x000000000000ff00LL) ? 255 : (r2>>48&0x00000000000000ffLL))<<40)
             | (((r2>>32&0x000000000000ff00LL) ? 255 : (r2>>32&0x00000000000000ffLL))<<32)
             | (((r1>>16&0x000000000000ff00LL) ? 255 : (r1>>16&0x00000000000000ffLL))<<24)
             | (((r1    &0x000000000000ff00LL) ? 255 : (r1    &0x00000000000000ffLL))<<16)
             | (((r2>>16&0x000000000000ff00LL) ? 255 : (r2>>16&0x00000000000000ffLL))<< 8)
             | (((r2    &0x000000000000ff00LL) ? 255 : (r2    &0x00000000000000ffLL))    );
    break;
  case OP_MCAS: /* 16bit*2 2in (r1.h2<r2.h2)?0:0xff->d.b1
                               (r1.h0<r2.h0)?0:0xff->d.b0 */
    t2 = ((r1&0x0000ffff00000000LL)<(r2&0x0000ffff00000000LL))?0:0x000000000000ff00LL;
    t0 = ((r1&0x000000000000ffffLL)<(r2&0x000000000000ffffLL))?0:0x00000000000000ffLL;
    ex1_outd = t2 | t0;
    break;
  case OP_MMID3: /* 8bit*8 3in bytewise compare and output middle */
    t1 = ((r1&0xff00000000000000LL)<(r2&0xff00000000000000LL)?(r1&0xff00000000000000LL):(r2&0xff00000000000000LL))
       | ((r1&0x00ff000000000000LL)<(r2&0x00ff000000000000LL)?(r1&0x00ff000000000000LL):(r2&0x00ff000000000000LL))
       | ((r1&0x0000ff0000000000LL)<(r2&0x0000ff0000000000LL)?(r1&0x0000ff0000000000LL):(r2&0x0000ff0000000000LL))
       | ((r1&0x000000ff00000000LL)<(r2&0x000000ff00000000LL)?(r1&0x000000ff00000000LL):(r2&0x000000ff00000000LL))
       | ((r1&0x00000000ff000000LL)<(r2&0x00000000ff000000LL)?(r1&0x00000000ff000000LL):(r2&0x00000000ff000000LL))
       | ((r1&0x0000000000ff0000LL)<(r2&0x0000000000ff0000LL)?(r1&0x0000000000ff0000LL):(r2&0x0000000000ff0000LL))
       | ((r1&0x000000000000ff00LL)<(r2&0x000000000000ff00LL)?(r1&0x000000000000ff00LL):(r2&0x000000000000ff00LL))
       | ((r1&0x00000000000000ffLL)<(r2&0x00000000000000ffLL)?(r1&0x00000000000000ffLL):(r2&0x00000000000000ffLL));
    t2 = ((r1&0xff00000000000000LL)>(r2&0xff00000000000000LL)?(r1&0xff00000000000000LL):(r2&0xff00000000000000LL))
       | ((r1&0x00ff000000000000LL)>(r2&0x00ff000000000000LL)?(r1&0x00ff000000000000LL):(r2&0x00ff000000000000LL))
       | ((r1&0x0000ff0000000000LL)>(r2&0x0000ff0000000000LL)?(r1&0x0000ff0000000000LL):(r2&0x0000ff0000000000LL))
       | ((r1&0x000000ff00000000LL)>(r2&0x000000ff00000000LL)?(r1&0x000000ff00000000LL):(r2&0x000000ff00000000LL))
       | ((r1&0x00000000ff000000LL)>(r2&0x00000000ff000000LL)?(r1&0x00000000ff000000LL):(r2&0x00000000ff000000LL))
       | ((r1&0x0000000000ff0000LL)>(r2&0x0000000000ff0000LL)?(r1&0x0000000000ff0000LL):(r2&0x0000000000ff0000LL))
       | ((r1&0x000000000000ff00LL)>(r2&0x000000000000ff00LL)?(r1&0x000000000000ff00LL):(r2&0x000000000000ff00LL))
       | ((r1&0x00000000000000ffLL)>(r2&0x00000000000000ffLL)?(r1&0x00000000000000ffLL):(r2&0x00000000000000ffLL));
    ex1_outd = ((r3&0xff00000000000000LL)<(t1&0xff00000000000000LL)?(t1&0xff00000000000000LL):((r3&0xff00000000000000LL)<(t2&0xff00000000000000LL)?(r3&0xff00000000000000LL):(t2&0xff00000000000000LL)))
             | ((r3&0x00ff000000000000LL)<(t1&0x00ff000000000000LL)?(t1&0x00ff000000000000LL):((r3&0x00ff000000000000LL)<(t2&0x00ff000000000000LL)?(r3&0x00ff000000000000LL):(t2&0x00ff000000000000LL)))
             | ((r3&0x0000ff0000000000LL)<(t1&0x0000ff0000000000LL)?(t1&0x0000ff0000000000LL):((r3&0x0000ff0000000000LL)<(t2&0x0000ff0000000000LL)?(r3&0x0000ff0000000000LL):(t2&0x0000ff0000000000LL)))
             | ((r3&0x000000ff00000000LL)<(t1&0x000000ff00000000LL)?(t1&0x000000ff00000000LL):((r3&0x000000ff00000000LL)<(t2&0x000000ff00000000LL)?(r3&0x000000ff00000000LL):(t2&0x000000ff00000000LL)))
             | ((r3&0x00000000ff000000LL)<(t1&0x00000000ff000000LL)?(t1&0x00000000ff000000LL):((r3&0x00000000ff000000LL)<(t2&0x00000000ff000000LL)?(r3&0x00000000ff000000LL):(t2&0x00000000ff000000LL)))
             | ((r3&0x0000000000ff0000LL)<(t1&0x0000000000ff0000LL)?(t1&0x0000000000ff0000LL):((r3&0x0000000000ff0000LL)<(t2&0x0000000000ff0000LL)?(r3&0x0000000000ff0000LL):(t2&0x0000000000ff0000LL)))
             | ((r3&0x000000000000ff00LL)<(t1&0x000000000000ff00LL)?(t1&0x000000000000ff00LL):((r3&0x000000000000ff00LL)<(t2&0x000000000000ff00LL)?(r3&0x000000000000ff00LL):(t2&0x000000000000ff00LL)))
             | ((r3&0x00000000000000ffLL)<(t1&0x00000000000000ffLL)?(t1&0x00000000000000ffLL):((r3&0x00000000000000ffLL)<(t2&0x00000000000000ffLL)?(r3&0x00000000000000ffLL):(t2&0x00000000000000ffLL)));
    break;
  case OP_MMAX3: /* 8bit*8 3in bytewise compare and output maximum */
    t1 = ((r1&0xff00000000000000LL)>(r2&0xff00000000000000LL)?(r1&0xff00000000000000LL):(r2&0xff00000000000000LL))
       | ((r1&0x00ff000000000000LL)>(r2&0x00ff000000000000LL)?(r1&0x00ff000000000000LL):(r2&0x00ff000000000000LL))
       | ((r1&0x0000ff0000000000LL)>(r2&0x0000ff0000000000LL)?(r1&0x0000ff0000000000LL):(r2&0x0000ff0000000000LL))
       | ((r1&0x000000ff00000000LL)>(r2&0x000000ff00000000LL)?(r1&0x000000ff00000000LL):(r2&0x000000ff00000000LL))
       | ((r1&0x00000000ff000000LL)>(r2&0x00000000ff000000LL)?(r1&0x00000000ff000000LL):(r2&0x00000000ff000000LL))
       | ((r1&0x0000000000ff0000LL)>(r2&0x0000000000ff0000LL)?(r1&0x0000000000ff0000LL):(r2&0x0000000000ff0000LL))
       | ((r1&0x000000000000ff00LL)>(r2&0x000000000000ff00LL)?(r1&0x000000000000ff00LL):(r2&0x000000000000ff00LL))
       | ((r1&0x00000000000000ffLL)>(r2&0x00000000000000ffLL)?(r1&0x00000000000000ffLL):(r2&0x00000000000000ffLL));
    ex1_outd = ((t1&0xff00000000000000LL)>(r3&0xff00000000000000LL)?(t1&0xff00000000000000LL):(r3&0xff00000000000000LL))
             | ((t1&0x00ff000000000000LL)>(r3&0x00ff000000000000LL)?(t1&0x00ff000000000000LL):(r3&0x00ff000000000000LL))
             | ((t1&0x0000ff0000000000LL)>(r3&0x0000ff0000000000LL)?(t1&0x0000ff0000000000LL):(r3&0x0000ff0000000000LL))
             | ((t1&0x000000ff00000000LL)>(r3&0x000000ff00000000LL)?(t1&0x000000ff00000000LL):(r3&0x000000ff00000000LL))
             | ((t1&0x00000000ff000000LL)>(r3&0x00000000ff000000LL)?(t1&0x00000000ff000000LL):(r3&0x00000000ff000000LL))
             | ((t1&0x0000000000ff0000LL)>(r3&0x0000000000ff0000LL)?(t1&0x0000000000ff0000LL):(r3&0x0000000000ff0000LL))
             | ((t1&0x000000000000ff00LL)>(r3&0x000000000000ff00LL)?(t1&0x000000000000ff00LL):(r3&0x000000000000ff00LL))
             | ((t1&0x00000000000000ffLL)>(r3&0x00000000000000ffLL)?(t1&0x00000000000000ffLL):(r3&0x00000000000000ffLL));
    break;
  case OP_MMIN3: /* 8bit*8 3in bytewise compare and output minimum */
    t1 = ((r1&0xff00000000000000LL)<(r2&0xff00000000000000LL)?(r1&0xff00000000000000LL):(r2&0xff00000000000000LL))
       | ((r1&0x00ff000000000000LL)<(r2&0x00ff000000000000LL)?(r1&0x00ff000000000000LL):(r2&0x00ff000000000000LL))
       | ((r1&0x0000ff0000000000LL)<(r2&0x0000ff0000000000LL)?(r1&0x0000ff0000000000LL):(r2&0x0000ff0000000000LL))
       | ((r1&0x000000ff00000000LL)<(r2&0x000000ff00000000LL)?(r1&0x000000ff00000000LL):(r2&0x000000ff00000000LL))
       | ((r1&0x00000000ff000000LL)<(r2&0x00000000ff000000LL)?(r1&0x00000000ff000000LL):(r2&0x00000000ff000000LL))
       | ((r1&0x0000000000ff0000LL)<(r2&0x0000000000ff0000LL)?(r1&0x0000000000ff0000LL):(r2&0x0000000000ff0000LL))
       | ((r1&0x000000000000ff00LL)<(r2&0x000000000000ff00LL)?(r1&0x000000000000ff00LL):(r2&0x000000000000ff00LL))
       | ((r1&0x00000000000000ffLL)<(r2&0x00000000000000ffLL)?(r1&0x00000000000000ffLL):(r2&0x00000000000000ffLL));
    ex1_outd = ((t1&0xff00000000000000LL)<(r3&0xff00000000000000LL)?(t1&0xff00000000000000LL):(r3&0xff00000000000000LL))
             | ((t1&0x00ff000000000000LL)<(r3&0x00ff000000000000LL)?(t1&0x00ff000000000000LL):(r3&0x00ff000000000000LL))
             | ((t1&0x0000ff0000000000LL)<(r3&0x0000ff0000000000LL)?(t1&0x0000ff0000000000LL):(r3&0x0000ff0000000000LL))
             | ((t1&0x000000ff00000000LL)<(r3&0x000000ff00000000LL)?(t1&0x000000ff00000000LL):(r3&0x000000ff00000000LL))
             | ((t1&0x00000000ff000000LL)<(r3&0x00000000ff000000LL)?(t1&0x00000000ff000000LL):(r3&0x00000000ff000000LL))
             | ((t1&0x0000000000ff0000LL)<(r3&0x0000000000ff0000LL)?(t1&0x0000000000ff0000LL):(r3&0x0000000000ff0000LL))
             | ((t1&0x000000000000ff00LL)<(r3&0x000000000000ff00LL)?(t1&0x000000000000ff00LL):(r3&0x000000000000ff00LL))
             | ((t1&0x00000000000000ffLL)<(r3&0x00000000000000ffLL)?(t1&0x00000000000000ffLL):(r3&0x00000000000000ffLL));
    break;
  case OP_MMAX: /* 8bit*8 2in bytewise compare and output maximum */
    ex1_outd = ((r1&0xff00000000000000LL)>(r2&0xff00000000000000LL)?(r1&0xff00000000000000LL):(r2&0xff00000000000000LL))
             | ((r1&0x00ff000000000000LL)>(r2&0x00ff000000000000LL)?(r1&0x00ff000000000000LL):(r2&0x00ff000000000000LL))
             | ((r1&0x0000ff0000000000LL)>(r2&0x0000ff0000000000LL)?(r1&0x0000ff0000000000LL):(r2&0x0000ff0000000000LL))
             | ((r1&0x000000ff00000000LL)>(r2&0x000000ff00000000LL)?(r1&0x000000ff00000000LL):(r2&0x000000ff00000000LL))
             | ((r1&0x00000000ff000000LL)>(r2&0x00000000ff000000LL)?(r1&0x00000000ff000000LL):(r2&0x00000000ff000000LL))
             | ((r1&0x0000000000ff0000LL)>(r2&0x0000000000ff0000LL)?(r1&0x0000000000ff0000LL):(r2&0x0000000000ff0000LL))
             | ((r1&0x000000000000ff00LL)>(r2&0x000000000000ff00LL)?(r1&0x000000000000ff00LL):(r2&0x000000000000ff00LL))
             | ((r1&0x00000000000000ffLL)>(r2&0x00000000000000ffLL)?(r1&0x00000000000000ffLL):(r2&0x00000000000000ffLL));
    break;
  case OP_MMIN: /* 8bit*8 2in bytewise compare and output minimum */
    ex1_outd = ((r1&0xff00000000000000LL)<(r2&0xff00000000000000LL)?(r1&0xff00000000000000LL):(r2&0xff00000000000000LL))
             | ((r1&0x00ff000000000000LL)<(r2&0x00ff000000000000LL)?(r1&0x00ff000000000000LL):(r2&0x00ff000000000000LL))
             | ((r1&0x0000ff0000000000LL)<(r2&0x0000ff0000000000LL)?(r1&0x0000ff0000000000LL):(r2&0x0000ff0000000000LL))
             | ((r1&0x000000ff00000000LL)<(r2&0x000000ff00000000LL)?(r1&0x000000ff00000000LL):(r2&0x000000ff00000000LL))
             | ((r1&0x00000000ff000000LL)<(r2&0x00000000ff000000LL)?(r1&0x00000000ff000000LL):(r2&0x00000000ff000000LL))
             | ((r1&0x0000000000ff0000LL)<(r2&0x0000000000ff0000LL)?(r1&0x0000000000ff0000LL):(r2&0x0000000000ff0000LL))
             | ((r1&0x000000000000ff00LL)<(r2&0x000000000000ff00LL)?(r1&0x000000000000ff00LL):(r2&0x000000000000ff00LL))
             | ((r1&0x00000000000000ffLL)<(r2&0x00000000000000ffLL)?(r1&0x00000000000000ffLL):(r2&0x00000000000000ffLL));
    break;
  default:
    printf("emax5lib: exe: undefined op_ex1=%d\n", op_ex1);
    break;
  }

  switch (op_ex2) {
  case OP_NOP:
    ex2_outd = ex1_outd;
    break;
  case OP_AND: /* 64bit 2in logical and s1&s2 */
    ex2_outd = ex1_outd & r4;
    break;
  case OP_OR: /* 64bit 2in logical or s1|s2 */
    ex2_outd = ex1_outd | r4;
    break;
  case OP_XOR: /* 64bit 2in logical xor s1^s2 */
    ex2_outd = ex1_outd ^ r4;
    break;
  case OP_SUMHH: /* 16bit*4 1in & s1.h3+s1.h2->d.h3, s1.h1+s1.h0->d.h1 */
    t3 = ex1_outd>>48&0x000000000000ffffLL;
    t2 = ex1_outd>>32&0x000000000000ffffLL;
    t1 = ex1_outd>>16&0x000000000000ffffLL;
    t0 = ex1_outd    &0x000000000000ffffLL;
    t3 += t2;
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t1 += t0;
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    ex2_outd = (t3<<48)|(t1<<16);
    break;
  case OP_SUMHL: /* 16bit*4 1in & s1.h3+s1.h2->d.h2, s1.h1+s1.h0->d.h0 */
    t3 = ex1_outd>>48&0x000000000000ffffLL;
    t2 = ex1_outd>>32&0x000000000000ffffLL;
    t1 = ex1_outd>>16&0x000000000000ffffLL;
    t0 = ex1_outd    &0x000000000000ffffLL;
    t2 += t3;
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t0 += t1;
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex2_outd = (t2<<32)|(t0);
    break;
  case OP_WSWAP: /* 32bit 2in swap words */
    ex2_outd = (ex1_outd<<32)|(ex1_outd>>32);
    break;
  default:
    printf("emax5lib: exe: undefined op_ex2=%d\n", op_ex2);
    break;
  }

  switch (op_ex3) {
  case OP_NOP:
    if (d) *d = ex2_outd;
    break;
  case OP_SLL: /* 32bit*2 2in 32bit logical shift to left */
    t1 = (Ull)(ex2_outd    &0xffffffff00000000LL)<<r5;
    t0 = (Ull)(ex2_outd<<r5&0x00000000ffffffffLL);
    if (d) *d = t1 | t0;
    break;
  case OP_SRL: /* 32bit*2 2in 32bit logical shift to right */
    t1 = (Ull)(ex2_outd>>r5&0xffffffff00000000LL);
    t0 = (Ull)(ex2_outd    &0x00000000ffffffffLL)>>r5;
    if (d) *d = t1 | t0;
    break;
  case OP_SRAA: /* 32bit*2 2in 32bit arith shift to right (bit63,31 is ext.) */
    t1 = (Sll)(ex2_outd    )>>r5&0xffffffff00000000LL;
    t0 = (Sll)(ex2_outd<<32)>>r5&0xffffffff00000000LL;
    if (d) *d = t1 | (t0>>32);
    break;
  case OP_SRAB: /* 32bit*2 2in 32bit arith shift to right (bit55,23 is ext.) */
    t1 = (Sll)(ex2_outd<< 8)>>(r5+8)&0xffffffff00000000LL;
    t0 = (Sll)(ex2_outd<<40)>>(r5+8)&0xffffffff00000000LL;
    if (d) *d = t1 | (t0>>32);
    break;
  case OP_SRAC: /* 32bit*2 2in 32bit arith shift to right (bit47,15 is ext.) */
    t1 = (Sll)(ex2_outd<<16)>>(r5+16)&0xffffffff00000000LL;
    t0 = (Sll)(ex2_outd<<48)>>(r5+16)&0xffffffff00000000LL;
    if (d) *d = t1 | (t0>>32);
    break;
  case OP_SRAD: /* 32bit*2 2in 32bit arith shift to right (bit39,7 is ext.) */
    t1 = (Sll)(ex2_outd<<24)>>(r5+24)&0xffffffff00000000LL;
    t0 = (Sll)(ex2_outd<<56)>>(r5+24)&0xffffffff00000000LL;
    if (d) *d = t1 | (t0>>32);
    break;
  case OP_SRLM: /* 16bit*4 2in 16bit arith shift to right */
    t3 = (Ull)(ex2_outd    )>>r5&0xffff000000000000LL;
    t2 = (Ull)(ex2_outd<<16)>>r5&0xffff000000000000LL;
    t1 = (Ull)(ex2_outd<<32)>>r5&0xffff000000000000LL;
    t0 = (Ull)(ex2_outd<<48)>>r5&0xffff000000000000LL;
    if (d) *d = t3 | (t2>>16) | (t1>>32) | (t0>>48);
    break;
  default:
    printf("emax5lib: exe: undefined op_ex3=%d\n", op_ex3);
    break;
  }

  return (retval);
}

void __attribute__((always_inline))
eag(Ull *adr, Ull base, Ull offset, Uchar msk)
{
  switch (msk) {
  case  MSK_D0:
    break;
  case  MSK_W1:		
    offset = offset>>32;
    break;
  case  MSK_W0:
    offset = offset&0x00000000ffffffffLL;
    break;
  case  MSK_H3:
    offset = offset>>48&0x000000000000ffffLL;
    break;
  case  MSK_H2:
    offset = offset>>32&0x000000000000ffffLL;
    break;
  case  MSK_H1:
    offset = offset>>16&0x000000000000ffffLL;
    break;
  case  MSK_H0:
    offset = offset&0x000000000000ffffLL;
    break;
  case  MSK_B7:
    offset = offset>>56&0x00000000000000ffLL;
    break;
  case  MSK_B6:
    offset = offset>>48&0x00000000000000ffLL;
    break;
  case  MSK_B5:
    offset = offset>>40&0x00000000000000ffLL;
    break;
  case  MSK_B4:
    offset = offset>>32&0x00000000000000ffLL;
    break;
  case  MSK_B3:
    offset = offset>>24&0x00000000000000ffLL;
    break;
  case  MSK_B2:
    offset = offset>>16&0x00000000000000ffLL;
    break;
  case  MSK_B1:
    offset = offset>>8&0x00000000000000ffLL;
    break;
  case  MSK_B0:
    offset = offset&0x00000000000000ffLL;
    break;
  default:
    /*dmop1->offsm = 15; /* for internal update of ea1*/
    /*printf("emax5lib: eag: undefined msk=%d\n", msk);*/
    break;
  }

  *adr = base + offset;
}

void __attribute__((always_inline))
mop(Uint op_mm, Ull ex, Ull *d, Ull base, Ull offset, Uchar msk, Ull top, Uint len, Uint blk, Uchar force, Ull ptop, Uint plen)
{
  Ull adr;

  eag(&adr, base, offset, msk);
  mmp(op_mm, ex, d, adr, top, len, blk);
}

void __attribute__((always_inline))
mo4(Uint op_mm, Ull ex, Ull *d, Ull base, Ull offset, Uchar msk, Ull top, Uint len, Uint blk, Uchar force, Ull ptop, Uint plen)
{
  Ull adr;

  eag(&adr, base, offset, msk);
  mmp(op_mm, ex, d, adr, top, len, blk);
}

void __attribute__((always_inline))
mmp(Uint op_mm, Ull ex, Ull *d, Ull adr, Ull top, Uint len, Uint blk)
{
  Ull c1, c0;

  c1 = ex>>1&1;
  c0 = ex   &1;

  switch (op_mm) {
  case OP_NOP:
    break;

    /* MOP */
  case OP_LDR: /* 64bit lmm LMM is preloaded, random-access */
    *d = *(Ull*)(adr&~7LL);
    break;
  case OP_LDWR: /* s32bit lmm LMM is preloaded, random-access */
    *d = (Sll)*(int*)(adr&~3LL);
    break;
  case OP_LDUWR: /* u32bit lmm LMM is preloaded, random-access */
    *d = (Ull)*(Uint*)(adr&~3LL);
    break;
  case OP_LDHR: /* s16bit lmm LMM is preloaded, random-access */
    *d = (Sll)*(short*)(adr&~1LL);
    break;
  case OP_LDUHR: /* u16bit lmm LMM is preloaded, random-access */
    *d = (Ull)*(Ushort*)(adr&~1LL);
    break;
  case OP_LDBR: /* s8bit lmm LMM is preloaded, random-access */
    *d = (Sll)*(char*)adr;
    break;
  case OP_LDUBR: /* u8bit lmm LMM is preloaded, random-access */
    *d = (Ull)*(Uchar*)adr;
    break;
  case OP_STR: /* 64bit lmm LMM is drained. random-access */
    if (c1) *((Uint*)(adr&~7LL)+1) = *d>>32;
    if (c0) *((Uint*)(adr&~7LL)  ) = *d;
    break;
  case OP_STWR: /* 32bit lmm LMM is drained. random-access */
    if (c0) *(Uint*)(adr&~3LL) = *d;
    break;
  case OP_STHR: /* 16bit lmm LMM is drained. random-access */
    if (c0) *(Ushort*)(adr&~1LL) = *d;
    break;
  case OP_STBR: /* 8bit lmm LMM is drained. random-access */
    if (c0) *(Uchar*)adr = *d;
    break;

    /* MO4 */
  case OP_LDRQ: /* 64bit*4 lmm LMM is preloaded, random-access */
    switch (blk) {
    case 0: /* normal */
      /* adr=0,32,64,... */
      *(d+0) = *((Ull*)(adr&~31LL)+0);
      *(d+1) = *((Ull*)(adr&~31LL)+1);
      *(d+2) = *((Ull*)(adr&~31LL)+2);
      *(d+3) = *((Ull*)(adr&~31LL)+3);
      break;
    case 1: /* block_size=16-members */
      /* adr=0,32,64,... memadr = mem(top + (adr/32/16*ptr)) + (adr/32/&15)*4 */
      *(d+0) = *(*(Ull**)(top + (adr/32/16*sizeof(Ull*))) + (adr/32&15)*4 + 0);
      *(d+1) = *(*(Ull**)(top + (adr/32/16*sizeof(Ull*))) + (adr/32&15)*4 + 1);
      *(d+2) = *(*(Ull**)(top + (adr/32/16*sizeof(Ull*))) + (adr/32&15)*4 + 2);
      *(d+3) = *(*(Ull**)(top + (adr/32/16*sizeof(Ull*))) + (adr/32&15)*4 + 3);
      break;
    case 2: /* block_size=32-members */
      /* adr=0,32,64,... memadr = mem(top + (adr/32/32*ptr)) + (adr/32/&31)*4 */
      *(d+0) = *(*(Ull**)(top + (adr/32/32*sizeof(Ull*))) + (adr/32&31)*4 + 0);
      *(d+1) = *(*(Ull**)(top + (adr/32/32*sizeof(Ull*))) + (adr/32&31)*4 + 1);
      *(d+2) = *(*(Ull**)(top + (adr/32/32*sizeof(Ull*))) + (adr/32&31)*4 + 2);
      *(d+3) = *(*(Ull**)(top + (adr/32/32*sizeof(Ull*))) + (adr/32&31)*4 + 3);
      break;
    default:/* block_size=64-members */
      /* adr=0,32,64,... memadr = mem(top + (adr/32/64*ptr)) + (adr/32/&63)*4 */
      *(d+0) = *(*(Ull**)(top + (adr/32/64*sizeof(Ull*))) + (adr/32&63)*4 + 0);
      *(d+1) = *(*(Ull**)(top + (adr/32/64*sizeof(Ull*))) + (adr/32&63)*4 + 1);
      *(d+2) = *(*(Ull**)(top + (adr/32/64*sizeof(Ull*))) + (adr/32&63)*4 + 2);
      *(d+3) = *(*(Ull**)(top + (adr/32/64*sizeof(Ull*))) + (adr/32&63)*4 + 3);
      break;
    }
    break;
  case OP_LDDMQ: /* 64bit*4 mem Direct access to MM */
    if (c0) {
      *(d+0) = *((Ull*)(adr&~31LL)+0);
      *(d+1) = *((Ull*)(adr&~31LL)+1);
      *(d+2) = *((Ull*)(adr&~31LL)+2);
      *(d+3) = *((Ull*)(adr&~31LL)+3);
    }
    break;
  case OP_STRQ: /* 64bit*4 lmm LMM is drained. random-access */
    *((Ull*)(adr&~31LL)+0) = *(d+0);
    *((Ull*)(adr&~31LL)+1) = *(d+1);
    *((Ull*)(adr&~31LL)+2) = *(d+2);
    *((Ull*)(adr&~31LL)+3) = *(d+3);
    break;
  case OP_TR: /* 64bit*4 exec Send transaction */
    /* addrをtransaction()指定に使用 */
    if (c0) {
      Ull (*trans)() = top;
      (trans)(*(d+0), *(d+1), *(d+2), *(d+3));
    }
    break;
  default:
    printf("emax5lib: mmp: undefined op_mm=%d\n", op_mm);
    break;
  }
}
