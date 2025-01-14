
## EMAX5/6 Application Simulator       ##
##   Copyright (C) 2014 by NAIST UNIV. ##
##         Primary writer: Y.Nakashima ##
##                nakashim@is.naist.jp ##

## -DEMAX5     ... with emaxnc/emax
## -DEMAX6     ... with emaxnc/emax
## -DARMSIML   ... with bsim/csim
## -DARMZYNQ   ... with ZYNQ

## Makefile              native        : none
## Makefile.emax5nc      native+EMAX5NC: -DEMAX5
## Makefile.emax6nc      native+EMAX6NC: -DEMAX6

## Makefile-bsim         bsim          : -DARMSIML
## Makefile-bsim.emax5nc bsim+EMAX5NC  : -DARMSIML -DEMAX5
## Makefile-bsim.emax5   bsim+EMAX5    : -DARMSIML -DEMAX5 emax5_start->emax_start->syscall
## Makefile-zynq.emax5nc(ZYNQ+EMAX5NC  : -DARMZYNQ -DEMAX5)
## Makefile-zynq.emax5  (ZYNQ+EMAX5HW  : -DARMZYNQ -DEMAX5) emax5_start->udev_write

## Makefile-csim         csim          : -DARMSIML
## Makefile-csim.emax6nc csim+EMAX6NC  : -DARMSIML -DEMAX6
## Makefile-csim.emax6   csim+EMAX6    : -DARMSIML -DEMAX6 emax6_start->emax_start->syscall
## Makefile-zynq.emax6nc(ZYNQ+EMAX6NC  : -DARMZYNQ -DEMAX6)
## Makefile-zynq.emax6  (ZYNQ+EMAX6HW  : -DARMZYNQ -DEMAX6) emax6_start->udev_write

PROJTOP	      = ../../
OPTION        = -mstrict-align -DDEBUG -DCYCLECNT -DARMZYNQ -DEMAX7 -DFPDDMA
PROGRAM       = cnn3d-acap_sang.emax7+dma
CPP           = cpp -P
CC            = gcc
CFLAGS        = -I. -O2 $(OPTION)
AS            = as
ASFLAGS       = 
LD            = gcc
LDFLAGS       = 
LIBS          = -lm -lc -lX11 -lXext -lrt -pthread
LIBFLAGS      = 
OBJS	      =	cnn3d+rmm-emax7.o
SRCS	      =	cnn3d+rmm_sang.c

all:		$(PROGRAM)

clean:;		rm -f *.o core *~ *-mark.c *-cppo.c *-emax7.c *-emax7s?.c

cnn3d-acap_sang.emax7+dma: cnn3d+rmm_sang-emax7.o
		$(CC) $(LDFLAGS) -o $@ $< $(LIBFLAGS) $(LIBS)

cnn3d+rmm_sang-emax7.o:	cnn3d+rmm_sang-emax7.c
		$(CC) $(CFLAGS) -w -c $<

cnn3d+rmm_sang-emax7.c:	cnn3d+rmm_sang.c
		$(PROJTOP)/src/conv-mark/conv-mark $< > $<-mark.c
		$(CPP) -DNCHIP=1 -DIMAP=2 $(OPTION) $<-mark.c > $<-cppo.c
		$(PROJTOP)/src/conv-c2d/conv-c2d $<-cppo.c

###

cnn3d+rmm-emax7.o: ../../src/conv-c2d/emax7.h ../../src/conv-c2d/emax7lib.c