
static char RcsHeader[] = "$Header: /usr/home/nakashim/proj-arm64/src/bsim/RCS/emax5.c,v 1.219 2018/02/11 13:36:34 nakashim Exp nakashim $";

/* EMAX5 Simulator                     */
/*         Copyright (C) 2012 by NAIST */
/*         Primary writer: Y.Nakashima */
/*                nakashim@is.naist.jp */

/* emax5.c 2012/9/22 */

#include <stdio.h>
#include "bsim.h"
#include "../conv-c2b/emax5.h"
#include "../conv-c2b/emax5lib.c"

/* CGRA hardware */
/*#undef FEATURE_SHIFT_CONF*/
#define FEATURE_SHIFT_CONF

enum { FSM_IDLE,    FSM_CONF,    FSM_LMMI,    FSM_DRAIN,    FSM_LOAD,    FSM_REGV,    FSM_START,    FSM_EXEC,    FSM_TERM };
enum { MEMIF_IDLE,  MEMIF_AREQ,  MEMIF_DREQ,  MEMIF_TERM };

struct emax5 { /* lmm status of EMAX5 */
  Ull   v                 : 1; /* 0:empty, 1:unuse */
  Ull   tid               :12; /* owner thread of EMAX */
  Ull   mode              : 2; /* 1:normal array, 2:drain_dirty_lmm */
  Ull   status            : 4;
  Ull   retval            : 2; /* 0:normal_end, 1:require L2$invalidation, 2:busy */
  Ull   last_conf            ; /* for insn_reuse */
  Ull   last_dist         : 6; /* latest map_dist */
  Ull   last_row0         : 6; /* physical top of logical unit[][0] */

  Ull   unit1_arbrk;   /* loop最終命令の実行完了を表示 */
  Ull   unit1_exec;    /* 次の動作を指示 (cex,exe,eag), 0:wait 1:exec */
  Ull   unit1_stop;    /* 次の動作を指示 (cex,exe,eag), 0:wait 1:stop */
  Ull   tr_valid;      /* TRの状態を表示 */
#ifndef IGNORE_LDDMQ_HANDSHAKE
  Ull   unit2_eag_aen; /* for LDDMQ    lmm->addr */
  Ull   unit2_eag_den; /* for IM_BUFRD lmm->data */
  Ull   unit2_guard;   /* LDDMQ位置に1 (gnore unit1_stop) */
  Ull   unit2_lmbrk;   /* lmm finish */
  Ull   unit2_lmbusy;  /* unit1_exec|fsm_busy|eneq */
#endif
  Ull   unit2_exec;    /* 次の動作を指示 (lmm),         0:wait 1:exec */
  Ull   unit2_stop;    /* 次の動作を指示 (lmm),         0:wait 1:stop */
  Ull   brout_valid;   /* BRの状態を表示 常時tr_validを1τ後に伝搬 */

  Uint  cycles_tinit_part;
  Uint  cycles_conf_part;
  Uint  cycles_scon_part;
  Uint  cycles_lmmi_part;
  Uint  cycles_drain_part;
  Uint  cycles_load_part;
  Uint  cycles_regv_part;
  Uint  cycles_start_part;
  Uint  cycles_exec_part;
  Uint  cycles_term_part;
  Uint  cycles_trans_part;
  Ull   cycles_tinit;
  Ull   cycles_conf;
  Ull   cycles_scon;
  Ull   cycles_lmmi;
  Ull   cycles_drain;
  Ull   cycles_load;
  Ull   cycles_regv;
  Ull   cycles_start;
  Ull   cycles_exec;
  Ull   cycles_term;
  Ull   cycles_trans;
                                /* dirtyが残っている場合,lmmiの前にdrain               */
                                /*  conf  | drain | load | lmmi | regv | exec        | */
                                /*        |       |             |      | pload       | */
                                /* 残っていない場合,execと同時にdrain開始              */
                                /*  conf  |       |      | lmmi | regv | exec        | */
                                /*                       |      |      | drain pload | */

                                /* 1 :conf  fsm_way毎に,last_row0から順にEMAX本体に格納                */
                                /*          4wayが全て完了するまで待機                                 */
                                /* 2 :lmmi  fsm_way毎に,fsm内部のlmmiへ読み込み                        */
                                /*          4wayが全て完了するまで待機                                 */
                                /*(3):drain fsm_way毎に,lmmoにdirtyがあるか検査                        */
                                /*          dirtyは,fsm_way毎にdrain                                   */
                                /*          4wayが全て完了するまで待機                                 */
                                /*(4):load  fsm_way毎に,lmmiにpreload以外の未loadLMMがあるか検査       */
                                /*          未loadLMMが存在する場合,fsm_way毎にload                    */
                                /*          4wayが全て完了するまで待機                                 */
                                /* 5 :regv  全fsm_wayに,start準備をセット                              */
                                /*          4wayが全て完了するまで待機                                 */
                                /* 6 :start 全fsm_wayに,startをセット                                  */
                                /* 7 :exec  全fsm_wayのlast_row0にflag=1をセット.EMAX5起動             */
                                /*          4wayが全て完了するまで待機                                 */
                                /*          この間,各fsm_wayは全lmmiに未drainがあるか検査              */
                                /*          未drainが存在する場合,fsm_way毎に,last_row0から順にdrain   */
                                /*          drain後,pload開始(drain+ploadは，EMAX5の演算動作と同時)    */
                                /*          EMAX5動作と全fsmのdrain/pload動作完了をもって,8:termへ遷移 */

  struct fsm {                 /* load/drainは,複数rowを同時動作 */
    struct lmmi lmmo[EMAX_DEPTH]; /* previous lmmi */
    struct lmmi lmmc[EMAX_DEPTH]; /* current lmmi */
    Uchar       lmmd[EMAX_DEPTH]; /* 0:clean, 1:dirty,   exec後store箇所に1, drain直後0 */

    Ull   memif_status       : 4;
    Ull   last_dist          : 6; /* latest map_dist */
    Ull   row_count          : 8; /* valid row counter is 6bit */
    Ull   row_select         :64; /* bitmap 0:off 1:selected */
    Ull   row_lmm_en         :64; /* lmm enable for read/write */

#ifndef IGNORE_LMMI_BLKGATHER
    Ull   blkstat            : 1; /* 0:PTRLIST 1:VERTEXLIST */
    Ull   blkcount           : 7; /* active block number */
    Ull   blksize            : 9; /* 1:64 2:128 3:256 dwords */
    Ull   blktop[UNIT_WIDTH]    ; /* block address */
    Ull   lmmblktop             ; /* LMM-addr     for LDRQ(blk>0) */
    Ull   lmmblklen             ; /* total dwords for LDRQ(blk>0) */
#endif

    Uint  ardyc                 ; /* LMM addr-ready(read)                                               */
    Uint  rrdyc                 ; /* LMM data-ready(read), AXI data-ready(rvalid) counter               */
                                  /*                         CF  RV  LI  PF  DR  TR  DM                 */
    Ull   araddr                ; /* read-address  of mm      v   v   v   v           v                 */
    Ull   arlen                 ; /* read-length   of mm      v   v   v   v           1                 */
    Ull   awaddr                ; /* write-address of mm                      v                         */
    Ull   awlen                 ; /* write-length  of mm                      v                         */
    Ull   lmm_fmask          : 4; /* mask for first 32B-chunk                                           */
    Ull   lmm_lmask          : 4; /* mask for last  32B-chunk                                           */
    Ull   lmm_nreq              ; /* number of LMM cycles                                               */

    Ull   lmwa                  ; /* -> ea0dr                     v       v                             */
    Ull   lmwd[UNIT_WIDTH]      ; /* <- lmm wdata                 v       v           v                 */
    Ull   lmra                  ; /* -> ea1dr                                 v                         */
    Ull   lmrd[UNIT_WIDTH]      ; /* -> lmm rdata                             v   v                     */

#ifndef IGNORE_LDDMQ_HANDSHAKE
    Ull   fsm_busy           : 1; /* for LDDMQ and TR */
    Ull   lmwd_valid         : 1; /* for LDDMQ */
    Ull   tcureg_valid       : 1; /* fsm->ARM   0 -> 1 -> 1 -> 0 -> 0 -> 0                              */
    Ull   tcureg_ready       : 1; /* fsm<-ARM   0 -> 0 -> 1 -> 0 -> 0 -> 0                              */
    Ull   tcureg_last        : 1; /* fsm->ARM   0 -> 0 -> 0 -> 1 -> 1 -> 0                              */
    Ull   tcureg_term        : 1; /* fsm<-ARM   0 -> 0 -> 0 -> 0 -> 1 -> 0                              */
    Ull   tcureg[UNIT_WIDTH]    ; /* tcu-data        of tcu                       v                     */
                                  /* from ARM:  svc 0x1010 ... tcureg_valid->x0                         */
                                  /* from ARM:  svc 0x1011 ... 1->tcureg_ready                          */
                                  /* from ARM:  svc 0x1012 ... tcureg_last->x0                          */
                                  /* from ARM:  svc 0x1013 ... 1->tcureg_term                           */
                                  /* from ARM:  svc 0x1014 ... tcureg[3:0]->x3,2,1,0                    */
#endif

    Ull   axi_arready        : 1; /* axi -> fsm                                                         */
    Ull   axi_arvalid        : 1; /* axi <- fsm                                                         */
    Ull   axi_first_read     : 1; /* simulate pipelined AXI (1->0) same as one_shot */
    Ull   axi_araddr            ; /* aligned-address of mm    v   v   v   v           v                 */
    Ull   axi_arlen             ; /* aligned-length  of mm    v   v   v   v           1                 */
    Ull   axi_rvalid         : 1; /* axi -> fsm read-ready                                              */
    Ull   axi_rdata[UNIT_WIDTH] ; /* read-data       of mm    v   v   v   v           v                 */
    Ull   axi_awready        : 1; /* axi -> fsm                                                         */
    Ull   axi_awvalid        : 1; /* axi -> fsm                                                         */
    Ull   axi_awaddr            ; /* aligned-address of mm                    v                         */
    Ull   axi_awlen             ; /* aligned-length  of mm                    v                         */
    Ull   axi_wstrb          :32; /* axi byte-enable for 32B                                            */
    Ull   axi_wvalid         : 1; /* fsm -> axi write-ready                                             */
    Ull   axi_wdata[UNIT_WIDTH] ; /* write-data      of mm                    v                         */

    Ull   iaddr                 ; /* fsm internal                                                       */
    Ull   ilen                  ; /* fsm internal                                                       */
    Ull   idelay                ; /* siml MEMORY delay (same as MMDELAY/RATIO)                          */
  } fsm[EMAX_WIDTH];
} emax5[MAXCORE];

struct unit { /* hardware status of EMAX5 units */
  struct conf conf;
  struct regv regv;        /* ea0br,ea0or,ea1br,ea1or,br[UNIT_WIDTH] */
  Ull   one_shot     : 1;  /* reg  *//* for self_loop_control 0:init 1:self_loop */
#ifndef IGNORE_LDDMQ_HANDSHAKE
  Ull   one_shot_a   : 1;  /* reg (internal) *//* for self_loop_control 0:init 1:self_loop for LDDMQ    */
  Ull   one_shot_d   : 1;  /* reg (internal) *//* for self_loop_control 0:init 1:self_loop for LM_BUFRD */
  Ull   unit1_eneq   : 1;  /* wire(internal) *//* for detecting LMM has valid entry */
  Ull   lmwd_valid   : 1;  /* wire(from fsm) */
#endif
  Uchar c[UNIT_WIDTH];     /* wire */
  Ull   cexdr        : 2;  /* reg  *//* bit1: 0:none 1:exec, bit0: 0:none 1:exec */
  Ull   ex1             ;  /* wire *//* in for ALU */
  Ull   ex2             ;  /* wire *//* in for ALU */
  Ull   ex3             ;  /* wire *//* in for ALU */
  Ull   eab             ;  /* wire *//* in for ALU */
  Ull   eao             ;  /* wire *//* in for ALU */
  Ull   ea0b            ;  /* wire *//* in for EA0 */
  Ull   ea0o            ;  /* wire *//* in for EA0 */
  Ull   ea1b            ;  /* wire *//* in for EA1 */
  Ull   ea1o            ;  /* wire *//* in for EA1 */
  Ull   exdr            ;  /* reg  */
  Ull   ea0dr           ;  /* reg  */
  Ull   ea1dr           ;  /* reg  */
  Ull   ea0d            ;  /* wire */
  Ull   ea1d            ;  /* wire */

  Ull   lmen         : 1;  /* lmm enable for read/write */
  Ull   drty         : 1;  /* lmm mamrked as dirty */
  Ull   rrdy         : 1;  /* wire *//* LMM data-valid for FSM */

  Ull   lmwa            ;  /* wire *//* -> ea0dr */
  Ull   lmwd[UNIT_WIDTH];  /* wire *//* <- axi */
  Ull   lmra            ;  /* wire *//* -> ea1dr */
  Ull   lmrd[UNIT_WIDTH];  /* wire *//* -> axi */

  Ull   lmria           ;  /* wire */
  Ull   lmroa           ;  /* wire */
  Ull   lmlia           ;  /* wire */
  Ull   lmloa           ;  /* wire */
  Ull   lmri[UNIT_WIDTH];  /* wire */
  Ull   lmro[UNIT_WIDTH];  /* wire */
  Ull   lmli[UNIT_WIDTH];  /* wire */
  Ull   lmlo[UNIT_WIDTH];  /* wire */
  Ull   t[UNIT_WIDTH];     /* wire */
  Ull   tr[UNIT_WIDTH];    /* reg  */
  struct lmm {
    Ull   en0         : 1; /* internal reg       */
    Ull   en1         : 1; /* internal reg       */
    Ull   rw0         : 1; /* 0:read, 1:write    */
    Ull   rw1         : 1; /* 0:read,(1:write)   */
    Ull   ma0            ; /* internal reg  addr(32B aligned)      */
    Ull   ma1            ; /* internal reg  addr(32B aligned)      */
    Ull   mm0[UNIT_WIDTH]; /* internal reg  mask */
    Ull   mw0[UNIT_WIDTH]; /* internal reg  data */
    Ull   mr0[UNIT_WIDTH]; /* internal wire data */
    Ull   mr1[UNIT_WIDTH]; /* internal wire data */
    Uchar m[LMEM_SIZE]   ; /* local memory       */
  } lmm;
  Ull   mr0mux        : 2; /* mr0[3-0] -> brs0     */
  Ull   mr1mux        : 2; /* mr1[3-0] -> brs1     */
  Ull   mr0d             ; /* muxed data for BR[0] */
  Ull   mr1d             ; /* muxed data for BR[1] */
} unit[MAXCORE][EMAX_DEPTH][EMAX_WIDTH];

/* TCU hardware */
enum { TCU_IDLE, TCU_BUSY };

#define MAX_TRANS_CBL 8
#define MAX_TRANS_REG 8

Uint next_tcu; /* tcb_entry for next tcb registration by trans_start() */
struct tcu { /* final information for EMAX5 hardware */
  Ull   status : 4;
  Ull   tcbid     ; /* 0:invalid, start address of trans */
  struct tconf tconf[TRANS_DEPTH]; /* copy of tconf[] */
  Uint  pc;                 /* program counter */
  Ull   reg[MAX_TRANS_REG]; /* r0-r7 for param/work */
} tcu[MAX_TRANS_CBL];

Ull get_tcureg_valid(cid, col) int cid, col;
{
#ifndef IGNORE_LDDMQ_HANDSHAKE
  return (emax5[cid].fsm[col].tcureg_valid);
#else
  return (0);
#endif
}

put_tcureg_ready(cid, col) int cid, col;
{
#ifndef IGNORE_LDDMQ_HANDSHAKE
  emax5[cid].fsm[col].tcureg_ready = 1;
#endif
}

Ull get_tcureg_last(cid, col) int cid, col;
{
#ifndef IGNORE_LDDMQ_HANDSHAKE
  return (emax5[cid].fsm[col].tcureg_last);
#else
  return (0);
#endif
}

put_tcureg_term(cid, col) int cid, col;
{
#ifndef IGNORE_LDDMQ_HANDSHAKE
  emax5[cid].fsm[col].tcureg_term = 1;
#endif
}

Ull get_tcureg(cid, col, n) int cid, col, n;
{
#ifndef IGNORE_LDDMQ_HANDSHAKE
  return (emax5[cid].fsm[col].tcureg[n]);
#else
  return (0);
#endif
}

/* TCU control */
siml_trans(tid, pa_cycle, tic, trace, trace_pipe, base, start, end, gr2) Uint tid; Ull pa_cycle; int tic; Uint trace, trace_pipe; Uchar *base; Ull start, end, gr2;
{
  Uint cid = tid2cid(tid);
  int i, j, k, a;

  emax5[cid].cycles_tinit_part = 0;

  for (i=0; i<MAX_TRANS_CBL; i++) {
    if (tcu[i].tcbid == start) {
      next_tcu = i;
      break;
    }
  }

  if (tcu[next_tcu].status != TCU_IDLE)
    return (2);

  /* new tcb is stored in tcu.next_tcb */
  tcu[next_tcu].tcbid = start;
  for (i=0; i<TRANS_DEPTH; i++)
    tcu[next_tcu].tconf[i] = *((struct tconf*)(base+start)+i);

  emax5[cid].cycles_tinit_part = sizeof(tconf)/(sizeof(Ull)*UNIT_WIDTH*EMAX_WIDTH);
  emax5[cid].cycles_tinit += emax5[cid].cycles_tinit_part;

  next_tcu = (next_tcu+1)%MAX_TRANS_CBL;

  return (0);
}

