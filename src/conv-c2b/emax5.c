
static char RcsHeader[] = "$Header: /usr/home/nakashim/proj-arm64/src/conv-c2b/RCS/emax5.c,v 1.162 2018/02/17 16:22:54 nakashim Exp nakashim $";

/* EMAX5 Compiler                      */
/*         Copyright (C) 2012 by NAIST */
/*         Primary writer: Y.Nakashima */
/*                nakashim@is.naist.jp */

/* emax5.c 2012/9/22 */

#include <stdio.h>
#include "conv-c2b.h"
#include "emax5.h"

emit_emax5a(int mode) /* 0:array, 1:drain */
{
  int i, j, k, flag;
  int last_row = -1; /* last location */
  int last_col = -1; /* last location */
  int last_mop = -1; /* 0:mop0, 1:mop1 */
  int bcas_col = 0;  /* for rotating broadcasting #1 */
  int bcas_co2 = 0;  /* for rotating broadcasting #2 */
  struct cex *dcex;
  struct exu *dexu;
  struct mop *dmop0, *dmop1;

  if (mode == 1) { /* emit drain */
    fprintf(ofile, "\temax5_drain_dirty_lmm();\n");
    return (0);
  }

  /**********************************************************************************************************/
  /* ��insn[]�˳�Ǽ����륪�ڥ��ɼ���ʡ������а��ֻ�����ҡ�                                             */
  /*              T_IMMEDIATE  T_VARIABLE              T_EXRNO     T_ALRNO                  T_BDRNO         */
  /* ------------------------------------------------------------------------------------------------------ */
  /* while_src1 :              VARIABLE,                                                                    */
  /* while_src2 : IMMEDIATE,                                                                                */
  /* while_dst  :              VARIABLE,                                                                    */
  /* ------------------------------------------------------------------------------------------------------ */
  /* cex_src    : IMMEDIATE,   VARIABLE,                                                                    */
  /* cex_dst    :                                       &EXRNO                                              */
  /* ------------------------------------------------------------------------------------------------------ */
  /* ex4_src    :                          VARIABLE([]),           ALRNO[r]([]),            BDRNO[r][c]([]) */
  /*                                     ����alu���Ϥ�BDRNO[r][*][2]���ͳ ����ld���Ϥ�BDRNO[r][c][*]���ͳ */
  /* ex4_dstd   :                          VARIABLE([]),         ��ALRNO[r]([]),       �������»��ˤ�BR��ͳ */
  /*                                       ���ʤ�alu����           ���ʤ�alu����       ����ѥ��餬��ư���� */
  /* ------------------------------------------------------------------------------------------------------ */
  /* exe_src1   : IMMEDIATE,   VARIABLE,   VARIABLE[s],            ALRNO[r][s],             BDRNO[r][c][s]  */
  /* exe_src2   : IMMEDIATE,   VARIABLE,   VARIABLE[s],            ALRNO[r][s],             BDRNO[r][c][s]  */
  /* exe_src3   : IMMEDIATE,   VARIABLE,   VARIABLE[s],            ALRNO[r][s],             BDRNO[r][c][s]  */
  /* exe_src4   : IMMEDIATE,   VARIABLE,   VARIABLE[s],            ALRNO[r][s],             BDRNO[r][c][s]  */
  /* exe_src5   : IMMEDIATE,   VARIABLE,   VARIABLE[s],            ALRNO[r][s],             BDRNO[r][c][s]  */
  /* exe_dstd   :             &VARIABLE,  &VARIABLE[s],         ��&ALRNO[r][s],                             */
  /* ------------------------------------------------------------------------------------------------------ */
  /* mop_ex     : IMMEDIATE,                           ��EXRNO                                              */
  /* mo4_srcdst :                          VARIABLE([]),           ALRNO[r]([]),          ��BDRNO[r][c]([]) */
  /*                                            store4,                 store4,                       load4 */
  /* mop_srcdst :             &VARIABLE,  &VARIABLE[s],           &ALRNO[r][s],          ��&BDRNO[r][c][01] */
  /*                             store1,        store1, store1,         store1,                       load1 */
  /*               store-data��variable/gprno��,ɬ��Ʊ���ʤ�ALU����.���ʤ�BR��store�������,ɬ��ALU���̤� */
  /* mop_base   :              VARIABLE,    VARIABLE[s],                                    BDRNO[r][c][s]  */
  /* mop.offset : IMMEDIATE,   VARIABLE,    VARIABLE[s],                                    BDRNO[r][c][s]  */
  /* mop.stream :              VARIABLE,                                                                    */
  /**********************************************************************************************************/
  /* ��insn[]->decode[r][c] ���֥롼��                                                                      */
  /*   ���������֡��������֥ҥ�Ȥ˻��ѡ�����Ū�ˤϺ����                                                   */
  /* - ex4(),exe():            dst��ALRNO[]��BDRNO[][]�����ꤵ��Ƥ�����,������֤�����                   */
  /* - mo4(load),mop(load):    dst��BDRNO[][]�����ꤵ��Ƥ�����,������֤�����                            */
  /*   ����������                                                                                           */
  /* - cex():                  src��cx�����ꤵ��Ƥ�����,cx�����ʤμ��ʤ�����                             */
  /* - mo4(exx):               src��exx�����ꤵ��Ƥ�����,exx�����ʤ�Ʊ�ʤ�����                           */
  /**********************************************************************************************************/
  /*******************************************************************************************************************************************************/
  /* ��lmmi�ؼ��롼�� (copy from conv-c2b/emac5.c)                                                                  lmmi-loc  v  top  blk  len  rw  f  p */
  /* LD with force-read=0 and ptop==NULL generates current(lmr) and reuse LMM. same as lmr in EMAX4                     curr  1  top  blk  len   0  0  0 */
  /* LD with force-read=1 and ptop==NULL generates current(lmf) and !reuse LMM. same as lmf in EMAX4                    curr  1  top  blk  len   0  1  0 */
  /* LD with force-read=0 and ptop!=NULL generates current(lmr) and next(lmp). mapdist!=0                               curr  1  top  blk  len   0  0  0 */
  /*                                                                                                                  c+dist  1 ptop  blk  len   0  0  1 */
  /* LD with force-read=0 and ptop!=NULL generates current(lmr) and next(lmp). mapdist==0                  ofs=ptop-top curr  1  top  blk  len   0  0  1 */
  /*                                                                                                               p=1�ξ��,pref-addr�Ͼ��lmmi.top+ofs */
  /* LDDMQ set f=1 and p=1 in lmmc automatically                                                                        curr  1  top  -    -     0  1  1 */
  /*******************************************************************************************************************************************************/
  /* ST with force-read=0 and ptop==NULL generates current(lmw) and reuse+wback LMM. same as lmw in EMAX4               curr  1  top  blk  len   1  0  0 */
  /* ST with force-read=1 and ptop==NULL generates current(lmx) and !reuse+wback LMM. same as lmx in EMAX4              curr  1  top  blk  len   1  1  0 */
  /* ST with force-read=0 and ptop!=NULL generates current(lmw) and prev(lmd). mapdist!=0                               curr  1  top  blk  len   1  0  0 */
  /*                                                                                                                  c-dist  1 ptop  blk  len   1  0  1 */
  /* ST with force-read=0 and ptop!=NULL generates current(lmw) and prev(lmd). mapdist==0                  ofs=ptop-top curr  1  top  blk  len   1  0  1 */
  /*                                                                                                              p=1�ξ��,drain-addr�Ͼ��lmmi.top+ofs */
  /* TR    set f=1 and p=1 in lmmc automatically                                                                        curr  1  top  -    -     1  1  1 */
  /*******************************************************************************************************************************************************/
  /**********************************************************************************************************/
  /* Step 1 ... decode[][]��Ͽ�����¥쥸����                                                                */
  /* 1-1.  ��insn[]��src��˰�¸�ط������оݤ���Ф�,insn[].header.rdep����ӡ�rdep�����ع���             */
  /*                              ��get_valid_row(hash) ... id[hash].type�ˤ�����                         */
  /*                                src������id[].row,col(����ͤ�-1)�Ƚ缡���                           */
  /* 1.2a  ���а��ֻ����row,col���ʤ����(row=-1)                                                          */
  /*                              ��last_row��,last_row��rdep���礭���������                               */
  /*                                last_row,last_col�����ä��Ĥ�����                                       */
  /* 1.2b  ���а��ֻ����row,col��������(row>=0)                                                          */
  /*                              ������row < rdep��last_row���礭�����ʤ�error                             */
  /*                                last_row�����row�˹���                                                 */
  /* 1-3.  ��Լ����Ȥζ��縡��                                                                             */
  /*                              ��exe()��mop()�����ϥ쥸��������,����reg��­,reg��nw�����,�����оݳ�     */
  /* 1-4.  insn[]->decode[][]���ԡ������ALU��ǽ������Ʋ��ݸ���                                            */
  /* 1-5.  busmap+���¥쥸���������emax�Ȱۤʤ�,�����ѿ���,Ʊ����̥����Ǥλ��Ȥ�ػ�(�༡�¹ԤȤθߴ�)  */
  /*                           ---src�˴ؤ���busmap---                                                      */
  /*                              ��WHILE stype=VAR                                                         */
  /*                                   -id.row=-1�ʤ�ARM��ľ������BR�ζ���������                            */
  /*                                   -id.row>=0�ʤ�error                                                  */
  /*                              ��CEX stype=VAR                                                           */
  /*                                   -id.row=-1�ʤ�ARM��ľ������BR�ζ���������                            */
  /*                                   -id.row>=0 & row=����(id.itype=CEX)�ʤ� ��                           */
  /*                                   -          & row=����(id.itype=EXE)�ʤ� ��                           */
  /*                                   -          & row=����(id.itype=MOP)�ʤ� ��                           */
  /*                                   -          & row=����(id.itype=CEX)�ʤ� ��                           */
  /*                                   -          & row=����(id.itype=EXE)�ʤ�,ARõ��->BR����               */
  /*                                   -          & row=����(id.itype=MOP)�ʤ�,BRõ��                       */
  /*                                   -          & row=����(id.itype=CEX)�ʤ� ��                           */
  /*                                   -          & row=����(id.itype=EXE)�ʤ�,ARõ��->BR����->BR����       */
  /*                                   -          & row=����(id.itype=MOP)�ʤ�,BRõ��        ->BR����       */
  /*                              ��EX4 stype=VAR,AR,BR                                                     */
  /*                              ��EXE stype=VAR,AR,BR,EX                                                  */
  /*                                   -id.row=-1�ʤ�ARM��ľ������BR�ζ���������                            */
  /*                                   -id.row>=0 & row=����(id.itype=CEX)�ʤ�,EX ��                        */
  /*                                   -          & row=����(id.itype=EXE)�ʤ� ��                           */
  /*                                   -          & row=����(id.itype=MOP)�ʤ� ��                           */
  /*                                   -          & row=����(id.itype=CEX)�ʤ� ��                           */
  /*                                   -          & row=����(id.itype=EXE)�ʤ�,ARõ��->BR����               */
  /*                                   -          & row=����(id.itype=MOP)�ʤ�,BRõ��                       */
  /*                                   -          & row=����(id.itype=CEX)�ʤ� ��                           */
  /*                                   -          & row=����(id.itype=EXE)�ʤ�,ARõ��->BR����->BR����       */
  /*                                   -          & row=����(id.itype=MOP)�ʤ�,BRõ��        ->BR����       */
  /*                              ��MO4 stype=VAR,AR,BR,EX                                                  */
  /*                              ��MOP stype=VAR,AR,BR,EX                                                  */
  /*                                   -id.row=-1�ʤ�ARM��ľ������BR�ζ���������                            */
  /*                                   -id.row>=0 & row=����(id.itype=CEX)�ʤ�,EX ��                        */
  /*                                   -          & row=����(id.itype=EXE)�ʤ�,AR ��                        */
  /*                                   -          & row=����(id.itype=MOP)�ʤ� ��                           */
  /*                                   -          & row=����(id.itype=CEX)�ʤ� ��                           */
  /*                                   -          & row=����(id.itype=EXE)�ʤ�,ARõ��->BR����               */
  /*                                   -          & row=����(id.itype=MOP)�ʤ�,BRõ��                       */
  /*                                   -          & row=����(id.itype=CEX)�ʤ� ��                           */
  /*                                   -          & row=����(id.itype=EXE)�ʤ�,ARõ��->BR����->BR����       */
  /*                                   -          & row=����(id.itype=MOP)�ʤ�,BRõ��        ->BR����       */
  /* 1-6.  ���֤����.dst�ѿ��ΰ��־����id[].row,col�˵�Ͽ                                                 */
  /*                           ---dst�˴ؤ���busmap---                                                      */
  /*                              ��WHILE�ΰ��ְ��ۻ����[0,0]��       busmap��EXDR(AR)�ߤ�                 */
  /*                              ��CEX  �ΰ������������̵��          busmap��CEXD�ߤ� (UNIT��Ǿ���)      */
  /*                              ��EXE  �ΰ������������out-AR��      busmap��EXDR(AR)�ߤ�                 */
  /*                 MTYPE_*LOAD  ��LD   �ΰ������������out-BR��      busmap��BR�ߤ�                       */
  /*                 MTYPE_*STORE ��ST/TR�ΰ������������Ʊrow��in-AR��busmap��TR�ߤ�                       */
  /**********************************************************************************************************/
  for (i=0; i<last_insn; i++) {
    char type  =  insn[i].iheader.type;
    char row   =  insn[i].iheader.row; /* ���� */
    char col   =  insn[i].iheader.col; /* ���� */
    char *rdep = &insn[i].iheader.rdep;
    if (row >= EMAX_DEPTH || col >= EMAX_WIDTH) {
      printf("in %s: specified [%d][%d] exceed limits (EMAX_ROW=%d EMAX_COL=%d)\n", id[current_prefix].name, row, col, EMAX_DEPTH, EMAX_WIDTH);
      exit(1);
    }
#if 1
    printf("%s:insn%03.3d:type=%d [%3.2d,%3.2d] ->", id[current_prefix].name, i, type, row, col);
#endif
    switch (type) {
    case ITYPE_WHILE: /* WHILE */
      /****************************************/
      /* WHILE is mapped only on decode[0][0] */
      /* and has only loc-free variable       */
      /* 1-1                                  */
      /****************************************/
      switch (insn[i].iexe.op1) {
      case OP_WHILE:
        /* ���op�Ϥʤ��Τ�,iheader.rdep��0�Τޤ޹������� */
        break;
      default:
        printf("in %s: while found illegal op=%d\n", id[current_prefix].name, insn[i].iexe.op1);
        exit(1);
      }
      if (row < 0) { /* none of WHILE/ALR/BDR is specified */
        /* 1-2a */
        /* never reached */
      }
      else { /* WHILE/ALR/BDR is specified */
        /* 1-2b */
        if (row > 0 || col > 0) { /* 0,0 is specified in conv-c2b.y */
          printf("in %s: [%d][%d] while found\n", id[current_prefix].name, row, col);
          exit(1);
        }
        if (last_row < row) { /* ����row�ޤǴ֤������Τ�C�Ȥ���OK *//* while�Ͼ�ˤ������̲� */
          last_row = row;
          last_col = 0;
        }
        else { /* last_row >= row *//* ���������C�Ȥ��ư�̣���Ѥ��Τ�����error *//* while����Ƭ�ˤʤ����˳��� */
          printf("in %s: while found violation of sequence (last_row=%d >= row=%d)\n", id[current_prefix].name, last_row, row);
          exit(1);
        }
      }
      /* 1-3 */
      if (last_row >= EMAX_DEPTH || last_col >= EMAX_WIDTH) { /* copy���˸��� */
        printf("in %s: [%d][%d] while exceeds EMAX_DEPTH/EMAX_WIDTH\n", id[current_prefix].name, last_row, last_col);
        exit(1);
      }
      if (dec[last_row][last_col].dexu.op1 || dec[last_row][last_col].dexu.op2 || dec[last_row][last_col].dexu.op3) { /* ��Լ����Ȥζ��縡�� */
        printf("in %s: [%d][%d] while conflicts\n", id[current_prefix].name, last_row, last_col);
        exit(1);
      }
      /* 1-4 */
      dexu = &dec[last_row][last_col].dexu;
      dexu->op1    = insn[i].iexe.op1;
      dexu->op2    = insn[i].iexe.op2;
      dexu->op3    = insn[i].iexe.op3;
      dexu->updt   = insn[i].iexe.updt;
      dexu->ex1v   = insn[i].iexe.src1v; /* default */
      dexu->ex1h   = insn[i].iexe.src1h; /* default */
      dexu->ex1s   = insn[i].iexe.src1s; /* default */
      dexu->ex1e   = insn[i].iexe.src1e; /* default */
      dexu->ex2v   = insn[i].iexe.src2v; /* default */
      dexu->ex2h   = insn[i].iexe.src2h; /* default */
      dexu->ex2s   = insn[i].iexe.src2s; /* default */
      dexu->ex2e   = insn[i].iexe.src2e; /* default */
      dexu->ex3v   = T_NONE;
      dexu->ex3h   = -1;
      dexu->ex3s   = -1;
      dexu->ex3e   = 0;
      dexu->e2iv   = T_NONE;
      dexu->e2ih   = -1;
      dexu->e2is   = 0;
      dexu->e3iv   = T_NONE;
      dexu->e3ih   = -1;
      dexu->e3is   = 0;
      dexu->exdv   = insn[i].iexe.exedv; /* default */
      dexu->exdh   = insn[i].iexe.exedh; /* default */
      dexu->exds   = insn[i].iexe.exeds; /* default */
      /* 1-5 *//* EMAX4�Ȱۤʤ��༡�¹Ըߴ��Τ���,prop_skp������ */
      /*     *//* id[].row,col��-1�ξ��,src��ARM�����å�.���ʤξ��br����.����ʳ���br����. */
      set_reg_path(last_row, last_col, type, RTYPE_DATA, 0, dexu->ex1v, dexu->ex1h, dexu->ex1s);
      set_reg_path(last_row, last_col, type, RTYPE_DATA, 0, dexu->ex2v, dexu->ex2h, dexu->ex2s);
      /* 1-6 *//* ��Ǽ��busmap��EXDR�ߤޤ� */
      bus[last_row][last_col].exdrv = dexu->exdv;
      bus[last_row][last_col].exdrh = dexu->exdh;
      bus[last_row][last_col].exdrs = dexu->exds;
      id[insn[i].iexe.exedh].itype = ITYPE_WHILE;
      id[insn[i].iexe.exedh].row   = last_row;
      id[insn[i].iexe.exedh].col   = last_col;
      insn[i].iheader.fixed = 1;
      break;
    case ITYPE_CEX: /* CEX */
      /*********************************************/
      /* CEX is mapped on the row next to exe_dstc */
      /* and has no absolute location              */
      /* 1-1                                       */
      /*********************************************/
      switch (insn[i].icex.op) {
      case OP_CEXE:
        get_valid_row(ITYPE_CEX, 0, insn[i].icex.bit0v, insn[i].icex.bit0h, rdep);
        get_valid_row(ITYPE_CEX, 0, insn[i].icex.bit1v, insn[i].icex.bit1h, rdep);
        get_valid_row(ITYPE_CEX, 0, insn[i].icex.bit2v, insn[i].icex.bit2h, rdep);
        get_valid_row(ITYPE_CEX, 0, insn[i].icex.bit3v, insn[i].icex.bit3h, rdep);
        break;
      default:
        printf("in %s: cexe found illegal op=%d\n", id[current_prefix].name, insn[i].icex.op);
        exit(1);
      }
      if (row < 0) { /* none of WHILE/ALR/BDR is specified */
        /* 1-2a *//* Ʊ��row��ʣ��CEXE�����֤���뤳�Ȥ����� */
        if (last_row < *rdep) { /* �֤���������ֲ�ǽ */
          last_row = *rdep;
          last_col = 0;
        }
        else { /* last_row >= *rdep *//* �ǽ�����>=��¸�ط�������� */
          if (dec[last_row][last_col].dcex.op) /* Ʊ��row��³CEXE������.��Լ����Ȥζ��縡�� */
            last_col++; /* overflow�Ϥ��ȤǸ���.CEXE��WIDTH�ʾ夢���error */
        }
      }
      else { /* WHILE/ALR/BDR is specified */
        /* 1-2b */
        /* never reached */
      }
      /* 1-3 */
      if (last_row >= EMAX_DEPTH || last_col >= EMAX_WIDTH) { /* copy���˸��� */
        printf("in %s: [%d][%d] cexe exceeds EMAX_DEPTH/EMAX_WIDTH\n", id[current_prefix].name, last_row, last_col);
        exit(1);
      }
      if (dec[last_row][last_col].dcex.op) { /* ��Լ����Ȥζ��縡�� */
        printf("in %s: [%d][%d] cexe conflicts\n", id[current_prefix].name, last_row, last_col);
        exit(1);
      }
      /* 1-4 */
      dcex = &dec[last_row][last_col].dcex;
      *dcex = insn[i].icex;
      /* 1-5 *//* EMAX4�Ȱۤʤ��༡�¹Ըߴ��Τ���,prop_skp������ */
      /*     *//* id[].row,col��-1�ξ��,src��ARM�����å�.���ʤξ��br����.����ʳ���br����. */
      set_reg_path(last_row, last_col, type, RTYPE_DATA, 0, dcex->bit0v, dcex->bit0h, -1);
      set_reg_path(last_row, last_col, type, RTYPE_DATA, 0, dcex->bit1v, dcex->bit1h, -1);
      set_reg_path(last_row, last_col, type, RTYPE_DATA, 0, dcex->bit2v, dcex->bit2h, -1);
      set_reg_path(last_row, last_col, type, RTYPE_DATA, 0, dcex->bit3v, dcex->bit3h, -1);
      /* 1-6 *//* ��Ǽ��busmap��CEXD�ߤޤ� */
      bus[last_row][last_col].cexdv = dcex->cexdv;
      bus[last_row][last_col].cexdh = dcex->cexdh;
      id[insn[i].icex.cexdh].itype = ITYPE_CEX;
      id[insn[i].icex.cexdh].row   = last_row;
      id[insn[i].icex.cexdh].col   = last_col;
      insn[i].iheader.fixed = 1;
      break;
    case ITYPE_EX4: /* EX4 */
      /**********************************************/
      /* EX4 has variable([]) or bdr[][]([]) as src */
      /* 1-1                                        */
      /**********************************************/
      switch (insn[i].iexe.op1) {
      case OP_FAD: /* 2 */
      case OP_FML: /* 2 */
      case OP_ADD: /* 2 */
      case OP_SUB: /* 2 */
        get_valid_row(ITYPE_EX4, 0, insn[i].iexe.src1v, insn[i].iexe.src1h, rdep);
        get_valid_row(ITYPE_EX4, 0, insn[i].iexe.src2v, insn[i].iexe.src2h, rdep);
        insn[i].iexe.src3v = T_NONE; /* delete */
        break;
      case OP_FMA:  /* 3 */
      case OP_ADD3: /* 3 */
      case OP_SUB3: /* 3 */
        get_valid_row(ITYPE_EX4, 0, insn[i].iexe.src1v, insn[i].iexe.src1h, rdep);
        get_valid_row(ITYPE_EX4, 0, insn[i].iexe.src2v, insn[i].iexe.src2h, rdep);
        get_valid_row(ITYPE_EX4, 0, insn[i].iexe.src3v, insn[i].iexe.src3h, rdep);
        break;
      default:
        printf("in %s: ex4 found illegal op1=%d\n", id[current_prefix].name, insn[i].iexe.op1);
        exit(1);
      }
      if (row < 0) { /* none of WHILE/ALR/BDR is specified */
        /* 1-2a */
        if (last_row < *rdep) { /* �֤���������ֲ�ǽ */
          last_row = *rdep;
          last_col = 0; /* ���ֻ����ǽex4.dst��ALR�Τ�.var��ͳ��Ʊ��row���³st4()�����ֲ�ǽ */
        }
        else { /* last_row >= *rdep *//* �ǽ�����>=��¸�ط�������� */
          if (dec[last_row][0].dexu.op1 || dec[last_row][0].dexu.op2 || dec[last_row][0].dexu.op3) { /* ��Լ����Ȥζ��縡�� */
            last_row++; /* overflow�Ϥ��ȤǸ���.CEXE��WIDTH�ʾ夢���error */
            last_col = 0; /* ���ֻ����ǽex4.dst��ALR�Τ�.var��ͳ��Ʊ��row���³st4()�����ֲ�ǽ */
          }
        }
      }
      else { /* WHILE/ALR/BDR is specified */
        /* 1-2b */
        if (row < *rdep) { /* ����row�ˤ����ֺ��� */
          printf("in %s: ex4 cannot locate destination ALRNO (row=%d)\n", id[current_prefix].name, row);
          exit(1);
        }
        else if (row < last_row) {
          printf("in %s: ex4 found violation of sequence (row=%d < last_row=%d)\n", id[current_prefix].name, row, last_row);
          exit(1);
        }
        else {
          last_row = row;
          last_col = 0; /* ���ֻ����ǽex4.dst��ALR�Τ�.ALR��ͳ��Ʊ��row���³st4()�����ֲ�ǽ */
        }
      }
      /* 1-3 */
      if (last_row >= EMAX_DEPTH || last_col >= EMAX_WIDTH) { /* copy���˸��� */
        printf("in %s: [%d][%d] ex4 exceeds EMAX_DEPTH/EMAX_WIDTH\n", id[current_prefix].name, last_row, last_col);
        exit(1);
      }
      /* ex4[row] is expanded into all columns in decode[row][] */
      for (j=0; j<EMAX_WIDTH; j++) {
        if (dec[last_row][j].dexu.op1 || dec[last_row][j].dexu.op2 || dec[last_row][j].dexu.op3) { /* ��Լ����Ȥζ��縡�� */
          printf("in %s: [%d][%d] ex4 conflicts\n", id[current_prefix].name, last_row, j);
          exit(1);
        }
      }
      /* 1-4 */
      for (j=0; j<EMAX_WIDTH; j++) {
        dexu = &dec[last_row][j].dexu;
        dexu->op1    = insn[i].iexe.op1;
        dexu->op2    = insn[i].iexe.op2;
        dexu->op3    = insn[i].iexe.op3;
        dexu->updt   = insn[i].iexe.updt;
        dexu->ex1v   = insn[i].iexe.src1v; /* default */
        dexu->ex1h   = insn[i].iexe.src1h; /* default */
        dexu->ex1s   = j;
        dexu->ex1e   = insn[i].iexe.src1e; /* default */
        dexu->ex2v   = insn[i].iexe.src2v; /* default */
        dexu->ex2h   = insn[i].iexe.src2h; /* default */
        dexu->ex2s   = j;
        dexu->ex2e   = insn[i].iexe.src2e; /* default */
        dexu->ex3v   = insn[i].iexe.src3v; /* default */
        dexu->ex3h   = insn[i].iexe.src3h; /* default */
        dexu->ex3s   = j;
        dexu->ex3e   = insn[i].iexe.src3e; /* default */
        dexu->e2iv   = T_NONE;
        dexu->e2ih   = -1;
        dexu->e2is   = 0;
        dexu->e3iv   = T_NONE;
        dexu->e3ih   = -1;
        dexu->e3is   = 0;
        dexu->exdv   = insn[i].iexe.exedv; /* default */
        dexu->exdh   = insn[i].iexe.exedh; /* default */
        dexu->exds   = j;
      }
      /* 1-5 *//* EMAX4�Ȱۤʤ��༡�¹Ըߴ��Τ���,prop_skp������ */
      /*     *//* id[].row,col��-1�ξ��,src��ARM�����å�.���ʤξ��br����.����ʳ���br����. */
      for (j=0; j<EMAX_WIDTH; j++) {
        dexu = &dec[last_row][j].dexu;
        set_reg_path(last_row, last_col, type, RTYPE_DATA, 0, dexu->ex1v, dexu->ex1h, dexu->ex1s); /* ex1s=3,2,1,0 */
        set_reg_path(last_row, last_col, type, RTYPE_DATA, 0, dexu->ex2v, dexu->ex2h, dexu->ex2s); /* ex2s=3,2,1,0 */
        set_reg_path(last_row, last_col, type, RTYPE_DATA, 0, dexu->ex3v, dexu->ex3h, dexu->ex3s); /* ex3s=3,2,1,0 */
      }
      /* 1-6 *//* ��Ǽ��busmap��EXDR�ߤޤ� */
      for (j=0; j<EMAX_WIDTH; j++) {
        dexu = &dec[last_row][j].dexu;
        bus[last_row][j].exdrv = dexu->exdv;
        bus[last_row][j].exdrh = dexu->exdh;
        bus[last_row][j].exdrs = dexu->exds; /* exds=3,2,1,0 */
      }
      id[insn[i].iexe.exedh].itype = ITYPE_EX4;
      id[insn[i].iexe.exedh].row   = last_row;
      id[insn[i].iexe.exedh].col   = -1; /* ������ exe->AR[]�ξ��,��column�Ƕ��̤ʤΤǡ�����ʤ� */
      insn[i].iheader.fixed = 1;
      break;
    case ITYPE_EXE: /* EXE */
      /**************************************************/
      /* 1-1                                            */
      /* EXE has imm, var, var[], gpr, bdr[][][] as src */
      /**************************************************/
      switch (insn[i].iexe.op1) {
      case OP_NOP:
        get_valid_row(ITYPE_EXE, 0, insn[i].iexe.src1v, insn[i].iexe.src1h, rdep);
        insn[i].iexe.src2v = T_NONE; /* delete */
        insn[i].iexe.src3v = T_NONE; /* delete */
        break;
      case OP_FAD:    /* 2 */
      case OP_FML:    /* 2 */
      case OP_ADD:    /* 2 */
      case OP_SUB:    /* 2 */
      case OP_CMP_EQ: /* 2 */
      case OP_CMP_NE: /* 2 */
      case OP_CMP_LT: /* 2 */
      case OP_CMP_LE: /* 2 */
      case OP_CMP_GT: /* 2 */
      case OP_CMP_GE: /* 2 */
      case OP_CCAT:   /* 2 */
      case OP_MAUH:   /* 2 */
      case OP_MSUH:   /* 2 */
      case OP_MLUH:   /* 2 */
      case OP_MSAD:   /* 2 */
      case OP_MINL:   /* 2 */
      case OP_MH2BW:  /* 2 */
      case OP_MCAS:   /* 2 */
      case OP_MMAX:   /* 2 */
      case OP_MMIN:   /* 2 */
        get_valid_row(ITYPE_EXE, 0, insn[i].iexe.src1v, insn[i].iexe.src1h, rdep);
        get_valid_row(ITYPE_EXE, 0, insn[i].iexe.src2v, insn[i].iexe.src2h, rdep);
        insn[i].iexe.src3v = T_NONE; /* delete */
        break;
      case OP_FMA:    /* 3 */
      case OP_ADD3:   /* 3 */
      case OP_SUB3:   /* 3 */
      case OP_CMOV:   /* 3 */
      case OP_MAUH3:  /* 3 */
      case OP_MSUH3:  /* 3 */
      case OP_MMRG:   /* 3 */
      case OP_MSSAD:  /* 3 */
      case OP_MINL3:  /* 3 */
      case OP_MMID3:  /* 3 */
      case OP_MMAX3:  /* 3 */
      case OP_MMIN3:  /* 3 */
        get_valid_row(ITYPE_EXE, 0, insn[i].iexe.src1v, insn[i].iexe.src1h, rdep);
        get_valid_row(ITYPE_EXE, 0, insn[i].iexe.src2v, insn[i].iexe.src2h, rdep);
        get_valid_row(ITYPE_EXE, 0, insn[i].iexe.src3v, insn[i].iexe.src3h, rdep);
        break;
      default:
        printf("in %s: exe found illegal op1=%d\n", id[current_prefix].name, insn[i].iexe.op1);
        exit(1);
      }
      switch (insn[i].iexe.op2) {
      case OP_NOP:
        insn[i].iexe.src4v = T_NONE; /* delete */
        break;
      case OP_AND:
      case OP_OR:
      case OP_XOR:
      case OP_SUMHH:
      case OP_SUMHL:
      case OP_WSWAP:
        get_valid_row(ITYPE_EXE, 0, insn[i].iexe.src4v, insn[i].iexe.src4h, rdep);
        break;
      default:
        printf("in %s: exe found illegal op2=%d\n", id[current_prefix].name, insn[i].iexe.op2);
        exit(1);
      }
      switch (insn[i].iexe.op3) {
      case OP_NOP:
        insn[i].iexe.src5v = T_NONE; /* delete */
        break;
      case OP_SLL:
      case OP_SRL:
      case OP_SRAA:
      case OP_SRAB:
      case OP_SRAC:
      case OP_SRAD:
      case OP_SRLM:
        get_valid_row(ITYPE_EXE, 0, insn[i].iexe.src5v, insn[i].iexe.src5h, rdep);
        break;
      default:
        printf("in %s: exe found illegal op3=%d\n", id[current_prefix].name, insn[i].iexe.op3);
        exit(1);
      }
      if (row < 0) { /* none of WHILE/ALR/BDR is specified */
        /* 1-2a *//* Ʊ��row��ʣ��EXE�����֤���뤳�Ȥ����� */
        if (last_row < *rdep) { /* �֤���������ֲ�ǽ */
          last_row = *rdep;
          last_col = 0;
        }
        else { /* last_row >= *rdep *//* �ǽ����֤Ȱ�¸�ط�������֤����� */
          if (dec[last_row][last_col].dexu.op1 || dec[last_row][last_col].dexu.op2 || dec[last_row][last_col].dexu.op3) { /* ��Լ����Ȥζ��縡�� */
            last_col++; /* overflow�Ϥ��ȤǸ���.EXE��WIDTH�ʾ夢��м��ʤذ�ư */
            if (last_col >= EMAX_WIDTH) {
              last_row++;
              last_col = 0;
            }
          }
        }
      }
      else { /* WHILE/ALR/BDR is specified */
        /* 1-2b */
        if (row < *rdep) { /* ����row�ˤ����ֺ��� */
          printf("in %s: exe cannot locate destination ALRNO/BDRNO (row=%d)\n", id[current_prefix].name, row);
          exit(1);
        }
        else if (row < last_row) {
          printf("in %s: exe found violation of sequence (row=%d < last_row=%d)\n", id[current_prefix].name, row, last_row);
          exit(1);
        }
        else {
          last_row = row;
          last_col = col;
        }
      }
      /* 1-3 */
      if (last_row >= EMAX_DEPTH || last_col >= EMAX_WIDTH) { /* copy���˸��� */
        printf("in %s: [%d][%d] exe exceeds EMAX_DEPTH/EMAX_WIDTH\n", id[current_prefix].name, last_row, last_col);
        exit(1);
      }
      if (dec[last_row][last_col].dexu.op1 || dec[last_row][last_col].dexu.op2 || dec[last_row][last_col].dexu.op3) {
        printf("in %s: [%d][%d] exe conflicts\n", id[current_prefix].name, last_row, last_col);
        exit(1);
      }
      /* 1-4 */
      /* check combination of sources */
      /*    src1 src2 src3        src4        src5       */
      /* A: ex1, ex2, ex3 -> EX1, e2i -> EX2, e3i -> EX3 */
      /* B: ex1, ex2      -> EX1, ex3 -> EX2, e3i -> EX3 */
      /* C: ex1, ex2      -> EX1, e2i -> EX2, ex3 -> EX3 */
      /* D: ex1           -> EX1, ex2 -> EX2, e3i -> EX3 */
      /* E: ex1           -> nop, ex2 -> EX2, ex3 -> EX3 */
      /* F: ex1           -> nop, e2i -> EX2, e3i -> EX3 */
      /* G: ex1           -> nop, e2i -> EX2, ex3 -> EX3 */
      dexu = &dec[last_row][last_col].dexu;
      dexu->op1    = insn[i].iexe.op1;
      dexu->op2    = insn[i].iexe.op2;
      dexu->op3    = insn[i].iexe.op3;
      dexu->updt   = insn[i].iexe.updt;
      dexu->ex1v   = insn[i].iexe.src1v; /* default */
      dexu->ex1h   = insn[i].iexe.src1h; /* default */
      dexu->ex1s   = insn[i].iexe.src1s; /* default */
      dexu->ex1e   = insn[i].iexe.src1e; /* default */
      if (insn[i].iexe.src2v) { /* case A,B,C */
        dexu->ex2v   = insn[i].iexe.src2v; /* default */
        dexu->ex2h   = insn[i].iexe.src2h; /* default */
        dexu->ex2s   = insn[i].iexe.src2s; /* default */
        dexu->ex2e   = insn[i].iexe.src2e; /* default */
      }
      if (insn[i].iexe.src3v) { /* case A */
        dexu->ex3v   = insn[i].iexe.src3v; /* default */
        dexu->ex3h   = insn[i].iexe.src3h; /* default */
        dexu->ex3s   = insn[i].iexe.src3s; /* default */
        dexu->ex3e   = insn[i].iexe.src3e; /* default */
      }
      if (insn[i].iexe.src4v==T_IMMEDIATE) { /* case A,C,F,G */
        dexu->e2iv   = insn[i].iexe.src4v; /* default */
        dexu->e2ih   = insn[i].iexe.src4h; /* default */
        dexu->e2is   = 0;                  /* e2imm */
      }
      else if (insn[i].iexe.src4v) { /* case B,D,E */
        if (dexu->ex3v) {
          printf("in %s: insn[%d].iexe has too many T_VARs\n", id[current_prefix].name, i);
          exit(1);
        }
        else if (dexu->ex2v) { /* case B */
          dexu->ex3v   = insn[i].iexe.src4v; /* default */
          dexu->ex3h   = insn[i].iexe.src4h; /* default */
          dexu->ex3s   = insn[i].iexe.src4s; /* default */
          dexu->ex3e   = 0;
          dexu->e2is   = 2;                  /* ex3 */
        }
        else { /* case D,E */
          dexu->ex2v   = insn[i].iexe.src4v; /* default */
          dexu->ex2h   = insn[i].iexe.src4h; /* default */
          dexu->ex2s   = insn[i].iexe.src4s; /* default */
          dexu->ex2e   = 0;
          dexu->e2is   = 1;                  /* ex2 */
        }
      }
      if (insn[i].iexe.src5v==T_IMMEDIATE) { /* case A,B,D,F */
        dexu->e3iv   = insn[i].iexe.src5v; /* default */
        dexu->e3ih   = insn[i].iexe.src5h; /* default */
        dexu->e3is   = 0;                  /* e3imm */
      }
      else if (insn[i].iexe.src5v) { /* case C,E,G */
        if (dexu->ex3v) {
          printf("in %s: insn[%d].iexe has too many T_VARs\n", id[current_prefix].name, i);
          exit(1);
        }
        else { /* case C,E,G */
          dexu->ex3v   = insn[i].iexe.src5v; /* default */
          dexu->ex3h   = insn[i].iexe.src5h; /* default */
          dexu->ex3s   = insn[i].iexe.src5s; /* default */
          dexu->ex3e   = 0;
          dexu->e3is   = 1;                  /* ex3 */
        }
      }
      dexu->exdv   = insn[i].iexe.exedv; /* default */
      dexu->exdh   = insn[i].iexe.exedh; /* default */
      dexu->exds   = insn[i].iexe.exeds; /* default */
      /* 1-5 */
      set_reg_path(last_row, last_col, type, RTYPE_DATA, 0, dexu->ex1v, dexu->ex1h, dexu->ex1s); /* discrete */
      set_reg_path(last_row, last_col, type, RTYPE_DATA, 0, dexu->ex2v, dexu->ex2h, dexu->ex2s); /* discrete */
      set_reg_path(last_row, last_col, type, RTYPE_DATA, 0, dexu->ex3v, dexu->ex3h, dexu->ex3s); /* discrete */
      /* 1-6 *//* ��Ǽ��busmap��EXDR�ߤޤ� */
      bus[last_row][last_col].exdrv = dexu->exdv;
      bus[last_row][last_col].exdrh = dexu->exdh;
      bus[last_row][last_col].exdrs = dexu->exds; /* &VAR�ξ��-1, &VAR[c]�ξ��c, &AR[r][c]�ξ��c */
      id[insn[i].iexe.exedh].itype = ITYPE_EXE;
      id[insn[i].iexe.exedh].row   = last_row;
      id[insn[i].iexe.exedh].col   = dexu->exds<0 /* ������ exe->&VAR�ξ��,last_col�򥻥å� */
                                   ? last_col     /* ������ exe->VAR[c],AR[r][c]��Х�ǻȤ����,col�Ǥ϶����Բ� */
                                   : -1;          /* ������ col���֤ϸ���ʤΤ�-1�ˤ��Ƥ��� */
      insn[i].iheader.fixed = 1;
      break;
    case ITYPE_MO4: /* MO4 */
      /**************************************************/
      /* 1-1                                            */
      /* MO4 has var([]), alr[]([]), bdr[][]([]) as src */
      /*         store    store      load               */
      /**************************************************/
      switch (insn[i].imop.op) {
      case OP_STRQ:  /* random_store on mop0->TR (+implicit mop1->AXI) */
	current_lmmwb = 1; /* mark as dirty L1 shold be flushed+cleared before starting EMAX */
      case OP_TR:    /* transaction on mop0->TR (+implicit mop1->AXI) */
        get_valid_row(ITYPE_MO4, 1, insn[i].imop.mopdv, insn[i].imop.mopdh, rdep);
      case OP_LDRQ:  /* random_load on mop1->BR (+implicit AXI->mop0->TR) */
      case OP_LDDMQ: /* direct_load on mop0->AXI->TR->BR */
        get_valid_row(ITYPE_MO4, 1, insn[i].imop.exv,   insn[i].imop.exh,   rdep);
        get_valid_row(ITYPE_MO4, 0, insn[i].imop.basev, insn[i].imop.baseh, rdep);
        get_valid_row(ITYPE_MO4, 0, insn[i].imop.offsv, insn[i].imop.offsh, rdep);
        break;
      default:
        printf("in %s: insn[%d].imop.op=%d is undefined\n", id[current_prefix].name, i, insn[i].imop.op);
        exit(1);
      }
      if (row < 0) { /* none of WHILE/ALR/BDR is specified */
        /* 1-2a */
        if (last_row < *rdep) { /* �֤���������ֲ�ǽ */
          last_row = *rdep;
          last_col = 0; /* ���ֻ����ǽex4.dst��ALR�Τ�.var��ͳ��Ʊ��row���³st4()�����ֲ�ǽ */
        }
        else { /* last_row >= *rdep *//* �ǽ����֤Ȱ�¸�ط�������֤����� */
          if (dec[last_row][last_col].dmop0.op || dec[last_row][last_col].dmop1.op) { /* ��Լ����Ȥζ��縡�� */
            last_col++; /* overflow�Ϥ��ȤǸ���.MOP4��WIDTH�ʾ夢��м��ʤذ�ư */
            if (last_col >= EMAX_WIDTH) {
              last_row++;
              last_col = 0;
            }
          }
        }
      }
      else { /* WHILE/ALR/BDR is specified */
        /* 1-2b */
        if (row < *rdep) { /* ����row�ˤ����ֺ��� */
          printf("in %s: mo4 cannot locate destination ALRNO/BDRNO (row=%d)\n", id[current_prefix].name, row);
          exit(1);
        }
        else if (row < last_row) {
          printf("in %s: mo4 found violation of sequence (row=%d < last_row=%d)\n", id[current_prefix].name, row, last_row);
          exit(1);
        }
        else {
          last_row = row;
          if (col >= 0) /* AR����ξ��,col=-1�ʤΤ�,col��̵�ѹ� */
            last_col = col;
        }
      }
      /* 1-3 */
      if (last_row >= EMAX_DEPTH || last_col >= EMAX_WIDTH) { /* copy���˸��� */
        printf("in %s: [%d][%d] mo4 exceeds EMAX_DEPTH/EMAX_WIDTH\n", id[current_prefix].name, last_row, last_col);
        exit(1);
      }
      if (dec[last_row][last_col].dmop0.op || dec[last_row][last_col].dmop1.op) {
        printf("in %s: [%d][%d] mo4 conflicts\n", id[current_prefix].name, last_row, last_col);
        exit(1);
      }
      /* 1-4 */
      dmop0 = &dec[last_row][last_col].dmop0;
      dmop1 = &dec[last_row][last_col].dmop1;
      if (insn[i].imop.mtype == MTYPE_RLOAD) /* mop1 */
        *dmop1 = insn[i].imop;
      else /* MTYPE_RSTORE, MTYPE_DLOAD, MTYPE_TRANS */
        *dmop0 = insn[i].imop;
      if (insn[i].imop.mtype == MTYPE_DLOAD) { /* MTYPE_DLOAD�μ絭��ADDR�������� */
        /*-------------����������������-----------------*/
        /* dec[last_row][last_col].dmop0.op = OP_LDDMQ; /* may be redundant */
        /* setup EX1 for ddr-addr */
        dexu = &dec[last_row][last_col].dexu;
        if (dexu->op1 || dexu->op2 || dexu->op3) {
          printf("in %s: [%d][%d] LDDMQ address generation conflicts in EXU\n", id[current_prefix].name, last_row, last_col);
          exit(1);
        }
        dexu->op1    = OP_ADD;
        dexu->op2    = OP_NOP;
        dexu->op3    = OP_NOP;
        dexu->updt   = 0; /* 0:none, 1:self_update */
        dexu->ex1v   = dmop0->basev; /* id.type */
        dexu->ex1h   = dmop0->baseh; /* hash val */
        dexu->ex1s   = dmop0->bases; /* suffix for var[s], bdr[][][s] */
        dexu->ex1e   = EXP_H3210;    /* 0:--, 1:B5410, 2:B7632, 3:H3210 */
        dexu->ex2v   = dmop0->offsv; /* id.type */
        dexu->ex2h   = dmop0->offsh; /* hash val */
        dexu->ex2s   = dmop0->offss; /* suffix for var[s], bdr[][][s] */
        dexu->ex2e   = EXP_H3210;    /* 0:--, 1:B5410, 2:B7632, 3:H3210 */
        dexu->ex3v   = T_NONE;       /* id.type */
        dexu->ex3h   = -1;           /* hash val */
        dexu->ex3s   = -1;           /* suffix for var[s], bdr[][][s] */
        dexu->ex3e   =  0;           /* 0:--, 1:B5410, 2:B7632, 3:H3210 */
        dexu->e2iv   = T_NONE;       /* id.type */
        dexu->e2ih   = -1;           /* hash val */
        dexu->e2is   =  0;           /* selector 0:e2imm, 1:ex2, 2:ex3 */
        dexu->e3iv   = T_NONE;       /* id.type */
        dexu->e3ih   = -1;           /* hash val */
        dexu->e3is   =  0;           /* selector 0:e3imm, 1:ex3 */
        dexu->exdv   = dmop0->basev; /* id.type */
        dexu->exdh   = dmop0->baseh; /* hash val */
        dexu->exds   = dmop0->bases; /* suffix for var[s], bdr[][][s] */
	dmop1->updt  = 1;  /* for internal update of ea1 */
	dmop1->offsm = 15; /* for internal update of ea1 */
      }
      else if (insn[i].imop.mtype == MTYPE_TRANS) { /* MTYPE_TRANS��PARAM*4�������� */
        /*-------------����������������-----------------*/
	dmop1->updt  = 1;  /* for internal update of ea1 */
	dmop1->offsm = 15; /* for internal update of ea1 */
      }
      /* 1-5 */
      if (insn[i].imop.mtype == MTYPE_RLOAD) { /* mop1 */
        /* LD with force-read=0 and ptop==NULL generates current(lmr) and reuse LMM. same as lmr in EMAX4                     curr  1  top  blk  len   0  0  0 */
        /* LD with force-read=1 and ptop==NULL generates current(lmf) and !reuse LMM. same as lmf in EMAX4                    curr  1  top  blk  len   0  1  0 */
        /* LD with force-read=0 and ptop!=NULL generates current(lmr) and next(lmp). mapdist!=0                               curr  1  top  blk  len   0  0  0 */
        /*                                                                                                                  c+dist  1 ptop  blk  len   0  0  1 */
        /* LD with force-read=0 and ptop!=NULL generates current(lmr) and next(lmp). mapdist==0                  ofs=ptop-top curr  1  top  blk  len   0  0  1 */
        /*                                                                                                               p=1�ξ��,pref-addr�Ͼ��lmmi.top+ofs */
        /* LDDMQ set f=1 and p=1 in lmmc automatically                                                                        curr  1  top  -    -     0  1  1 */
        set_reg_path(last_row, last_col, type, RTYPE_BASE, 1, dmop1->basev, dmop1->baseh, dmop1->bases);
        set_reg_path(last_row, last_col, type, RTYPE_OFFS, 1, dmop1->offsv, dmop1->offsh, dmop1->offss);
        if (dmop1->topv  == T_VARIABLE) {
#if 0
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].v     = %d;\n",  id[current_prefix].name, last_col, last_row, 1);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].rw    = %d;\n",  id[current_prefix].name, last_col, last_row,(dmop1->mtype==MTYPE_RLOAD||dmop1->mtype==MTYPE_DLOAD)?0:1);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].f     = %d;\n",  id[current_prefix].name, last_col, last_row, dmop1->force);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].p     = %d;\n",  id[current_prefix].name, last_col, last_row, 0);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].blk   = %d;\n",  id[current_prefix].name, last_col, last_row, dmop1->blk);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].len   = %d;\n",  id[current_prefix].name, last_col, last_row, dmop1->len);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].top   = %s;\n",  id[current_prefix].name, last_col, last_row, id[dmop1->toph].name);
#endif
          lmmi[last_col][last_row].v     = 1;
          lmmi[last_col][last_row].rw    = (dmop1->mtype==MTYPE_RLOAD||dmop1->mtype==MTYPE_DLOAD)?0:1;
          lmmi[last_col][last_row].f     = dmop1->force;
          lmmi[last_col][last_row].p     = 0; /* initial value */
          lmmi[last_col][last_row].blk   = dmop1->blk;
          lmmi[last_col][last_row].len   = id[dmop1->lenh].val-1;
          lmmi[last_col][last_row].ofs   = 0; /* initial value */
          lmmi[last_col][last_row].top   = (Ull)id[dmop1->toph].name;
          lmmx[last_col][last_row].lenv  = dmop1->lenv;
          lmmx[last_col][last_row].lenh  = dmop1->lenh;
        }
        if (dmop1->ptopv == T_VARIABLE) { /* lmp */
          if (last_row+current_mapdist >= EMAX_DEPTH) { /* copy���˸��� */
            printf("in %s: [%d][%d] prefetch exceeds EMAX_DEPTH\n", id[current_prefix].name, last_row, last_col);
            exit(1);
          }
          if (dec[last_row+current_mapdist][last_col].dmop0.op) {
            printf("in %s: [%d][%d] prefetch may conflict with other mop\n", id[current_prefix].name, last_row, last_col);
            exit(1);
          }
#if 0
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].v     = %d;\n",  id[current_prefix].name, last_col, last_row+current_mapdist, 1);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].rw    = %d;\n",  id[current_prefix].name, last_col, last_row+current_mapdist,(dmop1->mtype==MTYPE_RLOAD||dmop1->mtype==MTYPE_DLOAD)?0:1);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].f     = %d;\n",  id[current_prefix].name, last_col, last_row+current_mapdist, 0);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].p     = %d;\n",  id[current_prefix].name, last_col, last_row+current_mapdist, 1);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].blk   = %d;\n",  id[current_prefix].name, last_col, last_row+current_mapdist, dmop1->blk);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].len   = %d;\n",  id[current_prefix].name, last_col, last_row+current_mapdist, dmop1->plen);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].top   = %s;\n",  id[current_prefix].name, last_col, last_row+current_mapdist, id[dmop1->ptoph].name);
#endif
          if (current_mapdist==0) { /* old_LDBFQ */
            if (dmop1->force) { /* reserved for LDDMQ */
              /* f=1����ꤷ�Ƥ�ignored */
            }
            lmmi[last_col][last_row].p   = 1; /* optional prefetch */
            lmmi[last_col][last_row].ofs = (Uint)(id[dmop1->ptoph].name - id[dmop1->toph].name);
          }
          else {
            lmmi[last_col][last_row+current_mapdist].v     = 1;
            lmmi[last_col][last_row+current_mapdist].rw    = (dmop1->mtype==MTYPE_RLOAD||dmop1->mtype==MTYPE_DLOAD)?0:1;
            lmmi[last_col][last_row+current_mapdist].f     = 0;
            lmmi[last_col][last_row+current_mapdist].p     = 1;
            lmmi[last_col][last_row+current_mapdist].blk   = dmop1->blk;
            lmmi[last_col][last_row+current_mapdist].len   = id[dmop1->plenh].val-1;
            lmmi[last_col][last_row+current_mapdist].ofs   = 0;
            lmmi[last_col][last_row+current_mapdist].top   = (Ull)id[dmop1->ptoph].name;
            lmmx[last_col][last_row+current_mapdist].lenv  = dmop1->plenv;
            lmmx[last_col][last_row+current_mapdist].lenh  = dmop1->plenh;
          }
        }
      }
      else { /* MTYPE_RSTORE, MTYPE_DLOAD, MTYPE_TRANS */
        /* ST with force-read=0 and ptop==NULL generates current(lmw) and reuse+wback LMM. same as lmw in EMAX4               curr  1  top  blk  len   1  0  0 */
        /* ST with force-read=1 and ptop==NULL generates current(lmx) and !reuse+wback LMM. same as lmx in EMAX4              curr  1  top  blk  len   1  1  0 */
        /* ST with force-read=0 and ptop!=NULL generates current(lmw) and prev(lmd). mapdist!=0                               curr  1  top  blk  len   1  0  0 */
        /*                                                                                                                  c-dist  1 ptop  blk  len   1  0  1 */
        /* ST with force-read=0 and ptop!=NULL generates current(lmw) and prev(lmd). mapdist==0                  ofs=ptop-top curr  1  top  blk  len   1  0  1 */
        /*                                                                                                              p=1�ξ��,drain-addr�Ͼ��lmmi.top+ofs */
        /* TR    set f=1 and p=1 in lmmc automatically                                                                        curr  1  top  -    -     1  1  1 */
        if (insn[i].imop.mtype == MTYPE_RSTORE) { /* 3,2,1,0 */
          set_reg_path(last_row, last_col, type, RTYPE_BASE, 0, dmop0->basev, dmop0->baseh, dmop0->bases);
          set_reg_path(last_row, last_col, type, RTYPE_OFFS, 0, dmop0->offsv, dmop0->offsh, dmop0->offss);
          for (j=0; j<UNIT_WIDTH; j++)
            set_reg_path(last_row, last_col, type, RTYPE_DATA, 0, dmop0->mopdv, dmop0->mopdh, j);
        }
        else if (insn[i].imop.mtype == MTYPE_DLOAD) {
          set_reg_path(last_row, last_col, 4 /*EXE*/, RTYPE_DATA, 0, dmop0->basev, dmop0->baseh, dmop0->bases);
          set_reg_path(last_row, last_col, 4 /*EXE*/, RTYPE_DATA, 0, dmop0->offsv, dmop0->offsh, dmop0->offss);
        }
        else if (insn[i].imop.mtype == MTYPE_TRANS) { /* 3,2,1,0 */
          for (j=0; j<=last_col; j++) /* OP_TR can accept empty portion */
            set_reg_path(last_row, last_col, type, RTYPE_DATA, 0, dmop0->mopdv, dmop0->mopdh, j);
        }
        if (dmop0->topv  == T_VARIABLE) {
#if 0
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].v     = %d;\n",  id[current_prefix].name, last_col, last_row, 1);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].rw    = %d;\n",  id[current_prefix].name, last_col, last_row,(dmop0->mtype==MTYPE_RLOAD||dmop0->mtype==MTYPE_DLOAD)?0:1);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].f     = %d;\n",  id[current_prefix].name, last_col, last_row, dmop0->force);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].p     = %d;\n",  id[current_prefix].name, last_col, last_row, 0);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].blk   = %d;\n",  id[current_prefix].name, last_col, last_row, dmop0->blk);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].len   = %d;\n",  id[current_prefix].name, last_col, last_row, dmop0->len);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].top   = %s;\n",  id[current_prefix].name, last_col, last_row, id[dmop0->toph].name);
#endif
          lmmi[last_col][last_row].v     = 1;
          lmmi[last_col][last_row].rw    = (dmop0->mtype==MTYPE_RLOAD||dmop0->mtype==MTYPE_DLOAD)?0:1;
          lmmi[last_col][last_row].f     = (dmop0->mtype==MTYPE_DLOAD||dmop0->mtype==MTYPE_TRANS)?1:dmop0->force;
          lmmi[last_col][last_row].p     = (dmop0->mtype==MTYPE_DLOAD||dmop0->mtype==MTYPE_TRANS)?1:0; /* initial value */
          lmmi[last_col][last_row].blk   = dmop0->blk;
          lmmi[last_col][last_row].len   = id[dmop0->lenh].val-1;
          lmmi[last_col][last_row].ofs   = 0; /* initial value */
          lmmi[last_col][last_row].top   = (Ull)id[dmop0->toph].name;
          lmmx[last_col][last_row].lenv  = dmop0->lenv;
          lmmx[last_col][last_row].lenh  = dmop0->lenh;
        }
	else { /* LDDMQ��topv==NULL */
	  if (insn[i].imop.mtype == MTYPE_DLOAD) {
	    lmmi[last_col][last_row].v     = 1;
	    lmmi[last_col][last_row].rw    = 0;
	    lmmi[last_col][last_row].f     = 1;
	    lmmi[last_col][last_row].p     = 1;
	    lmmi[last_col][last_row].blk   = 0;
	    lmmi[last_col][last_row].len   = 0;
	    lmmi[last_col][last_row].ofs   = 0;
	    lmmi[last_col][last_row].top   = (Ull)id[dmop0->toph].name;
	    lmmx[last_col][last_row].lenv  = dmop0->lenv;
	    lmmx[last_col][last_row].lenh  = dmop0->lenh;
	  }
	} 
        if (dmop0->ptopv == T_VARIABLE) { /* lmd */
          if (last_row-current_mapdist < 0) { /* copy���˸��� */
            printf("in %s: [%d][%d] drain exceeds EMAX_DEPTH\n", id[current_prefix].name, last_row, last_col);
            exit(1);
          }
          if (dec[last_row-current_mapdist][last_col].dmop1.op) {
            printf("in %s: [%d][%d] drain may conflict with other mop\n", id[current_prefix].name, last_row, last_col);
            exit(1);
          }
#if 0
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].v     = %d;\n",  id[current_prefix].name, last_col, last_row-current_mapdist, 1);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].rw    = %d;\n",  id[current_prefix].name, last_col, last_row-current_mapdist,(dmop0->mtype==MTYPE_RLOAD||dmop0->mtype==MTYPE_DLOAD)?0:1);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].f     = %d;\n",  id[current_prefix].name, last_col, last_row-current_mapdist, 0);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].p     = %d;\n",  id[current_prefix].name, last_col, last_row-current_mapdist, 1);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].blk   = %d;\n",  id[current_prefix].name, last_col, last_row-current_mapdist, dmop0->blk);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].len   = %d;\n",  id[current_prefix].name, last_col, last_row-current_mapdist, dmop0->plen);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].top   = %s;\n",  id[current_prefix].name, last_col, last_row-current_mapdist, id[dmop0->ptoph].name);
#endif
          if (current_mapdist==0) { /* old_STBFQ */
            if (dmop0->force) { /* reserved for TR */
              /* f=1����ꤷ�Ƥ�ignored */
            }
            lmmi[last_col][last_row].p   = 1; /* optional postdrain */
            lmmi[last_col][last_row].ofs = (Uint)(id[dmop0->ptoph].name - id[dmop0->toph].name);
          }
          else {
            if (lmmi[last_col][last_row-current_mapdist].v) {
              printf("in %s: [%d][%d] drain may conflict with other lmm\n", id[current_prefix].name, last_row, last_col);
              exit(1);
            }
            lmmi[last_col][last_row-current_mapdist].v     = 1;
            lmmi[last_col][last_row-current_mapdist].rw    = (dmop0->mtype==MTYPE_RLOAD||dmop0->mtype==MTYPE_DLOAD)?0:1;
            lmmi[last_col][last_row-current_mapdist].f     = 0;
            lmmi[last_col][last_row-current_mapdist].p     = 1;
            lmmi[last_col][last_row-current_mapdist].blk   = dmop0->blk;
            lmmi[last_col][last_row-current_mapdist].len   = id[dmop0->plenh].val-1;
            lmmi[last_col][last_row-current_mapdist].ofs   = 0;
            lmmi[last_col][last_row-current_mapdist].top   = (Ull)id[dmop0->ptoph].name;
            lmmx[last_col][last_row-current_mapdist].lenv  = dmop0->plenv;
            lmmx[last_col][last_row-current_mapdist].lenh  = dmop0->plenh;
          }
        }
      }
      /* 1-6 *//* RLOAD,DLOAD:��Ǽ��busmap��BR�ߤޤ� RSTORE,TRANS: ��Ǽ��busmap��MW�ߤޤ� */
      if (insn[i].imop.mtype == MTYPE_RLOAD) {
        if (dmop1->topv  == T_VARIABLE) {
          for (j=0; j<UNIT_WIDTH; j++) {
            bus[last_row][last_col].lmwd[j].v = dmop1->topv;
            bus[last_row][last_col].lmwd[j].h = dmop1->toph;
            bus[last_row][last_col].lmwd[j].s = j;
            /* mw�ϼ¹Ի������ͥ��(STATUS_LOAD���¹Ի������̵��) */
          }
        }
        if (dmop1->ptopv == T_VARIABLE) { /* lmp */
          dec[last_row+current_mapdist][last_col].dmop0.op = OP_IM_PREF; /* mapdist=0�ޤ� */
          for (j=0; j<UNIT_WIDTH; j++) {
            bus[last_row+current_mapdist][last_col].lmwd[j].v = dmop1->ptopv;
            bus[last_row+current_mapdist][last_col].lmwd[j].h = dmop1->ptoph;
            bus[last_row+current_mapdist][last_col].lmwd[j].s = j;
            bus[last_row+current_mapdist][last_col].mw[j].v = dmop1->ptopv;
            bus[last_row+current_mapdist][last_col].mw[j].h = dmop1->ptoph;
            bus[last_row+current_mapdist][last_col].mw[j].s = j;
          }
#if 0
          bus[last_row+current_mapdist][last_col].ea0brv = T_IMMEDIATE; /* prefetch offset=32 �̾�lmmi�Ȥζ��縡���Τ�����ͽ�� */
          bus[last_row+current_mapdist][last_col].ea0brh = -1;
          bus[last_row+current_mapdist][last_col].ea0orv = T_IMMEDIATE; /* prefetch offset=32 �̾�lmmi�Ȥζ��縡���Τ�����ͽ�� */
          bus[last_row+current_mapdist][last_col].ea0orh = -1;
          fprintf(ofile, "\temax5_regv_%s->regv[%d][%d].ea0or = %d;\n",  id[current_prefix].name, last_col, last_row+current_mapdist, 32);
#endif
        }
        for (j=0; j<UNIT_WIDTH; j++) {
          bus[last_row][last_col].br[j].v = dmop1->mopdv;
          bus[last_row][last_col].br[j].h = dmop1->mopdh;
          bus[last_row][last_col].br[j].s = j;
        }
        conf[last_col][last_row].cdw2.brs0 = 1; /* 1:mr10 */
        conf[last_col][last_row].cdw2.brs1 = 1; /* 1:mr11 */
        conf[last_col][last_row].cdw2.brs2 = 1; /* 1:mr12 */
        conf[last_col][last_row].cdw2.brs3 = 1; /* 1:mr13 */
        id[insn[i].imop.mopdh].itype = ITYPE_MO4;
        id[insn[i].imop.mopdh].row   = last_row;
        id[insn[i].imop.mopdh].col   = last_col;
      }
      else if (insn[i].imop.mtype == MTYPE_DLOAD) { /* MTYPE_DLOAD�μ絭��ADDR�������� */
        /*-------------����������������-----------------*/
        bus[last_row][last_col].exdrv = dexu->exdv;
        bus[last_row][last_col].exdrh = dexu->exdh;
        bus[last_row][last_col].exdrs = dexu->exds; /* &VAR�ξ��-1, &VAR[c]�ξ��c, &AR[r][c]�ξ��c */
        /* setup LMM as FIFO */
        bus[last_row][last_col].ea0brv = T_IMMEDIATE; /* drain offset=32 �̾�lmmi�Ȥζ��縡���Τ�����ͽ�� */
        bus[last_row][last_col].ea0brh = -1;
        bus[last_row][last_col].ea0orv = T_IMMEDIATE; /* drain offset=32 �̾�lmmi�Ȥζ��縡���Τ�����ͽ�� */
        bus[last_row][last_col].ea0orh = -1;
        bus[last_row][last_col].ea1brv = T_IMMEDIATE; /* drain offset=32 �̾�lmmi�Ȥζ��縡���Τ�����ͽ�� */
        bus[last_row][last_col].ea1brh = -1;
        bus[last_row][last_col].ea1orv = T_IMMEDIATE; /* drain offset=32 �̾�lmmi�Ȥζ��縡���Τ�����ͽ�� */
        bus[last_row][last_col].ea1orh = -1;
        fprintf(ofile, "\temax5_regv_%s->regv[%d][%d].ea0br = %dLL; /* prev_ea0br->ex1 */\n", id[current_prefix].name, last_col, last_row, 0);
        fprintf(ofile, "\temax5_regv_%s->regv[%d][%d].ea0or = %dLL; /* prev_ea0or->ex2 */\n", id[current_prefix].name, last_col, last_row, 32);
        fprintf(ofile, "\temax5_regv_%s->regv[%d][%d].ea1br = %dLL; /* prev_ea0br->ex1 */\n", id[current_prefix].name, last_col, last_row, 0);
        fprintf(ofile, "\temax5_regv_%s->regv[%d][%d].ea1or = %dLL; /* prev_ea0or->ex2 */\n", id[current_prefix].name, last_col, last_row, 32);
        bus[last_row][last_col].mw[0].v = dmop0->basev;
        bus[last_row][last_col].mw[0].h = dmop0->baseh;
        bus[last_row][last_col].mw[0].s = dmop0->bases;
        bus[last_row][last_col].lmrd[0].v = dmop0->basev; /* for DLOAD-addr */
        bus[last_row][last_col].lmrd[0].h = dmop0->baseh; /* for DLOAD-addr */
        bus[last_row][last_col].lmrd[0].s = dmop0->bases; /* for DLOAD-addr */
        for (j=0; j<UNIT_WIDTH; j++) {
          bus[last_row][last_col].lmwd[j].v = dmop0->mopdv;
          bus[last_row][last_col].lmwd[j].h = dmop0->mopdh;
          bus[last_row][last_col].lmwd[j].s = j;
          bus[last_row][last_col].tr[j].v   = dmop0->mopdv;
          bus[last_row][last_col].tr[j].h   = dmop0->mopdh;
          bus[last_row][last_col].tr[j].s   = j;
          bus[last_row][last_col].br[j].v   = dmop0->mopdv;
          bus[last_row][last_col].br[j].h   = dmop0->mopdh;
          bus[last_row][last_col].br[j].s   = j;
        }
        conf[last_col][last_row].cdw2.brs0 = 2; /* 2:tr0 */
        conf[last_col][last_row].cdw2.brs1 = 2; /* 2:tr1 */
        conf[last_col][last_row].cdw2.brs2 = 2; /* 2:tr2 */
        conf[last_col][last_row].cdw2.brs3 = 2; /* 2:tr3 */
        id[insn[i].imop.mopdh].itype = ITYPE_MO4;
        id[insn[i].imop.mopdh].row   = last_row;
        id[insn[i].imop.mopdh].col   = last_col;
      }
      else if (insn[i].imop.mtype == MTYPE_TRANS) { /* MTYPE_TRANS��PARAM*4�������� */
        /*-------------����������������-----------------*/
        /* dec[last_row][last_col].dmop0.op = OP_TR; /* may be redundant */
        /* setup LMM as FIFO */
        bus[last_row][last_col].ea0brv = T_IMMEDIATE; /* drain offset=32 �̾�lmmi�Ȥζ��縡���Τ�����ͽ�� */
        bus[last_row][last_col].ea0brh = -1;
        bus[last_row][last_col].ea0orv = T_IMMEDIATE; /* drain offset=32 �̾�lmmi�Ȥζ��縡���Τ�����ͽ�� */
        bus[last_row][last_col].ea0orh = -1;
        bus[last_row][last_col].ea1brv = T_IMMEDIATE; /* drain offset=32 �̾�lmmi�Ȥζ��縡���Τ�����ͽ�� */
        bus[last_row][last_col].ea1brh = -1;
        bus[last_row][last_col].ea1orv = T_IMMEDIATE; /* drain offset=32 �̾�lmmi�Ȥζ��縡���Τ�����ͽ�� */
        bus[last_row][last_col].ea1orh = -1;
        fprintf(ofile, "\temax5_regv_%s->regv[%d][%d].ea0br = %dLL;\n", id[current_prefix].name, last_col, last_row, 0);
        fprintf(ofile, "\temax5_regv_%s->regv[%d][%d].ea0or = %dLL;\n", id[current_prefix].name, last_col, last_row, 32);
        fprintf(ofile, "\temax5_regv_%s->regv[%d][%d].ea1br = %dLL;\n", id[current_prefix].name, last_col, last_row, 0);
        fprintf(ofile, "\temax5_regv_%s->regv[%d][%d].ea1or = %dLL;\n", id[current_prefix].name, last_col, last_row, 32);
        for (j=0; j<=last_col; j++) { /* OP_TR can accept empty portion */
          bus[last_row][last_col].mw[j].v = dmop0->mopdv;
          bus[last_row][last_col].mw[j].h = dmop0->mopdh;
          bus[last_row][last_col].mw[j].s = j;
          bus[last_row][last_col].lmrd[j].v = dmop0->mopdv;
          bus[last_row][last_col].lmrd[j].h = dmop0->mopdh;
          bus[last_row][last_col].lmrd[j].s = j;
        }
      }
      else { /* MTYPE_RSTORE */
        if (dmop0->ptopv == T_VARIABLE) { /* lmd */
          dec[last_row-current_mapdist][last_col].dmop1.op = OP_IM_DRAIN; /* mapdist=0�ޤ� */
          for (j=0; j<UNIT_WIDTH; j++) {
            bus[last_row-current_mapdist][last_col].lmrd[j].v = dmop0->ptopv;
            bus[last_row-current_mapdist][last_col].lmrd[j].h = dmop0->ptoph;
            bus[last_row-current_mapdist][last_col].lmrd[j].s = j;
          }
#if 0
          bus[last_row-current_mapdist][last_col].ea1brv = T_IMMEDIATE; /* drain offset=32 �̾�lmmi�Ȥζ��縡�� */
          bus[last_row-current_mapdist][last_col].ea1brh = -1;
          bus[last_row-current_mapdist][last_col].ea1orv = T_IMMEDIATE; /* drain offset=32 �̾�lmmi�Ȥζ��縡�� */
          bus[last_row-current_mapdist][last_col].ea1orh = -1;
          fprintf(ofile, "\temax5_regv_%s->regv[%d][%d].ea1or = %d;\n", id[current_prefix].name, last_col, last_row-current_mapdist, 32);
#endif
        }
        for (j=0; j<UNIT_WIDTH; j++) {
          bus[last_row][last_col].mw[j].v = dmop0->mopdv;
          bus[last_row][last_col].mw[j].h = dmop0->mopdh;
          bus[last_row][last_col].mw[j].s = j;
        }
      }
      insn[i].iheader.fixed = 1;
      break;
    case ITYPE_MOP: /* MOP */
      /***************************************************************/
      /* 1-1                                                         */
      /* MOP has &var,   &var[], &gpr,   &alr[][], &bdr[][][] as src */
      /*         store1, store1, store1, store1,   load1             */
      /***************************************************************/
      switch (insn[i].imop.op) {
      case OP_STR:  /* 64bit */
      case OP_STWR: /* 32bit */
      case OP_STHR: /* 16bit */
      case OP_STBR: /*  8bit */
	current_lmmwb = 1; /* mark as dirty L1 shold be flushed+cleared before starting EMAX */
        get_valid_row(ITYPE_MOP, 1, insn[i].imop.mopdv, insn[i].imop.mopdh, rdep);
      case OP_LDR:  /* 64bit */
      case OP_LDWR: /* 32bit signed */
      case OP_LDUWR:/* 32bit unsigned */
      case OP_LDHR: /* 16bit signed */
      case OP_LDUHR:/* 16bit unsigned */
      case OP_LDBR: /*  8bit signed */
      case OP_LDUBR:/*  8bit unsigned */
        get_valid_row(ITYPE_MOP, 1, insn[i].imop.exv,   insn[i].imop.exh,   rdep);
        get_valid_row(ITYPE_MOP, 0, insn[i].imop.basev, insn[i].imop.baseh, rdep);
        get_valid_row(ITYPE_MOP, 0, insn[i].imop.offsv, insn[i].imop.offsh, rdep);
        break;
      default:
        printf("in %s: mop found illegal op=%d\n", id[current_prefix].name, insn[i].imop.op);
        exit(1);
      }
      if (insn[i].imop.mtype == MTYPE_RLOAD)
        last_mop = 1;
      else /* MTYPE_RSTORE, MTYPE_DLOAD, MTYPE_TRANS */
        last_mop = 0;
      if (row < 0) { /* none of WHILE/ALR/BDR is specified */
        /* 1-2a */
        if (last_row < *rdep) { /* �֤���������ֲ�ǽ */
          last_row = *rdep;
          last_col = 0; /* ���ֻ����ǽex4.dst��ALR�Τ�.var��ͳ��Ʊ��row���³st4()�����ֲ�ǽ */
        }
        else { /* last_row >= *rdep *//* �ǽ����֤Ȱ�¸�ط�������֤����� */
          int op0 = dec[last_row][last_col].dmop0.op;
          int op1 = dec[last_row][last_col].dmop1.op;
          int typ = dec[last_row][last_col].dmop1.mtype;
          int tpv = dec[last_row][last_col].dmop1.topv;
          int tph = dec[last_row][last_col].dmop1.toph;
          int lev = dec[last_row][last_col].dmop1.lenv;
          int leh = dec[last_row][last_col].dmop1.lenh;
          int blk = dec[last_row][last_col].dmop1.blk;
          int fce = dec[last_row][last_col].dmop1.force;
          int ldx2_and_op0_is_empty = (op1 && !op0) && (typ == MTYPE_RLOAD)
                                   && (typ == insn[i].imop.mtype)
                                   && (tpv == insn[i].imop.topv)
                                   && (tph == insn[i].imop.toph)
                                   && (lev == insn[i].imop.lenv)
                                   && (leh == insn[i].imop.lenh)
                                   && (blk == insn[i].imop.blk)
                                   && (fce == insn[i].imop.force);
          if (ldx2_and_op0_is_empty)
            last_mop = 0; /* secoundary load */
          else if (op0 || op1) { /* mop0(l/s)=full */
            /* new_load,new_store�ϼ�col�� */
            last_col++; /* overflow�Ϥ��ȤǸ���.EXE��WIDTH�ʾ夢��м��ʤذ�ư */
            if (last_col >= EMAX_WIDTH) {
              last_row++;
              last_col = 0;
            }
          }
        }
      }
      else { /* WHILE/ALR/BDR is specified */
        /* 1-2b */
        if (row < *rdep) { /* ����row�ˤ����ֺ��� */
          printf("in %s: mop cannot locate destination ALRNO/BDRNO (row=%d)\n", id[current_prefix].name, row);
          exit(1);
        }
        else if (row < last_row) {
          printf("in %s: mop found violation of sequence (row=%d < last_row=%d)\n", id[current_prefix].name, row, last_row);
          exit(1);
        }
        else {
          last_row = row;
          last_col = col;
          int op0 = dec[last_row][last_col].dmop0.op;
          int op1 = dec[last_row][last_col].dmop1.op;
          int typ = dec[last_row][last_col].dmop1.mtype;
          int tpv = dec[last_row][last_col].dmop1.topv;
          int tph = dec[last_row][last_col].dmop1.toph;
          int lev = dec[last_row][last_col].dmop1.lenv;
          int leh = dec[last_row][last_col].dmop1.lenh;
          int blk = dec[last_row][last_col].dmop1.blk;
          int fce = dec[last_row][last_col].dmop1.force;
          int ldx2_and_op0_is_empty = (op1 && !op0) && (typ == MTYPE_RLOAD)
                                   && (typ == insn[i].imop.mtype)
                                   && (tpv == insn[i].imop.topv)
                                   && (tph == insn[i].imop.toph)
                                   && (lev == insn[i].imop.lenv)
                                   && (leh == insn[i].imop.lenh)
                                   && (blk == insn[i].imop.blk)
                                   && (fce == insn[i].imop.force);
          if (ldx2_and_op0_is_empty)
            last_mop = 0; /* load */
        }
      }
      /* 1-3 */
      if (last_row >= EMAX_DEPTH || last_col >= EMAX_WIDTH) { /* copy���˸��� */
        printf("in %s: [%d][%d] mop exceeds EMAX_DEPTH/EMAX_WIDTH\n", id[current_prefix].name, last_row, last_col);
        exit(1);
      }
      if (last_mop==0 && dec[last_row][last_col].dmop0.op) {
        printf("in %s: [%d][%d] mop conflicts\n", id[current_prefix].name, last_row, last_col);
        exit(1);
      }
      if (last_mop==1 && dec[last_row][last_col].dmop1.op) {
        printf("in %s: [%d][%d] mop conflicts\n", id[current_prefix].name, last_row, last_col);
        exit(1);
      }
      /* 1-4 */
      dmop0 = &dec[last_row][last_col].dmop0;
      dmop1 = &dec[last_row][last_col].dmop1;
      if (last_mop==1) /* load */
        *dmop1 = insn[i].imop;
      else /* store/load */
        *dmop0 = insn[i].imop;
      /* 1-5 */
      if (last_mop==1) { /* load */
        /* LD with force-read=0 and ptop==NULL generates current(lmr) and reuse LMM. same as lmr in EMAX4                     curr  1  top  blk  len   0  0  0 */
        /* LD with force-read=1 and ptop==NULL generates current(lmf) and !reuse LMM. same as lmf in EMAX4                    curr  1  top  blk  len   0  1  0 */
        /* LD with force-read=0 and ptop!=NULL generates current(lmr) and next(lmp). mapdist!=0                               curr  1  top  blk  len   0  0  0 */
        /*                                                                                                                  c+dist  1 ptop  blk  len   0  0  1 */
        /* LD with force-read=0 and ptop!=NULL generates current(lmr) and next(lmp). mapdist==0                  ofs=ptop-top curr  1  top  blk  len   0  0  1 */
        /*                                                                                                               p=1�ξ��,pref-addr�Ͼ��lmmi.top+ofs */
        /* LDDMQ set f=1 and p=1 in lmmc automatically                                                                        curr  1  top  -    -     0  1  1 */
        set_reg_path(last_row, last_col, type, RTYPE_BASE, 1, dmop1->basev, dmop1->baseh, dmop1->bases);
        set_reg_path(last_row, last_col, type, RTYPE_OFFS, 1, dmop1->offsv, dmop1->offsh, dmop1->offss);
        if (dmop1->topv  == T_VARIABLE) {
#if 0
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].v     = %d;\n",  id[current_prefix].name, last_col, last_row, 1);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].rw    = %d;\n",  id[current_prefix].name, last_col, last_row,(dmop1->mtype==MTYPE_RLOAD||dmop1->mtype==MTYPE_DLOAD)?0:1);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].f     = %d;\n",  id[current_prefix].name, last_col, last_row, dmop1->force);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].p     = %d;\n",  id[current_prefix].name, last_col, last_row, 0);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].blk   = %d;\n",  id[current_prefix].name, last_col, last_row, dmop1->blk);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].len   = %d;\n",  id[current_prefix].name, last_col, last_row, dmop1->len);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].top   = %s;\n",  id[current_prefix].name, last_col, last_row, id[dmop1->toph].name);
#endif
          lmmi[last_col][last_row].v     = 1;
          lmmi[last_col][last_row].rw    = (dmop1->mtype==MTYPE_RLOAD||dmop1->mtype==MTYPE_DLOAD)?0:1;
          lmmi[last_col][last_row].f     = dmop1->force;
          lmmi[last_col][last_row].p     = 0; /* initial value */
          lmmi[last_col][last_row].blk   = dmop1->blk;
          lmmi[last_col][last_row].len   = id[dmop1->lenh].val-1;
          lmmi[last_col][last_row].ofs   = 0; /* initial value */
          lmmi[last_col][last_row].top   = (Ull)id[dmop1->toph].name;
          lmmx[last_col][last_row].lenv  = dmop1->lenv;
          lmmx[last_col][last_row].lenh  = dmop1->lenh;
        }
        if (dmop1->ptopv == T_VARIABLE) { /* lmp */
          if (last_row+current_mapdist >= EMAX_DEPTH) { /* copy���˸��� */
            printf("in %s: [%d][%d] prefetch exceeds EMAX_DEPTH\n", id[current_prefix].name, last_row, last_col);
            exit(1);
          }
          if (dec[last_row+current_mapdist][last_col].dmop0.op) {
            printf("in %s: [%d][%d] prefetch may conflict with other mop\n", id[current_prefix].name, last_row, last_col);
            exit(1);
          }
#if 0
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].v     = %d;\n",  id[current_prefix].name, last_col, last_row+current_mapdist, 1);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].rw    = %d;\n",  id[current_prefix].name, last_col, last_row+current_mapdist,(dmop1->mtype==MTYPE_RLOAD||dmop1->mtype==MTYPE_DLOAD)?0:1);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].f     = %d;\n",  id[current_prefix].name, last_col, last_row+current_mapdist, 0);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].p     = %d;\n",  id[current_prefix].name, last_col, last_row+current_mapdist, 1);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].blk   = %d;\n",  id[current_prefix].name, last_col, last_row+current_mapdist, dmop1->blk);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].len   = %d;\n",  id[current_prefix].name, last_col, last_row+current_mapdist, dmop1->plen);
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].top   = %s;\n",  id[current_prefix].name, last_col, last_row+current_mapdist, id[dmop1->ptoph].name);
#endif
          if (current_mapdist==0) { /* old_LDBF */
            if (dmop1->force) { /* reserved for LDDMQ */
              /* f=1����ꤷ�Ƥ�ignored */
            }
            lmmi[last_col][last_row].p   = 1; /* optional prefetch */
            lmmi[last_col][last_row].ofs = (Uint)(id[dmop1->ptoph].name - id[dmop1->toph].name);
          }
          else {
            lmmi[last_col][last_row+current_mapdist].v     = 1;
            lmmi[last_col][last_row+current_mapdist].rw    = (dmop1->mtype==MTYPE_RLOAD||dmop1->mtype==MTYPE_DLOAD)?0:1;
            lmmi[last_col][last_row+current_mapdist].f     = 0;
            lmmi[last_col][last_row+current_mapdist].p     = 1;
            lmmi[last_col][last_row+current_mapdist].blk   = dmop1->blk;
            lmmi[last_col][last_row+current_mapdist].len   = id[dmop1->plenh].val-1;
            lmmi[last_col][last_row+current_mapdist].ofs   = 0;
            lmmi[last_col][last_row+current_mapdist].top   = (Ull)id[dmop1->ptoph].name;
            lmmx[last_col][last_row+current_mapdist].lenv  = dmop1->plenv;
            lmmx[last_col][last_row+current_mapdist].lenh  = dmop1->plenh;
          }
        }
      }
      else { /* store/load */
        /* ST with force-read=0 and ptop==NULL generates current(lmw) and reuse+wback LMM. same as lmw in EMAX4               curr  1  top  blk  len   1  0  0 */
        /* ST with force-read=1 and ptop==NULL generates current(lmx) and !reuse+wback LMM. same as lmx in EMAX4              curr  1  top  blk  len   1  1  0 */
        /* ST with force-read=0 and ptop!=NULL generates current(lmw) and prev(lmd). mapdist!=0                               curr  1  top  blk  len   1  0  0 */
        /*                                                                                                                  c-dist  1 ptop  blk  len   1  0  1 */
        /* ST with force-read=0 and ptop!=NULL generates current(lmw) and prev(lmd). mapdist==0                  ofs=ptop-top curr  1  top  blk  len   1  0  1 */
        /*                                                                                                              p=1�ξ��,drain-addr�Ͼ��lmmi.top+ofs */
        /* TR    set f=1 and p=1 in lmmc automatically                                                                        curr  1  top  -    -     1  1  1 */
        if (insn[i].imop.mtype == MTYPE_RSTORE)
          set_reg_path(last_row, last_col, type, RTYPE_DATA, 0, dmop0->mopdv, dmop0->mopdh, dmop0->mopds);
        set_reg_path(last_row, last_col, type, RTYPE_BASE, 0, dmop0->basev, dmop0->baseh, dmop0->bases);
        set_reg_path(last_row, last_col, type, RTYPE_OFFS, 0, dmop0->offsv, dmop0->offsh, dmop0->offss);
        if (dmop0->topv  == T_VARIABLE) {
          if (insn[i].imop.mtype == MTYPE_RLOAD) {
            /* if ldx2_and_op0_is_empty==true, dmop0 can share lmmi with dmop1 */
          }
          else {
#if 0
            fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].v     = %d;\n",  id[current_prefix].name, last_col, last_row, 1);
            fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].rw    = %d;\n",  id[current_prefix].name, last_col, last_row,(dmop0->mtype==MTYPE_RLOAD||dmop0->mtype==MTYPE_DLOAD)?0:1);
            fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].f     = %d;\n",  id[current_prefix].name, last_col, last_row, dmop0->force);
            fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].p     = %d;\n",  id[current_prefix].name, last_col, last_row, 0);
            fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].blk   = %d;\n",  id[current_prefix].name, last_col, last_row, dmop0->blk);
            fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].len   = %d;\n",  id[current_prefix].name, last_col, last_row, dmop0->len);
            fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].top   = %s;\n",  id[current_prefix].name, last_col, last_row, id[dmop0->toph].name);
