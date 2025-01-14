
/* EMAX5 Compiler                      */
/*        Copyright (C) 2012 by NAIST. */
/*         Primary writer: Y.Nakashima */
/*                nakashim@is.naist.jp */

/* conv-a2c.y   2012/6/15 */

%token  EOL
%token  ARMV8
%token  EMAX5ABEGIN     EMAX5ASTATEM    EMAX5AEND	EMAX5ADRAIN
%token  EMAX5TBEGIN     EMAX5TSTATEM    EMAX5TEND

/* CGRA */
%token  CGRA_ULL        CGRA_UINT
%token  CGRA_SLL	CGRA_SRL
%token  CGRA_WHILE	CGRA_CEX
%token	CGRA_EX4	CGRA_EXE
%token	CGRA_MO4	CGRA_MOP
%token	CGRA_DECR	CGRA_INCR

/* TRANSACTION */
%token  TRAN_READ       TRAN_WRITE

/* COMMON */
%token  IMMEDIATE
%token  VARIABLE
%token  EXRNO
%token  ALRNO
%token  BDRNO

%start  program
%%
program : program line
        | line
        ;

line :  EOL {
        }
        | ARMV8 {
          fprintf(ofile, "%s\n", yytext);
        }
        | EMAX5ABEGIN VARIABLE expr { /* reset conf[][] */
          printf("==EMAX5AB reading line=%d name=%s\n", y_lineno, id[$2].name);
          current_prefix  = $2;
          current_mapdist = id[$3].val;
          current_lmmwb   = 0;
          last_insn = 0;
	  bzero(&insn, sizeof(insn));
	  bzero(&dec,  sizeof(dec));
	  bzero(&bus,  sizeof(bus));
	  bzero(&conf, sizeof(conf));
	  bzero(&lmmi, sizeof(lmmi));
	  bzero(&lmmx, sizeof(lmmx));
          fprintf(ofile, "volatile emax5_conf_%s();\n", id[current_prefix].name);
          if (y_emax5a_seqno >= ACP_CONF_MAX) {
	    fprintf(stderr, "in %s: y_emax5a_seqno exceeds ACP_CONF_MAX=%d\n", id[current_prefix].name, ACP_CONF_MAX);
            exit(1);
          }
	  /* lmmiは1wayあたり,16B*16行=0.25KB,16B*64行=1KB(最大). 4way分連続にするには,16行で1KB,64行で4KBアラインが必要.  ZYNQのpage-sizeが4KB以上であればOK */
          fprintf(ofile, "volatile struct { struct { Uint ctl, ofs; Ull top;} lmmi[%d][%d];} *emax5_lmmi_%s = acp_lmmi;\n", EMAX_WIDTH, EMAX_DEPTH, id[current_prefix].name);
	  /* regvは1wayあたり,64B*16行=1KB,   64B*64行=4KB(最大). 4way分連続にするには,16行で4KB,64行で16KBアラインが必要. ZYNQのpage-sizeが16KB以上であればOK */
          fprintf(ofile, "volatile struct { struct { Ull ea0br, ea0or, ea1br, ea1or; Ull br[%d];} regv[%d][%d];} *emax5_regv_%s = acp_regv;\n", UNIT_WIDTH, EMAX_WIDTH, EMAX_DEPTH, id[current_prefix].name);
        }
        | EMAX5ASTATEM EMAX5ABODY {
        }
        | EMAX5AEND {
	  emit_emax5a(0);
	  hash_clear();
        }
        | EMAX5ADRAIN {
	  emit_emax5a(1);
	  hash_clear();
        }
        | EMAX5TBEGIN VARIABLE { /* reset tconf[][] */
          printf("==EMAX5TB reading line=%d name=%s\n", y_lineno, id[$2].name);
          current_prefix = $2;
          trans_pc = 0;
	  bzero(&trans, sizeof(trans));
	  bzero(&tconf, sizeof(tconf));
	}
        | EMAX5TSTATEM EMAX5TBODY {
	}
        | EMAX5TEND {
	  emit_emax5t(0);
	  hash_clear();
	}
        ;