/* EMAX5 control */
//application -> emax5_start((Ull*)emax5_conf_x1, (Ull*)emax5_lmmi_x1, (Ull*)emax5_regv_x1);
//            -> svc 0xf1
siml_emax5(tid, pa_cycle, tic, trace, trace_pipe, base, conf, lmmi, regv, mode)
     Uint tid; Ull pa_cycle; int tic; Uint trace, trace_pipe; char *base; Ull conf, lmmi, regv; int mode;
{
  /* mode=1:normal_array, 2:drain_dirty_lmm */
  Uint cid = tid2cid(tid);
  int i, j, k, mark, sync, total;
  Ull a;
  Ull *conf_p, *lmmi_p, *regv_p, *load_p;

  if (emax5[cid].v && emax5[cid].tid != tid)
    return (2); /* busy */

  if (pa_cycle % ARM_EMAX5_RATIO) /* ARM:2.4GHz EMAX5:300MHz */
    return (2); /* busy */

  if (emax5[cid].status == STATUS_IDLE) {
    emax5[cid].v = 1; /* lock */
    emax5[cid].tid = tid;
    emax5[cid].cycles_conf_part  = 0;
    emax5[cid].cycles_scon_part  = 0;
    emax5[cid].cycles_lmmi_part  = 0;
    emax5[cid].cycles_drain_part = 0;
    emax5[cid].cycles_load_part  = 0;
    emax5[cid].cycles_regv_part  = 0;
    emax5[cid].cycles_start_part = 0;
    emax5[cid].cycles_exec_part  = 0;
    emax5[cid].cycles_term_part  = 0;
    emax5[cid].cycles_trans_part = 0;
  }
  while (tic-- > 0) {
    Ull unit1_stop_next, unit1_exec_next, unit2_stop_next, unit2_exec_next;
    /*******************************************************/
    /******************* unit siml start *******************/
    /*******************************************************/
    siml_axiif(cid, trace, base);
    for (i=(emax5[cid].last_row0+EMAX_DEPTH-1)%EMAX_DEPTH;; i=(i+EMAX_DEPTH-1)%EMAX_DEPTH) { /* for each unit */
      siml_unit_bus1(cid, i); /* c,t,ex,ea */
      siml_unit_bus2(cid, i); /* lmw,lmr */
      for (j=EMAX_WIDTH-1; j>=0; j--) /* for each unit */
        siml_unit_lmm(cid, i, j); /* lmm */
      emax5[cid].unit1_arbrk &= ~(1LL<<i); /* reset arbrk */
#ifndef IGNORE_LDDMQ_HANDSHAKE
      emax5[cid].unit2_guard &= ~(1LL<<i); /* reset guard */
      emax5[cid].unit2_lmbrk &= ~(1LL<<i); /* reset lmbrk */
#endif
      if (i==(emax5[cid].last_row0+EMAX_DEPTH-1)%EMAX_DEPTH)
	emax5[cid].brout_valid = (emax5[cid].brout_valid &~(1LL<<i)) | (1LL<<i); /* 最終brout_validは常時1 */
      else
	emax5[cid].brout_valid = (emax5[cid].brout_valid &~(1LL<<i)) | (emax5[cid].tr_valid & (1LL<<i));
      for (j=EMAX_WIDTH-1; j>=0; j--) { /* for each unit */
        /**************************/
        /****** do exe ************/
        /**************************/
        siml_unit_cex(cid, i, j); /* cexdr */
        siml_unit_exe(cid, i, j); /* exdr    (unit1_arbrk) */
        siml_unit_eas(cid, i, j); /* eadr,ma (eneq) */
      }
      siml_unit_bus3(cid, i); /* unit2_eag_aen,unit2_eag_den */
      for (j=EMAX_WIDTH-1; j>=0; j--) /* for each unit */
        siml_unit_ead(cid, i, j); /* unit2_guard,unit2_lmbrk */
      for (j=EMAX_WIDTH-1; j>=0; j--) /* for each unit */
        siml_unit_trg(cid, i, j); /* tr,mw */
      siml_unit_bus4(cid, i); /* tr_valid */
      /* 自stage:stop=1と同時に自stage:exec=0 次cycleから実行停止 */
      switch (emax5[cid].status) {
      case STATUS_REGV:
        emax5[cid].unit1_stop  &= ~(1LL<<i);
        emax5[cid].tr_valid    &= ~(1LL<<i);
        emax5[cid].unit2_stop  &= ~(1LL<<i);
        emax5[cid].brout_valid &= ~(1LL<<i);
        break;
      case STATUS_START:
        emax5[cid].unit1_exec  = emax5[cid].fsm[0].row_select;
        break;
      case STATUS_EXEC:
	unit1_stop_next = ((emax5[cid].unit1_arbrk &(1LL<<i))||(emax5[cid].unit1_stop                        &(1LL<<i))||(emax5[cid].unit2_stop&(1LL<<((i+EMAX_DEPTH-1)%EMAX_DEPTH))))?(1LL<<i):0;
	unit1_exec_next = (                                    (emax5[cid].unit1_exec                        &(1LL<<i))||(emax5[cid].unit2_exec&(1LL<<((i+EMAX_DEPTH-1)%EMAX_DEPTH))))?(1LL<<i):0;
#ifndef IGNORE_LDDMQ_HANDSHAKE
	unit2_stop_next = ((emax5[cid].unit2_lmbrk &(1LL<<i))||(emax5[cid].unit1_stop&~emax5[cid].unit2_guard&(1LL<<i))||(emax5[cid].unit2_stop&(1LL<<((i             )           ))))?(1LL<<i):0;
#else
	unit2_stop_next = ((                              0 )||(emax5[cid].unit1_stop                        &(1LL<<i))||(emax5[cid].unit2_stop&(1LL<<((i             )           ))))?(1LL<<i):0;
#endif
	unit2_exec_next = (                                    (emax5[cid].unit1_exec                        &(1LL<<i))||(emax5[cid].unit2_exec&(1LL<<((i             )           ))))?(1LL<<i):0;
        emax5[cid].unit1_stop = (emax5[cid].unit1_stop &~(1LL<<i)) |                    unit1_stop_next;
        emax5[cid].unit1_exec = (emax5[cid].unit1_exec &~(1LL<<i)) |(unit1_exec_next & ~unit1_stop_next);
        emax5[cid].unit2_stop = (emax5[cid].unit2_stop &~(1LL<<i)) |                    unit2_stop_next;
        emax5[cid].unit2_exec = (emax5[cid].unit2_exec &~(1LL<<i)) |(unit2_exec_next & ~unit2_stop_next);
        break;
      }
      if (i==emax5[cid].last_row0)
        break;
    }
    /*******************************************************/
    /******************* unit siml end *********************/
    /*******************************************************/

    /*******************************************************/
    /******************* FSM siml start ********************/
    /******** 全unit 1cycle動作後,FSMは次のcmdを用意 *******/
    /*******************************************************/
    switch (emax5[cid].status) {
    case STATUS_IDLE:
      if ((flag & DUMP_DDR) && !dump_ddr_done) { /* dump once */
	printf("\n");
	if ((fp_conf = fopen("conf.dat", "w"))==NULL) {
	  printf(" cannot open conf.dat for DUMP_DDR\n");
	  exit(1);
	}
	if ((fp_lmmi = fopen("lmmi.dat", "w"))==NULL) {
	  printf(" cannot open lmmi.dat for DUMP_DDR\n");
	  exit(1);
	}
	if ((fp_regv = fopen("regv.dat", "w"))==NULL) {
	  printf(" cannot open regv.dat for DUMP_DDR\n");
	  exit(1);
	}
	if ((fp_load = fopen("load.dat", "w"))==NULL) {
	  printf(" cannot open load.dat for DUMP_DDR\n");
	  exit(1);
	}
      }
      printf(" EMAX_START(%08.8x_%08.8x)", (Uint)(pa_cycle>>32), (Uint)pa_cycle);
      if (trace || ((flag & DUMP_DDR) && !dump_ddr_done)) /* dump once */
	printf("\n");
      if (mode==2) { /* drain_dirty_lmm */
        if (trace)
          printf("%03.3d:siml_emax5: drain_dirty_lmm start\n", tid);
        emax5[cid].status = STATUS_DRAIN;
      }
      else if (emax5[cid].last_conf != conf) {
        if (trace)
          printf("%03.3d:siml_emax5: conf=%08.8x_%08.8x start (load)\n", tid, (Uint)(conf>>32), (Uint)conf);
        emax5[cid].status = STATUS_CONF;
      }
      else if (emax5[cid].last_dist > 0) {
#ifdef FEATURE_SHIFT_CONF
        if (trace)
          printf("%03.3d:siml_emax5: conf=%08.8x_%08.8x start (shift)\n", tid, (Uint)(conf>>32), (Uint)conf);
        emax5[cid].status = STATUS_SCON;
#else
        if (trace)
          printf("%03.3d:siml_emax5: conf=%08.8x_%08.8x start (load)\n", tid, (Uint)(conf>>32), (Uint)conf);
        emax5[cid].status = STATUS_CONF;
#endif
      }
      else {
        if (trace)
          printf("%03.3d:siml_emax5: conf=%08.8x_%08.8x start (reuse)\n", tid, (Uint)(conf>>32), (Uint)conf);
        emax5[cid].status = STATUS_LMMI;
      }
      {
	int found = 0;
	for (j=0; j<EMAX_WIDTH; j++) {
	  for (i=0; i<EMAX_DEPTH; i++) {
	    /* transaction有りと,lmm_dirty有りは,1つのEMAXカーネルでは混在禁止とする */
	    /* START時にlmm_dirtyがある場合,次のEXECにて主記憶を更新する.            */
	    /*   transactionはないものとし,EMAX実行から復帰時に,L2$を無効化する      */
	    /* START時にlmm_dirtyがない場合,transactionのみが含まれると考える.       */
	    /*   transactionがある場合,L1$とL2$は使用されているためL2$は無効化しない */
	    if (emax5[cid].fsm[j].lmmd[i]) /* mark dirty */
	      found = 1;
	  }
	}
	emax5[cid].retval = (found)? 1 : 0; /* dirty有りの場合,EMAX完了時にARM-L2$無効化 */
      }
      for (j=0; j<EMAX_WIDTH; j++) {
        emax5[cid].fsm[j].memif_status = MEMIF_AREQ;
        emax5[cid].fsm[j].row_count    = 0;
        emax5[cid].fsm[j].row_select   = 0LL;
#ifndef IGNORE_LMMI_BLKGATHER
	emax5[cid].fsm[j].blkstat  = 0; /* ptrlist */
	emax5[cid].fsm[j].blkcount = 0; /* dword/dword: 7bit */
#endif
      }
      break;
    case STATUS_SCON:
      emax5[cid].cycles_scon_part++;
      for (j=0; j<EMAX_WIDTH; j++) {
	/* row_countでシフト数制御, row_selectで 0:conf->BR, 1:BR->conf 切替え */
	if (emax5[cid].fsm[j].row_count < emax5[cid].fsm[j].last_dist) { /* last_dist > 0 */
	  if (!(emax5[cid].fsm[j].row_select&1))  /* 1回早くインクリメントし終了タイミングを合わせる */
	    emax5[cid].fsm[j].row_count++;
	  emax5[cid].fsm[j].row_select  = ~emax5[cid].fsm[j].row_select; /* STAT_SCON2回目からall-1 */
	}
	else { /* row_count*2サイクルシフトして終了 */
	  emax5[cid].status = STATUS_LMMI;
	  emax5[cid].fsm[j].memif_status = MEMIF_AREQ;
	  emax5[cid].fsm[j].row_count    = 0LL;
	  emax5[cid].fsm[j].row_select   = 0LL;
#ifndef IGNORE_LMMI_BLKGATHER
	  emax5[cid].fsm[j].blkstat  = 0; /* ptrlist */
	  emax5[cid].fsm[j].blkcount = 0; /* dword/dword: 7bit */
#endif
	}
      }
      break;
      /*******************************************************************************************************************************************************/
      /* ●lmmi指示ルール (copy from conv-c2b/emac5.c)                                                                  lmmi-loc  v  top  blk  len  rw  f  p */
      /* LD with force-read=0 and ptop==NULL generates current(lmr) and reuse LMM. same as lmr in EMAX4                     curr  1  top  blk  len   0  0  0 */
      /* LD with force-read=1 and ptop==NULL generates current(lmf) and !reuse LMM. same as lmf in EMAX4                    curr  1  top  blk  len   0  1  0 */
      /* LD with force-read=0 and ptop!=NULL generates current(lmr) and next(lmp). mapdist!=0                               curr  1  top  blk  len   0  0  0 */
      /*                                                                                                       ofs=0      c+dist  1 ptop  blk  len   0  0  1 */
      /* LD with force-read=0 and ptop!=NULL generates current(lmr) and next(lmp). mapdist==0                  ofs=ptop-top curr  1  top  blk  len   0  0  1 */
      /*                                                                                                               p=1の場合,pref-addrは常にlmmi.top+ofs */
      /* LDDMQ set f=1 and p=1 in lmmc automatically                                                                        curr  1  top  -    -     0  1  1 */
      /*******************************************************************************************************************************************************/
      /* ST with force-read=0 and ptop==NULL generates current(lmw) and reuse+wback LMM. same as lmw in EMAX4               curr  1  top  blk  len   1  0  0 */
      /* ST with force-read=1 and ptop==NULL generates current(lmx) and !reuse+wback LMM. same as lmx in EMAX4              curr  1  top  blk  len   1  1  0 */
      /* ST with force-read=0 and ptop!=NULL generates current(lmw) and prev(lmd). mapdist!=0                               curr  1  top  blk  len   1  0  0 */
      /*                                                                                                       ofs=0      c-dist  1 ptop  blk  len   1  0  1 */
      /* ST with force-read=0 and ptop!=NULL generates current(lmw) and prev(lmd). mapdist==0                  ofs=ptop-top curr  1  top  blk  len   1  0  1 */
      /*                                                                                                              p=1の場合,drain-addrは常にlmmi.top+ofs */
      /* TR    set f=1 and p=1 in lmmc automatically                                                                        curr  1  top  -    -     1  1  1 */
      /*******************************************************************************************************************************************************/
      /* Example of Load+Store **************************************************************************/
      /* for (x=0; x<XSIZE; x+=4) { /* mapped to while() on BR[15][0][0]                                */
      /*   mo4(LDRQ,  1, src1, A[y], x, msk, A[y], 0, XSIZE, 0, NULL);   lmr reuse-OK                   */
      /*   mo4(LDRQ,  1, src2, B[y], x, msk, B[y], 0, XSIZE, 0, NULL);   lmr reuse-OK                   */
      /*   mo4(LDRQ,  1, src3, C[y], x, msk, C[y], 0, XSIZE, 0, NULL);   lmr reuse-OK                   */
      /*                        ●1 lmmc=lmr,lmmo.top!=lmmc.top,の場合, load before next exec           */
      /*   ex4(FMAQ, src1, src2, src3, dst1);                                                           */
      /*   mo4(STRQ,  1, dst1, D[y], x, msk, D[y], 0, XSIZE, 0, NULL);   lmw (store)                    */
      /*                        ●2 lmmo=lmw,lmmc!=lmd,dirty=1の場合, writeback before next exec        */
      /* }                                                                                              */
      /* Example of Accumulate **************************************************************************/
      /* for (x=0; x<XSIZE; x+=4) { /* mapped to while() on BR[15][0][0]                                */
      /*   mo4(LDRQ,  1, src1, D[y], x, msk, D[y], 0, XSIZE, 1, NULL);   lmf (load)                     */
      /*                        ●3 lmmc=lmfの場合, load always before next exec                        */
      /*   ex4(FMAQ, src1, src2, src3, dst1);                                (accumulate)               */
      /*   mo4(STRQ,  1, dst1, D[y], x, msk, D[y], 0, XSIZE, 0, NULL);   lmw (store)                    */
      /*                        ●2 lmmo=lmw,lmmc!=lmd,dirty=1の場合, writeback before next exec        */
      /*                   (lmfとlmwが重なるケースでも一旦memに追い出すことで単純化. lmfは再利用しない) */
      /* }                                                                                              */
      /* Example of Partial Update **********************************************************************/
      /* for (x=0; x<XSIZE; x+=4) { /* mapped to while() on BR[15][0][0]                                */
      /*   mo4(STRQ, ex, dst1, D[y], x, msk, D[y], 0, XSIZE, 0, NULL);   lmx (read-&-conditional-write) */
      /*                        ●3 lmmc=lmxの場合, load always before next exec                        */
      /*                        ●4 lmmc=lmx,dirty=1の場合, writeback before next exec                  */
      /*                                        (lmxも一旦memに追い出すことで単純化. lmxも再利用しない) */
      /* }                                                                                              */
      /* Example of Prefetch+Drain (mapdist>0)***********************************************************/
      /* for (x=0; x<XSIZE; x+=4) { /* mapped to while() on BR[15][0][0]                                */
      /*   mo4(LDRQ,  1, src1, A[y], x, msk, A[y], 0, XSIZE, 0, A[y+1]); lmr+lmp prefetch               */
      /*   mo4(LDRQ,  1, src2, B[y], x, msk, B[y], 0, XSIZE, 0, B[y+1]); lmr+lmp prefetch               */
      /*   mo4(LDRQ,  1, src3, C[y], x, msk, C[y], 0, XSIZE, 0, C[y+1]); lmr+lmp prefetch               */
      /*                        ●1 lmmc=lmr,lmmo.top!=lmmc.topの場合, load before next exec            */
      /*                        ●5 lmmc=lmpの場合, load top+ofs(ofs=0) with next exec                  */
      /*   ex4(FMAQ, src1, src2, src3, dst1);                                                           */
      /*   mo4(STRQ,  1, dst1, D[y], x, msk, NULL, 0, XSIZE, 0, D[y-1]); lmd explicit late drain        */
      /*                        ●6 lmmc=lmd,dirty=1の場合, drain top+ofs(ofs=0) with next exec         */
      /* }                                                                                              */
      /* Example of Prefetch+Drain (mapdist=0)***********************************************************/
      /* for (x=0; x<XSIZE; x+=4) { /* mapped to while() on BR[15][0][0]                                */
      /*   mo4(LDRQ,  1, src1, A[y], x, msk, A[y], 0, XSIZE, 0, A[y+1]); lmr+lmp prefetch               */
      /*   mo4(LDRQ,  1, src2, B[y], x, msk, B[y], 0, XSIZE, 0, B[y+1]); lmr+lmp prefetch               */
      /*   mo4(LDRQ,  1, src3, C[y], x, msk, C[y], 0, XSIZE, 0, C[y+1]); lmr+lmp prefetch               */
      /*                        ●7 lmmc=lmp,lmmo.top+ofs!=lmmc.topの場合, load top+ofs before next exec*/
      /*   ex4(FMAQ, src1, src2, src3, dst1);                                                           */
      /*   mo4(STRQ,  1, dst1, D[y], x, msk, NULL, 0, XSIZE, 0, D[y-1]); lmd explicit late drain        */
      /*                        ●6 lmmc=lmd,dirty=1の場合, drain top+ofs with next exec                */
      /* }                                                                                              */
      /*************************************************************************************************************************************/
      /* 【FSM_DRAIN】                                                                                                                     */
      /* lmmo.v rw  f  p                                                                                lmmo_cur      lmmi_cur             */
      /*      1  1  0  0 ... lmw       lmmd=1のみ,必ず,regv前にdrain.終了時にlmmd=0                     store:d=1     --                   */
      /*      1  1  1  0 ... lmx       lmmd=1のみ,必ず,regv前にdrain.終了時にlmmd=0                     store:d=1     --                   */
      /*      1  1  0  1 ... lmd       drainは完了(dirty=0)しているので無視してよい                     drain済       --                   */
      /* 【FSM_LOAD】                                                                                                                      */
      /* lmmi.v rw  f  p                                                                                lmmo_cur      lmmi_cur             */
      /*      1  0  0  0 ... lmr       lmmoとlmmiが不一致ならdrainとregvの間にload(top)                 prefetch/--   reuse/mload          */
      /*      1  0  1  0 ... lmf       必ずdrainとregvの間にload                                        --            mload(always)        */
      /*      1  1  1  0 ... lmx       必ずdrainとregvの間にload                                        --            store:d=1            */
      /* 【FSM_EXEC】lmm_store開始と同時にlmmd=1                                                                                           */
      /* lmmi.v rw  f  p                                                                                lmmo_cur      lmmi_cur             */
      /*      1  0  0  1 ... lmp       必ずexecと同時にloadする(top+ofs)                                prefetch/--   reuse/prefetch       */
      /*      1  1  0  0 ... lmw                                                                        --            store:d=1            */
      /*      1  1  0  1 ... lmd       lmmd=1のみ,execと同時にdrain.終了時にlmmd=0                      store:d=1     d=1時のみdrain       */
      /*                               最後のlmdを追い出すためには明示的drain指示(startとは別コマンド)が必要                               */
      /*      1  0  1  1 ... LDDMQ                                                                      --            lddmq                */
      /*      1  1  1  1 ... TR                                                                         --            tr                   */
      /*************************************************************************************************************************************/
    case STATUS_CONF:
    case STATUS_REGV:
    case STATUS_LMMI:
    case STATUS_DRAIN:
    case STATUS_LOAD:
    case STATUS_EXEC: /* simulate from stage15 to stage0, from col=3 to col=0 */
      switch (emax5[cid].status) {
      case STATUS_CONF:  emax5[cid].cycles_conf_part++;  break;
      case STATUS_REGV:  emax5[cid].cycles_regv_part++;  break;
      case STATUS_LMMI:  emax5[cid].cycles_lmmi_part++;  break;
      case STATUS_DRAIN: emax5[cid].cycles_drain_part++; break;
      case STATUS_LOAD:  emax5[cid].cycles_load_part++;  break;
      case STATUS_EXEC:  emax5[cid].cycles_exec_part++;  break;
      }
      for (sync=1,j=0; j<EMAX_WIDTH; j++) {
#ifndef IGNORE_LDDMQ_HANDSHAKE
        if (emax5[cid].unit1_exec || emax5[cid].unit2_exec || emax5[cid].unit2_lmbusy) /* exec not finished */
#else
        if (emax5[cid].unit1_exec || emax5[cid].unit2_exec                           ) /* exec not finished */
#endif
          sync = 0; /* not finished */
        i = emax5[cid].fsm[j].row_count;
        if (i < EMAX_DEPTH) {
	  int lmmc_topz =  (emax5[cid].fsm[j].lmmc[i].top == 0);
	  int lmmc_ofsz =  (emax5[cid].fsm[j].lmmc[i].ofs == 0);
          int lmmo_stat = ((emax5[cid].fsm[j].lmmo[i].v                                  )<<3)
	                  |(emax5[cid].fsm[j].lmmo[i].rw<<2)|(emax5[cid].fsm[j].lmmo[i].f<<1)|(emax5[cid].fsm[j].lmmo[i].p); /* v|rw|f|p */
          int lmmc_stat = ((emax5[cid].fsm[j].lmmc[i].v & ~emax5[cid].fsm[j].lmmc[i].copy & ((emax5[cid].fsm[j].lmmc[i].f&emax5[cid].fsm[j].lmmc[i].p) | !lmmc_topz))<<3)
                                                                                       	                                     /* v= ~copy & (OP_LDDMQ/OP_TR または ptop!=NULL) */
	                  |(emax5[cid].fsm[j].lmmc[i].rw<<2)|(emax5[cid].fsm[j].lmmc[i].f<<1)|(emax5[cid].fsm[j].lmmc[i].p); /* v|rw|f|p */
          int lmm_ready =  (emax5[cid].fsm[j].lmmo[i].v && emax5[cid].fsm[j].lmmo[i].blk == emax5[cid].fsm[j].lmmc[i].blk
	                                                && emax5[cid].fsm[j].lmmo[i].len == emax5[cid].fsm[j].lmmc[i].len
	                                                && emax5[cid].fsm[j].lmmo[i].top == emax5[cid].fsm[j].lmmc[i].top);
	  int lmm_readz =  (emax5[cid].fsm[j].lmmo[i].v && emax5[cid].fsm[j].lmmo[i].blk == emax5[cid].fsm[j].lmmc[i].blk
                                                        && emax5[cid].fsm[j].lmmo[i].len == emax5[cid].fsm[j].lmmc[i].len
                                                        &&(emax5[cid].fsm[j].lmmo[i].top+(Sll)(int)emax5[cid].fsm[j].lmmo[i].ofs) == emax5[cid].fsm[j].lmmc[i].top);
	  Ull ofs;
	  switch (emax5[cid].status) {
	  case STATUS_CONF:                                      mark = 1; break; /* load */
	  case STATUS_REGV:                                      mark = 1; break; /* load */
	  case STATUS_LMMI:                                      mark = 1; break; /* load */
          case STATUS_DRAIN:
            if      (mode==1 && (lmmo_stat==12 && lmmc_stat!=13) && emax5[cid].fsm[j].lmmd[i]) mark = 1; /* ●2 lmw&!lmd drain */
            else if (mode==1 && (lmmo_stat==14                 ) && emax5[cid].fsm[j].lmmd[i]) mark = 1; /* ●4 lmx      drain */
            else if (mode==2 &&                                     emax5[cid].fsm[j].lmmd[i]) mark = 1; /* ☆  drain_dirty_lmm */
            else                                                                               mark = 0; /* skip drain */
	    break;
	  case STATUS_LOAD:
            if      (lmmc_stat== 8               && !lmm_ready)  mark = 1; /* ●1 lmr & !ready */
            else if (lmmc_stat== 9 && !lmmc_ofsz && !lmm_readz)  mark = 1; /* ●7 lmr & !readz */
            else if (lmmc_stat==10 || lmmc_stat==14)             mark = 1; /* ●3 lmf/lmx always load */
            else                                                 mark = 0; /* skip load */
	    break;
	  case STATUS_EXEC:
	    /* ●●● OP_IM_PREF,OP_IM_DRAIN,OP_LDDMQ,OP_TRが処理対象 ●●● */
	    /*  OP_IM_PREF:  ofsz=0,v=1,rw=0,f=0,p=1 lmmc_stat==9  */
	    /*  OP_IM_PREF:  ofsz=1,v=1,rw=0,f=0,p=1 lmmc_stat==9  */
	    /*  OP_IM_DRAIN: ofsz=0,v=1,rw=1,f=0,p=1 lmmc_stat==13 */
	    /*  OP_IM_DRAIN: ofsz=1,v=1,rw=1,f=0,p=1 lmmc_stat==13 */
	    /*  OP_LDDMQ:           v=1,rw=0,f=1,p=1 lmmc_stat==11 */
	    /*  OP_TR:              v=1,rw=1,f=1,p=1 lmmc_stat==15 */
	    /* ●●● 同一列に複数リクエストがある場合は当面考えない ●●● */
	    /*  PREFとDRAINはEXEC以外でもよいが,LDDMQとTR(f=1,p=1)はEXEC時に要対応 */
	    /*    ・LDDMQはAXIにRead-req送出,Data受取り,lmwd書き込み */
	    /*    ・TRはEMAX制御Regにストア,ARM引き継ぎ              */
            if      (lmmc_stat== 9                             ) mark = 1; /* ●5 lmp */
            else if (lmmc_stat==13 && emax5[cid].fsm[j].lmmd[i]) mark = 1; /* ●6 lmd & dirty */
#ifndef IGNORE_LDDMQ_HANDSHAKE
	    else if (lmmc_stat==11                             ) mark = 1; /*     LDDMQ */
	    else if (lmmc_stat==15                             ) mark = 1; /*     TR */
#endif
            else                                                 mark = 0; /* skip pdrain/pload */
	    break;
          }
#if 0
	  switch (emax5[cid].status) {
	  case STATUS_DRAIN:
	  case STATUS_LOAD:
	  case STATUS_EXEC:
	    printf("status=%d lmm[row=%d][col=%d]: lmmo_stat=%d lmmc_stat=%d lmm_ready=%d mark=%d\n",
		   emax5[cid].status, i, j, lmmo_stat, lmmc_stat, lmm_ready, mark);
	    break;
	  }
#endif
	  /* UNIT <=> 主記憶転送対象検出 */
          if (mark) {
            switch (emax5[cid].fsm[j].memif_status) {
            case MEMIF_AREQ:
	      if (!emax5[cid].fsm[j].axi_awvalid && !emax5[cid].fsm[j].axi_arvalid) {
		/*****************************************/
		/* AXI用加工前アドレスおよび長さをセット */
		/*****************************************/
		if (emax5[cid].status==STATUS_CONF) {
		  emax5[cid].fsm[j].axi_arvalid = 1;
		  emax5[cid].fsm[j].araddr = conf+sizeof(Ull)*UNIT_WIDTH*EMAX_DEPTH*j; /* address should be 32B-aligned */
		  emax5[cid].fsm[j].arlen  =                  UNIT_WIDTH*EMAX_DEPTH-1; /* length should be # of dwords */
		  if ((flag & DUMP_DDR) && !dump_ddr_done) { /* dump once */
		    int i;
		    conf_p = (Ull*)(base+emax5[cid].fsm[j].araddr);
		    printf(" EMAX_DUMP_DDR(conf=%08.8x_%08.8x)\n", (Uint)(emax5[cid].fsm[j].araddr>>32), (Uint)emax5[cid].fsm[j].araddr);
		    if (emax5[cid].fsm[j].araddr == conf)
		      fprintf(fp_conf, "ddr_conf_top = 40\'h%08.8x;\n", (Uint)emax5[cid].fsm[j].araddr);
		    for (i=0; i<=emax5[cid].fsm[j].arlen*sizeof(Ull); i+=sizeof(Ull),conf_p++)
		      fprintf(fp_conf, "HOST_DDR_W(40\'h%08.8x, 64'h%08.8x_%08.8x);\n", (Uint)emax5[cid].fsm[j].araddr+i, (Uint)((*conf_p)>>32), (Uint)(*conf_p));
		  }
		}
		else if (emax5[cid].status==STATUS_REGV) {
		  emax5[cid].fsm[j].axi_arvalid = 1;
		  emax5[cid].fsm[j].araddr = regv+sizeof(Ull)*UNIT_WIDTH*2*EMAX_DEPTH*j; /* address should be 32B-aligned */
		  emax5[cid].fsm[j].arlen  =                  UNIT_WIDTH*2*EMAX_DEPTH-1; /* length should be # of dwords */
		  if ((flag & DUMP_DDR) && !dump_ddr_done) { /* dump once */
		    int i;
		    regv_p = (Ull*)(base+emax5[cid].fsm[j].araddr);
		    printf(" EMAX_DUMP_DDR(regv=%08.8x_%08.8x)\n", (Uint)(emax5[cid].fsm[j].araddr>>32), (Uint)emax5[cid].fsm[j].araddr);
		    if (emax5[cid].fsm[j].araddr == regv)
		      fprintf(fp_regv, "ddr_regv_top = 40\'h%08.8x;\n", (Uint)emax5[cid].fsm[j].araddr);
		    for (i=0; i<=emax5[cid].fsm[j].arlen*sizeof(Ull); i+=sizeof(Ull),regv_p++)
		      fprintf(fp_regv, "HOST_DDR_W(40\'h%08.8x, 64'h%08.8x_%08.8x);\n", (Uint)emax5[cid].fsm[j].araddr+i, (Uint)((*regv_p)>>32), (Uint)(*regv_p));
		  }
		}
		else if (emax5[cid].status==STATUS_LMMI) {
		  emax5[cid].fsm[j].axi_arvalid = 1;
		  emax5[cid].fsm[j].araddr = lmmi+sizeof(Ull)*UNIT_WIDTH/2*EMAX_DEPTH*j; /* address should be 32B-aligned */
		  emax5[cid].fsm[j].arlen  =                  UNIT_WIDTH/2*EMAX_DEPTH-1; /* length should be # of dwords */
		  if ((flag & DUMP_DDR) && !dump_ddr_done) { /* dump once */
		    int i;
		    lmmi_p = (Ull*)(base+emax5[cid].fsm[j].araddr);
		    printf(" EMAX_DUMP_DDR(lmmi=%08.8x_%08.8x)\n", (Uint)(emax5[cid].fsm[j].araddr>>32), (Uint)emax5[cid].fsm[j].araddr);
		    if (emax5[cid].fsm[j].araddr == lmmi)
		      fprintf(fp_lmmi, "ddr_lmmi_top = 40\'h%08.8x;\n", (Uint)emax5[cid].fsm[j].araddr);
		    for (i=0; i<=emax5[cid].fsm[j].arlen*sizeof(Ull); i+=sizeof(Ull),lmmi_p++)
		      fprintf(fp_lmmi, "HOST_DDR_W(40\'h%08.8x, 64'h%08.8x_%08.8x);\n", (Uint)emax5[cid].fsm[j].araddr+i, (Uint)(*(lmmi_p)>>32), (Uint)(*lmmi_p));
		  }
		}
#ifndef IGNORE_LDDMQ_HANDSHAKE
		else if (emax5[cid].status==STATUS_EXEC && lmmc_stat==11) { /* LDDMQ lmm->lmrd(addr) */
                  if (unit[cid][i][j].rrdy) {
		    emax5[cid].fsm[j].axi_arvalid = 1;
		    emax5[cid].fsm[j].araddr = emax5[cid].fsm[j].lmrd[0]; /* lmm->lmrd(addr) */
		    emax5[cid].fsm[j].arlen  = UNIT_WIDTH-1; /* length should be # of dwords */
		    if (trace)
		      printf("%03.3d:siml_emax5: LDDMQ AREQ1 row=%d col=%d araddr=%08.8x\n", tid, i, j, (Uint)emax5[cid].fsm[j].araddr);
		  }
		}
		else if (emax5[cid].status==STATUS_EXEC && lmmc_stat==15) { /* TR lmm->lmrd(addr) */
                  if (unit[cid][i][j].rrdy) {
		    emax5[cid].fsm[j].tcureg_valid = 1;
		    for (k=0; k<UNIT_WIDTH; k++)
		      emax5[cid].fsm[j].tcureg[k] = emax5[cid].fsm[j].lmrd[k]; /* lmm->lmrd(addr) */
		    if (trace)
		      printf("%03.3d:siml_emax5: TR RRDY row=%d col=%d tcureg[3:0]=%08.8x %08.8x %08.8x %08.8x\n", tid, i, j, (Uint)emax5[cid].fsm[j].tcureg[3], (Uint)emax5[cid].fsm[j].tcureg[2], (Uint)emax5[cid].fsm[j].tcureg[1], (Uint)emax5[cid].fsm[j].tcureg[0]);
		  }
		  else if (emax5[cid].fsm[j].tcureg_ready) {
		    emax5[cid].fsm[j].tcureg_valid = 0;
		    emax5[cid].fsm[j].tcureg_ready = 0;
		    emax5[cid].fsm[j].fsm_busy     = 0;
		  }
		  if (!(emax5[cid].unit1_exec || emax5[cid].unit2_exec || (emax5[cid].unit2_lmbusy & (1LL<<i)))) { /* if last transaction */
		    if (trace && emax5[cid].fsm[j].tcureg_last==0)
		      printf("%03.3d:siml_emax5: TR TCUREG_LAST=1 row=%d col=%d\n", tid, i, j);
		    emax5[cid].fsm[j].tcureg_last = 1;
		  }
		}
#endif
		else if (emax5[cid].status==STATUS_DRAIN) { /* drain */
		  emax5[cid].fsm[j].axi_awvalid = 1;
		  emax5[cid].fsm[j].awaddr = (mode==1)?emax5[cid].fsm[j].lmmo[i].top:emax5[cid].fsm[j].lmmc[i].top; /* address should be 8B-aligned */
		  emax5[cid].fsm[j].awlen  = (mode==1)?emax5[cid].fsm[j].lmmo[i].len:emax5[cid].fsm[j].lmmc[i].len; /* length should be # of dwords */
		}
		else if (emax5[cid].status==STATUS_EXEC && emax5[cid].fsm[j].lmmc[i].rw==1) { /* pdrain */
		  emax5[cid].fsm[j].axi_awvalid = 1;
		  emax5[cid].fsm[j].awaddr = emax5[cid].fsm[j].lmmc[i].top+(Sll)(int)emax5[cid].fsm[j].lmmc[i].ofs; /* address should be 8B-aligned */
		  emax5[cid].fsm[j].awlen  = emax5[cid].fsm[j].lmmc[i].len; /* length should be # of dwords */
		}
		/*** NORMAL ************/
		/* --- single-load --- : fsmが1回のみburst起動                              */
		/* align=8B,  block=0, blocking=none             ... 下位5bit無視 4倍幅load */
		/* align=16B, block=0, blocking=none             ... 下位5bit無視 4倍幅load */
		/* align=32B, block=0, blocking=none             ... align済      4倍幅load */
		
		/*** GATHER ************/
		/* --- blocking-load --- : fsmがblock単位にburst起動                        */
		/* align=32B, block=1, blocksize=8*4*16=512B *MAXPAGE_PVE = 64KB  for LMM   */
		/* align=32B, block=2, blocksize=8*4*32=1KB  *MAXPAGE_PVE = 128KB for LMM   */
		/* align=32B, block=3, blocksize=8*4*64=2KB  *MAXPAGE_PVE = 256KB for LMM   */ 
		
		/* 総転送topは,emax5[cid].fsm[j].lmmc[i].top                                */
		/*  pref_topは,emax5[cid].fsm[j].lmmc[i].top+emax5[cid].fsm[j].lmmc[i].ofs  */
		/* 総転送lenは,emax5[cid].fsm[j].lmmc[i].len                                */
		/*                blkstat    = 0                                            */
		/*                blkcount   = 0                                            */
		/*                             emax5[cid].fsm[j].lmmc[i].len/blksize 7bit   */
		/*                                                 MAX= 64KB/MAX=512 7bit   */
		/*                                                 MAX=128KB/MAX=1KB 7bit   */
		/*                                                 MAX=256KB/MAX=2KB 7bit   */
		/*                blktop[4]    (ddr-data -> ddr-addr)                       */
		/*                lmmblktop  = 0                                            */
		/*                lmmblklen  = emax5[cid].fsm[j].lmmc[i].len #dwords        */
		/* MEMIF_AREQ:                                                              */
		/*                  memif_status = MEMIF_DREQ                               */
		/*                  ardyc     = 0                             #4dwords      */
		/*                  rrdyc     = 0                             #4dwords      */
		/*  FSM_BLKSTAT=0:  araddr    = emax5[cid].fsm[j].lmmc[i].top(+ofs)+blkcount/4*32 */
		/*                  arlen     = 3 (64bit*4) 使用dataは64bit*4               */
		/*                  blksize   = 32<<lmm.blk                   #dwords       */
		/*  FSM_BLKSTAT=1:  araddr    = blktop[blkcount%4]                          */
		/*                  arlen     = (lmmblklen<blksize)?lmmblklen:blksize       */
		/*                  lmmblklen = (lmmblklen<blksize)?0:(lmmblklen-blksize)   */
		/*                lmm_nreq  = arlen/UNIT_WIDTH                              */
		/* MEMIF_DREQ:                                                              */
		/*  FSM_BLKSTAT=0: blktop[3:0]  = axi_rdata[3:0] .. 有効ptrが最大4個        */
		/*                 FSM_BLKSTAT  = 1                                         */
		/*                 memif_status = MEMIF_AREQ                                */
		/*  FSM_BLKSTAT=1: if (rrdyc<lmm_nreq)                                      */
		/*                   lmwa    = lmmblktop+rrdyc*32                           */
		/*                 else                                                     */
		/*                   if ((blkcount&3)==3 || lmmblklen==0) FSM_BLKSTAT = 0   */
		/*                   if (lmmblklen==0) { row_count++; blkcount=0}           */
		/*                   else              { blkcount++ }                       */
		/*                   lmmblktop += blksize*8                                 */
		/*                   memif_status = MEMIF_AREQ                              */
		/*                 if (axi_rvalid)                                          */
		/*                   lmwd[4] = axi_rdata[4]                                 */
		/*                   rrdyc++                                                */
		else if (emax5[cid].status==STATUS_LOAD                                        /* load */
                      ||(emax5[cid].status==STATUS_EXEC && emax5[cid].fsm[j].lmmc[i].rw==0)) { /* pload *//* address should be 8B-aligned *//* length should be # of dwords */
		  emax5[cid].fsm[j].axi_arvalid = 1;
		  if (emax5[cid].fsm[j].lmmc[i].blk==0) { /* inf */
		    if (emax5[cid].status==STATUS_LOAD)
		      emax5[cid].fsm[j].araddr = emax5[cid].fsm[j].lmmc[i].top; /* address should be 8B-aligned */
		    else
		      emax5[cid].fsm[j].araddr = emax5[cid].fsm[j].lmmc[i].top+(Sll)(int)emax5[cid].fsm[j].lmmc[i].ofs; /* address should be 8B-aligned */
		    emax5[cid].fsm[j].arlen      = emax5[cid].fsm[j].lmmc[i].len; /* length should be # of dwords */
#ifndef IGNORE_LMMI_BLKGATHER
		    emax5[cid].fsm[j].blksize    = 0; /* max:10bit */
#endif
		  }
#ifndef IGNORE_LMMI_BLKGATHER
		  else { /* 16,32,64 */
		    switch (emax5[cid].fsm[j].blkstat) {
		    case 0: /* PTRLIST */
		      if (emax5[cid].status==STATUS_LOAD)
			emax5[cid].fsm[j].araddr = emax5[cid].fsm[j].lmmc[i].top+emax5[cid].fsm[j].blkcount/4*32; /* address should be 8B-aligned */
		      else
			emax5[cid].fsm[j].araddr = emax5[cid].fsm[j].lmmc[i].top+emax5[cid].fsm[j].blkcount/4*32+(Sll)(int)emax5[cid].fsm[j].lmmc[i].ofs; /* address should be 8B-aligned */
		      emax5[cid].fsm[j].arlen     = 3; /* 4 dwords */
		      emax5[cid].fsm[j].blksize   = 32<<emax5[cid].fsm[j].lmmc[i].blk; /* max:10bit */
		      if (emax5[cid].fsm[j].blkcount==0) {
			emax5[cid].fsm[j].lmmblktop = 0;
			emax5[cid].fsm[j].lmmblklen = emax5[cid].fsm[j].lmmc[i].len; /* length should be # of dwords */
		      }
		      break;
		    case 1: /* VERTEXLIST */
		      emax5[cid].fsm[j].araddr    = emax5[cid].fsm[j].blktop[emax5[cid].fsm[j].blkcount%4]; /* address should be 8B-aligned */
		      emax5[cid].fsm[j].arlen     = (emax5[cid].fsm[j].lmmblklen<emax5[cid].fsm[j].blksize)?emax5[cid].fsm[j].lmmblklen:emax5[cid].fsm[j].blksize-1;
		      emax5[cid].fsm[j].lmmblklen = (emax5[cid].fsm[j].lmmblklen<emax5[cid].fsm[j].blksize)?0:(emax5[cid].fsm[j].lmmblklen-emax5[cid].fsm[j].blksize);
		      break;
		    }
		  }
#endif
		  if ((flag & DUMP_DDR) && !dump_ddr_done) { /* dump once */
		    int i;
		    load_p = (Ull*)(base+emax5[cid].fsm[j].araddr);
		    printf(" EMAX_DUMP_DDR(load=%08.8x_%08.8x)\n", (Uint)(emax5[cid].fsm[j].araddr>>32), (Uint)emax5[cid].fsm[j].araddr);
		    for (i=0; i<=emax5[cid].fsm[j].arlen*sizeof(Ull); i+=sizeof(Ull),load_p++)
		      fprintf(fp_load, "HOST_DDR_W(40\'h%08.8x, 64'h%08.8x_%08.8x);\n", (Uint)emax5[cid].fsm[j].araddr+i, (Uint)(*(load_p)>>32), (Uint)(*load_p));
		  }
		}
		/*************************************/
		/* check align and set mask/lmm_nreq */
		/*************************************/
		if      (emax5[cid].status==STATUS_CONF || emax5[cid].status==STATUS_REGV || emax5[cid].status==STATUS_LMMI) { /* address should be 32B-aligned *//* length should be # of dwords */
		  emax5[cid].fsm[j].lmm_nreq   = emax5[cid].fsm[j].arlen/UNIT_WIDTH;
		  emax5[cid].fsm[j].axi_araddr = emax5[cid].fsm[j].araddr;
		  emax5[cid].fsm[j].axi_arlen  = emax5[cid].fsm[j].lmm_nreq;
		}
#ifndef IGNORE_LDDMQ_HANDSHAKE
		else if (emax5[cid].status==STATUS_EXEC && lmmc_stat==11) { /* LDDMQ lmm->lmrd(addr) */
		  emax5[cid].fsm[j].lmm_nreq   = emax5[cid].fsm[j].arlen/UNIT_WIDTH;
		  emax5[cid].fsm[j].axi_araddr = emax5[cid].fsm[j].araddr;
		  emax5[cid].fsm[j].axi_arlen  = emax5[cid].fsm[j].lmm_nreq;
		}
		else if (emax5[cid].status==STATUS_EXEC && lmmc_stat==15) { /* TR lmm->lmrd(addr) */
		  emax5[cid].fsm[j].lmm_nreq   = 0;
                  /* do nothing */
		}
#endif
		else if (emax5[cid].status==STATUS_DRAIN                                       /* drain */
		      ||(emax5[cid].status==STATUS_EXEC && emax5[cid].fsm[j].lmmc[i].rw==1)) { /* pdrain *//* address should be 8B-aligned *//* length should be # of dwords */
		  emax5[cid].fsm[j].lmm_fmask = 0xf << ( (emax5[cid].fsm[j].awaddr/sizeof(Ull)                        ) & (UNIT_WIDTH-1));
		  emax5[cid].fsm[j].lmm_lmask = 0xf >> (~(emax5[cid].fsm[j].awaddr/sizeof(Ull)+emax5[cid].fsm[j].awlen) & (UNIT_WIDTH-1));
		  emax5[cid].fsm[j].lmm_nreq  = ((emax5[cid].fsm[j].awaddr/sizeof(Ull)+emax5[cid].fsm[j].awlen)/UNIT_WIDTH) - ((emax5[cid].fsm[j].awaddr/sizeof(Ull))/UNIT_WIDTH); /* 0:1cycle, 1:2cycle */
		  emax5[cid].fsm[j].axi_awaddr = emax5[cid].fsm[j].awaddr & ~(sizeof(Ull)*UNIT_WIDTH-1);
		  emax5[cid].fsm[j].axi_awlen  = emax5[cid].fsm[j].lmm_nreq;
		  if (emax5[cid].fsm[j].lmm_nreq==0) {
		    emax5[cid].fsm[j].lmm_fmask &= emax5[cid].fsm[j].lmm_lmask;
		    emax5[cid].fsm[j].lmm_lmask &= emax5[cid].fsm[j].lmm_fmask;
		  }
		}
		else if (emax5[cid].status==STATUS_LOAD                                        /* load */
                      ||(emax5[cid].status==STATUS_EXEC && emax5[cid].fsm[j].lmmc[i].rw==0)) { /* pload *//* address should be 8B-aligned *//* length should be # of dwords */
		  emax5[cid].fsm[j].lmm_fmask = 0xf << ( (emax5[cid].fsm[j].araddr/sizeof(Ull)                        ) & (UNIT_WIDTH-1));
		  emax5[cid].fsm[j].lmm_lmask = 0xf >> (~(emax5[cid].fsm[j].araddr/sizeof(Ull)+emax5[cid].fsm[j].arlen) & (UNIT_WIDTH-1));
		  emax5[cid].fsm[j].lmm_nreq  = ((emax5[cid].fsm[j].araddr/sizeof(Ull)+emax5[cid].fsm[j].arlen)/UNIT_WIDTH) - ((emax5[cid].fsm[j].araddr/sizeof(Ull))/UNIT_WIDTH); /* 0:1cycle, 1:2cycle */
		  emax5[cid].fsm[j].axi_araddr = emax5[cid].fsm[j].araddr & ~(sizeof(Ull)*UNIT_WIDTH-1);
		  emax5[cid].fsm[j].axi_arlen  = emax5[cid].fsm[j].lmm_nreq;
		  if (emax5[cid].fsm[j].lmm_nreq==0) {
		    emax5[cid].fsm[j].lmm_fmask &= emax5[cid].fsm[j].lmm_lmask;
		    emax5[cid].fsm[j].lmm_lmask &= emax5[cid].fsm[j].lmm_fmask;
		  }
		}
		if (emax5[cid].fsm[j].lmm_nreq >= LMEM_SIZE/(sizeof(Ull)*UNIT_WIDTH)) { /* LMM overflow */
		  printf("%03.3d:siml_emax5: row=%d col=%d LMM overflow lmm_nreq=%d (>= %d)\n",
			 tid, i, j, emax5[cid].fsm[j].lmm_nreq, LMEM_SIZE/(sizeof(Ull)*UNIT_WIDTH));
		  exit(1);
		}
	      }
	      else if (emax5[cid].fsm[j].axi_awready || emax5[cid].fsm[j].axi_arready) {
		emax5[cid].fsm[j].memif_status = MEMIF_DREQ;
		emax5[cid].fsm[j].ardyc = 0; /* LMM addr-ready(read)                                 */
		emax5[cid].fsm[j].rrdyc = 0; /* LMM data-ready(read), AXI data-ready(rvalid) counter */
		if      (emax5[cid].status==STATUS_CONF || emax5[cid].status==STATUS_REGV || emax5[cid].status==STATUS_LMMI)
		  emax5[cid].fsm[j].axi_arvalid = 0;
#ifndef IGNORE_LDDMQ_HANDSHAKE
		else if (emax5[cid].status==STATUS_EXEC && lmmc_stat==11) { /* LDDMQ lmm->lmrd(addr) */
                  emax5[cid].fsm[j].axi_arvalid = 0;
		}
		else if (emax5[cid].status==STATUS_EXEC && lmmc_stat==15) { /* TR lmm->lmrd(addr) */
                  /* do nothing */
		}
#endif
		else if (emax5[cid].status==STATUS_DRAIN                                     /* drain */
                      ||(emax5[cid].status==STATUS_EXEC && emax5[cid].fsm[j].lmmc[i].rw==1)) /* pdrain */
		  emax5[cid].fsm[j].axi_awvalid = 0;
		else /* STATUS_LOAD, STATUS_EXEC&rw==0 */
		  emax5[cid].fsm[j].axi_arvalid = 0;
	      }
              break;
            case MEMIF_DREQ:
#ifndef IGNORE_LDDMQ_HANDSHAKE
	      /************************************************************************/
	      /************************************************************************/
	      if (emax5[cid].status==STATUS_EXEC && lmmc_stat==11) { /* LDDMQ lmm->lmwd(data) */
		if (emax5[cid].fsm[j].rrdyc <= emax5[cid].fsm[j].lmm_nreq) {
		  /* do nothing */
		}		
		else {
		  emax5[cid].fsm[j].memif_status = MEMIF_AREQ;
		}
		if (emax5[cid].fsm[j].axi_rvalid) {
		  emax5[cid].fsm[j].fsm_busy = 0;
		  for (k=0; k<UNIT_WIDTH; k++) {
		    emax5[cid].fsm[j].lmwd[k] = emax5[cid].fsm[j].axi_rdata[k];
		    if (trace)
		      printf("%03.3d:siml_emax5: load row=%d col=%d lmwd[%d]=%08.8x_%08.8x (%d/%d)\n",
			     tid, i, j, k, (Uint)(emax5[cid].fsm[j].lmwd[k]>>32), (Uint)emax5[cid].fsm[j].lmwd[k], emax5[cid].fsm[j].rrdyc, emax5[cid].fsm[j].lmm_nreq);
		  }
		  emax5[cid].fsm[j].lmwd_valid = 1;
		  emax5[cid].fsm[j].rrdyc++;
		}
		else {
		  emax5[cid].fsm[j].lmwd_valid = 0;
		}
	      }
	      /************************************************************************/
	      /************************************************************************/
	      else if (emax5[cid].status==STATUS_EXEC && lmmc_stat==15) { /* TR lmm->lmwd(addr) */
		/* do nothing */
	      }
	      else
#endif
	      /************************************************************************/
	      /************************************************************************/
              if (emax5[cid].status==STATUS_DRAIN                                       /* drain */
                    ||(emax5[cid].status==STATUS_EXEC && emax5[cid].fsm[j].lmmc[i].rw==1)) { /* pdrain */
		if (emax5[cid].fsm[j].ardyc <= emax5[cid].fsm[j].lmm_nreq) {
		  /**********************/
		  /* row_selectをセット */
		  /**********************/
		  switch (emax5[cid].status) {
		  case STATUS_DRAIN: case STATUS_EXEC:
		    emax5[cid].fsm[j].row_select |= (1LL<<i);
		    emax5[cid].fsm[j].row_lmm_en |= (1LL<<i);
		    break;
		  }
		  /************************/
		  /* generate lmm address */
		  /************************/
		  emax5[cid].fsm[j].lmra = (emax5[cid].fsm[j].awaddr & ~(sizeof(Ull)*UNIT_WIDTH-1)) + emax5[cid].fsm[j].ardyc*sizeof(Ull)*UNIT_WIDTH;
		  if (trace) {
		    printf("%03.3d:siml_emax5: drain row=%d col=%d lmra=%08.8x_%08.8x (%d/%d)\n",
			   tid, i, j, (Uint)(emax5[cid].fsm[j].lmra>>32), (Uint)emax5[cid].fsm[j].lmra, emax5[cid].fsm[j].ardyc, emax5[cid].fsm[j].lmm_nreq);
		  }
		  emax5[cid].fsm[j].ardyc++;
		}
		else { /* バースト転送終了#1 */
		  emax5[cid].fsm[j].row_lmm_en &= ~(1LL<<i);
		}
		if (emax5[cid].fsm[j].rrdyc <= emax5[cid].fsm[j].lmm_nreq) {
		  /*********************************************/
		  /* LMMからのrrdy到着データを主記憶へ書き込み */
		  /*********************************************/
		  if (unit[cid][i][j].rrdy) { /* ack from lmm */
		    if (emax5[cid].fsm[j].rrdyc == 0)
		      emax5[cid].fsm[j].axi_wstrb = ((emax5[cid].fsm[j].lmm_fmask&8)?0xff000000:0)
		                                  | ((emax5[cid].fsm[j].lmm_fmask&4)?0x00ff0000:0)
		                                  | ((emax5[cid].fsm[j].lmm_fmask&2)?0x0000ff00:0)
		                                  | ((emax5[cid].fsm[j].lmm_fmask&1)?0x000000ff:0);
		    else if (emax5[cid].fsm[j].rrdyc == emax5[cid].fsm[j].lmm_nreq)
		      emax5[cid].fsm[j].axi_wstrb = ((emax5[cid].fsm[j].lmm_lmask&8)?0xff000000:0)
		                                  | ((emax5[cid].fsm[j].lmm_lmask&4)?0x00ff0000:0)
		                                  | ((emax5[cid].fsm[j].lmm_lmask&2)?0x0000ff00:0)
		                                  | ((emax5[cid].fsm[j].lmm_lmask&1)?0x000000ff:0);
		    else
		      emax5[cid].fsm[j].axi_wstrb = 0xffffffff;
		    emax5[cid].fsm[j].axi_wvalid = 1;
		    for (k=0; k<UNIT_WIDTH; k++) { /* 32B aligned */
		      emax5[cid].fsm[j].axi_wdata[k] = emax5[cid].fsm[j].lmrd[k];
		      if (trace)
			printf("%03.3d:siml_emax5: drain row=%d col=%d lmrd[%d]=%08.8x_%08.8x (%d/%d)\n",
			       tid, i, j, k, (Uint)(emax5[cid].fsm[j].lmrd[k]>>32), (Uint)emax5[cid].fsm[j].lmrd[k], emax5[cid].fsm[j].rrdyc, emax5[cid].fsm[j].lmm_nreq);
		    }
		    emax5[cid].fsm[j].rrdyc++;		
		  }
		  else
		    emax5[cid].fsm[j].axi_wvalid = 0;
		}
		else { /* バースト転送終了#2 */
		  emax5[cid].fsm[j].axi_wvalid = 0;
		  emax5[cid].fsm[j].lmmd[i] = 0;
		  emax5[cid].fsm[j].memif_status = MEMIF_AREQ;
		  emax5[cid].fsm[j].row_count++;
		  emax5[cid].fsm[j].row_select   = 0LL;
#ifndef IGNORE_LMMI_BLKGATHER
		  emax5[cid].fsm[j].blkstat  = 0; /* ptrlist */
		  emax5[cid].fsm[j].blkcount = 0; /* dword/dword: 7bit */
#endif
		}
	      }
	      /************************************************************************/
	      /************************************************************************/
	      else { /* STATUS_CONF, STATUS_REGV, STATUS_LMMI, STATUS_LOAD, STATUS_EXEC&rw==0 */
		if (emax5[cid].fsm[j].rrdyc <= emax5[cid].fsm[j].lmm_nreq) {
#if 0
		  /**********************/
		  /* row_selectをセット */
		  /**********************/
		  switch (emax5[cid].status) {
		  case STATUS_CONF: case STATUS_REGV: case STATUS_LMMI:
		    emax5[cid].fsm[j].row_select = 1LL<<((emax5[cid].last_row0+i)%EMAX_DEPTH); /* units ignore row_select in STATUS_LMMI */
		    break;
		  case STATUS_LOAD: case STATUS_EXEC:
		    /*emax5[cid].fsm[j].row_select |= (1LL<<i);*/
		    /*emax5[cid].fsm[j].row_lmm_en |= (1LL<<i);*//* wait for data arrived from MEM */
		    break;
		  }
#endif
		  /************************/
		  /* generate lmm address */
		  /************************/
		  if (emax5[cid].status==STATUS_CONF)
		    emax5[cid].fsm[j].lmwa = 0LL; /* fixed */
		  else if (emax5[cid].status==STATUS_REGV)
		    emax5[cid].fsm[j].lmwa = emax5[cid].fsm[j].rrdyc&1; /* even/odd */
		  else if (emax5[cid].status==STATUS_LOAD                                        /* load */
			||(emax5[cid].status==STATUS_EXEC && emax5[cid].fsm[j].lmmc[i].rw==0)) { /* pload */
		    if (emax5[cid].fsm[j].lmmc[i].blk==0) { /* inf */
		      emax5[cid].fsm[j].lmwa = (emax5[cid].fsm[j].araddr & ~(sizeof(Ull)*UNIT_WIDTH-1)) + emax5[cid].fsm[j].rrdyc*sizeof(Ull)*UNIT_WIDTH;
		      if (trace) {
			printf("%03.3d:siml_emax5: load0 row=%d col=%d lmwa=%08.8x_%08.8x (%d/%d)\n",
			       tid, i, j, (Uint)(emax5[cid].fsm[j].lmwa>>32), (Uint)emax5[cid].fsm[j].lmwa, emax5[cid].fsm[j].rrdyc, emax5[cid].fsm[j].lmm_nreq);
		      }
		    }
#ifndef IGNORE_LMMI_BLKGATHER
		    else { /* 16,32,64 */
		      switch (emax5[cid].fsm[j].blkstat) {
		      case 0: /* PTRLIST */
			/* no write to lmm */
			break;
		      case 1: /* VERTEXLIST */
			emax5[cid].fsm[j].lmwa = emax5[cid].fsm[j].lmmblktop + emax5[cid].fsm[j].rrdyc*sizeof(Ull)*UNIT_WIDTH;
			if (trace) {
			  printf("%03.3d:siml_emax5: load1 row=%d col=%d lmwa=%08.8x_%08.8x (%d/%d)\n",
				 tid, i, j, (Uint)(emax5[cid].fsm[j].lmwa>>32), (Uint)emax5[cid].fsm[j].lmwa, emax5[cid].fsm[j].rrdyc, emax5[cid].fsm[j].lmm_nreq);
			}
			break;
		      }
		    }
#endif
		  }
		}
		else { /* バースト転送終了#3 */
		  if      (emax5[cid].status==STATUS_CONF || emax5[cid].status==STATUS_REGV || emax5[cid].status==STATUS_LMMI) {
		    emax5[cid].fsm[j].memif_status = MEMIF_TERM;
		  //emax5[cid].fsm[j].row_select   = 0LL;
		  }
		  else if (emax5[cid].status==STATUS_LOAD                                        /* load */
                        ||(emax5[cid].status==STATUS_EXEC && emax5[cid].fsm[j].lmmc[i].rw==0)) { /* pload */
		    if (emax5[cid].fsm[j].lmmc[i].blk==0) { /* inf */
		      emax5[cid].fsm[j].memif_status = MEMIF_AREQ;
		      emax5[cid].fsm[j].row_count++;
		      emax5[cid].fsm[j].row_select &= ~(1LL<<i);
		      /*emax5[cid].fsm[j].row_lmm_en &= ~(1LL<<i);*//* wait for data arrived from MEM */
#ifndef IGNORE_LMMI_BLKGATHER
		      emax5[cid].fsm[j].blkstat  = 0; /* ptrlist */
		      emax5[cid].fsm[j].blkcount = 0; /* dword/dword: 7bit */
#endif
		    }
#ifndef IGNORE_LMMI_BLKGATHER
		    else { /* 16,32,64 */
		      switch (emax5[cid].fsm[j].blkstat) {
		      case 0: /* PTRLIST */
			emax5[cid].fsm[j].memif_status = MEMIF_AREQ;
			emax5[cid].fsm[j].blkstat = 1;
			break;
		      case 1: /* VERTEXLIST */
			if ((emax5[cid].fsm[j].blkcount&(UNIT_WIDTH-1))==(UNIT_WIDTH-1)
			  || emax5[cid].fsm[j].lmmblklen==0) /* current_row is finished */
			  emax5[cid].fsm[j].blkstat = 0; /* restart with new pointer */

			if (emax5[cid].fsm[j].lmmblklen==0) {
			  emax5[cid].fsm[j].blkcount = 0;
			  emax5[cid].fsm[j].row_count++; /* current_row is finished */
			}
			else
			  emax5[cid].fsm[j].blkcount++; /* continue */
			emax5[cid].fsm[j].memif_status = MEMIF_AREQ;
			emax5[cid].fsm[j].lmmblktop += emax5[cid].fsm[j].blksize*sizeof(Ull);
			break;
		      }
		    }
#endif
		  }
		}
		/**************************************************/
		/* MMEMからのrvalid到着データをUNIT/FSMへ書き込み */
		/**************************************************/
		if (emax5[cid].fsm[j].axi_rvalid) {
		  switch (emax5[cid].status) {
		  case STATUS_CONF:
		    emax5[cid].fsm[j].last_dist = ((struct conf*)&emax5[cid].fsm[j].axi_rdata)->cdw2.mapdist; /* mapdist */
		    emax5[cid].fsm[j].row_count++;
		    emax5[cid].fsm[j].row_select = 1LL<<((emax5[cid].last_row0+i)%EMAX_DEPTH); /* units ignore row_select in STATUS_LMMI */
		    break;
		  case STATUS_REGV:
		    emax5[cid].fsm[j].row_count+=(emax5[cid].fsm[j].rrdyc&1); /* even/odd */
		    emax5[cid].fsm[j].row_select = 1LL<<((emax5[cid].last_row0+i)%EMAX_DEPTH); /* units ignore row_select in STATUS_LMMI */
		    break;
		  case STATUS_LMMI:
		    emax5[cid].fsm[j].row_count+=2;
		    emax5[cid].fsm[j].row_select = 1LL<<((emax5[cid].last_row0+i)%EMAX_DEPTH); /* units ignore row_select in STATUS_LMMI */
		    break;
		  }
		  if (emax5[cid].status==STATUS_CONF || emax5[cid].status==STATUS_REGV
		   || emax5[cid].status==STATUS_LOAD                                        /* load */
                   ||(emax5[cid].status==STATUS_EXEC && emax5[cid].fsm[j].lmmc[i].rw==0)) { /* pload */
		    for (k=0; k<UNIT_WIDTH; k++) {
		      emax5[cid].fsm[j].lmwd[k] = emax5[cid].fsm[j].axi_rdata[k];
		      if (trace)
			printf("%03.3d:siml_emax5: load row=%d col=%d lmwd[%d]=%08.8x_%08.8x (%d/%d)\n",
			       tid, i, j, k, (Uint)(emax5[cid].fsm[j].lmwd[k]>>32), (Uint)emax5[cid].fsm[j].lmwd[k], emax5[cid].fsm[j].rrdyc, emax5[cid].fsm[j].lmm_nreq);
		    }
		    if (emax5[cid].status==STATUS_LOAD                                        /* load */
                     ||(emax5[cid].status==STATUS_EXEC && emax5[cid].fsm[j].lmmc[i].rw==0)) { /* pload */
		      if (emax5[cid].fsm[j].lmmc[i].blk==0) { /* inf */
			emax5[cid].fsm[j].row_lmm_en |= (1LL<<i); /* 水平方向broadcastの送出はここ */
			for (k=0; k<EMAX_WIDTH; k++) {
			  if (emax5[cid].fsm[j].lmmc[i].bcas & (1<<k))
			    emax5[cid].fsm[k].row_lmm_en |= (1LL<<i);
			}
		      }
#ifndef IGNORE_LMMI_BLKGATHER
		      else { /* 16,32,64 */
			switch (emax5[cid].fsm[j].blkstat) {
			case 0: /* PTRLIST */
			  for (k=0; k<UNIT_WIDTH; k++)
			    emax5[cid].fsm[j].blktop[k] = emax5[cid].fsm[j].axi_rdata[k];
			  break;
			case 1: /* VERTEXLIST */
			  emax5[cid].fsm[j].row_lmm_en |= (1LL<<i);
			  break;
			}
		      }
#endif
		    }
		  }
		  else if (emax5[cid].status==STATUS_LMMI) {
		    for (k=0; k<UNIT_WIDTH; k++) {
		      /* copy a pair of lmmo <- lmmc */
		      *(((Ull*)&emax5[cid].fsm[j].lmmo[(emax5[cid].last_row0+i+(k>>1))%EMAX_DEPTH])+(k&1)) = *(((Ull*)&emax5[cid].fsm[j].lmmc[(emax5[cid].last_row0+i+(k>>1))%EMAX_DEPTH])+(k&1));
		      /* copy a pair of lmmc <- rdata */
		      *(((Ull*)&emax5[cid].fsm[j].lmmc[(emax5[cid].last_row0+i+(k>>1))%EMAX_DEPTH])+(k&1)) = emax5[cid].fsm[j].axi_rdata[k];
		    }
		  }
		  emax5[cid].fsm[j].rrdyc++;		
		}
		else {
		  if      (emax5[cid].status == STATUS_CONF) emax5[cid].fsm[j].row_select = 0LL;
		  else if (emax5[cid].status == STATUS_REGV) emax5[cid].fsm[j].row_select = 0LL;
		  else if (emax5[cid].status == STATUS_LMMI) emax5[cid].fsm[j].row_select = 0LL;
		  emax5[cid].fsm[j].row_lmm_en &= ~(1LL<<i);
		  for (k=0; k<EMAX_WIDTH; k++) {
		    if (emax5[cid].fsm[j].lmmc[i].bcas & (1<<k))
		      emax5[cid].fsm[k].row_lmm_en &= ~(1LL<<i);
		  }
		}
	      }
              break;
            } /* end of case AREQ/DREQ */
          } /* end of if (mark) */
          else { /* for STATUS_DRAIN, STATUS_LOAD, STATUS_EXEC */
	    /* 次の候補を粗く探索 */
	    while (++emax5[cid].fsm[j].row_count < EMAX_DEPTH) {
	      i = emax5[cid].fsm[j].row_count;
	      if (emax5[cid].fsm[j].lmmd[i])                                     break; /* rough condition for next STATUS_DRAIN */
	      if (emax5[cid].fsm[j].lmmc[i].v & ~emax5[cid].fsm[j].lmmc[i].copy) break; /* rough condition for next STATUS_LOAD/EXEC  */
	    }
          }
          if (!(emax5[cid].status == STATUS_EXEC && (lmmc_stat==11 || lmmc_stat==15))) /* LDDMQ/TRの場合,sync=0対象外 */
	    sync = 0; /* not finished */
        }
      }

      if (sync) { /* all FSM_DRAIN/FSM_LOAD/FSM_EXEC finished */
	switch (emax5[cid].status) {
	case STATUS_CONF:
          emax5[cid].status = STATUS_LMMI;
	  break;
	case STATUS_REGV:
          emax5[cid].status = STATUS_START;
	  goto transit_to_start;
        case STATUS_LMMI:
          emax5[cid].status = STATUS_DRAIN;
	  break;
        case STATUS_DRAIN:
	  if      (mode==1) emax5[cid].status = STATUS_LOAD; /* normal_array */
	  else if (mode==2) emax5[cid].status = STATUS_TERM; /* drain_dirty_lmm */
	  break;
	case STATUS_LOAD:
          emax5[cid].status = STATUS_REGV;
	  break;
	case STATUS_EXEC:
          emax5[cid].status = STATUS_TERM;
	  break;
	}
        for (j=0; j<EMAX_WIDTH; j++) {
          emax5[cid].fsm[j].memif_status = MEMIF_AREQ;
          emax5[cid].fsm[j].row_count    = 0;
          emax5[cid].fsm[j].row_select   = 0LL;
#ifndef IGNORE_LMMI_BLKGATHER
	  emax5[cid].fsm[j].blkstat  = 0; /* ptrlist */
	  emax5[cid].fsm[j].blkcount = 0; /* dword/dword: 7bit */
#endif
        }
	break;
      transit_to_start:
	for (j=0; j<EMAX_WIDTH; j++) {
          emax5[cid].fsm[j].memif_status = MEMIF_AREQ;
          emax5[cid].fsm[j].row_count    = 0;
	  emax5[cid].fsm[j].row_select   = 1LL<<emax5[cid].last_row0; /* start row */
#ifndef IGNORE_LMMI_BLKGATHER
	  emax5[cid].fsm[j].blkstat  = 0; /* ptrlist */
	  emax5[cid].fsm[j].blkcount = 0; /* dword/dword: 7bit */
#endif
	}
	break;
      }
      break; /* never reached */
    case STATUS_START:
      emax5[cid].cycles_start_part++;
      emax5[cid].status = STATUS_EXEC;
      for (j=0; j<EMAX_WIDTH; j++) {
	emax5[cid].fsm[j].memif_status = MEMIF_AREQ;
	emax5[cid].fsm[j].row_count    = 0;
	emax5[cid].fsm[j].row_select   = 0LL;
#ifndef IGNORE_LMMI_BLKGATHER
	emax5[cid].fsm[j].blkstat  = 0; /* ptrlist */
	emax5[cid].fsm[j].blkcount = 0; /* dword/dword: 7bit */
#endif
	emax5[cid].fsm[j].axi_first_read = 1; /* simulate pipelined AXI for LDDMQ (1->0) */
	                                      /* same as one_shot */
      }
      break;
    case STATUS_TERM:
      emax5[cid].cycles_term_part++;
#ifndef IGNORE_LDDMQ_HANDSHAKE
      {
	int found = 0;
	for (j=0; j<EMAX_WIDTH; j++) {
	  if (emax5[cid].fsm[j].tcureg_last) { /* TR exists */
	    found = 1;
	    if (emax5[cid].fsm[j].tcureg_term) { /* ARM response */
	      emax5[cid].fsm[j].tcureg_last = 0;
	      emax5[cid].fsm[j].tcureg_term = 0;
	    }
	  }
	}
	if (found)
	  break; /* keep STATUS_TERM */
      }
#endif
      printf(" EMAX_TERM(%08.8x_%08.8x) retv=%d", (Uint)(pa_cycle>>32), (Uint)pa_cycle, emax5[cid].retval);
      if (trace)
	printf("\n");
      if ((flag & DUMP_DDR) && !dump_ddr_done) {
	fclose(fp_conf);
	fclose(fp_lmmi);
	fclose(fp_regv);
	fclose(fp_load);
	dump_ddr_done = 1;
      }
      if (mode==1) { /* normal array */
	emax5[cid].last_conf = conf;
	emax5[cid].last_dist = emax5[cid].fsm[0].last_dist;
	emax5[cid].last_row0 = (emax5[cid].last_row0+emax5[cid].last_dist)%EMAX_DEPTH;
      }
      emax5[cid].v = 0; /* unlock */
      emax5[cid].status = STATUS_IDLE;
      for (j=0; j<EMAX_WIDTH; j++) {
	for (i=0; i<EMAX_DEPTH; i++) {
	  if (unit[cid][i][j].drty) emax5[cid].fsm[j].lmmd[i] = 1; /* mark dirty */
	}
	emax5[cid].fsm[j].memif_status = MEMIF_AREQ;
	emax5[cid].fsm[j].row_count    = 0;
	emax5[cid].fsm[j].row_select   = 0LL;
#ifndef IGNORE_LMMI_BLKGATHER
	emax5[cid].fsm[j].blkstat  = 0; /* ptrlist */
	emax5[cid].fsm[j].blkcount = 0; /* dword/dword: 7bit */
#endif
#ifndef IGNORE_LDDMQ_HANDSHAKE
	emax5[cid].fsm[j].tcureg_last = 0;
	emax5[cid].fsm[j].tcureg_term = 0;
#endif
      }
      total = emax5[cid].cycles_tinit_part+emax5[cid].cycles_conf_part+emax5[cid].cycles_scon_part+emax5[cid].cycles_lmmi_part+emax5[cid].cycles_drain_part+emax5[cid].cycles_load_part+emax5[cid].cycles_regv_part+emax5[cid].cycles_start_part+emax5[cid].cycles_exec_part+emax5[cid].cycles_term_part+emax5[cid].cycles_trans_part;
      printf(" c%d s%d i%d d%d l%d r%d s%d e%d z%d t%d total=%d\n",
             emax5[cid].cycles_conf_part, emax5[cid].cycles_scon_part,  emax5[cid].cycles_lmmi_part, emax5[cid].cycles_drain_part, emax5[cid].cycles_load_part,
             emax5[cid].cycles_regv_part, emax5[cid].cycles_start_part, emax5[cid].cycles_exec_part, emax5[cid].cycles_term_part,  emax5[cid].cycles_trans_part, total);
      emax5[cid].cycles_conf  += emax5[cid].cycles_conf_part;
      emax5[cid].cycles_scon  += emax5[cid].cycles_scon_part;
      emax5[cid].cycles_lmmi  += emax5[cid].cycles_lmmi_part;
      emax5[cid].cycles_drain += emax5[cid].cycles_drain_part;
      emax5[cid].cycles_load  += emax5[cid].cycles_load_part;
      emax5[cid].cycles_regv  += emax5[cid].cycles_regv_part;
      emax5[cid].cycles_start += emax5[cid].cycles_start_part;
      emax5[cid].cycles_exec  += emax5[cid].cycles_exec_part;
      emax5[cid].cycles_term  += emax5[cid].cycles_term_part;
      emax5[cid].cycles_trans += emax5[cid].cycles_trans_part;
      tic = -1;
      break; /* EMAX5 finished */
    }
    if (trace)
#ifndef IGNORE_LDDMQ_HANDSHAKE
      printf("%03.3d:siml_emax5: final arbrk=%08.8x 1exec=%08.8x_%08.8x 1stop=%08.8x eagaen=%08.8x eagden=%08.8x guard=%08.8x lmbrk=%08.8x trval=%08.8x 2exec=%08.8x_%08.8x 2stop=%08.8x fsmbusy=%d%d%d%d lmbusy=%08.8x brout=%08.8x\n",
	     tid,
	     (Uint)emax5[cid].unit1_arbrk,   (Uint)(emax5[cid].unit1_exec>>32), (Uint)emax5[cid].unit1_exec, (Uint)emax5[cid].unit1_stop,
	     (Uint)emax5[cid].unit2_eag_aen, (Uint)emax5[cid].unit2_eag_den, (Uint)emax5[cid].unit2_guard,
	     (Uint)emax5[cid].unit2_lmbrk,   (Uint)emax5[cid].tr_valid, (Uint)(emax5[cid].unit2_exec>>32), (Uint)emax5[cid].unit2_exec, (Uint)emax5[cid].unit2_stop,
	     emax5[cid].fsm[3].fsm_busy, emax5[cid].fsm[2].fsm_busy, emax5[cid].fsm[1].fsm_busy, emax5[cid].fsm[0].fsm_busy, (Uint)emax5[cid].unit2_lmbusy, (Uint)emax5[cid].brout_valid);
#else
      printf("%03.3d:siml_emax5: final arbrk=%08.8x 1exec=%08.8x_%08.8x 1stop=%08.8x trval=%08.8x 2exec=%08.8x_%08.8x 2stop=%08.8x brout=%08.8x\n",
	     tid,
	     (Uint)emax5[cid].unit1_arbrk,   (Uint)(emax5[cid].unit1_exec>>32), (Uint)emax5[cid].unit1_exec, (Uint)emax5[cid].unit1_stop,
	     (Uint)emax5[cid].tr_valid, (Uint)(emax5[cid].unit2_exec>>32), (Uint)emax5[cid].unit2_exec, (Uint)emax5[cid].unit2_stop,
	     (Uint)emax5[cid].brout_valid);
#endif
    /*******************************************************/
    /******************* FSM siml end **********************/
    /*******************************************************/
    if (trace && trace_pipe)
      show_emax5_status(cid);
  }
  if (tic < -1)
    return (emax5[cid].retval); /* EMAX5 finished 0:normal with transaction, 1:normal with lmm_dirty */
  else
    return (2); /* EMAX5 busy */
}