#endif
            lmmi[last_col][last_row].v     = 1;
            lmmi[last_col][last_row].rw    = (dmop0->mtype==MTYPE_RLOAD||dmop0->mtype==MTYPE_DLOAD)?0:1;
            lmmi[last_col][last_row].f     = dmop0->force;
            lmmi[last_col][last_row].p     = 0; /* initial value */
            lmmi[last_col][last_row].blk   = dmop0->blk;
            lmmi[last_col][last_row].len   = id[dmop0->lenh].val-1;
            lmmi[last_col][last_row].ofs   = 0; /* initial value */
            lmmi[last_col][last_row].top   = (Ull)id[dmop0->toph].name;
            lmmx[last_col][last_row].lenv  = dmop0->lenv;
            lmmx[last_col][last_row].lenh  = dmop0->lenh;
          }
        }
        if (dmop0->ptopv == T_VARIABLE) { /* lmd */
          if (insn[i].imop.mtype == MTYPE_RLOAD) {
            /* if ldx2_and_op0_is_empty==true, dmop0 can share lmmi with dmop1 */
          }
          else { /* MTYPE_RSTORE */
            if (last_row-current_mapdist < 0) { /* copy���˸��� */
              printf("in %s: [%d][%d] drain exceeds EMAX_DEPTH\n", id[current_prefix].name, last_row, last_col);
              exit(1);
            }
            if (dec[last_row-current_mapdist][last_col].dmop1.op) {
              printf("in %s: [%d][%d] drain may conflict with other mop\n", id[current_prefix].name, last_row, last_col);
              exit(1);
            }
#if 0
            fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].v     = %d;\n",  id[current_prefix].name, last_col, last_row-current_mapdist, 1);
            fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].rw    = %d;\n",  id[current_prefix].name, last_col, last_row-current_mapdist,(dmop0->mtype==MTYPE_RLOAD||dmop0->mtype==MTYPE_DLOAD)?0:1);
            fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].f     = %d;\n",  id[current_prefix].name, last_col, last_row-current_mapdist, 0);
            fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].p     = %d;\n",  id[current_prefix].name, last_col, last_row-current_mapdist, 1);
            fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].blk   = %d;\n",  id[current_prefix].name, last_col, last_row-current_mapdist, dmop0->blk);
            fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].len   = %d;\n",  id[current_prefix].name, last_col, last_row-current_mapdist, dmop0->plen);
            fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].top   = %s;\n",  id[current_prefix].name, last_col, last_row-current_mapdist, id[dmop0->ptoph].name);
