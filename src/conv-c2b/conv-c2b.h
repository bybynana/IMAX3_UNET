
/* EMAX5 Compiter                      */
/*        Copyright (C) 2012 by NAIST. */
/*         Primary writer: Y.Nakashima */
/*                nakashim@is.naist.jp */

/*=======================================================================
=       conv-c2b.h      2012/9/21                                       =
=======================================================================*/
#include <sys/types.h>
#include <sys/param.h>
#include <sys/times.h>
#include <sys/stat.h>
#include <signal.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define         OBJSUFX "-emax5.c"
#define         FIGSUFX "-emax5.obj"

char            *srcprog;
char            *objprog;
char            *figfile;
FILE            *ofile; /* object file */
FILE            *ffile; /* tgif file */

#define YY_SKIP_YYWRAP

int             y_lineno;
int             y_errornum;
int             y_emax5a_seqno;

#define         yywrap()        (1)
#define         rehash(x)       ((x+137) % ID_NUM+1)

/* variable */
#define         ID_NUM          4096
/* variable.type */
#define         T_NONE          0x00
#define         T_IMMEDIATE     0x01
#define         T_EXRNO         0x02
#define         T_ALRNO         0x03
#define         T_BDRNO         0x04
#define         T_VARIABLE      0x05

#define BUF_MAXLEN 1024
char buf[BUF_MAXLEN+1];

struct id {
  char               *name;
  char               type;  /* T_XXX */
  char               itype; /* ITYPE_XXX where id is defined as dst */
  char               row;   /* -1:undefined, 0-EMAX_DEPTH-1:location of destination */
  char               col;   /* -1:undefined, 0-EMAX_WIDTH-1:location of destination */
  unsigned long long val;   /* immediate / absolute address */
} id[ID_NUM];