siml_axiif(cid, trace, base) Uint cid, trace; char *base;
{
  int tid = emax5[cid].tid;
  int j, k;

  /* pseudo for resetting arready and awready */
  if (emax5[cid].status==STATUS_IDLE) {
    for (j=EMAX_WIDTH-1; j>=0; j--) { /* for each column */
      emax5[cid].fsm[j].axi_arready = 1; /* reset read */
      emax5[cid].fsm[j].axi_awready = 1; /* reset write */
    }
  }

#define EMAX5_LDDMQ_MUX 8
  for (j=EMAX_WIDTH-1; j>=0; j--) { /* for each column */
    /* start read/write */
    if (emax5[cid].fsm[j].axi_arready && emax5[cid].fsm[j].axi_arvalid) { /* new read_req starts */
      emax5[cid].fsm[j].axi_arready = 0; /* start read */
      emax5[cid].fsm[j].iaddr = emax5[cid].fsm[j].axi_araddr; /* start read */
      emax5[cid].fsm[j].ilen  = 0;                            /* start read (unit is multople of 64bits) */
      if (emax5[cid].fsm[j].axi_arlen == 0) {
	if (!emax5[cid].fsm[j].axi_first_read) /* LDDMQ is assumed to be multiplexed */
	  emax5[cid].fsm[j].idelay= MMDELAY/ARM_EMAX5_RATIO/EMAX5_LDDMQ_MUX; /* pipelined read */
	else {
	  emax5[cid].fsm[j].idelay= MMDELAY/ARM_EMAX5_RATIO;                 /* sequential read */
	  emax5[cid].fsm[j].axi_first_read = 0;
	}
      }
      else
	emax5[cid].fsm[j].idelay= MMDELAY/ARM_EMAX5_RATIO;                 /* sequential read */
      if (trace)
	printf("%03.3d:siml_axiif: read col=%d start araddr=%08.8x_%08.8x arlen=%08.8x_%08.8x\n",
	       tid, j, (Uint)(emax5[cid].fsm[j].axi_araddr>>32), (Uint)emax5[cid].fsm[j].axi_araddr, (Uint)(emax5[cid].fsm[j].axi_arlen>>32), (Uint)emax5[cid].fsm[j].axi_arlen);
    }
    else if (emax5[cid].fsm[j].axi_awready && emax5[cid].fsm[j].axi_awvalid) { /* new write_req starts */
      emax5[cid].fsm[j].axi_awready = 0; /* start write */
      emax5[cid].fsm[j].iaddr = emax5[cid].fsm[j].axi_awaddr; /* start write */
      emax5[cid].fsm[j].ilen  = 0;                            /* start write (unit is multople of 64bits) */
      emax5[cid].fsm[j].idelay= 0;                            /* start write */
      if (trace)
	printf("%03.3d:siml_axiif: write col=%d start awaddr=%08.8x_%08.8x awlen=%08.8x_%08.8x\n",
	       tid, j, (Uint)(emax5[cid].fsm[j].axi_awaddr>>32), (Uint)emax5[cid].fsm[j].axi_awaddr, (Uint)(emax5[cid].fsm[j].axi_awlen>>32), (Uint)emax5[cid].fsm[j].axi_awlen);
    }
    /* exec_length: max 64bit*1024count = 8KB */
    /* burst read:  max 256bit*256count = 8KB */
    /*                     256bit_AXI_read   -> 256bit_LMM */
    /*  lmmi.top -> axira  top(256bit align) -> mask       */
    /*  lmmi.len -> axirl  len(256bit align) -> mask       */
    else if (!emax5[cid].fsm[j].axi_arready) {
      if (emax5[cid].fsm[j].idelay)
	emax5[cid].fsm[j].idelay--;
      else if (emax5[cid].fsm[j].ilen <= emax5[cid].fsm[j].axi_arlen) {
	emax5[cid].fsm[j].axi_rvalid = 1;
	for (k=0; k<UNIT_WIDTH; k++) { /* 32B aligned */
	  Ull a = emax5[cid].fsm[j].iaddr + sizeof(Ull)*(emax5[cid].fsm[j].ilen*UNIT_WIDTH+k);
	  emax5[cid].fsm[j].axi_rdata[k] = *(Ull*)(base + a);
	  if (trace)
	    printf("%03.3d:siml_axiif: read col=%d iaddr=%08.8x_%08.8x rdata[%d]=%08.8x_%08.8x\n",
		   tid, j, (Uint)(a>>32), (Uint)a, k, (Uint)(emax5[cid].fsm[j].axi_rdata[k]>>32), (Uint)emax5[cid].fsm[j].axi_rdata[k]);
	}
	emax5[cid].fsm[j].ilen++;
      }
      else {
	emax5[cid].fsm[j].axi_rvalid = 0;
	emax5[cid].fsm[j].axi_arready = 1;
      }
    }
    /* burst write */
    /*                            256bit_LMM ->  256iAXI_write          */
    /*  lmmi.top -> lmra (align)  mask       ->  WSTRBtop(256bit align) */
    /*  lmmi.len -> rrdyc(align)                 256bit align           */
    else if (!emax5[cid].fsm[j].axi_awready) {
      if (emax5[cid].fsm[j].idelay)
	emax5[cid].fsm[j].idelay--;
      else if (emax5[cid].fsm[j].ilen <= emax5[cid].fsm[j].axi_awlen) {
	if (emax5[cid].fsm[j].axi_wvalid) {
	  for (k=0; k<UNIT_WIDTH; k++) { /* 32B aligned */
	    if (emax5[cid].fsm[j].axi_wstrb & (0xff<<(k*8))) {
	      Ull a = emax5[cid].fsm[j].iaddr + sizeof(Ull)*(emax5[cid].fsm[j].ilen*UNIT_WIDTH+k);
	      *(Ull*)(base + a) = emax5[cid].fsm[j].axi_wdata[k];
	      if (trace)
		printf("%03.3d:siml_axiif: write col=%d iaddr=%08.8x_%08.8x wdata[%d]=%08.8x_%08.8x\n",
		       tid, j, (Uint)(a>>32), (Uint)a, k, (Uint)(emax5[cid].fsm[j].axi_wdata[k]>>32), (Uint)emax5[cid].fsm[j].axi_wdata[k]);
	    }
	  }
	  emax5[cid].fsm[j].ilen++;
	}
      }
      else {
	emax5[cid].fsm[j].axi_awready = 1;
      }
    }
  }
}