#endif
            if (current_mapdist==0) { /* old_STBF */
              if (dmop0->force) { /* reserved for TR */
                /* f=1����ꤷ�Ƥ�ignored */
              }
              lmmi[last_col][last_row].p   = 1; /* optional postdrain */
              lmmi[last_col][last_row].ofs = (Uint)(id[dmop0->ptoph].name - id[dmop0->toph].name);
            }
            else {
              if (lmmi[last_col][last_row-current_mapdist].v) {
                printf("in %s: [%d][%d] drain may conflict with other lmm\n", id[current_prefix].name, last_row, last_col);
                exit(1);
              }
              lmmi[last_col][last_row-current_mapdist].v     = 1;
              lmmi[last_col][last_row-current_mapdist].rw    = (dmop0->mtype==MTYPE_RLOAD||dmop0->mtype==MTYPE_DLOAD)?0:1;
              lmmi[last_col][last_row-current_mapdist].f     = 0;
              lmmi[last_col][last_row-current_mapdist].p     = 1;
              lmmi[last_col][last_row-current_mapdist].blk   = dmop0->blk;
              lmmi[last_col][last_row-current_mapdist].len   = id[dmop0->plenh].val-1;
              lmmi[last_col][last_row-current_mapdist].ofs   = 0;
              lmmi[last_col][last_row-current_mapdist].top   = (Ull)id[dmop0->ptoph].name;
              lmmx[last_col][last_row-current_mapdist].lenv  = dmop0->plenv;
              lmmx[last_col][last_row-current_mapdist].lenh  = dmop0->plenh;
            }
          }
        }
      }
      /* 1-6 *//* RLOAD,DLOAD:��Ǽ��busmap��BR�ߤޤ� RSTORE,TRANS: ��Ǽ��busmap��TR�ߤޤ� */
      if (insn[i].imop.mtype == MTYPE_RLOAD) {
        if (last_mop==1) { /* load */
          if (dmop1->topv  == T_VARIABLE) {
            for (j=0; j<UNIT_WIDTH; j++) {
              bus[last_row][last_col].lmwd[j].v = dmop1->topv;
              bus[last_row][last_col].lmwd[j].h = dmop1->toph;
              bus[last_row][last_col].lmwd[j].s = j;
              /* mw�ϼ¹Ի������ͥ��(STATUS_LOAD���¹Ի������̵��) */
            }
          }
          if (dmop1->ptopv == T_VARIABLE) { /* lmp */
            dec[last_row+current_mapdist][last_col].dmop0.op = OP_IM_PREF; /* mapdist=0�ޤ� */
            for (j=0; j<UNIT_WIDTH; j++) {
              bus[last_row+current_mapdist][last_col].lmwd[j].v = dmop1->ptopv;
              bus[last_row+current_mapdist][last_col].lmwd[j].h = dmop1->ptoph;
              bus[last_row+current_mapdist][last_col].lmwd[j].s = j;
              bus[last_row+current_mapdist][last_col].mw[j].v   = dmop1->ptopv;
              bus[last_row+current_mapdist][last_col].mw[j].h   = dmop1->ptoph;
              bus[last_row+current_mapdist][last_col].mw[j].s   = j;
            }
#if 0
            bus[last_row+current_mapdist][last_col].ea0brv = T_IMMEDIATE; /* prefetch offset=32 �̾�lmmi�Ȥζ��縡���Τ�����ͽ�� */
            bus[last_row+current_mapdist][last_col].ea0brh = -1;
            bus[last_row+current_mapdist][last_col].ea0orv = T_IMMEDIATE; /* prefetch offset=32 �̾�lmmi�Ȥζ��縡���Τ�����ͽ�� */
            bus[last_row+current_mapdist][last_col].ea0orh = -1;
            fprintf(ofile, "\temax5_regv_%s->regv[%d][%d].ea0or = %d;\n",  id[current_prefix].name, last_col, last_row+current_mapdist, 32);
#endif
          }
          if (dmop1->mopds == 0) {
            printf("in %s: [%d][%d] mop1 cannot connect to %s[%d]\n", id[current_prefix].name, last_row, last_col, id[dmop1->mopdh].name,dmop1->mopds);
            exit(1);
          }
          bus[last_row][last_col].br[1].v = dmop1->mopdv;
          bus[last_row][last_col].br[1].h = dmop1->mopdh;
          bus[last_row][last_col].br[1].s = dmop1->mopds;
          conf[last_col][last_row].cdw2.brs1 = 3; /* 3:mr1 */
        }
        else { /* store/load */
          if (dmop0->mopds == 1) {
            printf("in %s: [%d][%d] mop0 cannot connect to %s[%d]\n", id[current_prefix].name, last_row, last_col, id[dmop1->mopdh].name,dmop1->mopds);
            exit(1);
          }
          bus[last_row][last_col].br[0].v = dmop0->mopdv;
          bus[last_row][last_col].br[0].h = dmop0->mopdh;
          bus[last_row][last_col].br[0].s = dmop0->mopds;
          conf[last_col][last_row].cdw2.brs0 = 3; /* 3:mr0 */
        }
        id[insn[i].imop.mopdh].itype = ITYPE_MOP;
        id[insn[i].imop.mopdh].row   = last_row;
        id[insn[i].imop.mopdh].col   = last_col;
      }
      else { /* MTYPE_RSTORE */
        if (dmop0->ptopv == T_VARIABLE) { /* lmd */
          dec[last_row-current_mapdist][last_col].dmop1.op = OP_IM_DRAIN; /* mapdist=0�ޤ� */
          for (j=0; j<UNIT_WIDTH; j++) {
            bus[last_row-current_mapdist][last_col].lmrd[j].v = dmop0->ptopv;
            bus[last_row-current_mapdist][last_col].lmrd[j].h = dmop0->ptoph;
            bus[last_row-current_mapdist][last_col].lmrd[j].s = j;
          }
#if 0
          bus[last_row-current_mapdist][last_col].ea1brv = T_IMMEDIATE; /* drain offset=32 �̾�lmmi�Ȥζ��縡�� */
          bus[last_row-current_mapdist][last_col].ea1brh = -1;
          bus[last_row-current_mapdist][last_col].ea1orv = T_IMMEDIATE; /* drain offset=32 �̾�lmmi�Ȥζ��縡�� */
          bus[last_row-current_mapdist][last_col].ea1orh = -1;
          fprintf(ofile, "\temax5_regv_%s->regv[%d][%d].ea1or = %d;\n",  id[current_prefix].name, last_col, last_row-current_mapdist, 32);
#endif
        }
        for (j=0; j<UNIT_WIDTH; j++) {
          bus[last_row][last_col].mw[j].v = dmop0->mopdv;
          bus[last_row][last_col].mw[j].h = dmop0->mopdh;
          bus[last_row][last_col].mw[j].s = dmop0->mopds;
        }
      }
      insn[i].iheader.fixed = 1;
      break;
    default: /* illegal */
      break;
    }
