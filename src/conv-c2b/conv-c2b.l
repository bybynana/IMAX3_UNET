
/* EMAX5 Compiler                      */
/*        Copyright (C) 2012 by NAIST. */
/*         Primary writer: Y.Nakashima */
/*                nakashim@is.naist.jp */

/* conv-c2b.l   2012/6/15 */

%e      300
%p      700
%n      100
%k      60
%a      300
%o      500

%{
double      atof();
void        *malloc();
static int  indx;
%}

%%
\n                   { ++y_lineno; return(EOL); }
^[^\/\n].*           { return(ARMV8); }
^\/[^-\n].*          { return(ARMV8); }
^\/-EMAX5AB-\/       { return(EMAX5ABEGIN); }
^\/-EMAX5AS-\/       { return(EMAX5ASTATEM); }
^\/-EMAX5AE-\/       { return(EMAX5AEND); }
^\/-EMAX5AD-\/       { return(EMAX5ADRAIN); }
^\/-EMAX5TB-\/       { return(EMAX5TBEGIN); }
^\/-EMAX5TS-\/       { return(EMAX5TSTATEM); }
^\/-EMAX5TE-\/       { return(EMAX5TEND); }
\(Ull\)              { return(CGRA_ULL); }
\(Uint\)             { return(CGRA_UINT); }
"<<"                 { return(CGRA_SLL); }
">>"                 { return(CGRA_SRL); }
while                { return(CGRA_WHILE); }
cex                  { return(CGRA_CEX); }
ex4                  { return(CGRA_EX4); }
exe                  { return(CGRA_EXE); }
mo4                  { return(CGRA_MO4); }
mop                  { return(CGRA_MOP); }
\-\-                 {
    /* copy "-1LL" --> buf[] */
    yylval = hash_reg_immediate(-1LL);
    return(CGRA_DECR);
}
\+\+                 { return(CGRA_INCR); }
read                 { return(TRAN_READ); }
write                { return(TRAN_WRITE); }
[\(\)\[\]\{\},\;\*\/\%\+\-\&\|\^\~] { return(*yytext); }
[ \t]+ ;

\(\(void[ ]*\*\)0\)  {
    /* copy yytext[] --> buf[] */
    for (indx=0; indx<yyleng && indx<BUF_MAXLEN; indx++)
        buf[indx] = yytext[indx];
    buf[indx] = 0;
    if (!hash_search(buf, &yylval)) { /* not found */
      id[yylval].type = T_IMMEDIATE;
      id[yylval].val = 0;
    }
    return(IMMEDIATE);
}

0x[0-9A-Fa-f]+   |
0x[0-9A-Fa-f]+LL |
[0-9]+           |
[0-9]+LL         |
-[0-9]+          |
-[0-9]+LL        {
    /* copy yytext[] --> buf[] */
    for (indx=0; indx<yyleng && indx<BUF_MAXLEN; indx++)
        buf[indx] = yytext[indx];
    buf[indx] = 0;
    if (!hash_search(buf, &yylval)) { /* not found */
      id[yylval].type = T_IMMEDIATE;
      id[yylval].val = strtoll(buf, NULL, 0);
    }
    return(IMMEDIATE);
}

ex[0-9] {
    /* copy yytext[] --> buf[] */
    for (indx=0; indx<yyleng && indx<BUF_MAXLEN; indx++)
        buf[indx] = yytext[indx];
    buf[indx] = 0;
    if (!hash_search(buf, &yylval)) { /* not found */
      id[yylval].type = T_EXRNO;
      id[yylval].val = strtoll(buf+3, NULL, 0);
    }
    return(EXRNO);
}

AR\[[0-9][0-9]*\] { /* row only */
    /* copy yytext[] --> buf[] */
    for (indx=0; indx<yyleng && indx<BUF_MAXLEN; indx++)
        buf[indx] = yytext[indx];
    buf[indx] = 0;
    if (!hash_search(buf, &yylval)) { /* not found */
      id[yylval].type = T_ALRNO;
      id[yylval].val = strtoll(buf+3, NULL, 0);
    }
    return(ALRNO);
}

BR\[[0-9][0-9]*\]\[[0-3]\] { /* row+column only */
    /* copy yytext[] --> buf[] */
    for (indx=0; indx<yyleng && indx<BUF_MAXLEN; indx++)
        buf[indx] = yytext[indx];
    buf[indx] = 0;
    if (!hash_search(buf, &yylval)) { /* not found */
      id[yylval].type = T_BDRNO;
      id[yylval].val = strtoll(strchr(buf, '\[')+1, NULL, 0)*EMAX_WIDTH+strtoll(strrchr(buf, '\[')+1, NULL, 0);
    }
    return(BDRNO);
}

\.*[A-Za-z_][A-Za-z0-9_]* |
[A-Za-z_][A-Za-z0-9_]* {
    /* copy yytext[] --> buf[] */
    for (indx=0; indx<yyleng && indx<BUF_MAXLEN; indx++)
        buf[indx] = yytext[indx];
    buf[indx] = 0;
    if (!hash_search(buf, &yylval)) { /* not found */
      id[yylval].type = T_VARIABLE;
      id[yylval].val  = 0;
    }
    return(VARIABLE);
}