siml_unit_bus1(cid, i) Uint cid, i; /* 演算器入力までを計算 */
{
  int j, k, s;
  int pi = (i+EMAX_DEPTH-1)%EMAX_DEPTH;

  /* regv(br,ea[01][bo]r) -> c,t,ex[123],ea[bo],ea[01][bo] */
  for (j=0; j<EMAX_WIDTH; j++) { /* 0:br0_0, 1:br0_1, ... 15:3_3 */
    s = unit[cid][i][j].conf.cdw1.cs0;    unit[cid][i][j].c[0] = unit[cid][pi][s/UNIT_WIDTH].regv.br[s%UNIT_WIDTH]&3;
    s = unit[cid][i][j].conf.cdw1.cs1;    unit[cid][i][j].c[1] = unit[cid][pi][s/UNIT_WIDTH].regv.br[s%UNIT_WIDTH]&3;
    s = unit[cid][i][j].conf.cdw1.cs2;    unit[cid][i][j].c[2] = unit[cid][pi][s/UNIT_WIDTH].regv.br[s%UNIT_WIDTH]&3;
    s = unit[cid][i][j].conf.cdw1.cs3;    unit[cid][i][j].c[3] = unit[cid][pi][s/UNIT_WIDTH].regv.br[s%UNIT_WIDTH]&3;

    s = unit[cid][i][j].conf.cdw2.ts0;    unit[cid][i][j].t[0] = unit[cid][pi][s/UNIT_WIDTH].regv.br[s%UNIT_WIDTH];
    s = unit[cid][i][j].conf.cdw2.ts1;    unit[cid][i][j].t[1] = unit[cid][pi][s/UNIT_WIDTH].regv.br[s%UNIT_WIDTH];
    s = unit[cid][i][j].conf.cdw2.ts2;    unit[cid][i][j].t[2] = unit[cid][pi][s/UNIT_WIDTH].regv.br[s%UNIT_WIDTH];
    s = unit[cid][i][j].conf.cdw2.ts3;    unit[cid][i][j].t[3] = unit[cid][pi][s/UNIT_WIDTH].regv.br[s%UNIT_WIDTH];

    s = unit[cid][i][j].conf.cdw0.ex1brs; unit[cid][i][j].ex1  = unit[cid][pi][s/UNIT_WIDTH].regv.br[s%UNIT_WIDTH];
    s = unit[cid][i][j].conf.cdw0.ex2brs; unit[cid][i][j].ex2  = unit[cid][pi][s/UNIT_WIDTH].regv.br[s%UNIT_WIDTH];
    s = unit[cid][i][j].conf.cdw0.ex3brs; unit[cid][i][j].ex3  = unit[cid][pi][s/UNIT_WIDTH].regv.br[s%UNIT_WIDTH];

    s = unit[cid][i][j].conf.cdw1.eabbrs; unit[cid][i][j].eab  = unit[cid][pi][s/UNIT_WIDTH].regv.br[s%UNIT_WIDTH];
    s = unit[cid][i][j].conf.cdw1.eaobrs; unit[cid][i][j].eao  = unit[cid][pi][s/UNIT_WIDTH].regv.br[s%UNIT_WIDTH];

    s = unit[cid][i][j].conf.cdw1.ea0bs;  unit[cid][i][j].ea0b = (s&2)?unit[cid][i][j].eab:unit[cid][i][j].regv.ea0br;
    s = unit[cid][i][j].conf.cdw1.ea0os;  unit[cid][i][j].ea0o = (s&1)?unit[cid][i][j].eao:unit[cid][i][j].regv.ea0or;

    s = unit[cid][i][j].conf.cdw1.ea1bs;  unit[cid][i][j].ea1b = (s&2)?unit[cid][i][j].eab:unit[cid][i][j].regv.ea1br;
    s = unit[cid][i][j].conf.cdw1.ea1os;  unit[cid][i][j].ea1o = (s&1)?unit[cid][i][j].eao:unit[cid][i][j].regv.ea1or;
  }
}