#if 1
    printf("dec[%d][%d]:type=%d\n", last_row, last_col, type);
#endif
  }
  /**********************************************************************************************************/
  /* Step 2 ... setup conf[][]                                                                              */
  /* 2-1. select EXE-in                                                                                     */
  /* 2-2. select CEX-in and EAG-in                                                                          */
  /* 2-3. setup broadcast bus pass1                                                                         */
  /**********************************************************************************************************/
  for (i=0; i<EMAX_DEPTH; i++) {
    for (j=0; j<EMAX_WIDTH; j++) {
      int ea0rs, ea1rs;
      /* 2-1 */
      /* ex[123] depends on busmap[i][j].br[prev][] and decode[i][j].dexu.ex[123] */
      conf[j][i].cdw0.op1    = dec[i][j].dexu.op1;
      conf[j][i].cdw0.op2    = dec[i][j].dexu.op2;
      conf[j][i].cdw0.op3    = dec[i][j].dexu.op3;
      conf[j][i].cdw0.ex1brs = search_prev_br0(i, dec[i][j].dexu.ex1v, dec[i][j].dexu.ex1h, dec[i][j].dexu.ex1s);
      conf[j][i].cdw0.ex1s   = dec[i][j].dexu.updt; /* 0->0 or 0->1 */
      conf[j][i].cdw0.ex1exp = dec[i][j].dexu.ex1e;
      conf[j][i].cdw0.ex2brs = search_prev_br0(i, dec[i][j].dexu.ex2v, dec[i][j].dexu.ex2h, dec[i][j].dexu.ex2s);
      conf[j][i].cdw0.ex2exp = dec[i][j].dexu.ex2e;
      conf[j][i].cdw0.ex3brs = search_prev_br0(i, dec[i][j].dexu.ex3v, dec[i][j].dexu.ex3h, dec[i][j].dexu.ex3s);
      conf[j][i].cdw0.ex3exp = dec[i][j].dexu.ex3e;
      if (dec[i][j].dexu.e2iv==T_IMMEDIATE)
        conf[j][i].cdw3.e2imm  = id[dec[i][j].dexu.e2ih].val;
      else
        conf[j][i].cdw3.e2imm  = 0;
      conf[j][i].cdw0.e2is   = dec[i][j].dexu.e2is;
      if (dec[i][j].dexu.e3iv==T_IMMEDIATE) {
        if ((Ull)id[dec[i][j].dexu.e3ih].val > (1<<E3IMMBITS)-1) {
          printf("in %s: [%d][%d] cannot fit to e3imm(unsigned %dbit) immediate=0x%08.8x%08.8x\n", id[current_prefix].name, i, j, E3IMMBITS, (Uint)(id[dec[i][j].dexu.e3ih].val>>32), (Uint)id[dec[i][j].dexu.e3ih].val);
          exit(1);
        }
        conf[j][i].cdw0.e3imm  = id[dec[i][j].dexu.e3ih].val;
      }
      else
        conf[j][i].cdw0.e3imm  = 0;
      conf[j][i].cdw0.e3is   = dec[i][j].dexu.e3is;

      /* 2-2 */
      /* cs[0-3] depends on busmap[i][j].br[prev][] and decode[i][j].dcex.bit[0-3] */
      conf[j][i].cdw1.cs0    = search_prev_br0(i, dec[i][j].dcex.bit0v, dec[i][j].dcex.bit0h, -1);
      conf[j][i].cdw1.cs1    = search_prev_br0(i, dec[i][j].dcex.bit1v, dec[i][j].dcex.bit1h, -1);
      conf[j][i].cdw1.cs2    = search_prev_br0(i, dec[i][j].dcex.bit2v, dec[i][j].dcex.bit2h, -1);
      conf[j][i].cdw1.cs3    = search_prev_br0(i, dec[i][j].dcex.bit3v, dec[i][j].dcex.bit3h, -1);
      conf[j][i].cdw1.cex_tab= dec[i][j].dcex.op ? dec[i][j].dcex.table : 0xffff; /* always true */
      /* ea[bo] depends on busmap[i][j].br[prev][] and decode[i][j].dmop.ex[123] */
      /* mapdist=0�ξ��,dmop0.op=OP_IM_PREF�β�ǽ������,����оݳ� */
      conf[j][i].cdw1.ea0op  = dec[i][j].dmop0.op;
      conf[j][i].cdw1.ea0bs  =((!dec[i][j].dmop0.op||dec[i][j].dmop0.op==OP_IM_PREF )||bus[i][j].ea0brv?0:2)|(dec[i][j].dmop0.updt?1:0); /* 0:ea0br, 1:ea0dr(ea0br+self-loop), 2:eabbrs, 3:ea0dr(eabbrs+self-loop) */
      conf[j][i].cdw1.ea0os  = (!dec[i][j].dmop0.op||dec[i][j].dmop0.op==OP_IM_PREF )||bus[i][j].ea0orv?0:1;                             /* 0:ea0or, 1:eaobrs */
      conf[j][i].cdw1.ea0msk = dec[i][j].dmop0.offsm;
      /* mapdist=0�ξ��,dmop1.op=OP_IM_DRAIN�β�ǽ������,����оݳ� */
      if (dec[i][j].dmop0.op == OP_LDDMQ || dec[i][j].dmop0.op == OP_TR)
	conf[j][i].cdw1.ea1op  = dec[i][j].dmop0.op;
      else
	conf[j][i].cdw1.ea1op  = dec[i][j].dmop1.op;
      conf[j][i].cdw1.ea1bs  =((!dec[i][j].dmop1.op||dec[i][j].dmop1.op==OP_IM_DRAIN)||bus[i][j].ea1brv?0:2)|(dec[i][j].dmop1.updt?1:0); /* 0:ea1br, 1:ea1dr(ea1br+self-loop), 2:eabbrs, 3:ea1dr(eabbrs+self-loop) */
      conf[j][i].cdw1.ea1os  = (!dec[i][j].dmop1.op||dec[i][j].dmop1.op==OP_IM_DRAIN)||bus[i][j].ea1orv?0:1;                             /* 0:ea1or, 1:eaobrs */
      conf[j][i].cdw1.ea1msk = dec[i][j].dmop1.offsm;
      if (conf[j][i].cdw1.ea0bs&2) /* find source of eabbrs */
        ea0rs = search_prev_br0(i, dec[i][j].dmop0.basev, dec[i][j].dmop0.baseh, dec[i][j].dmop0.bases);
      else
        ea0rs = -1;
      if (conf[j][i].cdw1.ea1bs&2) /* find source of eabbrs */
        ea1rs = search_prev_br0(i, dec[i][j].dmop1.basev, dec[i][j].dmop1.baseh, dec[i][j].dmop1.bases);
      else
        ea1rs = -1;
      if ((conf[j][i].cdw1.ea0bs&2) && (conf[j][i].cdw1.ea1bs&2)) { /* eabbrs is shared */
        /* check conflict */
        if (ea0rs != ea1rs) { /* conflict */
          printf("in %s: [%d][%d] dmop1.base(%s) and dmop0.base(%s) conflict\n", id[current_prefix].name, i, j, id[dec[i][j].dmop1.baseh].name, id[dec[i][j].dmop0.baseh].name);
          exit(1);
        }
        conf[j][i].cdw1.eabbrs = ea0rs; /* dmop0.base takes eabbrs */
      }
      else if (conf[j][i].cdw1.ea0bs&2)
        conf[j][i].cdw1.eabbrs = ea0rs; /* dmop0.base takes eabbrs */
      else if (conf[j][i].cdw1.ea1bs&2)
        conf[j][i].cdw1.eabbrs = ea1rs; /* dmop1.base takes eabbrs */
      else
        conf[j][i].cdw1.eabbrs = 0; /* not used */
      if (conf[j][i].cdw1.ea0os)
        ea0rs = search_prev_br0(i, dec[i][j].dmop0.offsv, dec[i][j].dmop0.offsh, dec[i][j].dmop0.offss);
      if (conf[j][i].cdw1.ea1os)
        ea1rs = search_prev_br0(i, dec[i][j].dmop1.offsv, dec[i][j].dmop1.offsh, dec[i][j].dmop1.offss);
      if (conf[j][i].cdw1.ea0os && conf[j][i].cdw1.ea1os) { /* eaobrs is selected */
        /* check conflict */
        if (ea0rs != ea1rs) { /* conflict */
          printf("in %s: [%d][%d] dmop1.offs(%s) and dmop0.offs(%s) conflict\n", id[current_prefix].name, i, j, id[dec[i][j].dmop1.offsh].name, id[dec[i][j].dmop0.offsh].name);
          exit(1);
        }
        conf[j][i].cdw1.eaobrs = ea0rs; /* dmop0.offs takes eaobrs */
      }
      else if (conf[j][i].cdw1.ea0os)
        conf[j][i].cdw1.eaobrs = ea0rs; /* dmop0.offs takes eaobrs */
      else if (conf[j][i].cdw1.ea1os)
        conf[j][i].cdw1.eaobrs = ea1rs; /* dmop1.offs takes eaobrs */
      else
        conf[j][i].cdw1.eaobrs = 0; /* not used */
    }

#if 1
    /* 2-3-1 */
    /* setup broadcast bus pass1 */
    /* lmp/lmd�ξ��,ptop�����Ȥä�lmwd/lmrd�˼��̻Ҥ����åȤ���Ƥ��� */
    /* ��ʿ��������Ӥ�,��ʣlmwd��ޡ�������. ������ʪ���Х���1�ȤΤ���,broadcast����Ѳ�ǽ��lmwd��2�Ȥޤ� */
    /* 1. broadcast�ε�������ơ������õ��         */
    /* 2. broadcast���ʤ����,skip                      */
    /* 3. broadcast��������,bus���ꤪ��Ӿ�Ĺlmmi��� */
    /* 4. broadcast��������,�Ĥ��broadcast��skip     */
    for (flag=0,j=0; j<EMAX_WIDTH; j++) {
      for (k=0; k<EMAX_WIDTH; k++) {
        if (bcas_col == k)
          continue; /* ���Ȥ�skip */
        if (lmmi[bcas_col][i].v     && lmmi[k][i].v
         &&(lmmi[bcas_col][i].rw==0 || lmmi[bcas_col][i].f)
         && lmmi[bcas_col][i].rw    == lmmi[k][i].rw
         && lmmi[bcas_col][i].f     == lmmi[k][i].f
         && lmmi[bcas_col][i].p     == lmmi[k][i].p
         && lmmi[bcas_col][i].blk   == lmmi[k][i].blk
         && lmmi[bcas_col][i].len   == lmmi[k][i].len
         && lmmi[bcas_col][i].top   == lmmi[k][i].top) {
          lmmi[bcas_col][i].bcas |= (1<<k); /* add */
          lmmi[k][i].copy = 1; /* mark as copy */
          bus[i][k].lmwd[0].v = 0; /* delete duplicated lmwd[0] */
          bus[i][k].lmwd[1].v = 0; /* delete duplicated lmwd[1] */
          bus[i][k].lmwd[2].v = 0; /* delete duplicated lmwd[2] */
          bus[i][k].lmwd[3].v = 0; /* delete duplicated lmwd[3] */
          flag |= 1<<k;
        }
      }
      if (flag)
        break;
      bcas_col=(bcas_col+1)%EMAX_WIDTH;
    }
    if (flag) { /* duplicated lmmi exist */
      /* connect broadcast bus left <- right */
      for (j=0; j<EMAX_WIDTH; j++) {
        for (k=0; k<UNIT_WIDTH; k++) {
          bus[i][j].lmri[k].v = (j >  bcas_col && (flag & (0x7<<j))) ? bus[i][bcas_col].lmwd[k].v :  0;
          bus[i][j].lmri[k].h = (j >  bcas_col && (flag & (0x7<<j))) ? bus[i][bcas_col].lmwd[k].h : -1;
          bus[i][j].lmri[k].s = (j >  bcas_col && (flag & (0x7<<j))) ? bus[i][bcas_col].lmwd[k].s : -1;
          bus[i][j].lmlo[k].v = (j >= bcas_col && (flag & (0xe<<j))) ? bus[i][bcas_col].lmwd[k].v :  0;
          bus[i][j].lmlo[k].h = (j >= bcas_col && (flag & (0xe<<j))) ? bus[i][bcas_col].lmwd[k].h : -1;
          bus[i][j].lmlo[k].s = (j >= bcas_col && (flag & (0xe<<j))) ? bus[i][bcas_col].lmwd[k].s : -1;
        }
      }
      /* connect broadcast bus left -> right */
      for (j=EMAX_WIDTH-1; j>=0; j--) {
        for (k=0; k<UNIT_WIDTH; k++) {
          bus[i][j].lmli[k].v = (j <  bcas_col && (flag & (0xe>>(UNIT_WIDTH-1-j)))) ? bus[i][bcas_col].lmwd[k].v :  0;
          bus[i][j].lmli[k].h = (j <  bcas_col && (flag & (0xe>>(UNIT_WIDTH-1-j)))) ? bus[i][bcas_col].lmwd[k].h : -1;
          bus[i][j].lmli[k].s = (j <  bcas_col && (flag & (0xe>>(UNIT_WIDTH-1-j)))) ? bus[i][bcas_col].lmwd[k].s : -1;
          bus[i][j].lmro[k].v = (j <= bcas_col && (flag & (0x7>>(UNIT_WIDTH-1-j)))) ? bus[i][bcas_col].lmwd[k].v :  0;
          bus[i][j].lmro[k].h = (j <= bcas_col && (flag & (0x7>>(UNIT_WIDTH-1-j)))) ? bus[i][bcas_col].lmwd[k].h : -1;
          bus[i][j].lmro[k].s = (j <= bcas_col && (flag & (0x7>>(UNIT_WIDTH-1-j)))) ? bus[i][bcas_col].lmwd[k].s : -1;
        }
      }
      /* setup conf */
      for (j=0; j<EMAX_WIDTH; j++) {
        if (j == bcas_col) { /* broadcasting point */
          conf[j][i].cdw2.lmls = 0; /* lmlo  <- lmwad */
          conf[j][i].cdw2.lmrs = 0; /* lmwad -> lmro  */
          /* STATUS_LOAD���� */
          conf[j][i].cdw2.xmws = 2;
        }
        else if (flag & (1<<j)) { /* bcast_slave */
          conf[j][i].cdw2.lmls = 1; /* lmlo <- lmri */
          conf[j][i].cdw2.lmrs = 1; /* lmli -> lmro */
          /* STATUS_LOAD���� */
          conf[j][i].cdw2.xmws = bus[i][j].lmli[0].v?1:3;
        }
        else { /* !bcast_slave */
          conf[j][i].cdw2.lmls = 1; /* lmlo <- lmri */
          conf[j][i].cdw2.lmrs = 1; /* lmli -> lmro */
          /* STATUS_LOAD���� */
          conf[j][i].cdw2.xmws = 2; /* ���Ȥ���Ωư�� */
        }
      }
      bcas_col=(bcas_col+1)%EMAX_WIDTH;
    }
    else { /* no duplication */
      for (j=0; j<EMAX_WIDTH; j++) {
        if (lmmi[j][i].v && (lmmi[j][i].rw  == 0 || lmmi[j][i].f) && !(lmmi[j][i].f && lmmi[j][i].p)) { /* ñ��lmr,lmf,lmp,lmx */
          /* STATUS_LOAD���� */
          conf[j][i].cdw2.xmws = 2;
        }
      }
    }
    /* 2-3-2 */
    /* setup broadcast bus pass2 */
    /* 2���ܤ�broadcast��,Way3-Way2�ޤ���Way1-Way0�Τ߸����Ǥ褤 */
    /* check Way1-Way0 */
    /* pass1�ˤ�� conf[j][i].cdw2.lmls = 1;  lmlo <- lmri   */
    /*             conf[j][i].cdw2.lmrs = 1;  lmli -> lmro   */
    /*             conf[j][i].cdw2.xmws = 2;  ���Ȥ���Ωư�� */
    /* �ȤʤäƤ����Τ�����Ʊlmmi�ˤĤ��Ƥ�,�ʲ��˾��   */
    /*             lmmi[bcas_col][i].bcas |= (1<<j); */
    /*             lmmi[j][i].copy = 1;              */
    /*             bus[i][j].lmwd[0..3].v = 0;       */

    /*    bcas>j: bcas=3,j=2�䡤bcas=1,j=0��ͭ�����ʤ�      */
    /*             bus[i][b].lmro[0..3].v,h,s = bus[i][bcas_col].lmwd[0..3].v,h,s */
    /*             conf[b][i].cdw2.lmrs = 0; lmwad -> lmro  */
    /*             conf[b][i].cdw2.xmws = 2; lmwad -> get   */
    /*             bus[i][j].lmli[0..3].v,h,s = bus[i][bcas_col].lmwd[0..3].v,h,s */
    /*             conf[j][i].cdw2.xmws = 1; lmli  -> get   */
    /*    j>bcas: j=3,bcas=2�ȡ�j=1,bcas=0��ͭ������        */
    /*             bus[i][b].lmlo[0..3].v,h,s = bus[i][bcas_col].lmwd[0..3].v,h,s */
    /*             conf[b][i].cdw2.lmls = 0; lmlo  <- lmwad */
    /*             conf[b][i].cdw2.xmws = 2; lmwad -> get   */
    /*             bus[i][j].lmri[0..3].v,h,s = bus[i][bcas_col].lmwd[0..3].v,h,s */
    /*             conf[j][i].cdw2.xmws = 3; lmri  -> get   */
    flag = 0;
    if (!lmmi[1][i].bcas  && !lmmi[0][i].bcas
      &&!lmmi[1][i].copy  && !lmmi[0][i].copy
      && lmmi[1][i].v     &&  lmmi[0][i].v
      &&(lmmi[1][i].rw==0 ||  lmmi[1][i].f)
      && lmmi[1][i].rw    ==  lmmi[0][i].rw
      && lmmi[1][i].f     ==  lmmi[0][i].f
      && lmmi[1][i].p     ==  lmmi[0][i].p   /* ofs!=0�ξ���EXECƱ��(p=1)���оݤ�top+ofs */
      && lmmi[1][i].blk   ==  lmmi[0][i].blk /*                       PLOAD���оݤ�TOP     */
      && lmmi[1][i].len   ==  lmmi[0][i].len
      && lmmi[1][i].top   ==  lmmi[0][i].top) {
      flag = 1;
      if (bcas_col == 0) bcas_col = 2; /* skip 0 and 1 */
      switch (bcas_co2) {
      case 0: case 2: bcas_co2 = 0; j = 1; break;
      case 1: case 3: bcas_co2 = 1; j = 0; break;
      }
    }
    else if (!lmmi[3][i].bcas  && !lmmi[2][i].bcas
      &&!lmmi[3][i].copy  && !lmmi[2][i].copy
      && lmmi[3][i].v     &&  lmmi[2][i].v
      &&(lmmi[3][i].rw==0 ||  lmmi[3][i].f)
      && lmmi[3][i].rw    ==  lmmi[2][i].rw
      && lmmi[3][i].f     ==  lmmi[2][i].f
      && lmmi[3][i].p     ==  lmmi[2][i].p   /* ofs!=0�ξ���EXECƱ��(p=1)���оݤ�top+ofs */
      && lmmi[3][i].blk   ==  lmmi[2][i].blk /*                       PLOAD���оݤ�TOP     */
      && lmmi[3][i].len   ==  lmmi[2][i].len
      && lmmi[3][i].top   ==  lmmi[2][i].top) {
      flag = 1;
      if (bcas_col == 2) bcas_col = 0; /* skip 2 and 3 */
      switch (bcas_co2) {
      case 0: case 2: bcas_co2 = 2; j = 3; break;
      case 1: case 3: bcas_co2 = 3; j = 2; break;
      }
    }
    if (flag) {
      lmmi[bcas_co2][i].bcas |= (1<<j); /* add */
      lmmi[j][i].copy = 1; /* mark as copy */
      bus[i][j].lmwd[0].v = 0; /* delete duplicated lmwd[0] */
      bus[i][j].lmwd[1].v = 0; /* delete duplicated lmwd[1] */
      bus[i][j].lmwd[2].v = 0; /* delete duplicated lmwd[2] */
      bus[i][j].lmwd[3].v = 0; /* delete duplicated lmwd[3] */
      if (j > bcas_co2) {
        for (k=0; k<UNIT_WIDTH; k++) {
          bus[i][bcas_co2].lmlo[k].v = bus[i][bcas_co2].lmwd[k].v;
          bus[i][bcas_co2].lmlo[k].h = bus[i][bcas_co2].lmwd[k].h;
          bus[i][bcas_co2].lmlo[k].s = bus[i][bcas_co2].lmwd[k].s;
        }
        conf[bcas_co2][i].cdw2.lmls = 0; /* lmlo  <- lmwad */
        conf[bcas_co2][i].cdw2.xmws = 2; /* lmwad -> get   */
        for (k=0; k<UNIT_WIDTH; k++) {
          bus[i][j].lmri[k].v = bus[i][bcas_co2].lmwd[k].v;
          bus[i][j].lmri[k].h = bus[i][bcas_co2].lmwd[k].h;
          bus[i][j].lmri[k].s = bus[i][bcas_co2].lmwd[k].s;
        }
        conf[j][i].cdw2.xmws = 3; /* lmri  -> get   */
      }
      else { /* bcas_co2 > j */
        for (k=0; k<UNIT_WIDTH; k++) {
          bus[i][bcas_co2].lmro[k].v = bus[i][bcas_co2].lmwd[k].v;
          bus[i][bcas_co2].lmro[k].h = bus[i][bcas_co2].lmwd[k].h;
          bus[i][bcas_co2].lmro[k].s = bus[i][bcas_co2].lmwd[k].s;
        }
        conf[bcas_co2][i].cdw2.lmrs = 0; /* lmlo  <- lmwad */
        conf[bcas_co2][i].cdw2.xmws = 2; /* lmwad -> get   */
        for (k=0; k<UNIT_WIDTH; k++) {
          bus[i][j].lmli[k].v = bus[i][bcas_co2].lmwd[k].v;
          bus[i][j].lmli[k].h = bus[i][bcas_co2].lmwd[k].h;
          bus[i][j].lmli[k].s = bus[i][bcas_co2].lmwd[k].s;
        }
        conf[j][i].cdw2.xmws = 1; /* lmli  -> get   */
      }
      bcas_co2=(bcas_co2+1)%EMAX_WIDTH;
    }
#endif
  }
  /**********************************************************************************************************/
  /* Step 3 ... setup conf[][]                                                                              */
  /* 3-1. select MW-in                                                                                      */
  /* 3-2. select BR-in                                                                                      */
  /* 3-3. set mapdist                                                                                       */
  /**********************************************************************************************************/
  for (i=0; i<EMAX_DEPTH; i++) {
    for (j=0; j<EMAX_WIDTH; j++) {
      /* 3-1 */
      /* tr[0],mw[0] */
      /* AR->TR�Υѥ��������EX4��������� */
      /* BR->TR�Υѥ�������������� */
      if (bus[i][j].tr[0].v) { /* tr[0] active */
        if ((k = search_prev_ar0_tr(i, j, 0, bus[i][j].tr[0].v, bus[i][j].tr[0].h, bus[i][j].tr[0].s)) >= 0) {
          conf[j][i].cdw2.trs0 = k;
        }
        else {
          k = search_prev_br0(i, bus[i][j].tr[0].v, bus[i][j].tr[0].h, bus[i][j].tr[0].s);
          conf[j][i].cdw2.ts0  = k;
          conf[j][i].cdw2.trs0 = 2; /* ts0 */
        }
      }
      /* AR->MW�Υѥ��������set */
      /* BR->MW�Υѥ��������set */
      /* LMWD->MW�Υѥ��������set */
      if (bus[i][j].mw[0].v) { /* mw[0] active */
        if ((k = search_prev_ar0_mw(i, j, 0, bus[i][j].mw[0].v, bus[i][j].mw[0].h, bus[i][j].mw[0].s)) >= 0) {
          conf[j][i].cdw2.mws0 = k;
        }
        else {
          k = search_prev_br0(i, bus[i][j].mw[0].v, bus[i][j].mw[0].h, bus[i][j].mw[0].s);
          conf[j][i].cdw2.ts0  = k;
          conf[j][i].cdw2.mws0 = 2; /* ts0 */
        }
      }
      /* mws0... 0:exdr, 1:exdr0, 2:ts0, 3:lmli0, 4:lmwd0, 5:lmri0 */
      /* mwsa... 0:ea0, 1:lmlia, 2:lmwa, 3:lmria *//* for STATUS_EXEC+lmp */
      switch (conf[j][i].cdw2.mws0) {
      case 3: conf[j][i].cdw2.mwsa = 1; break;
      case 4: conf[j][i].cdw2.mwsa = 2; break;
      case 5: conf[j][i].cdw2.mwsa = 3; break;
      default:conf[j][i].cdw2.mwsa = 0; break;
      }

      /* tr[1],mw[1] */
      if (bus[i][j].tr[1].v) { /* tr[1] active */
        if ((k = search_prev_ar0_tr(i, j, 1, bus[i][j].tr[1].v, bus[i][j].tr[1].h, bus[i][j].tr[1].s)) >= 0) {
          conf[j][i].cdw2.trs1 = k;
        }
        else {
          k = search_prev_br0(i, bus[i][j].tr[1].v, bus[i][j].tr[1].h, bus[i][j].tr[1].s);
          conf[j][i].cdw2.ts1  = k;
          conf[j][i].cdw2.trs1 = 2; /* ts1 */
        }
      }
      if (bus[i][j].mw[1].v) { /* mw[1] active */
        if ((k = search_prev_ar0_mw(i, j, 1, bus[i][j].mw[1].v, bus[i][j].mw[1].h, bus[i][j].mw[1].s)) >= 0) {
          conf[j][i].cdw2.mws1 = k;
        }
        else {
          k = search_prev_br0(i, bus[i][j].mw[1].v, bus[i][j].mw[1].h, bus[i][j].mw[1].s);
          conf[j][i].cdw2.ts1  = k;
          conf[j][i].cdw2.mws1 = 2; /* ts1 */
        }
      }

      /* tr[2],mw[2] */
      if (bus[i][j].tr[2].v) { /* tr[2] active */
        if ((k = search_prev_ar0_tr(i, j, 2, bus[i][j].tr[2].v, bus[i][j].tr[2].h, bus[i][j].tr[2].s)) >= 0) {
          conf[j][i].cdw2.trs2 = k;
        }
        else {
          k = search_prev_br0(i, bus[i][j].tr[2].v, bus[i][j].tr[2].h, bus[i][j].tr[2].s);
          conf[j][i].cdw2.ts2  = k;
          conf[j][i].cdw2.trs2 = 2; /* ts2 */
        }
      }
      if (bus[i][j].mw[2].v) { /* mw[2] active */
        if ((k = search_prev_ar0_mw(i, j, 2, bus[i][j].mw[2].v, bus[i][j].mw[2].h, bus[i][j].mw[2].s)) >= 0) {
          conf[j][i].cdw2.mws2 = k;
        }
        else {
          k = search_prev_br0(i, bus[i][j].mw[2].v, bus[i][j].mw[2].h, bus[i][j].mw[2].s);
          conf[j][i].cdw2.ts2  = k;
          conf[j][i].cdw2.mws2 = 2; /* ts2 */
        }
      }

      /* tr[3],mw[3] */
      if (bus[i][j].tr[3].v) { /* tr[3] active */
        if ((k = search_prev_ar0_tr(i, j, 3, bus[i][j].tr[3].v, bus[i][j].tr[3].h, bus[i][j].tr[3].s)) >= 0) {
          conf[j][i].cdw2.trs3 = k;
        }
        else {
          k = search_prev_br0(i, bus[i][j].tr[3].v, bus[i][j].tr[3].h, bus[i][j].tr[3].s);
          conf[j][i].cdw2.ts3  = k;
          conf[j][i].cdw2.trs3 = 2; /* ts3 */
        }
      }
      if (bus[i][j].mw[3].v) { /* mw[3] active */
        if ((k = search_prev_ar0_mw(i, j, 3, bus[i][j].mw[3].v, bus[i][j].mw[3].h, bus[i][j].mw[3].s)) >= 0) {
          conf[j][i].cdw2.mws3 = k;
        }
        else {
          k = search_prev_br0(i, bus[i][j].mw[3].v, bus[i][j].mw[3].h, bus[i][j].mw[3].s);
          conf[j][i].cdw2.ts3  = k;
          conf[j][i].cdw2.mws3 = 2; /* ts3 */
        }
      }

      /* 3-2 */
      /* conf[j][i].cdw2.brs0; *//* set with bus.tr[]/br[] */
      /* conf[j][i].cdw2.brs1; *//* set with bus.tr[]/br[] */
      /* conf[j][i].cdw2.brs2; *//* set with bus.tr[]/br[] */
      /* conf[j][i].cdw2.brs3; *//* set with bus.tr[]/br[] */
      /* exdr is connected by default (brs=0) */

      /* 3-3 */
      conf[j][i].cdw2.mapdist = current_mapdist;
    }
  }
  /**********************************************************************************************************/
  /* Step 4 ... Insert LMM-buffering for neighbor LDDMQ                                                     */
  /*            Multiple LDDMQ in the same row is not allowed                                               */
  /**********************************************************************************************************/
  for (i=0; i<EMAX_DEPTH; i++) {
    /* checking LDDMQ */
    int lddmq_loc = -1;
    for (j=0; j<EMAX_WIDTH; j++) {
      if (conf[j][i].cdw1.ea0op == OP_LDDMQ) {
        lddmq_loc = j;
        break;
      }
    }
    if (lddmq_loc < 0)
      continue;
    for (j=0; j<EMAX_WIDTH; j++) {
      if (j == lddmq_loc)
        continue;
      /* LMM-buffering replacement */
      if (conf[j][i].cdw2.brs0 || conf[j][i].cdw2.brs1 || conf[j][i].cdw2.brs2 || conf[j][i].cdw2.brs3) {
        if (conf[j][i].cdw1.ea0op || conf[j][i].cdw1.ea1op) { /* error if EAGs are occupied */
          printf("in %s: [%d][%d] cannot remap BR-buffering for neighbor lddmq (ea0op=%d ea1op=%d\n",
		 id[current_prefix].name, i, j, conf[j][i].cdw1.ea0op, conf[j][i].cdw1.ea1op);
          exit(1);
        }
        /* setup LMM as FIFO */
        conf[j][i].cdw1.ea0op  = OP_IM_BUFWR;
        conf[j][i].cdw1.ea0bs  = 1; /* ea0br+self-loop */
        conf[j][i].cdw1.ea0os  = 0; /* ea0or           */
        conf[j][i].cdw1.ea0msk = 15;/* 64bit           */
        conf[j][i].cdw1.ea1op  = OP_IM_BUFRD;
        conf[j][i].cdw1.ea1bs  = 1; /* ea1br+self-loop */
        conf[j][i].cdw1.ea1os  = 0; /* ea1or           */
        conf[j][i].cdw1.ea1msk = 15;/* 64bit           */
        conf[j][i].cdw1.eabbrs = 0; /* not used */
        conf[j][i].cdw1.eaobrs = 0; /* not used */
        fprintf(ofile, "\temax5_regv_%s->regv[%d][%d].ea0br = %dLL; /* LMM_buffering */\n", id[current_prefix].name, j, i, 0);
        fprintf(ofile, "\temax5_regv_%s->regv[%d][%d].ea0or = %dLL; /* LMM_buffering */\n", id[current_prefix].name, j, i, 32);
        fprintf(ofile, "\temax5_regv_%s->regv[%d][%d].ea1br = %dLL; /* LMM_buffering */\n", id[current_prefix].name, j, i, 0);
        fprintf(ofile, "\temax5_regv_%s->regv[%d][%d].ea1or = %dLL; /* LMM_buffering */\n", id[current_prefix].name, j, i, 32);
        /* ts0-3�ϰݻ� */
        /* brs0-3��TR��EXDR�Ǥ��뤳�Ȥ��ǧ��,mws0-3��ȿ�� */
        /* brs0-3��mr10-13�����ؤ� */
        printf("Lmm-buffering is inserted in conf[%d][%d]", i, j);
        switch (conf[j][i].cdw2.brs3) {
        case 2: conf[j][i].cdw2.mws3 = 2; conf[j][i].cdw2.brs3 = 1; printf(".t3"); break; /* tr3: ts3->mw3->mr13 */
        default:                          conf[j][i].cdw2.brs3 = 0; break; /* off */
        }
        switch (conf[j][i].cdw2.brs2) {
        case 2: conf[j][i].cdw2.mws2 = 2; conf[j][i].cdw2.brs2 = 1; printf(".t2"); break; /* tr2: ts2->mw2->mr12 */
        case 3: conf[j][i].cdw2.mws2 = 0; conf[j][i].cdw2.brs2 = 1; printf(".ex"); break; /* exd: exd->mw2->mr12 */
        default:                          conf[j][i].cdw2.brs2 = 0; break; /* off */
        }
        switch (conf[j][i].cdw2.brs1) {
        case 2: conf[j][i].cdw2.mws1 = 2; conf[j][i].cdw2.brs1 = 1; printf(".t1"); break; /* tr1: ts1->mw1->mr11 */
        default:                          conf[j][i].cdw2.brs1 = 0; break; /* off */
        }
        switch (conf[j][i].cdw2.brs0) {
        case 2: conf[j][i].cdw2.mws0 = 2; conf[j][i].cdw2.brs0 = 1; printf(".t0"); break; /* tr0: ts0->mw0->mr10 */
        default:                          conf[j][i].cdw2.brs0 = 0; break; /* off */
        }
        printf(" for [%d][%d].lddmq\n", i, lddmq_loc);
      }
    }
    /**/
  }
  /**********************************************************************************************************/
  /* Step 5 ... emit all                                                                                    */
  /**********************************************************************************************************/
