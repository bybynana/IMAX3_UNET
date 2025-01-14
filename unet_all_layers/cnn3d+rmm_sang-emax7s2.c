/* EMAXSC start */
void emax7sc_pth_cnn_00(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit0 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (0 && SCBR[63].enq[CHIP]==SCBR[63].deq[CHIP]) || (0<57 && SCBR[0].enq[CHIP]!=SCBR[0].deq[CHIP])) continue;
SCBR[63].deq[CHIP] = 1-SCBR[63].deq[CHIP];
enq[CHIP] = SCBR[0].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((1&1)&&INIT0[CHIP]) ? SCBR[63].r[CHIP][enq[CHIP]][3] : alud[CHIP][2], 0);
ex2 = exm(((1&2)&&!INIT0[CHIP]) ? 0 : SCBR[63].r[CHIP][enq[CHIP]][4], 0);
t2 = (ex1>>32&0x00000000ffffffffLL)+(ex2>>32&0x00000000ffffffffLL);
t2 &= 0x00000000ffffffffLL;
t0 = (ex1    &0x00000000ffffffffLL)+(ex2    &0x00000000ffffffffLL);
t0 &= 0x00000000ffffffffLL;
ex1_outd = (t2<<32)|(t0);
ex4 = 0==0 ? 0x00000000ffffffffLL : 0==1 ? SCBR[63].r[CHIP][enq[CHIP]][4] : SCBR[63].r[CHIP][enq[CHIP]][0];
ex2_outd = ex1_outd & ex4;
alud[CHIP][2] = ex2_outd;
SCBR[0].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((2&1)&&INIT0[CHIP]) ? SCBR[63].r[CHIP][enq[CHIP]][5] : alud[CHIP][3], 0);
ex2 = exm(((2&2)&&!INIT0[CHIP]) ? 0 : SCBR[63].r[CHIP][enq[CHIP]][6], 0);
t2 = (ex1>>32&0x00000000ffffffffLL)+(ex2>>32&0x00000000ffffffffLL);
t2 &= 0x00000000ffffffffLL;
t0 = (ex1    &0x00000000ffffffffLL)+(ex2    &0x00000000ffffffffLL);
t0 &= 0x00000000ffffffffLL;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[0].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[0].enq[CHIP] = 1-SCBR[0].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_01(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit1 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (1 && SCBR[0].enq[CHIP]==SCBR[0].deq[CHIP]) || (1<57 && SCBR[1].enq[CHIP]!=SCBR[1].deq[CHIP])) continue;
SCBR[0].deq[CHIP] = 1-SCBR[0].deq[CHIP];
enq[CHIP] = SCBR[1].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[0].r[CHIP][enq[CHIP]][14] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[0].r[CHIP][enq[CHIP]][10], 0);
t2 = (ex1>>32&0x00000000ffffffffLL)+(ex2>>32&0x00000000ffffffffLL);
t2 &= 0x00000000ffffffffLL;
t0 = (ex1    &0x00000000ffffffffLL)+(ex2    &0x00000000ffffffffLL);
t0 &= 0x00000000ffffffffLL;
ex1_outd = (t2<<32)|(t0);
ex4 = 0==0 ? 0x00000000ffffffffLL : 0==1 ? SCBR[0].r[CHIP][enq[CHIP]][10] : SCBR[0].r[CHIP][enq[CHIP]][0];
ex2_outd = ex1_outd & ex4;
alud[CHIP][0] = ex2_outd;
SCBR[1].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[1].enq[CHIP] = 1-SCBR[1].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_02(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit2 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (2 && SCBR[1].enq[CHIP]==SCBR[1].deq[CHIP]) || (2<57 && SCBR[2].enq[CHIP]!=SCBR[2].deq[CHIP])) continue;
SCBR[1].deq[CHIP] = 1-SCBR[1].deq[CHIP];
enq[CHIP] = SCBR[2].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[2].r[CHIP][enq[CHIP]][2] = SCBR[1].r[CHIP][enq[CHIP]][2];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[1].r[CHIP][enq[CHIP]][0]:SCM1[2].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[1].r[CHIP][enq[CHIP]][0] : SCM1[2].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[2].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[1].r[CHIP][enq[CHIP]][0]:SCM0[2].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[1].r[CHIP][enq[CHIP]][0] : SCM0[2].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[2].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[2].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[2].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[1].r[CHIP][enq[CHIP]][0]:SCM1[2].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[1].r[CHIP][enq[CHIP]][0] : SCM1[2].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[2].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[1].r[CHIP][enq[CHIP]][0]:SCM0[2].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[1].r[CHIP][enq[CHIP]][0] : SCM0[2].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[2].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[2].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[2].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[1].r[CHIP][enq[CHIP]][0]:SCM1[2].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[1].r[CHIP][enq[CHIP]][2] : SCM1[2].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[2].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[2].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[2].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[1].r[CHIP][enq[CHIP]][0]:SCM0[2].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[1].r[CHIP][enq[CHIP]][2] : SCM0[2].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[2].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[2].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[2].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[2].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[2].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[2].enq[CHIP] = 1-SCBR[2].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_03(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit3 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (3 && SCBR[2].enq[CHIP]==SCBR[2].deq[CHIP]) || (3<57 && SCBR[3].enq[CHIP]!=SCBR[3].deq[CHIP])) continue;
SCBR[2].deq[CHIP] = 1-SCBR[2].deq[CHIP];
enq[CHIP] = SCBR[3].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[3].r[CHIP][enq[CHIP]][3] = SCBR[2].r[CHIP][enq[CHIP]][2];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[2].r[CHIP][enq[CHIP]][0]:SCM1[3].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[2].r[CHIP][enq[CHIP]][0] : SCM1[3].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[3].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[2].r[CHIP][enq[CHIP]][0]:SCM0[3].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[2].r[CHIP][enq[CHIP]][0] : SCM0[3].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[3].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[3].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[3].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[2].r[CHIP][enq[CHIP]][0]:SCM1[3].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[2].r[CHIP][enq[CHIP]][0] : SCM1[3].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[3].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[2].r[CHIP][enq[CHIP]][0]:SCM0[3].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[2].r[CHIP][enq[CHIP]][0] : SCM0[3].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[3].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[3].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[3].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[2].r[CHIP][enq[CHIP]][0]:SCM1[3].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[2].r[CHIP][enq[CHIP]][2] : SCM1[3].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[3].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[3].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[3].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[2].r[CHIP][enq[CHIP]][0]:SCM0[3].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[2].r[CHIP][enq[CHIP]][2] : SCM0[3].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[3].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[3].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[3].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[3].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[3].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[2].r[CHIP][enq[CHIP]][8] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[2].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32);
f0.f = f1.f * f2.f;
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2);
f0.f = f1.f * f2.f;
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[3].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[2].r[CHIP][enq[CHIP]][8] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[2].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32);
f0.f = f1.f * f2.f;
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2);
f0.f = f1.f * f2.f;
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[3].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[2].r[CHIP][enq[CHIP]][8] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[2].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32);
f0.f = f1.f * f2.f;
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2);
f0.f = f1.f * f2.f;
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[3].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[2].r[CHIP][enq[CHIP]][8] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[2].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32);
f0.f = f1.f * f2.f;
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2);
f0.f = f1.f * f2.f;
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[3].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[3].enq[CHIP] = 1-SCBR[3].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_04(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit4 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (4 && SCBR[3].enq[CHIP]==SCBR[3].deq[CHIP]) || (4<57 && SCBR[4].enq[CHIP]!=SCBR[4].deq[CHIP])) continue;
SCBR[3].deq[CHIP] = 1-SCBR[3].deq[CHIP];
enq[CHIP] = SCBR[4].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[4].r[CHIP][enq[CHIP]][3] = SCBR[3].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[3].r[CHIP][enq[CHIP]][0]:SCM1[4].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[3].r[CHIP][enq[CHIP]][0] : SCM1[4].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[4].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[3].r[CHIP][enq[CHIP]][0]:SCM0[4].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[3].r[CHIP][enq[CHIP]][0] : SCM0[4].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[4].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[4].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[4].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[3].r[CHIP][enq[CHIP]][0]:SCM1[4].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[3].r[CHIP][enq[CHIP]][0] : SCM1[4].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[4].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[3].r[CHIP][enq[CHIP]][0]:SCM0[4].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[3].r[CHIP][enq[CHIP]][0] : SCM0[4].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[4].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[4].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[4].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[3].r[CHIP][enq[CHIP]][0]:SCM1[4].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[3].r[CHIP][enq[CHIP]][3] : SCM1[4].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[4].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[4].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[4].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[3].r[CHIP][enq[CHIP]][0]:SCM0[4].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[3].r[CHIP][enq[CHIP]][3] : SCM0[4].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[4].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[4].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[4].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[4].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[4].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[3].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[3].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[3].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[4].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[3].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[3].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[3].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[4].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[3].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[3].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[3].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[4].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[3].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[3].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[3].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[4].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[4].enq[CHIP] = 1-SCBR[4].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_05(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit5 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (5 && SCBR[4].enq[CHIP]==SCBR[4].deq[CHIP]) || (5<57 && SCBR[5].enq[CHIP]!=SCBR[5].deq[CHIP])) continue;
SCBR[4].deq[CHIP] = 1-SCBR[4].deq[CHIP];
enq[CHIP] = SCBR[5].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[5].r[CHIP][enq[CHIP]][3] = SCBR[4].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[4].r[CHIP][enq[CHIP]][0]:SCM1[5].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[4].r[CHIP][enq[CHIP]][0] : SCM1[5].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[5].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[4].r[CHIP][enq[CHIP]][0]:SCM0[5].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[4].r[CHIP][enq[CHIP]][0] : SCM0[5].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[5].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[5].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[5].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[4].r[CHIP][enq[CHIP]][0]:SCM1[5].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[4].r[CHIP][enq[CHIP]][0] : SCM1[5].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[5].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[4].r[CHIP][enq[CHIP]][0]:SCM0[5].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[4].r[CHIP][enq[CHIP]][0] : SCM0[5].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[5].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[5].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[5].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[4].r[CHIP][enq[CHIP]][0]:SCM1[5].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[4].r[CHIP][enq[CHIP]][3] : SCM1[5].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[5].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[5].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[5].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[4].r[CHIP][enq[CHIP]][0]:SCM0[5].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[4].r[CHIP][enq[CHIP]][3] : SCM0[5].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[5].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[5].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[5].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[5].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[5].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[4].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[4].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[4].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[5].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[4].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[4].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[4].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[5].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[4].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[4].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[4].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[5].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[4].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[4].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[4].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[5].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[5].enq[CHIP] = 1-SCBR[5].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_06(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit6 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (6 && SCBR[5].enq[CHIP]==SCBR[5].deq[CHIP]) || (6<57 && SCBR[6].enq[CHIP]!=SCBR[6].deq[CHIP])) continue;
SCBR[5].deq[CHIP] = 1-SCBR[5].deq[CHIP];
enq[CHIP] = SCBR[6].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[6].r[CHIP][enq[CHIP]][3] = SCBR[5].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[5].r[CHIP][enq[CHIP]][0]:SCM1[6].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[5].r[CHIP][enq[CHIP]][0] : SCM1[6].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[6].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[5].r[CHIP][enq[CHIP]][0]:SCM0[6].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[5].r[CHIP][enq[CHIP]][0] : SCM0[6].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[6].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[6].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[6].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[5].r[CHIP][enq[CHIP]][0]:SCM1[6].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[5].r[CHIP][enq[CHIP]][0] : SCM1[6].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[6].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[5].r[CHIP][enq[CHIP]][0]:SCM0[6].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[5].r[CHIP][enq[CHIP]][0] : SCM0[6].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[6].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[6].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[6].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[5].r[CHIP][enq[CHIP]][0]:SCM1[6].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[5].r[CHIP][enq[CHIP]][3] : SCM1[6].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[6].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[6].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[6].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[5].r[CHIP][enq[CHIP]][0]:SCM0[6].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[5].r[CHIP][enq[CHIP]][3] : SCM0[6].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[6].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[6].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[6].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[6].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[6].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[5].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[5].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[5].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[6].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[5].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[5].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[5].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[6].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[5].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[5].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[5].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[6].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[5].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[5].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[5].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[6].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[6].enq[CHIP] = 1-SCBR[6].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_07(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit7 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (7 && SCBR[6].enq[CHIP]==SCBR[6].deq[CHIP]) || (7<57 && SCBR[7].enq[CHIP]!=SCBR[7].deq[CHIP])) continue;
SCBR[6].deq[CHIP] = 1-SCBR[6].deq[CHIP];
enq[CHIP] = SCBR[7].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[7].r[CHIP][enq[CHIP]][3] = SCBR[6].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[6].r[CHIP][enq[CHIP]][0]:SCM1[7].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[6].r[CHIP][enq[CHIP]][0] : SCM1[7].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[7].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[6].r[CHIP][enq[CHIP]][0]:SCM0[7].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[6].r[CHIP][enq[CHIP]][0] : SCM0[7].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[7].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[7].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[7].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[6].r[CHIP][enq[CHIP]][0]:SCM1[7].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[6].r[CHIP][enq[CHIP]][0] : SCM1[7].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[7].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[6].r[CHIP][enq[CHIP]][0]:SCM0[7].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[6].r[CHIP][enq[CHIP]][0] : SCM0[7].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[7].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[7].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[7].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[6].r[CHIP][enq[CHIP]][0]:SCM1[7].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[6].r[CHIP][enq[CHIP]][3] : SCM1[7].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[7].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[7].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[7].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[6].r[CHIP][enq[CHIP]][0]:SCM0[7].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[6].r[CHIP][enq[CHIP]][3] : SCM0[7].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[7].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[7].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[7].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[7].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[7].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[6].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[6].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[6].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[7].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[6].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[6].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[6].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[7].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[6].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[6].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[6].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[7].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[6].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[6].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[6].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[7].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[7].enq[CHIP] = 1-SCBR[7].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_08(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit8 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (8 && SCBR[7].enq[CHIP]==SCBR[7].deq[CHIP]) || (8<57 && SCBR[8].enq[CHIP]!=SCBR[8].deq[CHIP])) continue;
SCBR[7].deq[CHIP] = 1-SCBR[7].deq[CHIP];
enq[CHIP] = SCBR[8].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[8].r[CHIP][enq[CHIP]][3] = SCBR[7].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[7].r[CHIP][enq[CHIP]][0]:SCM1[8].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[7].r[CHIP][enq[CHIP]][0] : SCM1[8].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[8].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[7].r[CHIP][enq[CHIP]][0]:SCM0[8].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[7].r[CHIP][enq[CHIP]][0] : SCM0[8].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[8].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[8].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[8].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[7].r[CHIP][enq[CHIP]][0]:SCM1[8].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[7].r[CHIP][enq[CHIP]][0] : SCM1[8].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[8].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[7].r[CHIP][enq[CHIP]][0]:SCM0[8].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[7].r[CHIP][enq[CHIP]][0] : SCM0[8].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[8].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[8].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[8].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[7].r[CHIP][enq[CHIP]][0]:SCM1[8].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[7].r[CHIP][enq[CHIP]][3] : SCM1[8].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[8].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[8].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[8].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[7].r[CHIP][enq[CHIP]][0]:SCM0[8].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[7].r[CHIP][enq[CHIP]][3] : SCM0[8].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[8].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[8].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[8].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[8].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[8].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[7].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[7].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[7].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[8].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[7].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[7].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[7].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[8].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[7].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[7].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[7].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[8].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[7].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[7].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[7].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[8].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[8].enq[CHIP] = 1-SCBR[8].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_09(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit9 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (9 && SCBR[8].enq[CHIP]==SCBR[8].deq[CHIP]) || (9<57 && SCBR[9].enq[CHIP]!=SCBR[9].deq[CHIP])) continue;
SCBR[8].deq[CHIP] = 1-SCBR[8].deq[CHIP];
enq[CHIP] = SCBR[9].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[9].r[CHIP][enq[CHIP]][3] = SCBR[8].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[8].r[CHIP][enq[CHIP]][0]:SCM1[9].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[8].r[CHIP][enq[CHIP]][0] : SCM1[9].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[9].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[8].r[CHIP][enq[CHIP]][0]:SCM0[9].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[8].r[CHIP][enq[CHIP]][0] : SCM0[9].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[9].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[9].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[9].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[8].r[CHIP][enq[CHIP]][0]:SCM1[9].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[8].r[CHIP][enq[CHIP]][0] : SCM1[9].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[9].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[8].r[CHIP][enq[CHIP]][0]:SCM0[9].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[8].r[CHIP][enq[CHIP]][0] : SCM0[9].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[9].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[9].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[9].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[8].r[CHIP][enq[CHIP]][0]:SCM1[9].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[8].r[CHIP][enq[CHIP]][3] : SCM1[9].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[9].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[9].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[9].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[8].r[CHIP][enq[CHIP]][0]:SCM0[9].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[8].r[CHIP][enq[CHIP]][3] : SCM0[9].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[9].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[9].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[9].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[9].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[9].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[8].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[8].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[8].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[9].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[8].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[8].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[8].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[9].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[8].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[8].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[8].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[9].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[8].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[8].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[8].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[9].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[9].enq[CHIP] = 1-SCBR[9].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_10(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit10 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (10 && SCBR[9].enq[CHIP]==SCBR[9].deq[CHIP]) || (10<57 && SCBR[10].enq[CHIP]!=SCBR[10].deq[CHIP])) continue;
SCBR[9].deq[CHIP] = 1-SCBR[9].deq[CHIP];
enq[CHIP] = SCBR[10].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[10].r[CHIP][enq[CHIP]][3] = SCBR[9].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[9].r[CHIP][enq[CHIP]][0]:SCM1[10].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[9].r[CHIP][enq[CHIP]][0] : SCM1[10].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[10].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[9].r[CHIP][enq[CHIP]][0]:SCM0[10].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[9].r[CHIP][enq[CHIP]][0] : SCM0[10].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[10].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[10].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[10].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[9].r[CHIP][enq[CHIP]][0]:SCM1[10].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[9].r[CHIP][enq[CHIP]][0] : SCM1[10].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[10].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[9].r[CHIP][enq[CHIP]][0]:SCM0[10].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[9].r[CHIP][enq[CHIP]][0] : SCM0[10].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[10].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[10].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[10].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[9].r[CHIP][enq[CHIP]][0]:SCM1[10].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[9].r[CHIP][enq[CHIP]][3] : SCM1[10].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[10].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[10].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[10].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[9].r[CHIP][enq[CHIP]][0]:SCM0[10].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[9].r[CHIP][enq[CHIP]][3] : SCM0[10].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[10].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[10].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[10].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[10].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[10].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[9].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[9].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[9].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[10].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[9].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[9].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[9].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[10].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[9].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[9].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[9].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[10].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[9].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[9].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[9].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[10].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[10].enq[CHIP] = 1-SCBR[10].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_11(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit11 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (11 && SCBR[10].enq[CHIP]==SCBR[10].deq[CHIP]) || (11<57 && SCBR[11].enq[CHIP]!=SCBR[11].deq[CHIP])) continue;
SCBR[10].deq[CHIP] = 1-SCBR[10].deq[CHIP];
enq[CHIP] = SCBR[11].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[11].r[CHIP][enq[CHIP]][3] = SCBR[10].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[10].r[CHIP][enq[CHIP]][0]:SCM1[11].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[10].r[CHIP][enq[CHIP]][0] : SCM1[11].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[11].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[10].r[CHIP][enq[CHIP]][0]:SCM0[11].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[10].r[CHIP][enq[CHIP]][0] : SCM0[11].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[11].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[11].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[11].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[10].r[CHIP][enq[CHIP]][0]:SCM1[11].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[10].r[CHIP][enq[CHIP]][0] : SCM1[11].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[11].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[10].r[CHIP][enq[CHIP]][0]:SCM0[11].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[10].r[CHIP][enq[CHIP]][0] : SCM0[11].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[11].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[11].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[11].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[10].r[CHIP][enq[CHIP]][0]:SCM1[11].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[10].r[CHIP][enq[CHIP]][3] : SCM1[11].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[11].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[11].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[11].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[10].r[CHIP][enq[CHIP]][0]:SCM0[11].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[10].r[CHIP][enq[CHIP]][3] : SCM0[11].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[11].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[11].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[11].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[11].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[11].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[10].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[10].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[10].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[11].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[10].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[10].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[10].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[11].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[10].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[10].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[10].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[11].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[10].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[10].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[10].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[11].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[11].enq[CHIP] = 1-SCBR[11].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_12(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit12 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (12 && SCBR[11].enq[CHIP]==SCBR[11].deq[CHIP]) || (12<57 && SCBR[12].enq[CHIP]!=SCBR[12].deq[CHIP])) continue;
SCBR[11].deq[CHIP] = 1-SCBR[11].deq[CHIP];
enq[CHIP] = SCBR[12].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[12].r[CHIP][enq[CHIP]][3] = SCBR[11].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[11].r[CHIP][enq[CHIP]][0]:SCM1[12].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[11].r[CHIP][enq[CHIP]][0] : SCM1[12].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[12].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[11].r[CHIP][enq[CHIP]][0]:SCM0[12].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[11].r[CHIP][enq[CHIP]][0] : SCM0[12].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[12].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[12].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[12].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[11].r[CHIP][enq[CHIP]][0]:SCM1[12].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[11].r[CHIP][enq[CHIP]][0] : SCM1[12].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[12].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[11].r[CHIP][enq[CHIP]][0]:SCM0[12].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[11].r[CHIP][enq[CHIP]][0] : SCM0[12].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[12].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[12].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[12].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[11].r[CHIP][enq[CHIP]][0]:SCM1[12].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[11].r[CHIP][enq[CHIP]][3] : SCM1[12].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[12].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[12].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[12].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[11].r[CHIP][enq[CHIP]][0]:SCM0[12].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[11].r[CHIP][enq[CHIP]][3] : SCM0[12].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[12].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[12].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[12].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[12].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[12].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[11].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[11].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[11].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[12].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[11].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[11].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[11].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[12].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[11].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[11].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[11].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[12].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[11].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[11].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[11].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[12].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[12].enq[CHIP] = 1-SCBR[12].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_13(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit13 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (13 && SCBR[12].enq[CHIP]==SCBR[12].deq[CHIP]) || (13<57 && SCBR[13].enq[CHIP]!=SCBR[13].deq[CHIP])) continue;
SCBR[12].deq[CHIP] = 1-SCBR[12].deq[CHIP];
enq[CHIP] = SCBR[13].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[13].r[CHIP][enq[CHIP]][3] = SCBR[12].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[12].r[CHIP][enq[CHIP]][0]:SCM1[13].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[12].r[CHIP][enq[CHIP]][0] : SCM1[13].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[13].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[12].r[CHIP][enq[CHIP]][0]:SCM0[13].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[12].r[CHIP][enq[CHIP]][0] : SCM0[13].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[13].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[13].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[13].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[12].r[CHIP][enq[CHIP]][0]:SCM1[13].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[12].r[CHIP][enq[CHIP]][0] : SCM1[13].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[13].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[12].r[CHIP][enq[CHIP]][0]:SCM0[13].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[12].r[CHIP][enq[CHIP]][0] : SCM0[13].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[13].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[13].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[13].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[12].r[CHIP][enq[CHIP]][0]:SCM1[13].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[12].r[CHIP][enq[CHIP]][3] : SCM1[13].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[13].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[13].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[13].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[12].r[CHIP][enq[CHIP]][0]:SCM0[13].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[12].r[CHIP][enq[CHIP]][3] : SCM0[13].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[13].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[13].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[13].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[13].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[13].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[12].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[12].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[12].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[13].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[12].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[12].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[12].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[13].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[12].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[12].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[12].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[13].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[12].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[12].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[12].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[13].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[13].enq[CHIP] = 1-SCBR[13].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_14(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit14 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (14 && SCBR[13].enq[CHIP]==SCBR[13].deq[CHIP]) || (14<57 && SCBR[14].enq[CHIP]!=SCBR[14].deq[CHIP])) continue;
SCBR[13].deq[CHIP] = 1-SCBR[13].deq[CHIP];
enq[CHIP] = SCBR[14].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[14].r[CHIP][enq[CHIP]][3] = SCBR[13].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[13].r[CHIP][enq[CHIP]][0]:SCM1[14].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[13].r[CHIP][enq[CHIP]][0] : SCM1[14].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[14].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[13].r[CHIP][enq[CHIP]][0]:SCM0[14].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[13].r[CHIP][enq[CHIP]][0] : SCM0[14].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[14].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[14].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[14].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[13].r[CHIP][enq[CHIP]][0]:SCM1[14].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[13].r[CHIP][enq[CHIP]][0] : SCM1[14].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[14].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[13].r[CHIP][enq[CHIP]][0]:SCM0[14].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[13].r[CHIP][enq[CHIP]][0] : SCM0[14].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[14].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[14].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[14].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[13].r[CHIP][enq[CHIP]][0]:SCM1[14].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[13].r[CHIP][enq[CHIP]][3] : SCM1[14].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[14].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[14].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[14].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[13].r[CHIP][enq[CHIP]][0]:SCM0[14].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[13].r[CHIP][enq[CHIP]][3] : SCM0[14].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[14].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[14].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[14].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[14].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[14].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[13].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[13].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[13].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[14].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[13].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[13].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[13].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[14].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[13].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[13].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[13].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[14].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[13].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[13].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[13].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[14].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[14].enq[CHIP] = 1-SCBR[14].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_15(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit15 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (15 && SCBR[14].enq[CHIP]==SCBR[14].deq[CHIP]) || (15<57 && SCBR[15].enq[CHIP]!=SCBR[15].deq[CHIP])) continue;
SCBR[14].deq[CHIP] = 1-SCBR[14].deq[CHIP];
enq[CHIP] = SCBR[15].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[15].r[CHIP][enq[CHIP]][3] = SCBR[14].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[14].r[CHIP][enq[CHIP]][0]:SCM1[15].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[14].r[CHIP][enq[CHIP]][0] : SCM1[15].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[15].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[14].r[CHIP][enq[CHIP]][0]:SCM0[15].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[14].r[CHIP][enq[CHIP]][0] : SCM0[15].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[15].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[15].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[15].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[14].r[CHIP][enq[CHIP]][0]:SCM1[15].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[14].r[CHIP][enq[CHIP]][0] : SCM1[15].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[15].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[14].r[CHIP][enq[CHIP]][0]:SCM0[15].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[14].r[CHIP][enq[CHIP]][0] : SCM0[15].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[15].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[15].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[15].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[14].r[CHIP][enq[CHIP]][0]:SCM1[15].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[14].r[CHIP][enq[CHIP]][3] : SCM1[15].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[15].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[15].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[15].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[14].r[CHIP][enq[CHIP]][0]:SCM0[15].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[14].r[CHIP][enq[CHIP]][3] : SCM0[15].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[15].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[15].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[15].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[15].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[15].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[14].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[14].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[14].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[15].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[14].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[14].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[14].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[15].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[14].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[14].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[14].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[15].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[14].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[14].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[14].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[15].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[15].enq[CHIP] = 1-SCBR[15].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_16(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit16 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (16 && SCBR[15].enq[CHIP]==SCBR[15].deq[CHIP]) || (16<57 && SCBR[16].enq[CHIP]!=SCBR[16].deq[CHIP])) continue;
SCBR[15].deq[CHIP] = 1-SCBR[15].deq[CHIP];
enq[CHIP] = SCBR[16].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[16].r[CHIP][enq[CHIP]][3] = SCBR[15].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[15].r[CHIP][enq[CHIP]][0]:SCM1[16].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[15].r[CHIP][enq[CHIP]][0] : SCM1[16].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[16].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[15].r[CHIP][enq[CHIP]][0]:SCM0[16].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[15].r[CHIP][enq[CHIP]][0] : SCM0[16].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[16].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[16].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[16].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[15].r[CHIP][enq[CHIP]][0]:SCM1[16].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[15].r[CHIP][enq[CHIP]][0] : SCM1[16].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[16].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[15].r[CHIP][enq[CHIP]][0]:SCM0[16].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[15].r[CHIP][enq[CHIP]][0] : SCM0[16].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[16].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[16].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[16].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[15].r[CHIP][enq[CHIP]][0]:SCM1[16].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[15].r[CHIP][enq[CHIP]][3] : SCM1[16].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[16].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[16].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[16].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[15].r[CHIP][enq[CHIP]][0]:SCM0[16].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[15].r[CHIP][enq[CHIP]][3] : SCM0[16].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[16].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[16].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[16].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[16].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[16].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[15].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[15].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[15].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[16].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[15].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[15].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[15].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[16].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[15].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[15].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[15].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[16].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[15].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[15].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[15].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[16].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[16].enq[CHIP] = 1-SCBR[16].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_17(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit17 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (17 && SCBR[16].enq[CHIP]==SCBR[16].deq[CHIP]) || (17<57 && SCBR[17].enq[CHIP]!=SCBR[17].deq[CHIP])) continue;
SCBR[16].deq[CHIP] = 1-SCBR[16].deq[CHIP];
enq[CHIP] = SCBR[17].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[17].r[CHIP][enq[CHIP]][3] = SCBR[16].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[16].r[CHIP][enq[CHIP]][0]:SCM1[17].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[16].r[CHIP][enq[CHIP]][0] : SCM1[17].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[17].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[16].r[CHIP][enq[CHIP]][0]:SCM0[17].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[16].r[CHIP][enq[CHIP]][0] : SCM0[17].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[17].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[17].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[17].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[16].r[CHIP][enq[CHIP]][0]:SCM1[17].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[16].r[CHIP][enq[CHIP]][0] : SCM1[17].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[17].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[16].r[CHIP][enq[CHIP]][0]:SCM0[17].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[16].r[CHIP][enq[CHIP]][0] : SCM0[17].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[17].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[17].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[17].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[16].r[CHIP][enq[CHIP]][0]:SCM1[17].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[16].r[CHIP][enq[CHIP]][3] : SCM1[17].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[17].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[17].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[17].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[16].r[CHIP][enq[CHIP]][0]:SCM0[17].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[16].r[CHIP][enq[CHIP]][3] : SCM0[17].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[17].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[17].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[17].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[17].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[17].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[16].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[16].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[16].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[17].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[16].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[16].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[16].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[17].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[16].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[16].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[16].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[17].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[16].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[16].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[16].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[17].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[17].enq[CHIP] = 1-SCBR[17].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_18(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit18 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (18 && SCBR[17].enq[CHIP]==SCBR[17].deq[CHIP]) || (18<57 && SCBR[18].enq[CHIP]!=SCBR[18].deq[CHIP])) continue;
SCBR[17].deq[CHIP] = 1-SCBR[17].deq[CHIP];
enq[CHIP] = SCBR[18].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[18].r[CHIP][enq[CHIP]][3] = SCBR[17].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[17].r[CHIP][enq[CHIP]][0]:SCM1[18].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[17].r[CHIP][enq[CHIP]][0] : SCM1[18].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[18].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[17].r[CHIP][enq[CHIP]][0]:SCM0[18].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[17].r[CHIP][enq[CHIP]][0] : SCM0[18].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[18].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[18].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[18].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[17].r[CHIP][enq[CHIP]][0]:SCM1[18].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[17].r[CHIP][enq[CHIP]][0] : SCM1[18].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[18].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[17].r[CHIP][enq[CHIP]][0]:SCM0[18].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[17].r[CHIP][enq[CHIP]][0] : SCM0[18].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[18].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[18].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[18].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[17].r[CHIP][enq[CHIP]][0]:SCM1[18].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[17].r[CHIP][enq[CHIP]][3] : SCM1[18].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[18].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[18].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[18].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[17].r[CHIP][enq[CHIP]][0]:SCM0[18].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[17].r[CHIP][enq[CHIP]][3] : SCM0[18].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[18].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[18].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[18].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[18].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[18].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[17].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[17].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[17].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[18].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[17].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[17].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[17].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[18].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[17].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[17].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[17].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[18].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[17].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[17].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[17].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[18].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[18].enq[CHIP] = 1-SCBR[18].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_19(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit19 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (19 && SCBR[18].enq[CHIP]==SCBR[18].deq[CHIP]) || (19<57 && SCBR[19].enq[CHIP]!=SCBR[19].deq[CHIP])) continue;
SCBR[18].deq[CHIP] = 1-SCBR[18].deq[CHIP];
enq[CHIP] = SCBR[19].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[19].r[CHIP][enq[CHIP]][3] = SCBR[18].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[18].r[CHIP][enq[CHIP]][0]:SCM1[19].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[18].r[CHIP][enq[CHIP]][0] : SCM1[19].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[19].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[18].r[CHIP][enq[CHIP]][0]:SCM0[19].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[18].r[CHIP][enq[CHIP]][0] : SCM0[19].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[19].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[19].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[19].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[18].r[CHIP][enq[CHIP]][0]:SCM1[19].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[18].r[CHIP][enq[CHIP]][0] : SCM1[19].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[19].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[18].r[CHIP][enq[CHIP]][0]:SCM0[19].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[18].r[CHIP][enq[CHIP]][0] : SCM0[19].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[19].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[19].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[19].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[18].r[CHIP][enq[CHIP]][0]:SCM1[19].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[18].r[CHIP][enq[CHIP]][3] : SCM1[19].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[19].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[19].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[19].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[18].r[CHIP][enq[CHIP]][0]:SCM0[19].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[18].r[CHIP][enq[CHIP]][3] : SCM0[19].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[19].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[19].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[19].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[19].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[19].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[18].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[18].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[18].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[19].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[18].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[18].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[18].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[19].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[18].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[18].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[18].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[19].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[18].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[18].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[18].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[19].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[19].enq[CHIP] = 1-SCBR[19].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_20(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit20 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (20 && SCBR[19].enq[CHIP]==SCBR[19].deq[CHIP]) || (20<57 && SCBR[20].enq[CHIP]!=SCBR[20].deq[CHIP])) continue;
SCBR[19].deq[CHIP] = 1-SCBR[19].deq[CHIP];
enq[CHIP] = SCBR[20].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[20].r[CHIP][enq[CHIP]][3] = SCBR[19].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[19].r[CHIP][enq[CHIP]][0]:SCM1[20].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[19].r[CHIP][enq[CHIP]][0] : SCM1[20].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[20].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[19].r[CHIP][enq[CHIP]][0]:SCM0[20].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[19].r[CHIP][enq[CHIP]][0] : SCM0[20].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[20].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[20].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[20].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[19].r[CHIP][enq[CHIP]][0]:SCM1[20].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[19].r[CHIP][enq[CHIP]][0] : SCM1[20].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[20].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[19].r[CHIP][enq[CHIP]][0]:SCM0[20].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[19].r[CHIP][enq[CHIP]][0] : SCM0[20].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[20].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[20].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[20].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[19].r[CHIP][enq[CHIP]][0]:SCM1[20].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[19].r[CHIP][enq[CHIP]][3] : SCM1[20].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[20].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[20].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[20].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[19].r[CHIP][enq[CHIP]][0]:SCM0[20].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[19].r[CHIP][enq[CHIP]][3] : SCM0[20].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[20].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[20].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[20].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[20].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[20].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[19].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[19].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[19].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[20].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[19].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[19].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[19].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[20].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[19].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[19].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[19].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[20].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[19].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[19].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[19].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[20].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[20].enq[CHIP] = 1-SCBR[20].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_21(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit21 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (21 && SCBR[20].enq[CHIP]==SCBR[20].deq[CHIP]) || (21<57 && SCBR[21].enq[CHIP]!=SCBR[21].deq[CHIP])) continue;
SCBR[20].deq[CHIP] = 1-SCBR[20].deq[CHIP];
enq[CHIP] = SCBR[21].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[21].r[CHIP][enq[CHIP]][3] = SCBR[20].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[20].r[CHIP][enq[CHIP]][0]:SCM1[21].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[20].r[CHIP][enq[CHIP]][0] : SCM1[21].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[21].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[20].r[CHIP][enq[CHIP]][0]:SCM0[21].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[20].r[CHIP][enq[CHIP]][0] : SCM0[21].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[21].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[21].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[21].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[20].r[CHIP][enq[CHIP]][0]:SCM1[21].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[20].r[CHIP][enq[CHIP]][0] : SCM1[21].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[21].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[20].r[CHIP][enq[CHIP]][0]:SCM0[21].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[20].r[CHIP][enq[CHIP]][0] : SCM0[21].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[21].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[21].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[21].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[20].r[CHIP][enq[CHIP]][0]:SCM1[21].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[20].r[CHIP][enq[CHIP]][3] : SCM1[21].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[21].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[21].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[21].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[20].r[CHIP][enq[CHIP]][0]:SCM0[21].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[20].r[CHIP][enq[CHIP]][3] : SCM0[21].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[21].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[21].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[21].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[21].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[21].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[20].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[20].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[20].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[21].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[20].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[20].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[20].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[21].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[20].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[20].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[20].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[21].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[20].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[20].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[20].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[21].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[21].enq[CHIP] = 1-SCBR[21].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_22(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit22 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (22 && SCBR[21].enq[CHIP]==SCBR[21].deq[CHIP]) || (22<57 && SCBR[22].enq[CHIP]!=SCBR[22].deq[CHIP])) continue;
SCBR[21].deq[CHIP] = 1-SCBR[21].deq[CHIP];
enq[CHIP] = SCBR[22].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[22].r[CHIP][enq[CHIP]][3] = SCBR[21].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[21].r[CHIP][enq[CHIP]][0]:SCM1[22].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[21].r[CHIP][enq[CHIP]][0] : SCM1[22].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[22].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[21].r[CHIP][enq[CHIP]][0]:SCM0[22].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[21].r[CHIP][enq[CHIP]][0] : SCM0[22].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[22].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[22].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[22].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[21].r[CHIP][enq[CHIP]][0]:SCM1[22].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[21].r[CHIP][enq[CHIP]][0] : SCM1[22].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[22].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[21].r[CHIP][enq[CHIP]][0]:SCM0[22].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[21].r[CHIP][enq[CHIP]][0] : SCM0[22].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[22].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[22].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[22].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[21].r[CHIP][enq[CHIP]][0]:SCM1[22].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[21].r[CHIP][enq[CHIP]][3] : SCM1[22].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[22].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[22].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[22].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[21].r[CHIP][enq[CHIP]][0]:SCM0[22].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[21].r[CHIP][enq[CHIP]][3] : SCM0[22].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[22].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[22].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[22].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[22].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[22].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[21].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[21].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[21].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[22].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[21].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[21].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[21].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[22].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[21].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[21].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[21].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[22].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[21].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[21].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[21].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[22].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[22].enq[CHIP] = 1-SCBR[22].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_23(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit23 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (23 && SCBR[22].enq[CHIP]==SCBR[22].deq[CHIP]) || (23<57 && SCBR[23].enq[CHIP]!=SCBR[23].deq[CHIP])) continue;
SCBR[22].deq[CHIP] = 1-SCBR[22].deq[CHIP];
enq[CHIP] = SCBR[23].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[23].r[CHIP][enq[CHIP]][3] = SCBR[22].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[22].r[CHIP][enq[CHIP]][0]:SCM1[23].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[22].r[CHIP][enq[CHIP]][0] : SCM1[23].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[23].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[22].r[CHIP][enq[CHIP]][0]:SCM0[23].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[22].r[CHIP][enq[CHIP]][0] : SCM0[23].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[23].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[23].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[23].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[22].r[CHIP][enq[CHIP]][0]:SCM1[23].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[22].r[CHIP][enq[CHIP]][0] : SCM1[23].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[23].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[22].r[CHIP][enq[CHIP]][0]:SCM0[23].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[22].r[CHIP][enq[CHIP]][0] : SCM0[23].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[23].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[23].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[23].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[22].r[CHIP][enq[CHIP]][0]:SCM1[23].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[22].r[CHIP][enq[CHIP]][3] : SCM1[23].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[23].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[23].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[23].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[22].r[CHIP][enq[CHIP]][0]:SCM0[23].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[22].r[CHIP][enq[CHIP]][3] : SCM0[23].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[23].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[23].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[23].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[23].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[23].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[22].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[22].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[22].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[23].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[22].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[22].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[22].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[23].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[22].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[22].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[22].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[23].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[22].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[22].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[22].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[23].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[23].enq[CHIP] = 1-SCBR[23].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_24(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit24 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (24 && SCBR[23].enq[CHIP]==SCBR[23].deq[CHIP]) || (24<57 && SCBR[24].enq[CHIP]!=SCBR[24].deq[CHIP])) continue;
SCBR[23].deq[CHIP] = 1-SCBR[23].deq[CHIP];
enq[CHIP] = SCBR[24].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[24].r[CHIP][enq[CHIP]][3] = SCBR[23].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[23].r[CHIP][enq[CHIP]][0]:SCM1[24].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[23].r[CHIP][enq[CHIP]][0] : SCM1[24].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[24].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[23].r[CHIP][enq[CHIP]][0]:SCM0[24].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[23].r[CHIP][enq[CHIP]][0] : SCM0[24].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[24].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[24].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[24].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[23].r[CHIP][enq[CHIP]][0]:SCM1[24].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[23].r[CHIP][enq[CHIP]][0] : SCM1[24].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[24].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[23].r[CHIP][enq[CHIP]][0]:SCM0[24].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[23].r[CHIP][enq[CHIP]][0] : SCM0[24].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[24].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[24].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[24].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[23].r[CHIP][enq[CHIP]][0]:SCM1[24].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[23].r[CHIP][enq[CHIP]][3] : SCM1[24].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[24].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[24].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[24].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[23].r[CHIP][enq[CHIP]][0]:SCM0[24].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[23].r[CHIP][enq[CHIP]][3] : SCM0[24].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[24].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[24].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[24].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[24].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[24].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[23].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[23].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[23].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[24].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[23].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[23].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[23].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[24].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[23].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[23].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[23].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[24].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[23].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[23].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[23].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[24].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[24].enq[CHIP] = 1-SCBR[24].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_25(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit25 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (25 && SCBR[24].enq[CHIP]==SCBR[24].deq[CHIP]) || (25<57 && SCBR[25].enq[CHIP]!=SCBR[25].deq[CHIP])) continue;
SCBR[24].deq[CHIP] = 1-SCBR[24].deq[CHIP];
enq[CHIP] = SCBR[25].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[25].r[CHIP][enq[CHIP]][3] = SCBR[24].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[24].r[CHIP][enq[CHIP]][0]:SCM1[25].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[24].r[CHIP][enq[CHIP]][0] : SCM1[25].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[25].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[24].r[CHIP][enq[CHIP]][0]:SCM0[25].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[24].r[CHIP][enq[CHIP]][0] : SCM0[25].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[25].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[25].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[25].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[24].r[CHIP][enq[CHIP]][0]:SCM1[25].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[24].r[CHIP][enq[CHIP]][0] : SCM1[25].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[25].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[24].r[CHIP][enq[CHIP]][0]:SCM0[25].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[24].r[CHIP][enq[CHIP]][0] : SCM0[25].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[25].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[25].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[25].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[24].r[CHIP][enq[CHIP]][0]:SCM1[25].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[24].r[CHIP][enq[CHIP]][3] : SCM1[25].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[25].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[25].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[25].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[24].r[CHIP][enq[CHIP]][0]:SCM0[25].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[24].r[CHIP][enq[CHIP]][3] : SCM0[25].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[25].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[25].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[25].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[25].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[25].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[24].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[24].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[24].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[25].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[24].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[24].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[24].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[25].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[24].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[24].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[24].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[25].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[24].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[24].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[24].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[25].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[25].enq[CHIP] = 1-SCBR[25].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_26(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit26 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (26 && SCBR[25].enq[CHIP]==SCBR[25].deq[CHIP]) || (26<57 && SCBR[26].enq[CHIP]!=SCBR[26].deq[CHIP])) continue;
SCBR[25].deq[CHIP] = 1-SCBR[25].deq[CHIP];
enq[CHIP] = SCBR[26].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[26].r[CHIP][enq[CHIP]][3] = SCBR[25].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[25].r[CHIP][enq[CHIP]][0]:SCM1[26].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[25].r[CHIP][enq[CHIP]][0] : SCM1[26].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[26].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[25].r[CHIP][enq[CHIP]][0]:SCM0[26].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[25].r[CHIP][enq[CHIP]][0] : SCM0[26].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[26].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[26].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[26].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[25].r[CHIP][enq[CHIP]][0]:SCM1[26].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[25].r[CHIP][enq[CHIP]][0] : SCM1[26].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[26].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[25].r[CHIP][enq[CHIP]][0]:SCM0[26].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[25].r[CHIP][enq[CHIP]][0] : SCM0[26].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[26].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[26].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[26].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[25].r[CHIP][enq[CHIP]][0]:SCM1[26].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[25].r[CHIP][enq[CHIP]][3] : SCM1[26].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[26].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[26].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[26].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[25].r[CHIP][enq[CHIP]][0]:SCM0[26].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[25].r[CHIP][enq[CHIP]][3] : SCM0[26].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[26].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[26].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[26].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[26].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[26].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[25].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[25].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[25].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[26].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[25].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[25].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[25].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[26].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[25].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[25].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[25].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[26].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[25].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[25].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[25].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[26].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[26].enq[CHIP] = 1-SCBR[26].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_27(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit27 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (27 && SCBR[26].enq[CHIP]==SCBR[26].deq[CHIP]) || (27<57 && SCBR[27].enq[CHIP]!=SCBR[27].deq[CHIP])) continue;
SCBR[26].deq[CHIP] = 1-SCBR[26].deq[CHIP];
enq[CHIP] = SCBR[27].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[27].r[CHIP][enq[CHIP]][3] = SCBR[26].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[26].r[CHIP][enq[CHIP]][0]:SCM1[27].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[26].r[CHIP][enq[CHIP]][0] : SCM1[27].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[27].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[26].r[CHIP][enq[CHIP]][0]:SCM0[27].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[26].r[CHIP][enq[CHIP]][0] : SCM0[27].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[27].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[27].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[27].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[26].r[CHIP][enq[CHIP]][0]:SCM1[27].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[26].r[CHIP][enq[CHIP]][0] : SCM1[27].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[27].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[26].r[CHIP][enq[CHIP]][0]:SCM0[27].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[26].r[CHIP][enq[CHIP]][0] : SCM0[27].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[27].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[27].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[27].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[26].r[CHIP][enq[CHIP]][0]:SCM1[27].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[26].r[CHIP][enq[CHIP]][3] : SCM1[27].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[27].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[27].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[27].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[26].r[CHIP][enq[CHIP]][0]:SCM0[27].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[26].r[CHIP][enq[CHIP]][3] : SCM0[27].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[27].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[27].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[27].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[27].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[27].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[26].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[26].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[26].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[27].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[26].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[26].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[26].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[27].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[26].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[26].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[26].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[27].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[26].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[26].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[26].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[27].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[27].enq[CHIP] = 1-SCBR[27].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_28(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit28 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (28 && SCBR[27].enq[CHIP]==SCBR[27].deq[CHIP]) || (28<57 && SCBR[28].enq[CHIP]!=SCBR[28].deq[CHIP])) continue;
SCBR[27].deq[CHIP] = 1-SCBR[27].deq[CHIP];
enq[CHIP] = SCBR[28].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[28].r[CHIP][enq[CHIP]][3] = SCBR[27].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[27].r[CHIP][enq[CHIP]][0]:SCM1[28].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[27].r[CHIP][enq[CHIP]][0] : SCM1[28].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[28].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[27].r[CHIP][enq[CHIP]][0]:SCM0[28].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[27].r[CHIP][enq[CHIP]][0] : SCM0[28].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[28].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[28].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[28].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[27].r[CHIP][enq[CHIP]][0]:SCM1[28].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[27].r[CHIP][enq[CHIP]][0] : SCM1[28].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[28].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[27].r[CHIP][enq[CHIP]][0]:SCM0[28].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[27].r[CHIP][enq[CHIP]][0] : SCM0[28].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[28].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[28].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[28].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[27].r[CHIP][enq[CHIP]][0]:SCM1[28].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[27].r[CHIP][enq[CHIP]][3] : SCM1[28].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[28].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[28].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[28].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[27].r[CHIP][enq[CHIP]][0]:SCM0[28].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[27].r[CHIP][enq[CHIP]][3] : SCM0[28].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[28].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[28].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[28].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[28].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[28].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[27].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[27].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[27].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[28].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[27].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[27].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[27].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[28].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[27].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[27].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[27].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[28].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[27].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[27].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[27].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[28].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[28].enq[CHIP] = 1-SCBR[28].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_29(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit29 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (29 && SCBR[28].enq[CHIP]==SCBR[28].deq[CHIP]) || (29<57 && SCBR[29].enq[CHIP]!=SCBR[29].deq[CHIP])) continue;
SCBR[28].deq[CHIP] = 1-SCBR[28].deq[CHIP];
enq[CHIP] = SCBR[29].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[29].r[CHIP][enq[CHIP]][3] = SCBR[28].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[28].r[CHIP][enq[CHIP]][0]:SCM1[29].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[28].r[CHIP][enq[CHIP]][0] : SCM1[29].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[29].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[28].r[CHIP][enq[CHIP]][0]:SCM0[29].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[28].r[CHIP][enq[CHIP]][0] : SCM0[29].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[29].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[29].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[29].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[28].r[CHIP][enq[CHIP]][0]:SCM1[29].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[28].r[CHIP][enq[CHIP]][0] : SCM1[29].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[29].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[28].r[CHIP][enq[CHIP]][0]:SCM0[29].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[28].r[CHIP][enq[CHIP]][0] : SCM0[29].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[29].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[29].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[29].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[28].r[CHIP][enq[CHIP]][0]:SCM1[29].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[28].r[CHIP][enq[CHIP]][3] : SCM1[29].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[29].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[29].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[29].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[28].r[CHIP][enq[CHIP]][0]:SCM0[29].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[28].r[CHIP][enq[CHIP]][3] : SCM0[29].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[29].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[29].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[29].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[29].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[29].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[28].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[28].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[28].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[29].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[28].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[28].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[28].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[29].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[28].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[28].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[28].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[29].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[28].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[28].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[28].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[29].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[29].enq[CHIP] = 1-SCBR[29].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_30(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit30 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (30 && SCBR[29].enq[CHIP]==SCBR[29].deq[CHIP]) || (30<57 && SCBR[30].enq[CHIP]!=SCBR[30].deq[CHIP])) continue;
SCBR[29].deq[CHIP] = 1-SCBR[29].deq[CHIP];
enq[CHIP] = SCBR[30].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[30].r[CHIP][enq[CHIP]][3] = SCBR[29].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[29].r[CHIP][enq[CHIP]][0]:SCM1[30].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[29].r[CHIP][enq[CHIP]][0] : SCM1[30].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[30].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[29].r[CHIP][enq[CHIP]][0]:SCM0[30].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[29].r[CHIP][enq[CHIP]][0] : SCM0[30].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[30].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[30].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[30].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[29].r[CHIP][enq[CHIP]][0]:SCM1[30].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[29].r[CHIP][enq[CHIP]][0] : SCM1[30].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[30].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[29].r[CHIP][enq[CHIP]][0]:SCM0[30].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[29].r[CHIP][enq[CHIP]][0] : SCM0[30].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[30].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[30].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[30].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[29].r[CHIP][enq[CHIP]][0]:SCM1[30].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[29].r[CHIP][enq[CHIP]][3] : SCM1[30].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[30].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[30].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[30].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[29].r[CHIP][enq[CHIP]][0]:SCM0[30].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[29].r[CHIP][enq[CHIP]][3] : SCM0[30].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[30].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[30].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[30].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[30].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[30].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[29].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[29].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[29].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[30].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[29].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[29].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[29].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[30].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[29].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[29].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[29].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[30].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[29].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[29].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[29].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[30].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[30].enq[CHIP] = 1-SCBR[30].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_31(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit31 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (31 && SCBR[30].enq[CHIP]==SCBR[30].deq[CHIP]) || (31<57 && SCBR[31].enq[CHIP]!=SCBR[31].deq[CHIP])) continue;
SCBR[30].deq[CHIP] = 1-SCBR[30].deq[CHIP];
enq[CHIP] = SCBR[31].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[31].r[CHIP][enq[CHIP]][3] = SCBR[30].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[30].r[CHIP][enq[CHIP]][0]:SCM1[31].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[30].r[CHIP][enq[CHIP]][0] : SCM1[31].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[31].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[30].r[CHIP][enq[CHIP]][0]:SCM0[31].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[30].r[CHIP][enq[CHIP]][0] : SCM0[31].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[31].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[31].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[31].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[30].r[CHIP][enq[CHIP]][0]:SCM1[31].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[30].r[CHIP][enq[CHIP]][0] : SCM1[31].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[31].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[30].r[CHIP][enq[CHIP]][0]:SCM0[31].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[30].r[CHIP][enq[CHIP]][0] : SCM0[31].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[31].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[31].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[31].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[30].r[CHIP][enq[CHIP]][0]:SCM1[31].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[30].r[CHIP][enq[CHIP]][3] : SCM1[31].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[31].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[31].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[31].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[30].r[CHIP][enq[CHIP]][0]:SCM0[31].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[30].r[CHIP][enq[CHIP]][3] : SCM0[31].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[31].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[31].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[31].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[31].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[31].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[30].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[30].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[30].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[31].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[30].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[30].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[30].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[31].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[30].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[30].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[30].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[31].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[30].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[30].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[30].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[31].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[31].enq[CHIP] = 1-SCBR[31].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_32(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit32 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (32 && SCBR[31].enq[CHIP]==SCBR[31].deq[CHIP]) || (32<57 && SCBR[32].enq[CHIP]!=SCBR[32].deq[CHIP])) continue;
SCBR[31].deq[CHIP] = 1-SCBR[31].deq[CHIP];
enq[CHIP] = SCBR[32].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[32].r[CHIP][enq[CHIP]][3] = SCBR[31].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[31].r[CHIP][enq[CHIP]][0]:SCM1[32].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[31].r[CHIP][enq[CHIP]][0] : SCM1[32].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[32].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[31].r[CHIP][enq[CHIP]][0]:SCM0[32].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[31].r[CHIP][enq[CHIP]][0] : SCM0[32].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[32].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[32].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[32].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[31].r[CHIP][enq[CHIP]][0]:SCM1[32].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[31].r[CHIP][enq[CHIP]][0] : SCM1[32].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[32].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[31].r[CHIP][enq[CHIP]][0]:SCM0[32].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[31].r[CHIP][enq[CHIP]][0] : SCM0[32].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[32].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[32].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[32].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[31].r[CHIP][enq[CHIP]][0]:SCM1[32].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[31].r[CHIP][enq[CHIP]][3] : SCM1[32].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[32].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[32].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[32].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[31].r[CHIP][enq[CHIP]][0]:SCM0[32].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[31].r[CHIP][enq[CHIP]][3] : SCM0[32].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[32].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[32].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[32].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[32].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[32].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[31].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[31].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[31].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[32].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[31].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[31].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[31].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[32].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[31].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[31].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[31].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[32].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[31].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[31].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[31].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[32].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[32].enq[CHIP] = 1-SCBR[32].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_33(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit33 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (33 && SCBR[32].enq[CHIP]==SCBR[32].deq[CHIP]) || (33<57 && SCBR[33].enq[CHIP]!=SCBR[33].deq[CHIP])) continue;
SCBR[32].deq[CHIP] = 1-SCBR[32].deq[CHIP];
enq[CHIP] = SCBR[33].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[33].r[CHIP][enq[CHIP]][3] = SCBR[32].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[32].r[CHIP][enq[CHIP]][0]:SCM1[33].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[32].r[CHIP][enq[CHIP]][0] : SCM1[33].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[33].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[32].r[CHIP][enq[CHIP]][0]:SCM0[33].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[32].r[CHIP][enq[CHIP]][0] : SCM0[33].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[33].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[33].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[33].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[32].r[CHIP][enq[CHIP]][0]:SCM1[33].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[32].r[CHIP][enq[CHIP]][0] : SCM1[33].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[33].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[32].r[CHIP][enq[CHIP]][0]:SCM0[33].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[32].r[CHIP][enq[CHIP]][0] : SCM0[33].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[33].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[33].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[33].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[32].r[CHIP][enq[CHIP]][0]:SCM1[33].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[32].r[CHIP][enq[CHIP]][3] : SCM1[33].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[33].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[33].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[33].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[32].r[CHIP][enq[CHIP]][0]:SCM0[33].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[32].r[CHIP][enq[CHIP]][3] : SCM0[33].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[33].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[33].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[33].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[33].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[33].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[32].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[32].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[32].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[33].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[32].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[32].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[32].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[33].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[32].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[32].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[32].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[33].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[32].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[32].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[32].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[33].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[33].enq[CHIP] = 1-SCBR[33].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_34(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit34 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (34 && SCBR[33].enq[CHIP]==SCBR[33].deq[CHIP]) || (34<57 && SCBR[34].enq[CHIP]!=SCBR[34].deq[CHIP])) continue;
SCBR[33].deq[CHIP] = 1-SCBR[33].deq[CHIP];
enq[CHIP] = SCBR[34].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[34].r[CHIP][enq[CHIP]][3] = SCBR[33].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[33].r[CHIP][enq[CHIP]][0]:SCM1[34].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[33].r[CHIP][enq[CHIP]][0] : SCM1[34].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[34].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[33].r[CHIP][enq[CHIP]][0]:SCM0[34].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[33].r[CHIP][enq[CHIP]][0] : SCM0[34].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[34].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[34].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[34].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[33].r[CHIP][enq[CHIP]][0]:SCM1[34].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[33].r[CHIP][enq[CHIP]][0] : SCM1[34].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[34].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[33].r[CHIP][enq[CHIP]][0]:SCM0[34].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[33].r[CHIP][enq[CHIP]][0] : SCM0[34].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[34].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[34].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[34].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[33].r[CHIP][enq[CHIP]][0]:SCM1[34].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[33].r[CHIP][enq[CHIP]][3] : SCM1[34].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[34].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[34].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[34].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[33].r[CHIP][enq[CHIP]][0]:SCM0[34].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[33].r[CHIP][enq[CHIP]][3] : SCM0[34].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[34].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[34].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[34].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[34].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[34].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[33].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[33].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[33].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[34].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[33].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[33].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[33].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[34].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[33].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[33].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[33].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[34].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[33].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[33].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[33].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[34].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[34].enq[CHIP] = 1-SCBR[34].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_35(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit35 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (35 && SCBR[34].enq[CHIP]==SCBR[34].deq[CHIP]) || (35<57 && SCBR[35].enq[CHIP]!=SCBR[35].deq[CHIP])) continue;
SCBR[34].deq[CHIP] = 1-SCBR[34].deq[CHIP];
enq[CHIP] = SCBR[35].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[35].r[CHIP][enq[CHIP]][3] = SCBR[34].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[34].r[CHIP][enq[CHIP]][0]:SCM1[35].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[34].r[CHIP][enq[CHIP]][0] : SCM1[35].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[35].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[34].r[CHIP][enq[CHIP]][0]:SCM0[35].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[34].r[CHIP][enq[CHIP]][0] : SCM0[35].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[35].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[35].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[35].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[34].r[CHIP][enq[CHIP]][0]:SCM1[35].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[34].r[CHIP][enq[CHIP]][0] : SCM1[35].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[35].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[34].r[CHIP][enq[CHIP]][0]:SCM0[35].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[34].r[CHIP][enq[CHIP]][0] : SCM0[35].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[35].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[35].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[35].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[34].r[CHIP][enq[CHIP]][0]:SCM1[35].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[34].r[CHIP][enq[CHIP]][3] : SCM1[35].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[35].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[35].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[35].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[34].r[CHIP][enq[CHIP]][0]:SCM0[35].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[34].r[CHIP][enq[CHIP]][3] : SCM0[35].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[35].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[35].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[35].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[35].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[35].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[34].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[34].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[34].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[35].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[34].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[34].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[34].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[35].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[34].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[34].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[34].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[35].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[34].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[34].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[34].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[35].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[35].enq[CHIP] = 1-SCBR[35].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_36(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit36 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (36 && SCBR[35].enq[CHIP]==SCBR[35].deq[CHIP]) || (36<57 && SCBR[36].enq[CHIP]!=SCBR[36].deq[CHIP])) continue;
SCBR[35].deq[CHIP] = 1-SCBR[35].deq[CHIP];
enq[CHIP] = SCBR[36].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[36].r[CHIP][enq[CHIP]][3] = SCBR[35].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[35].r[CHIP][enq[CHIP]][0]:SCM1[36].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[35].r[CHIP][enq[CHIP]][0] : SCM1[36].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[36].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[35].r[CHIP][enq[CHIP]][0]:SCM0[36].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[35].r[CHIP][enq[CHIP]][0] : SCM0[36].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[36].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[36].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[36].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[35].r[CHIP][enq[CHIP]][0]:SCM1[36].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[35].r[CHIP][enq[CHIP]][0] : SCM1[36].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[36].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[35].r[CHIP][enq[CHIP]][0]:SCM0[36].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[35].r[CHIP][enq[CHIP]][0] : SCM0[36].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[36].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[36].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[36].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[35].r[CHIP][enq[CHIP]][0]:SCM1[36].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[35].r[CHIP][enq[CHIP]][3] : SCM1[36].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[36].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[36].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[36].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[35].r[CHIP][enq[CHIP]][0]:SCM0[36].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[35].r[CHIP][enq[CHIP]][3] : SCM0[36].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[36].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[36].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[36].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[36].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[36].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[35].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[35].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[35].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[36].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[35].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[35].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[35].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[36].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[35].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[35].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[35].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[36].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[35].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[35].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[35].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[36].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[36].enq[CHIP] = 1-SCBR[36].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_37(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit37 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (37 && SCBR[36].enq[CHIP]==SCBR[36].deq[CHIP]) || (37<57 && SCBR[37].enq[CHIP]!=SCBR[37].deq[CHIP])) continue;
SCBR[36].deq[CHIP] = 1-SCBR[36].deq[CHIP];
enq[CHIP] = SCBR[37].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[37].r[CHIP][enq[CHIP]][3] = SCBR[36].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[36].r[CHIP][enq[CHIP]][0]:SCM1[37].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[36].r[CHIP][enq[CHIP]][0] : SCM1[37].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[37].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[36].r[CHIP][enq[CHIP]][0]:SCM0[37].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[36].r[CHIP][enq[CHIP]][0] : SCM0[37].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[37].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[37].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[37].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[36].r[CHIP][enq[CHIP]][0]:SCM1[37].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[36].r[CHIP][enq[CHIP]][0] : SCM1[37].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[37].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[36].r[CHIP][enq[CHIP]][0]:SCM0[37].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[36].r[CHIP][enq[CHIP]][0] : SCM0[37].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[37].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[37].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[37].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[36].r[CHIP][enq[CHIP]][0]:SCM1[37].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[36].r[CHIP][enq[CHIP]][3] : SCM1[37].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[37].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[37].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[37].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[36].r[CHIP][enq[CHIP]][0]:SCM0[37].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[36].r[CHIP][enq[CHIP]][3] : SCM0[37].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[37].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[37].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[37].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[37].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[37].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[36].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[36].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[36].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[37].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[36].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[36].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[36].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[37].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[36].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[36].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[36].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[37].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[36].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[36].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[36].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[37].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[37].enq[CHIP] = 1-SCBR[37].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_38(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit38 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (38 && SCBR[37].enq[CHIP]==SCBR[37].deq[CHIP]) || (38<57 && SCBR[38].enq[CHIP]!=SCBR[38].deq[CHIP])) continue;
SCBR[37].deq[CHIP] = 1-SCBR[37].deq[CHIP];
enq[CHIP] = SCBR[38].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[38].r[CHIP][enq[CHIP]][3] = SCBR[37].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[37].r[CHIP][enq[CHIP]][0]:SCM1[38].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[37].r[CHIP][enq[CHIP]][0] : SCM1[38].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[38].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[37].r[CHIP][enq[CHIP]][0]:SCM0[38].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[37].r[CHIP][enq[CHIP]][0] : SCM0[38].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[38].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[38].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[38].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[37].r[CHIP][enq[CHIP]][0]:SCM1[38].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[37].r[CHIP][enq[CHIP]][0] : SCM1[38].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[38].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[37].r[CHIP][enq[CHIP]][0]:SCM0[38].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[37].r[CHIP][enq[CHIP]][0] : SCM0[38].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[38].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[38].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[38].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[37].r[CHIP][enq[CHIP]][0]:SCM1[38].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[37].r[CHIP][enq[CHIP]][3] : SCM1[38].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[38].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[38].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[38].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[37].r[CHIP][enq[CHIP]][0]:SCM0[38].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[37].r[CHIP][enq[CHIP]][3] : SCM0[38].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[38].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[38].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[38].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[38].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[38].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[37].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[37].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[37].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[38].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[37].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[37].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[37].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[38].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[37].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[37].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[37].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[38].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[37].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[37].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[37].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[38].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[38].enq[CHIP] = 1-SCBR[38].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_39(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit39 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (39 && SCBR[38].enq[CHIP]==SCBR[38].deq[CHIP]) || (39<57 && SCBR[39].enq[CHIP]!=SCBR[39].deq[CHIP])) continue;
SCBR[38].deq[CHIP] = 1-SCBR[38].deq[CHIP];
enq[CHIP] = SCBR[39].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[39].r[CHIP][enq[CHIP]][3] = SCBR[38].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[38].r[CHIP][enq[CHIP]][0]:SCM1[39].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[38].r[CHIP][enq[CHIP]][0] : SCM1[39].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[39].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[38].r[CHIP][enq[CHIP]][0]:SCM0[39].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[38].r[CHIP][enq[CHIP]][0] : SCM0[39].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[39].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[39].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[39].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[38].r[CHIP][enq[CHIP]][0]:SCM1[39].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[38].r[CHIP][enq[CHIP]][0] : SCM1[39].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[39].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[38].r[CHIP][enq[CHIP]][0]:SCM0[39].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[38].r[CHIP][enq[CHIP]][0] : SCM0[39].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[39].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[39].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[39].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[38].r[CHIP][enq[CHIP]][0]:SCM1[39].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[38].r[CHIP][enq[CHIP]][3] : SCM1[39].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[39].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[39].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[39].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[38].r[CHIP][enq[CHIP]][0]:SCM0[39].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[38].r[CHIP][enq[CHIP]][3] : SCM0[39].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[39].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[39].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[39].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[39].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[39].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[38].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[38].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[38].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[39].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[38].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[38].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[38].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[39].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[38].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[38].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[38].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[39].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[38].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[38].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[38].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[39].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[39].enq[CHIP] = 1-SCBR[39].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_40(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit40 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (40 && SCBR[39].enq[CHIP]==SCBR[39].deq[CHIP]) || (40<57 && SCBR[40].enq[CHIP]!=SCBR[40].deq[CHIP])) continue;
SCBR[39].deq[CHIP] = 1-SCBR[39].deq[CHIP];
enq[CHIP] = SCBR[40].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[40].r[CHIP][enq[CHIP]][3] = SCBR[39].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[39].r[CHIP][enq[CHIP]][0]:SCM1[40].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[39].r[CHIP][enq[CHIP]][0] : SCM1[40].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[40].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[39].r[CHIP][enq[CHIP]][0]:SCM0[40].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[39].r[CHIP][enq[CHIP]][0] : SCM0[40].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[40].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[40].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[40].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[39].r[CHIP][enq[CHIP]][0]:SCM1[40].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[39].r[CHIP][enq[CHIP]][0] : SCM1[40].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[40].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[39].r[CHIP][enq[CHIP]][0]:SCM0[40].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[39].r[CHIP][enq[CHIP]][0] : SCM0[40].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[40].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[40].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[40].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[39].r[CHIP][enq[CHIP]][0]:SCM1[40].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[39].r[CHIP][enq[CHIP]][3] : SCM1[40].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[40].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[40].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[40].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[39].r[CHIP][enq[CHIP]][0]:SCM0[40].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[39].r[CHIP][enq[CHIP]][3] : SCM0[40].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[40].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[40].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[40].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[40].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[40].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[39].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[39].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[39].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[40].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[39].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[39].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[39].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[40].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[39].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[39].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[39].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[40].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[39].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[39].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[39].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[40].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[40].enq[CHIP] = 1-SCBR[40].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_41(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit41 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (41 && SCBR[40].enq[CHIP]==SCBR[40].deq[CHIP]) || (41<57 && SCBR[41].enq[CHIP]!=SCBR[41].deq[CHIP])) continue;
SCBR[40].deq[CHIP] = 1-SCBR[40].deq[CHIP];
enq[CHIP] = SCBR[41].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[41].r[CHIP][enq[CHIP]][3] = SCBR[40].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[40].r[CHIP][enq[CHIP]][0]:SCM1[41].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[40].r[CHIP][enq[CHIP]][0] : SCM1[41].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[41].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[40].r[CHIP][enq[CHIP]][0]:SCM0[41].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[40].r[CHIP][enq[CHIP]][0] : SCM0[41].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[41].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[41].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[41].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[40].r[CHIP][enq[CHIP]][0]:SCM1[41].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[40].r[CHIP][enq[CHIP]][0] : SCM1[41].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[41].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[40].r[CHIP][enq[CHIP]][0]:SCM0[41].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[40].r[CHIP][enq[CHIP]][0] : SCM0[41].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[41].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[41].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[41].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[40].r[CHIP][enq[CHIP]][0]:SCM1[41].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[40].r[CHIP][enq[CHIP]][3] : SCM1[41].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[41].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[41].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[41].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[40].r[CHIP][enq[CHIP]][0]:SCM0[41].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[40].r[CHIP][enq[CHIP]][3] : SCM0[41].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[41].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[41].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[41].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[41].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[41].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[40].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[40].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[40].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[41].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[40].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[40].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[40].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[41].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[40].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[40].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[40].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[41].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[40].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[40].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[40].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[41].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[41].enq[CHIP] = 1-SCBR[41].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_42(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit42 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (42 && SCBR[41].enq[CHIP]==SCBR[41].deq[CHIP]) || (42<57 && SCBR[42].enq[CHIP]!=SCBR[42].deq[CHIP])) continue;
SCBR[41].deq[CHIP] = 1-SCBR[41].deq[CHIP];
enq[CHIP] = SCBR[42].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[42].r[CHIP][enq[CHIP]][3] = SCBR[41].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[41].r[CHIP][enq[CHIP]][0]:SCM1[42].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[41].r[CHIP][enq[CHIP]][0] : SCM1[42].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[42].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[41].r[CHIP][enq[CHIP]][0]:SCM0[42].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[41].r[CHIP][enq[CHIP]][0] : SCM0[42].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[42].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[42].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[42].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[41].r[CHIP][enq[CHIP]][0]:SCM1[42].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[41].r[CHIP][enq[CHIP]][0] : SCM1[42].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[42].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[41].r[CHIP][enq[CHIP]][0]:SCM0[42].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[41].r[CHIP][enq[CHIP]][0] : SCM0[42].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[42].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[42].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[42].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[41].r[CHIP][enq[CHIP]][0]:SCM1[42].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[41].r[CHIP][enq[CHIP]][3] : SCM1[42].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[42].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[42].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[42].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[41].r[CHIP][enq[CHIP]][0]:SCM0[42].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[41].r[CHIP][enq[CHIP]][3] : SCM0[42].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[42].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[42].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[42].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[42].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[42].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[41].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[41].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[41].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[42].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[41].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[41].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[41].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[42].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[41].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[41].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[41].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[42].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[41].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[41].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[41].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[42].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[42].enq[CHIP] = 1-SCBR[42].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_43(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit43 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (43 && SCBR[42].enq[CHIP]==SCBR[42].deq[CHIP]) || (43<57 && SCBR[43].enq[CHIP]!=SCBR[43].deq[CHIP])) continue;
SCBR[42].deq[CHIP] = 1-SCBR[42].deq[CHIP];
enq[CHIP] = SCBR[43].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[43].r[CHIP][enq[CHIP]][3] = SCBR[42].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[42].r[CHIP][enq[CHIP]][0]:SCM1[43].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[42].r[CHIP][enq[CHIP]][0] : SCM1[43].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[43].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[42].r[CHIP][enq[CHIP]][0]:SCM0[43].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[42].r[CHIP][enq[CHIP]][0] : SCM0[43].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[43].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[43].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[43].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[42].r[CHIP][enq[CHIP]][0]:SCM1[43].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[42].r[CHIP][enq[CHIP]][0] : SCM1[43].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[43].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[42].r[CHIP][enq[CHIP]][0]:SCM0[43].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[42].r[CHIP][enq[CHIP]][0] : SCM0[43].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[43].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[43].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[43].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[42].r[CHIP][enq[CHIP]][0]:SCM1[43].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[42].r[CHIP][enq[CHIP]][3] : SCM1[43].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[43].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[43].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[43].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[42].r[CHIP][enq[CHIP]][0]:SCM0[43].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[42].r[CHIP][enq[CHIP]][3] : SCM0[43].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[43].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[43].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[43].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[43].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[43].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[42].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[42].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[42].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[43].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[42].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[42].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[42].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[43].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[42].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[42].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[42].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[43].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[42].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[42].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[42].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[43].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[43].enq[CHIP] = 1-SCBR[43].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_44(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit44 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (44 && SCBR[43].enq[CHIP]==SCBR[43].deq[CHIP]) || (44<57 && SCBR[44].enq[CHIP]!=SCBR[44].deq[CHIP])) continue;
SCBR[43].deq[CHIP] = 1-SCBR[43].deq[CHIP];
enq[CHIP] = SCBR[44].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[44].r[CHIP][enq[CHIP]][3] = SCBR[43].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[43].r[CHIP][enq[CHIP]][0]:SCM1[44].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[43].r[CHIP][enq[CHIP]][0] : SCM1[44].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[44].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[43].r[CHIP][enq[CHIP]][0]:SCM0[44].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[43].r[CHIP][enq[CHIP]][0] : SCM0[44].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[44].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[44].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[44].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[43].r[CHIP][enq[CHIP]][0]:SCM1[44].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[43].r[CHIP][enq[CHIP]][0] : SCM1[44].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[44].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[43].r[CHIP][enq[CHIP]][0]:SCM0[44].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[43].r[CHIP][enq[CHIP]][0] : SCM0[44].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[44].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[44].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[44].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[43].r[CHIP][enq[CHIP]][0]:SCM1[44].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[43].r[CHIP][enq[CHIP]][3] : SCM1[44].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[44].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[44].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[44].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[43].r[CHIP][enq[CHIP]][0]:SCM0[44].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[43].r[CHIP][enq[CHIP]][3] : SCM0[44].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[44].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[44].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[44].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[44].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[44].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[43].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[43].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[43].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[44].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[43].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[43].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[43].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[44].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[43].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[43].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[43].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[44].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[43].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[43].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[43].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[44].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[44].enq[CHIP] = 1-SCBR[44].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_45(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit45 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (45 && SCBR[44].enq[CHIP]==SCBR[44].deq[CHIP]) || (45<57 && SCBR[45].enq[CHIP]!=SCBR[45].deq[CHIP])) continue;
SCBR[44].deq[CHIP] = 1-SCBR[44].deq[CHIP];
enq[CHIP] = SCBR[45].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[45].r[CHIP][enq[CHIP]][3] = SCBR[44].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[44].r[CHIP][enq[CHIP]][0]:SCM1[45].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[44].r[CHIP][enq[CHIP]][0] : SCM1[45].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[45].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[44].r[CHIP][enq[CHIP]][0]:SCM0[45].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[44].r[CHIP][enq[CHIP]][0] : SCM0[45].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[45].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[45].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[45].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[44].r[CHIP][enq[CHIP]][0]:SCM1[45].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[44].r[CHIP][enq[CHIP]][0] : SCM1[45].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[45].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[44].r[CHIP][enq[CHIP]][0]:SCM0[45].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[44].r[CHIP][enq[CHIP]][0] : SCM0[45].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[45].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[45].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[45].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[44].r[CHIP][enq[CHIP]][0]:SCM1[45].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[44].r[CHIP][enq[CHIP]][3] : SCM1[45].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[45].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[45].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[45].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[44].r[CHIP][enq[CHIP]][0]:SCM0[45].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[44].r[CHIP][enq[CHIP]][3] : SCM0[45].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[45].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[45].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[45].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[45].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[45].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[44].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[44].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[44].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[45].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[44].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[44].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[44].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[45].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[44].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[44].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[44].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[45].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[44].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[44].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[44].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[45].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[45].enq[CHIP] = 1-SCBR[45].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_46(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit46 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (46 && SCBR[45].enq[CHIP]==SCBR[45].deq[CHIP]) || (46<57 && SCBR[46].enq[CHIP]!=SCBR[46].deq[CHIP])) continue;
SCBR[45].deq[CHIP] = 1-SCBR[45].deq[CHIP];
enq[CHIP] = SCBR[46].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[46].r[CHIP][enq[CHIP]][3] = SCBR[45].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[45].r[CHIP][enq[CHIP]][0]:SCM1[46].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[45].r[CHIP][enq[CHIP]][0] : SCM1[46].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[46].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[45].r[CHIP][enq[CHIP]][0]:SCM0[46].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[45].r[CHIP][enq[CHIP]][0] : SCM0[46].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[46].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[46].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[46].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[45].r[CHIP][enq[CHIP]][0]:SCM1[46].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[45].r[CHIP][enq[CHIP]][0] : SCM1[46].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[46].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[45].r[CHIP][enq[CHIP]][0]:SCM0[46].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[45].r[CHIP][enq[CHIP]][0] : SCM0[46].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[46].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[46].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[46].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[45].r[CHIP][enq[CHIP]][0]:SCM1[46].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[45].r[CHIP][enq[CHIP]][3] : SCM1[46].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[46].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[46].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[46].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[45].r[CHIP][enq[CHIP]][0]:SCM0[46].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[45].r[CHIP][enq[CHIP]][3] : SCM0[46].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[46].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[46].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[46].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[46].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[46].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[45].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[45].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[45].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[46].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[45].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[45].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[45].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[46].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[45].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[45].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[45].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[46].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[45].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[45].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[45].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[46].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[46].enq[CHIP] = 1-SCBR[46].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_47(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit47 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (47 && SCBR[46].enq[CHIP]==SCBR[46].deq[CHIP]) || (47<57 && SCBR[47].enq[CHIP]!=SCBR[47].deq[CHIP])) continue;
SCBR[46].deq[CHIP] = 1-SCBR[46].deq[CHIP];
enq[CHIP] = SCBR[47].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[47].r[CHIP][enq[CHIP]][3] = SCBR[46].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[46].r[CHIP][enq[CHIP]][0]:SCM1[47].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[46].r[CHIP][enq[CHIP]][0] : SCM1[47].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[47].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[46].r[CHIP][enq[CHIP]][0]:SCM0[47].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[46].r[CHIP][enq[CHIP]][0] : SCM0[47].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[47].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[47].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[47].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[46].r[CHIP][enq[CHIP]][0]:SCM1[47].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[46].r[CHIP][enq[CHIP]][0] : SCM1[47].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[47].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[46].r[CHIP][enq[CHIP]][0]:SCM0[47].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[46].r[CHIP][enq[CHIP]][0] : SCM0[47].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[47].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[47].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[47].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[46].r[CHIP][enq[CHIP]][0]:SCM1[47].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[46].r[CHIP][enq[CHIP]][3] : SCM1[47].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[47].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[47].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[47].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[46].r[CHIP][enq[CHIP]][0]:SCM0[47].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[46].r[CHIP][enq[CHIP]][3] : SCM0[47].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[47].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[47].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[47].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[47].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[47].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[46].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[46].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[46].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[47].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[46].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[46].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[46].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[47].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[46].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[46].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[46].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[47].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[46].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[46].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[46].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[47].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[47].enq[CHIP] = 1-SCBR[47].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_48(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit48 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (48 && SCBR[47].enq[CHIP]==SCBR[47].deq[CHIP]) || (48<57 && SCBR[48].enq[CHIP]!=SCBR[48].deq[CHIP])) continue;
SCBR[47].deq[CHIP] = 1-SCBR[47].deq[CHIP];
enq[CHIP] = SCBR[48].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[48].r[CHIP][enq[CHIP]][3] = SCBR[47].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[47].r[CHIP][enq[CHIP]][0]:SCM1[48].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[47].r[CHIP][enq[CHIP]][0] : SCM1[48].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[48].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[47].r[CHIP][enq[CHIP]][0]:SCM0[48].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[47].r[CHIP][enq[CHIP]][0] : SCM0[48].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[48].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[48].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[48].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[47].r[CHIP][enq[CHIP]][0]:SCM1[48].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[47].r[CHIP][enq[CHIP]][0] : SCM1[48].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[48].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[47].r[CHIP][enq[CHIP]][0]:SCM0[48].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[47].r[CHIP][enq[CHIP]][0] : SCM0[48].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[48].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[48].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[48].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[47].r[CHIP][enq[CHIP]][0]:SCM1[48].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[47].r[CHIP][enq[CHIP]][3] : SCM1[48].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[48].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[48].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[48].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[47].r[CHIP][enq[CHIP]][0]:SCM0[48].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[47].r[CHIP][enq[CHIP]][3] : SCM0[48].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[48].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[48].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[48].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[48].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[48].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[47].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[47].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[47].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[48].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[47].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[47].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[47].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[48].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[47].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[47].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[47].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[48].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[47].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[47].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[47].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[48].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[48].enq[CHIP] = 1-SCBR[48].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_49(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit49 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (49 && SCBR[48].enq[CHIP]==SCBR[48].deq[CHIP]) || (49<57 && SCBR[49].enq[CHIP]!=SCBR[49].deq[CHIP])) continue;
SCBR[48].deq[CHIP] = 1-SCBR[48].deq[CHIP];
enq[CHIP] = SCBR[49].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[49].r[CHIP][enq[CHIP]][3] = SCBR[48].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[48].r[CHIP][enq[CHIP]][0]:SCM1[49].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[48].r[CHIP][enq[CHIP]][0] : SCM1[49].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[49].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[48].r[CHIP][enq[CHIP]][0]:SCM0[49].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[48].r[CHIP][enq[CHIP]][0] : SCM0[49].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[49].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[49].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[49].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[48].r[CHIP][enq[CHIP]][0]:SCM1[49].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[48].r[CHIP][enq[CHIP]][0] : SCM1[49].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[49].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[48].r[CHIP][enq[CHIP]][0]:SCM0[49].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[48].r[CHIP][enq[CHIP]][0] : SCM0[49].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[49].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[49].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[49].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[48].r[CHIP][enq[CHIP]][0]:SCM1[49].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[48].r[CHIP][enq[CHIP]][3] : SCM1[49].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[49].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[49].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[49].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[48].r[CHIP][enq[CHIP]][0]:SCM0[49].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[48].r[CHIP][enq[CHIP]][3] : SCM0[49].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[49].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[49].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[49].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[49].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[49].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[48].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[48].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[48].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[49].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[48].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[48].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[48].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[49].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[48].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[48].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[48].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[49].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[48].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[48].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[48].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[49].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[49].enq[CHIP] = 1-SCBR[49].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_50(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit50 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (50 && SCBR[49].enq[CHIP]==SCBR[49].deq[CHIP]) || (50<57 && SCBR[50].enq[CHIP]!=SCBR[50].deq[CHIP])) continue;
SCBR[49].deq[CHIP] = 1-SCBR[49].deq[CHIP];
enq[CHIP] = SCBR[50].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[50].r[CHIP][enq[CHIP]][3] = SCBR[49].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[49].r[CHIP][enq[CHIP]][0]:SCM1[50].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[49].r[CHIP][enq[CHIP]][0] : SCM1[50].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[50].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[49].r[CHIP][enq[CHIP]][0]:SCM0[50].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[49].r[CHIP][enq[CHIP]][0] : SCM0[50].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[50].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[50].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[50].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[49].r[CHIP][enq[CHIP]][0]:SCM1[50].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[49].r[CHIP][enq[CHIP]][0] : SCM1[50].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[50].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[49].r[CHIP][enq[CHIP]][0]:SCM0[50].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[49].r[CHIP][enq[CHIP]][0] : SCM0[50].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[50].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[50].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[50].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[49].r[CHIP][enq[CHIP]][0]:SCM1[50].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[49].r[CHIP][enq[CHIP]][3] : SCM1[50].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[50].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[50].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[50].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[49].r[CHIP][enq[CHIP]][0]:SCM0[50].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[49].r[CHIP][enq[CHIP]][3] : SCM0[50].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[50].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[50].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[50].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[50].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[50].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[49].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[49].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[49].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[50].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[49].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[49].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[49].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[50].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[49].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[49].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[49].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[50].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[49].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[49].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[49].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[50].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[50].enq[CHIP] = 1-SCBR[50].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_51(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit51 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (51 && SCBR[50].enq[CHIP]==SCBR[50].deq[CHIP]) || (51<57 && SCBR[51].enq[CHIP]!=SCBR[51].deq[CHIP])) continue;
SCBR[50].deq[CHIP] = 1-SCBR[50].deq[CHIP];
enq[CHIP] = SCBR[51].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[51].r[CHIP][enq[CHIP]][3] = SCBR[50].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[50].r[CHIP][enq[CHIP]][0]:SCM1[51].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[50].r[CHIP][enq[CHIP]][0] : SCM1[51].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[51].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[50].r[CHIP][enq[CHIP]][0]:SCM0[51].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[50].r[CHIP][enq[CHIP]][0] : SCM0[51].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[51].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[51].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[51].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[50].r[CHIP][enq[CHIP]][0]:SCM1[51].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[50].r[CHIP][enq[CHIP]][0] : SCM1[51].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[51].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[50].r[CHIP][enq[CHIP]][0]:SCM0[51].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[50].r[CHIP][enq[CHIP]][0] : SCM0[51].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[51].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[51].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[51].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[50].r[CHIP][enq[CHIP]][0]:SCM1[51].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[50].r[CHIP][enq[CHIP]][3] : SCM1[51].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[51].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[51].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[51].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[50].r[CHIP][enq[CHIP]][0]:SCM0[51].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[50].r[CHIP][enq[CHIP]][3] : SCM0[51].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[51].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[51].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[51].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[51].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[51].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[50].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[50].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[50].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[51].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[50].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[50].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[50].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[51].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[50].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[50].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[50].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[51].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[50].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[50].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[50].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[51].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[51].enq[CHIP] = 1-SCBR[51].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_52(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit52 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (52 && SCBR[51].enq[CHIP]==SCBR[51].deq[CHIP]) || (52<57 && SCBR[52].enq[CHIP]!=SCBR[52].deq[CHIP])) continue;
SCBR[51].deq[CHIP] = 1-SCBR[51].deq[CHIP];
enq[CHIP] = SCBR[52].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[52].r[CHIP][enq[CHIP]][3] = SCBR[51].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[51].r[CHIP][enq[CHIP]][0]:SCM1[52].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[51].r[CHIP][enq[CHIP]][0] : SCM1[52].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[52].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[51].r[CHIP][enq[CHIP]][0]:SCM0[52].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[51].r[CHIP][enq[CHIP]][0] : SCM0[52].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[52].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[52].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[52].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[51].r[CHIP][enq[CHIP]][0]:SCM1[52].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[51].r[CHIP][enq[CHIP]][0] : SCM1[52].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[52].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[51].r[CHIP][enq[CHIP]][0]:SCM0[52].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[51].r[CHIP][enq[CHIP]][0] : SCM0[52].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[52].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[52].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[52].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[51].r[CHIP][enq[CHIP]][0]:SCM1[52].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[51].r[CHIP][enq[CHIP]][3] : SCM1[52].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[52].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[52].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[52].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[51].r[CHIP][enq[CHIP]][0]:SCM0[52].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[51].r[CHIP][enq[CHIP]][3] : SCM0[52].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[52].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[52].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[52].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[52].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[52].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[51].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[51].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[51].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[52].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[51].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[51].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[51].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[52].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[51].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[51].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[51].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[52].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[51].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[51].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[51].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[52].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[52].enq[CHIP] = 1-SCBR[52].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_53(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit53 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (53 && SCBR[52].enq[CHIP]==SCBR[52].deq[CHIP]) || (53<57 && SCBR[53].enq[CHIP]!=SCBR[53].deq[CHIP])) continue;
SCBR[52].deq[CHIP] = 1-SCBR[52].deq[CHIP];
enq[CHIP] = SCBR[53].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[53].r[CHIP][enq[CHIP]][3] = SCBR[52].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[52].r[CHIP][enq[CHIP]][0]:SCM1[53].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[52].r[CHIP][enq[CHIP]][0] : SCM1[53].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[53].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[52].r[CHIP][enq[CHIP]][0]:SCM0[53].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[52].r[CHIP][enq[CHIP]][0] : SCM0[53].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[53].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[53].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[53].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[52].r[CHIP][enq[CHIP]][0]:SCM1[53].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[52].r[CHIP][enq[CHIP]][0] : SCM1[53].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[53].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[52].r[CHIP][enq[CHIP]][0]:SCM0[53].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[52].r[CHIP][enq[CHIP]][0] : SCM0[53].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[53].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[53].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[53].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[52].r[CHIP][enq[CHIP]][0]:SCM1[53].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[52].r[CHIP][enq[CHIP]][3] : SCM1[53].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[53].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[53].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[53].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[52].r[CHIP][enq[CHIP]][0]:SCM0[53].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[52].r[CHIP][enq[CHIP]][3] : SCM0[53].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[53].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[53].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[53].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[53].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[53].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[52].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[52].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[52].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[53].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[52].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[52].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[52].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[53].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[52].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[52].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[52].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[53].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[52].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[52].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[52].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[53].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[53].enq[CHIP] = 1-SCBR[53].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_54(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit54 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (54 && SCBR[53].enq[CHIP]==SCBR[53].deq[CHIP]) || (54<57 && SCBR[54].enq[CHIP]!=SCBR[54].deq[CHIP])) continue;
SCBR[53].deq[CHIP] = 1-SCBR[53].deq[CHIP];
enq[CHIP] = SCBR[54].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[54].r[CHIP][enq[CHIP]][3] = SCBR[53].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[53].r[CHIP][enq[CHIP]][0]:SCM1[54].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[53].r[CHIP][enq[CHIP]][0] : SCM1[54].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[54].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[53].r[CHIP][enq[CHIP]][0]:SCM0[54].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[53].r[CHIP][enq[CHIP]][0] : SCM0[54].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[54].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[54].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[54].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[53].r[CHIP][enq[CHIP]][0]:SCM1[54].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[53].r[CHIP][enq[CHIP]][0] : SCM1[54].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[54].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[53].r[CHIP][enq[CHIP]][0]:SCM0[54].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[53].r[CHIP][enq[CHIP]][0] : SCM0[54].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[54].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[54].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[54].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[53].r[CHIP][enq[CHIP]][0]:SCM1[54].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[53].r[CHIP][enq[CHIP]][3] : SCM1[54].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[54].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[54].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[54].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[53].r[CHIP][enq[CHIP]][0]:SCM0[54].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[53].r[CHIP][enq[CHIP]][3] : SCM0[54].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[54].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[54].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[54].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[54].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[54].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[53].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[53].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[53].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[54].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[53].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[53].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[53].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[54].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[53].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[53].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[53].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[54].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[53].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[53].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[53].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[54].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[54].enq[CHIP] = 1-SCBR[54].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_55(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit55 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (55 && SCBR[54].enq[CHIP]==SCBR[54].deq[CHIP]) || (55<57 && SCBR[55].enq[CHIP]!=SCBR[55].deq[CHIP])) continue;
SCBR[54].deq[CHIP] = 1-SCBR[54].deq[CHIP];
enq[CHIP] = SCBR[55].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[55].r[CHIP][enq[CHIP]][3] = SCBR[54].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[54].r[CHIP][enq[CHIP]][0]:SCM1[55].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(0 ? SCBR[54].r[CHIP][enq[CHIP]][0] : SCM1[55].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
SCBR[55].r[CHIP][enq[CHIP]][1] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[54].r[CHIP][enq[CHIP]][0]:SCM0[55].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[54].r[CHIP][enq[CHIP]][0] : SCM0[55].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
SCBR[55].r[CHIP][enq[CHIP]][0] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][0] = SCBR[55].r[CHIP][enq[CHIP]][1];
mexd0[CHIP][0] = SCBR[55].r[CHIP][enq[CHIP]][0];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[54].r[CHIP][enq[CHIP]][0]:SCM1[55].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(0 ? SCBR[54].r[CHIP][enq[CHIP]][0] : SCM1[55].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
SCBR[55].r[CHIP][enq[CHIP]][5] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[54].r[CHIP][enq[CHIP]][0]:SCM0[55].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[54].r[CHIP][enq[CHIP]][0] : SCM0[55].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
SCBR[55].r[CHIP][enq[CHIP]][4] = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
mexd1[CHIP][1] = SCBR[55].r[CHIP][enq[CHIP]][5];
mexd0[CHIP][1] = SCBR[55].r[CHIP][enq[CHIP]][4];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[54].r[CHIP][enq[CHIP]][0]:SCM1[55].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[54].r[CHIP][enq[CHIP]][3] : SCM1[55].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[55].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[55].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[55].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[54].r[CHIP][enq[CHIP]][0]:SCM0[55].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(1 ? SCBR[54].r[CHIP][enq[CHIP]][3] : SCM0[55].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[55].r[CHIP][enq[CHIP]][8] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[55].r[CHIP][enq[CHIP]][8] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[55].r[CHIP][enq[CHIP]][8] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[55].r[CHIP][enq[CHIP]][9];
mexd0[CHIP][2] = SCBR[55].r[CHIP][enq[CHIP]][8];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[54].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[54].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[54].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[55].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[54].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[54].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[54].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[55].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[54].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[54].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[54].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[55].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[54].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[54].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[54].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[55].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[55].enq[CHIP] = 1-SCBR[55].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_56(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit56 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (56 && SCBR[55].enq[CHIP]==SCBR[55].deq[CHIP]) || (56<57 && SCBR[56].enq[CHIP]!=SCBR[56].deq[CHIP])) continue;
SCBR[55].deq[CHIP] = 1-SCBR[55].deq[CHIP];
enq[CHIP] = SCBR[56].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[56].r[CHIP][enq[CHIP]][0] = SCBR[55].r[CHIP][enq[CHIP]][3];
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[55].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[55].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[55].r[CHIP][enq[CHIP]][1], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[56].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[55].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[55].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[55].r[CHIP][enq[CHIP]][0], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[56].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[55].r[CHIP][enq[CHIP]][10] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[55].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[55].r[CHIP][enq[CHIP]][5], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[56].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[55].r[CHIP][enq[CHIP]][14] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[55].r[CHIP][enq[CHIP]][8], 0);
ex3 = exm(SCBR[55].r[CHIP][enq[CHIP]][4], 1);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^00000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^00000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[56].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[56].enq[CHIP] = 1-SCBR[56].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax7sc_pth_cnn_57(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit57 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (57 && SCBR[56].enq[CHIP]==SCBR[56].deq[CHIP]) || (57<57 && SCBR[57].enq[CHIP]!=SCBR[57].deq[CHIP])) continue;
SCBR[56].deq[CHIP] = 1-SCBR[56].deq[CHIP];
enq[CHIP] = SCBR[57].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[57].r[CHIP][enq[CHIP]][0] = SCBR[56].r[CHIP][enq[CHIP]][2];
SCBR[57].r[CHIP][enq[CHIP]][3] = SCBR[56].r[CHIP][enq[CHIP]][6];
}
{
SCBR[57].r[CHIP][enq[CHIP]][4] = SCBR[56].r[CHIP][enq[CHIP]][10];
SCBR[57].r[CHIP][enq[CHIP]][7] = SCBR[56].r[CHIP][enq[CHIP]][14];
}
{
SCBR[57].r[CHIP][enq[CHIP]][8] = SCBR[56].r[CHIP][enq[CHIP]][0];
}
{
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[56].r[CHIP][enq[CHIP]][8]:SCM1[57].b[CHIP][0]) : awoo1[CHIP][0];
offs = eam(1 ? SCBR[56].r[CHIP][enq[CHIP]][0] : SCM1[57].o[CHIP][0], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][0]);
adr = (Ull)(awoo1[CHIP][0] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[57].r[CHIP][enq[CHIP]][1] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[57].r[CHIP][enq[CHIP]][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[57].r[CHIP][enq[CHIP]][1] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][0] = SCBR[57].r[CHIP][enq[CHIP]][1];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[56].r[CHIP][enq[CHIP]][8]:SCM1[57].b[CHIP][1]) : awoo1[CHIP][1];
offs = eam(1 ? SCBR[56].r[CHIP][enq[CHIP]][0] : SCM1[57].o[CHIP][1], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][1]);
adr = (Ull)(awoo1[CHIP][1] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[57].r[CHIP][enq[CHIP]][5] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[57].r[CHIP][enq[CHIP]][5] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[57].r[CHIP][enq[CHIP]][5] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][1] = SCBR[57].r[CHIP][enq[CHIP]][5];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[56].r[CHIP][enq[CHIP]][8]:SCM1[57].b[CHIP][2]) : awoo1[CHIP][2];
offs = eam(1 ? SCBR[56].r[CHIP][enq[CHIP]][0] : SCM1[57].o[CHIP][2], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][2]);
adr = (Ull)(awoo1[CHIP][2] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[57].r[CHIP][enq[CHIP]][9] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[57].r[CHIP][enq[CHIP]][9] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[57].r[CHIP][enq[CHIP]][9] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][2] = SCBR[57].r[CHIP][enq[CHIP]][9];
}
{ Ull base, offs, adr, mexdist, mexlimit, load64;
  static int emax7_unaligned_load_valid;
  static Ull emax7_unaligned_load_high;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[56].r[CHIP][enq[CHIP]][8]:SCM1[57].b[CHIP][3]) : awoo1[CHIP][3];