EMAX5ABODY : CGRA_WHILE "(" VARIABLE CGRA_DECR ")" "\{" {
          if (last_insn >= INSN_DEPTH) {
	    fprintf(stderr, "in %s: last_insn exceeds INSN_DEPTH=%d\n", id[current_prefix].name, INSN_DEPTH);
            exit(1);
          }
	  insn[last_insn].iheader.type = 1; /* WHILE */
	  insn[last_insn].iheader.row  = 0; /* top */
	  insn[last_insn].iheader.col  = 0; /* top */
	  insn[last_insn].iexe.op1     = OP_WHILE;
	  insn[last_insn].iexe.updt    = 1;
	  insn[last_insn].iexe.src1v   = T_VARIABLE; /* variable */
	  insn[last_insn].iexe.src1h   = $3;
	  insn[last_insn].iexe.src1s   = -1; /* no suffix */
	  insn[last_insn].iexe.src1e   = EXP_H3210; /* full */
	  insn[last_insn].iexe.src2v   = T_IMMEDIATE; /* variable */
	  insn[last_insn].iexe.src2h   = $4; /* -1 */
	  insn[last_insn].iexe.src2s   = -1; /* no suffix */
	  insn[last_insn].iexe.src2e   = EXP_H3210; /* full */
	  insn[last_insn].iexe.exedv   = T_VARIABLE; /* variable */
	  insn[last_insn].iexe.exedh   = $3;
	  insn[last_insn].iexe.exeds   = -1; /* no suffix */
          last_insn++;
	}
        | CGRA_CEX "(" expr "," cex_dst "," cex_src "," cex_src "," cex_src "," cex_src "," expr ")" ";" {
          if (last_insn >= INSN_DEPTH) {
	    fprintf(stderr, "in %s: last_insn exceeds INSN_DEPTH=%d\n", id[current_prefix].name, INSN_DEPTH);
            exit(1);
          }
	  insn[last_insn].iheader.type = 2; /* CEX */
	  insn[last_insn].iheader.row  = -1;
	  insn[last_insn].iheader.col  = -1;
	  insn[last_insn].icex.op      = id[ $3].val;
	  insn[last_insn].icex.bit0v   = id[$13].type;
	  insn[last_insn].icex.bit0h   = $13;
	  insn[last_insn].icex.bit1v   = id[ $11].type;
	  insn[last_insn].icex.bit1h   = $11;
	  insn[last_insn].icex.bit2v   = id[ $9].type;
	  insn[last_insn].icex.bit2h   = $9;
	  insn[last_insn].icex.bit3v   = id[ $7].type;
	  insn[last_insn].icex.bit3h   = $7;
	  insn[last_insn].icex.table   = id[$15].val;
	  insn[last_insn].icex.cexdv   = id[$5].type;
	  insn[last_insn].icex.cexdh   = $5;
          last_insn++;
        }
        | CGRA_EX4 "(" expr "," ex4_dstd "," ex4_src "," expr "," ex4_src "," expr "," ex4_src "," expr "," expr "," ex4_src "," expr "," ex4_src ")" ";" {
	  /* ex4(op1, &BR[r-1][c1], &BR[r-1][c2], &BR[r-1][c3], op2, IMM, op3, IMM, &BR[r][c], NULL); followed by next ex */
	  /* ex4(op1, &BR[r-1][c1], &BR[r-1][c2], &BR[r-1][c3], op2, IMM, op3, IMM, &AR[r],    NULL); followed by store(automatic allocating) */
          if (last_insn >= INSN_DEPTH) {
	    fprintf(stderr, "in %s: last_insn exceeds INSN_DEPTH=%d\n", id[current_prefix].name, INSN_DEPTH);
            exit(1);
          }
	  insn[last_insn].iheader.type = 3; /* EX4 */
	  insn[last_insn].iheader.row  = id[$5].type==T_ALRNO?(id[$5].val):id[$5].type==T_BDRNO?(id[$5].val/EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iheader.col  = id[$5].type==T_ALRNO?(        -1):id[$5].type==T_BDRNO?(id[$5].val%EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iexe.op1     = id[ $3].val;
	  insn[last_insn].iexe.op2     = id[$19].val;
	  insn[last_insn].iexe.op3     = id[$23].val;
	  insn[last_insn].iexe.updt    = ($5 == $7)?1:0; /* if (src1 == dstd) self_update=1 */
	  insn[last_insn].iexe.src1v   = id[ $7].type;
	  insn[last_insn].iexe.src1h   = $7;
	  insn[last_insn].iexe.src1s   = 4; /* all suffix */
	  insn[last_insn].iexe.src1e   = id[ $9].val;
	  insn[last_insn].iexe.src2v   = id[ $11].type;
	  insn[last_insn].iexe.src2h   = $11;
	  insn[last_insn].iexe.src2s   = 4; /* all suffix */
	  insn[last_insn].iexe.src2e   = id[$13].val;
	  insn[last_insn].iexe.src3v   = id[$15].type;
	  insn[last_insn].iexe.src3h   = $15;
	  insn[last_insn].iexe.src3s   = 4; /* all suffix */
	  insn[last_insn].iexe.src3e   = id[$17].val;
	  insn[last_insn].iexe.src4v   = id[$21].type;
	  insn[last_insn].iexe.src4h   = $21;
	  insn[last_insn].iexe.src4s   = 4; /* all suffix */
	  insn[last_insn].iexe.src5v   = id[$25].type;
	  insn[last_insn].iexe.src5h   = $25;
	  insn[last_insn].iexe.src5s   = 4; /* all suffix */
	  insn[last_insn].iexe.exedv   = id[$5].type;
	  insn[last_insn].iexe.exedh   = $5;
	  insn[last_insn].iexe.exeds   = 4; /* all suffix */
          last_insn++;
        }
        | CGRA_EXE "(" expr "," exe_dstd "," exe_src1 "," expr "," exe_src2 "," expr "," exe_src3 "," expr "," expr "," exe_src4 "," expr "," exe_src5 ")" ";" {
	  /* exe(op1, BR[r-1][c1][s], BR[r-1][c2][s], BR[r-1][c3][s], op2, IMM, op3, IMM, &BR[r][c][s]); followed by next ex */
	  /* exe(op1, BR[r-1][c1][s], BR[r-1][c2][s], BR[r-1][c3][s], op2, IMM, op3, IMM, &AR[r][c]   ); followed by store(automatic allocating) */
          if (last_insn >= INSN_DEPTH) {
	    fprintf(stderr, "in %s: last_insn exceeds INSN_DEPTH=%d\n", id[current_prefix].name, INSN_DEPTH);
            exit(1);
          }
	  insn[last_insn].iheader.type = 4; /* EXE */
	  insn[last_insn].iheader.row  = id[$5].type==T_ALRNO?(id[$5].val)                :id[$5].type==T_BDRNO?(id[$5].val/EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iheader.col  = id[$5].type==T_ALRNO?(insn[last_insn].iexe.exeds):id[$5].type==T_BDRNO?(id[$5].val%EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iexe.op1     = id[ $3].val;
	  insn[last_insn].iexe.op2     = id[$19].val;
	  insn[last_insn].iexe.op3     = id[$23].val;
	  insn[last_insn].iexe.updt    = ($5 == $7)?1:0; /* if (src1 == dstd) self_update=1 */
	  insn[last_insn].iexe.src1v   = id[ $7].type;
	  insn[last_insn].iexe.src1h   = $7;
	  insn[last_insn].iexe.src1e   = id[ $9].val;
	  insn[last_insn].iexe.src2v   = id[ $11].type;
	  insn[last_insn].iexe.src2h   = $11;
	  insn[last_insn].iexe.src2e   = id[$13].val;
	  insn[last_insn].iexe.src3v   = id[$15].type;
	  insn[last_insn].iexe.src3h   = $15;
	  insn[last_insn].iexe.src3e   = id[$17].val;
	  insn[last_insn].iexe.src4v   = id[$21].type;
	  insn[last_insn].iexe.src4h   = $21;
	  insn[last_insn].iexe.src5v   = id[$25].type;
	  insn[last_insn].iexe.src5h   = $25;
	  insn[last_insn].iexe.exedv   = id[$5].type;
	  insn[last_insn].iexe.exedh   = $5;
          last_insn++;
        }
        | CGRA_MO4 "(" expr "," mop_ex "," mo4_srcdst "," mop_base "," mop_offset "," expr "," mop_top "," mop_len "," expr "," expr "," mop_top "," mop_len ")" ";" {
	  /* mop(load,  ex, BR[r][c][s], single_reg, offset, offset_mask, stream_top, length, block, force, ptop, plen); load requires target regs */
	  /* mop(store, ex, AR[r][c][s], single_reg, offset, offset_mask, stream_top, length, block, force, ptop, plen); store requires current ex */
          if (last_insn >= INSN_DEPTH) {
	    fprintf(stderr, "in %s: last_insn exceeds INSN_DEPTH=%d\n", id[current_prefix].name, INSN_DEPTH);
            exit(1);
          }
	  insn[last_insn].iheader.type = 5; /* MO4 */
	  insn[last_insn].iheader.row  = id[$7].type==T_ALRNO?(id[$7].val):id[$7].type==T_BDRNO?(id[$7].val/EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iheader.col  = id[$7].type==T_ALRNO?(        -1):id[$7].type==T_BDRNO?(id[$7].val%EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].imop.op      = id[ $3].val;
	  insn[last_insn].imop.mtype   = get_mop_type(id[ $3].val);
	  insn[last_insn].imop.exv     = id[ $5].type;
	  insn[last_insn].imop.exh     = $5;
	  insn[last_insn].imop.mopdv   = id[ $7].type;
	  insn[last_insn].imop.mopdh   = $7;
	  insn[last_insn].imop.mopds   = 4; /* all suffix */
	  insn[last_insn].imop.basev   = id[ $9].type;
	  insn[last_insn].imop.baseh   = $9;
	  insn[last_insn].imop.offsv   = id[$11].type;
	  insn[last_insn].imop.offsh   = $11;
	  if (insn[last_insn].imop.updt) { /* addr++ */
	    if (insn[last_insn].imop.offsv != T_IMMEDIATE || id[insn[last_insn].imop.offsh].val) { /* != zero */
	      fprintf(stderr, "in %s: incremental base=%s requires offset=0 (specified type=%d val=%d)\n",
		      id[current_prefix].name, id[insn[last_insn].imop.baseh].name, insn[last_insn].imop.offsv, id[insn[last_insn].imop.offsh].val);
	      exit(1);
	    }
	    else {
	      Ull size;
	      switch (insn[last_insn].imop.op) {
	      case OP_LDRQ: case OP_STRQ: size = 32LL; break;
	      default:
		fprintf(stderr, "in %s: incremental base=%s is available with OP_LDRQ and OP_STRQ\n",
			id[current_prefix].name, id[insn[last_insn].imop.baseh].name);
		exit(1);
	      }
	      /* one_shotを使用し,アドレス計算の初回は,immediateを０として扱う */
	      insn[last_insn].imop.offsv   = T_IMMEDIATE;
	      insn[last_insn].imop.offsh   = hash_reg_immediate(size);
	    }
	  }
	  else if (insn[last_insn].imop.op == OP_LDDMQ) {
	    insn[last_insn].imop.updt    = 1; /* force automatic imcrement */
	    /* basev -> dexu->ex1v */
	    /* offsv -> dexu->ex2v */
	  }
	  else if (insn[last_insn].imop.op == OP_TR) {
	    insn[last_insn].imop.updt    = 1; /* force automatic imcrement */
	    insn[last_insn].imop.basev   = T_IMMEDIATE;
	    insn[last_insn].imop.baseh   = hash_reg_immediate(0LL); /* start from lmm_0 */
	    insn[last_insn].imop.bases   = -1;
	    insn[last_insn].imop.offsv   = T_IMMEDIATE;
	    insn[last_insn].imop.offsh   = hash_reg_immediate(32LL);
	    insn[last_insn].imop.offss   = -1;
	  }
	  insn[last_insn].imop.offsm   = id[$13].val;
	  insn[last_insn].imop.topv    = id[$15].type;
	  insn[last_insn].imop.toph    = $15;
	  insn[last_insn].imop.lenv    = id[$17].type;
	  insn[last_insn].imop.lenh    = $17;
	  insn[last_insn].imop.blk     = id[$19].val;
	  insn[last_insn].imop.force   = id[$21].val;
	  insn[last_insn].imop.ptopv   = id[$23].type;
	  insn[last_insn].imop.ptoph   = $23;
	  insn[last_insn].imop.plenv   = id[$25].type;
	  insn[last_insn].imop.plenh   = $25;
          last_insn++;
        }
        | CGRA_MOP "(" expr "," mop_ex "," mop_srcdst "," mop_base "," mop_offset "," expr "," mop_top "," mop_len "," expr "," expr "," mop_top "," mop_len ")" ";" {
	  /* mop(load,  ex, BR[r][c][s], single_reg, offset, offset_mask, stream_top, length, block, force, ptop, plen); load requires target regs */
	  /* mop(store, ex, AR[r][c][s], single_reg, offset, offset_mask, stream_top, length, , blockforce, ptop, plen); store requires current ex */
          if (last_insn >= INSN_DEPTH) {
	    fprintf(stderr, "in %s: last_insn exceeds INSN_DEPTH=%d\n", id[current_prefix].name, INSN_DEPTH);
            exit(1);
          }
	  insn[last_insn].iheader.type = 6; /* MOP */
	  insn[last_insn].iheader.row  = id[$7].type==T_ALRNO?(id[$7].val)                :id[$7].type==T_BDRNO?(id[$7].val/EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iheader.col  = id[$7].type==T_ALRNO?(insn[last_insn].imop.mopds):id[$7].type==T_BDRNO?(id[$7].val%EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].imop.op      = id[ $3].val;
	  insn[last_insn].imop.mtype   = get_mop_type(id[ $3].val);
	  insn[last_insn].imop.exv     = id[ $5].type;
	  insn[last_insn].imop.exh     = $5;
	  insn[last_insn].imop.mopdv   = id[ $7].type;
	  insn[last_insn].imop.mopdh   = $7;
	  insn[last_insn].imop.basev   = id[ $9].type;
	  insn[last_insn].imop.baseh   = $9;
	  insn[last_insn].imop.offsv   = id[$11].type;
	  insn[last_insn].imop.offsh   = $11;
	  if (insn[last_insn].imop.updt) { /* addr++ */
	    if (insn[last_insn].imop.offsv != T_IMMEDIATE || id[insn[last_insn].imop.offsh].val) { /* != zero */
	      fprintf(stderr, "in %s: incremental base=%s requires offset=0 (specified type=%d val=%d)\n",
		      id[current_prefix].name, id[insn[last_insn].imop.baseh].name, insn[last_insn].imop.offsv, id[insn[last_insn].imop.offsh].val);
	      exit(1);
	    }
	    else {
	      Ull size;
	      switch (insn[last_insn].imop.op) {
	      case OP_LDR:  case OP_STR:                 size =  8LL; break;
	      case OP_LDWR: case OP_LDUWR: case OP_STWR: size =  4LL; break;
	      case OP_LDHR: case OP_LDUHR: case OP_STHR: size =  2LL; break;
	      case OP_LDBR: case OP_LDUBR: case OP_STBR: size =  1LL; break;
	      default:
		fprintf(stderr, "in %s: incremental base=%s is available with OP_LD*R and OP_ST*R\n",
			id[current_prefix].name, id[insn[last_insn].imop.baseh].name);
		exit(1);
	      }
	      /* one_shotを使用し,アドレス計算の初回は,immediateを０として扱う */
	      insn[last_insn].imop.offsv   = T_IMMEDIATE;
	      insn[last_insn].imop.offsh   = hash_reg_immediate(size);
	    }
	  }
	  insn[last_insn].imop.offsm   = id[$13].val;
	  insn[last_insn].imop.topv    = id[$15].type;
	  insn[last_insn].imop.toph    = $15;
	  insn[last_insn].imop.lenv    = id[$17].type;
	  insn[last_insn].imop.lenh    = $17;
	  insn[last_insn].imop.blk     = id[$19].val;
	  insn[last_insn].imop.force   = id[$21].val;
	  insn[last_insn].imop.ptopv   = id[$23].type;
	  insn[last_insn].imop.ptoph   = $23;
	  insn[last_insn].imop.plenv   = id[$25].type;
	  insn[last_insn].imop.plenh   = $25;
          last_insn++;
        }
        | "\}" {
        }
	| {
        }
        ;

cex_src : expr {
          $$ = $1;
        }
        | VARIABLE {
          $$ = $1;
	}
        | CGRA_ULL VARIABLE {
          $$ = $2;
	}
	; 

cex_dst : "\&" EXRNO {
          $$ = $2;
        }
	;

ex4_src : expr {
          $$ = $1;
        }
        | VARIABLE { /* var ([UNIT_WIDTH]) */
          $$ = $1;
	}
        | CGRA_ULL VARIABLE { /* var ([UNIT_WIDTH]) */
          $$ = $2;
	}
        | ALRNO { /* AR[r] ([UNIT_WIDTH]) */
          $$ = $1;
	}
        | BDRNO { /* BR[r][c] ([UNIT_WIDTH]) */
          $$ = $1;
	}
	;

ex4_dstd : VARIABLE { /* var ([UNIT_WIDTH]) */
          $$ = $1;
	}
        | ALRNO { /* AR[r] ([UNIT_WIDTH]) */
          $$ = $1;
	}
	;

exe_src1 : expr {
	  insn[last_insn].iexe.src1s = -1;
          $$ = $1;
        }
        | VARIABLE {
	  insn[last_insn].iexe.src1s = -1;
          $$ = $1;
	}
        | CGRA_ULL VARIABLE {
	  insn[last_insn].iexe.src1s = -1;
          $$ = $2;
	}
        | VARIABLE "\[" expr "\]" { /* var[s] */
	  insn[last_insn].iexe.src1s = id[$3].val;
          $$ = $1;
        }
        | CGRA_ULL VARIABLE "\[" expr "\]" { /* var[s] */
	  insn[last_insn].iexe.src1s = id[$4].val;
          $$ = $2;
        }
        | ALRNO "\[" expr "\]" { /* AR[r][s] */
	  insn[last_insn].iexe.src1s = id[$3].val;
          $$ = $1;
	}
        | BDRNO "\[" expr "\]" { /* BR[r][c][s] */
	  insn[last_insn].iexe.src1s = id[$3].val;
          $$ = $1;
	}
	;

exe_src2 : expr {
	  insn[last_insn].iexe.src2s = -1;
          $$ = $1;
        }
        | VARIABLE {
	  insn[last_insn].iexe.src2s = -1;
          $$ = $1;
	}
        | CGRA_ULL VARIABLE {
	  insn[last_insn].iexe.src2s = -1;
          $$ = $2;
	}
        | VARIABLE "\[" expr "\]" { /* var[s] */
	  insn[last_insn].iexe.src2s = id[$3].val;
          $$ = $1;
        }
        | CGRA_ULL VARIABLE "\[" expr "\]" { /* var[s] */
	  insn[last_insn].iexe.src2s = id[$4].val;
          $$ = $2;
        }
        | ALRNO "\[" expr "\]" { /* AR[r][s] */
	  insn[last_insn].iexe.src2s = id[$3].val;
          $$ = $1;
	}
        | BDRNO "\[" expr "\]" { /* BR[r][c][s] */
	  insn[last_insn].iexe.src2s = id[$3].val;
          $$ = $1;
	}
	;

exe_src3 : expr {
	  insn[last_insn].iexe.src3s = -1;
          $$ = $1;
        }
        | VARIABLE {
	  insn[last_insn].iexe.src3s = -1;
          $$ = $1;
	}
        | CGRA_ULL VARIABLE {
	  insn[last_insn].iexe.src3s = -1;
          $$ = $2;
	}
        | VARIABLE "\[" expr "\]" { /* var[s] */
	  insn[last_insn].iexe.src3s = id[$3].val;
          $$ = $1;
        }
        | CGRA_ULL VARIABLE "\[" expr "\]" { /* var[s] */
	  insn[last_insn].iexe.src3s = id[$4].val;
          $$ = $2;
        }
        | ALRNO "\[" expr "\]" { /* AR[r][s] */
	  insn[last_insn].iexe.src3s = id[$3].val;
          $$ = $1;
	}
        | BDRNO "\[" expr "\]" { /* BR[r][c][s] */
	  insn[last_insn].iexe.src3s = id[$3].val;
          $$ = $1;
	}
	;

exe_src4 : expr {
	  insn[last_insn].iexe.src4s = -1;
          $$ = $1;
        }
        | VARIABLE {
	  insn[last_insn].iexe.src4s = -1;
          $$ = $1;
	}
        | CGRA_ULL VARIABLE {
	  insn[last_insn].iexe.src4s = -1;
          $$ = $2;
	}
        | VARIABLE "\[" expr "\]" { /* var[s] */
	  insn[last_insn].iexe.src4s = id[$3].val;
          $$ = $1;
        }
        | CGRA_ULL VARIABLE "\[" expr "\]" { /* var[s] */
	  insn[last_insn].iexe.src4s = id[$4].val;
          $$ = $2;
        }
        | ALRNO "\[" expr "\]" { /* AR[r][s] */
	  insn[last_insn].iexe.src4s = id[$3].val;
          $$ = $1;
	}
        | BDRNO "\[" expr "\]" { /* BR[r][c][s] */
	  insn[last_insn].iexe.src4s = id[$3].val;
          $$ = $1;
	}
	;

exe_src5 : expr {
	  insn[last_insn].iexe.src5s = -1;
          $$ = $1;
        }
        | VARIABLE {
	  insn[last_insn].iexe.src5s = -1;
          $$ = $1;
	}
        | CGRA_ULL VARIABLE {
	  insn[last_insn].iexe.src5s = -1;
          $$ = $2;
	}
        | VARIABLE "\[" expr "\]" { /* var[s] */
	  insn[last_insn].iexe.src5s = id[$3].val;
          $$ = $1;
        }
        | CGRA_ULL VARIABLE "\[" expr "\]" { /* var[s] */
	  insn[last_insn].iexe.src5s = id[$4].val;
          $$ = $2;
        }
        | ALRNO "\[" expr "\]" { /* AR[r][s] */
	  insn[last_insn].iexe.src5s = id[$3].val;
          $$ = $1;
	}
        | BDRNO "\[" expr "\]" { /* BR[r][c][s] */
	  insn[last_insn].iexe.src5s = id[$3].val;
          $$ = $1;
	}
	;

exe_dstd : "\&" VARIABLE { /* &var */
	  insn[last_insn].iexe.exeds = -1;
          $$ = $2;
        }
        | "\&" VARIABLE "\[" expr "\]" { /* &var[s] */
	  insn[last_insn].iexe.exeds = id[$4].val;
          $$ = $2;
        }
        | "\&" ALRNO "\[" expr "\]" { /* &AR[r][s] */
	  insn[last_insn].iexe.exeds = id[$4].val;
          $$ = $2;
	}
	;

mop_ex : expr {
          $$ = $1;
        }
        | EXRNO { /* exx */
          $$ = $1;
	}
	;

mo4_srcdst : VARIABLE { /* for load/store */
          $$ = $1;
	}
        | ALRNO { /* for store */
          $$ = $1;
	}
        | BDRNO { /* for load */
          $$ = $1;
        }
	;

mop_srcdst : "\&" VARIABLE { /* for load/store */
	  insn[last_insn].imop.mopds = -1;
          $$ = $2;
	}
        | "\&" VARIABLE "\[" expr "\]" { /* for load/store */
	  insn[last_insn].imop.mopds = id[$4].val;
          $$ = $2;
        }
        | "\&" ALRNO "\[" expr "\]" { /* for store */
	  insn[last_insn].imop.mopds = id[$4].val;
          $$ = $2;
	}
        | "\&" BDRNO "\[" expr "\]" { /* for load */
	  insn[last_insn].imop.mopds = id[$4].val;
          $$ = $2;
        }
	;

mop_base : expr {
	  insn[last_insn].imop.bases = -1;
          $$ = $1;
        }
        | VARIABLE {
	  insn[last_insn].imop.bases = -1;
          $$ = $1;
	}
        | CGRA_ULL VARIABLE {
	  insn[last_insn].imop.bases = -1;
          $$ = $2;
	}
        | VARIABLE CGRA_INCR {
	  insn[last_insn].imop.updt = 1;
	  insn[last_insn].imop.bases = -1;
          $$ = $1;
	}
        | CGRA_ULL "(" VARIABLE CGRA_INCR ")" {
	  insn[last_insn].imop.updt = 1;
	  insn[last_insn].imop.bases = -1;
          $$ = $3;
	}
        | BDRNO "\[" expr "\]" {
	  insn[last_insn].imop.bases = id[$3].val;
          $$ = $1;
	}
	;

mop_offset : expr {
	  insn[last_insn].imop.offss = -1;
          $$ = $1;
        }
        | VARIABLE {
	  insn[last_insn].imop.offss = -1;
          $$ = $1;
	}
        | CGRA_ULL VARIABLE {
	  insn[last_insn].imop.offss = -1;
          $$ = $2;
	}
        | BDRNO "\[" expr "\]" {
	  insn[last_insn].imop.offss = id[$3].val;
          $$ = $1;
	}
	;

mop_top : expr {
          $$ = $1;
        }
        | VARIABLE {
          $$ = $1;
	}
        | CGRA_ULL VARIABLE {
          $$ = $2;
	}
	;

mop_len : expr {
          $$ = $1;
        }
        | VARIABLE {
          $$ = $1;
	}
        | CGRA_ULL VARIABLE {
          $$ = $2;
	}
	;

expr : expr "\*" sexpr {
          int hashval;
	  strncpy(buf, id[$1].name, BUF_MAXLEN-1);
	  strncat(buf, "*", 1);
	  strncat(buf, id[$3].name, BUF_MAXLEN-strlen(buf)-1);
	  buf[BUF_MAXLEN-1] = 0;
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = id[$1].val * id[$3].val;
	  }
          $$ = hashval;
        }
        | expr "\/" sexpr {
          int hashval;
	  strncpy(buf, id[$1].name, BUF_MAXLEN-1);
	  strncat(buf, "/", 1);
	  strncat(buf, id[$3].name, BUF_MAXLEN-strlen(buf)-1);
	  buf[BUF_MAXLEN-1] = 0;
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = id[$1].val / id[$3].val;
	  }
          $$ = hashval;
        }
        | expr "\%" sexpr {
          int hashval;
	  strncpy(buf, id[$1].name, BUF_MAXLEN-1);
	  strncat(buf, "%", 1);
	  strncat(buf, id[$3].name, BUF_MAXLEN-strlen(buf)-1);
	  buf[BUF_MAXLEN-1] = 0;
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = id[$1].val % id[$3].val;
	  }
          $$ = hashval;
        }
        | expr "\&" sexpr {
          int hashval;
	  strncpy(buf, id[$1].name, BUF_MAXLEN-1);
	  strncat(buf, "&", 1);
	  strncat(buf, id[$3].name, BUF_MAXLEN-strlen(buf)-1);
	  buf[BUF_MAXLEN-1] = 0;
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = id[$1].val & id[$3].val;
	  }
          $$ = hashval;
        }
        | expr "\^" sexpr {
          int hashval;
	  strncpy(buf, id[$1].name, BUF_MAXLEN-1);
	  strncat(buf, "^", 1);
	  strncat(buf, id[$3].name, BUF_MAXLEN-strlen(buf)-1);
	  buf[BUF_MAXLEN-1] = 0;
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = id[$1].val ^ id[$3].val;
	  }
          $$ = hashval;
        }
        | expr "\|" sexpr {
          int hashval;
	  strncpy(buf, id[$1].name, BUF_MAXLEN-1);
	  strncat(buf, "|", 1);
	  strncat(buf, id[$3].name, BUF_MAXLEN-strlen(buf)-1);
	  buf[BUF_MAXLEN-1] = 0;
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = id[$1].val | id[$3].val;
	  }
          $$ = hashval;
        }
        | sexpr {
          $$ = $1;
        }
        ;