#if 0
  fprintf(ofile, "int emax5_lmmi_%s_i, emax5_lmmi_%s_j;\n", id[current_prefix].name, id[current_prefix].name);
  fprintf(ofile, "for (emax5_lmmi_%s_i=0;emax5_lmmi_%s_i<%d;emax5_lmmi_%s_i++) {\n", id[current_prefix].name, id[current_prefix].name, EMAX_WIDTH, id[current_prefix].name);
  fprintf(ofile, "for (emax5_lmmi_%s_j=0;emax5_lmmi_%s_j<%d;emax5_lmmi_%s_j++) {\n", id[current_prefix].name, id[current_prefix].name, EMAX_DEPTH, id[current_prefix].name);
  fprintf(ofile, "emax5_lmmi_%s[emax5_lmmi_%s_i][emax5_lmmi_%s_j].v = 0; }}\n", id[current_prefix].name, id[current_prefix].name, id[current_prefix].name);
#endif
  for (j=0; j<EMAX_WIDTH; j++) {
    for (i=0; i<EMAX_DEPTH; i++) {
      if (lmmi[j][i].v) {
        if (lmmx[j][i].lenv == T_IMMEDIATE) { /* IMMEDIATE */
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].ctl = 0x%08.8x;\n",
                  id[current_prefix].name, j, i,
                  *(Uint*)&lmmi[j][i]);
        }
        else { /* VARIABLE */
          fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].ctl = ((%s-1)<<16)|0x%04.4x;\n",
                  id[current_prefix].name, j, i,
                  id[lmmx[j][i].lenh].name, *(Ushort*)&lmmi[j][i]);
        }
        fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].ofs = (Uchar*)%s - (Uchar*)%s;\n",
                id[current_prefix].name, j, i,
                (char*)lmmi[j][i].top + lmmi[j][i].ofs,
                (char*)lmmi[j][i].top);
        fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].top = %s;\n", id[current_prefix].name, j, i, (char*)lmmi[j][i].top);
      }
      else
        fprintf(ofile, "\temax5_lmmi_%s->lmmi[%d][%d].ctl = 0x00000000;\n",
                id[current_prefix].name, j, i);
    }
  }
  fprintf(ofile, "\tif (!acp_conf_tab[%d].v) {\n", y_emax5a_seqno);
  fprintf(ofile, "\tint i;\n");
  fprintf(ofile, "\tacp_conf_tab[%d].v   = 1;\n", y_emax5a_seqno);
  fprintf(ofile, "\tacp_conf_tab[%d].top = emax5_conf_%s;\n", y_emax5a_seqno, id[current_prefix].name);
  fprintf(ofile, "\tfor (i=0; i<sizeof(conf)/sizeof(Ull); i++)\n");
  fprintf(ofile, "\t*((Ull*)acp_conf+%d*sizeof(conf)/sizeof(Ull)+i) = *((Ull*)(acp_conf_tab[%d].top)+i);\n", y_emax5a_seqno, y_emax5a_seqno);
  fprintf(ofile, "\t}\n");
  if (!current_lmmwb) /* for transaction */
    fprintf(ofile, "\temax5_start_with_keep_cache(acp_conf+0x%08.8xLL, acp_lmmi, acp_regv);\n", sizeof(conf)*y_emax5a_seqno);
  else /* for normal emax */
    fprintf(ofile, "\temax5_start_with_drain_cache(acp_conf+0x%08.8xLL, acp_lmmi, acp_regv);\n", sizeof(conf)*y_emax5a_seqno);
  y_emax5a_seqno++;
  /* conf��1way������,32B*16��=0.5KB,32B*64��=2KB(����). 4wayʬϢ³�ˤ���ˤ�,16�Ԥ�2KB,64�Ԥ�8KB���饤��ɬ��. ZYNQ��page-size��8KB�ʾ�Ǥ����OK */
  fprintf(ofile, "asm volatile(\"b emax5_conf_end_%s\\n\"\n\".align 5\\n\"\n\"emax5_conf_%s:\\n\"\n", id[current_prefix].name, id[current_prefix].name, id[current_prefix].name);
  for (j=0; j<EMAX_WIDTH; j++) {
    for (i=0; i<EMAX_DEPTH; i++) {
      fprintf(ofile, "\"\t.word\t0x%08.8x, 0x%08.8x\\n\"\n", *(Ull*)&conf[j][i].cdw0, (Uint)((*(Ull*)&conf[j][i].cdw0)>>32));
      fprintf(ofile, "\"\t.word\t0x%08.8x, 0x%08.8x\\n\"\n", *(Ull*)&conf[j][i].cdw1, (Uint)((*(Ull*)&conf[j][i].cdw1)>>32));
      fprintf(ofile, "\"\t.word\t0x%08.8x, 0x%08.8x\\n\"\n", *(Ull*)&conf[j][i].cdw2, (Uint)((*(Ull*)&conf[j][i].cdw2)>>32));
      fprintf(ofile, "\"\t.word\t0x%08.8x, 0x%08.8x\\n\"\n", *(Ull*)&conf[j][i].cdw3, (Uint)((*(Ull*)&conf[j][i].cdw3)>>32));
    }
  }
  fprintf(ofile, "\"emax5_conf_end_%s:\\n\"\n", id[current_prefix].name);
  fprintf(ofile, ");\n");
  /**********************************************************************************************************/
  /* Step 6 ... emit tgif                                                                                   */
  /**********************************************************************************************************/
  strncpy(figfile = (char*)malloc(strlen(srcprog)+1+strlen(id[current_prefix].name)+strlen(FIGSUFX)+1), srcprog, strlen(srcprog)+1); /* xxx.x -> xxx-func.obj */
  for (i=0; i<strlen(srcprog); i++) {
    if (figfile[i] == '.' || figfile[i] == '\0' ) {
      strncpy(figfile+i, "-", 2);
      strncat(figfile, id[current_prefix].name, strlen(id[current_prefix].name)+1);
      strncat(figfile, FIGSUFX, strlen(FIGSUFX)+1);
      break;
    }
  }

  /* open fig-file */
  if ((ffile = fopen(figfile, "w")) == NULL) {
    fprintf(stderr, "can't open object:\"%s\"\n", figfile);
    exit(1);
  }

  /* generate fig-file */
  fprintf(ffile, "%%TGIF 4.1.45-QPL\n");
  fprintf(ffile, "state(0,37,100.000,0,0,1,16,1,9,1,1,0,0,1,0,1,0,'Ryumin-Light-EUC-H',0,80640,0,0,1,5,0,0,1,1,0,16,0,0,1,1,1,1,8100,9500,1,0,19000,0).\n");
  fprintf(ffile, "%%\n");
  fprintf(ffile, "unit(\"1 pixel/pixel\").\n");
  fprintf(ffile, "color_info(11,65535,0,[\n");
  fprintf(ffile, "  \"magenta\", 65535, 0, 65535, 65535, 0, 65535, 1,\n");
  fprintf(ffile, "  \"red\", 65535, 0, 0, 65535, 0, 0, 1,\n");
  fprintf(ffile, "  \"green\", 0, 65535, 0, 0, 65535, 0, 1,\n");
  fprintf(ffile, "  \"blue\", 0, 0, 65535, 0, 0, 65535, 1,\n");
  fprintf(ffile, "  \"yellow\", 65535, 65535, 0, 65535, 65535, 0, 1,\n");
  fprintf(ffile, "  \"pink\", 65535, 49344, 52171, 65535, 49344, 52171, 1,\n");
  fprintf(ffile, "  \"cyan\", 0, 65535, 65535, 0, 65535, 65535, 1,\n");
  fprintf(ffile, "  \"CadetBlue\", 24415, 40606, 41120, 24415, 40606, 41120, 1,\n");
  fprintf(ffile, "  \"white\", 65535, 65535, 65535, 65535, 65535, 65535, 1,\n");
  fprintf(ffile, "  \"black\", 0, 0, 0, 0, 0, 0, 1,\n");
  fprintf(ffile, "  \"DarkSlateGray\", 12079, 20303, 20303, 12079, 20303, 20303, 1\n");
  fprintf(ffile, "]).\n");
  fprintf(ffile, "script_frac(\"0.6\").\n");
  fprintf(ffile, "fg_bg_colors('black','white').\n");
  fprintf(ffile, "dont_reencode(\"FFDingbests:ZapfDingbats\").\n");
  fprintf(ffile, "objshadow_info('#c0c0c0',2,2).\n");
  fprintf(ffile, "page(1,\"\",1,'').\n");
  draw_text(100, 100, figfile, 5, 0);

  for (i=0; i<EMAX_DEPTH; i++) {
    for (j=0; j<EMAX_WIDTH; j++) {
      emit_tgif(i, j);
    }
  }

  /* close fig-file */
  fclose(ffile);
  free(figfile);

  return (0);
}

/*****************************************************************************************/
/*****************************************************************************************/
/*****************************************************************************************/

get_mop_type(int op)
{
  int retval;
  switch (op) {
  case OP_LDR:
  case OP_LDWR:
  case OP_LDUWR:
  case OP_LDHR:
  case OP_LDUHR:
  case OP_LDBR:
  case OP_LDUBR:
  case OP_LDRQ:
    retval = MTYPE_RLOAD; /* random_load on mop1->BR (+implicit AXI->mop0->MW) */
    break;
  case OP_STR:
  case OP_STWR:
  case OP_STHR:
  case OP_STBR:
  case OP_STRQ:
    retval = MTYPE_RSTORE; /* random_store on mop0->MW (+implicit mop1->MR->AXI) */
    break;
  case OP_LDDMQ:
    retval = MTYPE_DLOAD; /* direct_load on mop0->MW,MR->AXI->TR->BR (+implicit mop1->MR->AXI) */
    break;
  case OP_TR:
    retval = MTYPE_TRANS; /* transaction on mop0->MW,MR->AXI (+implicit mop1->MR->AXI) */
    break;
  }

  return (retval);
}

get_valid_row(int insn_type, int mid, int src_type, int src_hash, char *rdep)
{
  /* mid:0 ... refer at the top    of UNIT (                 EXE->store_addr) */
  /* mid:1 ... refer at the middle of UNIT (CEX->store_cond, EXE->store_data) */
  int i, j;

  switch (src_type) {
  case T_NONE:
  case T_IMMEDIATE:
    /* do nothing */
    break;
  case T_EXRNO: /* for cex in same unit */
  case T_ALRNO:
  case T_BDRNO:    /* for boundary reg */
  case T_VARIABLE: /* for any variable */
    switch (id[src_hash].itype) { /* ����src�������������̿�᥿���� */
    case ITYPE_CEX:
      if (*rdep < id[src_hash].row) /* loc of new_insn < loc of dst_reg */
        *rdep = id[src_hash].row; /* same row ��CEX+CMOV/MOP */
      break;
    case ITYPE_WHILE:
    case ITYPE_EX4:
    case ITYPE_EXE:
      if (insn_type == ITYPE_MO4 ||  insn_type == ITYPE_MOP) { /* ��³̿�᥿���� MO4 || MOP */
        if (mid==0) { /* EXE->store_addr */
          if (id[src_hash].row >= 0) { /* if defined as dst in EMAX */
            if (*rdep <= id[src_hash].row) /* loc of new_insn < loc of dst_reg */
              *rdep = id[src_hash].row+1; /* next row */
          }
        }
        else { /* EXE->store_data */
          if (*rdep < id[src_hash].row) /* loc of new_insn < loc of dst_reg */
            *rdep = id[src_hash].row; /* same row ��EXE+MOP���ȹ礻��Ʊ��UNIT���Ʋ�ǽ */
        }
      }
      else { /* ��³̿�᥿���� ITYPE_WHILE || ITYPE_CEX || ITYPE_EX4 || ITYPE_EXE */
        if (id[src_hash].row >= 0) { /* if defined as dst in EMAX */
          if (*rdep <= id[src_hash].row) /* loc of new_insn < loc of dst_reg */
            *rdep = id[src_hash].row+1; /* next row */
        }
      }
      break;
    case ITYPE_MO4:
    case ITYPE_MOP:
      if (id[src_hash].row >= 0) { /* if defined as dst in EMAX */
        if (*rdep <= id[src_hash].row) /* loc of new_insn < loc of dst_reg */
          *rdep = id[src_hash].row+1; /* next row */
      }
      break;
    }
    break;
  }
  /* printf("in get_valid: rdep=%d\n", *rdep); */
}