siml_unit_bus2(cid, i) Uint cid, i; /* TR入力を計算 */
{
  int j, k, s;

  /* fsm.lmw[ad],lmra <-> unit.lmw[ad],lmra */
  for (j=0; j<EMAX_WIDTH; j++) {
    unit[cid][i][j].lmen    = emax5[cid].fsm[j].row_lmm_en>>i&1;
    unit[cid][i][j].lmwa    = emax5[cid].fsm[j].lmwa;
    unit[cid][i][j].lmwd[0] = emax5[cid].fsm[j].lmwd[0];
    unit[cid][i][j].lmwd[1] = emax5[cid].fsm[j].lmwd[1];
    unit[cid][i][j].lmwd[2] = emax5[cid].fsm[j].lmwd[2];
    unit[cid][i][j].lmwd[3] = emax5[cid].fsm[j].lmwd[3];
    unit[cid][i][j].lmra    = emax5[cid].fsm[j].lmra;
#ifndef IGNORE_LDDMQ_HANDSHAKE
    unit[cid][i][j].lmwd_valid   = emax5[cid].fsm[j].lmwd_valid;
#endif
  }
  /* lmw[ad] -> (lmlo <- lmri) */
  for (j=0; j<EMAX_WIDTH; j++) { /* s=0:lmwd, s=1:lmri */
    s = unit[cid][i][j].conf.cdw2.lmls;
    unit[cid][i][j].lmloa   = (s==0)?unit[cid][i][j].lmwa   :unit[cid][i][j].lmria;
    unit[cid][i][j].lmlo[0] = (s==0)?unit[cid][i][j].lmwd[0]:unit[cid][i][j].lmri[0];
    unit[cid][i][j].lmlo[1] = (s==0)?unit[cid][i][j].lmwd[1]:unit[cid][i][j].lmri[1];
    unit[cid][i][j].lmlo[2] = (s==0)?unit[cid][i][j].lmwd[2]:unit[cid][i][j].lmri[2];
    unit[cid][i][j].lmlo[3] = (s==0)?unit[cid][i][j].lmwd[3]:unit[cid][i][j].lmri[3];
    if (j<EMAX_WIDTH-1) { /* 左へ伝搬 */
      unit[cid][i][j+1].lmria   = unit[cid][i][j].lmloa;
      unit[cid][i][j+1].lmri[0] = unit[cid][i][j].lmlo[0];
      unit[cid][i][j+1].lmri[1] = unit[cid][i][j].lmlo[1];
      unit[cid][i][j+1].lmri[2] = unit[cid][i][j].lmlo[2];
      unit[cid][i][j+1].lmri[3] = unit[cid][i][j].lmlo[3];
    }
  }
  /* lmw[ad] -> (lmli -> lmro) */
  for (j=EMAX_WIDTH-1; j>=0; j--) { /* s=0:lmwd, s=1:lmli */
    s = unit[cid][i][j].conf.cdw2.lmrs;
    unit[cid][i][j].lmroa   = (s==0)?unit[cid][i][j].lmwa   :unit[cid][i][j].lmlia;
    unit[cid][i][j].lmro[0] = (s==0)?unit[cid][i][j].lmwd[0]:unit[cid][i][j].lmli[0];
    unit[cid][i][j].lmro[1] = (s==0)?unit[cid][i][j].lmwd[1]:unit[cid][i][j].lmli[1];
    unit[cid][i][j].lmro[2] = (s==0)?unit[cid][i][j].lmwd[2]:unit[cid][i][j].lmli[2];
    unit[cid][i][j].lmro[3] = (s==0)?unit[cid][i][j].lmwd[3]:unit[cid][i][j].lmli[3];
    if (j>0) { /* 右へ伝搬 */
      unit[cid][i][j-1].lmlia   = unit[cid][i][j].lmroa;
      unit[cid][i][j-1].lmli[0] = unit[cid][i][j].lmro[0];
      unit[cid][i][j-1].lmli[1] = unit[cid][i][j].lmro[1];
      unit[cid][i][j-1].lmli[2] = unit[cid][i][j].lmro[2];
      unit[cid][i][j-1].lmli[3] = unit[cid][i][j].lmro[3];
    }
  }
}

siml_unit_bus3(cid, i) Uint cid, i; /* unit2_eag_aen,unit2_eag_denを計算 */
{
  int j, k, s;

#ifndef IGNORE_LDDMQ_HANDSHAKE
  emax5[cid].unit2_eag_aen &= ~(1LL<<i);
  emax5[cid].unit2_eag_den &= ~(1LL<<i);
  for (j=0; j<EMAX_WIDTH; j++) {
    if (unit[cid][i][j].conf.cdw1.ea1op == OP_LDDMQ) {
      if (!emax5[cid].fsm[j].fsm_busy && unit[cid][i][j].unit1_eneq) /* inactive */
	emax5[cid].unit2_eag_aen |= (1LL<<i);
      if (unit[cid][i][j].lmwd_valid) /* inactive */
	emax5[cid].unit2_eag_den |= (1LL<<i);
    }
    else if (unit[cid][i][j].conf.cdw1.ea1op == OP_TR) {
      if (!emax5[cid].fsm[j].fsm_busy && unit[cid][i][j].unit1_eneq) /* inactive */
	emax5[cid].unit2_eag_aen |= (1LL<<i);
    }
  }  
#endif
}

siml_unit_bus4(cid, i) Uint cid, i; /* unit2_eag_aen,unit2_eag_denを計算 */
{
  int j, found_lddmq, found_tr, unit2_lmbusy = 0;

#ifndef IGNORE_LDDMQ_HANDSHAKE
  emax5[cid].unit2_lmbusy &= ~(1LL<<i);
  found_lddmq = 0;
  for (j=0; j<EMAX_WIDTH; j++) {
    if (unit[cid][i][j].conf.cdw1.ea1op == OP_LDDMQ) {
      found_lddmq = 1;
      unit2_lmbusy = (emax5[cid].unit1_exec & (1LL<<i)) || emax5[cid].fsm[j].fsm_busy || unit[cid][i][j].unit1_eneq;
    }
    else if (unit[cid][i][j].conf.cdw1.ea1op == OP_TR)
      unit2_lmbusy = (emax5[cid].unit1_exec & (1LL<<i)) || emax5[cid].fsm[j].fsm_busy || unit[cid][i][j].unit1_eneq;
  }  
  if (unit2_lmbusy)
    emax5[cid].unit2_lmbusy |= (1LL<<i);
#endif

  emax5[cid].tr_valid &= ~(1LL<<i);
#ifndef IGNORE_LDDMQ_HANDSHAKE
  if (found_lddmq) {
    if (emax5[cid].unit2_eag_den & (1LL<<i))
      emax5[cid].tr_valid |= (1LL<<i);
    emax5[cid].unit2_guard |= (1LL<<i);
    emax5[cid].unit2_lmbrk |= ((Ull)(!unit2_lmbusy && (emax5[cid].brout_valid & (1LL<<i)))<<i);
  }
  else
#endif
  { /* including OP_TR */
    if ((emax5[cid].unit1_exec & (1LL<<i)) && (emax5[cid].brout_valid & (1LL<<((i+EMAX_DEPTH-1)%EMAX_DEPTH)))) /* active */
      emax5[cid].tr_valid |= (1LL<<i);
  }

#ifndef IGNORE_LDDMQ_HANDSHAKE
  for (j=0; j<EMAX_WIDTH; j++) {
    if (unit[cid][i][j].conf.cdw1.ea1op == OP_LDDMQ) {
      if (!emax5[cid].fsm[j].fsm_busy && unit[cid][i][j].unit1_eneq) /* inactive */
	emax5[cid].fsm[j].fsm_busy = 1;
    }
    else if (unit[cid][i][j].conf.cdw1.ea1op == OP_TR) {
      if (!emax5[cid].fsm[j].fsm_busy && unit[cid][i][j].unit1_eneq) /* inactive */
	emax5[cid].fsm[j].fsm_busy = 1;
    }
  }  
#endif
}

siml_unit_cex(cid, i, j) Uint cid, i, j; /* reg更新がないので最初に実行 */
{
  Ull c3, c2, c1, c0;
  Ushort pattern;
  Ull ex;

  /* c -> cexdr */
  switch (emax5[cid].status) {
  case STATUS_IDLE:
  case STATUS_CONF:
  case STATUS_SCON:
  case STATUS_LMMI:
  case STATUS_DRAIN:
  case STATUS_LOAD:
  case STATUS_REGV:
  case STATUS_START:
    return (0);
  case STATUS_EXEC:
    if ((emax5[cid].unit1_exec & (1LL<<i)) && (emax5[cid].brout_valid & (1LL<<((i+EMAX_DEPTH-1)%EMAX_DEPTH)))) { /* active */
      c0      = unit[cid][i][j].c[0];
      c1      = unit[cid][i][j].c[1];
      c2      = unit[cid][i][j].c[2];
      c3      = unit[cid][i][j].c[3];
      pattern = unit[cid][i][j].conf.cdw1.cex_tab;
      cex(OP_CEXE, &ex, c3, c2, c1, c0, pattern);
      unit[cid][i][j].cexdr = ex;
    }
    return (0);
  case STATUS_TERM:
    return (0);
  }
}

siml_unit_exe(cid, i, j) Uint cid, i, j; /* 全bus計算後にreg更新 */
{
  Uint op_ex1, op_ex2, op_ex3;
  Ull  r1, r2, r3, r4, r5;
  Uint exp1, exp2, exp3;
  Ull  d;
  int retval;

  /* ex[123] -> exdr */
  switch (emax5[cid].status) {
  case STATUS_IDLE:
  case STATUS_CONF:
  case STATUS_SCON:
  case STATUS_LMMI:
  case STATUS_DRAIN:
  case STATUS_LOAD:
  case STATUS_REGV:
  case STATUS_START:
    return (0);
  case STATUS_EXEC:
    if ((emax5[cid].unit1_exec & (1LL<<i)) && (emax5[cid].brout_valid & (1LL<<((i+EMAX_DEPTH-1)%EMAX_DEPTH)))) { /* active */
      op_ex1 = unit[cid][i][j].conf.cdw0.op1;
      op_ex2 = unit[cid][i][j].conf.cdw0.op2;
      op_ex3 = unit[cid][i][j].conf.cdw0.op3;
      r1     = (unit[cid][i][j].conf.cdw0.ex1s!=1 || !unit[cid][i][j].one_shot)
             ? unit[cid][i][j].ex1 : unit[cid][i][j].exdr; /* self_loop */
      r2     = unit[cid][i][j].ex2;
      r3     = unit[cid][i][j].ex3;
      r4     = unit[cid][i][j].conf.cdw0.e2is==0 ? unit[cid][i][j].conf.cdw3.e2imm
             : unit[cid][i][j].conf.cdw0.e2is==1 ? unit[cid][i][j].ex2
             :                                     unit[cid][i][j].ex3;
      r5     = unit[cid][i][j].conf.cdw0.e3is==0 ? unit[cid][i][j].conf.cdw0.e3imm
             :                                     unit[cid][i][j].ex3;
      exp1   = unit[cid][i][j].conf.cdw0.ex1exp;
      exp2   = unit[cid][i][j].conf.cdw0.ex2exp;
      exp3   = unit[cid][i][j].conf.cdw0.ex3exp;
      retval = exe(op_ex1, &d, r1, exp1, r2, exp2, r3, exp3, op_ex2, r4, op_ex3, r5);
      unit[cid][i][j].exdr = d;

      emax5[cid].unit1_arbrk |= ((Ull)retval<<i);
    }
    return (0);
  case STATUS_TERM:
    return (0);
  }
}

siml_unit_eas(cid, i, j) Uint cid, i, j; /* 全bus計算後にreg更新 */
{
  Ull base0, offs0;
  Ull base1, offs1;

  /* ea[01][bo] -> ea[01]dr,ma */
  switch (emax5[cid].status) {
  case STATUS_IDLE:
  case STATUS_CONF:
  case STATUS_SCON:
  case STATUS_LMMI:
  case STATUS_DRAIN: /* fsm drain */
  case STATUS_LOAD: /* fsm pload */
    return (0);
  case STATUS_REGV:
#ifndef IGNORE_LDDMQ_HANDSHAKE
    unit[cid][i][j].unit1_eneq  = 0; /* reset */
#endif
  case STATUS_START:
    return (0);
  case STATUS_EXEC:
    base0 = (!(unit[cid][i][j].conf.cdw1.ea0bs&1) || !unit[cid][i][j].one_shot)?unit[cid][i][j].ea0b:unit[cid][i][j].ea0dr;
    offs0 = (!(unit[cid][i][j].conf.cdw1.ea0bs&1) ||  unit[cid][i][j].one_shot)?unit[cid][i][j].ea0o:0LL;
    if (unit[cid][i][j].conf.cdw1.ea1op == OP_LDDMQ || unit[cid][i][j].conf.cdw1.ea1op == OP_TR) {
#ifndef IGNORE_LDDMQ_HANDSHAKE
      base1 = (!(unit[cid][i][j].conf.cdw1.ea1bs&1) || !unit[cid][i][j].one_shot_a)?unit[cid][i][j].ea1b:unit[cid][i][j].ea1dr;
      offs1 = (!(unit[cid][i][j].conf.cdw1.ea1bs&1) ||  unit[cid][i][j].one_shot_a)?unit[cid][i][j].ea1o:0LL;
#endif
    }
    else if (unit[cid][i][j].conf.cdw1.ea1op == OP_IM_BUFRD) {
#ifndef IGNORE_LDDMQ_HANDSHAKE
      base1 = (!(unit[cid][i][j].conf.cdw1.ea1bs&1) || !unit[cid][i][j].one_shot_d)?unit[cid][i][j].ea1b:unit[cid][i][j].ea1dr;
      offs1 = (!(unit[cid][i][j].conf.cdw1.ea1bs&1) ||  unit[cid][i][j].one_shot_d)?unit[cid][i][j].ea1o:0LL;
#endif
    }
    else {
      base1 = (!(unit[cid][i][j].conf.cdw1.ea1bs&1) || !unit[cid][i][j].one_shot)?unit[cid][i][j].ea1b:unit[cid][i][j].ea1dr;
      offs1 = (!(unit[cid][i][j].conf.cdw1.ea1bs&1) ||  unit[cid][i][j].one_shot)?unit[cid][i][j].ea1o:0LL;
    }
    eag(&unit[cid][i][j].ea0d, base0, offs0, unit[cid][i][j].conf.cdw1.ea0msk); /* self_loop=0の場合の初期値はaddr+offs, self_loop=1かつ初回はaddr,以降addr+offs */
    eag(&unit[cid][i][j].ea1d, base1, offs1, unit[cid][i][j].conf.cdw1.ea1msk); /* self_loop=0の場合の初期値はaddr+offs, self_loop=1かつ初回はaddr,以降addr+offs */
#ifndef IGNORE_LDDMQ_HANDSHAKE
    unit[cid][i][j].unit1_eneq = (unit[cid][i][j].ea1d != unit[cid][i][j].ea0d);
#endif
    return (0);
  case STATUS_TERM:
    return (0);
  }
}