offs = eam(1 ? SCBR[56].r[CHIP][enq[CHIP]][0] : SCM1[57].o[CHIP][3], 12);
mexdist = INIT0[CHIP] ? 0 : 0;
mexlimit = 0;
awoo1[CHIP][3] = (Ull)(INIT0[CHIP]?base:awoo1[CHIP][3]);
adr = (Ull)(awoo1[CHIP][3] + offs);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[57].r[CHIP][enq[CHIP]][13] = load64;
else if (!emax7_unaligned_load_valid) { /* BR[][][1] */
  emax7_unaligned_load_valid = 1;
  emax7_unaligned_load_high = load64;
  SCBR[57].r[CHIP][enq[CHIP]][13] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax7_unaligned_load_valid = 0;
  SCBR[57].r[CHIP][enq[CHIP]][13] = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
mexd1[CHIP][3] = SCBR[57].r[CHIP][enq[CHIP]][13];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[57].r[CHIP][enq[CHIP]][0] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[57].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32);
f0.f = f1.f + f2.f;
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2);
f0.f = f1.f + f2.f;
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[57].r[CHIP][enq[CHIP]][3] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[57].r[CHIP][enq[CHIP]][5], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32);
f0.f = f1.f + f2.f;
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2);
f0.f = f1.f + f2.f;
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[57].r[CHIP][enq[CHIP]][4] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[57].r[CHIP][enq[CHIP]][9], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32);
f0.f = f1.f + f2.f;
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2);
f0.f = f1.f + f2.f;
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[57].r[CHIP][enq[CHIP]][7] : alud[CHIP][3], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[57].r[CHIP][enq[CHIP]][13], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32);
f0.f = f1.f + f2.f;
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2);
f0.f = f1.f + f2.f;
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(2&1)||INIT0[CHIP]) ? ((2&2)?SCBR[57].r[CHIP][enq[CHIP]][8]:SCM0[57].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[57].r[CHIP][enq[CHIP]][0] : SCM0[57].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex>>1&1) *((Uint*)(adr&~7LL)+1) = (1==1? alud[CHIP][0] : SCBR[57].r[CHIP][enq[CHIP]][2])>>32;
if (cex   &1) *((Uint*)(adr&~7LL)  ) = (1==1? alud[CHIP][0] : SCBR[57].r[CHIP][enq[CHIP]][2]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(2&1)||INIT0[CHIP]) ? ((2&2)?SCBR[57].r[CHIP][enq[CHIP]][8]:SCM0[57].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[57].r[CHIP][enq[CHIP]][0] : SCM0[57].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1]);
adr = (Ull)(awoo0[CHIP][1] + offs);
if (cex>>1&1) *((Uint*)(adr&~7LL)+1) = (1==1? alud[CHIP][1] : SCBR[57].r[CHIP][enq[CHIP]][10])>>32;
if (cex   &1) *((Uint*)(adr&~7LL)  ) = (1==1? alud[CHIP][1] : SCBR[57].r[CHIP][enq[CHIP]][10]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(2&1)||INIT0[CHIP]) ? ((2&2)?SCBR[57].r[CHIP][enq[CHIP]][8]:SCM0[57].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(0 ? SCBR[57].r[CHIP][enq[CHIP]][0] : SCM0[57].o[CHIP][2], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
if (cex>>1&1) *((Uint*)(adr&~7LL)+1) = (1==1? alud[CHIP][2] : SCBR[57].r[CHIP][enq[CHIP]][0])>>32;
if (cex   &1) *((Uint*)(adr&~7LL)  ) = (1==1? alud[CHIP][2] : SCBR[57].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(2&1)||INIT0[CHIP]) ? ((2&2)?SCBR[57].r[CHIP][enq[CHIP]][8]:SCM0[57].b[CHIP][3]) : awoo0[CHIP][3];
offs = eam(0 ? SCBR[57].r[CHIP][enq[CHIP]][0] : SCM0[57].o[CHIP][3], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][3] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][3]);
adr = (Ull)(awoo0[CHIP][3] + offs);
if (cex>>1&1) *((Uint*)(adr&~7LL)+1) = (1==1? alud[CHIP][3] : SCBR[57].r[CHIP][enq[CHIP]][0])>>32;
if (cex   &1) *((Uint*)(adr&~7LL)  ) = (1==1? alud[CHIP][3] : SCBR[57].r[CHIP][enq[CHIP]][0]);
}
SCBR[57].enq[CHIP] = 1-SCBR[57].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