set_reg_path(int last_row, int last_col, int insn_type, int reg_type, int reg_loc, int src_type, int src_hash, int src_sidx)
     /* last_row:  ������԰��� */
     /* last_col:  ����������� */
     /* insn_type: ̿�����     ITYPE_WHILE, ITYPE_CEX, ITYPE_EX4, ITYPE_EXE, ITYPE_MO4, ITYPE_MOP */
     /* reg_type:  ITYPE_MO4/ITYPE_MOP�ξ��Τ�ͭ��: �쥸�������� RTYPE_DATA, RTYPE_BASE, RTYPE_OFFS */
     /* reg_loc:   ITYPE_MO4/ITYPE_MOP�ξ��Τ�ͭ��: MO4/MOP��base/offs�ΰ��� 0:mop0, 1:mop1 */
     /* src_type:  T_NONE, T_IMMEDIATE, T_EXRNO, T_ALRNO, T_BDRNO, T_VARIABLE */
     /* src_hash:  id[src_hash] */
     /* src_sidx:  subindex of VAR[]/AR[]/BR[] */
     /* ������������ARM����������,�����,busmap���� */
{
  int i, j, k, h, w;

  if (src_type == T_NONE) /* T_NONE */
    return;
  if (src_type == T_EXRNO) /* T_EXRNO��Ʊ��UNIT�ˤƾ��񤹤뤿�ᡤbusmap���� */
    return;
  if (id[src_hash].row < 0) { /* initialized by ARM (T_IMMEDIATE, T_VARIABLE) */
    if (insn_type == ITYPE_MO4 || insn_type == ITYPE_MOP) { /* store4/store1 */
      switch (reg_type) {
      case RTYPE_DATA:
        printf("in %s: [%d][%d] ITYPE_MO4/ITYPE_MOP cannot store constant variable %s\n", id[current_prefix].name, last_row, last_col, id[src_hash].name);
        exit(1);
      case RTYPE_BASE:
        if (reg_loc==0) {
          if (bus[last_row][last_col].ea0brv) {
            printf("in %s: [%d][%d] ITYPE_MO4/ITYPE_MOP cannot find empty reg for RTYPE_BASE %s (may conflict with prefetch)\n", id[current_prefix].name, last_row, last_col, id[src_hash].name);
            exit(1);
          }
          bus[last_row][last_col].ea0brv = src_type;
          bus[last_row][last_col].ea0brh = src_hash;
          bus[last_row][last_col].ea0drv = src_type;
          bus[last_row][last_col].ea0drh = src_hash;
          if (src_sidx < 0)
            fprintf(ofile, "\temax5_regv_%s->regv[%d][%d].ea0br = %s;\n", id[current_prefix].name, last_col, last_row, id[src_hash].name);
          else
            fprintf(ofile, "\temax5_regv_%s->regv[%d][%d].ea0br = %s[%d];\n", id[current_prefix].name, last_col, last_row, id[src_hash].name, src_sidx);
        }
        else {
          if (bus[last_row][last_col].ea1brv) {
            printf("in %s: [%d][%d] ITYPE_MO4/ITYPE_MOP cannot find empty reg for RTYPE_BASE %s (may conflict with drain)\n", id[current_prefix].name, last_row, last_col, id[src_hash].name);
            exit(1);
          }
          bus[last_row][last_col].ea1brv = src_type;
          bus[last_row][last_col].ea1brh = src_hash;
          bus[last_row][last_col].ea1drv = src_type;
          bus[last_row][last_col].ea1drh = src_hash;
          if (src_sidx < 0)
            fprintf(ofile, "\temax5_regv_%s->regv[%d][%d].ea1br = %s;\n", id[current_prefix].name, last_col, last_row, id[src_hash].name);
          else
            fprintf(ofile, "\temax5_regv_%s->regv[%d][%d].ea1br = %s[%d];\n", id[current_prefix].name, last_col, last_row, id[src_hash].name, src_sidx);
        }
        break;
      case RTYPE_OFFS: /* prefetch/drain������ˤ���ѡ��ͤ�,�Х��ȥ��ɥ쥹��64bit*4��1ñ��,¨��32. N+1�󻲾Ȥ�,align����Ƥ��ʤ����Ǥ�FSM��Ĵ����*/
        if (reg_loc==0) {
          if (bus[last_row][last_col].ea0orv) {
            printf("in %s: [%d][%d] ITYPE_MO4/ITYPE_MOP cannot find empty reg for RTYPE_OFFS %s (may conflict with prefetch)\n", id[current_prefix].name, last_row, last_col, id[src_hash].name);
            exit(1);
          }
          bus[last_row][last_col].ea0orv = src_type;
          bus[last_row][last_col].ea0orh = src_hash;
          if (src_sidx < 0)
            fprintf(ofile, "\temax5_regv_%s->regv[%d][%d].ea0or = %s;\n", id[current_prefix].name, last_col, last_row, id[src_hash].name);
          else
            fprintf(ofile, "\temax5_regv_%s->regv[%d][%d].ea0or = %s[%d];\n", id[current_prefix].name, last_col, last_row, id[src_hash].name, src_sidx);
        }
        else {
          if (bus[last_row][last_col].ea1orv) {
            printf("in %s: [%d][%d] ITYPE_MO4/ITYPE_MOP cannot find empty reg for RTYPE_OFFS %s (may conflict with drain)\n", id[current_prefix].name, last_row, last_col, id[src_hash].name);
            exit(1);
          }
          bus[last_row][last_col].ea1orv = src_type;
          bus[last_row][last_col].ea1orh = src_hash;
          if (src_sidx < 0)
            fprintf(ofile, "\temax5_regv_%s->regv[%d][%d].ea1or = %s;\n", id[current_prefix].name, last_col, last_row, id[src_hash].name);
          else
            fprintf(ofile, "\temax5_regv_%s->regv[%d][%d].ea1or = %s[%d];\n", id[current_prefix].name, last_col, last_row, id[src_hash].name, src_sidx);
        }
        break;
      }
    }
    else { /* (insn_type == ITYPE_WHILE || insn_type == ITYPE_CEX || insn_type == ITYPE_EX4 || insn_type == ITYPE_EXE) */
      h = (last_row+EMAX_DEPTH-1)%EMAX_DEPTH; /* ľ���ʽ���BR[][][0-3]�ζ�����õ��,ARM��ľ�ܥ��å� */
      /* find same BR1 */
      for (j=0; j<EMAX_WIDTH; j++) {
        for (k=0; k<UNIT_WIDTH; k++) {
          if (bus[h][j].br[k].v==src_type && bus[h][j].br[k].h==src_hash && bus[h][j].br[k].s==src_sidx) /* already set */
            return; /* found & do nothing */
        }
      }
      /* find empty BR1 */
      for (j=0; j<EMAX_WIDTH; j++) {
        for (k=0; k<UNIT_WIDTH; k++) {
          if (k==2 && bus[h][j].exdrv && (bus[h][j].exdrh != src_hash))
            continue; /* ������ AR->EXDR->BR���¤�BR[2]����Ѥ����ǽ��������Τ������򤱤� ������ */
          if (!bus[h][j].br[k].v) { /* empty BR1 found */
            bus[h][j].br[k].v = src_type;
            bus[h][j].br[k].h = src_hash;
            bus[h][j].br[k].s = src_sidx;
            /* generate C-code to copy C-var to emax5_xx_regv[x][y].xxx before all EMAX5 code */
            if (src_sidx < 0)
              fprintf(ofile, "\temax5_regv_%s->regv[%d][%d].br[%d] = %s;\n", id[current_prefix].name, j, h, k, id[src_hash].name);
            else
              fprintf(ofile, "\temax5_regv_%s->regv[%d][%d].br[%d] = %s[%d];\n", id[current_prefix].name, j, h, k, id[src_hash].name, src_sidx);
            return; /* generate ARM->BR */
          }
        }
      }
      printf("in %s: [%d][%d] cannot find BR1 for %s\n", id[current_prefix].name, last_row, last_col, id[src_hash].name);
      exit(1);
    }
  }
  else { /* initialized by previous row (T_ALRNO, T_BDRNO, T_VARIABLE) */
    h = id[src_hash].row; /* �����ʤΤ��о� */
    /* ������ < last_row ���� src=AR�ʤ鳫���ʤ�BR�ޤǻ��äƤ��� */
    if (h < last_row) {
      if (id[src_hash].itype == ITYPE_EX4) { /* Ʊ��UNIT��TR�˽���ľ����BR�� */
        /* find same TR4+BR4 */
        for (j=0; j<EMAX_WIDTH; j++) {
          for (k=0; k<UNIT_WIDTH; k++) {
            if (!(bus[h][j].tr[k].v==src_type && bus[h][j].tr[k].h==src_hash && bus[h][j].tr[k].s==k
               && bus[h][j].br[k].v==src_type && bus[h][j].br[k].h==src_hash && bus[h][j].br[k].s==k)) /* miss */
              break;
          }
          if (k >= UNIT_WIDTH)
            goto srp_ar_br_ready; /* found & proceed */
        }
        /* find empty TR4+BR4 */
        for (j=0; j<EMAX_WIDTH; j++) {
#if 1
	  /* LMM-buffering�Τ���ˤϡ�����REG��LMP�о�UNIT�˺��ߤ��Ƥϥ��� */
          if (lmmi[j][h].v && !lmmi[j][h].rw && lmmi[j][h].p) /* conflict with lmm pload */
            continue;
#endif
          for (k=0; k<UNIT_WIDTH; k++) {
            if (bus[h][j].tr[k].v || bus[h][j].br[k].v) /* inuse */
              break;
          }
          if (k >= UNIT_WIDTH) { /* empty TR4+BR4 found */
            for (k=0; k<UNIT_WIDTH; k++) {
              bus[h][j].tr[k].v = src_type;
              bus[h][j].tr[k].h = src_hash;
              bus[h][j].tr[k].s = k;
              bus[h][j].br[k].v = src_type;
              bus[h][j].br[k].h = src_hash;
              bus[h][j].br[k].s = k;
            }
            conf[j][h].cdw2.brs0 = 2; /* 2:tr0 */
            conf[j][h].cdw2.brs1 = 2; /* 2:tr1 */
            conf[j][h].cdw2.brs2 = 2; /* 2:tr2 */
            conf[j][h].cdw2.brs3 = 2; /* 2:tr3 */
            goto srp_ar_br_ready; /* found & proceed */
          }
        }
        printf("in %s: [%d][%d] cannot find TR4+BR4 for %s\n", id[current_prefix].name, last_row, last_col, id[src_hash].name);
        exit(1);
      }
      else if (id[src_hash].itype == ITYPE_EXE) { /* �ѿ�������EXE�黻��̤ξ�硤��EXE��EXDR���ͳ��BR[2]����³ */
        /* find same BR[2] */
        j = id[src_hash].col; /* ������ id[src_hash].col�λ��Ȳս�Ϥ����Τߡ�ITYPE_EXE�ξ��,VAR[c],AR[r][c]���Ф���,j=-1 (Ʊ��Ԥ�ʣ��) */
        if (j<0)        /* exe->&VAR�ξ��,j=last_col�����åȤ���Ƥ��� */
          j = src_sidx; /* exe->VAR[c],AR[r][c]��Х�ǻȤ����,j=-1�����åȤ���Ƥ��� */
        /* printf("h=%d j=%d name=%s | v=%d srctype=%d h=%d srchash=%d s=%d srcidx=%d\n", h, j, id[src_hash].name, bus[h][j].br[2].v, src_type, bus[h][j].br[2].h, src_hash, bus[h][j].br[2].s, src_sidx);*/
        if (bus[h][j].br[2].v==src_type && bus[h][j].br[2].h==src_hash && bus[h][j].br[2].s==src_sidx) /* already set */
          goto srp_ar_br_ready; /* found & proceed */
        /* find empty BR[2] */
        if (!bus[h][j].br[2].v) { /* empty BR[2] found */
          bus[h][j].br[2].v = src_type;
          bus[h][j].br[2].h = src_hash;
          bus[h][j].br[2].s = src_sidx;
          conf[j][h].cdw2.brs2 = 3; /* 3:exdr */
          goto srp_ar_br_ready; /* found & proceed */
        }
        printf("in %s: [%d][%d] cannot find BR[2] for %s (BR[2] is occupied by %s)\n", id[current_prefix].name, last_row, last_col, id[src_hash].name, id[bus[h][j].br[2].h].name);
        exit(1);
      }
    }
srp_ar_br_ready:

    /* ���θ�,last_row���ʤޤ�ɬ�פʤ�,������BR��TR+BR�ˤ������ */
    for (h=id[src_hash].row+1; h<last_row; h++) { /* ����ޤ�,���¥쥸����tr[][]��br[][]����� */
      if (insn_type == ITYPE_EX4 || insn_type == ITYPE_MO4) { /* multiple use (ex4/store4) */
        /* find same TR4+BR4 */
        for (j=0; j<EMAX_WIDTH; j++) {
          for (k=0; k<UNIT_WIDTH; k++) {
            if (!(bus[h][j].tr[k].v==src_type && bus[h][j].tr[k].h==src_hash && bus[h][j].tr[k].s==k
               && bus[h][j].br[k].v==src_type && bus[h][j].br[k].h==src_hash && bus[h][j].br[k].s==k)) /* miss */
              break;
          }
          if (k >= UNIT_WIDTH)
            goto srp_tr_br_ready; /* found & proceed */
        }
        /* find empty TR4+BR4 */
        for (j=0; j<EMAX_WIDTH; j++) {
#if 1
	  /* LMM-buffering�Τ���ˤϡ�����REG��LMP�о�UNIT�˺��ߤ��Ƥϥ��� */
          if (lmmi[j][h].v && !lmmi[j][h].rw && lmmi[j][h].p) /* conflict with lmm pload */
            continue;
#endif
          for (k=0; k<UNIT_WIDTH; k++) {
            if (bus[h][j].tr[k].v || bus[h][j].br[k].v) /* inuse */
              break;
          }
          if (k >= UNIT_WIDTH) { /* empty TR4+BR4 found */
            for (k=0; k<UNIT_WIDTH; k++) {
              bus[h][j].tr[k].v = src_type;
              bus[h][j].tr[k].h = src_hash;
              bus[h][j].tr[k].s = k;
              bus[h][j].br[k].v = src_type;
              bus[h][j].br[k].h = src_hash;
              bus[h][j].br[k].s = k;
            }
            conf[j][h].cdw2.brs0 = 2; /* 2:tr0 */
            conf[j][h].cdw2.brs1 = 2; /* 2:tr1 */
            conf[j][h].cdw2.brs2 = 2; /* 2:tr2 */
            conf[j][h].cdw2.brs3 = 2; /* 2:tr3 */
            goto srp_tr_br_ready; /* found & proceed */
          }
        }
        printf("in %s: [%d][%d] cannot find TR4+BR4 for %s\n", id[current_prefix].name, last_row, last_col, id[src_hash].name);
        exit(1);
      }
      else { /* (insn_type == ITYPE_WHILE || insn_type == ITYPE_CEX || insn_type == ITYPE_EXE || insn_type == ITYPE_MOP) *//* single use */
        /* find same TR1+BR1 */
        for (j=0; j<EMAX_WIDTH; j++) {
          for (k=0; k<UNIT_WIDTH; k++) {
            if (bus[h][j].tr[k].v==src_type && bus[h][j].tr[k].h==src_hash && bus[h][j].tr[k].s==src_sidx
             && bus[h][j].br[k].v==src_type && bus[h][j].br[k].h==src_hash && bus[h][j].br[k].s==src_sidx) /* hit */
              goto srp_tr_br_ready; /* found & proceed */
          }
        }
        /* find empty TR1+BR1 */
        for (j=0; j<EMAX_WIDTH; j++) {
#if 1
	  /* LMM-buffering�Τ���ˤϡ�����REG��LMP�о�UNIT�˺��ߤ��Ƥϥ��� */
          if (lmmi[j][h].v && !lmmi[j][h].rw && lmmi[j][h].p) /* conflict with lmm pload */
            continue;
#endif
          for (k=0; k<UNIT_WIDTH; k++) {
            if (k==2 && bus[h][j].exdrv && (bus[h][j].exdrh != src_hash))
              continue; /* ������ AR->EXDR->BR���¤�BR[2]����Ѥ����ǽ��������Τ������򤱤� ������ */
            if (!bus[h][j].tr[k].v && !bus[h][j].br[k].v) { /* empty */
	      if (!bus[h][j].mw[k].v || search_prev_ar0_mw(h, j, k, bus[h][j].mw[k].v, bus[h][j].mw[k].h, bus[h][j].mw[k].s) >= 0) { /* ��unit���src�ξ���tr����̵�� */
		bus[h][j].tr[k].v = src_type;
		bus[h][j].tr[k].h = src_hash;
		bus[h][j].tr[k].s = src_sidx;
		bus[h][j].br[k].v = src_type;
		bus[h][j].br[k].h = src_hash;
		bus[h][j].br[k].s = src_sidx;
		switch (k) {
		case 0: conf[j][h].cdw2.brs0 = 2; /* 2:tr0 */ break;
		case 1: conf[j][h].cdw2.brs1 = 2; /* 2:tr1 */ break;
		case 2: conf[j][h].cdw2.brs2 = 2; /* 2:tr2 */ break;
		case 3: conf[j][h].cdw2.brs3 = 2; /* 2:tr3 */ break;
		}
		goto srp_tr_br_ready; /* found & proceed */
	      }
	      else  { /* ��unit��src������ȡ�tr����ͭ��Τ������ɬ�� */
		continue;
	      }
            }
          }
        }
        /* find same emergency bypass through EXE+EXDR+BR[2] */
        for (j=0; j<EMAX_WIDTH; j++) {
          if (!dec[h][j].dexu.op1 && dec[h][j].dexu.op2 == OP_OR && !dec[h][j].dexu.op3
           && bus[h][j].exdrv   == src_type && bus[h][j].exdrh   == src_hash && bus[h][j].exdrs   == src_sidx
           && bus[h][j].br[2].v == src_type && bus[h][j].br[2].h == src_hash && bus[h][j].br[2].s == src_sidx) {
            goto srp_tr_br_ready;
          }
        }
        /* find empty emergency bypass through EXE+EXDR+BR[2] */
        for (j=0; j<EMAX_WIDTH; j++) {
          if (!dec[h][j].dexu.op1 && !dec[h][j].dexu.op2 && !dec[h][j].dexu.op3
           && !bus[h][j].exdrv && !bus[h][j].br[2].v) {
            dec[h][j].dexu.op1  = OP_NOP;
            dec[h][j].dexu.op2  = OP_OR;
            dec[h][j].dexu.op3  = OP_NOP;
            dec[h][j].dexu.updt = 0;
            dec[h][j].dexu.ex1v = src_type;
            dec[h][j].dexu.ex1h = src_hash;
            dec[h][j].dexu.ex1s = src_sidx;
            dec[h][j].dexu.ex1e = EXP_H3210;
            dec[h][j].dexu.ex2v = T_NONE;
            dec[h][j].dexu.ex2h = -1;
            dec[h][j].dexu.ex2s = -1;
            dec[h][j].dexu.ex2e = 0;
            dec[h][j].dexu.ex3v = T_NONE;
            dec[h][j].dexu.ex3h = -1;
            dec[h][j].dexu.ex3s = -1;
            dec[h][j].dexu.ex3e = 0;
            dec[h][j].dexu.e2iv = T_IMMEDIATE;
            dec[h][j].dexu.e2ih = hash_reg_immediate(0LL);
            dec[h][j].dexu.e2is = 0; /* e2imm */
            dec[h][j].dexu.e3iv = T_NONE;
            dec[h][j].dexu.e3ih = -1;
            dec[h][j].dexu.e3is = 0; /* e3imm */
            dec[h][j].dexu.exdv = src_type;
            dec[h][j].dexu.exdh = src_hash;
            dec[h][j].dexu.exds = src_sidx;
            bus[h][j].exdrv     = src_type;
            bus[h][j].exdrh     = src_hash;
            bus[h][j].exdrs     = src_sidx;
            bus[h][j].br[2].v   = src_type;
            bus[h][j].br[2].h   = src_hash;
            bus[h][j].br[2].s   = src_sidx;
            conf[j][h].cdw2.brs2 = 3; /* 3:exdr */
            goto srp_tr_br_ready;
          }
        }
        printf("in %s: [%d][%d] cannot find TR1+BR1 for %s\n", id[current_prefix].name, last_row, last_col, id[src_hash].name);
        exit(1);
      }
srp_tr_br_ready:
      continue;
    }
  }
}

search_prev_br0(int row, int src_type, int src_hash, int src_sidx)
{
  /* return 0-3:br[][0].br[0-3], 4-7:br[][1].br[0-3], 8-11:br[][2].br[0-3], 12-15:br[][3].br[0-3] */
  /* return 0 and warn if not found */
  int i, j;

  row = (row+EMAX_DEPTH-1)%EMAX_DEPTH;
  if (src_type) {
    for (i=0; i<EMAX_WIDTH; i++) {
      for (j=0; j<UNIT_WIDTH; j++) {
        if (bus[row][i].br[j].v == src_type && bus[row][i].br[j].h == src_hash && bus[row][i].br[j].s == src_sidx)
          return (i*UNIT_WIDTH + j);
      }
    }
    printf("in %s: [%d][] cannot find source bus[%d][].br[] for %s sidx=%d (malfunction)\n", id[current_prefix].name, (row+1)%EMAX_DEPTH, row, id[src_hash].name, src_sidx);
  }
  return (0);
}

search_prev_ar0_tr(int row, int col, int pos, int src_type, int src_hash, int src_sidx)
{
  /* col=0 ... return 0:exdr0, 1:lmwd0, 2:ts0 */
  /* col=1 ... return 0:exdr1, 1:lmwd1, 2:ts1 */
  /* col=2 ... return 0:exdr2, 1:lmwd2, 2:ts2 */
  /* col=3 ... return 0:exdr3, 1:lmwd3, 2:ts3 */
  /* return -1 if not found */
  int i, j;

  /* tsX���Ѥ���������(retval=2)��search_prev_br0�θ������ */
  if (src_type) {
    if (bus[row][pos].exdrv       == src_type && bus[row][pos].exdrh       == src_hash && bus[row][pos].exdrs       == src_sidx) return (0); /* EX4->TR4->BR4 */
    if (bus[row][col].lmwd[pos].v == src_type && bus[row][col].lmwd[pos].h == src_hash && bus[row][col].lmwd[pos].s == src_sidx) return (1); /* LDDMQ */
    return (-1);
  }
  else
    return (0);
}

search_prev_ar0_mw(int row, int col, int pos, int src_type, int src_hash, int src_sidx)
{
  /* col=0 ... return 0:exdr, 1:exdr0, 2:ts0, 3:lmli0, 4:lmwd0, 5:lmri0 */
  /* col=1 ... return 0:exdr, 1:exdr1, 2:ts1, 3:lmli1, 4:lmwd1, 5:lmri1 */
  /* col=2 ... return 0:exdr, 1:exdr2, 2:ts2, 3:lmli2, 4:lmwd2, 5:lmri2 */
  /* col=3 ... return 0:exdr, 1:exdr3, 2:ts3, 3:lmli3, 4:lmwd3, 5:lmri3 */
  /* return -1 if not found */
  int i, j;

  /* tsX���Ѥ���������(retval=2)��search_prev_br0�θ������ */
  if (src_type) {
    if (bus[row][col].exdrv       == src_type && bus[row][col].exdrh       == src_hash && bus[row][col].exdrs       == src_sidx) return (0);
    if (bus[row][pos].exdrv       == src_type && bus[row][pos].exdrh       == src_hash && bus[row][pos].exdrs       == src_sidx) return (1);
    if (bus[row][col].lmli[pos].v == src_type && bus[row][col].lmli[pos].h == src_hash && bus[row][col].lmli[pos].s == src_sidx) return (3);
    if (bus[row][col].lmwd[pos].v == src_type && bus[row][col].lmwd[pos].h == src_hash && bus[row][col].lmwd[pos].s == src_sidx) return (4);
    if (bus[row][col].lmri[pos].v == src_type && bus[row][col].lmri[pos].h == src_hash && bus[row][col].lmri[pos].s == src_sidx) return (5);
    return (-1);
  }
  else
    return (0);
}

emit_emax5t(int type) /* 0:transaction */
{
  int i, j, l;

  for (i=0; i<=trans_pc; i++) {
    tconf[i].rw            = trans[i].rw;
    tconf[i].base_type     = trans[i].base_type;
    tconf[i].offset_type   = trans[i].offset_type;
    tconf[i].offset        = trans[i].offset;
    tconf[i].offset_suffix = trans[i].offset_suffix;
    tconf[i].offset_sll    = trans[i].offset_sll;
    tconf[i].op_type       = trans[i].op_type;
    tconf[i].op_val_type   = trans[i].op_val_type > 0;
    tconf[i].t_action_type = trans[i].t_action_type;
    tconf[i].t_action      = trans[i].t_action;
    tconf[i].f_action_type = trans[i].f_action_type;
    tconf[i].f_action      = trans[i].f_action;
    tconf[i].reg_type      = trans[i].reg_type;
    fprintf(ofile, "\t.word\t0x%08.8x /* tconf[%d].word0 */\n", *(Uint*)&tconf[i], i);
    if (trans[i].base_type == 2)
      fprintf(ofile, "%s\t.word\t0x%08.8x /* tconf[%d].base */\n", trans[i].base_symbol, trans[i].base_num, i);
    else
      fprintf(ofile, "\t.word\t0x%08.8x /* tconf[%d].base */\n", trans[i].base_num, i);
    if (trans[i].op_val_type == 2)
      fprintf(ofile, "%s\t.word\t0x%08.8x /* tconf[%d].op_val */\n", trans[i].op_val_symbol, trans[i].op_val_num, i);
    else
      fprintf(ofile, "\t.word\t0x%08.8x /* tconf[%d].op_val */\n", trans[i].op_val_num, i);
    if (trans[i].reg_type == 1)
      fprintf(ofile, "%s\t.word\t0x%08.8x /* tconf[%d].reg */\n", trans[i].reg_symbol, trans[i].reg_num, i);
    else
      fprintf(ofile, "\t.word\t0x%08.8x /* tconf[%d].reg */\n", trans[i].reg_num, i);
  }
}

emit_tgif(int i, int j)
{
  int k;
  int base_row = (i%16) * 540  + 300;
  int base_col = (i/16) * 2020 + ((EMAX_WIDTH-1)-j) * 500;
  int bro_x = base_col,     bro_y = base_row+10;
  int aro_x = base_col,     aro_y = base_row+210;
  int lmi_x = base_col,     lmi_y = base_row+280;
  int exb_x = base_col+70,  exb_y = base_row+160;
  int cxb_x = base_col+20,  cxb_y = base_row+160;
  int e0b_x = base_col+320, e0b_y = base_row+170;
  int e1b_x = base_col+200, e1b_y = base_row+170;
  int trb_x = base_col+60,  trb_y = base_row+350;
  int lmb_x = base_col+40,  lmb_y = base_row+380;
  int bri_x = base_col+40,  bri_y = base_row+530;

  for (k=0; k<EMAX_WIDTH*UNIT_WIDTH; k++)
    draw_bro(i, j, bro_x, bro_y, k);

  for (k=0; k<EMAX_WIDTH+1; k++)
    draw_aro(i, j, aro_x, aro_y, k);

  for (k=0; k<UNIT_WIDTH+1; k++)
    draw_lmi(i, j, lmi_x, lmi_y, k);

  draw_exe(exb_x, exb_y,
	   conf[j][i].cdw0.op1,    /*:  6; alu_opcd */
	   conf[j][i].cdw0.op2,    /*:  3; logical_opcd */
	   conf[j][i].cdw0.op3,    /*:  3; sft_opcd */
	   conf[j][i].cdw0.ex1brs, /*:  4; 0:br0_0, 1:br0_1, ... 15:3_3 */
	   conf[j][i].cdw0.ex1s,   /*:  1; 0:ex1brs, 1:exdr(self-loop) */
	   conf[j][i].cdw0.ex1exp, /*:  2; 0:--, 1:B5410, 2:B7632, 3:H3210 */
	   conf[j][i].cdw0.ex2brs, /*:  4; 0:br0_0, 1:br0_1, ... 15:3_3 */
	   conf[j][i].cdw0.ex2exp, /*:  2; 0:--, 1:B5410, 2:B7632, 3:H3210 */
	   conf[j][i].cdw0.ex3brs, /*:  4; 0:br0_0, 1:br0_1, ... 15:3_3 */
	   conf[j][i].cdw0.ex3exp, /*:  2; 0:--, 1:B5410, 2:B7632, 3:H3210 */
	   conf[j][i].cdw3.e2imm,  /*: 64; */
	   conf[j][i].cdw0.e2is,   /*:  2; 0:e2imm, 1:ex2, 2:ex3 */
	   conf[j][i].cdw0.e3imm,  /*:  E3IMMBITS; */
	   conf[j][i].cdw0.e3is    /*:  1; 0:e3imm, 1:ex3 */
	   );

  draw_cex(cxb_x, cxb_y,
	   conf[j][i].cdw1.cs0,    /*:  4; 0:br0_0, 1:br0_1, ... 15:3_3 */
	   conf[j][i].cdw1.cs1,    /*:  4; 0:br0_0, 1:br0_1, ... 15:3_3 */
	   conf[j][i].cdw1.cs2,    /*:  4; 0:br0_0, 1:br0_1, ... 15:3_3 */
	   conf[j][i].cdw1.cs3,    /*:  4; 0:br0_0, 1:br0_1, ... 15:3_3 */
	   conf[j][i].cdw1.cex_tab /*: 16; c3.c2.c1.c0���ȹ礻 (cop=NOP�ξ��,ffff) */
	                           /* 1111,1110,1101,1100,....,0001,0000 �γơ���0/1�������Ƥ�16bit����� */
	   );

  draw_ea0(e0b_x, e0b_y,
	   conf[j][i].cdw1.ea0op,  /*:  5; mem_opcd */
	   conf[j][i].cdw1.ea0bs,  /*:  2; 0:ea0br, 1:ea0dr(ea0br+self-loop), 2:eabbrs, 3:ea0dr(eabbrs+self-loop) */
	   conf[j][i].cdw1.ea0os,  /*:  1; 0:ea0or, 1:eaobrs */
	   conf[j][i].cdw1.ea0msk, /*:  4; 15:64bit, 13:word1, 12:word0, 11-8:half3-0, 7-0:byte7-0 of offset */
	   conf[j][i].cdw1.eabbrs, /*:  4; 0:br0_0, 1:br0_1, ... 15:3_3 */
	   conf[j][i].cdw1.eaobrs  /*:  4; 0:br0_0, 1:br0_1, ... 15:3_3 */
	   );

  draw_ea1(e1b_x, e1b_y,
	   conf[j][i].cdw1.ea1op,  /*:  5; mem_opcd */
	   conf[j][i].cdw1.ea1bs,  /*:  2; 0:ea1br, 1:ea1dr(ea1br+self-loop), 2:eabbrs, 3:ea1dr(self-loop) */
	   conf[j][i].cdw1.ea1os,  /*:  1; 0:ea1or, 1:eaobrs */
	   conf[j][i].cdw1.ea1msk, /*:  4; 15:64bit, 13:word1, 12:word0, 11-8:half3-0, 7-0:byte7-0 of offset */
	   conf[j][i].cdw1.eabbrs, /*:  4; 0:br0_0, 1:br0_1, ... 15:3_3 */
	   conf[j][i].cdw1.eaobrs  /*:  4; 0:br0_0, 1:br0_1, ... 15:3_3 */
	   );

  draw_trx(trb_x, trb_y,
	   bus[i][j].tr[0].v,
	   bus[i][j].tr[1].v,
	   bus[i][j].tr[2].v,
	   bus[i][j].tr[3].v,
	   conf[j][i].cdw2.ts0,    /*:  4; 0:br0_0, 1:br0_1, ... 15:br3_3 */
	   conf[j][i].cdw2.ts1,    /*:  4; 0:br0_0, 1:br0_1, ... 15:br3_3 */
	   conf[j][i].cdw2.ts2,    /*:  4; 0:br0_0, 1:br0_1, ... 15:br3_3 */
	   conf[j][i].cdw2.ts3,    /*:  4; 0:br0_0, 1:br0_1, ... 15:br3_3 */
	   conf[j][i].cdw2.trs0,   /*:  2; 0:exdr0, 1:lmwd0, 2:ts0 */
	   conf[j][i].cdw2.trs1,   /*:  2; 0:exdr1, 1:lmwd1, 2:ts1 */
	   conf[j][i].cdw2.trs2,   /*:  2; 0:exdr2, 1:lmwd2, 2:ts2 */
	   conf[j][i].cdw2.trs3    /*:  2; 0:exdr3, 1:lmwd3, 2:ts3 */
	   );

  draw_lmx(lmb_x, lmb_y,
	   conf[j][i].cdw1.ea0op,  /*:  5; mem_opcd */
	   conf[j][i].cdw2.mwsa,   /*:  2; 0:off, 1:lmlia,2:lmwa,3:lmria  *//* for STATUS_EXEC+lmp */
	   conf[j][i].cdw2.mws0,   /*:  3; 0:exdr,1:exdr0,2:ts0, 3:lmli0, 4:lmwd0, 5:lmri0 */
	   conf[j][i].cdw2.mws1,   /*:  3; 0:exdr,1:exdr1,2:ts1, 3:lmli1, 4:lmwd1, 5:lmri1 */
	   conf[j][i].cdw2.mws2,   /*:  3; 0:exdr,1:exdr2,2:ts2, 3:lmli2, 4:lmwd2, 5:lmri2 */
	   conf[j][i].cdw2.mws3,   /*:  3; 0:exdr,1:exdr3,2:ts3, 3:lmli3, 4:lmwd3, 5:lmri3 */
	   conf[j][i].cdw2.xmws    /*:  2; 0:off, 1:lmli, 2:lmwd,3:lmri *//* for STATUS_LOAD */
	   );

  draw_bri(bri_x, bri_y,
	   conf[j][i].cdw1.ea0op,  /*:  5; mem_opcd */
	   conf[j][i].cdw1.ea1op,  /*:  5; mem_opcd */
	   conf[j][i].cdw2.brs0,   /*:  2; 0:off, 1:mr10, 2:tr0, 3:mr0  */
	   conf[j][i].cdw2.brs1,   /*:  2; 0:off, 1:mr11, 2:tr1, 3:mr1  */
	   conf[j][i].cdw2.brs2,   /*:  2; 0:off, 1:mr12, 2:tr2, 3:exdr */
	   conf[j][i].cdw2.brs3,   /*:  2; 0:off, 1:mr13, 2:tr3         */
	   bus[i][j].br[0].v,
	   bus[i][j].br[0].h,
	   bus[i][j].br[1].v,
	   bus[i][j].br[1].h,
	   bus[i][j].br[2].v,
	   bus[i][j].br[2].h,
	   bus[i][j].br[3].v,
	   bus[i][j].br[3].h
	   );

  draw_lmr(bri_x, bri_y,
	   bus[i][j].lmrd[0].v,
	   bus[i][j].lmrd[1].v,
	   bus[i][j].lmrd[2].v,
	   bus[i][j].lmrd[3].v
	   );
}