siml_unit_ead(cid, i, j) Uint cid, i, j; /* 全bus計算後にreg更新 */
{
  Ull base0, offs0;
  Ull base1, offs1;

  /* ea[01][bo] -> ea[01]dr,ma */
  switch (emax5[cid].status) {
  case STATUS_IDLE:
  case STATUS_CONF:
  case STATUS_SCON:
  case STATUS_LMMI:
    return (0);
  case STATUS_DRAIN: /* fsm drain */
    if (unit[cid][i][j].lmen) {
      unit[cid][i][j].lmm.en1 = 1;
      unit[cid][i][j].lmm.rw1 = 0; /* read */
      unit[cid][i][j].ea1dr = unit[cid][i][j].lmra;
      unit[cid][i][j].lmm.ma1 = (unit[cid][i][j].ea1dr % LMEM_SIZE) & ~(sizeof(Ull)*UNIT_WIDTH-1);
    }
    else
      unit[cid][i][j].lmm.en1 = 0;
    return (0);
  case STATUS_LOAD: /* fsm pload */
    if (unit[cid][i][j].lmen) {
      unit[cid][i][j].lmm.en0 = 1;
      unit[cid][i][j].lmm.rw0 = 1; /* write */
      unit[cid][i][j].ea0dr = unit[cid][i][j].conf.cdw2.xmws==1 ? unit[cid][i][j].lmlia
                            : unit[cid][i][j].conf.cdw2.xmws==2 ? unit[cid][i][j].lmwa
                            : unit[cid][i][j].conf.cdw2.xmws==3 ? unit[cid][i][j].lmria
                            :                                     0LL;
      unit[cid][i][j].lmm.ma0 = (unit[cid][i][j].ea0dr % LMEM_SIZE) & ~(sizeof(Ull)*UNIT_WIDTH-1);
    }
    else
      unit[cid][i][j].lmm.en0 = 0;
    return (0);
  case STATUS_REGV:
  case STATUS_START:
    return (0);
  case STATUS_EXEC:
    /* fsm drain */
    if (unit[cid][i][j].conf.cdw1.ea1op == OP_IM_DRAIN) {
      if (unit[cid][i][j].lmen) { /* active */
        unit[cid][i][j].ea1dr = unit[cid][i][j].lmra;
        unit[cid][i][j].lmm.en1 = 1;
        unit[cid][i][j].lmm.rw1 = 0; /* read */
        unit[cid][i][j].lmm.ma1 = (unit[cid][i][j].ea1dr % LMEM_SIZE) & ~(sizeof(Ull)*UNIT_WIDTH-1);
      }
      else
        unit[cid][i][j].lmm.en1 = 0;
    }
#ifndef IGNORE_LDDMQ_HANDSHAKE
    else if (unit[cid][i][j].conf.cdw1.ea1op == OP_LDDMQ) { /* eag0->WRITE,eag1->READ *//* 読み出し側はbase+offsを使用 */
      if (emax5[cid].unit2_eag_aen & (1LL<<i)) { /* active */
	unit[cid][i][j].ea1dr   = unit[cid][i][j].ea1d;
        unit[cid][i][j].lmm.en1 = 1;
        unit[cid][i][j].lmm.rw1 = 0; /* read */
        unit[cid][i][j].lmm.ma1 = (unit[cid][i][j].ea1dr % LMEM_SIZE) & ~(sizeof(Ull)*UNIT_WIDTH-1);
	/*printf("===LDDMQ read row=%d col=%d ea1d=%08.8x ea0d=%08.8x\n", i, j, (Uint)unit[cid][i][j].ea1d, (Uint)unit[cid][i][j].ea0d);*/
      }
      else /* inactive */
        unit[cid][i][j].lmm.en1 = 0;
    }
    else if (unit[cid][i][j].conf.cdw1.ea1op == OP_TR) { /* eag0->WRITE,eag1->READ *//* 読み出し側はbase+offsを使用 */
      if (emax5[cid].unit2_eag_aen & (1LL<<i)) { /* active */
	unit[cid][i][j].ea1dr   = unit[cid][i][j].ea1d;
        unit[cid][i][j].lmm.en1 = 1;
        unit[cid][i][j].lmm.rw1 = 0; /* read */
        unit[cid][i][j].lmm.ma1 = (unit[cid][i][j].ea1dr % LMEM_SIZE) & ~(sizeof(Ull)*UNIT_WIDTH-1);
	/*printf("===TR read row=%d col=%d ea1d=%08.8x ea0d=%08.8x\n", i, j, (Uint)unit[cid][i][j].ea1d, (Uint)unit[cid][i][j].ea0d);*/
      }
      else /* inactive */
        unit[cid][i][j].lmm.en1 = 0;
    }
    else if (unit[cid][i][j].conf.cdw1.ea1op == OP_IM_BUFRD) { /* eag0->WRITE,eag1->READ *//* 読み出し側はbase+offsを使用 */
      if (emax5[cid].unit2_eag_den & (1LL<<i)) { /* active */
	unit[cid][i][j].ea1dr   = unit[cid][i][j].ea1d;
        unit[cid][i][j].lmm.en1 = 1;
        unit[cid][i][j].lmm.rw1 = 0; /* read */
        unit[cid][i][j].lmm.ma1 = (unit[cid][i][j].ea1dr % LMEM_SIZE) & ~(sizeof(Ull)*UNIT_WIDTH-1);
	/*printf("===BUFRD read row=%d col=%d ea1d=%08.8x ea0d=%08.8x\n", i, j, (Uint)unit[cid][i][j].ea1d, (Uint)unit[cid][i][j].ea0d);*/
      }
      else /* inactive */
        unit[cid][i][j].lmm.en1 = 0;
    }
#endif
    else if (unit[cid][i][j].conf.cdw1.ea1op) { /* normal load */
      if ((emax5[cid].unit1_exec & (1LL<<i)) && (emax5[cid].brout_valid & (1LL<<((i+EMAX_DEPTH-1)%EMAX_DEPTH)))) { /* active */
	unit[cid][i][j].ea1dr   = unit[cid][i][j].ea1d;
        unit[cid][i][j].lmm.en1 = 1; /* 同一行にLDDMQがある場合,unit[cid][i][j].lmm.en1の連動が必要(次のsiml_unit_bus2()にて補正) */
        unit[cid][i][j].lmm.rw1 = 0; /* read */
        unit[cid][i][j].lmm.ma1 = (unit[cid][i][j].ea1dr % LMEM_SIZE) & ~(sizeof(Ull)*UNIT_WIDTH-1);
	/*printf("===NLOAD read row=%d col=%d ea1d=%08.8x ea0d=%08.8x\n", i, j, (Uint)unit[cid][i][j].ea1d, (Uint)unit[cid][i][j].ea0d);*/
      }
      else /* inactive */
        unit[cid][i][j].lmm.en1 = 0;
    }
    else { /* inactive */
      unit[cid][i][j].lmm.ma1 = unit[cid][i][j].ea1dr = 0LL; /* always non-exec */
      unit[cid][i][j].lmm.en1 = 0;
    }
    /* fsm pload */
    if (unit[cid][i][j].conf.cdw1.ea0op == OP_IM_PREF) {
      if (unit[cid][i][j].lmen) {
	unit[cid][i][j].ea0dr = unit[cid][i][j].conf.cdw2.mwsa==1 ? unit[cid][i][j].lmlia
	                      : unit[cid][i][j].conf.cdw2.mwsa==2 ? unit[cid][i][j].lmwa
                              : unit[cid][i][j].conf.cdw2.mwsa==3 ? unit[cid][i][j].lmria
                              :                                     0LL;
        unit[cid][i][j].lmm.en0 = 1;
        unit[cid][i][j].lmm.rw0 = 1; /* write */
        unit[cid][i][j].lmm.ma0 = (unit[cid][i][j].ea0dr % LMEM_SIZE) & ~(sizeof(Ull)*UNIT_WIDTH-1);
      }
      else
        unit[cid][i][j].lmm.en0 = 0;
    }
    else if (unit[cid][i][j].conf.cdw1.ea0op == OP_TR) { /* write */
      if (((emax5[cid].unit1_exec & (1LL<<i)) && (emax5[cid].brout_valid & (1LL<<((i+EMAX_DEPTH-1)%EMAX_DEPTH))))
	  && (unit[cid][i][j].cexdr&1)) { /* active */
	unit[cid][i][j].ea0dr   = unit[cid][i][j].ea0d;
	unit[cid][i][j].lmm.en0 = 1;
	unit[cid][i][j].lmm.rw0 = (unit[cid][i][j].conf.cdw1.ea0op & 0x10)!=0; /* read/write */
	unit[cid][i][j].lmm.ma0 = (unit[cid][i][j].ea0dr % LMEM_SIZE) & ~(sizeof(Ull)*UNIT_WIDTH-1);
      }
      else  /* inactive */
	unit[cid][i][j].lmm.en0 = 0;
    }
    else if (unit[cid][i][j].conf.cdw1.ea0op) { /* normal load/store */
      if ((emax5[cid].unit1_exec & (1LL<<i)) && (emax5[cid].brout_valid & (1LL<<((i+EMAX_DEPTH-1)%EMAX_DEPTH)))) { /* active */
        unit[cid][i][j].ea0dr   = unit[cid][i][j].ea0d;
        unit[cid][i][j].lmm.en0 = 1;
        unit[cid][i][j].lmm.rw0 = (unit[cid][i][j].conf.cdw1.ea0op & 0x10)!=0; /* read/write */
	                          /* OP_TR   の場合,eag0->WRITE,eag1->READ */
	                          /* OP_LDDMQの場合,eag0->WRITE,eag1->READ */
        unit[cid][i][j].lmm.ma0 = (unit[cid][i][j].ea0dr % LMEM_SIZE) & ~(sizeof(Ull)*UNIT_WIDTH-1);
	/*printf("===BUFWR write row=%d col=%d ea1d=%08.8x ea0d=%08.8x\n", i, j, (Uint)unit[cid][i][j].ea1d, (Uint)unit[cid][i][j].ea0d);*/
      }
      else /* inactive */
        unit[cid][i][j].lmm.en0 = 0;
    }
    else { /* inactive */
      unit[cid][i][j].lmm.ma0 = unit[cid][i][j].ea0dr = 0LL; /* always non-exec */
      unit[cid][i][j].lmm.en0 = 0;
    }
    return (0);
  case STATUS_TERM:
    return (0);
  }
}

siml_unit_trg(cid, i, j) Uint cid, i, j; /* 全bus計算後にtr更新 */
{
  Ull a;
  int k;
  Ull exdmux[UNIT_WIDTH], exdsft[UNIT_WIDTH], lmwlwr[UNIT_WIDTH];

  /* update: exdr,t,lmwd,lmlio/lmrio -> tr,mw */
  switch (emax5[cid].status) {
  case STATUS_IDLE:
    return (0);
  case STATUS_CONF:
    if (emax5[cid].fsm[j].row_select & (1LL<<i)) {
      for (k=0; k<UNIT_WIDTH; k++)
        *((Ull*)&unit[cid][i][j].conf+k) = unit[cid][i][j].lmwd[k];
    }
    return (0);
  case STATUS_SCON:
    if (!(emax5[cid].fsm[j].row_select & (1LL<<i))) { /* 初回を0と数えて偶数番 */
      for (k=0; k<UNIT_WIDTH; k++)
	unit[cid][i][j].regv.br[k] = *((Ull*)&unit[cid][i][j].conf+k);
    }
    else { /* 初回を0と数えて奇数番 */
      for (k=0; k<UNIT_WIDTH; k++)
	*((Ull*)&unit[cid][i][j].conf+k) = unit[cid][(i+EMAX_DEPTH-1)%EMAX_DEPTH][j].regv.br[k];
    }
    return (0);
  case STATUS_LMMI:
  case STATUS_DRAIN:
    return (0);
  case STATUS_LOAD:
    if (unit[cid][i][j].lmen) {
      /* xmws: 0:off, 1:lmli, 2:lmwd, 3:lmri */
      for (k=0; k<UNIT_WIDTH; k++) {
        unit[cid][i][j].lmm.mm0[k] = 0xffffffffffffffffLL; /* mask */
	unit[cid][i][j].lmm.mw0[k] = unit[cid][i][j].conf.cdw2.xmws==1 ? unit[cid][i][j].lmli[k]
                                   : unit[cid][i][j].conf.cdw2.xmws==2 ? unit[cid][i][j].lmwd[k]
                                   : unit[cid][i][j].conf.cdw2.xmws==3 ? unit[cid][i][j].lmri[k]
                                   :                                     0LL;
      }
    }
    return (0);
  case STATUS_REGV:
    unit[cid][i][j].one_shot   = 0; /* reset one_shot   here */
#ifndef IGNORE_LDDMQ_HANDSHAKE
    unit[cid][i][j].one_shot_a = 0; /* reset one_shot_a here */
    unit[cid][i][j].one_shot_d = 0; /* reset one_shot_d here */
#endif
    return (0);
  case STATUS_START:
    return (0);
  case STATUS_EXEC:
    if ((emax5[cid].unit1_exec & (1LL<<i)) && (emax5[cid].brout_valid & (1LL<<((i+EMAX_DEPTH-1)%EMAX_DEPTH)))) { /* active */
      if (unit[cid][i][j].conf.cdw1.ea0op == OP_TR) {
	if (unit[cid][i][j].cexdr&1)
	  unit[cid][i][j].one_shot = 1; /* set one_shot here */
      }
      else
	unit[cid][i][j].one_shot = 1; /* set one_shot here */
    }
#ifndef IGNORE_LDDMQ_HANDSHAKE
    if (emax5[cid].unit2_eag_aen & (1LL<<i)) /* first active eneq */
      unit[cid][i][j].one_shot_a = 1; 
    if (emax5[cid].unit2_eag_den & (1LL<<i)) /* first active lmwd_valid */
      unit[cid][i][j].one_shot_d = 1; 
#endif
    /* mws[3-0]: 0:exdr, 1:exdr0, 2:ts0, 3:lmli0, 4:lmwd0, 5:lmri0 */
    a = unit[cid][i][j].ea0dr % LMEM_SIZE; /* main-mamory-address -> lmm-address */
    exdmux[0] = unit[cid][i][j].conf.cdw2.mws0==0 ? unit[cid][i][j].exdr /* tr[3-0]はalign不要 */
              : unit[cid][i][j].conf.cdw2.mws0==1 ? unit[cid][i][0].exdr
              : unit[cid][i][j].conf.cdw2.mws0==2 ? unit[cid][i][j].t[0]
              :                                     0LL;
    exdmux[1] = unit[cid][i][j].conf.cdw2.mws1==0 ? unit[cid][i][j].exdr
              : unit[cid][i][j].conf.cdw2.mws1==1 ? unit[cid][i][1].exdr
              : unit[cid][i][j].conf.cdw2.mws1==2 ? unit[cid][i][j].t[1]
              :                                     0LL;
    exdmux[2] = unit[cid][i][j].conf.cdw2.mws2==0 ? unit[cid][i][j].exdr
              : unit[cid][i][j].conf.cdw2.mws2==1 ? unit[cid][i][2].exdr
              : unit[cid][i][j].conf.cdw2.mws2==2 ? unit[cid][i][j].t[2]
              :                                     0LL;
    exdmux[3] = unit[cid][i][j].conf.cdw2.mws3==0 ? unit[cid][i][j].exdr
              : unit[cid][i][j].conf.cdw2.mws3==1 ? unit[cid][i][3].exdr
              : unit[cid][i][j].conf.cdw2.mws3==2 ? unit[cid][i][j].t[3]
              :                                     0LL;

    switch (unit[cid][i][j].conf.cdw1.ea0op) {
    case OP_STR:
      for (k=0; k<UNIT_WIDTH; k++) {
	unit[cid][i][j].lmm.mm0[k] = (a/sizeof(Ull) & (UNIT_WIDTH-1))==k ? (((unit[cid][i][j].cexdr&2)?0xffffffff00000000LL:0LL)|((unit[cid][i][j].cexdr&1)?0x00000000ffffffffLL:0LL)) : 0LL; /* mask */
	exdsft[k] = exdmux[k]; /* align不要 */
      }
      break;
    case OP_STWR:
      for (k=0; k<UNIT_WIDTH; k++) {
	unit[cid][i][j].lmm.mm0[k] = (a/sizeof(Ull) & (UNIT_WIDTH-1))==k ? (((unit[cid][i][j].cexdr&1)?0x00000000ffffffffLL:0LL)<<(a & sizeof(int))*8) : 0LL; /* mask */
	exdsft[k] = exdmux[k]<<(a & sizeof(int))*8; /* align必要 */
      }
      break;
    case OP_STHR:
      for (k=0; k<UNIT_WIDTH; k++) {
	unit[cid][i][j].lmm.mm0[k] = (a/sizeof(Ull) & (UNIT_WIDTH-1))==k ? (((unit[cid][i][j].cexdr&1)?0x000000000000ffffLL:0LL)<<(a & (sizeof(int)|sizeof(short)))*8) : 0LL; /* mask */
	exdsft[k] = exdmux[k]<<(a & (sizeof(int)|sizeof(short)))*8; /* align必要 */
      }
      break;
    case OP_STBR:
      for (k=0; k<UNIT_WIDTH; k++) {
	unit[cid][i][j].lmm.mm0[k] = (a/sizeof(Ull) & (UNIT_WIDTH-1))==k ? (((unit[cid][i][j].cexdr&1)?0x00000000000000ffLL:0LL)<<(a & (sizeof(int)|sizeof(short)|sizeof(char)))*8) : 0LL; /* mask */
	exdsft[k] = exdmux[k]<<(a & (sizeof(int)|sizeof(short)|sizeof(char)))*8; /* align必要 */
      }
      break;
    case OP_STRQ:
    case OP_IM_PREF:
    case OP_IM_BUFWR:
      for (k=0; k<UNIT_WIDTH; k++) {
	unit[cid][i][j].lmm.mm0[k] = 0xffffffffffffffffLL; /* mask */
	exdsft[k] = exdmux[k];
      }
      break;
#ifndef IGNORE_LDDMQ_HANDSHAKE
    case OP_LDDMQ: /* ●●● mws=0 */
      unit[cid][i][j].lmm.mm0[0] = 0xffffffffffffffffLL; /* mask */
      exdsft[0] = exdmux[0]; /* LDDMQ addr */
      for (k=1; k<UNIT_WIDTH; k++) {
	unit[cid][i][j].lmm.mm0[k] = 0LL; /* mask */
	exdsft[k] = exdmux[k]; /* LDDMQ addr */
      }
      break;
    case OP_TR: /* ●●● mws=1 */
      for (k=0; k<UNIT_WIDTH; k++) {
	unit[cid][i][j].lmm.mm0[k] = (unit[cid][i][j].cexdr&1)?0xffffffffffffffffLL:0LL; /* mask */
	exdsft[k] = exdmux[k]; /* not used */
      }
      break;
#endif
    }

    lmwlwr[0] = unit[cid][i][j].conf.cdw2.mws0==3 ? unit[cid][i][j].lmli[0] :
                unit[cid][i][j].conf.cdw2.mws0==4 ? unit[cid][i][j].lmwd[0] :
		unit[cid][i][j].conf.cdw2.mws0==5 ? unit[cid][i][j].lmri[0] :
		                                    0LL;    

    lmwlwr[1] = unit[cid][i][j].conf.cdw2.mws1==3 ? unit[cid][i][j].lmli[1] :
                unit[cid][i][j].conf.cdw2.mws1==4 ? unit[cid][i][j].lmwd[1] :
                unit[cid][i][j].conf.cdw2.mws1==5 ? unit[cid][i][j].lmri[1] :
		                                    0LL;    

    lmwlwr[2] = unit[cid][i][j].conf.cdw2.mws2==3 ? unit[cid][i][j].lmli[2] :
                unit[cid][i][j].conf.cdw2.mws2==4 ? unit[cid][i][j].lmwd[2] :
                unit[cid][i][j].conf.cdw2.mws2==5 ? unit[cid][i][j].lmri[2] :
		                                    0LL;    

    lmwlwr[3] = unit[cid][i][j].conf.cdw2.mws3==3 ? unit[cid][i][j].lmli[3] :
                unit[cid][i][j].conf.cdw2.mws3==4 ? unit[cid][i][j].lmwd[3] :
                unit[cid][i][j].conf.cdw2.mws3==5 ? unit[cid][i][j].lmri[3] :
		                                    0LL;    

    unit[cid][i][j].lmm.mw0[0] = (unit[cid][i][j].conf.cdw2.mws0 < 3) ? exdsft[0] : lmwlwr[0];
    unit[cid][i][j].lmm.mw0[1] = (unit[cid][i][j].conf.cdw2.mws1 < 3) ? exdsft[1] : lmwlwr[1];
    unit[cid][i][j].lmm.mw0[2] = (unit[cid][i][j].conf.cdw2.mws2 < 3) ? exdsft[2] : lmwlwr[2];
    unit[cid][i][j].lmm.mw0[3] = (unit[cid][i][j].conf.cdw2.mws3 < 3) ? exdsft[3] : lmwlwr[3];

    /* explicit trs[3-0]: 0:exdr[], 1:lmwd[], 2:t[] */
    unit[cid][i][j].tr[0] = unit[cid][i][j].conf.cdw2.trs0==0 ? unit[cid][i][0].exdr   :
                            unit[cid][i][j].conf.cdw2.trs0==1 ? unit[cid][i][j].lmwd[0]:
			                                        unit[cid][i][j].t[0]   ;
    unit[cid][i][j].tr[1] = unit[cid][i][j].conf.cdw2.trs1==0 ? unit[cid][i][1].exdr   :
                            unit[cid][i][j].conf.cdw2.trs1==1 ? unit[cid][i][j].lmwd[1]:
			                                        unit[cid][i][j].t[1]   ;
    unit[cid][i][j].tr[2] = unit[cid][i][j].conf.cdw2.trs2==0 ? unit[cid][i][2].exdr   :
                            unit[cid][i][j].conf.cdw2.trs2==1 ? unit[cid][i][j].lmwd[2]:
			                                        unit[cid][i][j].t[2]   ;
    unit[cid][i][j].tr[3] = unit[cid][i][j].conf.cdw2.trs3==0 ? unit[cid][i][3].exdr   :
                            unit[cid][i][j].conf.cdw2.trs3==1 ? unit[cid][i][j].lmwd[3]:
			                                        unit[cid][i][j].t[3]   ;
    return (0);
  case STATUS_TERM:
    return (0);
  }
}