sexpr : IMMEDIATE {
          $$ = $1;
        }
        | CGRA_ULL IMMEDIATE {
          $$ = $2;
        }
        | CGRA_UINT IMMEDIATE {
          $$ = $2;
        }
        | "\~" IMMEDIATE {
          int hashval;
	  buf[0] = '~';
	  buf[1] = 0;
	  strncat(buf, id[$2].name, BUF_MAXLEN-strlen(buf)-1);
	  buf[BUF_MAXLEN-1] = 0;
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = ~ id[$2].val;
	  }
          $$ = hashval;
        }
        | "-" IMMEDIATE {
          int hashval;
	  buf[0] = '-';
	  buf[1] = 0;
	  strncat(buf, id[$2].name, BUF_MAXLEN-strlen(buf)-1);
	  buf[BUF_MAXLEN-1] = 0;
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = - id[$2].val;
	  }
          $$ = hashval;
        }
        | "(" sexpr CGRA_SLL sexpr ")" {
          int hashval;
	  strncpy(buf, id[$2].name, BUF_MAXLEN-1);
	  strncat(buf, "<<", 2);
	  strncat(buf, id[$4].name, BUF_MAXLEN-strlen(buf)-1);
	  buf[BUF_MAXLEN-1] = 0;
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = id[$2].val << id[$4].val;
	  }
          $$ = hashval;
        }
        | "(" sexpr CGRA_SRL sexpr ")" {
          int hashval;
	  strncpy(buf, id[$2].name, BUF_MAXLEN-1);
	  strncat(buf, ">>", 2);
	  strncat(buf, id[$4].name, BUF_MAXLEN-strlen(buf)-1);
	  buf[BUF_MAXLEN-1] = 0;
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = id[$2].val >> id[$4].val;
	  }
          $$ = hashval;
        }
        ;