/*    0   50   100  150  200  250  300  350  400  450  500 */
/*   0+----+----+----+----+----+----+----+----+----+----+  */
/*  10  |||| :  |  |  |  :---------| :         | :   BOBASE*/
/*  15  |||| :  |  |  |  :---------| :         | :         */
/*  20  |||| :  |  |  |  :---------| :         | :         */
/*  25  |||| :  |  |  |  :---------| :         | :         */
/*  30  |||| :  |  |  |  :---------| :         | :         */
/*  35  |||| :  |  |  |  :---------| :         | :         */
/*  40  |||| :  |  |  |  :---------| :         | :         */
/*  45  |||| :  |  |  |  :---------| :         | :         */
/*  50  |||| :  |  |  |  :---------| :         | :         */
/*  55  |||| :  |  |  |  :---------| :         | :         */
/*  60  |||| :  |  |  |  :---------| :         | :         */
/*  65  |||| :  |  |  |  :---------| :         | :         */
/*  70  |||| :  |  |  |  :---------| :         | :         */
/*  75  |||| :  |  |  |  :---------| :         | :         */
/*  80  |||| :  |  |  |  :---------| :         | :         */
/*  85  |||| :  |  |  |  :---------| :         | :         */
/*  90  |||| :  |  |  |  :         | :         | :         */
/* 100  |||| :  |  |  |  :   +-----*-----+     | :         */
/* 110  |||| :  |  |  |  :   |     +-----------+ :         */
/* 120  |||| :  |  |  |  :   |     | :   |     | :         */
/* 130  |||| :  |  |  |  :+---+ +---+:+---+ +---+:         */
/* 140  |||| :  |  |  |  :+-*-+ +-*-+:+---+ +---+:         */
/* 150  |||| :  -  -  -  :  ||    || :  ||    || :         */
/* 160  +--+ +-----------+  --    -- :  --    -- :   EXBASE*/
/* 170  |  | :\ A       /:+---------+:+---------+:         */
/* 180  |  | : \|      / : \A      / : \A      / :         */
/* 190  +--+ |  +--*--+  |  +--*--+  |  +--*--+  |         */
/* 200       |  |  |     |  |  |     |  |  |     |         */
/* 210   ----|-----------|-----------|----------*|-  AOBASE*/
/* 215   ----|-----------|----------*|----------||-        */
/* 220   ----|----------*|----------||----------||-        */
/* 225   ---*|-----*----||----------||----------||-        */
/* 230   --*||--|--*---*||---------*||---------*||-        */
/* 260     |||  |  |   |||  |  |   |||  |  |   |||         */
/* 270     |||+<|  |   |||+<|  |+  |||+<|  |+  |||+<       */
/* 280   --||||--------||||--------||||------**|||*  LIBASE*/
/* 285   --||||--------||||------**|||*------||||||        */
/* 290   --||||------**|||*------||||||------||||||        */
/* 295   **|||*------||||||------||||||------||||||        */
/* 300   ||||||------||||||------||||||-----*||||||        */
/* 310   |||||| |  | |||||| |  |||||||| |  ||||||||        */
/* 320   ****** |  | ****** |  ||****** |  ||******        */
/* 330     | || |  |   | || |  ||  | || |  ||  | ||        */
/* 340     | ** |  |   | ** |  ||  | ** |  ||  | **        */
/* 350     |+*+ | +*+  |+*+ | +*+  |+*+ | +*+  |+*+  TRBASE*/
/* 360     |+*+ | +*+  |+*+ | +*+  |+*+ | +*+  |+*+        */
/* 370     | |  +--*   | |  +--*   | |  +--*   | |         */
/* 380  : +*----+  |  +*----+ +*+ +*----+ +*+ +*----+LMBASE*/
/* 390  : +-----+  |  +-----+ +-+ +-----+ +-+ +-----+      */
/* 400       |     |     |     |     |     |     |         */
/* 410    +-----+  |  +-----+  |  +-----+  |  +-----+      */
/* 420    |-----|  |  |-----|  |  |-----|  |  |-----|      */
/* 430    |-----|  |  |-----|  |  |-----|  |  |-----|      */
/* 440    +---**+  |  +---**+  |  +---**+  |  +---**+      */
/* 450       |||   +-+   |||   |     ||+-------++||+       */
/* 460       |||     |   ||+---------||-------+||||        */
/* 470       ||+-----|-- ||----------||------+|||||        */
/* 480       ||      |   |*-------++-|*    | ||||||        */
/* 500       |*------|---||------+||+||------|||||*        */
/* 510       ||      *--*||    +>*--*||    +>*--*||        */
/* 520       |+>        ||+>        ||+>   |    ||+>       */
/* 530    +--**-+     +-***-+     +-***-+  V  +-***-+BIBASE*/
/* 540    +-----+     +-----+     +-----+     +-----+      */

draw_bro(int i, int j, int bro_x, int bro_y, int num)
{
  int col, thi;
  i = (i+EMAX_DEPTH-1)%EMAX_DEPTH;

  /* BR0-0..3-3 */
  switch (bus[i][num/UNIT_WIDTH].br[num%UNIT_WIDTH].v) {
  case 0: /* T_NONE */
    col=0; /*black*/
    thi=1;
    break;
  case 1: /* T_IMMEDIATE */
    col=4; /*blue*/
    thi=5;
    break;
  case 2: /* T_EXRNO */
    col=5; /*magenta*/
    thi=5;
    break;
  case 3: /* T_ALRNO */
    col=3; /*yellow*/
    thi=5;
    break;
  case 4: /* T_BDRNO */
    col=1; /*red*/
    thi=5;
    break;
  case 5: /* T_VARIABLE */
    col=2; /*green*/
    thi=5;
    break;
  default:
    col=6; /*cyan*/
    thi=5;
    break;
  }
  draw_line(bro_x,  bro_y+num*5, bro_x+500,  bro_y+num*5, thi, col);
} 

draw_aro(int i, int j, int aro_x, int aro_y, int num)
{
  int col, thi;

  /* AR0..EXD */
  if (num < EMAX_WIDTH) {
    switch (bus[i][num].exdrv) {
    case 0: /* T_NONE */
      col=0; /*black*/
      thi=1;
      break;
    case 1: /* T_IMMEDIATE */
      col=4; /*blue*/
      thi=5;
      break;
    case 2: /* T_EXRNO */
      col=5; /*magenta*/
    thi=5;
    break;
    case 3: /* T_ALRNO */
      col=3; /*yellow*/
      thi=5;
      break;
    case 4: /* T_BDRNO */
      col=1; /*red*/
      thi=5;
      break;
    case 5: /* T_VARIABLE */
      col=2; /*green*/
      thi=5;
      break;
    default:
      col=6; /*cyan*/
      thi=5;
      break;
    }
    draw_line(aro_x,  aro_y+num*5, aro_x+500,  aro_y+num*5, thi, col);
  }
  else {
    switch (bus[i][j].exdrv) {
    case 0: /* T_NONE */
      col=0; /*black*/
      thi=1;
      break;
    case 1: /* T_IMMEDIATE */
      col=4; /*blue*/
      thi=5;
      break;
    case 2: /* T_EXRNO */
      col=5; /*magenta*/
    thi=5;
    break;
    case 3: /* T_ALRNO */
      col=3; /*yellow*/
      thi=5;
      break;
    case 4: /* T_BDRNO */
      col=1; /*red*/
      thi=5;
      break;
    case 5: /* T_VARIABLE */
      col=2; /*green*/
      thi=5;
      break;
    default:
      col=6; /*cyan*/
      thi=5;
      break;
    }
    draw_line(aro_x+30, aro_y+num*5, aro_x+470,  aro_y+num*5, thi, col);
  }
} 

draw_lmi(int i, int j, int lmi_x, int lmi_y, int num)
{
  int col, thi;
  int lmiall;

  /* LMI */
  if (num < UNIT_WIDTH) { /* lmwd */
    lmiall = bus[i][j].lmwd[num].v
           | bus[i][j].lmli[num].v | bus[i][j].lmlo[num].v
           | bus[i][j].lmri[num].v | bus[i][j].lmro[num].v;
    switch (lmiall) {
    case 0: /* T_NONE */
      col=0; /*black*/
      thi=1;
      break;
    case 1: /* T_IMMEDIATE */
      col=4; /*blue*/
      thi=5;
      break;
    case 2: /* T_EXRNO */
      col=5; /*magenta*/
      thi=5;
      break;
    case 3: /* T_ALRNO */
      col=3; /*yellow*/
      thi=5;
      break;
    case 4: /* T_BDRNO */
      col=1; /*red*/
      thi=5;
      break;
    case 5: /* T_VARIABLE */
      col=2; /*green*/
      thi=5;
      break;
    default:
      col=6; /*cyan*/
      thi=5;
      break;
    }
    draw_line(lmi_x,  lmi_y+num*5, lmi_x+500,  lmi_y+num*5, thi, col);
  }
  else { /* lmwa */
    lmiall = bus[i][j].lmwd[0].v
           | bus[i][j].lmli[0].v | bus[i][j].lmlo[0].v
           | bus[i][j].lmri[0].v | bus[i][j].lmro[0].v;
    switch (lmiall) {
    case 0: /* T_NONE */
      col=0; /*black*/
      thi=1;
      break;
    case 1: /* T_IMMEDIATE */
      col=4; /*blue*/
      thi=5;
      break;
    case 2: /* T_EXRNO */
      col=5; /*magenta*/
      thi=5;
      break;
    case 3: /* T_ALRNO */
      col=3; /*yellow*/
      thi=5;
      break;
    case 4: /* T_BDRNO */
      col=1; /*red*/
      thi=5;
      break;
    case 5: /* T_VARIABLE */
      col=2; /*green*/
      thi=5;
      break;
    default:
      col=6; /*cyan*/
      thi=5;
      break;
    }
    draw_line(lmi_x,  lmi_y+num*5, lmi_x+500,  lmi_y+num*5, thi, col);
  }
}