siml_unit_lmm(cid,  i, j) Uint cid, i, j; /* 旧TR/旧EADRを使ったLMM動作 & TR更新 */
{
  Ull a0, a1, a0al, a1al, d;
  int k;

  /* write:  cexdr,mw,ma                                -> LMM                      */
  /* read:   cexdr,exdr,mw/tr,ma/ea[01]dr,LMM -> mr[01] -> br,lmrd                  */
  /*        |         |         |         |         |         |         |         | */
  /* clk ___/~~~~\____/~~~~\____/~~~~\____/~~~~\____/~~~~\____/~~~~\____/~~~~\____/ */
  /* en  ____/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\___________________ */
  /* rw  _______read___/~~~~~~write~~~~~~~~\______read_____________________________ */
  /* ma  -----<   A0  ><   A1   ><   A2   ><   A3   ><   A4   >-------------------- */
  /* mw  --------------<   W1   ><   W2   >---------------------------------------- */
  /* mr  --------------<   R0   >--------------------<   R3   ><   R4   >---------- */

  a0   = unit[cid][i][j].ea0dr % LMEM_SIZE;
  a1   = unit[cid][i][j].ea1dr % LMEM_SIZE;
  a0al = unit[cid][i][j].lmm.ma0; /* should be aligned by fsm */
  a1al = unit[cid][i][j].lmm.ma1; /* should be aligned by fsm */

  switch (emax5[cid].status) {
  case STATUS_IDLE:
  case STATUS_CONF:
  case STATUS_SCON:
  case STATUS_LMMI:
    return (0);
  case STATUS_DRAIN:
    if (unit[cid][i][j].lmm.en1 && !unit[cid][i][j].lmm.rw1) { /* lmm read enabled */
      unit[cid][i][j].rrdy = 1; /* rdata valid */
      for (k=0; k<UNIT_WIDTH; k++)
        emax5[cid].fsm[j].lmrd[k] = unit[cid][i][j].lmrd[k] = unit[cid][i][j].lmm.mr1[k] = *((Ull*)&unit[cid][i][j].lmm.m[a1al]+k);
    }
    else
      unit[cid][i][j].rrdy = 0; /* rdata invalid */
    return (0);
  case STATUS_LOAD: /* 水平方向broadcastの受取りもここ */
    if (unit[cid][i][j].lmm.en0 && unit[cid][i][j].lmm.rw0) { /* lmm write enabled */
      for (k=0; k<UNIT_WIDTH; k++)
        *((Ull*)&unit[cid][i][j].lmm.m[a0al]+k) = (*((Ull*)&unit[cid][i][j].lmm.m[a0al]+k) & ~unit[cid][i][j].lmm.mm0[k]) | (unit[cid][i][j].lmm.mw0[k] & unit[cid][i][j].lmm.mm0[k]);
      /*printf("LMM pload row=%d col=%d: A=%08.8x %08.8x/%08.8x %08.8x/%08.8x %08.8x/%08.8x %08.8x/%08.8x\n", i, j, (Uint)a0al, (Uint)unit[cid][i][j].lmm.mw0[3], (Uint)unit[cid][i][j].lmm.mm0[3], (Uint)unit[cid][i][j].lmm.mw0[2], (Uint)unit[cid][i][j].lmm.mm0[2], (Uint)unit[cid][i][j].lmm.mw0[1], (Uint)unit[cid][i][j].lmm.mm0[1], (Uint)unit[cid][i][j].lmm.mw0[0], (Uint)unit[cid][i][j].lmm.mm0[0]);*/
    }
    return (0);
  case STATUS_REGV:
    if (emax5[cid].fsm[j].row_select & (1LL<<i)) {
      for (k=0; k<UNIT_WIDTH; k++) {
        switch (unit[cid][i][j].lmwa) {
        case 0: /* lower */
          *((Ull*)&unit[cid][i][j].regv+0+k) = unit[cid][i][j].lmwd[k];
          break;
        case 1: /* upper */
          *((Ull*)&unit[cid][i][j].regv+4+k) = unit[cid][i][j].lmwd[k];
          break;
        }
      }
    }
    return (0);
  case STATUS_START:
    unit[cid][i][j].drty = 0; /* reset dirty */
    return (0);
  case STATUS_EXEC:
    /* store mw    -> lmm[] */
    /* load  lmm[] -> mr    */
    if (unit[cid][i][j].conf.cdw1.ea1op == OP_IM_DRAIN
     || unit[cid][i][j].conf.cdw1.ea1op == OP_LDDMQ
     || unit[cid][i][j].conf.cdw1.ea1op == OP_TR) {
      if (unit[cid][i][j].lmm.en1 && !unit[cid][i][j].lmm.rw1) { /* lmm read enabled */
	unit[cid][i][j].rrdy = 1; /* rdata valid */
	for (k=0; k<UNIT_WIDTH; k++)
	  emax5[cid].fsm[j].lmrd[k] = unit[cid][i][j].lmrd[k] = unit[cid][i][j].lmm.mr1[k] = *((Ull*)&unit[cid][i][j].lmm.m[a1al]+k);
	/*printf("LMM read row=%d col=%d: A=%08.8x %08.8x %08.8x %08.8x %08.8x\n", i, j, (Uint)a1al, (Uint)emax5[cid].fsm[j].lmrd[3], (Uint)emax5[cid].fsm[j].lmrd[2], (Uint)emax5[cid].fsm[j].lmrd[1], (Uint)emax5[cid].fsm[j].lmrd[0]);*/
      }
      else
	unit[cid][i][j].rrdy = 0; /* rdata invalid */
    }
    else if (unit[cid][i][j].conf.cdw1.ea1op) { /* OP_IM_BUFRD or normal load */
      if (unit[cid][i][j].lmm.en1 && !unit[cid][i][j].lmm.rw1) { /* lmm read enabled */
	for (k=0; k<UNIT_WIDTH; k++)
	  unit[cid][i][j].lmm.mr1[k] = *((Ull*)&unit[cid][i][j].lmm.m[a1al]+k);
	/*printf("LMM read row=%d col=%d: A=%08.8x %08.8x %08.8x %08.8x %08.8x\n", i, j, (Uint)a1al, (Uint)unit[cid][i][j].lmm.mr1[3], (Uint)unit[cid][i][j].lmm.mr1[2], (Uint)unit[cid][i][j].lmm.mr1[1], (Uint)unit[cid][i][j].lmm.mr1[0]);*/
      }
    }
    
    if (unit[cid][i][j].conf.cdw1.ea0op == OP_IM_PREF) {
      if (unit[cid][i][j].lmm.en0 &&  unit[cid][i][j].lmm.rw0) { /* lmm write enabled */
	for (k=0; k<UNIT_WIDTH; k++)
	  *((Ull*)&unit[cid][i][j].lmm.m[a0al]+k) = (*((Ull*)&unit[cid][i][j].lmm.m[a0al]+k) & ~unit[cid][i][j].lmm.mm0[k]) | (unit[cid][i][j].lmm.mw0[k] & unit[cid][i][j].lmm.mm0[k]);
	/*printf("PRF write row=%d col=%d: A=%08.8x %08.8x/%08.8x %08.8x/%08.8x %08.8x/%08.8x %08.8x/%08.8x\n", i, j, (Uint)a0al, (Uint)unit[cid][i][j].lmm.mw0[3], (Uint)unit[cid][i][j].lmm.mm0[3], (Uint)unit[cid][i][j].lmm.mw0[2], (Uint)unit[cid][i][j].lmm.mm0[2], (Uint)unit[cid][i][j].lmm.mw0[1], (Uint)unit[cid][i][j].lmm.mm0[1], (Uint)unit[cid][i][j].lmm.mw0[0], (Uint)unit[cid][i][j].lmm.mm0[0]);*/
      }
    }
    else if (unit[cid][i][j].conf.cdw1.ea0op) { /* normal load/store */
      if (unit[cid][i][j].lmm.en0 && !unit[cid][i][j].lmm.rw0) { /* lmm read enabled */
	for (k=0; k<UNIT_WIDTH; k++)
	  unit[cid][i][j].lmm.mr0[k] = *((Ull*)&unit[cid][i][j].lmm.m[a0al]+k);
      }
      if (unit[cid][i][j].lmm.en0 &&  unit[cid][i][j].lmm.rw0) { /* lmm write enabled */
	/*emax5[cid].fsm[j].lmmd[i] = 1; /* mark dirty */
	if (unit[cid][i][j].conf.cdw1.ea0op < OP_LDDMQ)
	  unit[cid][i][j].drty = 1; /* mark dirty (OP_LDDMQ,OP_TR,OP_IM_BUFWR,は除外が必要) */
	for (k=0; k<UNIT_WIDTH; k++)
	  *((Ull*)&unit[cid][i][j].lmm.m[a0al]+k) = (*((Ull*)&unit[cid][i][j].lmm.m[a0al]+k) & ~unit[cid][i][j].lmm.mm0[k]) | (unit[cid][i][j].lmm.mw0[k] & unit[cid][i][j].lmm.mm0[k]);
	/*printf("LMM write row=%d col=%d: A=%08.8x %08.8x/%08.8x %08.8x/%08.8x %08.8x/%08.8x %08.8x/%08.8x\n", i, j, (Uint)a0al, (Uint)unit[cid][i][j].lmm.mw0[3], (Uint)unit[cid][i][j].lmm.mm0[3], (Uint)unit[cid][i][j].lmm.mw0[2], (Uint)unit[cid][i][j].lmm.mm0[2], (Uint)unit[cid][i][j].lmm.mw0[1], (Uint)unit[cid][i][j].lmm.mm0[1], (Uint)unit[cid][i][j].lmm.mw0[0], (Uint)unit[cid][i][j].lmm.mm0[0]);*/
      }
    }
    
    /* load mr -> br0 */
    switch (unit[cid][i][j].conf.cdw2.brs0) {
    case 0:                                                          break; /* off */
    case 1: unit[cid][i][j].regv.br[0] = unit[cid][i][j].lmm.mr1[0]; break; /* 1:mr10 align不要 */
    case 2: unit[cid][i][j].regv.br[0] = unit[cid][i][j].tr[0];      break; /* 2:tr0  align不要 */
    case 3:                                                                 /* 3:mr0  align必要 */
      unit[cid][i][j].mr0mux = (a0/sizeof(Ull) & (UNIT_WIDTH-1)); /* mr0[3-0] -> mr0d */
      unit[cid][i][j].mr0d   = unit[cid][i][j].lmm.mr0[unit[cid][i][j].mr0mux];
      switch (unit[cid][i][j].conf.cdw1.ea0op) {
      case OP_LDR :  unit[cid][i][j].regv.br[0] =                unit[cid][i][j].mr0d;                                                                                 break;
      case OP_LDWR:  unit[cid][i][j].regv.br[0] = (Sll)   (int)((unit[cid][i][j].mr0d >> ((a0 & (sizeof(int)                           ))*8)) & 0x00000000ffffffffLL); break;
      case OP_LDUWR: unit[cid][i][j].regv.br[0] = (Ull)  (Uint)((unit[cid][i][j].mr0d >> ((a0 & (sizeof(int)                           ))*8)) & 0x00000000ffffffffLL); break;
      case OP_LDHR:  unit[cid][i][j].regv.br[0] = (Sll) (short)((unit[cid][i][j].mr0d >> ((a0 & (sizeof(int)|sizeof(short)             ))*8)) & 0x000000000000ffffLL); break;
      case OP_LDUHR: unit[cid][i][j].regv.br[0] = (Ull)(Ushort)((unit[cid][i][j].mr0d >> ((a0 & (sizeof(int)|sizeof(short)             ))*8)) & 0x000000000000ffffLL); break;
      case OP_LDBR:  unit[cid][i][j].regv.br[0] = (Sll)  (char)((unit[cid][i][j].mr0d >> ((a0 & (sizeof(int)|sizeof(short)|sizeof(char)))*8)) & 0x00000000000000ffLL); break;
      case OP_LDUBR: unit[cid][i][j].regv.br[0] = (Ull) (Uchar)((unit[cid][i][j].mr0d >> ((a0 & (sizeof(int)|sizeof(short)|sizeof(char)))*8)) & 0x00000000000000ffLL); break;
      }
    }
    /* load mr -> br1 */
    switch (unit[cid][i][j].conf.cdw2.brs1) {
    case 0:                                                          break; /* off */
    case 1: unit[cid][i][j].regv.br[1] = unit[cid][i][j].lmm.mr1[1]; break; /* 1:mr11 align不要 */
    case 2: unit[cid][i][j].regv.br[1] = unit[cid][i][j].tr[1];      break; /* 2:tr1  align不要 */
    case 3:                                                                 /* 3:mr1  align必要 */
      unit[cid][i][j].mr1mux = (a1/sizeof(Ull) & (UNIT_WIDTH-1)); /* mr1[3-0] -> mr0d */
      unit[cid][i][j].mr1d   = unit[cid][i][j].lmm.mr1[unit[cid][i][j].mr1mux];
      switch (unit[cid][i][j].conf.cdw1.ea1op) {
      case OP_LDR:   unit[cid][i][j].regv.br[1] =                unit[cid][i][j].mr1d;                                                                                 break;
      case OP_LDWR:  unit[cid][i][j].regv.br[1] = (Sll)   (int)((unit[cid][i][j].mr1d >> ((a1 & (sizeof(int)                           ))*8)) & 0x00000000ffffffffLL); break;
      case OP_LDUWR: unit[cid][i][j].regv.br[1] = (Ull)  (Uint)((unit[cid][i][j].mr1d >> ((a1 & (sizeof(int)                           ))*8)) & 0x00000000ffffffffLL); break;
      case OP_LDHR:  unit[cid][i][j].regv.br[1] = (Sll) (short)((unit[cid][i][j].mr1d >> ((a1 & (sizeof(int)|sizeof(short)             ))*8)) & 0x000000000000ffffLL); break;
      case OP_LDUHR: unit[cid][i][j].regv.br[1] = (Ull)(Ushort)((unit[cid][i][j].mr1d >> ((a1 & (sizeof(int)|sizeof(short)             ))*8)) & 0x000000000000ffffLL); break;
      case OP_LDBR:  unit[cid][i][j].regv.br[1] = (Sll)  (char)((unit[cid][i][j].mr1d >> ((a1 & (sizeof(int)|sizeof(short)|sizeof(char)))*8)) & 0x00000000000000ffLL); break;
      case OP_LDUBR: unit[cid][i][j].regv.br[1] = (Ull) (Uchar)((unit[cid][i][j].mr1d >> ((a1 & (sizeof(int)|sizeof(short)|sizeof(char)))*8)) & 0x00000000000000ffLL); break;
      }
    }
    /* load mr -> br2 */
    switch (unit[cid][i][j].conf.cdw2.brs2) {
    case 0:                                                          break; /* off */
    case 1: unit[cid][i][j].regv.br[2] = unit[cid][i][j].lmm.mr1[2]; break; /* 1:mr12 align不要 */
    case 2: unit[cid][i][j].regv.br[2] = unit[cid][i][j].tr[2];      break; /* 2:tr2  align不要 */
    case 3: unit[cid][i][j].regv.br[2] = unit[cid][i][j].exdr;       break; /* 3:exdr align不要 */
    }
    /* load mr -> br3 */
    switch (unit[cid][i][j].conf.cdw2.brs3) {
    case 0:                                                          break; /* off */
    case 1: unit[cid][i][j].regv.br[3] = unit[cid][i][j].lmm.mr1[3]; break; /* 1:mr13 align不要 */
    case 2: unit[cid][i][j].regv.br[3] = unit[cid][i][j].tr[3];      break; /* 2:tr3  align不要 */
    }
    return (0);
  case STATUS_TERM:
    return (0);
  }
}

show_emax5_pa(cid, pa_cycle) Uint cid; Ull pa_cycle;
{
  int tid = emax5[cid].tid;
  Ull total;

  printf("%03.3d:PA %08.8x_%08.8x siml_emax5: tinit=%08.8x_%08.8x  conf=%08.8x_%08.8x scon=%08.8x_%08.8x lmmi=%08.8x_%08.8x drain=%08.8x_%08.8x load=%08.8x_%08.8x\n",
         tid,
         (Uint)(t[tid].total_steps>>32),      (Uint)(t[tid].total_steps),
         (Uint)(emax5[cid].cycles_tinit>>32), (Uint)emax5[cid].cycles_tinit,
         (Uint)(emax5[cid].cycles_conf>>32),  (Uint)emax5[cid].cycles_conf,
         (Uint)(emax5[cid].cycles_scon>>32),  (Uint)emax5[cid].cycles_scon,
         (Uint)(emax5[cid].cycles_lmmi>>32),  (Uint)emax5[cid].cycles_lmmi,
         (Uint)(emax5[cid].cycles_drain>>32), (Uint)emax5[cid].cycles_drain,
         (Uint)(emax5[cid].cycles_load>>32),  (Uint)emax5[cid].cycles_load);
  printf("                                      regv=%08.8x_%08.8x start=%08.8x_%08.8x exec=%08.8x_%08.8x term=%08.8x_%08.8x trans=%08.8x_%08.8x\n",
         (Uint)(emax5[cid].cycles_regv>>32),  (Uint)emax5[cid].cycles_regv,
         (Uint)(emax5[cid].cycles_start>>32), (Uint)emax5[cid].cycles_start,
         (Uint)(emax5[cid].cycles_exec>>32),  (Uint)emax5[cid].cycles_exec,
         (Uint)(emax5[cid].cycles_term>>32),  (Uint)emax5[cid].cycles_term,
         (Uint)(emax5[cid].cycles_trans>>32), (Uint)emax5[cid].cycles_trans);
  total = emax5[cid].cycles_tinit+emax5[cid].cycles_conf+emax5[cid].cycles_scon+emax5[cid].cycles_lmmi+emax5[cid].cycles_drain+emax5[cid].cycles_load+emax5[cid].cycles_regv+emax5[cid].cycles_start+emax5[cid].cycles_exec+emax5[cid].cycles_term+emax5[cid].cycles_trans;
  printf("\033[33m%03.3d:EMAX%dMHz=%08.8x_%08.8x(icidlrett)", cid, 2400/ARM_EMAX5_RATIO, (Uint)(total>>32), (Uint)total);
  printf("\033[33m%03.3d:ARM%dMHz=%08.8x_%08.8x\033[0m\n",  cid, 2400, (Uint)(pa_cycle>>32), (Uint)pa_cycle);

  emax5[cid].cycles_tinit = 0LL;
  emax5[cid].cycles_conf  = 0LL;
  emax5[cid].cycles_scon  = 0LL;
  emax5[cid].cycles_lmmi  = 0LL;
  emax5[cid].cycles_drain = 0LL;
  emax5[cid].cycles_load  = 0LL;
  emax5[cid].cycles_regv  = 0LL;
  emax5[cid].cycles_start = 0LL;
  emax5[cid].cycles_exec  = 0LL;
  emax5[cid].cycles_term  = 0LL;
  emax5[cid].cycles_trans = 0LL;
}