EMAX5TBODY : TRAN_READ {
          trans[trans_pc].rw = 0; /* READ */
	}
        | TRAN_WRITE {
          trans[trans_pc].rw = 1; /* WRITE */
        }
        ;

%%

#include "conv-c2b.h"
#include "emax5.h"
#include "lex.yy.c"

hash(s) register char *s;
{
  register int    hashval;

  for (hashval=0; *s!=0;)
    hashval += *s++;
  return(hashval % ID_NUM+1);
}

hash_clear()
{
  register int    i;

  for (i=0; i<ID_NUM; i++) {
    id[i].name  = NULL;
    id[i].type  = 0;
    id[i].itype = 0;
    id[i].row   = 0;
    id[i].col   = 0;
  }
}

hash_search(buf, reth) char *buf; int *reth;
{
  /* return 0 ... new id[reth] is assigned */
  /* return 1 ... old id[reth] is found */
  char *bufptr;
  int  hashval, hashsave, buflen;

  /* hash */
  hashval = hashsave = hash(buf);
  while (id[hashval].name != NULL) {
    if (!strncmp(buf, id[hashval].name, BUF_MAXLEN)) {
      *reth = hashval;
      return (1);
    }
    hashval = rehash(hashval);
    if (hashval == hashsave)
      break;
  }
  if (id[hashval].name != NULL) {
    yyerror("too many IDs");
    fprintf(stderr, "current ID_NUM is %d\n", ID_NUM);
    exit(1);
  }

  /* new number */
  buflen = strlen(buf)+1;
  id[hashval].name = bufptr = malloc(buflen);
  id[hashval].row = -1; /* init */
  id[hashval].col = -1; /* init */
  strncpy(bufptr, buf, buflen);
  *reth = hashval;
  return(0);
}

hash_reg_immediate(imm) Ull imm;
{
  int hashval;
  /* return hashval */
  snprintf(buf, BUF_MAXLEN, "%lldLL", imm);
  if (!hash_search(buf, &hashval)) { /* not found */
    id[hashval].type = T_IMMEDIATE;
    id[hashval].val = imm;
  }
  return (hashval);
}

yyerror(s) char *s;
{
  if (++y_errornum == 1)
    fprintf(stderr, "\n");
#if 0
  fprintf(stderr, "line %d: \"%s\": %s.\n", y_lineno, yytext, s);
#endif
  /* lex -l により,yylinenoが使える */
  fprintf(stderr, "err%d: line %d: \"%s\": %s.\n", y_errornum, yylineno, yytext, s);
}