draw_exe(int exb_x, int exb_y,
	 int op1,    /*:  6; alu_opcd */
	 int op2,    /*:  3; logical_opcd */
	 int op3,    /*:  3; sft_opcd */
	 int ex1brs, /*:  4; 0:br0_0, 1:br0_1, ... 15:3_3 */
	 int ex1s,   /*:  1; 0:ex1brs, 1:exdr(self-loop) */
	 int ex1exp, /*:  2; 0:--, 1:B5410, 2:B7632, 3:H3210 */
	 int ex2brs, /*:  4; 0:br0_0, 1:br0_1, ... 15:3_3 */
	 int ex2exp, /*:  2; 0:--, 1:B5410, 2:B7632, 3:H3210 */
	 int ex3brs, /*:  4; 0:br0_0, 1:br0_1, ... 15:3_3 */
	 int ex3exp, /*:  2; 0:--, 1:B5410, 2:B7632, 3:H3210 */
	 Ull e2imm,  /*: 64; */
	 int e2is,   /*:  2; 0:e2imm, 1:ex2, 2:ex3 */
	 int e3imm,  /*:  E3IMMBITS; */
	 int e3is    /*:  1; 0:e3imm, 1:ex3 */
	 )
{
#define EXLABELMAX 30
  char opcd[EXLABELMAX];
  int col, thi;

  /* ALU */
  if (op1 || op2 || op3) {
    col=5; /*magenta*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_line(exb_x+20,  exb_y-10, exb_x+40,  exb_y-10, thi, col);
  draw_line(exb_x+50,  exb_y-10, exb_x+70,  exb_y-10, thi, col);
  draw_line(exb_x+80,  exb_y-10, exb_x+100, exb_y-10, thi, col);
  draw_line(exb_x,     exb_y,    exb_x+120, exb_y,    thi, col);
  draw_line(exb_x+120, exb_y,    exb_x+90,  exb_y+30, thi, col);
  draw_line(exb_x+90,  exb_y+30, exb_x+30,  exb_y+30, thi, col);
  draw_line(exb_x+30,  exb_y+30, exb_x,     exb_y,    thi, col);
  snprintf(opcd, EXLABELMAX, "%02.2x-%01.1x-%01.1x", op1, op2, op3);
  draw_text(exb_x+35, exb_y+15, opcd, 1, col);
  if (e2is == 0) {
    snprintf(opcd, EXLABELMAX, "%08.8x", (Uint)(e2imm>>32));
    draw_text(exb_x-50, exb_y+45, opcd, 1, col);
    snprintf(opcd, EXLABELMAX, "%08.8x", (Uint)e2imm);
    draw_text(exb_x+35, exb_y+45, opcd, 1, col);
  }
  if (e3is == 0) {
    snprintf(opcd, EXLABELMAX, "%08.8x", e3imm);
    draw_text(exb_x+35, exb_y+30, opcd, 1, col);
  }
  draw_line (exb_x+60, exb_y+30,              exb_x+60, exb_y+190,     thi, col);
  draw_box  (exb_x+50, exb_y+190,             exb_x+70, exb_y+200,     thi, col);

  /* SRC1 */
  if (op1 || op2 || op3) {
    col=5; /*magenta*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_arrow(exb_x+30, exb_y-160+ex1brs*5+10, exb_x+30, exb_y-160+150, thi, col);
  if (ex1s) { /* feedback-loop */
    col=5; /*magenta*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_line (exb_x+60, exb_y+200,             exb_x+60, exb_y+210,     thi, col);
  draw_line (exb_x+60, exb_y+210,             exb_x+30, exb_y+210,     thi, col);
  draw_arrow(exb_x+30, exb_y+210,             exb_x+30, exb_y-10,      thi, col);
  /* SRC2 */
  if (op1 || op2 || op3) {
    col=5; /*magenta*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_arrow(exb_x+60, exb_y-160+ex2brs*5+10, exb_x+60, exb_y-160+150, thi, col);
  /* SRC3 */
  if (op1 || op2 || op3) {
    col=5; /*magenta*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_arrow(exb_x+90, exb_y-160+ex3brs*5+10, exb_x+90, exb_y-160+150, thi, col);
}

draw_cex(int cxb_x, int cxb_y,
	 int cs0,    /*:  4; 0:br0_0, 1:br0_1, ... 15:3_3 */
	 int cs1,    /*:  4; 0:br0_0, 1:br0_1, ... 15:3_3 */
	 int cs2,    /*:  4; 0:br0_0, 1:br0_1, ... 15:3_3 */
	 int cs3,    /*:  4; 0:br0_0, 1:br0_1, ... 15:3_3 */
	 int cex_tab /*: 16; c3.c2.c1.c0���ȹ礻 (cop=NOP�ξ��,ffff) */
	             /* 1111,1110,1101,1100,....,0001,0000 �γơ���0/1�������Ƥ�16bit����� */
	 )
{
#define CXLABELMAX 30
  char opcd[CXLABELMAX];
  int col, thi;

  /* CEX */
  if (cex_tab != 0xffff) {
    col=2; /*green*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_box  (cxb_x-10, cxb_y, cxb_x+40, cxb_y+30, thi, col);
  snprintf(opcd, CXLABELMAX, "%04.4x", cex_tab);
  draw_text(cxb_x, cxb_y+20, opcd, 1, 0);

  /* SRC1 */
  if (cex_tab != 0xffff) {
    col=2; /*green*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_arrow(cxb_x,    cxb_y-160+cs0*5+10, cxb_x,    cxb_y-5,  thi, col);
  /* SRC2 */
  if (cex_tab != 0xffff) {
    col=2; /*green*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_arrow(cxb_x+10, cxb_y-160+cs1*5+10, cxb_x+10, cxb_y-5, thi, col);
  /* SRC3 */
  if (cex_tab != 0xffff) {
    col=2; /*green*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_arrow(cxb_x+20, cxb_y-160+cs2*5+10, cxb_x+20, cxb_y-5, thi, col);
  /* SRC4 */
  if (cex_tab != 0xffff) {
    col=2; /*green*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_arrow(cxb_x+30, cxb_y-160+cs3*5+10, cxb_x+30, cxb_y-5, thi, col);
}

draw_ea0(int e0b_x, int e0b_y,
	 int ea0op,  /*:  5; mem_opcd */
	 int ea0bs,  /*:  2; 0:ea0br, 1:ea0dr(ea0br+self-loop), 2:eabbrs, 3:ea0dr(eabbrs+self-loop) */
	 int ea0os,  /*:  1; 0:ea0or, 1:eaobrs */
	 int ea0msk, /*:  4; 15:64bit, 13:word1, 12:word0, 11-8:half3-0, 7-0:byte7-0 of offset */
	 int eabbrs, /*:  4; 0:br0_0, 1:br0_1, ... 15:3_3 */
	 int eaobrs  /*:  4; 0:br0_0, 1:br0_1, ... 15:3_3 */
	 )
{
#define E0LABELMAX 30
  char opcd[E0LABELMAX];
  int col, thi;
  int ea0singleload = (ea0op && (ea0op <= OP_LDUBR));

  /* EA0 */
  if (ea0op) {
    col=1; /*red*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_line(e0b_x+10,  e0b_y-10, e0b_x+30,  e0b_y-10, thi, col);
  draw_line(e0b_x+70,  e0b_y-10, e0b_x+90,  e0b_y-10, thi, col);
  draw_line(e0b_x,     e0b_y,    e0b_x+100, e0b_y,    thi, col);
  draw_line(e0b_x+100, e0b_y,    e0b_x+80,  e0b_y+20, thi, col);
  draw_line(e0b_x+80,  e0b_y+20, e0b_x+20,  e0b_y+20, thi, col);
  draw_line(e0b_x+20,  e0b_y+20, e0b_x,     e0b_y,    thi, col);
  snprintf(opcd, E0LABELMAX, "%02.2x", ea0op);
  draw_text(e0b_x+35, e0b_y+15, opcd, 1, col);
  draw_line (e0b_x+50, e0b_y+20,              e0b_x+50, e0b_y+180,     thi, col);
  draw_box  (e0b_x+40, e0b_y+180,             e0b_x+60, e0b_y+190,     thi, col);
  draw_line (e0b_x+50, e0b_y+190,             e0b_x+50, e0b_y+210,     thi, col);
  draw_box  (e0b_x+40, e0b_y+210,             e0b_x+60, e0b_y+220,     thi, col);
  if (ea0singleload) {
    col=4; /*blue*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_line (e0b_x+55, e0b_y+190,             e0b_x+55, e0b_y+340,     thi, col);
  draw_arrow(e0b_x+55, e0b_y+340,             e0b_x+65, e0b_y+340,     thi, col);
  draw_line (e0b_x+65, e0b_y+340,             e0b_x+100,e0b_y+340,     thi, col);

  /* SRC1 */
  if (ea0op && !(ea0bs & 2)) { /* ea0br */
    col=1; /*red*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_box  (e0b_x,    e0b_y-40, e0b_x+40, e0b_y-30, thi, col);
  draw_arrow(e0b_x+20, e0b_y-30, e0b_x+20, e0b_y-10, thi, col);
  if (ea0op && (ea0bs & 2)) { /* eabbrs */
    col=1; /*red*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_line (e0b_x-30, e0b_y-170+eabbrs*5+10, e0b_x-30, e0b_y-70, thi, col);
  draw_line (e0b_x-30, e0b_y-70,              e0b_x+30, e0b_y-70, thi, col);
  draw_arrow(e0b_x+30, e0b_y-70,              e0b_x+30, e0b_y-10, thi, col);
  if (ea0bs & 1) { /* feedback-loop */
    col=1; /*red*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_line (e0b_x+50, e0b_y+190,             e0b_x+50, e0b_y+200,     thi, col);
  draw_line (e0b_x+50, e0b_y+200,             e0b_x+20, e0b_y+200,     thi, col);
  draw_arrow(e0b_x+20, e0b_y+200,             e0b_x+20, e0b_y-10,      thi, col);
  /* SRC2 */
  if (ea0op && !(ea0os & 1)) { /* ea0or */
    col=1; /*red*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_box  (e0b_x+60, e0b_y-40, e0b_x+100, e0b_y-30, thi, col);
  draw_arrow(e0b_x+80, e0b_y-30, e0b_x+80,  e0b_y-10, thi, col);
  if (ea0op && (ea0os & 1)) { /* eaobrs */
    col=1; /*red*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_line (e0b_x+90, e0b_y-170+eaobrs*5+10, e0b_x+90, e0b_y-70, thi, col);
  draw_arrow(e0b_x+90, e0b_y-70,              e0b_x+90, e0b_y-10, thi, col);
}

draw_ea1(int e1b_x, int e1b_y,
	 int ea1op,  /*:  5; mem_opcd */
	 int ea1bs,  /*:  2; 0:ea1br, 1:ea1dr(ea1br+self-loop), 2:eabbrs, 3:ea1dr(self-loop) */
	 int ea1os,  /*:  1; 0:ea1or, 1:eaobrs */
	 int ea1msk, /*:  4; 15:64bit, 13:word1, 12:word0, 11-8:half3-0, 7-0:byte7-0 of offset */
	 int eabbrs, /*:  4; 0:br0_0, 1:br0_1, ... 15:3_3 */
	 int eaobrs  /*:  4; 0:br0_0, 1:br0_1, ... 15:3_3 */
	 )
{
#define E1LABELMAX 30
  char opcd[E1LABELMAX];
  int col, thi;
  int ea1singleload = (ea1op && (ea1op <= OP_LDUBR));

  /* EA1 */
  if (ea1op) {
    col=4; /*blue*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_line(e1b_x+10,  e1b_y-10, e1b_x+30,  e1b_y-10, thi, col);
  draw_line(e1b_x+70,  e1b_y-10, e1b_x+90,  e1b_y-10, thi, col);
  draw_line(e1b_x,     e1b_y,    e1b_x+100, e1b_y,    thi, col);
  draw_line(e1b_x+100, e1b_y,    e1b_x+80,  e1b_y+20, thi, col);
  draw_line(e1b_x+80,  e1b_y+20, e1b_x+20,  e1b_y+20, thi, col);
  draw_line(e1b_x+20,  e1b_y+20, e1b_x,     e1b_y,    thi, col);
  snprintf(opcd, E1LABELMAX, "%02.2x", ea1op);
  draw_text(e1b_x+35, e1b_y+15, opcd, 1, col);
  draw_line (e1b_x+50, e1b_y+20,              e1b_x+50, e1b_y+180,     thi, col);
  draw_box  (e1b_x+40, e1b_y+180,             e1b_x+60, e1b_y+190,     thi, col);
  draw_line (e1b_x+50, e1b_y+190,             e1b_x+50, e1b_y+210,     thi, col);
  draw_box  (e1b_x+40, e1b_y+210,             e1b_x+60, e1b_y+220,     thi, col);
  if (ea1singleload) {
    col=4; /*blue*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_line (e1b_x+55, e1b_y+190,             e1b_x+55, e1b_y+340,     thi, col);
  draw_arrow(e1b_x+55, e1b_y+340,             e1b_x+65, e1b_y+340,     thi, col);
  draw_line (e1b_x+65, e1b_y+340,             e1b_x+100,e1b_y+340,     thi, col);

  /* SRC1 */
  if (ea1op && !(ea1bs & 2)) { /* ea1br */
    col=4; /*blue*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_box  (e1b_x,    e1b_y-40, e1b_x+40, e1b_y-30, thi, col);
  draw_arrow(e1b_x+20, e1b_y-30, e1b_x+20, e1b_y-10, thi, col);
  if (ea1op && (ea1bs & 2)) { /* eabbrs */
    col=4; /*blue*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_line (e1b_x+90, e1b_y-170+eabbrs*5+10, e1b_x+90, e1b_y-70, thi, col);
  draw_line (e1b_x+90, e1b_y-70,              e1b_x+30, e1b_y-70, thi, col);
  draw_arrow(e1b_x+30, e1b_y-70,              e1b_x+30, e1b_y-10, thi, col);
  if (ea1bs & 1) { /* feedback-loop */
    col=4; /*blue*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_line (e1b_x+50, e1b_y+190,             e1b_x+50, e1b_y+200,     thi, col);
  draw_line (e1b_x+50, e1b_y+200,             e1b_x+20, e1b_y+200,     thi, col);
  draw_arrow(e1b_x+20, e1b_y+200,             e1b_x+20, e1b_y-10,      thi, col);
  /* SRC2 */
  if (ea1op && !(ea1os & 1)) { /* ea1or */
    col=4; /*blue*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_box  (e1b_x+60, e1b_y-40, e1b_x+100, e1b_y-30, thi, col);
  draw_arrow(e1b_x+80, e1b_y-30, e1b_x+80,  e1b_y-10, thi, col);
  if (ea1op && (ea1os & 1)) { /* eaobrs */
    col=4; /*blue*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_line (e1b_x+210, e1b_y-170+eaobrs*5+10, e1b_x+210, e1b_y-60, thi, col);
  draw_line (e1b_x+210, e1b_y-60,              e1b_x+90,  e1b_y-60, thi, col);
  draw_arrow(e1b_x+90,  e1b_y-60,              e1b_x+90,  e1b_y-10, thi, col);
}

draw_trx(int trb_x, int trb_y,
	 int tr0v,
	 int tr1v,
	 int tr2v,
	 int tr3v,
	 int ts0,    /*:  4; 0:br0_0, 1:br0_1, ... 15:br3_3 */
	 int ts1,    /*:  4; 0:br0_0, 1:br0_1, ... 15:br3_3 */
	 int ts2,    /*:  4; 0:br0_0, 1:br0_1, ... 15:br3_3 */
	 int ts3,    /*:  4; 0:br0_0, 1:br0_1, ... 15:br3_3 */
	 int trs0,   /*:  2; 0:exdr0, 1:lmwd0, 2:ts0 */
	 int trs1,   /*:  2; 0:exdr1, 1:lmwd1, 2:ts1 */
	 int trs2,   /*:  2; 0:exdr2, 1:lmwd2, 2:ts2 */
	 int trs3    /*:  2; 0:exdr3, 1:lmwd3, 2:ts3 */
	 )
{
#define TRLABELMAX 30
  char opcd[TRLABELMAX];
  int col, thi;

  /* TR0 */
  if (tr0v) { col=2; /*green*/ thi=5; }
  else      { col=0; /*black*/ thi=1; }
  draw_box  (trb_x+360,   trb_y,              trb_x+380, trb_y+10,  thi, col);
  if (tr0v && trs0==0) { col=2; /*green*/ thi=5; } /* exdr */
  else                 { col=0; /*black*/ thi=1; }
  draw_arrow(trb_x+360,   trb_y-140,          trb_x+360, trb_y,     thi, col);
  if (tr0v && trs0==1) { col=2; /*green*/ thi=5; } /* lmwd */
  else                 { col=0; /*black*/ thi=1; }
  draw_arrow(trb_x+380,   trb_y-80,           trb_x+380, trb_y,     thi, col);
  if (tr0v && trs0==2) { col=2; /*green*/ thi=5; } /* ts */
  else                 { col=0; /*black*/ thi=1; }
  draw_arrow(trb_x+370,   trb_y-350+ts0*5+10, trb_x+370, trb_y,     thi, col);

  /* TR1 */
  if (tr1v) { col=2; /*green*/ thi=5; }
  else      { col=0; /*black*/ thi=1; }
  draw_box  (trb_x+240,   trb_y,              trb_x+260, trb_y+10,  thi, col);
  if (tr1v && trs1==0) { col=2; /*green*/ thi=5; } /* exdr */
  else                 { col=0; /*black*/ thi=1; }
  draw_arrow(trb_x+240,   trb_y-135,          trb_x+240, trb_y,     thi, col);
  if (tr1v && trs1==1) { col=2; /*green*/ thi=5; } /* lmwd */
  else                 { col=0; /*black*/ thi=1; }
  draw_arrow(trb_x+260,   trb_y-80,           trb_x+260, trb_y,     thi, col);
  if (tr1v && trs1==2) { col=2; /*green*/ thi=5; } /* ts */
  else                 { col=0; /*black*/ thi=1; }
  draw_arrow(trb_x+250,   trb_y-350+ts1*5+10, trb_x+250, trb_y,     thi, col);

  /* TR2 */
  if (tr2v) { col=2; /*green*/ thi=5; }
  else      { col=0; /*black*/ thi=1; }
  draw_box  (trb_x+120,   trb_y,              trb_x+140, trb_y+10,  thi, col);
  if (tr2v && trs2==0) { col=2; /*green*/ thi=5; } /* exdr */
  else                 { col=0; /*black*/ thi=1; }
  draw_arrow(trb_x+120,   trb_y-130,          trb_x+120, trb_y,     thi, col);
  if (tr2v && trs2==1) { col=2; /*green*/ thi=5; } /* lmwd */
  else                 { col=0; /*black*/ thi=1; }
  draw_arrow(trb_x+140,   trb_y-80,           trb_x+140, trb_y,     thi, col);
  if (tr2v && trs2==2) { col=2; /*green*/ thi=5; } /* ts */
  else                 { col=0; /*black*/ thi=1; }
  draw_arrow(trb_x+130,   trb_y-350+ts2*5+10, trb_x+130, trb_y,     thi, col);

  /* TR3 */
  if (tr3v) { col=2; /*green*/ thi=5; }
  else      { col=0; /*black*/ thi=1; }
  draw_box  (trb_x,       trb_y,              trb_x+20,  trb_y+10,  thi, col);
  if (tr3v && trs3==0) { col=2; /*green*/ thi=5; } /* exdr */
  else                 { col=0; /*black*/ thi=1; }
  draw_arrow(trb_x,       trb_y-125,          trb_x,     trb_y,     thi, col);
  if (tr3v && trs3==1) { col=2; /*green*/ thi=5; } /* lmwd */
  else                 { col=0; /*black*/ thi=1; }
  draw_arrow(trb_x+20,    trb_y-80,           trb_x+20,  trb_y,     thi, col);
  if (tr3v && trs3==2) { col=2; /*green*/ thi=5; } /* ts */
  else                 { col=0; /*black*/ thi=1; }
  draw_arrow(trb_x+10,    trb_y-350+ts3*5+10, trb_x+10,  trb_y,     thi, col);
}

draw_lmx(int lmb_x, int lmb_y,
	 int ea0op,  /* MWSA�˲ä�,LDDMQ�����STORE�ξ��ˤ�MWͭ�� */
	 int mwsa,   /*:  2; 0:off, 1:lmlia,2:lmwa,3:lmria  *//* for STATUS_EXEC+lmp */
	 int mws0,   /*:  3; 0:exdr,1:exdr0,2:ts0, 3:lmli0, 4:lmwd0, 5:lmri0 */
	 int mws1,   /*:  3; 0:exdr,1:exdr1,2:ts1, 3:lmli1, 4:lmwd1, 5:lmri1 */
	 int mws2,   /*:  3; 0:exdr,1:exdr2,2:ts2, 3:lmli2, 4:lmwd2, 5:lmri2 */
	 int mws3,   /*:  3; 0:exdr,1:exdr3,2:ts3, 3:lmli3, 4:lmwd3, 5:lmri3 */
	 int xmws    /*:  2; 0:off, 1:lmli, 2:lmwd,3:lmri *//* for STATUS_LOAD */
	 )
{
#define LMLABELMAX 30
  char opcd[LMLABELMAX];
  int col, thi;
  int ea0store = (ea0op&0x10);

  /* MWA */
  if (mwsa) {
    col=1; /*red*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_arrow(lmb_x+340,   lmb_y-110, lmb_x+340, lmb_y-30,  thi, col);

  /* MW0 */
  if (ea0store || mwsa) {
    col=1; /*red*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_box  (lmb_x+360,   lmb_y,     lmb_x+420, lmb_y+10,  thi, col);
  draw_box  (lmb_x+360,   lmb_y+20,  lmb_x+420, lmb_y+30,  thi, col);
  draw_box  (lmb_x+360,   lmb_y+30,  lmb_x+420, lmb_y+40,  thi, col);
  draw_box  (lmb_x+360,   lmb_y+40,  lmb_x+420, lmb_y+50,  1, 0);
  draw_box  (lmb_x+360,   lmb_y+50,  lmb_x+420, lmb_y+60,  1, 0);
  draw_line (lmb_x+345,   lmb_y-60,  lmb_x+405, lmb_y-60,  thi, col);
  draw_line (lmb_x+370,   lmb_y-60,  lmb_x+370, lmb_y,     thi, col);
  if ((ea0store || mwsa) && mws0==0) { col=1; /*red*/   thi=5; } /* exdr */ 
  else                               { col=0; /*black*/ thi=1; }
  draw_arrow(lmb_x+370,   lmb_y-150, lmb_x+370, lmb_y-60,  thi, col);
  if ((ea0store || mwsa) && mws0==1) { col=1; /*red*/   thi=5; } /* exdr0 */
  else                               { col=0; /*black*/ thi=1; }
  draw_arrow(lmb_x+380,   lmb_y-170, lmb_x+380, lmb_y-60,  thi, col);
  if ((ea0store || mwsa) && mws0==3) { col=1; /*red*/   thi=5; } /* lmli0 */
  else                               { col=0; /*black*/ thi=1; }
  draw_arrow(lmb_x+350,   lmb_y-100, lmb_x+350, lmb_y-60,  thi, col);
  if ((ea0store || mwsa) && mws0==5) { col=1; /*red*/   thi=5; } /* lmri0 */
  else                               { col=0; /*black*/ thi=1; }
  draw_arrow(lmb_x+360,   lmb_y-100, lmb_x+360, lmb_y-60,  thi, col);
  if ((ea0store || mwsa) && mws0==2) { col=1; /*red*/   thi=5; } /* ts0 */ 
  else                               { col=0; /*black*/ thi=1; }
  draw_arrow(lmb_x+390,   lmb_y-370, lmb_x+390, lmb_y-60,  thi, col);
  if ((ea0store || mwsa) && mws0==4) { col=1; /*red*/   thi=5; } /* lmwd0 */
  else                               { col=0; /*black*/ thi=1; }
  draw_arrow(lmb_x+400,   lmb_y-110, lmb_x+400, lmb_y-60,  thi, col);

  /* MW1 */
  if (ea0store || mwsa) {
    col=1; /*red*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_box  (lmb_x+240,   lmb_y,     lmb_x+300, lmb_y+10,  thi, col);
  draw_box  (lmb_x+240,   lmb_y+20,  lmb_x+300, lmb_y+30,  thi, col);
  draw_box  (lmb_x+240,   lmb_y+30,  lmb_x+300, lmb_y+40,  thi, col);
  draw_box  (lmb_x+240,   lmb_y+40,  lmb_x+300, lmb_y+50,  1, 0);
  draw_box  (lmb_x+240,   lmb_y+50,  lmb_x+300, lmb_y+60,  1, 0);
  draw_line (lmb_x+225,   lmb_y-60,  lmb_x+285, lmb_y-60,  thi, col);
  draw_line (lmb_x+250,   lmb_y-60,  lmb_x+250, lmb_y,     thi, col);
  if ((ea0store || mwsa) && mws1==0) { col=1; /*red*/   thi=5; } /* exdr */ 
  else                               { col=0; /*black*/ thi=1; }
  draw_arrow(lmb_x+250,   lmb_y-150, lmb_x+250, lmb_y-60,  thi, col);
  if ((ea0store || mwsa) && mws1==1) { col=1; /*red*/   thi=5; } /* exdr1 */
  else                               { col=0; /*black*/ thi=1; }
  draw_arrow(lmb_x+260,   lmb_y-165, lmb_x+260, lmb_y-60,  thi, col);
  if ((ea0store || mwsa) && mws1==3) { col=1; /*red*/   thi=5; } /* lmli1 */
  else                               { col=0; /*black*/ thi=1; }
  draw_arrow(lmb_x+230,   lmb_y-95,  lmb_x+230, lmb_y-60,  thi, col);
  if ((ea0store || mwsa) && mws1==5) { col=1; /*red*/   thi=5; } /* lmri1 */
  else                               { col=0; /*black*/ thi=1; }
  draw_arrow(lmb_x+240,   lmb_y-95,  lmb_x+240, lmb_y-60,  thi, col);
  if ((ea0store || mwsa) && mws1==2) { col=1; /*red*/   thi=5; } /* ts1 */ 
  else                               { col=0; /*black*/ thi=1; }
  draw_arrow(lmb_x+270,   lmb_y-370, lmb_x+270, lmb_y-60,  thi, col);
  if ((ea0store || mwsa) && mws1==4) { col=1; /*red*/   thi=5; } /* lmwd1 */
  else                               { col=0; /*black*/ thi=1; }
  draw_arrow(lmb_x+280,   lmb_y-110, lmb_x+280, lmb_y-60,  thi, col);

  /* MW2 */
  if (ea0store || mwsa) {
    col=1; /*red*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_box  (lmb_x+120,   lmb_y,     lmb_x+180, lmb_y+10,  thi, col);
  draw_box  (lmb_x+120,   lmb_y+20,  lmb_x+180, lmb_y+30,  thi, col);
  draw_box  (lmb_x+120,   lmb_y+30,  lmb_x+180, lmb_y+40,  thi, col);
  draw_box  (lmb_x+120,   lmb_y+40,  lmb_x+180, lmb_y+50,  1, 0);
  draw_box  (lmb_x+120,   lmb_y+50,  lmb_x+180, lmb_y+60,  1, 0);
  draw_line (lmb_x+105,   lmb_y-60,  lmb_x+165, lmb_y-60,  thi, col);
  draw_line (lmb_x+130,   lmb_y-60,  lmb_x+130, lmb_y,     thi, col);
  if ((ea0store || mwsa) && mws2==0) { col=1; /*red*/   thi=5; } /* exdr */ 
  else                               { col=0; /*black*/ thi=1; }
  draw_arrow(lmb_x+130,   lmb_y-150, lmb_x+130, lmb_y-60,  thi, col);
  if ((ea0store || mwsa) && mws2==1) { col=1; /*red*/   thi=5; } /* exdr2 */
  else                               { col=0; /*black*/ thi=1; }
  draw_arrow(lmb_x+140,   lmb_y-160, lmb_x+140, lmb_y-60,  thi, col);
  if ((ea0store || mwsa) && mws2==3) { col=1; /*red*/   thi=5; } /* lmli2 */
  else                               { col=0; /*black*/ thi=1; }
  draw_arrow(lmb_x+110,   lmb_y-90,  lmb_x+110, lmb_y-60,  thi, col);
  if ((ea0store || mwsa) && mws2==5) { col=1; /*red*/   thi=5; } /* lmri2 */
  else                               { col=0; /*black*/ thi=1; }
  draw_arrow(lmb_x+120,   lmb_y-90,  lmb_x+120, lmb_y-60,  thi, col);
  if ((ea0store || mwsa) && mws2==2) { col=1; /*red*/   thi=5; } /* ts2 */ 
  else                               { col=0; /*black*/ thi=1; }
  draw_arrow(lmb_x+150,   lmb_y-370, lmb_x+150, lmb_y-60,  thi, col);
  if ((ea0store || mwsa) && mws2==4) { col=1; /*red*/   thi=5; } /* lmwd2 */
  else                               { col=0; /*black*/ thi=1; }
  draw_arrow(lmb_x+160,   lmb_y-110, lmb_x+160, lmb_y-60,  thi, col);

  /* MW3 */
  if (ea0store || mwsa) {
    col=1; /*red*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_box  (lmb_x,       lmb_y,     lmb_x+60,  lmb_y+10,  thi, col);
  draw_box  (lmb_x,       lmb_y+20,  lmb_x+60,  lmb_y+30,  thi, col);
  draw_box  (lmb_x,       lmb_y+30,  lmb_x+60,  lmb_y+40,  thi, col);
  draw_box  (lmb_x,       lmb_y+40,  lmb_x+60,  lmb_y+50,  1, 0);
  draw_box  (lmb_x,       lmb_y+50,  lmb_x+60,  lmb_y+60,  1, 0);
  draw_line (lmb_x-15,    lmb_y-60,  lmb_x+45,  lmb_y-60,  thi, col);
  draw_line (lmb_x+10,    lmb_y-60,  lmb_x+10,  lmb_y,     thi, col);
  if ((ea0store || mwsa) && mws3==0) { col=1; /*red*/   thi=5; } /* exdr */ 
  else                               { col=0; /*black*/ thi=1; }
  draw_arrow(lmb_x+10,    lmb_y-150, lmb_x+10,  lmb_y-60,  thi, col);
  if ((ea0store || mwsa) && mws3==1) { col=1; /*red*/   thi=5; } /* exdr3 */
  else                               { col=0; /*black*/ thi=1; }
  draw_arrow(lmb_x+20,    lmb_y-155, lmb_x+20,  lmb_y-60,  thi, col);
  if ((ea0store || mwsa) && mws3==3) { col=1; /*red*/   thi=5; } /* lmli3 */
  else                               { col=0; /*black*/ thi=1; }
  draw_arrow(lmb_x-10,    lmb_y-85,  lmb_x-10,  lmb_y-60,  thi, col);
  if ((ea0store || mwsa) && mws3==5) { col=1; /*red*/   thi=5; } /* lmri3 */
  else                               { col=0; /*black*/ thi=1; }
  draw_arrow(lmb_x,       lmb_y-85,  lmb_x,     lmb_y-60,  thi, col);
  if ((ea0store || mwsa) && mws3==2) { col=1; /*red*/   thi=5; } /* ts3 */ 
  else                               { col=0; /*black*/ thi=1; }
  draw_arrow(lmb_x+30,    lmb_y-370, lmb_x+30,  lmb_y-60,  thi, col);
  if ((ea0store || mwsa) && mws3==4) { col=1; /*red*/   thi=5; } /* lmwd3 */
  else                               { col=0; /*black*/ thi=1; }
  draw_arrow(lmb_x+40,    lmb_y-110, lmb_x+40 , lmb_y-60,  thi, col);
}

draw_bri(int bri_x, int bri_y,
	 int ea0op,  /*:  5; mem_opcd */
	 int ea1op,  /*:  5; mem_opcd */
	 int brs0,   /*:  2; 0:off, 1:mr10, 2:tr0, 3:mr0  */
	 int brs1,   /*:  2; 0:off, 1:mr11, 2:tr1, 3:mr1  */
	 int brs2,   /*:  2; 0:off, 1:mr12, 2:tr2, 3:exdr */
	 int brs3,   /*:  2; 0:off, 1:mr13, 2:tr3         */
	 int br0v,
	 int br0h,
	 int br1v,
	 int br1h,
	 int br2v,
	 int br2h,
	 int br3v,
	 int br3h
	 )
{
#define BRLABELMAX 30
  char opcd[BRLABELMAX];
  int col, thi;
  int ea0singleload = (ea0op && (ea0op <= OP_LDUBR));
  int ea1singleload = (ea1op && (ea1op <= OP_LDUBR));

  /* BR0 */
  if (brs0) {
    col=4; /*blue*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_box  (bri_x+360,   bri_y,     bri_x+420, bri_y+15,  thi, col);
  if (brs0==1) { col=4; thi=5; } /* mr10 */
  else         { col=0; thi=1; }
  if (col) {
    draw_box(bri_x+360,   bri_y-110, bri_x+420, bri_y-100, thi, col);
    draw_box(bri_x+360,   bri_y-100, bri_x+420, bri_y-90,  thi, col);
  }
  draw_arrow(bri_x+400,   bri_y-90,  bri_x+400, bri_y,     thi, col);
  if (brs0==2) { col=4; thi=5; } /* tr0 */
  else         { col=0; thi=1; }
  draw_arrow(bri_x+390,   bri_y-170, bri_x+390, bri_y,     thi, col);
  if (brs0==3) { col=4; thi=5; } /* mr0 */
  else         { col=0; thi=1; }
  if (col) {
    draw_box(bri_x+360,   bri_y-110, bri_x+420, bri_y-100, thi, col);
    draw_box(bri_x+360,   bri_y-100, bri_x+420, bri_y-90,  thi, col);
    draw_box(bri_x+240,   bri_y-110, bri_x+300, bri_y-100, thi, col);
    draw_box(bri_x+240,   bri_y-100, bri_x+300, bri_y-90,  thi, col);
    draw_box(bri_x+120,   bri_y-110, bri_x+180, bri_y-100, thi, col);
    draw_box(bri_x+120,   bri_y-100, bri_x+180, bri_y-90,  thi, col);
    draw_box(bri_x,       bri_y-110, bri_x+60,  bri_y-100, thi, col);
    draw_box(bri_x,       bri_y-100, bri_x+60,  bri_y-90,  thi, col);
  }
  draw_line (bri_x+410,   bri_y-90,  bri_x+410, bri_y-80,  thi, col);
  draw_line (bri_x+410,   bri_y-80,  bri_x+380, bri_y-80,  thi, col);
  draw_arrow(bri_x+380,   bri_y-80,  bri_x+380, bri_y-20,  thi, col);
  draw_line (bri_x+290,   bri_y-90,  bri_x+290, bri_y-80,  thi, col);
  draw_line (bri_x+290,   bri_y-80,  bri_x+370, bri_y-80,  thi, col);
  draw_arrow(bri_x+370,   bri_y-80,  bri_x+370, bri_y-20,  thi, col);
  draw_line (bri_x+170,   bri_y-90,  bri_x+170, bri_y-70,  thi, col);
  draw_line (bri_x+170,   bri_y-70,  bri_x+360, bri_y-70,  thi, col);
  draw_arrow(bri_x+360,   bri_y-70,  bri_x+360, bri_y-20,  thi, col);
  draw_line (bri_x+50,    bri_y-90,  bri_x+50,  bri_y-60,  thi, col);
  draw_line (bri_x+50,    bri_y-60,  bri_x+350, bri_y-60,  thi, col);
  draw_arrow(bri_x+350,   bri_y-60,  bri_x+350, bri_y-20,  thi, col);
  draw_arrow(bri_x+380,   bri_y-20,  bri_x+380, bri_y,     thi, col);
  switch (br0v) {
  case 0: /* T_NONE */
    col=0; /*black*/
    thi=1;
    break;
  case 1: /* T_IMMEDIATE */
    col=4; /*blue*/
    thi=5;
    break;
  case 2: /* T_EXRNO */
    col=5; /*magenta*/
    thi=5;
    break;
  case 3: /* T_ALRNO */
    col=3; /*yellow*/
    thi=5;
    break;
  case 4: /* T_BDRNO */
    col=1; /*red*/
    thi=5;
    break;
  case 5: /* T_VARIABLE */
    col=2; /*green*/
    thi=5;
    break;
  default:
    col=6; /*cyan*/
    thi=5;
    break;
  }
  if (col) {
    draw_box (bri_x+360,   bri_y,    bri_x+420, bri_y+15,  thi, col);
    draw_text(bri_x+365,   bri_y+14, id[br0h].name, 1, 0);
  }

  /* BR1 */
  if (brs1) {
    col=4; /*blue*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_box  (bri_x+240,   bri_y,     bri_x+300, bri_y+15,  thi, col);
  if (brs1==1) { col=4; thi=5; } /* mr11 */
  else         { col=0; thi=1; }
  if (col) {
    draw_box(bri_x+240,   bri_y-110, bri_x+300, bri_y-100, thi, col);
    draw_box(bri_x+240,   bri_y-100, bri_x+300, bri_y-90,  thi, col);
  }
  draw_arrow(bri_x+280,   bri_y-90,  bri_x+280, bri_y,     thi, col);
  if (brs1==2) { col=4; thi=5; } /* tr1 */
  else         { col=0; thi=1; }
  draw_arrow(bri_x+270,   bri_y-170, bri_x+270, bri_y,     thi, col);
  if (brs1==3) { col=4; thi=5; } /* mr1 */
  else         { col=0; thi=1; }
  if (col) {
    draw_box(bri_x+360,   bri_y-110, bri_x+420, bri_y-100, thi, col);
    draw_box(bri_x+360,   bri_y-100, bri_x+420, bri_y-90,  thi, col);
    draw_box(bri_x+240,   bri_y-110, bri_x+300, bri_y-100, thi, col);
    draw_box(bri_x+240,   bri_y-100, bri_x+300, bri_y-90,  thi, col);
    draw_box(bri_x+120,   bri_y-110, bri_x+180, bri_y-100, thi, col);
    draw_box(bri_x+120,   bri_y-100, bri_x+180, bri_y-90,  thi, col);
    draw_box(bri_x,       bri_y-110, bri_x+60,  bri_y-100, thi, col);
    draw_box(bri_x,       bri_y-100, bri_x+60,  bri_y-90,  thi, col);
  }
  draw_line (bri_x+400,   bri_y-40,  bri_x+260, bri_y-40,  thi, col);
  draw_arrow(bri_x+260,   bri_y-40,  bri_x+260, bri_y-20,  thi, col);
  draw_line (bri_x+280,   bri_y-50,  bri_x+250, bri_y-50,  thi, col);
  draw_arrow(bri_x+250,   bri_y-50,  bri_x+250, bri_y-20,  thi, col);
  draw_line (bri_x+160,   bri_y-50,  bri_x+240, bri_y-50,  thi, col);
  draw_arrow(bri_x+240,   bri_y-50,  bri_x+240, bri_y-20,  thi, col);
  draw_line (bri_x+40,    bri_y-40,  bri_x+230, bri_y-40,  thi, col);
  draw_arrow(bri_x+230,   bri_y-40,  bri_x+230, bri_y-20,  thi, col);
  draw_arrow(bri_x+260,   bri_y-20,  bri_x+260, bri_y,     thi, col);
  switch (br1v) {
  case 0: /* T_NONE */
    col=0; /*black*/
    thi=1;
    break;
  case 1: /* T_IMMEDIATE */
    col=4; /*blue*/
    thi=5;
    break;
  case 2: /* T_EXRNO */
    col=5; /*magenta*/
    thi=5;
    break;
  case 3: /* T_ALRNO */
    col=3; /*yellow*/
    thi=5;
    break;
  case 4: /* T_BDRNO */
    col=1; /*red*/
    thi=5;
    break;
  case 5: /* T_VARIABLE */
    col=2; /*green*/
    thi=5;
    break;
  default:
    col=6; /*cyan*/
    thi=5;
    break;
  }
  if (col) {
    draw_box (bri_x+240,   bri_y,    bri_x+300, bri_y+15,  thi, col);
    draw_text(bri_x+245,   bri_y+14, id[br1h].name, 1, 0);
  }

  /* BR2 */
  if (brs2) {
    col=4; /*blue*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_box  (bri_x+120,   bri_y,     bri_x+180, bri_y+15,  thi, col);
  if (brs2==1) { col=4; thi=5; } /* mr12 */
  else         { col=0; thi=1; }
  if (col) {
    draw_box(bri_x+120,   bri_y-110, bri_x+180, bri_y-100, thi, col);
    draw_box(bri_x+120,   bri_y-100, bri_x+180, bri_y-90,  thi, col);
  }
  draw_arrow(bri_x+160,   bri_y-90,  bri_x+160, bri_y,     thi, col);
  if (brs2==2) { col=4; thi=5; } /* tr2 */
  else         { col=0; thi=1; }
  draw_arrow(bri_x+150,   bri_y-170, bri_x+150, bri_y,     thi, col);
  if (brs2==3) { col=5; thi=5; } /* exdr */
  else         { col=0; thi=1; }
  draw_line (bri_x+90,    bri_y-170, bri_x+90,  bri_y-20,  thi, col);
  draw_line (bri_x+90,    bri_y-20,  bri_x+140, bri_y-20,  thi, col);
  draw_arrow(bri_x+140,   bri_y-20,  bri_x+140, bri_y,     thi, col);
  switch (br2v) {
  case 0: /* T_NONE */
    col=0; /*black*/
    thi=1;
    break;
  case 1: /* T_IMMEDIATE */
    col=4; /*blue*/
    thi=5;
    break;
  case 2: /* T_EXRNO */
    col=5; /*magenta*/
    thi=5;
    break;
  case 3: /* T_ALRNO */
    col=3; /*yellow*/
    thi=5;
    break;
  case 4: /* T_BDRNO */
    col=1; /*red*/
    thi=5;
    break;
  case 5: /* T_VARIABLE */
    col=2; /*green*/
    thi=5;
    break;
  default:
    col=6; /*cyan*/
    thi=5;
    break;
  }
  if (col) {
    draw_box (bri_x+120,   bri_y,    bri_x+180, bri_y+15,  thi, col);
    draw_text(bri_x+125,   bri_y+14, id[br2h].name, 1, 0);
  }

  /* BR3 */
  if (brs3) {
    col=4; /*blue*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_box  (bri_x,       bri_y,     bri_x+60,  bri_y+15,  thi, col);
  if (brs3==1) { col=4; thi=5; } /* mr13 */
  else         { col=0; thi=1; }
  if (col) {
    draw_box(bri_x,       bri_y-110, bri_x+60,  bri_y-100, thi, col);
    draw_box(bri_x,       bri_y-100, bri_x+60,  bri_y-90,  thi, col);
  }
  draw_arrow(bri_x+40,    bri_y-90,  bri_x+40,  bri_y,     thi, col);
  if (brs3==2) { col=4; thi=5; } /* tr3 */
  else         { col=0; thi=1; }
  draw_arrow(bri_x+30,    bri_y-170, bri_x+30,  bri_y,     thi, col);
  switch (br3v) {
  case 0: /* T_NONE */
    col=0; /*black*/
    thi=1;
    break;
  case 1: /* T_IMMEDIATE */
    col=4; /*blue*/
    thi=5;
    break;
  case 2: /* T_EXRNO */
    col=5; /*magenta*/
    thi=5;
    break;
  case 3: /* T_ALRNO */
    col=3; /*yellow*/
    thi=5;
    break;
  case 4: /* T_BDRNO */
    col=1; /*red*/
    thi=5;
    break;
  case 5: /* T_VARIABLE */
    col=2; /*green*/
    thi=5;
    break;
  default:
    col=6; /*cyan*/
    thi=5;
    break;
  }
  if (col) {
    draw_box (bri_x,       bri_y,    bri_x+60,  bri_y+15,  thi, col);
    draw_text(bri_x+5,     bri_y+14, id[br3h].name, 1, 0);
  }
}

draw_lmr(int bri_x, int bri_y,
	 int lmrd0,
	 int lmrd1,
	 int lmrd2,
	 int lmrd3
	 )
{
  int col, thi;

  /* LMRA */
  if (lmrd0 || lmrd1 || lmrd2 || lmrd3) {
    col=4; /*blue*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_arrow(bri_x+220,  bri_y-260, bri_x+220, bri_y-180,  thi, col);
  draw_box  (bri_x+200,  bri_y-180, bri_x+220, bri_y-170,  thi, col);
  draw_line (bri_x+210,  bri_y-170, bri_x+210, bri_y-150,  thi, col);
  draw_box  (bri_x+200,  bri_y-150, bri_x+220, bri_y-140,  thi, col);

  /* LMRD0 */
  if (lmrd0) {
    col=4; /*blue*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_box  (bri_x+360,   bri_y-110, bri_x+420, bri_y-100, thi, col);
  draw_box  (bri_x+360,   bri_y-100, bri_x+420, bri_y-90,  thi, col);
  draw_line (bri_x+400,   bri_y-90,  bri_x+400, bri_y-20,  thi, col);
  draw_arrow(bri_x+400,   bri_y-20,  bri_x+420, bri_y-20,  thi, col);

  /* LMRD1 */
  if (lmrd1) {
    col=4; /*blue*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_box  (bri_x+240,   bri_y-110, bri_x+300, bri_y-100, thi, col);
  draw_box  (bri_x+240,   bri_y-100, bri_x+300, bri_y-90,  thi, col);
  draw_line (bri_x+280,   bri_y-90,  bri_x+280, bri_y-20,  thi, col);
  draw_arrow(bri_x+280,   bri_y-20,  bri_x+300, bri_y-20,  thi, col);

  /* LMRD2 */
  if (lmrd2) {
    col=4; /*blue*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_box  (bri_x+120,   bri_y-110, bri_x+180, bri_y-100, thi, col);
  draw_box  (bri_x+120,   bri_y-100, bri_x+180, bri_y-90,  thi, col);
  draw_line (bri_x+160,   bri_y-90,  bri_x+160, bri_y-20,  thi, col);
  draw_arrow(bri_x+160,   bri_y-20,  bri_x+180, bri_y-20,  thi, col);

  /* LMRD3 */
  if (lmrd3) {
    col=4; /*blue*/
    thi=5;
  }
  else {
    col=0; /*black*/
    thi=1;
  }
  draw_box  (bri_x,       bri_y-110, bri_x+60,  bri_y-100, thi, col);
  draw_box  (bri_x,       bri_y-100, bri_x+60,  bri_y-90,  thi, col);
  draw_line (bri_x+40,    bri_y-90,  bri_x+40,  bri_y-20,  thi, col);
  draw_arrow(bri_x+40,    bri_y-20,  bri_x+60,  bri_y-20,  thi, col);
}

draw_box(int x0, int y0, int x1, int y1, int thick, int color)
{
  char *cstr[] = { "'black'", "'red'", "'green'", "'yellow'", "'blue'", "'magenta'", "'cyan'", "'white'"};

  if (thick>7) thick=7;
  if (color>7) color=7;

  fprintf(ffile, "box(%s,'',%d,%d,%d,%d,0,%d,1,0,0,0,0,0,0,'%d',0,[\n", cstr[color], x0, y0, x1, y1, thick, thick);
  fprintf(ffile, "]).\n");
}

draw_line(int x0, int y0, int x1, int y1, int thick, int color)
{
  char *cstr[] = { "'black'", "'red'", "'green'", "'yellow'", "'blue'", "'magenta'", "'cyan'", "'white'"};

  if (thick>7) thick=7;
  if (color>7) color=7;

  fprintf(ffile, "poly(%s,'',2,[\n", cstr[color]);
  fprintf(ffile, "%d,%d,%d,%d],0,%d,1,1,0,0,0,0,0,0,0,'%d',0,0,\n", x0, y0, x1, y1, thick, thick);
  fprintf(ffile, "\"0\",\"\",[\n");
  fprintf(ffile, "0,12,5,0,'12','5','0'],[0,12,5,0,'12','5','0'],[\n");
  fprintf(ffile, "]).\n");
}

draw_arrow(int x0, int y0, int x1, int y1, int thick, int color)
{
  char *cstr[] = { "'black'", "'red'", "'green'", "'yellow'", "'blue'", "'magenta'", "'cyan'", "'white'"};

  if (thick>7) thick=7;
  if (color>7) color=7;

  fprintf(ffile, "poly(%s,'',2,[\n", cstr[color]);
  fprintf(ffile, "%d,%d,%d,%d],1,%d,1,1,0,0,0,0,0,0,0,'%d',0,0,\n", x0, y0, x1, y1, thick, thick);
  fprintf(ffile, "\"0\",\"\",[\n");
  fprintf(ffile, "0,12,5,0,'12','5','0'],[0,12,5,0,'12','5','0'],[\n");
  fprintf(ffile, "]).\n");
}

draw_text(int x0, int y0, char *str, int size, int color)
{
  char *cstr[] = { "'black'", "'red'", "'green'", "'yellow'", "'blue'", "'magenta'", "'cyan'", "'white'"};

  if (color>7) color=7;

  fprintf(ffile, "text(%s,%d,%d,1,0,1,40,20,10,10,5,0,0,0,0,2,40,20,0,0,\"\",0,0,0,0,%d,'',[\n", cstr[color], x0, y0, y0);
  fprintf(ffile, "minilines(40,20,0,0,0,0,0,[\n");
  fprintf(ffile, "mini_line(40,20,10,0,0,0,[\n");
  fprintf(ffile, "str_block(0,40,20,10,0,0,0,0,0,[\n");
  fprintf(ffile, "str_seg(%s,'Times-Roman',0,%d,40,20,10,0,0,0,0,1,0,0,\n", cstr[color], size*115200);
  fprintf(ffile, "        \"%s\")])\n", str);
  fprintf(ffile, "])\n");
  fprintf(ffile, "])]).\n");
}