show_emax5_status(cid) Uint cid;
{
  int row, col, i;

  /* Black       0;30     Dark Gray     1;30 */
  /* Blue        0;34     Light Blue    1;34 */
  /* Green       0;32     Light Green   1;32 */
  /* Cyan        0;36     Light Cyan    1;36 */
  /* Red         0;31     Light Red     1;31 */
  /* Purple      0;35     Light Purple  1;35 */
  /* Brown       0;33     Yellow        1;33 */
  /* Light Gray  0;37     White         1;37 */

  /* show EMAX5 */
  printf("==== EMAX5[%02.2d] v=%d tid=%d stat=%d l_conf=%08.8x_%08.8x l_dist=%d last_row0=%d unit1_exec=%08.8x_%08.8x unit1_stop=%08.8x_%08.8x unit2_exec=%08.8x_%08.8x unit2_stop=%08.8x_%08.8x\n",
         cid, emax5[cid].v, emax5[cid].tid, emax5[cid].status, (Uint)(emax5[cid].last_conf>>32), (Uint)emax5[cid].last_conf, emax5[cid].last_dist, emax5[cid].last_row0,
         (Uint)(emax5[cid].unit1_exec>>32), (Uint)emax5[cid].unit1_exec, (Uint)(emax5[cid].unit1_stop>>32), (Uint)emax5[cid].unit1_stop, (Uint)(emax5[cid].unit2_exec>>32), (Uint)emax5[cid].unit2_exec, (Uint)(emax5[cid].unit2_stop>>32), (Uint)emax5[cid].unit2_stop);

  /* show FSM tables */
  for (col=EMAX_WIDTH-1; col>=0; col--)
    printf("         ---- FSM[%d] lmmo[],lmmc[],lmmd[]           ", col);
  printf("\n");
  for (row=0; row<EMAX_DEPTH; row++) {
    printf("lmmo[%02.2d]", row);
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("|\033[1;%dmd%d v%d rw%d f%d p%d b%d l%08.8x b%01.1x c%d top%08.8x%08.8x\033[0m",
             (Uint) emax5[cid].fsm[col].lmmo[row].v?36:34,
             (Uint) emax5[cid].fsm[col].lmmd[row],
             (Uint) emax5[cid].fsm[col].lmmo[row].v,
             (Uint) emax5[cid].fsm[col].lmmo[row].rw,
             (Uint) emax5[cid].fsm[col].lmmo[row].f,
             (Uint) emax5[cid].fsm[col].lmmo[row].p,
             (Uint) emax5[cid].fsm[col].lmmo[row].blk,
             (Uint) emax5[cid].fsm[col].lmmo[row].len,
             (Uint) emax5[cid].fsm[col].lmmo[row].bcas,
             (Uint) emax5[cid].fsm[col].lmmo[row].copy,
             (Uint)(emax5[cid].fsm[col].lmmo[row].top>>32),
             (Uint) emax5[cid].fsm[col].lmmo[row].top);
    printf("\n");
    printf("lmmc[%02.2d]", row);
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("|\033[1;%dmd%d v%d rw%d f%d p%d b%d l%08.8x b%01.1x c%d top%08.8x%08.8x\033[0m",
             (Uint) emax5[cid].fsm[col].lmmc[row].v?36:34,
             (Uint) emax5[cid].fsm[col].lmmd[row],
             (Uint) emax5[cid].fsm[col].lmmc[row].v,
             (Uint) emax5[cid].fsm[col].lmmc[row].rw,
             (Uint) emax5[cid].fsm[col].lmmc[row].f,
             (Uint) emax5[cid].fsm[col].lmmc[row].p,
             (Uint) emax5[cid].fsm[col].lmmc[row].blk,
             (Uint) emax5[cid].fsm[col].lmmc[row].len,
             (Uint) emax5[cid].fsm[col].lmmc[row].bcas,
             (Uint) emax5[cid].fsm[col].lmmc[row].copy,
             (Uint)(emax5[cid].fsm[col].lmmc[row].top>>32),
             (Uint) emax5[cid].fsm[col].lmmc[row].top);
    printf("\n");
  }

  /* show FSM controllers */
  for (col=EMAX_WIDTH-1; col>=0; col--)
    printf("         ---- FSM[%d] status=%02.2d bus_controller                       ", col, emax5[cid].status);
  printf("\n");
  for (col=EMAX_WIDTH-1; col>=0; col--)
    printf("         ---- unit1exec=%08.8x%08.8x unit1stop=%08.8x%08.8x ",
         (Uint)(emax5[cid].unit1_exec>>32), (Uint)emax5[cid].unit1_exec,
         (Uint)(emax5[cid].unit1_stop>>32), (Uint)emax5[cid].unit1_stop);
  printf("\n");
  for (col=EMAX_WIDTH-1; col>=0; col--)
    printf("         ---- unit2exec=%08.8x%08.8x unit2stop=%08.8x%08.8x ",
         (Uint)(emax5[cid].unit2_exec>>32), (Uint)emax5[cid].unit2_exec,
         (Uint)(emax5[cid].unit2_stop>>32), (Uint)emax5[cid].unit2_stop);
  printf("\n");
  printf("ld-ms-rc");
  for (col=EMAX_WIDTH-1; col>=0; col--)
    printf("|%d %d rc%02.2d rs%08.8x%08.8x lmen%08.8x%08.8x ardy%04.4d rrdy%04.4d ",
           (Uint) emax5[cid].fsm[col].memif_status,
           (Uint) emax5[cid].fsm[col].last_dist,
           (Uint) emax5[cid].fsm[col].row_count,
           (Uint)(emax5[cid].fsm[col].row_select>>32),
           (Uint) emax5[cid].fsm[col].row_select,
           (Uint)(emax5[cid].fsm[col].row_lmm_en>>32),
           (Uint) emax5[cid].fsm[col].row_lmm_en,
           emax5[cid].fsm[col].ardyc,
           emax5[cid].fsm[col].rrdyc);
  printf("\n");
  printf("aralawal");
  for (col=EMAX_WIDTH-1; col>=0; col--)
    printf("|%08.8x%08.8x %08.8x%08.8x %08.8x%08.8x %08.8x%08.8x",
           (Uint)(emax5[cid].fsm[col].araddr>>32),
           (Uint) emax5[cid].fsm[col].araddr,
           (Uint)(emax5[cid].fsm[col].arlen>>32),
           (Uint) emax5[cid].fsm[col].arlen,
           (Uint)(emax5[cid].fsm[col].awaddr>>32),
           (Uint) emax5[cid].fsm[col].awaddr,
           (Uint)(emax5[cid].fsm[col].awlen>>32),
           (Uint) emax5[cid].fsm[col].awlen);
  printf("\n");
  printf("lmwraxrw");
  for (col=EMAX_WIDTH-1; col>=0; col--)
    printf("|%08.8x%08.8x %08.8x%08.8x                                  ",
           (Uint)(emax5[cid].fsm[col].lmwa>>32),
           (Uint) emax5[cid].fsm[col].lmwa,
           (Uint)(emax5[cid].fsm[col].lmra>>32),
           (Uint) emax5[cid].fsm[col].lmra);
  printf("\n");
  printf("lmwd3-0 ");
  for (col=EMAX_WIDTH-1; col>=0; col--)
    printf("|%08.8x%08.8x %08.8x%08.8x %08.8x%08.8x %08.8x%08.8x",
           (Uint)(emax5[cid].fsm[col].lmwd[3]>>32),
           (Uint) emax5[cid].fsm[col].lmwd[3],
           (Uint)(emax5[cid].fsm[col].lmwd[2]>>32),
           (Uint) emax5[cid].fsm[col].lmwd[2],
           (Uint)(emax5[cid].fsm[col].lmwd[1]>>32),
           (Uint) emax5[cid].fsm[col].lmwd[1],
           (Uint)(emax5[cid].fsm[col].lmwd[0]>>32),
           (Uint) emax5[cid].fsm[col].lmwd[0]);
  printf("\n");
  printf("lmrd3-0 ");
  for (col=EMAX_WIDTH-1; col>=0; col--)
    printf("|%08.8x%08.8x %08.8x%08.8x %08.8x%08.8x %08.8x%08.8x",
           (Uint)(emax5[cid].fsm[col].lmrd[3]>>32),
           (Uint) emax5[cid].fsm[col].lmrd[3],
           (Uint)(emax5[cid].fsm[col].lmrd[2]>>32),
           (Uint) emax5[cid].fsm[col].lmrd[2],
           (Uint)(emax5[cid].fsm[col].lmrd[1]>>32),
           (Uint) emax5[cid].fsm[col].lmrd[1],
           (Uint)(emax5[cid].fsm[col].lmrd[0]>>32),
           (Uint) emax5[cid].fsm[col].lmrd[0]);
  printf("\n");
  printf("axistat ");
  for (col=EMAX_WIDTH-1; col>=0; col--)
    printf("|arr%d arv%d rv%d awr%d awv%d wst%08.8x wv%d ilen%04.4d idel%04.4d          ",
           (Uint) emax5[cid].fsm[col].axi_arready,
           (Uint) emax5[cid].fsm[col].axi_arvalid,
           (Uint) emax5[cid].fsm[col].axi_rvalid,
           (Uint) emax5[cid].fsm[col].axi_awready,
           (Uint) emax5[cid].fsm[col].axi_awvalid,
           (Uint) emax5[cid].fsm[col].axi_wstrb,
           (Uint) emax5[cid].fsm[col].axi_wvalid,
           (Uint) emax5[cid].fsm[col].ilen,
           (Uint) emax5[cid].fsm[col].idelay);
  printf("\n");
  printf("axaraxaw");
  for (col=EMAX_WIDTH-1; col>=0; col--)
    printf("|%08.8x%08.8x %08.8x%08.8x %08.8x%08.8x %08.8x%08.8x",
           (Uint)(emax5[cid].fsm[col].axi_araddr>>32),
           (Uint) emax5[cid].fsm[col].axi_araddr,
           (Uint)(emax5[cid].fsm[col].axi_arlen>>32),
           (Uint) emax5[cid].fsm[col].axi_arlen,
           (Uint)(emax5[cid].fsm[col].axi_awaddr>>32),
           (Uint) emax5[cid].fsm[col].axi_awaddr,
           (Uint)(emax5[cid].fsm[col].axi_awlen>>32),
           (Uint) emax5[cid].fsm[col].axi_awlen);
  printf("\n");
  printf("rdat3-0 ");
  for (col=EMAX_WIDTH-1; col>=0; col--)
    printf("|%08.8x%08.8x %08.8x%08.8x %08.8x%08.8x %08.8x%08.8x",
           (Uint)(emax5[cid].fsm[col].axi_rdata[3]>>32),
           (Uint) emax5[cid].fsm[col].axi_rdata[3],
           (Uint)(emax5[cid].fsm[col].axi_rdata[2]>>32),
           (Uint) emax5[cid].fsm[col].axi_rdata[2],
           (Uint)(emax5[cid].fsm[col].axi_rdata[1]>>32),
           (Uint) emax5[cid].fsm[col].axi_rdata[1],
           (Uint)(emax5[cid].fsm[col].axi_rdata[0]>>32),
           (Uint) emax5[cid].fsm[col].axi_rdata[0]);
  printf("\n");
  printf("wdat3-0 ");
  for (col=EMAX_WIDTH-1; col>=0; col--)
    printf("|%08.8x%08.8x %08.8x%08.8x %08.8x%08.8x %08.8x%08.8x",
           (Uint)(emax5[cid].fsm[col].axi_wdata[3]>>32),
           (Uint) emax5[cid].fsm[col].axi_wdata[3],
           (Uint)(emax5[cid].fsm[col].axi_wdata[2]>>32),
           (Uint) emax5[cid].fsm[col].axi_wdata[2],
           (Uint)(emax5[cid].fsm[col].axi_wdata[1]>>32),
           (Uint) emax5[cid].fsm[col].axi_wdata[1],
           (Uint)(emax5[cid].fsm[col].axi_wdata[0]>>32),
           (Uint) emax5[cid].fsm[col].axi_wdata[0]);
  printf("\n");
#ifndef IGNORE_LDDMQ_HANDSHAKE
  printf("tcur3-0 ");
  for (col=EMAX_WIDTH-1; col>=0; col--)
    printf("|%08.8x%08.8x %08.8x%08.8x %08.8x%08.8x %08.8x%08.8x",
           (Uint)(emax5[cid].fsm[col].tcureg[3]>>32),
           (Uint) emax5[cid].fsm[col].tcureg[3],
           (Uint)(emax5[cid].fsm[col].tcureg[2]>>32),
           (Uint) emax5[cid].fsm[col].tcureg[2],
           (Uint)(emax5[cid].fsm[col].tcureg[1]>>32),
           (Uint) emax5[cid].fsm[col].tcureg[1],
           (Uint)(emax5[cid].fsm[col].tcureg[0]>>32),
           (Uint) emax5[cid].fsm[col].tcureg[0]);
  printf("\n");
#endif

  /* show UNIT status */
  for (row=0; row<EMAX_DEPTH; row++) {
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("         ---- UNIT[%d][%d]                                            ", row, col);
    printf("\n");
    printf("cdw0    ");
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("|op123=%02.2x_%x_%x ex1=%01.1x_%d%d ex2=%01.1x_%d ex3=%01.1x_%d e2i%08.8x%08.8x_%d e3i%02.2x_%d",
             (Uint) unit[cid][row][col].conf.cdw0.op1,
             (Uint) unit[cid][row][col].conf.cdw0.op2,
             (Uint) unit[cid][row][col].conf.cdw0.op3,
             (Uint) unit[cid][row][col].conf.cdw0.ex1brs,
             (Uint) unit[cid][row][col].conf.cdw0.ex1s,
             (Uint) unit[cid][row][col].conf.cdw0.ex1exp,
             (Uint) unit[cid][row][col].conf.cdw0.ex2brs,
             (Uint) unit[cid][row][col].conf.cdw0.ex2exp,
             (Uint) unit[cid][row][col].conf.cdw0.ex3brs,
             (Uint) unit[cid][row][col].conf.cdw0.ex3exp,
             (Uint)(unit[cid][row][col].conf.cdw3.e2imm>>32),
             (Uint) unit[cid][row][col].conf.cdw3.e2imm,
             (Uint) unit[cid][row][col].conf.cdw0.e2is,
             (Uint) unit[cid][row][col].conf.cdw0.e3imm,
             (Uint) unit[cid][row][col].conf.cdw0.e3is);
    printf("\n");
    printf("cdw1    ");
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("|cop=%01.1x%01.1x%01.1x%01.1x_%04.4x ea1=%02.2x_%d_%d_%01.1x ea0=%02.2x_%d_%d_%01.1x eab=%01.1x eao=%01.1x                ",
             (Uint) unit[cid][row][col].conf.cdw1.cs3,
             (Uint) unit[cid][row][col].conf.cdw1.cs2,
             (Uint) unit[cid][row][col].conf.cdw1.cs1,
             (Uint) unit[cid][row][col].conf.cdw1.cs0,
             (Uint) unit[cid][row][col].conf.cdw1.cex_tab,
             (Uint) unit[cid][row][col].conf.cdw1.ea1op,
             (Uint) unit[cid][row][col].conf.cdw1.ea1bs,
             (Uint) unit[cid][row][col].conf.cdw1.ea1os,
             (Uint) unit[cid][row][col].conf.cdw1.ea1msk,
             (Uint) unit[cid][row][col].conf.cdw1.ea0op,
             (Uint) unit[cid][row][col].conf.cdw1.ea0bs,
             (Uint) unit[cid][row][col].conf.cdw1.ea0os,
             (Uint) unit[cid][row][col].conf.cdw1.ea0msk,
             (Uint) unit[cid][row][col].conf.cdw1.eabbrs,
             (Uint) unit[cid][row][col].conf.cdw1.eaobrs);
    printf("\n");
    printf("cdw2-3  ");
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("|lmls%d lmrs%d ts3-0=%01.1x%01.1x%01.1x%01.1x mwsa%d mws3-0=%d%d%d%d brs3-0=%d%d%d%d xmws%d mapd=%d  ",
             (Uint) unit[cid][row][col].conf.cdw2.lmls,
             (Uint) unit[cid][row][col].conf.cdw2.lmrs,
             (Uint) unit[cid][row][col].conf.cdw2.ts3,
             (Uint) unit[cid][row][col].conf.cdw2.ts2,
             (Uint) unit[cid][row][col].conf.cdw2.ts1,
             (Uint) unit[cid][row][col].conf.cdw2.ts0,
             (Uint) unit[cid][row][col].conf.cdw2.mwsa,
             (Uint) unit[cid][row][col].conf.cdw2.mws3,
             (Uint) unit[cid][row][col].conf.cdw2.mws2,
             (Uint) unit[cid][row][col].conf.cdw2.mws1,
             (Uint) unit[cid][row][col].conf.cdw2.mws0,
             (Uint) unit[cid][row][col].conf.cdw2.brs3,
             (Uint) unit[cid][row][col].conf.cdw2.brs2,
             (Uint) unit[cid][row][col].conf.cdw2.brs1,
             (Uint) unit[cid][row][col].conf.cdw2.brs0,
             (Uint) unit[cid][row][col].conf.cdw2.xmws,
             (Uint) unit[cid][row][col].conf.cdw2.mapdist);
    printf("\n");
    printf("regvea10");
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("|%08.8x%08.8x %08.8x%08.8x %08.8x%08.8x %08.8x%08.8x",
             (Uint)(unit[cid][row][col].regv.ea1br>>32),
             (Uint) unit[cid][row][col].regv.ea1br,
             (Uint)(unit[cid][row][col].regv.ea1or>>32),
             (Uint) unit[cid][row][col].regv.ea1or,
             (Uint)(unit[cid][row][col].regv.ea0br>>32),
             (Uint) unit[cid][row][col].regv.ea0br,
             (Uint)(unit[cid][row][col].regv.ea0or>>32),
             (Uint) unit[cid][row][col].regv.ea0or);
    printf("\n");
    printf("regvbr30");
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("|%08.8x%08.8x %08.8x%08.8x %08.8x%08.8x %08.8x%08.8x",
             (Uint)(unit[cid][row][col].regv.br[3]>>32),
             (Uint) unit[cid][row][col].regv.br[3],
             (Uint)(unit[cid][row][col].regv.br[2]>>32),
             (Uint) unit[cid][row][col].regv.br[2],
             (Uint)(unit[cid][row][col].regv.br[1]>>32),
             (Uint) unit[cid][row][col].regv.br[1],
             (Uint)(unit[cid][row][col].regv.br[0]>>32),
             (Uint) unit[cid][row][col].regv.br[0]);
    printf("\n");
    printf("cexex123");
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("|os=%d c3-0=%01.1x%01.1x%01.1x%01.1x_%01.1x %08.8x%08.8x %08.8x%08.8x %08.8x%08.8x",
             (Uint) unit[cid][row][col].one_shot,
             (Uint) unit[cid][row][col].c[3],
             (Uint) unit[cid][row][col].c[2],
             (Uint) unit[cid][row][col].c[1],
             (Uint) unit[cid][row][col].c[0],
             (Uint) unit[cid][row][col].cexdr,
             (Uint)(unit[cid][row][col].ex1>>32),
             (Uint) unit[cid][row][col].ex1,
             (Uint)(unit[cid][row][col].ex2>>32),
             (Uint) unit[cid][row][col].ex2,
             (Uint)(unit[cid][row][col].ex3>>32),
             (Uint) unit[cid][row][col].ex3);
    printf("\n");
    printf("eab eao ");
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("|%08.8x%08.8x %08.8x%08.8x                                  ",
             (Uint)(unit[cid][row][col].eab>>32),
             (Uint) unit[cid][row][col].eab,
             (Uint)(unit[cid][row][col].eao>>32),
             (Uint) unit[cid][row][col].eao);
    printf("\n");
    printf("ea1 ea0 ");
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("|%08.8x%08.8x %08.8x%08.8x %08.8x%08.8x %08.8x%08.8x",
             (Uint)(unit[cid][row][col].ea1b>>32),
             (Uint) unit[cid][row][col].ea1b,
             (Uint)(unit[cid][row][col].ea1o>>32),
             (Uint) unit[cid][row][col].ea1o,
             (Uint)(unit[cid][row][col].ea0b>>32),
             (Uint) unit[cid][row][col].ea0b,
             (Uint)(unit[cid][row][col].ea0o>>32),
             (Uint) unit[cid][row][col].ea0o);
    printf("\n");
    printf("exd ead ");
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("|%08.8x%08.8x %08.8x%08.8x %08.8x%08.8x lmen=%d rrdy=%d   ",
             (Uint)(unit[cid][row][col].exdr>>32),
             (Uint) unit[cid][row][col].exdr,
             (Uint)(unit[cid][row][col].ea1dr>>32),
             (Uint) unit[cid][row][col].ea1dr,
             (Uint)(unit[cid][row][col].ea0dr>>32),
             (Uint) unit[cid][row][col].ea0dr,
             unit[cid][row][col].lmen,
             unit[cid][row][col].rrdy);
    printf("\n");
    printf("lmwalmra");
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("|%08.8x%08.8x %08.8x%08.8x                                  ",
             (Uint)(unit[cid][row][col].lmwa>>32),
             (Uint) unit[cid][row][col].lmwa,
             (Uint)(unit[cid][row][col].lmra>>32),
             (Uint) unit[cid][row][col].lmra);
    printf("\n");
    printf("lmwd3-0 ");
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("|%08.8x%08.8x %08.8x%08.8x %08.8x%08.8x %08.8x%08.8x",
             (Uint)(unit[cid][row][col].lmwd[3]>>32),
             (Uint) unit[cid][row][col].lmwd[3],
             (Uint)(unit[cid][row][col].lmwd[2]>>32),
             (Uint) unit[cid][row][col].lmwd[2],
             (Uint)(unit[cid][row][col].lmwd[1]>>32),
             (Uint) unit[cid][row][col].lmwd[1],
             (Uint)(unit[cid][row][col].lmwd[0]>>32),
             (Uint) unit[cid][row][col].lmwd[0]);
    printf("\n");
    printf("lmrd3-0 ");
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("|%08.8x%08.8x %08.8x%08.8x %08.8x%08.8x %08.8x%08.8x",
             (Uint)(unit[cid][row][col].lmrd[3]>>32),
             (Uint) unit[cid][row][col].lmrd[3],
             (Uint)(unit[cid][row][col].lmrd[2]>>32),
             (Uint) unit[cid][row][col].lmrd[2],
             (Uint)(unit[cid][row][col].lmrd[1]>>32),
             (Uint) unit[cid][row][col].lmrd[1],
             (Uint)(unit[cid][row][col].lmrd[0]>>32),
             (Uint) unit[cid][row][col].lmrd[0]);
    printf("\n");
    printf("lmralmla");
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("|%08.8x%08.8x %08.8x%08.8x %08.8x%08.8x %08.8x%08.8x",
             (Uint)(unit[cid][row][col].lmria>>32),
             (Uint) unit[cid][row][col].lmria,
             (Uint)(unit[cid][row][col].lmroa>>32),
             (Uint) unit[cid][row][col].lmroa,
             (Uint)(unit[cid][row][col].lmlia>>32),
             (Uint) unit[cid][row][col].lmlia,
             (Uint)(unit[cid][row][col].lmloa>>32),
             (Uint) unit[cid][row][col].lmloa);
    printf("\n");
    printf("lmri3-0 ");
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("|%08.8x%08.8x %08.8x%08.8x %08.8x%08.8x %08.8x%08.8x",
             (Uint)(unit[cid][row][col].lmri[3]>>32),
             (Uint) unit[cid][row][col].lmri[3],
             (Uint)(unit[cid][row][col].lmri[2]>>32),
             (Uint) unit[cid][row][col].lmri[2],
             (Uint)(unit[cid][row][col].lmri[1]>>32),
             (Uint) unit[cid][row][col].lmri[1],
             (Uint)(unit[cid][row][col].lmri[0]>>32),
             (Uint) unit[cid][row][col].lmri[0]);
    printf("\n");
    printf("lmro3-0 ");
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("|%08.8x%08.8x %08.8x%08.8x %08.8x%08.8x %08.8x%08.8x",
             (Uint)(unit[cid][row][col].lmro[3]>>32),
             (Uint) unit[cid][row][col].lmro[3],
             (Uint)(unit[cid][row][col].lmro[2]>>32),
             (Uint) unit[cid][row][col].lmro[2],
             (Uint)(unit[cid][row][col].lmro[1]>>32),
             (Uint) unit[cid][row][col].lmro[1],
             (Uint)(unit[cid][row][col].lmro[0]>>32),
             (Uint) unit[cid][row][col].lmro[0]);
    printf("\n");
    printf("lmli3-0 ");
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("|%08.8x%08.8x %08.8x%08.8x %08.8x%08.8x %08.8x%08.8x",
             (Uint)(unit[cid][row][col].lmli[3]>>32),
             (Uint) unit[cid][row][col].lmli[3],
             (Uint)(unit[cid][row][col].lmli[2]>>32),
             (Uint) unit[cid][row][col].lmli[2],
             (Uint)(unit[cid][row][col].lmli[1]>>32),
             (Uint) unit[cid][row][col].lmli[1],
             (Uint)(unit[cid][row][col].lmli[0]>>32),
             (Uint) unit[cid][row][col].lmli[0]);
    printf("\n");
    printf("lmlo3-0 ");
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("|%08.8x%08.8x %08.8x%08.8x %08.8x%08.8x %08.8x%08.8x",
             (Uint)(unit[cid][row][col].lmlo[3]>>32),
             (Uint) unit[cid][row][col].lmlo[3],
             (Uint)(unit[cid][row][col].lmlo[2]>>32),
             (Uint) unit[cid][row][col].lmlo[2],
             (Uint)(unit[cid][row][col].lmlo[1]>>32),
             (Uint) unit[cid][row][col].lmlo[1],
             (Uint)(unit[cid][row][col].lmlo[0]>>32),
             (Uint) unit[cid][row][col].lmlo[0]);
    printf("\n");
    printf("t3-0    ");
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("|%08.8x%08.8x %08.8x%08.8x %08.8x%08.8x %08.8x%08.8x",
             (Uint)(unit[cid][row][col].t[3]>>32),
             (Uint) unit[cid][row][col].t[3],
             (Uint)(unit[cid][row][col].t[2]>>32),
             (Uint) unit[cid][row][col].t[2],
             (Uint)(unit[cid][row][col].t[1]>>32),
             (Uint) unit[cid][row][col].t[1],
             (Uint)(unit[cid][row][col].t[0]>>32),
             (Uint) unit[cid][row][col].t[0]);
    printf("\n");
    printf("tr3-0   ");
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("|%08.8x%08.8x %08.8x%08.8x %08.8x%08.8x %08.8x%08.8x",
             (Uint)(unit[cid][row][col].tr[3]>>32),
             (Uint) unit[cid][row][col].tr[3],
             (Uint)(unit[cid][row][col].tr[2]>>32),
             (Uint) unit[cid][row][col].tr[2],
             (Uint)(unit[cid][row][col].tr[1]>>32),
             (Uint) unit[cid][row][col].tr[1],
             (Uint)(unit[cid][row][col].tr[0]>>32),
             (Uint) unit[cid][row][col].tr[0]);
    printf("\n");
    printf("lmm1-0  ");
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("|en%d rw%d ma%08.8x%08.8x        en%d rw%d ma%08.8x%08.8x       ",
             (Uint) unit[cid][row][col].lmm.en1,
             (Uint) unit[cid][row][col].lmm.rw1,
             (Uint)(unit[cid][row][col].lmm.ma1>>32),
             (Uint) unit[cid][row][col].lmm.ma1,
             (Uint) unit[cid][row][col].lmm.en0,
             (Uint) unit[cid][row][col].lmm.rw0,
             (Uint)(unit[cid][row][col].lmm.ma0>>32),
             (Uint) unit[cid][row][col].lmm.ma0);
    printf("\n");
    printf("mm0[3-0]");
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("|%08.8x%08.8x %08.8x%08.8x %08.8x%08.8x %08.8x%08.8x",
             (Uint)(unit[cid][row][col].lmm.mm0[3]>>32),
             (Uint) unit[cid][row][col].lmm.mm0[3],
             (Uint)(unit[cid][row][col].lmm.mm0[2]>>32),
             (Uint) unit[cid][row][col].lmm.mm0[2],
             (Uint)(unit[cid][row][col].lmm.mm0[1]>>32),
             (Uint) unit[cid][row][col].lmm.mm0[1],
             (Uint)(unit[cid][row][col].lmm.mm0[0]>>32),
             (Uint) unit[cid][row][col].lmm.mm0[0]);
    printf("\n");
    printf("mw0[3-0]");
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("|\033[1;%dm%08.8x%08.8x %08.8x%08.8x %08.8x%08.8x %08.8x%08.8x\033[0m",
	     unit[cid][row][col].lmm.en0 && unit[cid][row][col].lmm.rw0?35:34,
             (Uint)(unit[cid][row][col].lmm.mw0[3]>>32),
             (Uint) unit[cid][row][col].lmm.mw0[3],
             (Uint)(unit[cid][row][col].lmm.mw0[2]>>32),
             (Uint) unit[cid][row][col].lmm.mw0[2],
             (Uint)(unit[cid][row][col].lmm.mw0[1]>>32),
             (Uint) unit[cid][row][col].lmm.mw0[1],
             (Uint)(unit[cid][row][col].lmm.mw0[0]>>32),
             (Uint) unit[cid][row][col].lmm.mw0[0]);
    printf("\n");
    printf("mr0[3-0]");
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("|%08.8x%08.8x %08.8x%08.8x %08.8x%08.8x %08.8x%08.8x",
             (Uint)(unit[cid][row][col].lmm.mr0[3]>>32),
             (Uint) unit[cid][row][col].lmm.mr0[3],
             (Uint)(unit[cid][row][col].lmm.mr0[2]>>32),
             (Uint) unit[cid][row][col].lmm.mr0[2],
             (Uint)(unit[cid][row][col].lmm.mr0[1]>>32),
             (Uint) unit[cid][row][col].lmm.mr0[1],
             (Uint)(unit[cid][row][col].lmm.mr0[0]>>32),
             (Uint) unit[cid][row][col].lmm.mr0[0]);
    printf("\n");
    printf("mr1[3-0]");
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("|\033[1;%dm%08.8x%08.8x %08.8x%08.8x %08.8x%08.8x %08.8x%08.8x\033[0m",
	     unit[cid][row][col].rrdy?36:34,
             (Uint)(unit[cid][row][col].lmm.mr1[3]>>32),
             (Uint) unit[cid][row][col].lmm.mr1[3],
             (Uint)(unit[cid][row][col].lmm.mr1[2]>>32),
             (Uint) unit[cid][row][col].lmm.mr1[2],
             (Uint)(unit[cid][row][col].lmm.mr1[1]>>32),
             (Uint) unit[cid][row][col].lmm.mr1[1],
             (Uint)(unit[cid][row][col].lmm.mr1[0]>>32),
             (Uint) unit[cid][row][col].lmm.mr1[0]);
    printf("\n");
    printf("mr1-0xd ");
    for (col=EMAX_WIDTH-1; col>=0; col--)
      printf("|mr1mux=%d mr0mux=%d mr1d=%08.8x%08.8x mr0d=%08.8x%08.8x      ",
             (Uint) unit[cid][row][col].mr1mux,
             (Uint) unit[cid][row][col].mr0mux,
             (Uint)(unit[cid][row][col].mr1d>>32),
             (Uint) unit[cid][row][col].mr1d,
             (Uint)(unit[cid][row][col].mr0d>>32),
             (Uint) unit[cid][row][col].mr0d);
    printf("\n");
  }
}
