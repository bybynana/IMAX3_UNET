static char RcsHeader[] = "$Header: /usr/home/nakashim/proj-arm64/sample/mm_cnn_lf/RCS/cnn.c,v 1.4 2018/02/04 10:28:43 nakashim Exp nakashim $";
typedef unsigned char Uchar;
typedef unsigned short Ushort;
typedef unsigned int Uint;
typedef unsigned long long Ull;
typedef long long int Sll;
typedef long double Dll;
typedef long unsigned int size_t;
typedef __builtin_va_list __gnuc_va_list;
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;
typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;
typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef long int __suseconds64_t;
typedef int __daddr_t;
typedef int __key_t;
typedef int __clockid_t;
typedef void * __timer_t;
typedef int __blksize_t;
typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;
typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;
typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;
typedef long int __fsword_t;
typedef long int __ssize_t;
typedef long int __syscall_slong_t;
typedef unsigned long int __syscall_ulong_t;
typedef __off64_t __loff_t;
typedef char *__caddr_t;
typedef long int __intptr_t;
typedef unsigned int __socklen_t;
typedef int __sig_atomic_t;
typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
typedef struct _G_fpos_t
{
  __off_t __pos;
  __mbstate_t __state;
} __fpos_t;
typedef struct _G_fpos64_t
{
  __off64_t __pos;
  __mbstate_t __state;
} __fpos64_t;
struct _IO_FILE;
typedef struct _IO_FILE __FILE;
struct _IO_FILE;
typedef struct _IO_FILE FILE;
struct _IO_FILE;
struct _IO_marker;
struct _IO_codecvt;
struct _IO_wide_data;
typedef void _IO_lock_t;
struct _IO_FILE
{
  int _flags;
  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;
  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;
  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int _fileno;
  int _flags2;
  __off_t _old_offset;
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t *_lock;
  __off64_t _offset;
  struct _IO_codecvt *_codecvt;
  struct _IO_wide_data *_wide_data;
  struct _IO_FILE *_freeres_list;
  void *_freeres_buf;
  size_t __pad5;
  int _mode;
  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
};
typedef __gnuc_va_list va_list;
typedef __off_t off_t;
typedef __ssize_t ssize_t;
typedef __fpos_t fpos_t;
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
extern int remove (const char *__filename) __attribute__ ((__nothrow__ , __leaf__));
extern int rename (const char *__old, const char *__new) __attribute__ ((__nothrow__ , __leaf__));
extern int renameat (int __oldfd, const char *__old, int __newfd,
       const char *__new) __attribute__ ((__nothrow__ , __leaf__));
extern int fclose (FILE *__stream);
extern FILE *tmpfile (void)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern char *tmpnam (char[20]) __attribute__ ((__nothrow__ , __leaf__)) ;
extern char *tmpnam_r (char __s[20]) __attribute__ ((__nothrow__ , __leaf__)) ;
extern char *tempnam (const char *__dir, const char *__pfx)
   __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (__builtin_free, 1)));
extern int fflush (FILE *__stream);
extern int fflush_unlocked (FILE *__stream);
extern FILE *fopen (const char *__restrict __filename,
      const char *__restrict __modes)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern FILE *freopen (const char *__restrict __filename,
        const char *__restrict __modes,
        FILE *__restrict __stream) ;
extern FILE *fdopen (int __fd, const char *__modes) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));
extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__ , __leaf__));
extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int fprintf (FILE *__restrict __stream,
      const char *__restrict __format, ...);
extern int printf (const char *__restrict __format, ...);
extern int sprintf (char *__restrict __s,
      const char *__restrict __format, ...) __attribute__ ((__nothrow__));
extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg);
extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);
extern int vsprintf (char *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));
extern int snprintf (char *__restrict __s, size_t __maxlen,
       const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));
extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));
extern int vdprintf (int __fd, const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));
extern int fscanf (FILE *__restrict __stream,
     const char *__restrict __format, ...) ;
extern int scanf (const char *__restrict __format, ...) ;
extern int sscanf (const char *__restrict __s,
     const char *__restrict __format, ...) __attribute__ ((__nothrow__ , __leaf__));
extern int fscanf (FILE *__restrict __stream, const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf") ;
extern int scanf (const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf") ;
extern int sscanf (const char *__restrict __s, const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf") __attribute__ ((__nothrow__ , __leaf__));
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *__restrict __s,
      const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vsscanf") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__format__ (__scanf__, 2, 0)));
extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);
extern int getchar (void);
extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
extern int fgetc_unlocked (FILE *__stream);
extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);
extern int putchar (int __c);
extern int fputc_unlocked (int __c, FILE *__stream);
extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);
extern int getw (FILE *__stream);
extern int putw (int __w, FILE *__stream);
extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     __attribute__ ((__access__ (__write_only__, 1, 2)));
extern __ssize_t __getdelim (char **__restrict __lineptr,
                             size_t *__restrict __n, int __delimiter,
                             FILE *__restrict __stream) ;
extern __ssize_t getdelim (char **__restrict __lineptr,
                           size_t *__restrict __n, int __delimiter,
                           FILE *__restrict __stream) ;
extern __ssize_t getline (char **__restrict __lineptr,
                          size_t *__restrict __n,
                          FILE *__restrict __stream) ;
extern int fputs (const char *__restrict __s, FILE *__restrict __stream);
extern int puts (const char *__s);
extern int ungetc (int __c, FILE *__stream);
extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite (const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s);
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream);
extern int fseek (FILE *__stream, long int __off, int __whence);
extern long int ftell (FILE *__stream) ;
extern void rewind (FILE *__stream);
extern int fseeko (FILE *__stream, __off_t __off, int __whence);
extern __off_t ftello (FILE *__stream) ;
extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);
extern int fsetpos (FILE *__stream, const fpos_t *__pos);
extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int feof (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int ferror (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void perror (const char *__s);
extern int fileno (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int pclose (FILE *__stream);
extern FILE *popen (const char *__command, const char *__modes)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (pclose, 1))) ;
extern char *ctermid (char *__s) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__access__ (__write_only__, 1)));
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int __uflow (FILE *);
extern int __overflow (FILE *, int);
typedef unsigned int wchar_t;
typedef struct
  {
    int quot;
    int rem;
  } div_t;
typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;
__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;
extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__ , __leaf__)) ;
extern double atof (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern int atoi (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern long int atol (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
__extension__ extern long long int atoll (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern double strtod (const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern float strtof (const char *__restrict __nptr,
       char **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long double strtold (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int strtol (const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern unsigned long int strtoul (const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
__extension__
extern long long int strtoq (const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
__extension__
extern unsigned long long int strtouq (const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
__extension__
extern long long int strtoll (const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
__extension__
extern unsigned long long int strtoull (const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern char *l64a (long int __n) __attribute__ ((__nothrow__ , __leaf__)) ;
extern long int a64l (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;
typedef __loff_t loff_t;
typedef __ino_t ino_t;
typedef __dev_t dev_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __nlink_t nlink_t;
typedef __uid_t uid_t;
typedef __pid_t pid_t;
typedef __id_t id_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;
typedef __key_t key_t;
typedef __clock_t clock_t;
typedef __clockid_t clockid_t;
typedef __time_t time_t;
typedef __timer_t timer_t;
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;
typedef int register_t __attribute__ ((__mode__ (__word__)));
static __inline __uint16_t
__bswap_16 (__uint16_t __bsx)
{
  return __builtin_bswap16 (__bsx);
}
static __inline __uint32_t
__bswap_32 (__uint32_t __bsx)
{
  return __builtin_bswap32 (__bsx);
}
__extension__ static __inline __uint64_t
__bswap_64 (__uint64_t __bsx)
{
  return __builtin_bswap64 (__bsx);
}
static __inline __uint16_t
__uint16_identity (__uint16_t __x)
{
  return __x;
}
static __inline __uint32_t
__uint32_identity (__uint32_t __x)
{
  return __x;
}
static __inline __uint64_t
__uint64_identity (__uint64_t __x)
{
  return __x;
}
typedef struct
{
  unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
} __sigset_t;
typedef __sigset_t sigset_t;
struct timeval
{
  __time_t tv_sec;
  __suseconds_t tv_usec;
};
struct timespec
{
  __time_t tv_sec;
  __syscall_slong_t tv_nsec;
};
typedef __suseconds_t suseconds_t;
typedef long int __fd_mask;
typedef struct
  {
    __fd_mask __fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];
  } fd_set;
typedef __fd_mask fd_mask;
extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);
typedef __blksize_t blksize_t;
typedef __blkcnt_t blkcnt_t;
typedef __fsblkcnt_t fsblkcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;
typedef union
{
  __extension__ unsigned long long int __value64;
  struct
  {
    unsigned int __low;
    unsigned int __high;
  } __value32;
} __atomic_wide_counter;
typedef struct __pthread_internal_list
{
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;
typedef struct __pthread_internal_slist
{
  struct __pthread_internal_slist *__next;
} __pthread_slist_t;
struct __pthread_mutex_s
{
  int __lock ;
  unsigned int __count;
  int __owner;
  unsigned int __nusers;
  int __kind;
  int __spins;
  __pthread_list_t __list;
};
struct __pthread_rwlock_arch_t
{
  unsigned int __readers;
  unsigned int __writers;
  unsigned int __wrphase_futex;
  unsigned int __writers_futex;
  unsigned int __pad3;
  unsigned int __pad4;
  int __cur_writer;
  int __shared;
  unsigned long int __pad1;
  unsigned long int __pad2;
  unsigned int __flags;
};
struct __pthread_cond_s
{
  __atomic_wide_counter __wseq;
  __atomic_wide_counter __g1_start;
  unsigned int __g_refs[2] ;
  unsigned int __g_size[2];
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
};
typedef unsigned int __tss_t;
typedef unsigned long int __thrd_t;
typedef struct
{
  int __data ;
} __once_flag;
typedef unsigned long int pthread_t;
typedef union
{
  char __size[8];
  int __align;
} pthread_mutexattr_t;
typedef union
{
  char __size[8];
  int __align;
} pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
union pthread_attr_t
{
  char __size[64];
  long int __align;
};
typedef union pthread_attr_t pthread_attr_t;
typedef union
{
  struct __pthread_mutex_s __data;
  char __size[48];
  long int __align;
} pthread_mutex_t;
typedef union
{
  struct __pthread_cond_s __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;
typedef union
{
  struct __pthread_rwlock_arch_t __data;
  char __size[56];
  long int __align;
} pthread_rwlock_t;
typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;
typedef volatile int pthread_spinlock_t;
typedef union
{
  char __size[32];
  long int __align;
} pthread_barrier_t;
typedef union
{
  char __size[8];
  int __align;
} pthread_barrierattr_t;
extern long int random (void) __attribute__ ((__nothrow__ , __leaf__));
extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));
extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };
extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));
extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int rand (void) __attribute__ ((__nothrow__ , __leaf__));
extern void srand (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));
extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__ , __leaf__));
extern double drand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int lrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int mrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void srand48 (long int __seedval) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    __extension__ unsigned long long int __a;
  };
extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern __uint32_t arc4random (void)
     __attribute__ ((__nothrow__ , __leaf__)) ;
extern void arc4random_buf (void *__buf, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern __uint32_t arc4random_uniform (__uint32_t __upper_bound)
     __attribute__ ((__nothrow__ , __leaf__)) ;
extern void *malloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__))
     __attribute__ ((__alloc_size__ (1))) ;
extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (1, 2))) ;
extern void *realloc (void *__ptr, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__)) __attribute__ ((__alloc_size__ (2)));
extern void free (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));
extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__))
     __attribute__ ((__alloc_size__ (2, 3)))
    __attribute__ ((__malloc__ (__builtin_free, 1)));
extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__ (reallocarray, 1)));
extern void *alloca (size_t __size) __attribute__ ((__nothrow__ , __leaf__));
extern void *valloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__))
     __attribute__ ((__alloc_size__ (1))) ;
extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern void *aligned_alloc (size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__alloc_align__ (1)))
     __attribute__ ((__alloc_size__ (2))) ;
extern void abort (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int at_quick_exit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void quick_exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void _Exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern char *getenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int putenv (char *__string) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int setenv (const char *__name, const char *__value, int __replace)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int unsetenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int clearenv (void) __attribute__ ((__nothrow__ , __leaf__));
extern char *mktemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) ;
extern int mkstemps (char *__template, int __suffixlen) __attribute__ ((__nonnull__ (1))) ;
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int system (const char *__command) ;
extern char *realpath (const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__ , __leaf__)) ;
typedef int (*__compar_fn_t) (const void *, const void *);
extern void *bsearch (const void *__key, const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) ;
extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
extern int abs (int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern long int labs (long int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
__extension__ extern long long int llabs (long long int __x)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;
extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;
extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int mblen (const char *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern int mbtowc (wchar_t *__restrict __pwc,
     const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__ , __leaf__));
extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__))
    __attribute__ ((__access__ (__read_only__, 2)));
extern size_t wcstombs (char *__restrict __s,
   const wchar_t *__restrict __pwcs, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__access__ (__write_only__, 1, 3)))
  __attribute__ ((__access__ (__read_only__, 2)));
extern int rpmatch (const char *__response) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int getsubopt (char **__restrict __optionp,
        char *const *__restrict __tokens,
        char **__restrict __valuep)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3))) ;
extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
  long int tm_gmtoff;
  const char *tm_zone;
};
struct itimerspec
  {
    struct timespec it_interval;
    struct timespec it_value;
  };
struct sigevent;
struct __locale_struct
{
  struct __locale_data *__locales[13];
  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;
  const char *__names[13];
};
typedef struct __locale_struct *__locale_t;
typedef __locale_t locale_t;
extern clock_t clock (void) __attribute__ ((__nothrow__ , __leaf__));
extern time_t time (time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
extern double difftime (time_t __time1, time_t __time0)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern time_t mktime (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern size_t strftime (char *__restrict __s, size_t __maxsize,
   const char *__restrict __format,
   const struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));
extern size_t strftime_l (char *__restrict __s, size_t __maxsize,
     const char *__restrict __format,
     const struct tm *__restrict __tp,
     locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
extern struct tm *gmtime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
extern struct tm *localtime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
extern struct tm *gmtime_r (const time_t *__restrict __timer,
       struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));
extern struct tm *localtime_r (const time_t *__restrict __timer,
          struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));
extern char *asctime (const struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern char *ctime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
extern char *asctime_r (const struct tm *__restrict __tp,
   char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));
extern char *ctime_r (const time_t *__restrict __timer,
        char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));
extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;
extern char *tzname[2];
extern void tzset (void) __attribute__ ((__nothrow__ , __leaf__));
extern int daylight;
extern long int timezone;
extern time_t timegm (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern time_t timelocal (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern int dysize (int __year) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int nanosleep (const struct timespec *__requested_time,
        struct timespec *__remaining);
extern int clock_getres (clockid_t __clock_id, struct timespec *__res) __attribute__ ((__nothrow__ , __leaf__));
extern int clock_gettime (clockid_t __clock_id, struct timespec *__tp)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int clock_settime (clockid_t __clock_id, const struct timespec *__tp)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int clock_nanosleep (clockid_t __clock_id, int __flags,
       const struct timespec *__req,
       struct timespec *__rem);
extern int clock_getcpuclockid (pid_t __pid, clockid_t *__clock_id) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_create (clockid_t __clock_id,
    struct sigevent *__restrict __evp,
    timer_t *__restrict __timerid) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_delete (timer_t __timerid) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_settime (timer_t __timerid, int __flags,
     const struct itimerspec *__restrict __value,
     struct itimerspec *__restrict __ovalue) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_gettime (timer_t __timerid, struct itimerspec *__value)
     __attribute__ ((__nothrow__ , __leaf__));
extern int timer_getoverrun (timer_t __timerid) __attribute__ ((__nothrow__ , __leaf__));
extern int timespec_get (struct timespec *__ts, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
struct flock
  {
    short int l_type;
    short int l_whence;
    __off_t l_start;
    __off_t l_len;
    __pid_t l_pid;
  };
struct stat
  {
    __dev_t st_dev;
    __ino_t st_ino;
    __mode_t st_mode;
    __nlink_t st_nlink;
    __uid_t st_uid;
    __gid_t st_gid;
    __dev_t st_rdev;
    __dev_t __pad1;
    __off_t st_size;
    __blksize_t st_blksize;
    int __pad2;
    __blkcnt_t st_blocks;
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
    int __glibc_reserved[2];
  };
extern int fcntl (int __fd, int __cmd, ...);
extern int open (const char *__file, int __oflag, ...) __attribute__ ((__nonnull__ (1)));
extern int openat (int __fd, const char *__file, int __oflag, ...)
     __attribute__ ((__nonnull__ (2)));
extern int creat (const char *__file, mode_t __mode) __attribute__ ((__nonnull__ (1)));
extern int lockf (int __fd, int __cmd, off_t __len);
extern int posix_fadvise (int __fd, off_t __offset, off_t __len,
     int __advise) __attribute__ ((__nothrow__ , __leaf__));
extern int posix_fallocate (int __fd, off_t __offset, off_t __len);
typedef float float_t;
typedef double double_t;
extern int __fpclassify (double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern int __signbit (double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern int __isinf (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __finite (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __isnan (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __iseqsig (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern int __issignaling (double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
 extern double acos (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __acos (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double asin (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __asin (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double atan (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atan (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double atan2 (double __y, double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atan2 (double __y, double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double cos (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cos (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double sin (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sin (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double tan (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __tan (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double cosh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cosh (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double sinh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sinh (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double tanh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __tanh (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double acosh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __acosh (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double asinh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __asinh (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double atanh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atanh (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double exp (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __exp (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double frexp (double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern double __frexp (double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));
extern double ldexp (double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern double __ldexp (double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));
 extern double log (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double log10 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log10 (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double modf (double __x, double *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern double __modf (double __x, double *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
 extern double expm1 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __expm1 (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double log1p (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log1p (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double logb (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __logb (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double exp2 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __exp2 (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double log2 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log2 (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double pow (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __pow (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double sqrt (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sqrt (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double hypot (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __hypot (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
 extern double cbrt (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cbrt (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double ceil (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __ceil (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fabs (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fabs (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double floor (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __floor (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fmod (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __fmod (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern int isinf (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int finite (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern double drem (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __drem (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double significand (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __significand (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double copysign (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __copysign (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double nan (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern double __nan (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
extern int isnan (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern double j0 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __j0 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double j1 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __j1 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double jn (int, double) __attribute__ ((__nothrow__ , __leaf__)); extern double __jn (int, double) __attribute__ ((__nothrow__ , __leaf__));
extern double y0 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __y0 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double y1 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __y1 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double yn (int, double) __attribute__ ((__nothrow__ , __leaf__)); extern double __yn (int, double) __attribute__ ((__nothrow__ , __leaf__));
 extern double erf (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __erf (double) __attribute__ ((__nothrow__ , __leaf__));
 extern double erfc (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __erfc (double) __attribute__ ((__nothrow__ , __leaf__));
extern double lgamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __lgamma (double) __attribute__ ((__nothrow__ , __leaf__));
extern double tgamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __tgamma (double) __attribute__ ((__nothrow__ , __leaf__));
extern double gamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __gamma (double) __attribute__ ((__nothrow__ , __leaf__));
extern double lgamma_r (double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern double __lgamma_r (double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));
extern double rint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __rint (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double nextafter (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __nextafter (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double nexttoward (double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __nexttoward (double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double remainder (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __remainder (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double scalbn (double __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalbn (double __x, int __n) __attribute__ ((__nothrow__ , __leaf__));
extern int ilogb (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogb (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double scalbln (double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalbln (double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));
extern double nearbyint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __nearbyint (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double round (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __round (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double trunc (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __trunc (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double remquo (double __x, double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern double __remquo (double __x, double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));
extern long int lrint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrint (double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrint (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int lround (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lround (double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llround (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llround (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double fdim (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __fdim (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double fmax (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmax (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fmin (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmin (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fma (double __x, double __y, double __z) __attribute__ ((__nothrow__ , __leaf__)); extern double __fma (double __x, double __y, double __z) __attribute__ ((__nothrow__ , __leaf__));
extern double scalb (double __x, double __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalb (double __x, double __n) __attribute__ ((__nothrow__ , __leaf__));
extern int __fpclassifyf (float __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern int __signbitf (float __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern int __isinff (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __finitef (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __isnanf (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __iseqsigf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern int __issignalingf (float __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
 extern float acosf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __acosf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float asinf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __asinf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float atanf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atanf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float atan2f (float __y, float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atan2f (float __y, float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float cosf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __cosf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float sinf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sinf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float tanf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __tanf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float coshf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __coshf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float sinhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sinhf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float tanhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __tanhf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float acoshf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __acoshf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float asinhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __asinhf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float atanhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atanhf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float expf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __expf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float frexpf (float __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern float __frexpf (float __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));
extern float ldexpf (float __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern float __ldexpf (float __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));
 extern float logf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __logf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float log10f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log10f (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float modff (float __x, float *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern float __modff (float __x, float *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
 extern float expm1f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __expm1f (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float log1pf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log1pf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float logbf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __logbf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float exp2f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __exp2f (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float log2f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log2f (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float powf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __powf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern float sqrtf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sqrtf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float hypotf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __hypotf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
 extern float cbrtf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __cbrtf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float ceilf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __ceilf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fabsf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fabsf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float floorf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __floorf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fmodf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __fmodf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern int isinff (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int finitef (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern float dremf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __dremf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern float significandf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __significandf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float copysignf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __copysignf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float nanf (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern float __nanf (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
extern int isnanf (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern float j0f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __j0f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float j1f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __j1f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float jnf (int, float) __attribute__ ((__nothrow__ , __leaf__)); extern float __jnf (int, float) __attribute__ ((__nothrow__ , __leaf__));
extern float y0f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __y0f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float y1f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __y1f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float ynf (int, float) __attribute__ ((__nothrow__ , __leaf__)); extern float __ynf (int, float) __attribute__ ((__nothrow__ , __leaf__));
 extern float erff (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __erff (float) __attribute__ ((__nothrow__ , __leaf__));
 extern float erfcf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __erfcf (float) __attribute__ ((__nothrow__ , __leaf__));
extern float lgammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __lgammaf (float) __attribute__ ((__nothrow__ , __leaf__));
extern float tgammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __tgammaf (float) __attribute__ ((__nothrow__ , __leaf__));
extern float gammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __gammaf (float) __attribute__ ((__nothrow__ , __leaf__));
extern float lgammaf_r (float, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern float __lgammaf_r (float, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));
extern float rintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __rintf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float nextafterf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __nextafterf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern float nexttowardf (float __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __nexttowardf (float __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern float remainderf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __remainderf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern float scalbnf (float __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalbnf (float __x, int __n) __attribute__ ((__nothrow__ , __leaf__));
extern int ilogbf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float scalblnf (float __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalblnf (float __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));
extern float nearbyintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __nearbyintf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float roundf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __roundf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float truncf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __truncf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float remquof (float __x, float __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern float __remquof (float __x, float __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));
extern long int lrintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintf (float __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int lroundf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundf (float __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float fdimf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __fdimf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern float fmaxf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fmaxf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fminf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fminf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fmaf (float __x, float __y, float __z) __attribute__ ((__nothrow__ , __leaf__)); extern float __fmaf (float __x, float __y, float __z) __attribute__ ((__nothrow__ , __leaf__));
extern float scalbf (float __x, float __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalbf (float __x, float __n) __attribute__ ((__nothrow__ , __leaf__));
extern int __fpclassifyl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern int __signbitl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern int __isinfl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __finitel (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __isnanl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __iseqsigl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern int __issignalingl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
 extern long double acosl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __acosl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double asinl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __asinl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double atanl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atanl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double atan2l (long double __y, long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atan2l (long double __y, long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double cosl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __cosl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double sinl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sinl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double tanl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tanl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double coshl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __coshl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double sinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double tanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double acoshl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __acoshl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double asinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __asinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double atanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double expl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __expl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double frexpl (long double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern long double __frexpl (long double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));
extern long double ldexpl (long double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern long double __ldexpl (long double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));
 extern long double logl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __logl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double log10l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log10l (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double modfl (long double __x, long double *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern long double __modfl (long double __x, long double *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
 extern long double expm1l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __expm1l (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double log1pl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log1pl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double logbl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __logbl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double exp2l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __exp2l (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double log2l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log2l (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double powl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __powl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern long double sqrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sqrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double hypotl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __hypotl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
 extern long double cbrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __cbrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double ceill (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __ceill (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fabsl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fabsl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double floorl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __floorl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fmodl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fmodl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern int isinfl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int finitel (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern long double dreml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __dreml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern long double significandl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __significandl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double copysignl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __copysignl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double nanl (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nanl (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
extern int isnanl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern long double j0l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __j0l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double j1l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __j1l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double jnl (int, long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __jnl (int, long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double y0l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __y0l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double y1l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __y1l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double ynl (int, long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __ynl (int, long double) __attribute__ ((__nothrow__ , __leaf__));
 extern long double erfl (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __erfl (long double) __attribute__ ((__nothrow__ , __leaf__));
 extern long double erfcl (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __erfcl (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double lgammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __lgammal (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double tgammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tgammal (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double gammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __gammal (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double lgammal_r (long double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern long double __lgammal_r (long double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));
extern long double rintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __rintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double nextafterl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nextafterl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern long double nexttowardl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nexttowardl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern long double remainderl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __remainderl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern long double scalbnl (long double __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalbnl (long double __x, int __n) __attribute__ ((__nothrow__ , __leaf__));
extern int ilogbl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double scalblnl (long double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalblnl (long double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));
extern long double nearbyintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nearbyintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double roundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __roundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double truncl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __truncl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double remquol (long double __x, long double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern long double __remquol (long double __x, long double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));
extern long int lrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int lroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double fdiml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fdiml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern long double fmaxl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fmaxl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fminl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fminl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__ , __leaf__));
extern long double scalbl (long double __x, long double __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalbl (long double __x, long double __n) __attribute__ ((__nothrow__ , __leaf__));
extern int signgam;
enum
  {
    FP_NAN =
      0,
    FP_INFINITE =
      1,
    FP_ZERO =
      2,
    FP_SUBNORMAL =
      3,
    FP_NORMAL =
      4
  };
typedef __useconds_t useconds_t;
typedef __intptr_t intptr_t;
typedef __socklen_t socklen_t;
extern int access (const char *__name, int __type) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int faccessat (int __fd, const char *__file, int __type, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;
extern __off_t lseek (int __fd, __off_t __offset, int __whence) __attribute__ ((__nothrow__ , __leaf__));
extern int close (int __fd);
extern void closefrom (int __lowfd) __attribute__ ((__nothrow__ , __leaf__));
extern ssize_t read (int __fd, void *__buf, size_t __nbytes)
    __attribute__ ((__access__ (__write_only__, 2, 3)));
extern ssize_t write (int __fd, const void *__buf, size_t __n)
    __attribute__ ((__access__ (__read_only__, 2, 3)));
extern ssize_t pread (int __fd, void *__buf, size_t __nbytes,
        __off_t __offset)
    __attribute__ ((__access__ (__write_only__, 2, 3)));
extern ssize_t pwrite (int __fd, const void *__buf, size_t __n,
         __off_t __offset)
    __attribute__ ((__access__ (__read_only__, 2, 3)));
extern int pipe (int __pipedes[2]) __attribute__ ((__nothrow__ , __leaf__)) ;
extern unsigned int alarm (unsigned int __seconds) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned int sleep (unsigned int __seconds);
extern __useconds_t ualarm (__useconds_t __value, __useconds_t __interval)
     __attribute__ ((__nothrow__ , __leaf__));
extern int usleep (__useconds_t __useconds);
extern int pause (void);
extern int chown (const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int fchown (int __fd, __uid_t __owner, __gid_t __group) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int lchown (const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int fchownat (int __fd, const char *__file, __uid_t __owner,
       __gid_t __group, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;
extern int chdir (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int fchdir (int __fd) __attribute__ ((__nothrow__ , __leaf__)) ;
extern char *getcwd (char *__buf, size_t __size) __attribute__ ((__nothrow__ , __leaf__)) ;
extern char *getwd (char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__))
    __attribute__ ((__access__ (__write_only__, 1)));
extern int dup (int __fd) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int dup2 (int __fd, int __fd2) __attribute__ ((__nothrow__ , __leaf__));
extern char **__environ;
extern int execve (const char *__path, char *const __argv[],
     char *const __envp[]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int fexecve (int __fd, char *const __argv[], char *const __envp[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int execv (const char *__path, char *const __argv[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execle (const char *__path, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execl (const char *__path, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execvp (const char *__file, char *const __argv[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execlp (const char *__file, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nice (int __inc) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void _exit (int __status) __attribute__ ((__noreturn__));
enum
  {
    _PC_LINK_MAX,
    _PC_MAX_CANON,
    _PC_MAX_INPUT,
    _PC_NAME_MAX,
    _PC_PATH_MAX,
    _PC_PIPE_BUF,
    _PC_CHOWN_RESTRICTED,
    _PC_NO_TRUNC,
    _PC_VDISABLE,
    _PC_SYNC_IO,
    _PC_ASYNC_IO,
    _PC_PRIO_IO,
    _PC_SOCK_MAXBUF,
    _PC_FILESIZEBITS,
    _PC_REC_INCR_XFER_SIZE,
    _PC_REC_MAX_XFER_SIZE,
    _PC_REC_MIN_XFER_SIZE,
    _PC_REC_XFER_ALIGN,
    _PC_ALLOC_SIZE_MIN,
    _PC_SYMLINK_MAX,
    _PC_2_SYMLINKS
  };
enum
  {
    _SC_ARG_MAX,
    _SC_CHILD_MAX,
    _SC_CLK_TCK,
    _SC_NGROUPS_MAX,
    _SC_OPEN_MAX,
    _SC_STREAM_MAX,
    _SC_TZNAME_MAX,
    _SC_JOB_CONTROL,
    _SC_SAVED_IDS,
    _SC_REALTIME_SIGNALS,
    _SC_PRIORITY_SCHEDULING,
    _SC_TIMERS,
    _SC_ASYNCHRONOUS_IO,
    _SC_PRIORITIZED_IO,
    _SC_SYNCHRONIZED_IO,
    _SC_FSYNC,
    _SC_MAPPED_FILES,
    _SC_MEMLOCK,
    _SC_MEMLOCK_RANGE,
    _SC_MEMORY_PROTECTION,
    _SC_MESSAGE_PASSING,
    _SC_SEMAPHORES,
    _SC_SHARED_MEMORY_OBJECTS,
    _SC_AIO_LISTIO_MAX,
    _SC_AIO_MAX,
    _SC_AIO_PRIO_DELTA_MAX,
    _SC_DELAYTIMER_MAX,
    _SC_MQ_OPEN_MAX,
    _SC_MQ_PRIO_MAX,
    _SC_VERSION,
    _SC_PAGESIZE,
    _SC_RTSIG_MAX,
    _SC_SEM_NSEMS_MAX,
    _SC_SEM_VALUE_MAX,
    _SC_SIGQUEUE_MAX,
    _SC_TIMER_MAX,
    _SC_BC_BASE_MAX,
    _SC_BC_DIM_MAX,
    _SC_BC_SCALE_MAX,
    _SC_BC_STRING_MAX,
    _SC_COLL_WEIGHTS_MAX,
    _SC_EQUIV_CLASS_MAX,
    _SC_EXPR_NEST_MAX,
    _SC_LINE_MAX,
    _SC_RE_DUP_MAX,
    _SC_CHARCLASS_NAME_MAX,
    _SC_2_VERSION,
    _SC_2_C_BIND,
    _SC_2_C_DEV,
    _SC_2_FORT_DEV,
    _SC_2_FORT_RUN,
    _SC_2_SW_DEV,
    _SC_2_LOCALEDEF,
    _SC_PII,
    _SC_PII_XTI,
    _SC_PII_SOCKET,
    _SC_PII_INTERNET,
    _SC_PII_OSI,
    _SC_POLL,
    _SC_SELECT,
    _SC_UIO_MAXIOV,
    _SC_IOV_MAX = _SC_UIO_MAXIOV,
    _SC_PII_INTERNET_STREAM,
    _SC_PII_INTERNET_DGRAM,
    _SC_PII_OSI_COTS,
    _SC_PII_OSI_CLTS,
    _SC_PII_OSI_M,
    _SC_T_IOV_MAX,
    _SC_THREADS,
    _SC_THREAD_SAFE_FUNCTIONS,
    _SC_GETGR_R_SIZE_MAX,
    _SC_GETPW_R_SIZE_MAX,
    _SC_LOGIN_NAME_MAX,
    _SC_TTY_NAME_MAX,
    _SC_THREAD_DESTRUCTOR_ITERATIONS,
    _SC_THREAD_KEYS_MAX,
    _SC_THREAD_STACK_MIN,
    _SC_THREAD_THREADS_MAX,
    _SC_THREAD_ATTR_STACKADDR,
    _SC_THREAD_ATTR_STACKSIZE,
    _SC_THREAD_PRIORITY_SCHEDULING,
    _SC_THREAD_PRIO_INHERIT,
    _SC_THREAD_PRIO_PROTECT,
    _SC_THREAD_PROCESS_SHARED,
    _SC_NPROCESSORS_CONF,
    _SC_NPROCESSORS_ONLN,
    _SC_PHYS_PAGES,
    _SC_AVPHYS_PAGES,
    _SC_ATEXIT_MAX,
    _SC_PASS_MAX,
    _SC_XOPEN_VERSION,
    _SC_XOPEN_XCU_VERSION,
    _SC_XOPEN_UNIX,
    _SC_XOPEN_CRYPT,
    _SC_XOPEN_ENH_I18N,
    _SC_XOPEN_SHM,
    _SC_2_CHAR_TERM,
    _SC_2_C_VERSION,
    _SC_2_UPE,
    _SC_XOPEN_XPG2,
    _SC_XOPEN_XPG3,
    _SC_XOPEN_XPG4,
    _SC_CHAR_BIT,
    _SC_CHAR_MAX,
    _SC_CHAR_MIN,
    _SC_INT_MAX,
    _SC_INT_MIN,
    _SC_LONG_BIT,
    _SC_WORD_BIT,
    _SC_MB_LEN_MAX,
    _SC_NZERO,
    _SC_SSIZE_MAX,
    _SC_SCHAR_MAX,
    _SC_SCHAR_MIN,
    _SC_SHRT_MAX,
    _SC_SHRT_MIN,
    _SC_UCHAR_MAX,
    _SC_UINT_MAX,
    _SC_ULONG_MAX,
    _SC_USHRT_MAX,
    _SC_NL_ARGMAX,
    _SC_NL_LANGMAX,
    _SC_NL_MSGMAX,
    _SC_NL_NMAX,
    _SC_NL_SETMAX,
    _SC_NL_TEXTMAX,
    _SC_XBS5_ILP32_OFF32,
    _SC_XBS5_ILP32_OFFBIG,
    _SC_XBS5_LP64_OFF64,
    _SC_XBS5_LPBIG_OFFBIG,
    _SC_XOPEN_LEGACY,
    _SC_XOPEN_REALTIME,
    _SC_XOPEN_REALTIME_THREADS,
    _SC_ADVISORY_INFO,
    _SC_BARRIERS,
    _SC_BASE,
    _SC_C_LANG_SUPPORT,
    _SC_C_LANG_SUPPORT_R,
    _SC_CLOCK_SELECTION,
    _SC_CPUTIME,
    _SC_THREAD_CPUTIME,
    _SC_DEVICE_IO,
    _SC_DEVICE_SPECIFIC,
    _SC_DEVICE_SPECIFIC_R,
    _SC_FD_MGMT,
    _SC_FIFO,
    _SC_PIPE,
    _SC_FILE_ATTRIBUTES,
    _SC_FILE_LOCKING,
    _SC_FILE_SYSTEM,
    _SC_MONOTONIC_CLOCK,
    _SC_MULTI_PROCESS,
    _SC_SINGLE_PROCESS,
    _SC_NETWORKING,
    _SC_READER_WRITER_LOCKS,
    _SC_SPIN_LOCKS,
    _SC_REGEXP,
    _SC_REGEX_VERSION,
    _SC_SHELL,
    _SC_SIGNALS,
    _SC_SPAWN,
    _SC_SPORADIC_SERVER,
    _SC_THREAD_SPORADIC_SERVER,
    _SC_SYSTEM_DATABASE,
    _SC_SYSTEM_DATABASE_R,
    _SC_TIMEOUTS,
    _SC_TYPED_MEMORY_OBJECTS,
    _SC_USER_GROUPS,
    _SC_USER_GROUPS_R,
    _SC_2_PBS,
    _SC_2_PBS_ACCOUNTING,
    _SC_2_PBS_LOCATE,
    _SC_2_PBS_MESSAGE,
    _SC_2_PBS_TRACK,
    _SC_SYMLOOP_MAX,
    _SC_STREAMS,
    _SC_2_PBS_CHECKPOINT,
    _SC_V6_ILP32_OFF32,
    _SC_V6_ILP32_OFFBIG,
    _SC_V6_LP64_OFF64,
    _SC_V6_LPBIG_OFFBIG,
    _SC_HOST_NAME_MAX,
    _SC_TRACE,
    _SC_TRACE_EVENT_FILTER,
    _SC_TRACE_INHERIT,
    _SC_TRACE_LOG,
    _SC_LEVEL1_ICACHE_SIZE,
    _SC_LEVEL1_ICACHE_ASSOC,
    _SC_LEVEL1_ICACHE_LINESIZE,
    _SC_LEVEL1_DCACHE_SIZE,
    _SC_LEVEL1_DCACHE_ASSOC,
    _SC_LEVEL1_DCACHE_LINESIZE,
    _SC_LEVEL2_CACHE_SIZE,
    _SC_LEVEL2_CACHE_ASSOC,
    _SC_LEVEL2_CACHE_LINESIZE,
    _SC_LEVEL3_CACHE_SIZE,
    _SC_LEVEL3_CACHE_ASSOC,
    _SC_LEVEL3_CACHE_LINESIZE,
    _SC_LEVEL4_CACHE_SIZE,
    _SC_LEVEL4_CACHE_ASSOC,
    _SC_LEVEL4_CACHE_LINESIZE,
    _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50,
    _SC_RAW_SOCKETS,
    _SC_V7_ILP32_OFF32,
    _SC_V7_ILP32_OFFBIG,
    _SC_V7_LP64_OFF64,
    _SC_V7_LPBIG_OFFBIG,
    _SC_SS_REPL_MAX,
    _SC_TRACE_EVENT_NAME_MAX,
    _SC_TRACE_NAME_MAX,
    _SC_TRACE_SYS_MAX,
    _SC_TRACE_USER_EVENT_MAX,
    _SC_XOPEN_STREAMS,
    _SC_THREAD_ROBUST_PRIO_INHERIT,
    _SC_THREAD_ROBUST_PRIO_PROTECT,
    _SC_MINSIGSTKSZ,
    _SC_SIGSTKSZ
  };
enum
  {
    _CS_PATH,
    _CS_V6_WIDTH_RESTRICTED_ENVS,
    _CS_GNU_LIBC_VERSION,
    _CS_GNU_LIBPTHREAD_VERSION,
    _CS_V5_WIDTH_RESTRICTED_ENVS,
    _CS_V7_WIDTH_RESTRICTED_ENVS,
    _CS_LFS_CFLAGS = 1000,
    _CS_LFS_LDFLAGS,
    _CS_LFS_LIBS,
    _CS_LFS_LINTFLAGS,
    _CS_LFS64_CFLAGS,
    _CS_LFS64_LDFLAGS,
    _CS_LFS64_LIBS,
    _CS_LFS64_LINTFLAGS,
    _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,
    _CS_XBS5_ILP32_OFF32_LDFLAGS,
    _CS_XBS5_ILP32_OFF32_LIBS,
    _CS_XBS5_ILP32_OFF32_LINTFLAGS,
    _CS_XBS5_ILP32_OFFBIG_CFLAGS,
    _CS_XBS5_ILP32_OFFBIG_LDFLAGS,
    _CS_XBS5_ILP32_OFFBIG_LIBS,
    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,
    _CS_XBS5_LP64_OFF64_CFLAGS,
    _CS_XBS5_LP64_OFF64_LDFLAGS,
    _CS_XBS5_LP64_OFF64_LIBS,
    _CS_XBS5_LP64_OFF64_LINTFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_CFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_LIBS,
    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_CFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_LIBS,
    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_LIBS,
    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,
    _CS_POSIX_V6_LP64_OFF64_CFLAGS,
    _CS_POSIX_V6_LP64_OFF64_LDFLAGS,
    _CS_POSIX_V6_LP64_OFF64_LIBS,
    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_CFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_LDFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_LIBS,
    _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_LIBS,
    _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS,
    _CS_POSIX_V7_LP64_OFF64_CFLAGS,
    _CS_POSIX_V7_LP64_OFF64_LDFLAGS,
    _CS_POSIX_V7_LP64_OFF64_LIBS,
    _CS_POSIX_V7_LP64_OFF64_LINTFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LIBS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS,
    _CS_V6_ENV,
    _CS_V7_ENV
  };
extern long int pathconf (const char *__path, int __name)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int fpathconf (int __fd, int __name) __attribute__ ((__nothrow__ , __leaf__));
extern long int sysconf (int __name) __attribute__ ((__nothrow__ , __leaf__));
extern size_t confstr (int __name, char *__buf, size_t __len) __attribute__ ((__nothrow__ , __leaf__))
    __attribute__ ((__access__ (__write_only__, 2, 3)));
extern __pid_t getpid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getppid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getpgrp (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t __getpgid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getpgid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));
extern int setpgid (__pid_t __pid, __pid_t __pgid) __attribute__ ((__nothrow__ , __leaf__));
extern int setpgrp (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t setsid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getsid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));
extern __uid_t getuid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __uid_t geteuid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __gid_t getgid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __gid_t getegid (void) __attribute__ ((__nothrow__ , __leaf__));
extern int getgroups (int __size, __gid_t __list[]) __attribute__ ((__nothrow__ , __leaf__))
    __attribute__ ((__access__ (__write_only__, 2, 1)));
extern int setuid (__uid_t __uid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int setreuid (__uid_t __ruid, __uid_t __euid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int seteuid (__uid_t __uid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int setgid (__gid_t __gid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int setregid (__gid_t __rgid, __gid_t __egid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int setegid (__gid_t __gid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern __pid_t fork (void) __attribute__ ((__nothrow__));
extern __pid_t vfork (void) __attribute__ ((__nothrow__ , __leaf__));
extern char *ttyname (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern int ttyname_r (int __fd, char *__buf, size_t __buflen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)))
     __attribute__ ((__access__ (__write_only__, 2, 3)));
extern int isatty (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern int ttyslot (void) __attribute__ ((__nothrow__ , __leaf__));
extern int link (const char *__from, const char *__to)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) ;
extern int linkat (int __fromfd, const char *__from, int __tofd,
     const char *__to, int __flags)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4))) ;
extern int symlink (const char *__from, const char *__to)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) ;
extern ssize_t readlink (const char *__restrict __path,
    char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)))
     __attribute__ ((__access__ (__write_only__, 2, 3)));
extern int symlinkat (const char *__from, int __tofd,
        const char *__to) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3))) ;
extern ssize_t readlinkat (int __fd, const char *__restrict __path,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)))
     __attribute__ ((__access__ (__write_only__, 3, 4)));
extern int unlink (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int unlinkat (int __fd, const char *__name, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int rmdir (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern __pid_t tcgetpgrp (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern int tcsetpgrp (int __fd, __pid_t __pgrp_id) __attribute__ ((__nothrow__ , __leaf__));
extern char *getlogin (void);
extern int getlogin_r (char *__name, size_t __name_len) __attribute__ ((__nonnull__ (1)))
    __attribute__ ((__access__ (__write_only__, 1, 2)));
extern int setlogin (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern char *optarg;
extern int optind;
extern int opterr;
extern int optopt;
extern int getopt (int ___argc, char *const *___argv, const char *__shortopts)
       __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern int gethostname (char *__name, size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
    __attribute__ ((__access__ (__write_only__, 1, 2)));
extern int sethostname (const char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__access__ (__read_only__, 1, 2)));
extern int sethostid (long int __id) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int getdomainname (char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
     __attribute__ ((__access__ (__write_only__, 1, 2)));
extern int setdomainname (const char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__access__ (__read_only__, 1, 2)));
extern int vhangup (void) __attribute__ ((__nothrow__ , __leaf__));
extern int revoke (const char *__file) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int profil (unsigned short int *__sample_buffer, size_t __size,
     size_t __offset, unsigned int __scale)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int acct (const char *__name) __attribute__ ((__nothrow__ , __leaf__));
extern char *getusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern void endusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern void setusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern int daemon (int __nochdir, int __noclose) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int chroot (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern char *getpass (const char *__prompt) __attribute__ ((__nonnull__ (1)));
extern int fsync (int __fd);
extern long int gethostid (void);
extern void sync (void) __attribute__ ((__nothrow__ , __leaf__));
extern int getpagesize (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int getdtablesize (void) __attribute__ ((__nothrow__ , __leaf__));
extern int truncate (const char *__file, __off_t __length)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int ftruncate (int __fd, __off_t __length) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int brk (void *__addr) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void *sbrk (intptr_t __delta) __attribute__ ((__nothrow__ , __leaf__));
extern long int syscall (long int __sysno, ...) __attribute__ ((__nothrow__ , __leaf__));
extern int fdatasync (int __fildes);
extern char *crypt (const char *__key, const char *__salt)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
int getentropy (void *__buffer, size_t __length)
    __attribute__ ((__access__ (__write_only__, 1, 2)));
struct tms
  {
    clock_t tms_utime;
    clock_t tms_stime;
    clock_t tms_cutime;
    clock_t tms_cstime;
  };
extern clock_t times (struct tms *__buffer) __attribute__ ((__nothrow__ , __leaf__));
extern void *mmap (void *__addr, size_t __len, int __prot,
     int __flags, int __fd, __off_t __offset) __attribute__ ((__nothrow__ , __leaf__));
extern int munmap (void *__addr, size_t __len) __attribute__ ((__nothrow__ , __leaf__));
extern int mprotect (void *__addr, size_t __len, int __prot) __attribute__ ((__nothrow__ , __leaf__));
extern int msync (void *__addr, size_t __len, int __flags);
extern int madvise (void *__addr, size_t __len, int __advice) __attribute__ ((__nothrow__ , __leaf__));
extern int posix_madvise (void *__addr, size_t __len, int __advice) __attribute__ ((__nothrow__ , __leaf__));
extern int mlock (const void *__addr, size_t __len) __attribute__ ((__nothrow__ , __leaf__));
extern int munlock (const void *__addr, size_t __len) __attribute__ ((__nothrow__ , __leaf__));
extern int mlockall (int __flags) __attribute__ ((__nothrow__ , __leaf__));
extern int munlockall (void) __attribute__ ((__nothrow__ , __leaf__));
extern int mincore (void *__start, size_t __len, unsigned char *__vec)
     __attribute__ ((__nothrow__ , __leaf__));
extern int shm_open (const char *__name, int __oflag, mode_t __mode);
extern int shm_unlink (const char *__name);
enum __rlimit_resource
{
  RLIMIT_CPU = 0,
  RLIMIT_FSIZE = 1,
  RLIMIT_DATA = 2,
  RLIMIT_STACK = 3,
  RLIMIT_CORE = 4,
  __RLIMIT_RSS = 5,
  RLIMIT_NOFILE = 7,
  __RLIMIT_OFILE = RLIMIT_NOFILE,
  RLIMIT_AS = 9,
  __RLIMIT_NPROC = 6,
  __RLIMIT_MEMLOCK = 8,
  __RLIMIT_LOCKS = 10,
  __RLIMIT_SIGPENDING = 11,
  __RLIMIT_MSGQUEUE = 12,
  __RLIMIT_NICE = 13,
  __RLIMIT_RTPRIO = 14,
  __RLIMIT_RTTIME = 15,
  __RLIMIT_NLIMITS = 16,
  __RLIM_NLIMITS = __RLIMIT_NLIMITS
};
typedef __rlim_t rlim_t;
struct rlimit
  {
    rlim_t rlim_cur;
    rlim_t rlim_max;
  };
enum __rusage_who
{
  RUSAGE_SELF = 0,
  RUSAGE_CHILDREN = -1
};
struct rusage
  {
    struct timeval ru_utime;
    struct timeval ru_stime;
    __extension__ union
      {
 long int ru_maxrss;
 __syscall_slong_t __ru_maxrss_word;
      };
    __extension__ union
      {
 long int ru_ixrss;
 __syscall_slong_t __ru_ixrss_word;
      };
    __extension__ union
      {
 long int ru_idrss;
 __syscall_slong_t __ru_idrss_word;
      };
    __extension__ union
      {
 long int ru_isrss;
  __syscall_slong_t __ru_isrss_word;
      };
    __extension__ union
      {
 long int ru_minflt;
 __syscall_slong_t __ru_minflt_word;
      };
    __extension__ union
      {
 long int ru_majflt;
 __syscall_slong_t __ru_majflt_word;
      };
    __extension__ union
      {
 long int ru_nswap;
 __syscall_slong_t __ru_nswap_word;
      };
    __extension__ union
      {
 long int ru_inblock;
 __syscall_slong_t __ru_inblock_word;
      };
    __extension__ union
      {
 long int ru_oublock;
 __syscall_slong_t __ru_oublock_word;
      };
    __extension__ union
      {
 long int ru_msgsnd;
 __syscall_slong_t __ru_msgsnd_word;
      };
    __extension__ union
      {
 long int ru_msgrcv;
 __syscall_slong_t __ru_msgrcv_word;
      };
    __extension__ union
      {
 long int ru_nsignals;
 __syscall_slong_t __ru_nsignals_word;
      };
    __extension__ union
      {
 long int ru_nvcsw;
 __syscall_slong_t __ru_nvcsw_word;
      };
    __extension__ union
      {
 long int ru_nivcsw;
 __syscall_slong_t __ru_nivcsw_word;
      };
  };
enum __priority_which
{
  PRIO_PROCESS = 0,
  PRIO_PGRP = 1,
  PRIO_USER = 2
};
typedef int __rlimit_resource_t;
typedef int __rusage_who_t;
typedef int __priority_which_t;
extern int getrlimit (__rlimit_resource_t __resource,
        struct rlimit *__rlimits) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int setrlimit (__rlimit_resource_t __resource,
        const struct rlimit *__rlimits) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int getrusage (__rusage_who_t __who, struct rusage *__usage) __attribute__ ((__nothrow__ , __leaf__));
extern int getpriority (__priority_which_t __which, id_t __who) __attribute__ ((__nothrow__ , __leaf__));
extern int setpriority (__priority_which_t __which, id_t __who, int __prio)
     __attribute__ ((__nothrow__ , __leaf__));
struct sched_param
{
  int sched_priority;
};
typedef unsigned long int __cpu_mask;
typedef struct
{
  __cpu_mask __bits[1024 / (8 * sizeof (__cpu_mask))];
} cpu_set_t;
extern int __sched_cpucount (size_t __setsize, const cpu_set_t *__setp)
     __attribute__ ((__nothrow__ , __leaf__));
extern cpu_set_t *__sched_cpualloc (size_t __count) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void __sched_cpufree (cpu_set_t *__set) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_setparam (__pid_t __pid, const struct sched_param *__param)
     __attribute__ ((__nothrow__ , __leaf__));
extern int sched_getparam (__pid_t __pid, struct sched_param *__param) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_setscheduler (__pid_t __pid, int __policy,
          const struct sched_param *__param) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_getscheduler (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_yield (void) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_get_priority_max (int __algorithm) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_get_priority_min (int __algorithm) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_rr_get_interval (__pid_t __pid, struct timespec *__t) __attribute__ ((__nothrow__ , __leaf__));
__extension__ typedef unsigned long long __jmp_buf [22];
struct __jmp_buf_tag
  {
    __jmp_buf __jmpbuf;
    int __mask_was_saved;
    __sigset_t __saved_mask;
  };
enum
{
  PTHREAD_CREATE_JOINABLE,
  PTHREAD_CREATE_DETACHED
};
enum
{
  PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_ADAPTIVE_NP
  ,
  PTHREAD_MUTEX_NORMAL = PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE = PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK = PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_DEFAULT = PTHREAD_MUTEX_NORMAL
};
enum
{
  PTHREAD_MUTEX_STALLED,
  PTHREAD_MUTEX_STALLED_NP = PTHREAD_MUTEX_STALLED,
  PTHREAD_MUTEX_ROBUST,
  PTHREAD_MUTEX_ROBUST_NP = PTHREAD_MUTEX_ROBUST
};
enum
{
  PTHREAD_PRIO_NONE,
  PTHREAD_PRIO_INHERIT,
  PTHREAD_PRIO_PROTECT
};
enum
{
  PTHREAD_RWLOCK_PREFER_READER_NP,
  PTHREAD_RWLOCK_PREFER_WRITER_NP,
  PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP,
  PTHREAD_RWLOCK_DEFAULT_NP = PTHREAD_RWLOCK_PREFER_READER_NP
};
enum
{
  PTHREAD_INHERIT_SCHED,
  PTHREAD_EXPLICIT_SCHED
};
enum
{
  PTHREAD_SCOPE_SYSTEM,
  PTHREAD_SCOPE_PROCESS
};
enum
{
  PTHREAD_PROCESS_PRIVATE,
  PTHREAD_PROCESS_SHARED
};
struct _pthread_cleanup_buffer
{
  void (*__routine) (void *);
  void *__arg;
  int __canceltype;
  struct _pthread_cleanup_buffer *__prev;
};
enum
{
  PTHREAD_CANCEL_ENABLE,
  PTHREAD_CANCEL_DISABLE
};
enum
{
  PTHREAD_CANCEL_DEFERRED,
  PTHREAD_CANCEL_ASYNCHRONOUS
};
extern int pthread_create (pthread_t *__restrict __newthread,
      const pthread_attr_t *__restrict __attr,
      void *(*__start_routine) (void *),
      void *__restrict __arg) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 3)));
extern void pthread_exit (void *__retval) __attribute__ ((__noreturn__));
extern int pthread_join (pthread_t __th, void **__thread_return);
extern int pthread_detach (pthread_t __th) __attribute__ ((__nothrow__ , __leaf__));
extern pthread_t pthread_self (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int pthread_equal (pthread_t __thread1, pthread_t __thread2)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int pthread_attr_init (pthread_attr_t *__attr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_destroy (pthread_attr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getdetachstate (const pthread_attr_t *__attr,
     int *__detachstate)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setdetachstate (pthread_attr_t *__attr,
     int __detachstate)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getguardsize (const pthread_attr_t *__attr,
          size_t *__guardsize)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setguardsize (pthread_attr_t *__attr,
          size_t __guardsize)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getschedparam (const pthread_attr_t *__restrict __attr,
           struct sched_param *__restrict __param)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setschedparam (pthread_attr_t *__restrict __attr,
           const struct sched_param *__restrict
           __param) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_getschedpolicy (const pthread_attr_t *__restrict
     __attr, int *__restrict __policy)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setschedpolicy (pthread_attr_t *__attr, int __policy)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getinheritsched (const pthread_attr_t *__restrict
      __attr, int *__restrict __inherit)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setinheritsched (pthread_attr_t *__attr,
      int __inherit)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getscope (const pthread_attr_t *__restrict __attr,
      int *__restrict __scope)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setscope (pthread_attr_t *__attr, int __scope)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getstackaddr (const pthread_attr_t *__restrict
          __attr, void **__restrict __stackaddr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__deprecated__));
extern int pthread_attr_setstackaddr (pthread_attr_t *__attr,
          void *__stackaddr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__));
extern int pthread_attr_getstacksize (const pthread_attr_t *__restrict
          __attr, size_t *__restrict __stacksize)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setstacksize (pthread_attr_t *__attr,
          size_t __stacksize)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getstack (const pthread_attr_t *__restrict __attr,
      void **__restrict __stackaddr,
      size_t *__restrict __stacksize)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3)));
extern int pthread_attr_setstack (pthread_attr_t *__attr, void *__stackaddr,
      size_t __stacksize) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_setschedparam (pthread_t __target_thread, int __policy,
      const struct sched_param *__param)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int pthread_getschedparam (pthread_t __target_thread,
      int *__restrict __policy,
      struct sched_param *__restrict __param)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern int pthread_setschedprio (pthread_t __target_thread, int __prio)
     __attribute__ ((__nothrow__ , __leaf__));
extern int pthread_once (pthread_once_t *__once_control,
    void (*__init_routine) (void)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_setcancelstate (int __state, int *__oldstate);
extern int pthread_setcanceltype (int __type, int *__oldtype);
extern int pthread_cancel (pthread_t __th);
extern void pthread_testcancel (void);
struct __cancel_jmp_buf_tag
{
  __jmp_buf __cancel_jmp_buf;
  int __mask_was_saved;
};
typedef struct
{
  struct __cancel_jmp_buf_tag __cancel_jmp_buf[1];
  void *__pad[4];
} __pthread_unwind_buf_t __attribute__ ((__aligned__));
struct __pthread_cleanup_frame
{
  void (*__cancel_routine) (void *);
  void *__cancel_arg;
  int __do_it;
  int __cancel_type;
};
extern void __pthread_register_cancel (__pthread_unwind_buf_t *__buf)
     ;
extern void __pthread_unregister_cancel (__pthread_unwind_buf_t *__buf)
  ;
extern void __pthread_unwind_next (__pthread_unwind_buf_t *__buf)
     __attribute__ ((__noreturn__))
     __attribute__ ((__weak__))
     ;
extern int __sigsetjmp_cancel (struct __cancel_jmp_buf_tag __env[1], int __savemask) __asm__ ("" "__sigsetjmp") __attribute__ ((__nothrow__)) __attribute__ ((__returns_twice__));
extern int pthread_mutex_init (pthread_mutex_t *__mutex,
          const pthread_mutexattr_t *__mutexattr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_destroy (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_trylock (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_lock (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_timedlock (pthread_mutex_t *__restrict __mutex,
        const struct timespec *__restrict
        __abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutex_unlock (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_getprioceiling (const pthread_mutex_t *
      __restrict __mutex,
      int *__restrict __prioceiling)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutex_setprioceiling (pthread_mutex_t *__restrict __mutex,
      int __prioceiling,
      int *__restrict __old_ceiling)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern int pthread_mutex_consistent (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_init (pthread_mutexattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_destroy (pthread_mutexattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_getpshared (const pthread_mutexattr_t *
      __restrict __attr,
      int *__restrict __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutexattr_setpshared (pthread_mutexattr_t *__attr,
      int __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_gettype (const pthread_mutexattr_t *__restrict
          __attr, int *__restrict __kind)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutexattr_settype (pthread_mutexattr_t *__attr, int __kind)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_getprotocol (const pthread_mutexattr_t *
       __restrict __attr,
       int *__restrict __protocol)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutexattr_setprotocol (pthread_mutexattr_t *__attr,
       int __protocol)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_getprioceiling (const pthread_mutexattr_t *
          __restrict __attr,
          int *__restrict __prioceiling)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutexattr_setprioceiling (pthread_mutexattr_t *__attr,
          int __prioceiling)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_getrobust (const pthread_mutexattr_t *__attr,
     int *__robustness)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutexattr_setrobust (pthread_mutexattr_t *__attr,
     int __robustness)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_init (pthread_rwlock_t *__restrict __rwlock,
    const pthread_rwlockattr_t *__restrict
    __attr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_destroy (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_rdlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_tryrdlock (pthread_rwlock_t *__rwlock)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_timedrdlock (pthread_rwlock_t *__restrict __rwlock,
           const struct timespec *__restrict
           __abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_rwlock_wrlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_trywrlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_timedwrlock (pthread_rwlock_t *__restrict __rwlock,
           const struct timespec *__restrict
           __abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_rwlock_unlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlockattr_init (pthread_rwlockattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlockattr_destroy (pthread_rwlockattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlockattr_getpshared (const pthread_rwlockattr_t *
       __restrict __attr,
       int *__restrict __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_rwlockattr_setpshared (pthread_rwlockattr_t *__attr,
       int __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlockattr_getkind_np (const pthread_rwlockattr_t *
       __restrict __attr,
       int *__restrict __pref)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_rwlockattr_setkind_np (pthread_rwlockattr_t *__attr,
       int __pref) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_init (pthread_cond_t *__restrict __cond,
         const pthread_condattr_t *__restrict __cond_attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_destroy (pthread_cond_t *__cond)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_signal (pthread_cond_t *__cond)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_broadcast (pthread_cond_t *__cond)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_wait (pthread_cond_t *__restrict __cond,
         pthread_mutex_t *__restrict __mutex)
     __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_cond_timedwait (pthread_cond_t *__restrict __cond,
       pthread_mutex_t *__restrict __mutex,
       const struct timespec *__restrict __abstime)
     __attribute__ ((__nonnull__ (1, 2, 3)));
extern int pthread_condattr_init (pthread_condattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_condattr_destroy (pthread_condattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_condattr_getpshared (const pthread_condattr_t *
     __restrict __attr,
     int *__restrict __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_condattr_setpshared (pthread_condattr_t *__attr,
     int __pshared) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_condattr_getclock (const pthread_condattr_t *
          __restrict __attr,
          __clockid_t *__restrict __clock_id)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_condattr_setclock (pthread_condattr_t *__attr,
          __clockid_t __clock_id)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_init (pthread_spinlock_t *__lock, int __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_destroy (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_lock (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_trylock (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_unlock (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrier_init (pthread_barrier_t *__restrict __barrier,
     const pthread_barrierattr_t *__restrict
     __attr, unsigned int __count)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrier_destroy (pthread_barrier_t *__barrier)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrier_wait (pthread_barrier_t *__barrier)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrierattr_init (pthread_barrierattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrierattr_destroy (pthread_barrierattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrierattr_getpshared (const pthread_barrierattr_t *
        __restrict __attr,
        int *__restrict __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_barrierattr_setpshared (pthread_barrierattr_t *__attr,
        int __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_key_create (pthread_key_t *__key,
          void (*__destr_function) (void *))
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_key_delete (pthread_key_t __key) __attribute__ ((__nothrow__ , __leaf__));
extern void *pthread_getspecific (pthread_key_t __key) __attribute__ ((__nothrow__ , __leaf__));
extern int pthread_setspecific (pthread_key_t __key,
    const void *__pointer)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__access__ (__none__, 2)));
extern int pthread_getcpuclockid (pthread_t __thread_id,
      __clockid_t *__clock_id)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int pthread_atfork (void (*__prepare) (void),
      void (*__parent) (void),
      void (*__child) (void)) __attribute__ ((__nothrow__ , __leaf__));
typedef __sig_atomic_t sig_atomic_t;
union sigval
{
  int sival_int;
  void *sival_ptr;
};
typedef union sigval __sigval_t;
typedef struct
  {
    int si_signo;
    int si_errno;
    int si_code;
    int __pad0;
    union
      {
 int _pad[((128 / sizeof (int)) - 4)];
 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
   } _kill;
 struct
   {
     int si_tid;
     int si_overrun;
     __sigval_t si_sigval;
   } _timer;
 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
     __sigval_t si_sigval;
   } _rt;
 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
     int si_status;
     __clock_t si_utime;
     __clock_t si_stime;
   } _sigchld;
 struct
   {
     void *si_addr;
    
     short int si_addr_lsb;
     union
       {
  struct
    {
      void *_lower;
      void *_upper;
    } _addr_bnd;
  __uint32_t _pkey;
       } _bounds;
   } _sigfault;
 struct
   {
     long int si_band;
     int si_fd;
   } _sigpoll;
 struct
   {
     void *_call_addr;
     int _syscall;
     unsigned int _arch;
   } _sigsys;
      } _sifields;
  } siginfo_t ;
enum
{
  SI_ASYNCNL = -60,
  SI_DETHREAD = -7,
  SI_TKILL,
  SI_SIGIO,
  SI_ASYNCIO,
  SI_MESGQ,
  SI_TIMER,
  SI_QUEUE,
  SI_USER,
  SI_KERNEL = 0x80
};
enum
{
  ILL_ILLOPC = 1,
  ILL_ILLOPN,
  ILL_ILLADR,
  ILL_ILLTRP,
  ILL_PRVOPC,
  ILL_PRVREG,
  ILL_COPROC,
  ILL_BADSTK,
  ILL_BADIADDR
};
enum
{
  FPE_INTDIV = 1,
  FPE_INTOVF,
  FPE_FLTDIV,
  FPE_FLTOVF,
  FPE_FLTUND,
  FPE_FLTRES,
  FPE_FLTINV,
  FPE_FLTSUB,
  FPE_FLTUNK = 14,
  FPE_CONDTRAP
};
enum
{
  SEGV_MAPERR = 1,
  SEGV_ACCERR,
  SEGV_BNDERR,
  SEGV_PKUERR,
  SEGV_ACCADI,
  SEGV_ADIDERR,
  SEGV_ADIPERR,
  SEGV_MTEAERR,
  SEGV_MTESERR
};
enum
{
  BUS_ADRALN = 1,
  BUS_ADRERR,
  BUS_OBJERR,
  BUS_MCEERR_AR,
  BUS_MCEERR_AO
};
enum
{
  CLD_EXITED = 1,
  CLD_KILLED,
  CLD_DUMPED,
  CLD_TRAPPED,
  CLD_STOPPED,
  CLD_CONTINUED
};
enum
{
  POLL_IN = 1,
  POLL_OUT,
  POLL_MSG,
  POLL_ERR,
  POLL_PRI,
  POLL_HUP
};
typedef __sigval_t sigval_t;
typedef struct sigevent
  {
    __sigval_t sigev_value;
    int sigev_signo;
    int sigev_notify;
    union
      {
 int _pad[((64 / sizeof (int)) - 4)];
 __pid_t _tid;
 struct
   {
     void (*_function) (__sigval_t);
     pthread_attr_t *_attribute;
   } _sigev_thread;
      } _sigev_un;
  } sigevent_t;
enum
{
  SIGEV_SIGNAL = 0,
  SIGEV_NONE,
  SIGEV_THREAD,
  SIGEV_THREAD_ID = 4
};
typedef void (*__sighandler_t) (int);
extern __sighandler_t __sysv_signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ , __leaf__));
extern __sighandler_t signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ , __leaf__));
extern int kill (__pid_t __pid, int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern int killpg (__pid_t __pgrp, int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern int raise (int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern __sighandler_t ssignal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ , __leaf__));
extern int gsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern void psignal (int __sig, const char *__s);
extern void psiginfo (const siginfo_t *__pinfo, const char *__s);
extern int sigblock (int __mask) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));
extern int sigsetmask (int __mask) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));
extern int siggetmask (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));
typedef __sighandler_t sig_t;
extern int sigemptyset (sigset_t *__set) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigfillset (sigset_t *__set) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigaddset (sigset_t *__set, int __signo) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigdelset (sigset_t *__set, int __signo) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigismember (const sigset_t *__set, int __signo)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
struct sigaction
  {
    union
      {
 __sighandler_t sa_handler;
 void (*sa_sigaction) (int, siginfo_t *, void *);
      }
    __sigaction_handler;
    __sigset_t sa_mask;
    int sa_flags;
    void (*sa_restorer) (void);
  };
extern int sigprocmask (int __how, const sigset_t *__restrict __set,
   sigset_t *__restrict __oset) __attribute__ ((__nothrow__ , __leaf__));
extern int sigsuspend (const sigset_t *__set) __attribute__ ((__nonnull__ (1)));
extern int sigaction (int __sig, const struct sigaction *__restrict __act,
        struct sigaction *__restrict __oact) __attribute__ ((__nothrow__ , __leaf__));
extern int sigpending (sigset_t *__set) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigwait (const sigset_t *__restrict __set, int *__restrict __sig)
     __attribute__ ((__nonnull__ (1, 2)));
extern int sigwaitinfo (const sigset_t *__restrict __set,
   siginfo_t *__restrict __info) __attribute__ ((__nonnull__ (1)));
extern int sigtimedwait (const sigset_t *__restrict __set,
    siginfo_t *__restrict __info,
    const struct timespec *__restrict __timeout)
     __attribute__ ((__nonnull__ (1)));
extern int sigqueue (__pid_t __pid, int __sig, const union sigval __val)
     __attribute__ ((__nothrow__ , __leaf__));
typedef __signed__ char __s8;
typedef unsigned char __u8;
typedef __signed__ short __s16;
typedef unsigned short __u16;
typedef __signed__ int __s32;
typedef unsigned int __u32;
__extension__ typedef __signed__ long long __s64;
__extension__ typedef unsigned long long __u64;
typedef struct {
 unsigned long fds_bits[1024 / (8 * sizeof(long))];
} __kernel_fd_set;
typedef void (*__kernel_sighandler_t)(int);
typedef int __kernel_key_t;
typedef int __kernel_mqd_t;
typedef unsigned short __kernel_old_uid_t;
typedef unsigned short __kernel_old_gid_t;
typedef long __kernel_long_t;
typedef unsigned long __kernel_ulong_t;
typedef __kernel_ulong_t __kernel_ino_t;
typedef unsigned int __kernel_mode_t;
typedef int __kernel_pid_t;
typedef int __kernel_ipc_pid_t;
typedef unsigned int __kernel_uid_t;
typedef unsigned int __kernel_gid_t;
typedef __kernel_long_t __kernel_suseconds_t;
typedef int __kernel_daddr_t;
typedef unsigned int __kernel_uid32_t;
typedef unsigned int __kernel_gid32_t;
typedef unsigned int __kernel_old_dev_t;
typedef __kernel_ulong_t __kernel_size_t;
typedef __kernel_long_t __kernel_ssize_t;
typedef __kernel_long_t __kernel_ptrdiff_t;
typedef struct {
 int val[2];
} __kernel_fsid_t;
typedef __kernel_long_t __kernel_off_t;
typedef long long __kernel_loff_t;
typedef __kernel_long_t __kernel_old_time_t;
typedef __kernel_long_t __kernel_time_t;
typedef long long __kernel_time64_t;
typedef __kernel_long_t __kernel_clock_t;
typedef int __kernel_timer_t;
typedef int __kernel_clockid_t;
typedef char * __kernel_caddr_t;
typedef unsigned short __kernel_uid16_t;
typedef unsigned short __kernel_gid16_t;
typedef __u16 __le16;
typedef __u16 __be16;
typedef __u32 __le32;
typedef __u32 __be32;
typedef __u64 __le64;
typedef __u64 __be64;
typedef __u16 __sum16;
typedef __u32 __wsum;
typedef unsigned __poll_t;
struct sigcontext {
 __u64 fault_address;
 __u64 regs[31];
 __u64 sp;
 __u64 pc;
 __u64 pstate;
 __u8 __reserved[4096] __attribute__((__aligned__(16)));
};
struct _aarch64_ctx {
 __u32 magic;
 __u32 size;
};
struct fpsimd_context {
 struct _aarch64_ctx head;
 __u32 fpsr;
 __u32 fpcr;
 __uint128_t vregs[32];
};
struct esr_context {
 struct _aarch64_ctx head;
 __u64 esr;
};
struct extra_context {
 struct _aarch64_ctx head;
 __u64 datap;
 __u32 size;
 __u32 __reserved[3];
};
struct sve_context {
 struct _aarch64_ctx head;
 __u16 vl;
 __u16 flags;
 __u16 __reserved[2];
};
struct za_context {
 struct _aarch64_ctx head;
 __u16 vl;
 __u16 __reserved[3];
};
extern int sigreturn (struct sigcontext *__scp) __attribute__ ((__nothrow__ , __leaf__));
typedef struct
  {
    void *ss_sp;
    int ss_flags;
    size_t ss_size;
  } stack_t;
struct timezone
  {
    int tz_minuteswest;
    int tz_dsttime;
  };
extern int gettimeofday (struct timeval *__restrict __tv,
    void *__restrict __tz) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int settimeofday (const struct timeval *__tv,
    const struct timezone *__tz)
     __attribute__ ((__nothrow__ , __leaf__));
extern int adjtime (const struct timeval *__delta,
      struct timeval *__olddelta) __attribute__ ((__nothrow__ , __leaf__));
enum __itimer_which
  {
    ITIMER_REAL = 0,
    ITIMER_VIRTUAL = 1,
    ITIMER_PROF = 2
  };
struct itimerval
  {
    struct timeval it_interval;
    struct timeval it_value;
  };
typedef int __itimer_which_t;
extern int getitimer (__itimer_which_t __which,
        struct itimerval *__value) __attribute__ ((__nothrow__ , __leaf__));
extern int setitimer (__itimer_which_t __which,
        const struct itimerval *__restrict __new,
        struct itimerval *__restrict __old) __attribute__ ((__nothrow__ , __leaf__));
extern int utimes (const char *__file, const struct timeval __tvp[2])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int lutimes (const char *__file, const struct timeval __tvp[2])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int futimes (int __fd, const struct timeval __tvp[2]) __attribute__ ((__nothrow__ , __leaf__));
struct user_regs_struct
{
  unsigned long long regs[31];
  unsigned long long sp;
  unsigned long long pc;
  unsigned long long pstate;
};
struct user_fpsimd_struct
{
  __uint128_t vregs[32];
  unsigned int fpsr;
  unsigned int fpcr;
};
typedef __uint64_t elf_greg_t;
typedef elf_greg_t elf_gregset_t[(sizeof (struct user_regs_struct) / sizeof (elf_greg_t))];
typedef struct user_fpsimd_struct elf_fpregset_t;
typedef unsigned int __pr_uid_t;
typedef unsigned int __pr_gid_t;
struct elf_siginfo
  {
    int si_signo;
    int si_code;
    int si_errno;
  };
struct elf_prstatus
  {
    struct elf_siginfo pr_info;
    short int pr_cursig;
    unsigned long int pr_sigpend;
    unsigned long int pr_sighold;
    __pid_t pr_pid;
    __pid_t pr_ppid;
    __pid_t pr_pgrp;
    __pid_t pr_sid;
    struct timeval pr_utime;
    struct timeval pr_stime;
    struct timeval pr_cutime;
    struct timeval pr_cstime;
    elf_gregset_t pr_reg;
    int pr_fpvalid;
  };
struct elf_prpsinfo
  {
    char pr_state;
    char pr_sname;
    char pr_zomb;
    char pr_nice;
    unsigned long int pr_flag;
    __pr_uid_t pr_uid;
    __pr_gid_t pr_gid;
    int pr_pid, pr_ppid, pr_pgrp, pr_sid;
    char pr_fname[16];
    char pr_psargs[(80)];
  };
typedef void *psaddr_t;
typedef elf_gregset_t __prgregset_t;
typedef elf_fpregset_t __prfpregset_t;
typedef __prgregset_t prgregset_t;
typedef __prfpregset_t prfpregset_t;
typedef __pid_t lwpid_t;
typedef struct elf_prstatus prstatus_t;
typedef struct elf_prpsinfo prpsinfo_t;
typedef elf_greg_t greg_t;
typedef elf_gregset_t gregset_t;
typedef elf_fpregset_t fpregset_t;
typedef struct
  {
    unsigned long long int fault_address;
    unsigned long long int regs[31];
    unsigned long long int sp;
    unsigned long long int pc;
    unsigned long long int pstate;
    unsigned char __reserved[4096] __attribute__ ((__aligned__ (16)));
  } mcontext_t;
typedef struct ucontext_t
  {
    unsigned long uc_flags;
    struct ucontext_t *uc_link;
    stack_t uc_stack;
    sigset_t uc_sigmask;
    mcontext_t uc_mcontext;
  } ucontext_t;
extern int siginterrupt (int __sig, int __interrupt) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__deprecated__ ("Use sigaction with SA_RESTART instead")));
enum
{
  SS_ONSTACK = 1,
  SS_DISABLE
};
extern int sigaltstack (const stack_t *__restrict __ss,
   stack_t *__restrict __oss) __attribute__ ((__nothrow__ , __leaf__));
struct sigstack
  {
    void *ss_sp;
    int ss_onstack;
  };
extern int sigstack (struct sigstack *__ss, struct sigstack *__oss)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));
extern int pthread_sigmask (int __how,
       const __sigset_t *__restrict __newmask,
       __sigset_t *__restrict __oldmask)__attribute__ ((__nothrow__ , __leaf__));
extern int pthread_kill (pthread_t __threadid, int __signo) __attribute__ ((__nothrow__ , __leaf__));
extern int __libc_current_sigrtmin (void) __attribute__ ((__nothrow__ , __leaf__));
extern int __libc_current_sigrtmax (void) __attribute__ ((__nothrow__ , __leaf__));
typedef unsigned long XID;
typedef unsigned long Mask;
typedef unsigned long Atom;
typedef unsigned long VisualID;
typedef unsigned long Time;
typedef XID Window;
typedef XID Drawable;
typedef XID Font;
typedef XID Pixmap;
typedef XID Cursor;
typedef XID Colormap;
typedef XID GContext;
typedef XID KeySym;
typedef unsigned char KeyCode;
typedef long int ptrdiff_t;
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;
extern int
_Xmblen(
    char *str,
    int len
    );
typedef char *XPointer;
typedef struct _XExtData {
 int number;
 struct _XExtData *next;
 int (*free_private)(
 struct _XExtData *extension
 );
 XPointer private_data;
} XExtData;
typedef struct {
 int extension;
 int major_opcode;
 int first_event;
 int first_error;
} XExtCodes;
typedef struct {
    int depth;
    int bits_per_pixel;
    int scanline_pad;
} XPixmapFormatValues;
typedef struct {
 int function;
 unsigned long plane_mask;
 unsigned long foreground;
 unsigned long background;
 int line_width;
 int line_style;
 int cap_style;
 int join_style;
 int fill_style;
 int fill_rule;
 int arc_mode;
 Pixmap tile;
 Pixmap stipple;
 int ts_x_origin;
 int ts_y_origin;
        Font font;
 int subwindow_mode;
 int graphics_exposures;
 int clip_x_origin;
 int clip_y_origin;
 Pixmap clip_mask;
 int dash_offset;
 char dashes;
} XGCValues;
typedef struct _XGC
*GC;
typedef struct {
 XExtData *ext_data;
 VisualID visualid;
 int class;
 unsigned long red_mask, green_mask, blue_mask;
 int bits_per_rgb;
 int map_entries;
} Visual;
typedef struct {
 int depth;
 int nvisuals;
 Visual *visuals;
} Depth;
struct _XDisplay;
typedef struct {
 XExtData *ext_data;
 struct _XDisplay *display;
 Window root;
 int width, height;
 int mwidth, mheight;
 int ndepths;
 Depth *depths;
 int root_depth;
 Visual *root_visual;
 GC default_gc;
 Colormap cmap;
 unsigned long white_pixel;
 unsigned long black_pixel;
 int max_maps, min_maps;
 int backing_store;
 int save_unders;
 long root_input_mask;
} Screen;
typedef struct {
 XExtData *ext_data;
 int depth;
 int bits_per_pixel;
 int scanline_pad;
} ScreenFormat;
typedef struct {
    Pixmap background_pixmap;
    unsigned long background_pixel;
    Pixmap border_pixmap;
    unsigned long border_pixel;
    int bit_gravity;
    int win_gravity;
    int backing_store;
    unsigned long backing_planes;
    unsigned long backing_pixel;
    int save_under;
    long event_mask;
    long do_not_propagate_mask;
    int override_redirect;
    Colormap colormap;
    Cursor cursor;
} XSetWindowAttributes;
typedef struct {
    int x, y;
    int width, height;
    int border_width;
    int depth;
    Visual *visual;
    Window root;
    int class;
    int bit_gravity;
    int win_gravity;
    int backing_store;
    unsigned long backing_planes;
    unsigned long backing_pixel;
    int save_under;
    Colormap colormap;
    int map_installed;
    int map_state;
    long all_event_masks;
    long your_event_mask;
    long do_not_propagate_mask;
    int override_redirect;
    Screen *screen;
} XWindowAttributes;
typedef struct {
 int family;
 int length;
 char *address;
} XHostAddress;
typedef struct {
 int typelength;
 int valuelength;
 char *type;
 char *value;
} XServerInterpretedAddress;
typedef struct _XImage {
    int width, height;
    int xoffset;
    int format;
    char *data;
    int byte_order;
    int bitmap_unit;
    int bitmap_bit_order;
    int bitmap_pad;
    int depth;
    int bytes_per_line;
    int bits_per_pixel;
    unsigned long red_mask;
    unsigned long green_mask;
    unsigned long blue_mask;
    XPointer obdata;
    struct funcs {
 struct _XImage *(*create_image)(
  struct _XDisplay* ,
  Visual* ,
  unsigned int ,
  int ,
  int ,
  char* ,
  unsigned int ,
  unsigned int ,
  int ,
  int );
 int (*destroy_image) (struct _XImage *);
 unsigned long (*get_pixel) (struct _XImage *, int, int);
 int (*put_pixel) (struct _XImage *, int, int, unsigned long);
 struct _XImage *(*sub_image)(struct _XImage *, int, int, unsigned int, unsigned int);
 int (*add_pixel) (struct _XImage *, long);
 } f;
} XImage;
typedef struct {
    int x, y;
    int width, height;
    int border_width;
    Window sibling;
    int stack_mode;
} XWindowChanges;
typedef struct {
 unsigned long pixel;
 unsigned short red, green, blue;
 char flags;
 char pad;
} XColor;
typedef struct {
    short x1, y1, x2, y2;
} XSegment;
typedef struct {
    short x, y;
} XPoint;
typedef struct {
    short x, y;
    unsigned short width, height;
} XRectangle;
typedef struct {
    short x, y;
    unsigned short width, height;
    short angle1, angle2;
} XArc;
typedef struct {
        int key_click_percent;
        int bell_percent;
        int bell_pitch;
        int bell_duration;
        int led;
        int led_mode;
        int key;
        int auto_repeat_mode;
} XKeyboardControl;
typedef struct {
        int key_click_percent;
 int bell_percent;
 unsigned int bell_pitch, bell_duration;
 unsigned long led_mask;
 int global_auto_repeat;
 char auto_repeats[32];
} XKeyboardState;
typedef struct {
        Time time;
 short x, y;
} XTimeCoord;
typedef struct {
  int max_keypermod;
  KeyCode *modifiermap;
} XModifierKeymap;
typedef struct _XDisplay Display;
struct _XPrivate;
struct _XrmHashBucketRec;
typedef struct
{
 XExtData *ext_data;
 struct _XPrivate *private1;
 int fd;
 int private2;
 int proto_major_version;
 int proto_minor_version;
 char *vendor;
        XID private3;
 XID private4;
 XID private5;
 int private6;
 XID (*resource_alloc)(
  struct _XDisplay*
 );
 int byte_order;
 int bitmap_unit;
 int bitmap_pad;
 int bitmap_bit_order;
 int nformats;
 ScreenFormat *pixmap_format;
 int private8;
 int release;
 struct _XPrivate *private9, *private10;
 int qlen;
 unsigned long last_request_read;
 unsigned long request;
 XPointer private11;
 XPointer private12;
 XPointer private13;
 XPointer private14;
 unsigned max_request_size;
 struct _XrmHashBucketRec *db;
 int (*private15)(
  struct _XDisplay*
  );
 char *display_name;
 int default_screen;
 int nscreens;
 Screen *screens;
 unsigned long motion_buffer;
 unsigned long private16;
 int min_keycode;
 int max_keycode;
 XPointer private17;
 XPointer private18;
 int private19;
 char *xdefaults;
}
*_XPrivDisplay;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 Window root;
 Window subwindow;
 Time time;
 int x, y;
 int x_root, y_root;
 unsigned int state;
 unsigned int keycode;
 int same_screen;
} XKeyEvent;
typedef XKeyEvent XKeyPressedEvent;
typedef XKeyEvent XKeyReleasedEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 Window root;
 Window subwindow;
 Time time;
 int x, y;
 int x_root, y_root;
 unsigned int state;
 unsigned int button;
 int same_screen;
} XButtonEvent;
typedef XButtonEvent XButtonPressedEvent;
typedef XButtonEvent XButtonReleasedEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 Window root;
 Window subwindow;
 Time time;
 int x, y;
 int x_root, y_root;
 unsigned int state;
 char is_hint;
 int same_screen;
} XMotionEvent;
typedef XMotionEvent XPointerMovedEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 Window root;
 Window subwindow;
 Time time;
 int x, y;
 int x_root, y_root;
 int mode;
 int detail;
 int same_screen;
 int focus;
 unsigned int state;
} XCrossingEvent;
typedef XCrossingEvent XEnterWindowEvent;
typedef XCrossingEvent XLeaveWindowEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 int mode;
 int detail;
} XFocusChangeEvent;
typedef XFocusChangeEvent XFocusInEvent;
typedef XFocusChangeEvent XFocusOutEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 char key_vector[32];
} XKeymapEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 int x, y;
 int width, height;
 int count;
} XExposeEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Drawable drawable;
 int x, y;
 int width, height;
 int count;
 int major_code;
 int minor_code;
} XGraphicsExposeEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Drawable drawable;
 int major_code;
 int minor_code;
} XNoExposeEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 int state;
} XVisibilityEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window parent;
 Window window;
 int x, y;
 int width, height;
 int border_width;
 int override_redirect;
} XCreateWindowEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window event;
 Window window;
} XDestroyWindowEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window event;
 Window window;
 int from_configure;
} XUnmapEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window event;
 Window window;
 int override_redirect;
} XMapEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window parent;
 Window window;
} XMapRequestEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window event;
 Window window;
 Window parent;
 int x, y;
 int override_redirect;
} XReparentEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window event;
 Window window;
 int x, y;
 int width, height;
 int border_width;
 Window above;
 int override_redirect;
} XConfigureEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window event;
 Window window;
 int x, y;
} XGravityEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 int width, height;
} XResizeRequestEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window parent;
 Window window;
 int x, y;
 int width, height;
 int border_width;
 Window above;
 int detail;
 unsigned long value_mask;
} XConfigureRequestEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window event;
 Window window;
 int place;
} XCirculateEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window parent;
 Window window;
 int place;
} XCirculateRequestEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 Atom atom;
 Time time;
 int state;
} XPropertyEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 Atom selection;
 Time time;
} XSelectionClearEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window owner;
 Window requestor;
 Atom selection;
 Atom target;
 Atom property;
 Time time;
} XSelectionRequestEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window requestor;
 Atom selection;
 Atom target;
 Atom property;
 Time time;
} XSelectionEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 Colormap colormap;
 int new;
 int state;
} XColormapEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 Atom message_type;
 int format;
 union {
  char b[20];
  short s[10];
  long l[5];
  } data;
} XClientMessageEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 int request;
 int first_keycode;
 int count;
} XMappingEvent;
typedef struct {
 int type;
 Display *display;
 XID resourceid;
 unsigned long serial;
 unsigned char error_code;
 unsigned char request_code;
 unsigned char minor_code;
} XErrorEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
} XAnyEvent;
typedef struct
    {
    int type;
    unsigned long serial;
    int send_event;
    Display *display;
    int extension;
    int evtype;
    } XGenericEvent;
typedef struct {
    int type;
    unsigned long serial;
    int send_event;
    Display *display;
    int extension;
    int evtype;
    unsigned int cookie;
    void *data;
} XGenericEventCookie;
typedef union _XEvent {
        int type;
 XAnyEvent xany;
 XKeyEvent xkey;
 XButtonEvent xbutton;
 XMotionEvent xmotion;
 XCrossingEvent xcrossing;
 XFocusChangeEvent xfocus;
 XExposeEvent xexpose;
 XGraphicsExposeEvent xgraphicsexpose;
 XNoExposeEvent xnoexpose;
 XVisibilityEvent xvisibility;
 XCreateWindowEvent xcreatewindow;
 XDestroyWindowEvent xdestroywindow;
 XUnmapEvent xunmap;
 XMapEvent xmap;
 XMapRequestEvent xmaprequest;
 XReparentEvent xreparent;
 XConfigureEvent xconfigure;
 XGravityEvent xgravity;
 XResizeRequestEvent xresizerequest;
 XConfigureRequestEvent xconfigurerequest;
 XCirculateEvent xcirculate;
 XCirculateRequestEvent xcirculaterequest;
 XPropertyEvent xproperty;
 XSelectionClearEvent xselectionclear;
 XSelectionRequestEvent xselectionrequest;
 XSelectionEvent xselection;
 XColormapEvent xcolormap;
 XClientMessageEvent xclient;
 XMappingEvent xmapping;
 XErrorEvent xerror;
 XKeymapEvent xkeymap;
 XGenericEvent xgeneric;
 XGenericEventCookie xcookie;
 long pad[24];
} XEvent;
typedef struct {
    short lbearing;
    short rbearing;
    short width;
    short ascent;
    short descent;
    unsigned short attributes;
} XCharStruct;
typedef struct {
    Atom name;
    unsigned long card32;
} XFontProp;
typedef struct {
    XExtData *ext_data;
    Font fid;
    unsigned direction;
    unsigned min_char_or_byte2;
    unsigned max_char_or_byte2;
    unsigned min_byte1;
    unsigned max_byte1;
    int all_chars_exist;
    unsigned default_char;
    int n_properties;
    XFontProp *properties;
    XCharStruct min_bounds;
    XCharStruct max_bounds;
    XCharStruct *per_char;
    int ascent;
    int descent;
} XFontStruct;
typedef struct {
    char *chars;
    int nchars;
    int delta;
    Font font;
} XTextItem;
typedef struct {
    unsigned char byte1;
    unsigned char byte2;
} XChar2b;
typedef struct {
    XChar2b *chars;
    int nchars;
    int delta;
    Font font;
} XTextItem16;
typedef union { Display *display;
  GC gc;
  Visual *visual;
  Screen *screen;
  ScreenFormat *pixmap_format;
  XFontStruct *font; } XEDataObject;
typedef struct {
    XRectangle max_ink_extent;
    XRectangle max_logical_extent;
} XFontSetExtents;
typedef struct _XOM *XOM;
typedef struct _XOC *XOC, *XFontSet;
typedef struct {
    char *chars;
    int nchars;
    int delta;
    XFontSet font_set;
} XmbTextItem;
typedef struct {
    wchar_t *chars;
    int nchars;
    int delta;
    XFontSet font_set;
} XwcTextItem;
typedef struct {
    int charset_count;
    char **charset_list;
} XOMCharSetList;
typedef enum {
    XOMOrientation_LTR_TTB,
    XOMOrientation_RTL_TTB,
    XOMOrientation_TTB_LTR,
    XOMOrientation_TTB_RTL,
    XOMOrientation_Context
} XOrientation;
typedef struct {
    int num_orientation;
    XOrientation *orientation;
} XOMOrientation;
typedef struct {
    int num_font;
    XFontStruct **font_struct_list;
    char **font_name_list;
} XOMFontInfo;
typedef struct _XIM *XIM;
typedef struct _XIC *XIC;
typedef void (*XIMProc)(
    XIM,
    XPointer,
    XPointer
);
typedef int (*XICProc)(
    XIC,
    XPointer,
    XPointer
);
typedef void (*XIDProc)(
    Display*,
    XPointer,
    XPointer
);
typedef unsigned long XIMStyle;
typedef struct {
    unsigned short count_styles;
    XIMStyle *supported_styles;
} XIMStyles;
typedef void *XVaNestedList;
typedef struct {
    XPointer client_data;
    XIMProc callback;
} XIMCallback;
typedef struct {
    XPointer client_data;
    XICProc callback;
} XICCallback;
typedef unsigned long XIMFeedback;
typedef struct _XIMText {
    unsigned short length;
    XIMFeedback *feedback;
    int encoding_is_wchar;
    union {
 char *multi_byte;
 wchar_t *wide_char;
    } string;
} XIMText;
typedef unsigned long XIMPreeditState;
typedef struct _XIMPreeditStateNotifyCallbackStruct {
    XIMPreeditState state;
} XIMPreeditStateNotifyCallbackStruct;
typedef unsigned long XIMResetState;
typedef unsigned long XIMStringConversionFeedback;
typedef struct _XIMStringConversionText {
    unsigned short length;
    XIMStringConversionFeedback *feedback;
    int encoding_is_wchar;
    union {
 char *mbs;
 wchar_t *wcs;
    } string;
} XIMStringConversionText;
typedef unsigned short XIMStringConversionPosition;
typedef unsigned short XIMStringConversionType;
typedef unsigned short XIMStringConversionOperation;
typedef enum {
    XIMForwardChar, XIMBackwardChar,
    XIMForwardWord, XIMBackwardWord,
    XIMCaretUp, XIMCaretDown,
    XIMNextLine, XIMPreviousLine,
    XIMLineStart, XIMLineEnd,
    XIMAbsolutePosition,
    XIMDontChange
} XIMCaretDirection;
typedef struct _XIMStringConversionCallbackStruct {
    XIMStringConversionPosition position;
    XIMCaretDirection direction;
    XIMStringConversionOperation operation;
    unsigned short factor;
    XIMStringConversionText *text;
} XIMStringConversionCallbackStruct;
typedef struct _XIMPreeditDrawCallbackStruct {
    int caret;
    int chg_first;
    int chg_length;
    XIMText *text;
} XIMPreeditDrawCallbackStruct;
typedef enum {
    XIMIsInvisible,
    XIMIsPrimary,
    XIMIsSecondary
} XIMCaretStyle;
typedef struct _XIMPreeditCaretCallbackStruct {
    int position;
    XIMCaretDirection direction;
    XIMCaretStyle style;
} XIMPreeditCaretCallbackStruct;
typedef enum {
    XIMTextType,
    XIMBitmapType
} XIMStatusDataType;
typedef struct _XIMStatusDrawCallbackStruct {
    XIMStatusDataType type;
    union {
 XIMText *text;
 Pixmap bitmap;
    } data;
} XIMStatusDrawCallbackStruct;
typedef struct _XIMHotKeyTrigger {
    KeySym keysym;
    int modifier;
    int modifier_mask;
} XIMHotKeyTrigger;
typedef struct _XIMHotKeyTriggers {
    int num_hot_key;
    XIMHotKeyTrigger *key;
} XIMHotKeyTriggers;
typedef unsigned long XIMHotKeyState;
typedef struct {
    unsigned short count_values;
    char **supported_values;
} XIMValuesList;
extern int _Xdebug;
extern XFontStruct *XLoadQueryFont(
    Display* ,
    const char*
);
extern XFontStruct *XQueryFont(
    Display* ,
    XID
);
extern XTimeCoord *XGetMotionEvents(
    Display* ,
    Window ,
    Time ,
    Time ,
    int*
);
extern XModifierKeymap *XDeleteModifiermapEntry(
    XModifierKeymap* ,
    KeyCode ,
    int
);
extern XModifierKeymap *XGetModifierMapping(
    Display*
);
extern XModifierKeymap *XInsertModifiermapEntry(
    XModifierKeymap* ,
    KeyCode ,
    int
);
extern XModifierKeymap *XNewModifiermap(
    int
);
extern XImage *XCreateImage(
    Display* ,
    Visual* ,
    unsigned int ,
    int ,
    int ,
    char* ,
    unsigned int ,
    unsigned int ,
    int ,
    int
);
extern int XInitImage(
    XImage*
);
extern XImage *XGetImage(
    Display* ,
    Drawable ,
    int ,
    int ,
    unsigned int ,
    unsigned int ,
    unsigned long ,
    int
);
extern XImage *XGetSubImage(
    Display* ,
    Drawable ,
    int ,
    int ,
    unsigned int ,
    unsigned int ,
    unsigned long ,
    int ,
    XImage* ,
    int ,
    int
);
extern Display *XOpenDisplay(
    const char*
);
extern void XrmInitialize(
    void
);
extern char *XFetchBytes(
    Display* ,
    int*
);
extern char *XFetchBuffer(
    Display* ,
    int* ,
    int
);
extern char *XGetAtomName(
    Display* ,
    Atom
);
extern int XGetAtomNames(
    Display* ,
    Atom* ,
    int ,
    char**
);
extern char *XGetDefault(
    Display* ,
    const char* ,
    const char*
);
extern char *XDisplayName(
    const char*
);
extern char *XKeysymToString(
    KeySym
);
extern int (*XSynchronize(
    Display* ,
    int
))(
    Display*
);
extern int (*XSetAfterFunction(
    Display* ,
    int (*) (
      Display*
            )
))(
    Display*
);
extern Atom XInternAtom(
    Display* ,
    const char* ,
    int
);
extern int XInternAtoms(
    Display* ,
    char** ,
    int ,
    int ,
    Atom*
);
extern Colormap XCopyColormapAndFree(
    Display* ,
    Colormap
);
extern Colormap XCreateColormap(
    Display* ,
    Window ,
    Visual* ,
    int
);
extern Cursor XCreatePixmapCursor(
    Display* ,
    Pixmap ,
    Pixmap ,
    XColor* ,
    XColor* ,
    unsigned int ,
    unsigned int
);
extern Cursor XCreateGlyphCursor(
    Display* ,
    Font ,
    Font ,
    unsigned int ,
    unsigned int ,
    XColor const * ,
    XColor const *
);
extern Cursor XCreateFontCursor(
    Display* ,
    unsigned int
);
extern Font XLoadFont(
    Display* ,
    const char*
);
extern GC XCreateGC(
    Display* ,
    Drawable ,
    unsigned long ,
    XGCValues*
);
extern GContext XGContextFromGC(
    GC
);
extern void XFlushGC(
    Display* ,
    GC
);
extern Pixmap XCreatePixmap(
    Display* ,
    Drawable ,
    unsigned int ,
    unsigned int ,
    unsigned int
);
extern Pixmap XCreateBitmapFromData(
    Display* ,
    Drawable ,
    const char* ,
    unsigned int ,
    unsigned int
);
extern Pixmap XCreatePixmapFromBitmapData(
    Display* ,
    Drawable ,
    char* ,
    unsigned int ,
    unsigned int ,
    unsigned long ,
    unsigned long ,
    unsigned int
);
extern Window XCreateSimpleWindow(
    Display* ,
    Window ,
    int ,
    int ,
    unsigned int ,
    unsigned int ,
    unsigned int ,
    unsigned long ,
    unsigned long
);
extern Window XGetSelectionOwner(
    Display* ,
    Atom
);
extern Window XCreateWindow(
    Display* ,
    Window ,
    int ,
    int ,
    unsigned int ,
    unsigned int ,
    unsigned int ,
    int ,
    unsigned int ,
    Visual* ,
    unsigned long ,
    XSetWindowAttributes*
);
extern Colormap *XListInstalledColormaps(
    Display* ,
    Window ,
    int*
);
extern char **XListFonts(
    Display* ,
    const char* ,
    int ,
    int*
);
extern char **XListFontsWithInfo(
    Display* ,
    const char* ,
    int ,
    int* ,
    XFontStruct**
);
extern char **XGetFontPath(
    Display* ,
    int*
);
extern char **XListExtensions(
    Display* ,
    int*
);
extern Atom *XListProperties(
    Display* ,
    Window ,
    int*
);
extern XHostAddress *XListHosts(
    Display* ,
    int* ,
    int*
);
__attribute__((deprecated))
extern KeySym XKeycodeToKeysym(
    Display* ,
    KeyCode ,
    int
);
extern KeySym XLookupKeysym(
    XKeyEvent* ,
    int
);
extern KeySym *XGetKeyboardMapping(
    Display* ,
    KeyCode ,
    int ,
    int*
);
extern KeySym XStringToKeysym(
    const char*
);
extern long XMaxRequestSize(
    Display*
);
extern long XExtendedMaxRequestSize(
    Display*
);
extern char *XResourceManagerString(
    Display*
);
extern char *XScreenResourceString(
 Screen*
);
extern unsigned long XDisplayMotionBufferSize(
    Display*
);
extern VisualID XVisualIDFromVisual(
    Visual*
);
extern int XInitThreads(
    void
);
extern int XFreeThreads(
    void
);
extern void XLockDisplay(
    Display*
);
extern void XUnlockDisplay(
    Display*
);
extern XExtCodes *XInitExtension(
    Display* ,
    const char*
);
extern XExtCodes *XAddExtension(
    Display*
);
extern XExtData *XFindOnExtensionList(
    XExtData** ,
    int
);
extern XExtData **XEHeadOfExtensionList(
    XEDataObject
);
extern Window XRootWindow(
    Display* ,
    int
);
extern Window XDefaultRootWindow(
    Display*
);
extern Window XRootWindowOfScreen(
    Screen*
);
extern Visual *XDefaultVisual(
    Display* ,
    int
);
extern Visual *XDefaultVisualOfScreen(
    Screen*
);
extern GC XDefaultGC(
    Display* ,
    int
);
extern GC XDefaultGCOfScreen(
    Screen*
);
extern unsigned long XBlackPixel(
    Display* ,
    int
);
extern unsigned long XWhitePixel(
    Display* ,
    int
);
extern unsigned long XAllPlanes(
    void
);
extern unsigned long XBlackPixelOfScreen(
    Screen*
);
extern unsigned long XWhitePixelOfScreen(
    Screen*
);
extern unsigned long XNextRequest(
    Display*
);
extern unsigned long XLastKnownRequestProcessed(
    Display*
);
extern char *XServerVendor(
    Display*
);
extern char *XDisplayString(
    Display*
);
extern Colormap XDefaultColormap(
    Display* ,
    int
);
extern Colormap XDefaultColormapOfScreen(
    Screen*
);
extern Display *XDisplayOfScreen(
    Screen*
);
extern Screen *XScreenOfDisplay(
    Display* ,
    int
);
extern Screen *XDefaultScreenOfDisplay(
    Display*
);
extern long XEventMaskOfScreen(
    Screen*
);
extern int XScreenNumberOfScreen(
    Screen*
);
typedef int (*XErrorHandler) (
    Display* ,
    XErrorEvent*
);
extern XErrorHandler XSetErrorHandler (
    XErrorHandler
);
typedef int (*XIOErrorHandler) (
    Display*
);
extern XIOErrorHandler XSetIOErrorHandler (
    XIOErrorHandler
);
typedef void (*XIOErrorExitHandler) (
    Display*,
    void*
);
extern void XSetIOErrorExitHandler (
    Display*,
    XIOErrorExitHandler,
    void*
);
extern XPixmapFormatValues *XListPixmapFormats(
    Display* ,
    int*
);
extern int *XListDepths(
    Display* ,
    int ,
    int*
);
extern int XReconfigureWMWindow(
    Display* ,
    Window ,
    int ,
    unsigned int ,
    XWindowChanges*
);
extern int XGetWMProtocols(
    Display* ,
    Window ,
    Atom** ,
    int*
);
extern int XSetWMProtocols(
    Display* ,
    Window ,
    Atom* ,
    int
);
extern int XIconifyWindow(
    Display* ,
    Window ,
    int
);
extern int XWithdrawWindow(
    Display* ,
    Window ,
    int
);
extern int XGetCommand(
    Display* ,
    Window ,
    char*** ,
    int*
);
extern int XGetWMColormapWindows(
    Display* ,
    Window ,
    Window** ,
    int*
);
extern int XSetWMColormapWindows(
    Display* ,
    Window ,
    Window* ,
    int
);
extern void XFreeStringList(
    char**
);
extern int XSetTransientForHint(
    Display* ,
    Window ,
    Window
);
extern int XActivateScreenSaver(
    Display*
);
extern int XAddHost(
    Display* ,
    XHostAddress*
);
extern int XAddHosts(
    Display* ,
    XHostAddress* ,
    int
);
extern int XAddToExtensionList(
    struct _XExtData** ,
    XExtData*
);
extern int XAddToSaveSet(
    Display* ,
    Window
);
extern int XAllocColor(
    Display* ,
    Colormap ,
    XColor*
);
extern int XAllocColorCells(
    Display* ,
    Colormap ,
    int ,
    unsigned long* ,
    unsigned int ,
    unsigned long* ,
    unsigned int
);
extern int XAllocColorPlanes(
    Display* ,
    Colormap ,
    int ,
    unsigned long* ,
    int ,
    int ,
    int ,
    int ,
    unsigned long* ,
    unsigned long* ,
    unsigned long*
);
extern int XAllocNamedColor(
    Display* ,
    Colormap ,
    const char* ,
    XColor* ,
    XColor*
);
extern int XAllowEvents(
    Display* ,
    int ,
    Time
);
extern int XAutoRepeatOff(
    Display*
);
extern int XAutoRepeatOn(
    Display*
);
extern int XBell(
    Display* ,
    int
);
extern int XBitmapBitOrder(
    Display*
);
extern int XBitmapPad(
    Display*
);
extern int XBitmapUnit(
    Display*
);
extern int XCellsOfScreen(
    Screen*
);
extern int XChangeActivePointerGrab(
    Display* ,
    unsigned int ,
    Cursor ,
    Time
);
extern int XChangeGC(
    Display* ,
    GC ,
    unsigned long ,
    XGCValues*
);
extern int XChangeKeyboardControl(
    Display* ,
    unsigned long ,
    XKeyboardControl*
);
extern int XChangeKeyboardMapping(
    Display* ,
    int ,
    int ,
    KeySym* ,
    int
);
extern int XChangePointerControl(
    Display* ,
    int ,
    int ,
    int ,
    int ,
    int
);
extern int XChangeProperty(
    Display* ,
    Window ,
    Atom ,
    Atom ,
    int ,
    int ,
    const unsigned char* ,
    int
);
extern int XChangeSaveSet(
    Display* ,
    Window ,
    int
);
extern int XChangeWindowAttributes(
    Display* ,
    Window ,
    unsigned long ,
    XSetWindowAttributes*
);
extern int XCheckIfEvent(
    Display* ,
    XEvent* ,
    int (*) (
        Display* ,
               XEvent* ,
               XPointer
             ) ,
    XPointer
);
extern int XCheckMaskEvent(
    Display* ,
    long ,
    XEvent*
);
extern int XCheckTypedEvent(
    Display* ,
    int ,
    XEvent*
);
extern int XCheckTypedWindowEvent(
    Display* ,
    Window ,
    int ,
    XEvent*
);
extern int XCheckWindowEvent(
    Display* ,
    Window ,
    long ,
    XEvent*
);
extern int XCirculateSubwindows(
    Display* ,
    Window ,
    int
);
extern int XCirculateSubwindowsDown(
    Display* ,
    Window
);
extern int XCirculateSubwindowsUp(
    Display* ,
    Window
);
extern int XClearArea(
    Display* ,
    Window ,
    int ,
    int ,
    unsigned int ,
    unsigned int ,
    int
);
extern int XClearWindow(
    Display* ,
    Window
);
extern int XCloseDisplay(
    Display*
);
extern int XConfigureWindow(
    Display* ,
    Window ,
    unsigned int ,
    XWindowChanges*
);
extern int XConnectionNumber(
    Display*
);
extern int XConvertSelection(
    Display* ,
    Atom ,
    Atom ,
    Atom ,
    Window ,
    Time
);
extern int XCopyArea(
    Display* ,
    Drawable ,
    Drawable ,
    GC ,
    int ,
    int ,
    unsigned int ,
    unsigned int ,
    int ,
    int
);
extern int XCopyGC(
    Display* ,
    GC ,
    unsigned long ,
    GC
);
extern int XCopyPlane(
    Display* ,
    Drawable ,
    Drawable ,
    GC ,
    int ,
    int ,
    unsigned int ,
    unsigned int ,
    int ,
    int ,
    unsigned long
);
extern int XDefaultDepth(
    Display* ,
    int
);
extern int XDefaultDepthOfScreen(
    Screen*
);
extern int XDefaultScreen(
    Display*
);
extern int XDefineCursor(
    Display* ,
    Window ,
    Cursor
);
extern int XDeleteProperty(
    Display* ,
    Window ,
    Atom
);
extern int XDestroyWindow(
    Display* ,
    Window
);
extern int XDestroySubwindows(
    Display* ,
    Window
);
extern int XDoesBackingStore(
    Screen*
);
extern int XDoesSaveUnders(
    Screen*
);
extern int XDisableAccessControl(
    Display*
);
extern int XDisplayCells(
    Display* ,
    int
);
extern int XDisplayHeight(
    Display* ,
    int
);
extern int XDisplayHeightMM(
    Display* ,
    int
);
extern int XDisplayKeycodes(
    Display* ,
    int* ,
    int*
);
extern int XDisplayPlanes(
    Display* ,
    int
);
extern int XDisplayWidth(
    Display* ,
    int
);
extern int XDisplayWidthMM(
    Display* ,
    int
);
extern int XDrawArc(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    unsigned int ,
    unsigned int ,
    int ,
    int
);
extern int XDrawArcs(
    Display* ,
    Drawable ,
    GC ,
    XArc* ,
    int
);
extern int XDrawImageString(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    const char* ,
    int
);
extern int XDrawImageString16(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    const XChar2b* ,
    int
);
extern int XDrawLine(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    int ,
    int
);
extern int XDrawLines(
    Display* ,
    Drawable ,
    GC ,
    XPoint* ,
    int ,
    int
);
extern int XDrawPoint(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int
);
extern int XDrawPoints(
    Display* ,
    Drawable ,
    GC ,
    XPoint* ,
    int ,
    int
);
extern int XDrawRectangle(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    unsigned int ,
    unsigned int
);
extern int XDrawRectangles(
    Display* ,
    Drawable ,
    GC ,
    XRectangle* ,
    int
);
extern int XDrawSegments(
    Display* ,
    Drawable ,
    GC ,
    XSegment* ,
    int
);
extern int XDrawString(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    const char* ,
    int
);
extern int XDrawString16(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    const XChar2b* ,
    int
);
extern int XDrawText(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    XTextItem* ,
    int
);
extern int XDrawText16(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    XTextItem16* ,
    int
);
extern int XEnableAccessControl(
    Display*
);
extern int XEventsQueued(
    Display* ,
    int
);
extern int XFetchName(
    Display* ,
    Window ,
    char**
);
extern int XFillArc(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    unsigned int ,
    unsigned int ,
    int ,
    int
);
extern int XFillArcs(
    Display* ,
    Drawable ,
    GC ,
    XArc* ,
    int
);
extern int XFillPolygon(
    Display* ,
    Drawable ,
    GC ,
    XPoint* ,
    int ,
    int ,
    int
);
extern int XFillRectangle(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    unsigned int ,
    unsigned int
);
extern int XFillRectangles(
    Display* ,
    Drawable ,
    GC ,
    XRectangle* ,
    int
);
extern int XFlush(
    Display*
);
extern int XForceScreenSaver(
    Display* ,
    int
);
extern int XFree(
    void*
);
extern int XFreeColormap(
    Display* ,
    Colormap
);
extern int XFreeColors(
    Display* ,
    Colormap ,
    unsigned long* ,
    int ,
    unsigned long
);
extern int XFreeCursor(
    Display* ,
    Cursor
);
extern int XFreeExtensionList(
    char**
);
extern int XFreeFont(
    Display* ,
    XFontStruct*
);
extern int XFreeFontInfo(
    char** ,
    XFontStruct* ,
    int
);
extern int XFreeFontNames(
    char**
);
extern int XFreeFontPath(
    char**
);
extern int XFreeGC(
    Display* ,
    GC
);
extern int XFreeModifiermap(
    XModifierKeymap*
);
extern int XFreePixmap(
    Display* ,
    Pixmap
);
extern int XGeometry(
    Display* ,
    int ,
    const char* ,
    const char* ,
    unsigned int ,
    unsigned int ,
    unsigned int ,
    int ,
    int ,
    int* ,
    int* ,
    int* ,
    int*
);
extern int XGetErrorDatabaseText(
    Display* ,
    const char* ,
    const char* ,
    const char* ,
    char* ,
    int
);
extern int XGetErrorText(
    Display* ,
    int ,
    char* ,
    int
);
extern int XGetFontProperty(
    XFontStruct* ,
    Atom ,
    unsigned long*
);
extern int XGetGCValues(
    Display* ,
    GC ,
    unsigned long ,
    XGCValues*
);
extern int XGetGeometry(
    Display* ,
    Drawable ,
    Window* ,
    int* ,
    int* ,
    unsigned int* ,
    unsigned int* ,
    unsigned int* ,
    unsigned int*
);
extern int XGetIconName(
    Display* ,
    Window ,
    char**
);
extern int XGetInputFocus(
    Display* ,
    Window* ,
    int*
);
extern int XGetKeyboardControl(
    Display* ,
    XKeyboardState*
);
extern int XGetPointerControl(
    Display* ,
    int* ,
    int* ,
    int*
);
extern int XGetPointerMapping(
    Display* ,
    unsigned char* ,
    int
);
extern int XGetScreenSaver(
    Display* ,
    int* ,
    int* ,
    int* ,
    int*
);
extern int XGetTransientForHint(
    Display* ,
    Window ,
    Window*
);
extern int XGetWindowProperty(
    Display* ,
    Window ,
    Atom ,
    long ,
    long ,
    int ,
    Atom ,
    Atom* ,
    int* ,
    unsigned long* ,
    unsigned long* ,
    unsigned char**
);
extern int XGetWindowAttributes(
    Display* ,
    Window ,
    XWindowAttributes*
);
extern int XGrabButton(
    Display* ,
    unsigned int ,
    unsigned int ,
    Window ,
    int ,
    unsigned int ,
    int ,
    int ,
    Window ,
    Cursor
);
extern int XGrabKey(
    Display* ,
    int ,
    unsigned int ,
    Window ,
    int ,
    int ,
    int
);
extern int XGrabKeyboard(
    Display* ,
    Window ,
    int ,
    int ,
    int ,
    Time
);
extern int XGrabPointer(
    Display* ,
    Window ,
    int ,
    unsigned int ,
    int ,
    int ,
    Window ,
    Cursor ,
    Time
);
extern int XGrabServer(
    Display*
);
extern int XHeightMMOfScreen(
    Screen*
);
extern int XHeightOfScreen(
    Screen*
);
extern int XIfEvent(
    Display* ,
    XEvent* ,
    int (*) (
        Display* ,
               XEvent* ,
               XPointer
             ) ,
    XPointer
);
extern int XImageByteOrder(
    Display*
);
extern int XInstallColormap(
    Display* ,
    Colormap
);
extern KeyCode XKeysymToKeycode(
    Display* ,
    KeySym
);
extern int XKillClient(
    Display* ,
    XID
);
extern int XLookupColor(
    Display* ,
    Colormap ,
    const char* ,
    XColor* ,
    XColor*
);
extern int XLowerWindow(
    Display* ,
    Window
);
extern int XMapRaised(
    Display* ,
    Window
);
extern int XMapSubwindows(
    Display* ,
    Window
);
extern int XMapWindow(
    Display* ,
    Window
);
extern int XMaskEvent(
    Display* ,
    long ,
    XEvent*
);
extern int XMaxCmapsOfScreen(
    Screen*
);
extern int XMinCmapsOfScreen(
    Screen*
);
extern int XMoveResizeWindow(
    Display* ,
    Window ,
    int ,
    int ,
    unsigned int ,
    unsigned int
);
extern int XMoveWindow(
    Display* ,
    Window ,
    int ,
    int
);
extern int XNextEvent(
    Display* ,
    XEvent*
);
extern int XNoOp(
    Display*
);
extern int XParseColor(
    Display* ,
    Colormap ,
    const char* ,
    XColor*
);
extern int XParseGeometry(
    const char* ,
    int* ,
    int* ,
    unsigned int* ,
    unsigned int*
);
extern int XPeekEvent(
    Display* ,
    XEvent*
);
extern int XPeekIfEvent(
    Display* ,
    XEvent* ,
    int (*) (
        Display* ,
               XEvent* ,
               XPointer
             ) ,
    XPointer
);
extern int XPending(
    Display*
);
extern int XPlanesOfScreen(
    Screen*
);
extern int XProtocolRevision(
    Display*
);
extern int XProtocolVersion(
    Display*
);
extern int XPutBackEvent(
    Display* ,
    XEvent*
);
extern int XPutImage(
    Display* ,
    Drawable ,
    GC ,
    XImage* ,
    int ,
    int ,
    int ,
    int ,
    unsigned int ,
    unsigned int
);
extern int XQLength(
    Display*
);
extern int XQueryBestCursor(
    Display* ,
    Drawable ,
    unsigned int ,
    unsigned int ,
    unsigned int* ,
    unsigned int*
);
extern int XQueryBestSize(
    Display* ,
    int ,
    Drawable ,
    unsigned int ,
    unsigned int ,
    unsigned int* ,
    unsigned int*
);
extern int XQueryBestStipple(
    Display* ,
    Drawable ,
    unsigned int ,
    unsigned int ,
    unsigned int* ,
    unsigned int*
);
extern int XQueryBestTile(
    Display* ,
    Drawable ,
    unsigned int ,
    unsigned int ,
    unsigned int* ,
    unsigned int*
);
extern int XQueryColor(
    Display* ,
    Colormap ,
    XColor*
);
extern int XQueryColors(
    Display* ,
    Colormap ,
    XColor* ,
    int
);
extern int XQueryExtension(
    Display* ,
    const char* ,
    int* ,
    int* ,
    int*
);
extern int XQueryKeymap(
    Display* ,
    char [32]
);
extern int XQueryPointer(
    Display* ,
    Window ,
    Window* ,
    Window* ,
    int* ,
    int* ,
    int* ,
    int* ,
    unsigned int*
);
extern int XQueryTextExtents(
    Display* ,
    XID ,
    const char* ,
    int ,
    int* ,
    int* ,
    int* ,
    XCharStruct*
);
extern int XQueryTextExtents16(
    Display* ,
    XID ,
    const XChar2b* ,
    int ,
    int* ,
    int* ,
    int* ,
    XCharStruct*
);
extern int XQueryTree(
    Display* ,
    Window ,
    Window* ,
    Window* ,
    Window** ,
    unsigned int*
);
extern int XRaiseWindow(
    Display* ,
    Window
);
extern int XReadBitmapFile(
    Display* ,
    Drawable ,
    const char* ,
    unsigned int* ,
    unsigned int* ,
    Pixmap* ,
    int* ,
    int*
);
extern int XReadBitmapFileData(
    const char* ,
    unsigned int* ,
    unsigned int* ,
    unsigned char** ,
    int* ,
    int*
);
extern int XRebindKeysym(
    Display* ,
    KeySym ,
    KeySym* ,
    int ,
    const unsigned char* ,
    int
);
extern int XRecolorCursor(
    Display* ,
    Cursor ,
    XColor* ,
    XColor*
);
extern int XRefreshKeyboardMapping(
    XMappingEvent*
);
extern int XRemoveFromSaveSet(
    Display* ,
    Window
);
extern int XRemoveHost(
    Display* ,
    XHostAddress*
);
extern int XRemoveHosts(
    Display* ,
    XHostAddress* ,
    int
);
extern int XReparentWindow(
    Display* ,
    Window ,
    Window ,
    int ,
    int
);
extern int XResetScreenSaver(
    Display*
);
extern int XResizeWindow(
    Display* ,
    Window ,
    unsigned int ,
    unsigned int
);
extern int XRestackWindows(
    Display* ,
    Window* ,
    int
);
extern int XRotateBuffers(
    Display* ,
    int
);
extern int XRotateWindowProperties(
    Display* ,
    Window ,
    Atom* ,
    int ,
    int
);
extern int XScreenCount(
    Display*
);
extern int XSelectInput(
    Display* ,
    Window ,
    long
);
extern int XSendEvent(
    Display* ,
    Window ,
    int ,
    long ,
    XEvent*
);
extern int XSetAccessControl(
    Display* ,
    int
);
extern int XSetArcMode(
    Display* ,
    GC ,
    int
);
extern int XSetBackground(
    Display* ,
    GC ,
    unsigned long
);
extern int XSetClipMask(
    Display* ,
    GC ,
    Pixmap
);
extern int XSetClipOrigin(
    Display* ,
    GC ,
    int ,
    int
);
extern int XSetClipRectangles(
    Display* ,
    GC ,
    int ,
    int ,
    XRectangle* ,
    int ,
    int
);
extern int XSetCloseDownMode(
    Display* ,
    int
);
extern int XSetCommand(
    Display* ,
    Window ,
    char** ,
    int
);
extern int XSetDashes(
    Display* ,
    GC ,
    int ,
    const char* ,
    int
);
extern int XSetFillRule(
    Display* ,
    GC ,
    int
);
extern int XSetFillStyle(
    Display* ,
    GC ,
    int
);
extern int XSetFont(
    Display* ,
    GC ,
    Font
);
extern int XSetFontPath(
    Display* ,
    char** ,
    int
);
extern int XSetForeground(
    Display* ,
    GC ,
    unsigned long
);
extern int XSetFunction(
    Display* ,
    GC ,
    int
);
extern int XSetGraphicsExposures(
    Display* ,
    GC ,
    int
);
extern int XSetIconName(
    Display* ,
    Window ,
    const char*
);
extern int XSetInputFocus(
    Display* ,
    Window ,
    int ,
    Time
);
extern int XSetLineAttributes(
    Display* ,
    GC ,
    unsigned int ,
    int ,
    int ,
    int
);
extern int XSetModifierMapping(
    Display* ,
    XModifierKeymap*
);
extern int XSetPlaneMask(
    Display* ,
    GC ,
    unsigned long
);
extern int XSetPointerMapping(
    Display* ,
    const unsigned char* ,
    int
);
extern int XSetScreenSaver(
    Display* ,
    int ,
    int ,
    int ,
    int
);
extern int XSetSelectionOwner(
    Display* ,
    Atom ,
    Window ,
    Time
);
extern int XSetState(
    Display* ,
    GC ,
    unsigned long ,
    unsigned long ,
    int ,
    unsigned long
);
extern int XSetStipple(
    Display* ,
    GC ,
    Pixmap
);
extern int XSetSubwindowMode(
    Display* ,
    GC ,
    int
);
extern int XSetTSOrigin(
    Display* ,
    GC ,
    int ,
    int
);
extern int XSetTile(
    Display* ,
    GC ,
    Pixmap
);
extern int XSetWindowBackground(
    Display* ,
    Window ,
    unsigned long
);
extern int XSetWindowBackgroundPixmap(
    Display* ,
    Window ,
    Pixmap
);
extern int XSetWindowBorder(
    Display* ,
    Window ,
    unsigned long
);
extern int XSetWindowBorderPixmap(
    Display* ,
    Window ,
    Pixmap
);
extern int XSetWindowBorderWidth(
    Display* ,
    Window ,
    unsigned int
);
extern int XSetWindowColormap(
    Display* ,
    Window ,
    Colormap
);
extern int XStoreBuffer(
    Display* ,
    const char* ,
    int ,
    int
);
extern int XStoreBytes(
    Display* ,
    const char* ,
    int
);
extern int XStoreColor(
    Display* ,
    Colormap ,
    XColor*
);
extern int XStoreColors(
    Display* ,
    Colormap ,
    XColor* ,
    int
);
extern int XStoreName(
    Display* ,
    Window ,
    const char*
);
extern int XStoreNamedColor(
    Display* ,
    Colormap ,
    const char* ,
    unsigned long ,
    int
);
extern int XSync(
    Display* ,
    int
);
extern int XTextExtents(
    XFontStruct* ,
    const char* ,
    int ,
    int* ,
    int* ,
    int* ,
    XCharStruct*
);
extern int XTextExtents16(
    XFontStruct* ,
    const XChar2b* ,
    int ,
    int* ,
    int* ,
    int* ,
    XCharStruct*
);
extern int XTextWidth(
    XFontStruct* ,
    const char* ,
    int
);
extern int XTextWidth16(
    XFontStruct* ,
    const XChar2b* ,
    int
);
extern int XTranslateCoordinates(
    Display* ,
    Window ,
    Window ,
    int ,
    int ,
    int* ,
    int* ,
    Window*
);
extern int XUndefineCursor(
    Display* ,
    Window
);
extern int XUngrabButton(
    Display* ,
    unsigned int ,
    unsigned int ,
    Window
);
extern int XUngrabKey(
    Display* ,
    int ,
    unsigned int ,
    Window
);
extern int XUngrabKeyboard(
    Display* ,
    Time
);
extern int XUngrabPointer(
    Display* ,
    Time
);
extern int XUngrabServer(
    Display*
);
extern int XUninstallColormap(
    Display* ,
    Colormap
);
extern int XUnloadFont(
    Display* ,
    Font
);
extern int XUnmapSubwindows(
    Display* ,
    Window
);
extern int XUnmapWindow(
    Display* ,
    Window
);
extern int XVendorRelease(
    Display*
);
extern int XWarpPointer(
    Display* ,
    Window ,
    Window ,
    int ,
    int ,
    unsigned int ,
    unsigned int ,
    int ,
    int
);
extern int XWidthMMOfScreen(
    Screen*
);
extern int XWidthOfScreen(
    Screen*
);
extern int XWindowEvent(
    Display* ,
    Window ,
    long ,
    XEvent*
);
extern int XWriteBitmapFile(
    Display* ,
    const char* ,
    Pixmap ,
    unsigned int ,
    unsigned int ,
    int ,
    int
);
extern int XSupportsLocale (void);
extern char *XSetLocaleModifiers(
    const char*
);
extern XOM XOpenOM(
    Display* ,
    struct _XrmHashBucketRec* ,
    const char* ,
    const char*
);
extern int XCloseOM(
    XOM
);
extern char *XSetOMValues(
    XOM ,
    ...
) __attribute__ ((__sentinel__(0)));
extern char *XGetOMValues(
    XOM ,
    ...
) __attribute__ ((__sentinel__(0)));
extern Display *XDisplayOfOM(
    XOM
);
extern char *XLocaleOfOM(
    XOM
);
extern XOC XCreateOC(
    XOM ,
    ...
) __attribute__ ((__sentinel__(0)));
extern void XDestroyOC(
    XOC
);
extern XOM XOMOfOC(
    XOC
);
extern char *XSetOCValues(
    XOC ,
    ...
) __attribute__ ((__sentinel__(0)));
extern char *XGetOCValues(
    XOC ,
    ...
) __attribute__ ((__sentinel__(0)));
extern XFontSet XCreateFontSet(
    Display* ,
    const char* ,
    char*** ,
    int* ,
    char**
);
extern void XFreeFontSet(
    Display* ,
    XFontSet
);
extern int XFontsOfFontSet(
    XFontSet ,
    XFontStruct*** ,
    char***
);
extern char *XBaseFontNameListOfFontSet(
    XFontSet
);
extern char *XLocaleOfFontSet(
    XFontSet
);
extern int XContextDependentDrawing(
    XFontSet
);
extern int XDirectionalDependentDrawing(
    XFontSet
);
extern int XContextualDrawing(
    XFontSet
);
extern XFontSetExtents *XExtentsOfFontSet(
    XFontSet
);
extern int XmbTextEscapement(
    XFontSet ,
    const char* ,
    int
);
extern int XwcTextEscapement(
    XFontSet ,
    const wchar_t* ,
    int
);
extern int Xutf8TextEscapement(
    XFontSet ,
    const char* ,
    int
);
extern int XmbTextExtents(
    XFontSet ,
    const char* ,
    int ,
    XRectangle* ,
    XRectangle*
);
extern int XwcTextExtents(
    XFontSet ,
    const wchar_t* ,
    int ,
    XRectangle* ,
    XRectangle*
);
extern int Xutf8TextExtents(
    XFontSet ,
    const char* ,
    int ,
    XRectangle* ,
    XRectangle*
);
extern int XmbTextPerCharExtents(
    XFontSet ,
    const char* ,
    int ,
    XRectangle* ,
    XRectangle* ,
    int ,
    int* ,
    XRectangle* ,
    XRectangle*
);
extern int XwcTextPerCharExtents(
    XFontSet ,
    const wchar_t* ,
    int ,
    XRectangle* ,
    XRectangle* ,
    int ,
    int* ,
    XRectangle* ,
    XRectangle*
);
extern int Xutf8TextPerCharExtents(
    XFontSet ,
    const char* ,
    int ,
    XRectangle* ,
    XRectangle* ,
    int ,
    int* ,
    XRectangle* ,
    XRectangle*
);
extern void XmbDrawText(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    XmbTextItem* ,
    int
);
extern void XwcDrawText(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    XwcTextItem* ,
    int
);
extern void Xutf8DrawText(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    XmbTextItem* ,
    int
);
extern void XmbDrawString(
    Display* ,
    Drawable ,
    XFontSet ,
    GC ,
    int ,
    int ,
    const char* ,
    int
);
extern void XwcDrawString(
    Display* ,
    Drawable ,
    XFontSet ,
    GC ,
    int ,
    int ,
    const wchar_t* ,
    int
);
extern void Xutf8DrawString(
    Display* ,
    Drawable ,
    XFontSet ,
    GC ,
    int ,
    int ,
    const char* ,
    int
);
extern void XmbDrawImageString(
    Display* ,
    Drawable ,
    XFontSet ,
    GC ,
    int ,
    int ,
    const char* ,
    int
);
extern void XwcDrawImageString(
    Display* ,
    Drawable ,
    XFontSet ,
    GC ,
    int ,
    int ,
    const wchar_t* ,
    int
);
extern void Xutf8DrawImageString(
    Display* ,
    Drawable ,
    XFontSet ,
    GC ,
    int ,
    int ,
    const char* ,
    int
);
extern XIM XOpenIM(
    Display* ,
    struct _XrmHashBucketRec* ,
    char* ,
    char*
);
extern int XCloseIM(
    XIM
);
extern char *XGetIMValues(
    XIM , ...
) __attribute__ ((__sentinel__(0)));
extern char *XSetIMValues(
    XIM , ...
) __attribute__ ((__sentinel__(0)));
extern Display *XDisplayOfIM(
    XIM
);
extern char *XLocaleOfIM(
    XIM
);
extern XIC XCreateIC(
    XIM , ...
) __attribute__ ((__sentinel__(0)));
extern void XDestroyIC(
    XIC
);
extern void XSetICFocus(
    XIC
);
extern void XUnsetICFocus(
    XIC
);
extern wchar_t *XwcResetIC(
    XIC
);
extern char *XmbResetIC(
    XIC
);
extern char *Xutf8ResetIC(
    XIC
);
extern char *XSetICValues(
    XIC , ...
) __attribute__ ((__sentinel__(0)));
extern char *XGetICValues(
    XIC , ...
) __attribute__ ((__sentinel__(0)));
extern XIM XIMOfIC(
    XIC
);
extern int XFilterEvent(
    XEvent* ,
    Window
);
extern int XmbLookupString(
    XIC ,
    XKeyPressedEvent* ,
    char* ,
    int ,
    KeySym* ,
    int*
);
extern int XwcLookupString(
    XIC ,
    XKeyPressedEvent* ,
    wchar_t* ,
    int ,
    KeySym* ,
    int*
);
extern int Xutf8LookupString(
    XIC ,
    XKeyPressedEvent* ,
    char* ,
    int ,
    KeySym* ,
    int*
);
extern XVaNestedList XVaCreateNestedList(
    int , ...
) __attribute__ ((__sentinel__(0)));
extern int XRegisterIMInstantiateCallback(
    Display* ,
    struct _XrmHashBucketRec* ,
    char* ,
    char* ,
    XIDProc ,
    XPointer
);
extern int XUnregisterIMInstantiateCallback(
    Display* ,
    struct _XrmHashBucketRec* ,
    char* ,
    char* ,
    XIDProc ,
    XPointer
);
typedef void (*XConnectionWatchProc)(
    Display* ,
    XPointer ,
    int ,
    int ,
    XPointer*
);
extern int XInternalConnectionNumbers(
    Display* ,
    int** ,
    int*
);
extern void XProcessInternalConnection(
    Display* ,
    int
);
extern int XAddConnectionWatch(
    Display* ,
    XConnectionWatchProc ,
    XPointer
);
extern void XRemoveConnectionWatch(
    Display* ,
    XConnectionWatchProc ,
    XPointer
);
extern void XSetAuthorization(
    char * ,
    int ,
    char * ,
    int
);
extern int _Xmbtowc(
    wchar_t * ,
    char * ,
    int
);
extern int _Xwctomb(
    char * ,
    wchar_t
);
extern int XGetEventData(
    Display* ,
    XGenericEventCookie*
);
extern void XFreeEventData(
    Display* ,
    XGenericEventCookie*
);
typedef struct {
     long flags;
 int x, y;
 int width, height;
 int min_width, min_height;
 int max_width, max_height;
     int width_inc, height_inc;
 struct {
  int x;
  int y;
 } min_aspect, max_aspect;
 int base_width, base_height;
 int win_gravity;
} XSizeHints;
typedef struct {
 long flags;
 int input;
 int initial_state;
 Pixmap icon_pixmap;
 Window icon_window;
 int icon_x, icon_y;
 Pixmap icon_mask;
 XID window_group;
} XWMHints;
typedef struct {
    unsigned char *value;
    Atom encoding;
    int format;
    unsigned long nitems;
} XTextProperty;
typedef enum {
    XStringStyle,
    XCompoundTextStyle,
    XTextStyle,
    XStdICCTextStyle,
    XUTF8StringStyle
} XICCEncodingStyle;
typedef struct {
 int min_width, min_height;
 int max_width, max_height;
 int width_inc, height_inc;
} XIconSize;
typedef struct {
 char *res_name;
 char *res_class;
} XClassHint;
typedef struct _XComposeStatus {
    XPointer compose_ptr;
    int chars_matched;
} XComposeStatus;
typedef struct _XRegion *Region;
typedef struct {
  Visual *visual;
  VisualID visualid;
  int screen;
  int depth;
  int class;
  unsigned long red_mask;
  unsigned long green_mask;
  unsigned long blue_mask;
  int colormap_size;
  int bits_per_rgb;
} XVisualInfo;
typedef struct {
 Colormap colormap;
 unsigned long red_max;
 unsigned long red_mult;
 unsigned long green_max;
 unsigned long green_mult;
 unsigned long blue_max;
 unsigned long blue_mult;
 unsigned long base_pixel;
 VisualID visualid;
 XID killid;
} XStandardColormap;
typedef int XContext;
extern XClassHint *XAllocClassHint (
    void
);
extern XIconSize *XAllocIconSize (
    void
);
extern XSizeHints *XAllocSizeHints (
    void
);
extern XStandardColormap *XAllocStandardColormap (
    void
);
extern XWMHints *XAllocWMHints (
    void
);
extern int XClipBox(
    Region ,
    XRectangle*
);
extern Region XCreateRegion(
    void
);
extern const char *XDefaultString (void);
extern int XDeleteContext(
    Display* ,
    XID ,
    XContext
);
extern int XDestroyRegion(
    Region
);
extern int XEmptyRegion(
    Region
);
extern int XEqualRegion(
    Region ,
    Region
);
extern int XFindContext(
    Display* ,
    XID ,
    XContext ,
    XPointer*
);
extern int XGetClassHint(
    Display* ,
    Window ,
    XClassHint*
);
extern int XGetIconSizes(
    Display* ,
    Window ,
    XIconSize** ,
    int*
);
extern int XGetNormalHints(
    Display* ,
    Window ,
    XSizeHints*
);
extern int XGetRGBColormaps(
    Display* ,
    Window ,
    XStandardColormap** ,
    int* ,
    Atom
);
extern int XGetSizeHints(
    Display* ,
    Window ,
    XSizeHints* ,
    Atom
);
extern int XGetStandardColormap(
    Display* ,
    Window ,
    XStandardColormap* ,
    Atom
);
extern int XGetTextProperty(
    Display* ,
    Window ,
    XTextProperty* ,
    Atom
);
extern XVisualInfo *XGetVisualInfo(
    Display* ,
    long ,
    XVisualInfo* ,
    int*
);
extern int XGetWMClientMachine(
    Display* ,
    Window ,
    XTextProperty*
);
extern XWMHints *XGetWMHints(
    Display* ,
    Window
);
extern int XGetWMIconName(
    Display* ,
    Window ,
    XTextProperty*
);
extern int XGetWMName(
    Display* ,
    Window ,
    XTextProperty*
);
extern int XGetWMNormalHints(
    Display* ,
    Window ,
    XSizeHints* ,
    long*
);
extern int XGetWMSizeHints(
    Display* ,
    Window ,
    XSizeHints* ,
    long* ,
    Atom
);
extern int XGetZoomHints(
    Display* ,
    Window ,
    XSizeHints*
);
extern int XIntersectRegion(
    Region ,
    Region ,
    Region
);
extern void XConvertCase(
    KeySym ,
    KeySym* ,
    KeySym*
);
extern int XLookupString(
    XKeyEvent* ,
    char* ,
    int ,
    KeySym* ,
    XComposeStatus*
);
extern int XMatchVisualInfo(
    Display* ,
    int ,
    int ,
    int ,
    XVisualInfo*
);
extern int XOffsetRegion(
    Region ,
    int ,
    int
);
extern int XPointInRegion(
    Region ,
    int ,
    int
);
extern Region XPolygonRegion(
    XPoint* ,
    int ,
    int
);
extern int XRectInRegion(
    Region ,
    int ,
    int ,
    unsigned int ,
    unsigned int
);
extern int XSaveContext(
    Display* ,
    XID ,
    XContext ,
    const char*
);
extern int XSetClassHint(
    Display* ,
    Window ,
    XClassHint*
);
extern int XSetIconSizes(
    Display* ,
    Window ,
    XIconSize* ,
    int
);
extern int XSetNormalHints(
    Display* ,
    Window ,
    XSizeHints*
);
extern void XSetRGBColormaps(
    Display* ,
    Window ,
    XStandardColormap* ,
    int ,
    Atom
);
extern int XSetSizeHints(
    Display* ,
    Window ,
    XSizeHints* ,
    Atom
);
extern int XSetStandardProperties(
    Display* ,
    Window ,
    const char* ,
    const char* ,
    Pixmap ,
    char** ,
    int ,
    XSizeHints*
);
extern void XSetTextProperty(
    Display* ,
    Window ,
    XTextProperty* ,
    Atom
);
extern void XSetWMClientMachine(
    Display* ,
    Window ,
    XTextProperty*
);
extern int XSetWMHints(
    Display* ,
    Window ,
    XWMHints*
);
extern void XSetWMIconName(
    Display* ,
    Window ,
    XTextProperty*
);
extern void XSetWMName(
    Display* ,
    Window ,
    XTextProperty*
);
extern void XSetWMNormalHints(
    Display* ,
    Window ,
    XSizeHints*
);
extern void XSetWMProperties(
    Display* ,
    Window ,
    XTextProperty* ,
    XTextProperty* ,
    char** ,
    int ,
    XSizeHints* ,
    XWMHints* ,
    XClassHint*
);
extern void XmbSetWMProperties(
    Display* ,
    Window ,
    const char* ,
    const char* ,
    char** ,
    int ,
    XSizeHints* ,
    XWMHints* ,
    XClassHint*
);
extern void Xutf8SetWMProperties(
    Display* ,
    Window ,
    const char* ,
    const char* ,
    char** ,
    int ,
    XSizeHints* ,
    XWMHints* ,
    XClassHint*
);
extern void XSetWMSizeHints(
    Display* ,
    Window ,
    XSizeHints* ,
    Atom
);
extern int XSetRegion(
    Display* ,
    GC ,
    Region
);
extern void XSetStandardColormap(
    Display* ,
    Window ,
    XStandardColormap* ,
    Atom
);
extern int XSetZoomHints(
    Display* ,
    Window ,
    XSizeHints*
);
extern int XShrinkRegion(
    Region ,
    int ,
    int
);
extern int XStringListToTextProperty(
    char** ,
    int ,
    XTextProperty*
);
extern int XSubtractRegion(
    Region ,
    Region ,
    Region
);
extern int XmbTextListToTextProperty(
    Display* display,
    char** list,
    int count,
    XICCEncodingStyle style,
    XTextProperty* text_prop_return
);
extern int XwcTextListToTextProperty(
    Display* display,
    wchar_t** list,
    int count,
    XICCEncodingStyle style,
    XTextProperty* text_prop_return
);
extern int Xutf8TextListToTextProperty(
    Display* display,
    char** list,
    int count,
    XICCEncodingStyle style,
    XTextProperty* text_prop_return
);
extern void XwcFreeStringList(
    wchar_t** list
);
extern int XTextPropertyToStringList(
    XTextProperty* ,
    char*** ,
    int*
);
extern int XmbTextPropertyToTextList(
    Display* display,
    const XTextProperty* text_prop,
    char*** list_return,
    int* count_return
);
extern int XwcTextPropertyToTextList(
    Display* display,
    const XTextProperty* text_prop,
    wchar_t*** list_return,
    int* count_return
);
extern int Xutf8TextPropertyToTextList(
    Display* display,
    const XTextProperty* text_prop,
    char*** list_return,
    int* count_return
);
extern int XUnionRectWithRegion(
    XRectangle* ,
    Region ,
    Region
);
extern int XUnionRegion(
    Region ,
    Region ,
    Region
);
extern int XWMGeometry(
    Display* ,
    int ,
    const char* ,
    const char* ,
    unsigned int ,
    XSizeHints* ,
    int* ,
    int* ,
    int* ,
    int* ,
    int*
);
extern int XXorRegion(
    Region ,
    Region ,
    Region
);
typedef struct
{
    VisualID visual;
    int depth;
    int perflevel;
}
XdbeVisualInfo;
typedef struct
{
    int count;
    XdbeVisualInfo *visinfo;
}
XdbeScreenVisualInfo;
typedef Drawable XdbeBackBuffer;
typedef unsigned char XdbeSwapAction;
typedef struct
{
    Window swap_window;
    XdbeSwapAction swap_action;
}
XdbeSwapInfo;
typedef struct
{
    Window window;
}
XdbeBackBufferAttributes;
typedef struct
{
    int type;
    Display *display;
    XdbeBackBuffer buffer;
    unsigned long serial;
    unsigned char error_code;
    unsigned char request_code;
    unsigned char minor_code;
}
XdbeBufferError;
extern int XdbeQueryExtension(
    Display* ,
    int* ,
    int*
);
extern XdbeBackBuffer XdbeAllocateBackBufferName(
    Display* ,
    Window ,
    XdbeSwapAction
);
extern int XdbeDeallocateBackBufferName(
    Display* ,
    XdbeBackBuffer
);
extern int XdbeSwapBuffers(
    Display* ,
    XdbeSwapInfo* ,
    int
);
extern int XdbeBeginIdiom(
    Display*
);
extern int XdbeEndIdiom(
    Display*
);
extern XdbeScreenVisualInfo *XdbeGetVisualInfo(
    Display* ,
    Drawable* ,
    int*
);
extern void XdbeFreeVisualInfo(
    XdbeScreenVisualInfo*
);
extern XdbeBackBufferAttributes *XdbeGetBackBufferAttributes(
    Display* ,
    XdbeBackBuffer
);
int WD=320, HT=240, BITMAP=320*240, SCRWD=5, SCRHT=5, VECWD=240, VECHT=240, VECSTEP=4;
void cex(Uint, Ull*, Ull, Ull, Ull, Ull, Ushort);
void ex4(Uint, Ull*, Ull*, Uint, Ull*, Uint, Ull*, Uint, Uint, Ull*, Uint, Ull*);
Ull __attribute__((always_inline)) exm(Ull, Uchar);
int exe(Uint, Ull*, Ull, Uint, Ull, Uint, Ull, Uint, Uint, Ull, Uint, Ull);
void mex(Uint, Uchar**, Uchar*, Ull, Uint, Uchar**, Uchar*, Ull, Ull, Ull, Ull);
void mo4(Uint, Ull, Ull*, Ull, Ull, Uchar, Ull, Uint, Uint, Uchar, Ull, Uint);
void mop(Uint, Ull, Ull*, Ull, Ull, Uchar, Ull, Uint, Uint, Uchar, Ull, Uint);
Ull __attribute__((always_inline)) eam(Ull, Uchar);
void eag(Ull*, Ull, Ull);
void mmp(Uint, Ull, Ull*, Ull, Ull, Uint, Uint);
int NLANE;
int EMAX_DEPTH;
int LMM_SIZE;
int current_prefix;
int current_mapdist;
int current_nchip;
int current_lmmwb;
int last_insn;
char forinit[2][4][1024];
char forinit_cidx[2];
struct cex {
  char op ;
  char bit0v ;
  int bit0h ;
  char bit1v ;
  int bit1h ;
  char bit2v ;
  int bit2h ;
  char bit3v ;
  int bit3h ;
  Ull table :16;
  char cexdv ;
  int cexdh ;
};
struct exe {
  char op1 ;
  char op2 ;
  char op3 ;
  Ull updt : 1;
  Ull init : 2;
  char src1v ;
  int src1h ;
  char src1s ;
  char src1e ;
  char src2v ;
  int src2h ;
  char src2s ;
  char src2e ;
  char src3v ;
  int src3h ;
  char src3s ;
  char src3e ;
  char src4v ;
  int src4h ;
  char src4s ;
  char src5v ;
  int src5h ;
  char src5s ;
  char exedv ;
  int exedh ;
  char exeds ;
};
struct mex {
  char op0 ;
  char op1 ;
  Ull init : 1;
  char adr1v ;
  int adr1h ;
  char adr1s ;
  char adr2v ;
  int adr2h ;
  char adr2s ;
  char dist1v ;
  int dist1h ;
  char adr3v ;
  int adr3h ;
  char adr3s ;
  char adr4v ;
  int adr4h ;
  char adr4s ;
  char dist2v ;
  int dist2h ;
  char limitv ;
  int limith ;
  char src1v ;
  int src1h ;
  char src1s ;
  char src2v ;
  int src2h ;
  char src2s ;
  char mexd0v ;
  int mexd0h ;
  char mexd0s ;
  char mexd1v ;
  int mexd1h ;
  char mexd1s ;
};
struct mop {
  char op ;
  char mtype ;
  Ull updt : 1;
  char exv ;
  int exh ;
  char mopdv ;
  int mopdh ;
  char mopds ;
  char basev ;
  int baseh ;
  char bases ;
  char offsv ;
  int offsh ;
  char offss ;
  char offsm ;
  char topv ;
  int toph ;
  int lenv ;
  int lenh ;
  char blk ;
  int forcev ;
  int forceh ;
  char ptopv ;
  int ptoph ;
  int plenv ;
  int plenh ;
};
struct insn {
  struct header {
    char type ;
    char row ;
    char col ;
    char rdep ;
    char fixed ;
  } iheader;
  struct cex icex;
  struct exe iexe;
  struct mex imex;
  struct mop imop;
} insn[(4*64*4)];
struct dec {
  struct cex dcex;
  struct exu {
    char op1 ;
    char op2 ;
    char op3 ;
    Ull updt : 1;
    Ull init : 2;
    Ull fold : 1;
    char ex1v ;
    int ex1h ;
    char ex1s ;
    char ex1e ;
    char ex2v ;
    int ex2h ;
    char ex2s ;
    char ex2e ;
    char ex3v ;
    int ex3h ;
    char ex3s ;
    char ex3e ;
    char e2iv ;
    int e2ih ;
    char e2is ;
    char e3iv ;
    int e3ih ;
    char e3is ;
    char exdv ;
    int exdh ;
    char exds ;
  } dexu;
  struct mex dmex;
  struct mop dmop0;
  struct mop dmop1;
} dec[64][4];
struct bus {
  char cexdv ;
  int cexdh ;
  char exdrv ;
  int exdrh ;
  char exdrs ;
  char ea0brv ;
  int ea0brh ;
  char ea0orv ;
  int ea0orh ;
  char ea0drv ;
  int ea0drh ;
  char ea0woofsv;
  int ea0woofsh;
  char ea1brv ;
  int ea1brh ;
  char ea1orv ;
  int ea1orh ;
  char ea1drv ;
  int ea1drh ;
  char ea1woofsv;
  int ea1woofsh;
  struct {
    char v ;
    int h ;
    char s ;
  } lmwd[4], lmrd[4];
  struct {
    char v ;
    int h ;
    char s ;
  } tr[4];
  struct {
    char v ;
    int h ;
    char s ;
  } mw[4];
  struct {
    char v ;
    int h ;
    char s ;
  } br[4];
} bus[64][4];
struct conf {
  struct cdw0 {
    Ull v : 1;
    Ull op1 : 6;
    Ull op2 : 3;
    Ull op3 : 3;
    Ull ex1brs : 4;
    Ull ex1s : 1;
    Ull ex1exp : 3;
    Ull ex2brs : 4;
    Ull ex2exp : 3;
    Ull ex3brs : 4;
    Ull ex3exp : 3;
    Ull e2is : 2;
    Ull e3imm : 6;
    Ull e3is : 1;
    Ull init : 2;
    Ull fold : 1;
    Ull mex0op : 2;
    Ull mex0init: 1;
    Ull mex0dist: 3;
    Ull mex1op : 2;
    Ull mex1init: 1;
    Ull mex1dist: 3;
    Ull mexlimit: 4;
    Ull dmy00 : 1;
  } cdw0;
  struct cdw1 {
    Ull cs0 : 4;
    Ull cs1 : 4;
    Ull cs2 : 4;
    Ull cs3 : 4;
    Ull cex_tab: 16;
    Ull ea0op : 5;
    Ull ea0bs : 2;
    Ull ea0os : 1;
    Ull ea0msk : 4;
    Ull ea1op : 5;
    Ull ea1bs : 2;
    Ull ea1os : 1;
    Ull ea1msk : 4;
    Ull eabbrs : 4;
    Ull eaobrs : 4;
  } cdw1;
  struct cdw2 {
    Ull ts0 : 4;
    Ull ts1 : 4;
    Ull ts2 : 4;
    Ull ts3 : 4;
    Ull trs0 : 2;
    Ull trs1 : 2;
    Ull trs2 : 2;
    Ull trs3 : 2;
    Ull mwsa : 1;
    Ull mws0 : 2;
    Ull mws1 : 2;
    Ull mws2 : 2;
    Ull mws3 : 2;
    Ull brs0 : 2;
    Ull brs1 : 2;
    Ull brs2 : 2;
    Ull brs3 : 2;
    Ull mapdist: 6;
    Ull lmm_mode: 2;
    Ull lmm_axiw: 1;
    Ull lmm_axir: 1;
    Ull dmy20 : 13;
  } cdw2;
  struct cdw3 {
    Ull e2imm : 64;
  } cdw3;
} conf[64][4];
struct lmmi {
  Ull v : 1;
  Ull rw : 1;
  Ull f : 1;
  Ull p : 1;
  Ull bcas : 4;
  Ull hcopy: 1;
  Ull vcopy: 1;
  Ull blk : 2;
  Ull cidx : 1;
  Ull len :19;
  Ull ofs :32;
  Ull top :64;
} lmmi[64][4];
int lmmi_first_loc;
Ull lmmi_bitmap[4];
Ull range_bitmap[4];
Uchar range_link[64][4];
struct lmmx {
  int forcev ;
  int forceh ;
  int lenv ;
  int lenh ;
} lmmx[64][4];
struct {
  struct {
    int v;
    int h;
    int s;
  } br[4];
  int ea0b_v;
  int ea0b_h;
  int ea0b_s;
  int ea0o_v;
  int ea0o_h;
  int ea0o_s;
  int ea1b_v;
  int ea1b_h;
  int ea1b_s;
  int ea1o_v;
  int ea1o_h;
  int ea1o_s;
} regv[64][4];
int trans_pc;
struct trans {
  Ull rw : 1;
  Ull base_type : 2;
  Ull base_num : 3;
  char *base_symbol;
  Ull offset_type : 1;
  Ull offset : 4;
  Ull offset_suffix : 3;
  Ull offset_sll : 3;
  Ull op_type : 3;
  Ull op_val_type : 2;
  Ull op_val_num;
  char *op_val_symbol;
  Ull t_action_type : 2;
  Ull t_action : 4;
  Ull f_action_type : 2;
  Ull f_action : 4;
  Ull reg_type : 1;
  Ull reg_num : 3;
  char *reg_symbol;
} trans[16];
struct tconf {
  Ull rw : 1;
  Ull base_type : 2;
  Ull offset_type : 1;
  Ull offset : 4;
  Ull offset_suffix : 3;
  Ull offset_sll : 3;
  Ull op_type : 3;
  Ull op_val_type : 1;
  Ull t_action_type : 2;
  Ull t_action : 4;
  Ull f_action_type : 2;
  Ull f_action : 4;
  Ull reg_type : 1;
  Ull dmy : 1;
  Ull base;
  Ull op_val;
  Ull reg;
} tconf[16];
enum { NANOS_ARM, NANOS_DRAIN, NANOS_CONF, NANOS_REGV, NANOS_RANGE, NANOS_LOAD, NANOS_EXEC, NANOS_TOTAL, NANOS_CLASS };
typedef struct {
  Uint f : 23;
  Uint e : 8;
  Uint s : 1;
} f32bit;
typedef struct {
  Uint e : 6;
  Uint b : 1;
  Uint s : 1;
  Uint dm : 24;
} wu7bit;
typedef struct {
  Uint e : 7;
  Uint s : 1;
  Uint dm : 24;
} wu8bit;
typedef struct {
  Uchar u[8];
} u64bit;
struct dma_ctrl {
  Uint MM2S_DMACR;
  Uint MM2S_DMASR;
  Uint reserved0[4];
  Uint MM2S_SA;
  Uint MM2S_SA_MSB;
  Uint reserved1[2];
  Uint MM2S_LENGTH;
  Uint reserved2[1];
  Uint S2MM_DMACR;
  Uint S2MM_DMASR;
  Uint reserves3[4];
  Uint S2MM_DA;
  Uint S2MM_DA_MSB;
  Uint reserved4[2];
  Uint S2MM_LENGTH;
};
enum { EXRING_IDLE, EXRING_BUSY};
enum { LMRING_IDLE, LMRING_BUSY};
enum { CMD_NOP, CMD_RESET, CMD_SCON, CMD_EXEC};
struct reg_ctrl {
  struct i0 {
    Ull stat;
    Uint mcid;
    Uint dmy0;
    Uint cmd;
    Uint dmy1;
    Ull dmy2;
    Ull adtr;
    Ull dmy3;
    Ull csel;
    Ull dmrp;
    Ull dmy4[1016];
    struct conf conf[64][4];
    struct {Ull br[4];} breg[64][4];
    struct {Uint ea0b ;
        Uint ea0o ;
        Uint ea1b ;
        Uint ea1o ;
        Uint top ;
        Uint bot ;
        Ull dmy6 ;} addr[64][4];
    struct {Ull reg[4];} lddmrw[64][4];
    Ull dmy5[3072];
  } i[4];
};
enum { STATUS_IDLE, STATUS_CONF, STATUS_SCON, STATUS_REGV, STATUS_RANGE, STATUS_DRAIN, STATUS_LOAD, STATUS_START, STATUS_EXEC, STATUS_TERM };
pthread_mutex_t axi_dma_mutex;
struct emax7 {
  volatile Ull dma_ctrl;
  volatile Ull reg_ctrl;
  Ull status : 4;
  Ull csel_save : 2;
  Ull last_conf ;
  Ull lmmic : 1;
  Ull lmmio : 1;
  Ull mapdist : 6;
  Ull lastdist : 6;
  struct lmmi lmmi[4][64][4][2];
  Ull lmmi_bitmap[4];
  Uchar lmmd[64][4];
  Ull plist ;
  Ull blkcount : 7;
  Ull blksize : 9;
  Ull lmmblktop ;
  Ull lmmblklen ;
  Ull rw ;
  Ull ddraddr ;
  Ull lmmaddr ;
  Ull dmalen ;
  Ull sigwait ;
  int *sigstat ;
  sigset_t *sigset ;
  Ull fsm_busy : 1;
  Ull lmwd_valid : 1;
  Ull tcureg_valid : 1;
  Ull tcureg_ready : 1;
  Ull tcureg_last : 1;
  Ull tcureg_term : 1;
  Ull tcureg[4] ;
} emax7[8];
volatile struct emax_info {
  Ull dma_phys;
  Ull dma_vadr;
  Ull dma_mmap;
  Ull reg_phys;
  Ull reg_vadr;
  Ull reg_mmap;
  Ull lmm_phys;
  Ull lmm_vadr;
  Ull lmm_mmap;
  Ull ddr_phys;
  Ull ddr_vadr;
  Ull ddr_mmap;
  int driver_use_1;
  int driver_use_2;
} emax_info[8];
extern int stat (const char *__restrict __file,
   struct stat *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int fstat (int __fd, struct stat *__buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int fstatat (int __fd, const char *__restrict __file,
      struct stat *__restrict __buf, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern int lstat (const char *__restrict __file,
    struct stat *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int chmod (const char *__file, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int lchmod (const char *__file, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int fchmod (int __fd, __mode_t __mode) __attribute__ ((__nothrow__ , __leaf__));
extern int fchmodat (int __fd, const char *__file, __mode_t __mode,
       int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;
extern __mode_t umask (__mode_t __mask) __attribute__ ((__nothrow__ , __leaf__));
extern int mkdir (const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int mkdirat (int __fd, const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int mknod (const char *__path, __mode_t __mode, __dev_t __dev)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int mknodat (int __fd, const char *__path, __mode_t __mode,
      __dev_t __dev) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int mkfifo (const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int mkfifoat (int __fd, const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int utimensat (int __fd, const char *__path,
        const struct timespec __times[2],
        int __flags)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int futimens (int __fd, const struct timespec __times[2]) __attribute__ ((__nothrow__ , __leaf__));
typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;
typedef __int_least8_t int_least8_t;
typedef __int_least16_t int_least16_t;
typedef __int_least32_t int_least32_t;
typedef __int_least64_t int_least64_t;
typedef __uint_least8_t uint_least8_t;
typedef __uint_least16_t uint_least16_t;
typedef __uint_least32_t uint_least32_t;
typedef __uint_least64_t uint_least64_t;
typedef signed char int_fast8_t;
typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef unsigned long int uintptr_t;
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;
extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
       size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memmove (void *__dest, const void *__src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memccpy (void *__restrict __dest, const void *__restrict __src,
        int __c, size_t __n)
    __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__write_only__, 1, 4)));
extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int __memcmpeq (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strcat (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strncat (char *__restrict __dest, const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strcmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strcoll (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern size_t strxfrm (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
    __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) __attribute__ ((__access__ (__write_only__, 1, 3)));
extern int strcoll_l (const char *__s1, const char *__s2, locale_t __l)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));
extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
    locale_t __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)))
     __attribute__ ((__access__ (__write_only__, 1, 3)));
extern char *strdup (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
extern char *strndup (const char *__string, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
extern char *strchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *strrchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern size_t strcspn (const char *__s, const char *__reject)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern size_t strspn (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strpbrk (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strstr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strtok (char *__restrict __s, const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern char *__strtok_r (char *__restrict __s,
    const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern char *strtok_r (char *__restrict __s, const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern size_t strlen (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern size_t strnlen (const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *strerror (int __errnum) __attribute__ ((__nothrow__ , __leaf__));
extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__ ("" "__xpg_strerror_r") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)))
    __attribute__ ((__access__ (__write_only__, 2, 3)));
extern char *strerror_l (int __errnum, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern void bcopy (const void *__src, void *__dest, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern char *index (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *rindex (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern int ffs (int __i) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int ffsl (long int __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
__extension__ extern int ffsll (long long int __ll)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int strcasecmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strcasecmp_l (const char *__s1, const char *__s2, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));
extern int strncasecmp_l (const char *__s1, const char *__s2,
     size_t __n, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 4)));
extern void explicit_bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
    __attribute__ ((__access__ (__write_only__, 1, 2)));
extern char *strsep (char **__restrict __stringp,
       const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern char *__stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *__stpncpy (char *__restrict __dest,
   const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
struct dirent
  {
    __ino_t d_ino;
    __off_t d_off;
    unsigned short int d_reclen;
    unsigned char d_type;
    char d_name[256];
  };
enum
  {
    DT_UNKNOWN = 0,
    DT_FIFO = 1,
    DT_CHR = 2,
    DT_DIR = 4,
    DT_BLK = 6,
    DT_REG = 8,
    DT_LNK = 10,
    DT_SOCK = 12,
    DT_WHT = 14
  };
typedef struct __dirstream DIR;
extern int closedir (DIR *__dirp) __attribute__ ((__nonnull__ (1)));
extern DIR *opendir (const char *__name) __attribute__ ((__nonnull__ (1)))
 __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (closedir, 1)));
extern DIR *fdopendir (int __fd)
 __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (closedir, 1)));
extern struct dirent *readdir (DIR *__dirp) __attribute__ ((__nonnull__ (1)));
extern int readdir_r (DIR *__restrict __dirp,
        struct dirent *__restrict __entry,
        struct dirent **__restrict __result)
     __attribute__ ((__nonnull__ (1, 2, 3))) __attribute__ ((__deprecated__));
extern void rewinddir (DIR *__dirp) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void seekdir (DIR *__dirp, long int __pos) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int telldir (DIR *__dirp) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int dirfd (DIR *__dirp) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int scandir (const char *__restrict __dir,
      struct dirent ***__restrict __namelist,
      int (*__selector) (const struct dirent *),
      int (*__cmp) (const struct dirent **,
      const struct dirent **))
     __attribute__ ((__nonnull__ (1, 2)));
extern int alphasort (const struct dirent **__e1,
        const struct dirent **__e2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern __ssize_t getdirentries (int __fd, char *__restrict __buf,
    size_t __nbytes,
    __off_t *__restrict __basep)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));
extern int *__errno_location (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
static int filter(struct dirent *dir)
{
  return dir->d_name[0] == '.' ? 0 : 1;
}
static void trim(char *d_name)
{
  char *p = strchr(d_name, '\n');
  if (p != ((void *)0)) *p = '\0';
}
static int is_target_dev(char *d_name, char *target)
{
  char path[32];
  char name[32];
  FILE *fp;
  sprintf(path, "/sys/class/uio/%s/name", d_name);
  if ((fp = fopen(path, "r")) == ((void *)0)) return 0;
  if (fgets(name, sizeof(name), fp) == ((void *)0)) {
    fclose(fp);
    return 0;
  }
  fclose(fp);
  if (strcmp(name, target) != 0) return 0;
  return 1;
}
static int get_reg_size(char *d_name)
{
  char path[32];
  char size[32];
  FILE *fp;
  sprintf(path, "/sys/class/uio/%s/maps/map0/size", d_name);
  if ((fp = fopen(path, "r")) == ((void *)0)) return 0;
  if (fgets(size, sizeof(size), fp) == ((void *)0)) {
    fclose(fp);
    return 0;
  }
  fclose(fp);
  return strtoull(size, ((void *)0), 16);
}
emax7_open(int NLANE)
{
  struct dirent **namelist;
  int num_dirs, dir, uiolen;
  int reg_size;
  char path[1024];
  int fd_dma;
  int fd_reg;
  int fd_ddr;
  char *UIO_AXI_C2C = "axi_chip2chip\n";
  char *UIO_AXI_MM2S = "axi_mm2s_mapper\n";
  char *UIO_DMA = "dma\n";
  char *UIO_AXI_EMAX6 = "emax6\n";
  char *UIO_DDR_HIGH = "ddr_high\n";
  int fd_dma_found = 0;
  int emax7_found = 0;
  int i;
  pthread_mutex_init(&axi_dma_mutex, ((void *)0));
  if ((num_dirs = scandir("/sys/class/uio", &namelist, filter, alphasort)) == -1)
    return (((void *)0));
  for (dir = 0; dir < num_dirs; ++dir)
    trim(namelist[dir]->d_name);
  for (uiolen=4; uiolen<6; uiolen++) {
    for (dir = 0; dir < num_dirs; ++dir) {
      if (strlen(namelist[dir]->d_name)!=uiolen)
 continue;
      if (is_target_dev(namelist[dir]->d_name, UIO_AXI_EMAX6)) {
 sprintf(path, "/dev/%s", namelist[dir]->d_name);
 if ((fd_reg = open(path, 02 | 04010000)) == -1) {
   printf("open failed. %s", UIO_AXI_EMAX6);
   return (((void *)0));
 }
 printf("%s: %s", path, UIO_AXI_EMAX6);
 if (emax7_found >= 8 || emax7_found >= NLANE) {
   printf("emax7_found > EMAX_NLANE || emax7_found >= given_NLANE (skip)\n");
   continue;
 }
 emax_info[emax7_found].reg_phys = 0x0000020800000000LL +0x0000000800000000LL*emax7_found;
 emax_info[emax7_found].reg_mmap = (Ull)mmap(((void *)0), 0x0000000200000000LL, 0x1|0x2, 0x01, fd_reg, 0);
 close(fd_reg);
 if (emax_info[emax7_found].reg_mmap == ((void *) -1)) {
   printf("fd_reg mmap() failed. errno=%d\n", (*__errno_location ()));
   return (((void *)0));
 }
 emax_info[emax7_found].lmm_phys = 0x0000020900000000LL +0x0000000800000000LL*emax7_found;
 emax_info[emax7_found].lmm_mmap = emax_info[emax7_found].reg_mmap + (0x0000020900000000LL - 0x0000020800000000LL);
 emax7_found++;
      }
    }
  }
  for (uiolen=4; uiolen<6; uiolen++) {
     for (dir = 0; dir < num_dirs; ++dir) {
      if (strlen(namelist[dir]->d_name)!=uiolen)
 continue;
      if (is_target_dev(namelist[dir]->d_name, UIO_DMA) && (reg_size = get_reg_size(namelist[dir]->d_name))) {
 sprintf(path, "/dev/%s", namelist[dir]->d_name);
 if ((fd_dma = open(path, 02 | 04010000)) == -1)
   continue;
 printf("%s: %s", path, UIO_DMA);
 if (fd_dma_found >= 8 || fd_dma_found >= NLANE) {
   printf("fd_dma_found > EMAX_NLANE || fd_dma_found > given_NLANE (skip)\n");
   continue;
 }
 emax_info[fd_dma_found].dma_phys = 0x00000000a4000000LL +0x0000000000010000LL*fd_dma_found;
 emax_info[fd_dma_found].dma_mmap = (Ull)mmap(((void *)0), reg_size, 0x1|0x2, 0x01, fd_dma, 0);
 close(fd_dma);
 if (emax_info[fd_dma_found].dma_mmap == ((void *) -1))
   continue;
 fd_dma_found++;
      }
      else if (is_target_dev(namelist[dir]->d_name, UIO_AXI_C2C)) {
 sprintf(path, "/dev/%s", namelist[dir]->d_name);
 if ((fd_reg = open(path, 02 | 04010000)) == -1) {
   printf("open failed. %s", UIO_AXI_C2C);
   return (((void *)0));
 }
 printf("%s: %s", path, UIO_AXI_C2C);
 if (emax7_found >= 8 || emax7_found >= NLANE) {
   printf("emax7_found > EMAX_NLANE || emax7_found > given_NLANE (skip)\n");
   continue;
 }
 emax_info[emax7_found].reg_phys = 0x0000020800000000LL +0x0000000800000000LL*emax7_found;
 emax_info[emax7_found].reg_mmap = (Ull)mmap(((void *)0), 0x0000000200000000LL, 0x1|0x2, 0x01, fd_reg, 0);
 close(fd_reg);
 if (emax_info[emax7_found].reg_mmap == ((void *) -1)) {
   printf("fd_reg mmap() failed. errno=%d\n", (*__errno_location ()));
   return (((void *)0));
 }
 emax_info[emax7_found].lmm_phys = 0x0000020900000000LL +0x0000000800000000LL*emax7_found;
 emax_info[emax7_found].lmm_mmap = emax_info[emax7_found].reg_mmap + (0x0000020900000000LL - 0x0000020800000000LL);
 emax7_found++;
      }
      else if (is_target_dev(namelist[dir]->d_name, UIO_AXI_MM2S)) {
 sprintf(path, "/dev/%s", namelist[dir]->d_name);
 if ((fd_reg = open(path, 02 | 04010000)) == -1) {
   printf("open failed. %s", UIO_AXI_MM2S);
   return (((void *)0));
 }
 printf("%s: %s", path, UIO_AXI_MM2S);
 if (emax7_found >= 8 || emax7_found >= NLANE) {
   printf("emax7_found > EMAX_NLANE || emax7_found > given_NLANE (skip)\n");
   continue;
 }
 emax_info[emax7_found].reg_phys = 0x0000020800000000LL +0x0000000800000000LL*emax7_found;
 emax_info[emax7_found].reg_mmap = (Ull)mmap(((void *)0), 0x0000000200000000LL, 0x1|0x2, 0x01, fd_reg, 0);
 close(fd_reg);
 if (emax_info[emax7_found].reg_mmap == ((void *) -1)) {
   printf("fd_reg mmap() failed. errno=%d\n", (*__errno_location ()));
   return (((void *)0));
 }
 emax_info[emax7_found].lmm_phys = 0x0000020900000000LL +0x0000000800000000LL*emax7_found;
 emax_info[emax7_found].lmm_mmap = emax_info[emax7_found].reg_mmap + (0x0000020900000000LL - 0x0000020800000000LL);
 emax7_found++;
      }
      else if (is_target_dev(namelist[dir]->d_name, UIO_DDR_HIGH)) {
 sprintf(path, "/dev/%s", namelist[dir]->d_name);
 if ((fd_ddr = open(path, 02 | 04010000)) == -1) {
   printf("open failed. %s",UIO_DDR_HIGH);
   return (((void *)0));
 }
 printf("%s: %s", path, UIO_DDR_HIGH);
 emax_info[0].ddr_phys = 0x0000050000000000LL;
 emax_info[0].ddr_mmap = (Ull)mmap(((void *)0), 0x0000000100000000LL, 0x1|0x2, 0x01, fd_ddr, 0);
 close(fd_ddr);
 if (emax_info[0].ddr_mmap == ((void *) -1)) {
   printf("fd_ddr mmap() failed. errno=%d\n", (*__errno_location ()));
   return (((void *)0));
 }
      }
    }
  }
  for (dir = 0; dir < num_dirs; ++dir)
    free(namelist[dir]);
  free(namelist);
  if (!emax7_found) {
    printf("EMAX not found: %s", UIO_AXI_EMAX6);
    exit(1);
  }
  if (fd_dma_found != emax7_found) {
    printf("Warning: fd_dma_found(%d) != emax7_found(%d)\n", fd_dma_found, emax7_found);
    if (fd_dma_found < emax7_found)
      emax7_found = fd_dma_found;
    else
      fd_dma_found = emax7_found;
  }
  for (i=0; i<fd_dma_found; i++) {
    ((struct dma_ctrl*)emax_info[i].dma_mmap)->MM2S_DMACR = 0x00010004;
    ((struct dma_ctrl*)emax_info[i].dma_mmap)->MM2S_DMASR = 0x00017000;
    ((struct dma_ctrl*)emax_info[i].dma_mmap)->S2MM_DMACR = 0x00010004;
    ((struct dma_ctrl*)emax_info[i].dma_mmap)->S2MM_DMASR = 0x00017000;
  }
  for (i=1; i<emax7_found; i++) {
    emax_info[i].ddr_phys = emax_info[0].ddr_phys;
    emax_info[i].ddr_mmap = emax_info[0].ddr_mmap;
  }
  return (emax7_found);
}
Ull nanosec_sav[8];
Ull nanosec[8][NANOS_CLASS];
sleep_nanosec(int nano)
{
  struct timespec ts;
  ts.tv_sec = 0;
  ts.tv_nsec = nano;
  nanosleep(((void *)0), &ts);
}
reset_nanosec(int LANE)
{
  int i;
  for (i=0; i<NANOS_CLASS; i++)
    nanosec[LANE][i] = 0;
  struct timespec ts;
  clock_gettime(0, &ts);
  nanosec_sav[LANE] = 1000000000*ts.tv_sec + ts.tv_nsec;
}
get_nanosec(int LANE, int class)
{
  Ull nanosec_now;
  struct timespec ts;
  clock_gettime(0, &ts);
  nanosec_now = 1000000000*ts.tv_sec + ts.tv_nsec;
  nanosec[LANE][class] += nanosec_now - nanosec_sav[LANE];
  nanosec[LANE][NANOS_TOTAL] += nanosec_now - nanosec_sav[LANE];
  nanosec_sav[LANE] = nanosec_now;
}
show_nanosec(int LANE)
{
  printf("LANE%d usec: ARM:%d DRAIN:%d CONF:%d REGV:%d RANGE:%d LOAD:%d EXEC:%d total:%d\n",
  LANE,
  (Uint)(nanosec[LANE][NANOS_ARM]/1000),
  (Uint)(nanosec[LANE][NANOS_DRAIN]/1000),
  (Uint)(nanosec[LANE][NANOS_CONF]/1000),
  (Uint)(nanosec[LANE][NANOS_REGV]/1000),
  (Uint)(nanosec[LANE][NANOS_RANGE]/1000),
  (Uint)(nanosec[LANE][NANOS_LOAD]/1000),
  (Uint)(nanosec[LANE][NANOS_EXEC]/1000),
  (Uint)(nanosec[LANE][NANOS_TOTAL]/1000));
}
emax7_check_lmmi_and_dma(int LANE, int mode, int phase, int lastdist, int c, int i, int j)
{
  int k, m = (i+lastdist)%EMAX_DEPTH;
  int lmmc_topz;
  int lmmc_ofsz;
  int lmmo_stat;
  int lmmc_stat;
  int lmm_ready;
  int lmm_readz;
  int mark;
  struct lmmi *lmmiop = &emax7[LANE].lmmi[c][m][j][emax7[LANE].lmmio];
  struct lmmi *lmmicp = &emax7[LANE].lmmi[c][i][j][emax7[LANE].lmmic];
  struct lmmi *lmmiop1 = &emax7[LANE].lmmi[c][(m+1)%EMAX_DEPTH][j][emax7[LANE].lmmio];
  struct lmmi *lmmicp1 = &emax7[LANE].lmmi[c][(i+1)%EMAX_DEPTH][j][emax7[LANE].lmmic];
  Ull dmadr;
  int dmlen;
  Ull dmnxt;
  int dmrw;
  static Ull concat_adr[8][4];
  static int concat_len[8][4];
  if ((phase == 1 && mode == 0) || phase == 2 || phase == 3) {
    lmmc_topz = (lmmicp->top == 0);
    lmmc_ofsz = (lmmicp->ofs == 0);
    lmmo_stat = (lmmiop->v<<3)|(lmmiop->rw<<2)|(lmmiop->f<<1)|(lmmiop->p);
    lmmc_stat =((lmmicp->v & ~lmmicp->hcopy & ~lmmicp->vcopy & ((lmmicp->f&lmmicp->p) | !lmmc_topz))<<3)|(lmmicp->rw<<2)|(lmmicp->f<<1)|(lmmicp->p);
    lmm_ready = (lmmiop->v && lmmiop->blk == lmmicp->blk && lmmiop->len == lmmicp->len && lmmiop->top == lmmicp->top);
    lmm_readz = (lmmiop->v && lmmiop->blk == lmmicp->blk && lmmiop->len == lmmicp->len &&(lmmiop->top+(Sll)(int)lmmiop->ofs) == lmmicp->top);
  }
  if (phase == 1) {
    if (mode==0 && lmmo_stat==12 && !lmm_ready && lmmc_stat!=13 && (emax7[LANE].lmmd[m][j]&1<<c)) { mark=1;emax7[LANE].lmmd[m][j]&=~(1<<c);dmadr=lmmiop->top;dmlen=lmmiop->len;dmnxt=lmmiop1->top;dmrw=1;}
    else if (mode==0 && lmmo_stat==14 && (emax7[LANE].lmmd[m][j]&1<<c)) { mark=1;emax7[LANE].lmmd[m][j]&=~(1<<c);dmadr=lmmiop->top;dmlen=lmmiop->len;dmnxt=lmmiop1->top;dmrw=1;}
    else if (mode==1 && (emax7[LANE].lmmd[i][j]&1<<c)) { mark=1;emax7[LANE].lmmd[i][j]&=~(1<<c);dmadr=lmmicp->top;dmlen=lmmicp->len;dmnxt=lmmicp1->top;dmrw=1;}
    else { mark=0; }
  }
  else if (phase == 2) {
    if ((lmmc_stat== 8 && !lmm_ready)
         || (lmmc_stat== 9 && !lmm_readz)
         || (lmmc_stat==10 )
         || (lmmc_stat==14 )) { mark=1; dmadr=lmmicp->top;dmlen=lmmicp->len;dmnxt=lmmicp1->top;dmrw=0;}
    else { mark=0; }
  }
  else if (phase == 3) {
    if (lmmc_stat== 9 && (lastdist||!lmmc_ofsz)) { mark=1; dmadr=lmmicp->top;dmlen=lmmicp->len; dmrw=0;}
    else if (lmmc_stat==12 || lmmc_stat==14 ) { mark=0; emax7[LANE].lmmd[i][j]|=(1<<c); }
    else if (lmmc_stat==13 ) { mark= emax7[LANE].lmmd[m][j]& (1<<c); emax7[LANE].lmmd[m][j]|=((!lastdist)<<c);dmadr=lmmicp->top;dmlen=lmmicp->len;dmrw=1;}
    else { mark=0; }
  }
  if (mark) {
    if (phase == 1) {
      if ((emax7[LANE].lmmd[(m+1)%EMAX_DEPTH][j]&(1<<c)) && (dmadr+(dmlen+1)*sizeof(Uint)) == dmnxt) {
 if (!concat_adr[LANE][c]) { concat_adr[LANE][c] = dmadr; concat_len[LANE][c] = dmlen; }
 else { concat_len[LANE][c] += dmlen+1; }
 if (concat_len[LANE][c] < 8192) mark = 0;
      }
      else {
 if (concat_adr[LANE][c]) { concat_len[LANE][c] += dmlen+1; }
      }
    }
    else if (phase == 2) {
      if (lmmicp1->v && (dmadr+(dmlen+1)*sizeof(Uint)) == dmnxt) {
 if (!concat_adr[LANE][c]) { concat_adr[LANE][c] = dmadr; concat_len[LANE][c] = dmlen; }
 else { concat_len[LANE][c] += dmlen+1; }
 if (concat_len[LANE][c] < 8192) mark = 0;
      }
      else {
 if (concat_adr[LANE][c]) { concat_len[LANE][c] += dmlen+1; }
      }
    }
  }
  if (mark) {
    emax7[LANE].rw = dmrw;
    if (phase == 1) {
      emax7[LANE].ddraddr = (concat_adr[LANE][c])?concat_adr[LANE][c]:dmadr;
      emax7[LANE].lmmaddr = emax7[LANE].ddraddr;
      emax7[LANE].dmalen = (concat_adr[LANE][c])?concat_len[LANE][c]:dmlen;
    }
    else if (phase == 3 && dmrw==1) {
      emax7[LANE].ddraddr = dmadr+(Sll)(int)lmmicp->ofs;
      emax7[LANE].lmmaddr = emax7[LANE].ddraddr;
      emax7[LANE].dmalen = dmlen;
    }
    else if (phase == 2
   ||(phase == 3 && dmrw==0)) {
      if (lmmicp->blk==0) {
 if (phase == 2) {
   emax7[LANE].ddraddr = (concat_adr[LANE][c])?concat_adr[LANE][c]:dmadr;
   emax7[LANE].lmmaddr = emax7[LANE].ddraddr;
   emax7[LANE].dmalen = (concat_adr[LANE][c])?concat_len[LANE][c]:dmlen;
 }
 else {
   emax7[LANE].ddraddr = dmadr+(Sll)(int)lmmicp->ofs;
   emax7[LANE].lmmaddr = emax7[LANE].ddraddr;
   emax7[LANE].dmalen = dmlen;
 }
 emax7[LANE].blksize = 0;
      }
      else {
 if (phase == 2)
   emax7[LANE].plist = dmadr+emax7[LANE].blkcount*8;
 else
   emax7[LANE].plist = dmadr+emax7[LANE].blkcount*8+(Sll)(int)lmmicp->ofs;
 emax7[LANE].blksize = 32<<lmmicp->blk;
 if (emax7[LANE].blkcount==0) {
   emax7[LANE].lmmblktop = 0;
   emax7[LANE].lmmblklen = dmlen;
 }
 emax7[LANE].ddraddr = emax7[LANE].plist;
 emax7[LANE].lmmaddr = emax7[LANE].lmmblktop;
 emax7[LANE].dmalen = (emax7[LANE].lmmblklen<emax7[LANE].blksize)?emax7[LANE].lmmblklen:emax7[LANE].blksize-1;
 emax7[LANE].lmmblktop += emax7[LANE].blksize*sizeof(Ull);
 emax7[LANE].lmmblklen = (emax7[LANE].lmmblklen<emax7[LANE].blksize)?0:(emax7[LANE].lmmblklen-emax7[LANE].blksize);
 if (emax7[LANE].lmmblklen==0)
   emax7[LANE].blkcount = 0;
 else
   emax7[LANE].blkcount++;
      }
    }
    concat_adr[LANE][c] = 0;
    emax7_kick_dma(LANE, j);
  }
}
emax7_sigwait(int LANE)
{
  int signo;
  if (emax7[LANE].sigwait) {
    *emax7[LANE].sigstat = 2;
    sigwait(emax7[LANE].sigset, &signo);
    *emax7[LANE].sigstat = 1;
  }
}
emax7_kick_dma(int LANE, int j)
{
  int status_mm2s, status_s2mm;
  Ull dst, src;
  Uint pio_words, pio_loop, pio_i, pio_b4, pio_b8, pio_b16, pio_e4, pio_e8, pio_e16;
  if (!emax7[LANE].ddraddr)
    return (0);
  if (j != emax7[LANE].csel_save) {
    ((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].csel = j;
    emax7[LANE].csel_save = j;
  }
  if (1 && emax7[LANE].dmalen > 1) {
    if (emax7[LANE].rw == 0) {
      ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->MM2S_DMACR = 0x00010001;
      *(Ull*)&(((struct dma_ctrl*)emax7[LANE].dma_ctrl)->MM2S_SA) = emax7[LANE].ddraddr-emax_info[LANE].ddr_mmap+emax_info[LANE].ddr_phys;
      ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->MM2S_LENGTH = (emax7[LANE].dmalen+1)*sizeof(Uint);
      ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->S2MM_DMACR = 0x00010001;
      *(Ull*)&(((struct dma_ctrl*)emax7[LANE].dma_ctrl)->S2MM_DA) = emax7[LANE].lmmaddr-emax_info[LANE].ddr_mmap+emax_info[LANE].lmm_phys;
      ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->S2MM_LENGTH = (emax7[LANE].dmalen+1)*sizeof(Uint);
      do {
 status_mm2s = ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->MM2S_DMASR;
 status_s2mm = ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->S2MM_DMASR;
 if ((status_mm2s & 0x71) || (status_s2mm & 0x71)) {
   ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->MM2S_DMACR = 0x00010004;
   printf("emax7_check_lmmi_and_dma(): mem->lmm status_mm2s=%08x, status_s2mm=%8.8x (malfunction)\n", status_mm2s, status_s2mm);
   break;
 }
      } while (!(status_mm2s & 0x2) || !(status_s2mm & 0x2));
      ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->MM2S_DMASR = 0x00001000;
    }
    else {
      while (((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].stat & 0xffff00f0);
      ((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].dmrp = (1LL<<63)|((emax7[LANE].dmalen+1)*sizeof(Uint)<<40)|(emax7[LANE].lmmaddr-emax_info[LANE].ddr_mmap+emax_info[LANE].lmm_phys);
      ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->MM2S_DMACR = 0x00010001;
      *(Ull*)&(((struct dma_ctrl*)emax7[LANE].dma_ctrl)->MM2S_SA) = emax7[LANE].lmmaddr-emax_info[LANE].ddr_mmap+emax_info[LANE].lmm_phys;
      ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->MM2S_LENGTH = (emax7[LANE].dmalen+1)*sizeof(Uint);
      ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->S2MM_DMACR = 0x00010001;
      *(Ull*)&(((struct dma_ctrl*)emax7[LANE].dma_ctrl)->S2MM_DA) = emax7[LANE].ddraddr-emax_info[LANE].ddr_mmap+emax_info[LANE].ddr_phys;
      ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->S2MM_LENGTH = (emax7[LANE].dmalen+1)*sizeof(Uint);
      do {
 status_mm2s = ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->MM2S_DMASR;
 status_s2mm = ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->S2MM_DMASR;
 if ((status_mm2s & 0x71) || (status_s2mm & 0x71)) {
   ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->MM2S_DMACR = 0x00010004;
   printf("emax7_check_lmmi_and_dma(): lmm->mem status_mm2s=%08x, status_s2mm=%8.8x (malfunction)\n", status_mm2s, status_s2mm);
   break;
 }
      } while (!(status_mm2s & 0x2) || !(status_s2mm & 0x2));
      ((struct dma_ctrl*)emax7[LANE].dma_ctrl)->MM2S_DMASR = 0x00001000;
      ((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].dmrp = (0LL<<63);
    }
  }
  else {
    if (emax7[LANE].rw == 0) {
      dst = emax7[LANE].lmmaddr-emax_info[LANE].ddr_mmap+emax_info[LANE].lmm_mmap;
      src = emax7[LANE].ddraddr;
    }
    else {
      dst = emax7[LANE].ddraddr;
      src = emax7[LANE].lmmaddr-emax_info[LANE].ddr_mmap+emax_info[LANE].lmm_mmap;
    }
    pio_words = emax7[LANE].dmalen+1;
    if (src & (sizeof(Ull)-1) & sizeof(Uint)) {
      *(Uint*)dst = *(Uint*)src;
      src += sizeof(Uint);
      dst += sizeof(Uint);
      pio_words--;
    }
    if (pio_words >= 2) {
      if (src & (sizeof(Dll)-1) & sizeof(Ull)) {
 *(Ull*)dst = *(Ull*)src;
 src += sizeof(Ull);
 dst += sizeof(Ull);
 pio_words-=2;
      }
    }
    if (pio_words >= 4) {
      if (pio_loop = pio_words/(sizeof(Dll)/sizeof(Uint))) {
 for(pio_i=0; pio_i<pio_loop; pio_i++)
   *((Dll*)dst + pio_i) = *((Dll*)src + pio_i);
 pio_words -= pio_loop*(sizeof(Dll)/sizeof(Uint));
 src += pio_loop*sizeof(Dll);
 dst += pio_loop*sizeof(Dll);
      }
    }
    if (pio_words >= 2) {
      *(Ull*)dst = *(Ull*)src;
      src += sizeof(Ull);
      dst += sizeof(Ull);
      pio_words-=2;
    }
    if (pio_words >= 1) {
      *(Uint*)dst = *(Uint*)src;
      src += sizeof(Uint);
      dst += sizeof(Uint);
      pio_words--;
    }
  }
  return (0);
}
emax7_pre_with_keep_cache()
{
}
emax7_pre_with_drain_cache()
{
}
void
cex(Uint op_cx, Ull *ex, Ull c3, Ull c2, Ull c1, Ull c0, Ushort pattern)
{
  Uint index1, index0;
  switch (op_cx) {
  case 0x00:
    if (ex)
      *ex = 3;
    break;
  case 0x01:
    index1 = ((c3>>32&1)<<3)|((c2>>32&1)<<2)|((c1>>32&1)<<1)|(c0>>32&1);
    index0 = ((c3 &1)<<3)|((c2 &1)<<2)|((c1 &1)<<1)|(c0 &1);
    *ex = 0;
    if (pattern>>index1&1) *ex |= 2;
    if (pattern>>index0&1) *ex |= 1;
    break;
  default:
    printf("emax7lib: cex: undefined op_cx=%d\n", op_cx);
    break;
  }
}
void
ex4(Uint op_ex1, Ull *d, Ull *r1, Uint exp1, Ull *r2, Uint exp2, Ull *r3, Uint exp3, Uint op_ex2, Ull *r4, Uint op_ex3, Ull *r5)
{
  switch (op_ex1) {
  case 0x08:
    exe(op_ex1, (d+0), (Ull)r1, exp1, *(r2+0), exp2, *(r3+0), exp3, 0x00, (Ull)r4, 0x00, (Ull)r5);
    exe(op_ex1, (d+0), *(d+0), exp1, *(r2+1), exp2, *(r3+1), exp3, 0x00, (Ull)r4, 0x00, (Ull)r5);
    exe(op_ex1, (d+0), *(d+0), exp1, *(r2+2), exp2, *(r3+2), exp3, 0x00, (Ull)r4, 0x00, (Ull)r5);
    exe(op_ex1, (d+0), *(d+0), exp1, *(r2+3), exp2, *(r3+3), exp3, 0x00, (Ull)r4, 0x00, (Ull)r5);
    break;
  case 0x00:
  case 0x0a:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
    exe(op_ex1, (d+0), *(r1+0), exp1, *(r2+0), exp2, *(r3+0), exp3, 0x00, 0LL, 0x00, 0LL);
    exe(op_ex1, (d+1), *(r1+1), exp1, *(r2+1), exp2, *(r3+1), exp3, 0x00, 0LL, 0x00, 0LL);
    exe(op_ex1, (d+2), *(r1+2), exp1, *(r2+2), exp2, *(r3+2), exp3, 0x00, 0LL, 0x00, 0LL);
    exe(op_ex1, (d+3), *(r1+3), exp1, *(r2+3), exp2, *(r3+3), exp3, 0x00, 0LL, 0x00, 0LL);
    break;
  default:
    printf("emax7lib: ex4: undefined op_ex1=%d\n", op_ex1);
    break;
  }
  switch (op_ex2) {
  case 0x00:
    break;
  default:
    printf("emax7lib: ex4: illegal op_ex2=%d\n", op_ex2);
    break;
  }
  switch (op_ex3) {
  case 0x00:
    break;
  default:
    printf("emax7lib: ex4: illegal op_ex3=%d\n", op_ex3);
    break;
  }
}
int convf32tou7(Uchar *out, float in)
{
  f32bit in_f32;
  wu7bit out_u7;
  *(float*)&in_f32 = in;
  out_u7.s = in_f32.s;
  out_u7.b = 0;
  in = ((in)> 0 ? (in) :-(in) );
  if (in >= 1.0) out_u7.e = 63;
  else out_u7.e = in*64;
  *out = *(Uchar*)&out_u7;
}
int convf32tou8(Uchar *out, float in)
{
  f32bit in_f32;
  wu8bit out_u8;
  *(float*)&in_f32 = in;
  out_u8.s = in_f32.s;
  in = ((in)> 0 ? (in) :-(in) );
  if (in >= 2.0) out_u8.e = 127;
  else out_u8.e = in*64;
  *out = *(Uchar*)&out_u8;
}
int convu8tof32(float *out, Uchar in)
{
  wu8bit in_u8;
  f32bit out_f32;
  *(Uchar*)&in_u8 = in;
  *(float*)&out_f32 = (float)in_u8.e/64;
  out_f32.s = in_u8.s;
  *out = *(float*)&out_f32;
}
Ull urand(int no)
{
  static Ull urand_seed[8]
    = {0xc3c3c3c3a5a5a5a5LL, 0x123456789abcdef0LL, 0xe1e1e1e1d4d4d4d4LL, 0x8888777766665555LL,
       0x8787878796969696LL, 0xfedcba9876543210LL, 0x5a5a5a5a3c3c3c3cLL, 0xbbbbccccddddeeeeLL};
  Ull retval = urand_seed[no];
  urand_seed[no] ^= (urand_seed[no]<<29);
  urand_seed[no] ^= (urand_seed[no]>>27);
  urand_seed[no] ^= (urand_seed[no]<<37);
  return (retval);
}
Ull shfl(Ull in, Ull r)
{
  int i;
  for (i=0; i<32; i++) {
    if (r&(1LL<<(i+16)))
      in = (in&~(1LL<<(i+32)|1LL<<i)) | (in>>i&1)<<(i+32) | (in>>(i+32)&1)<<i;
  }
  for (i=0; i<48; i++) {
    if (r&(1LL<<(i+8)))
      in = (in&~(1LL<<(i+16)|1LL<<i)) | (in>>i&1)<<(i+16) | (in>>(i+16)&1)<<i;
  }
  for (i=0; i<56; i++) {
    if (r&(1LL<<(i+4)))
      in = (in&~(1LL<<(i+ 8)|1LL<<i)) | (in>>i&1)<<(i+ 8) | (in>>(i+ 8)&1)<<i;
  }
  for (i=0; i<60; i++) {
    if (r&(1LL<<(i+2)))
      in = (in&~(1LL<<(i+ 4)|1LL<<i)) | (in>>i&1)<<(i+ 4) | (in>>(i+ 4)&1)<<i;
  }
  for (i=0; i<62; i++) {
    if (r&(1LL<<(i+1)))
      in = (in&~(1LL<<(i+ 2)|1LL<<i)) | (in>>i&1)<<(i+ 2) | (in>>(i+ 2)&1)<<i;
  }
  for (i=0; i<63; i++) {
    if (r&(1LL<<(i+0)))
      in = (in&~(1LL<<(i+ 1)|1LL<<i)) | (in>>i&1)<<(i+ 1) | (in>>(i+ 1)&1)<<i;
  }
  return(in);
}
int enable_x11;
void x11_softu64_dist(float, float);
int softu64(int stage, Ull *o1, Ull *o2, Ull *o3, Ull r1, Ull r2, Ull r3, Ull r4)
{
  int i, j;
  Ull u[8];
  Ull ss[8];
  Ull s2[8], s3[8];
  int pc, nc;
  int os, oc;
  switch (stage) {
  case 1:
    for (i=0; i<8; i++)
      u[i] = urand(i);
    for (i=0; i<8; i++) {
      ss[i] = (r2>>(i*8+7))&1 ^ (r3>>(i*8+7))&1;
  int s2e = (r2>>(i*8))&0x7f; s2e = s2e<15?s2e:15;
  int s3e = (r3>>(i*8))&0x7f; s3e = s3e<15?s3e:15;
      s2[i] = 0LL;
      s3[i] = 0LL;
      for (j=0; j<12; j++) {
 int k = j * 4;
 s2[i] |= ((u[(i+0)%8]>>k&15)<=s2e)<<j;
 s3[i] |= ((u[(i+1)%8]>>k&15)<=s3e)<<j;
      }
      o1[i] = s2[i] & s3[i];
      o1[i] = ss[i]<<63|(o1[i]&0x7fffffffffffffffLL);
    }
    break;
  case 2:
    pc = 0;
    nc = 0;
    for (j=0; j<12; j++) {
      for (i=0; i<8; i++) {
 if (!(o1[i]>>63)) pc += (o1[i] & (1LL<<j))!=0;
 else nc += (o1[i] & (1LL<<j))!=0;
      }
    }
    pc = pc>>r4;
    nc = nc>>r4;
    *o2 = (Ull)(pc&0xffff)<<32 | (Ull)(nc&0xffff);
    break;
  case 3:
    pc = *o2>>32&0xffff;
    nc = *o2 &0xffff;
    if (!(r1&0x80)) pc += (r1&0x7f);
    else nc += (r1&0x7f);
    if (pc >= nc) {
      os = 0x00;
      oc = pc-nc;
    }
    else {
      os = 0x80;
      oc = nc-pc;
    }
    if (oc >= 128) oc = 127;
    *o3 = os|oc;
    break;
  }
  return (0);
}
Ull __attribute__((always_inline))
exm(Ull s, Uchar exp)
{
  switch (exp) {
  case 0: return ( s );
  case 1: return ((s<<32&0xffffffff00000000LL) | (s &0x00000000ffffffffLL));
  case 2: return ((s &0xffffffff00000000LL) | (s>>32&0x00000000ffffffffLL));
  case 4: return ((s>> 8&0x00ff000000ff0000LL) | (s>>16&0x000000ff000000ffLL));
  case 3: return ((s<< 8&0x00ff000000ff0000LL) | (s &0x000000ff000000ffLL));
  default: return ( s );
  }
}
int
exe(Uint op_ex1, Ull *d, Ull s1, Uint exp1, Ull s2, Uint exp2, Ull s3, Uint exp3, Uint op_ex2, Ull r4, Uint op_ex3, Ull r5)
{
  union { Uint i; float f; } f3, f2, f1, f0;
  Ull r1, r2, r3;
  Ull t3, t2, t1, t0;
  Ull ro00, ro01, ro02, ro10, ro11, ro12;
  Ull c1, c0;
  Ull ex1_outd;
  Ull ex1_outd_sfma[8];
  Ull ex2_outd;
  int retval = 0;
  float convi4f32[16] = {-8.0, -7.0, -6.0, -5.0, -4.0, -3.0, -2.0, -1.0, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
  r1 = exm(s1, exp1);
  r2 = exm(s2, exp2);
  r3 = exm(s3, exp3);
  switch (op_ex1) {
  case 0x00:
    ex1_outd = r1;
    break;
  case 0x01:
    t0 = (r1&0x00000000ffffffffLL)+(r2&0x00000000ffffffffLL);
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = t0;
    if (t0==0) retval = 1;
    break;
  case 0x02:
    t0 = (r1&0x00000000ffffffffLL)+(r2&0x00000000ffffffffLL);
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = t0;
    if (t0==0) retval = 1;
    break;
  case 0x08:
    softu64(1, ex1_outd_sfma, ((void *)0), ((void *)0), r1, r2, r3, r4);
    break;
  case 0x0a:
    f1.i = (Uint)(r1);
    f2.i = (Uint)(r2>>32);
    f3.i = (Uint)(r3>>32);
    if (f2.i != -1 && f2.i == f3.i) {
      f2.i = (Uint)(r2);
      f3.i = (Uint)(r3);
      f0.f = f1.f + (f2.f * f3.f);
    }
    else {
      f0.f = f1.f;
    }
    t0 = f0.i;
    ex1_outd = t0;
    break;
  case 0x10:
  case 0x11:
    f1.i = (Uint)(r1>>32);
    f2.i = (Uint)(r2>>32)^(op_ex1==0x10?0:0x80000000);
    f3.i = (Uint)(r3>>32);
    f0.f = f1.f + (f2.f * f3.f);
    t2 = f0.i;
    f1.i = (Uint)(r1);
    f2.i = (Uint)(r2)^(op_ex1==0x10?0:0x80000000);
    f3.i = (Uint)(r3);
    f0.f = f1.f + (f2.f * f3.f);
    t0 = f0.i;
    ex1_outd = (t2<<32)|(t0);
    break;
  case 0x12:
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
  case 0x13:
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
  case 0x14:
    f1.i = (Uint)(r1>>32);
    f2.i = (Uint)(r2>>32);
    f3.i = (Uint)(r3>>32);
    f0.f = f1.f * convi4f32[(f2.i>>((f3.i&7)*4))&0xf];
    t2 = f0.i;
    f1.i = (Uint)(r1);
    f2.i = (Uint)(r2);
    f3.i = (Uint)(r3);
    f0.f = f1.f * convi4f32[(f2.i>>((f3.i&7)*4))&0xf];
    t0 = f0.i;
    ex1_outd = (t2<<32)|(t0);
    break;
  case 0x15:
    t2 = (r1>>32&0x00000000ffffffffLL)+((r2>>32&0x00000000ffffffffLL)+(r3>>32&0x00000000ffffffffLL));
    t2 &= 0x00000000ffffffffLL;
    t0 = (r1 &0x00000000ffffffffLL)+((r2 &0x00000000ffffffffLL)+(r3 &0x00000000ffffffffLL));
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = (t2<<32)|(t0);
    break;
  case 0x16:
    t2 = (r1>>32&0x00000000ffffffffLL)-((r2>>32&0x00000000ffffffffLL)+(r3>>32&0x00000000ffffffffLL));
    t2 &= 0x00000000ffffffffLL;
    t0 = (r1 &0x00000000ffffffffLL)-((r2 &0x00000000ffffffffLL)+(r3 &0x00000000ffffffffLL));
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = (t2<<32)|(t0);
    break;
  case 0x17:
    t2 = (r1>>32&0x00000000ffffffffLL)+(r2>>32&0x00000000ffffffffLL);
    t2 &= 0x00000000ffffffffLL;
    t0 = (r1 &0x00000000ffffffffLL)+(r2 &0x00000000ffffffffLL);
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = (t2<<32)|(t0);
    break;
  case 0x18:
    t2 = (r1>>32&0x00000000ffffffffLL)-(r2>>32&0x00000000ffffffffLL);
    t2 &= 0x00000000ffffffffLL;
    t0 = (r1 &0x00000000ffffffffLL)-(r2 &0x00000000ffffffffLL);
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = (t2<<32)|(t0);
    break;
  case 0x19:
    c1 = (r1>>32&0x00000000ffffffffLL) == (r2>>32&0x00000000ffffffffLL);
    c0 = (r1 &0x00000000ffffffffLL) == (r2 &0x00000000ffffffffLL);
    ex1_outd = (c1<<32)|c0;
    break;
  case 0x1a:
    c1 = (r1>>32&0x00000000ffffffffLL) != (r2>>32&0x00000000ffffffffLL);
    c0 = (r1 &0x00000000ffffffffLL) != (r2 &0x00000000ffffffffLL);
    ex1_outd = (c1<<32)|c0;
    break;
  case 0x1b:
    c1 = (r1>>32&0x00000000ffffffffLL) < (r2>>32&0x00000000ffffffffLL);
    c0 = (r1 &0x00000000ffffffffLL) < (r2 &0x00000000ffffffffLL);
    ex1_outd = (c1<<32)|c0;
    break;
  case 0x1c:
    c1 = (r1>>32&0x00000000ffffffffLL) <= (r2>>32&0x00000000ffffffffLL);
    c0 = (r1 &0x00000000ffffffffLL) <= (r2 &0x00000000ffffffffLL);
    ex1_outd = (c1<<32)|c0;
    break;
  case 0x1d:
    c1 = (r1>>32&0x00000000ffffffffLL) > (r2>>32&0x00000000ffffffffLL);
    c0 = (r1 &0x00000000ffffffffLL) > (r2 &0x00000000ffffffffLL);
    ex1_outd = (c1<<32)|c0;
    break;
  case 0x1e:
    c1 = (r1>>32&0x00000000ffffffffLL) >= (r2>>32&0x00000000ffffffffLL);
    c0 = (r1 &0x00000000ffffffffLL) >= (r2 &0x00000000ffffffffLL);
    ex1_outd = (c1<<32)|c0;
    break;
  case 0x1f:
    c1 = r1>>32&1;
    c0 = r1 &1;
    t2 = c1 ? (r2&0xffffffff00000000LL) : (r3&0xffffffff00000000LL);
    t0 = c0 ? (r2&0x00000000ffffffffLL) : (r3&0x00000000ffffffffLL);
    ex1_outd = t2 | t0;
    break;
  case 0x20:
    t3 = (r1>>48&0x000000000000ffffLL)+((r2>>48&0x000000000000ffffLL)+(r3>>48&0x000000000000ffffLL));
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t2 = (r1>>32&0x000000000000ffffLL)+((r2>>32&0x000000000000ffffLL)+(r3>>32&0x000000000000ffffLL));
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t1 = (r1>>16&0x000000000000ffffLL)+((r2>>16&0x000000000000ffffLL)+(r3>>16&0x000000000000ffffLL));
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    t0 = (r1 &0x000000000000ffffLL)+((r2 &0x000000000000ffffLL)+(r3 &0x000000000000ffffLL));
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case 0x21:
    t3 = (r1>>48&0x000000000000ffffLL)+(r2>>48&0x000000000000ffffLL);
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t2 = (r1>>32&0x000000000000ffffLL)+(r2>>32&0x000000000000ffffLL);
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t1 = (r1>>16&0x000000000000ffffLL)+(r2>>16&0x000000000000ffffLL);
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    t0 = (r1 &0x000000000000ffffLL)+(r2 &0x000000000000ffffLL);
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case 0x22:
    t3 = (r1>>48&0x000000000000ffffLL)-((r2>>48&0x000000000000ffffLL)+(r3>>48&0x000000000000ffffLL));
    if (t3 > 0x000000000000ffffLL) t3 = 0x0000000000000000LL;
    t2 = (r1>>32&0x000000000000ffffLL)-((r2>>32&0x000000000000ffffLL)+(r3>>32&0x000000000000ffffLL));
    if (t2 > 0x000000000000ffffLL) t2 = 0x0000000000000000LL;
    t1 = (r1>>16&0x000000000000ffffLL)-((r2>>16&0x000000000000ffffLL)+(r3>>16&0x000000000000ffffLL));
    if (t1 > 0x000000000000ffffLL) t1 = 0x0000000000000000LL;
    t0 = (r1 &0x000000000000ffffLL)-((r2 &0x000000000000ffffLL)+(r3 &0x000000000000ffffLL));
    if (t0 > 0x000000000000ffffLL) t0 = 0x0000000000000000LL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case 0x23:
    t3 = (r1>>48&0x000000000000ffffLL)-(r2>>48&0x000000000000ffffLL);
    if (t3 > 0x000000000000ffffLL) t3 = 0x0000000000000000LL;
    t2 = (r1>>32&0x000000000000ffffLL)-(r2>>32&0x000000000000ffffLL);
    if (t2 > 0x000000000000ffffLL) t2 = 0x0000000000000000LL;
    t1 = (r1>>16&0x000000000000ffffLL)-(r2>>16&0x000000000000ffffLL);
    if (t1 > 0x000000000000ffffLL) t1 = 0x0000000000000000LL;
    t0 = (r1 &0x000000000000ffffLL)-(r2 &0x000000000000ffffLL);
    if (t0 > 0x000000000000ffffLL) t0 = 0x0000000000000000LL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case 0x24:
    t3 = (r1>>48&0x00000000000007ffLL)*(r2&0x00000000000001ffLL);
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t2 = (r1>>32&0x00000000000007ffLL)*(r2&0x00000000000001ffLL);
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t1 = (r1>>16&0x00000000000007ffLL)*(r2&0x00000000000001ffLL);
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    t0 = (r1 &0x00000000000007ffLL)*(r2&0x00000000000001ffLL);
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case 0x25:
    ex1_outd = ((r1&0x000000ff00000000LL)<<24) | ((r2&0x000000ff00000000LL)<<16) | ((r3&0x000000ff00000000LL)<<8)
             | ((r1&0x00000000000000ffLL)<<24) | ((r2&0x00000000000000ffLL)<<16) | ((r3&0x00000000000000ffLL)<<8);
    break;
  case 0x26:
    t3 = (r1>>48&0x000000000000ffffLL) + ((r2>>56&0x00000000000000ffLL)<(r3>>56&0x00000000000000ffLL)?(r3>>56&0x00000000000000ffLL)-(r2>>56&0x00000000000000ffLL):(r2>>56&0x00000000000000ffLL)-(r3>>56&0x00000000000000ffLL)) + ((r2>>48&0x00000000000000ffLL)<(r3>>48&0x00000000000000ffLL)?(r3>>48&0x00000000000000ffLL)-(r2>>48&0x00000000000000ffLL):(r2>>48&0x00000000000000ffLL)-(r3>>48&0x00000000000000ffLL));
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t2 = (r1>>32&0x000000000000ffffLL) + ((r2>>40&0x00000000000000ffLL)<(r3>>40&0x00000000000000ffLL)?(r3>>40&0x00000000000000ffLL)-(r2>>40&0x00000000000000ffLL):(r2>>40&0x00000000000000ffLL)-(r3>>40&0x00000000000000ffLL)) + ((r2>>32&0x00000000000000ffLL)<(r3>>32&0x00000000000000ffLL)?(r3>>32&0x00000000000000ffLL)-(r2>>32&0x00000000000000ffLL):(r2>>32&0x00000000000000ffLL)-(r3>>32&0x00000000000000ffLL));
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t1 = (r1>>16&0x000000000000ffffLL) + ((r2>>24&0x00000000000000ffLL)<(r3>>24&0x00000000000000ffLL)?(r3>>24&0x00000000000000ffLL)-(r2>>24&0x00000000000000ffLL):(r2>>24&0x00000000000000ffLL)-(r3>>24&0x00000000000000ffLL)) + ((r2>>16&0x00000000000000ffLL)<(r3>>16&0x00000000000000ffLL)?(r3>>16&0x00000000000000ffLL)-(r2>>16&0x00000000000000ffLL):(r2>>16&0x00000000000000ffLL)-(r3>>16&0x00000000000000ffLL));
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    t0 = (r1 &0x000000000000ffffLL) + ((r2>> 8&0x00000000000000ffLL)<(r3>> 8&0x00000000000000ffLL)?(r3>> 8&0x00000000000000ffLL)-(r2>> 8&0x00000000000000ffLL):(r2>> 8&0x00000000000000ffLL)-(r3>> 8&0x00000000000000ffLL)) + ((r2 &0x00000000000000ffLL)<(r3 &0x00000000000000ffLL)?(r3 &0x00000000000000ffLL)-(r2 &0x00000000000000ffLL):(r2 &0x00000000000000ffLL)-(r3 &0x00000000000000ffLL));
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case 0x27:
    t3 = ((r1>>56&0x00000000000000ffLL)<(r2>>56&0x00000000000000ffLL)?(r2>>56&0x00000000000000ffLL)-(r1>>56&0x00000000000000ffLL):(r1>>56&0x00000000000000ffLL)-(r2>>56&0x00000000000000ffLL)) + ((r1>>48&0x00000000000000ffLL)<(r2>>48&0x00000000000000ffLL)?(r2>>48&0x00000000000000ffLL)-(r1>>48&0x00000000000000ffLL):(r1>>48&0x00000000000000ffLL)-(r2>>48&0x00000000000000ffLL));
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t2 = ((r1>>40&0x00000000000000ffLL)<(r2>>40&0x00000000000000ffLL)?(r2>>40&0x00000000000000ffLL)-(r1>>40&0x00000000000000ffLL):(r1>>40&0x00000000000000ffLL)-(r2>>40&0x00000000000000ffLL)) + ((r1>>32&0x00000000000000ffLL)<(r2>>32&0x00000000000000ffLL)?(r2>>32&0x00000000000000ffLL)-(r1>>32&0x00000000000000ffLL):(r1>>32&0x00000000000000ffLL)-(r2>>32&0x00000000000000ffLL));
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t1 = ((r1>>24&0x00000000000000ffLL)<(r2>>24&0x00000000000000ffLL)?(r2>>24&0x00000000000000ffLL)-(r1>>24&0x00000000000000ffLL):(r1>>24&0x00000000000000ffLL)-(r2>>24&0x00000000000000ffLL)) + ((r1>>16&0x00000000000000ffLL)<(r2>>16&0x00000000000000ffLL)?(r2>>16&0x00000000000000ffLL)-(r1>>16&0x00000000000000ffLL):(r1>>16&0x00000000000000ffLL)-(r2>>16&0x00000000000000ffLL));
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    t0 = ((r1>> 8&0x00000000000000ffLL)<(r2>> 8&0x00000000000000ffLL)?(r2>> 8&0x00000000000000ffLL)-(r1>> 8&0x00000000000000ffLL):(r1>> 8&0x00000000000000ffLL)-(r2>> 8&0x00000000000000ffLL)) + ((r1 &0x00000000000000ffLL)<(r2 &0x00000000000000ffLL)?(r2 &0x00000000000000ffLL)-(r1 &0x00000000000000ffLL):(r1 &0x00000000000000ffLL)-(r2 &0x00000000000000ffLL));
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case 0x28:
    t3 = r3>>48&0x000000000000ffffLL;
    t2 = r3>>32&0x000000000000ffffLL;
    t1 = r3>>16&0x000000000000ffffLL;
    t0 = r3 &0x000000000000ffffLL;
    if (t3<t2) t2 = (r1&0xffff000000000000LL)|(r3>>16&0x0000ffff00000000LL);
    else t2 = (r2&0xffff000000000000LL)|(r3 &0x0000ffff00000000LL);
    if (t1<t0) t0 = (r1&0x00000000ffff0000LL)|(r3>>16&0x000000000000ffffLL);
    else t0 = (r2&0x00000000ffff0000LL)|(r3 &0x000000000000ffffLL);
    ex1_outd = t2 | t0;
    break;
  case 0x29:
    if ((r1&0x0000ffff00000000LL)<(r2&0x0000ffff00000000LL)) t2 = r1&0xffffffff00000000LL;
    else t2 = r2&0xffffffff00000000LL;
    if ((r1&0x000000000000ffffLL)<(r2&0x000000000000ffffLL)) t0 = r1&0x00000000ffffffffLL;
    else t0 = r2&0x00000000ffffffffLL;
    ex1_outd = t2 | t0;
   break;
  case 0x2a:
    ex1_outd = (((r1>>48&0x000000000000ff00LL) ? 255 : (r1>>48&0x00000000000000ffLL))<<56)
             | (((r1>>32&0x000000000000ff00LL) ? 255 : (r1>>32&0x00000000000000ffLL))<<48)
             | (((r2>>48&0x000000000000ff00LL) ? 255 : (r2>>48&0x00000000000000ffLL))<<40)
             | (((r2>>32&0x000000000000ff00LL) ? 255 : (r2>>32&0x00000000000000ffLL))<<32)
             | (((r1>>16&0x000000000000ff00LL) ? 255 : (r1>>16&0x00000000000000ffLL))<<24)
             | (((r1 &0x000000000000ff00LL) ? 255 : (r1 &0x00000000000000ffLL))<<16)
             | (((r2>>16&0x000000000000ff00LL) ? 255 : (r2>>16&0x00000000000000ffLL))<< 8)
             | (((r2 &0x000000000000ff00LL) ? 255 : (r2 &0x00000000000000ffLL)) );
    break;
  case 0x2b:
    t2 = ((r1&0x0000ffff00000000LL)<(r2&0x0000ffff00000000LL))?0:0x000000ff00000000LL;
    t0 = ((r1&0x000000000000ffffLL)<(r2&0x000000000000ffffLL))?0:0x00000000000000ffLL;
    ex1_outd = t2 | t0;
    break;
  case 0x2c:
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
  case 0x2d:
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
  case 0x2e:
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
  case 0x2f:
    ex1_outd = ((r1&0xff00000000000000LL)>(r2&0xff00000000000000LL)?(r1&0xff00000000000000LL):(r2&0xff00000000000000LL))
             | ((r1&0x00ff000000000000LL)>(r2&0x00ff000000000000LL)?(r1&0x00ff000000000000LL):(r2&0x00ff000000000000LL))
             | ((r1&0x0000ff0000000000LL)>(r2&0x0000ff0000000000LL)?(r1&0x0000ff0000000000LL):(r2&0x0000ff0000000000LL))
             | ((r1&0x000000ff00000000LL)>(r2&0x000000ff00000000LL)?(r1&0x000000ff00000000LL):(r2&0x000000ff00000000LL))
             | ((r1&0x00000000ff000000LL)>(r2&0x00000000ff000000LL)?(r1&0x00000000ff000000LL):(r2&0x00000000ff000000LL))
             | ((r1&0x0000000000ff0000LL)>(r2&0x0000000000ff0000LL)?(r1&0x0000000000ff0000LL):(r2&0x0000000000ff0000LL))
             | ((r1&0x000000000000ff00LL)>(r2&0x000000000000ff00LL)?(r1&0x000000000000ff00LL):(r2&0x000000000000ff00LL))
             | ((r1&0x00000000000000ffLL)>(r2&0x00000000000000ffLL)?(r1&0x00000000000000ffLL):(r2&0x00000000000000ffLL));
    break;
  case 0x30:
    ex1_outd = ((r1&0xff00000000000000LL)<(r2&0xff00000000000000LL)?(r1&0xff00000000000000LL):(r2&0xff00000000000000LL))
             | ((r1&0x00ff000000000000LL)<(r2&0x00ff000000000000LL)?(r1&0x00ff000000000000LL):(r2&0x00ff000000000000LL))
             | ((r1&0x0000ff0000000000LL)<(r2&0x0000ff0000000000LL)?(r1&0x0000ff0000000000LL):(r2&0x0000ff0000000000LL))
             | ((r1&0x000000ff00000000LL)<(r2&0x000000ff00000000LL)?(r1&0x000000ff00000000LL):(r2&0x000000ff00000000LL))
             | ((r1&0x00000000ff000000LL)<(r2&0x00000000ff000000LL)?(r1&0x00000000ff000000LL):(r2&0x00000000ff000000LL))
             | ((r1&0x0000000000ff0000LL)<(r2&0x0000000000ff0000LL)?(r1&0x0000000000ff0000LL):(r2&0x0000000000ff0000LL))
             | ((r1&0x000000000000ff00LL)<(r2&0x000000000000ff00LL)?(r1&0x000000000000ff00LL):(r2&0x000000000000ff00LL))
             | ((r1&0x00000000000000ffLL)<(r2&0x00000000000000ffLL)?(r1&0x00000000000000ffLL):(r2&0x00000000000000ffLL));
    break;
  case 0x31:
    ex1_outd = (r1&0xffffffff00000000LL) | (((r1 & r2)^(r1 & r3)^(r2 & r3))&0xffffffffLL);
    break;
  case 0x32:
    ex1_outd = (r1&0xffffffff00000000LL) | (((r1 & r2)^(~r1 & r3))&0xffffffffLL);
    break;
  default:
    printf("emax7lib: exe: undefined op_ex1=%d\n", op_ex1);
    break;
  }
  switch (op_ex2) {
  case 0x00:
    if (op_ex1 == 0x08)
      softu64(2, ex1_outd_sfma, &ex2_outd, ((void *)0), r1, r2, r3, r4);
    else
      ex2_outd = ex1_outd;
    break;
  case 0x01:
    ex2_outd = ex1_outd & r4;
    break;
  case 0x02:
    ex2_outd = ex1_outd | r4;
    break;
  case 0x03:
    ex2_outd = ex1_outd ^ r4;
    break;
  case 0x04:
    t3 = ex1_outd>>48&0x000000000000ffffLL;
    t2 = ex1_outd>>32&0x000000000000ffffLL;
    t1 = ex1_outd>>16&0x000000000000ffffLL;
    t0 = ex1_outd &0x000000000000ffffLL;
    t3 += t2;
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t1 += t0;
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    ex2_outd = (t3<<48)|(t1<<16);
    break;
  case 0x05:
    t3 = ex1_outd>>48&0x000000000000ffffLL;
    t2 = ex1_outd>>32&0x000000000000ffffLL;
    t1 = ex1_outd>>16&0x000000000000ffffLL;
    t0 = ex1_outd &0x000000000000ffffLL;
    t2 += t3;
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t0 += t1;
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex2_outd = (t2<<32)|(t0);
    break;
  case 0x07:
    t2 = ex1_outd & 0xffffffff00000000LL;
    ro10 = r4>>32 & 0xff;
    ro11 = r4>>40 & 0xff;
    ro12 = r4>>48 & 0xff;
    t0 = ex1_outd & 0x00000000ffffffffLL;
    ro00 = r4 & 0xff;
    ro01 = r4>> 8 & 0xff;
    ro02 = r4>>16 & 0xff;
    ex2_outd = (((t2>>ro12|t2<<(32-ro12))^(t2>>ro11|t2<<(32-ro11))^(t2>>ro10|t2<<(32-ro10)))&0xffffffff00000000LL)
              |(((t0>>ro02|t0<<(32-ro02))^(t0>>ro01|t0<<(32-ro01))^(t0>>ro00|t0<<(32-ro00)))&0x00000000ffffffffLL);
    break;
  default:
    printf("emax7lib: exe: undefined op_ex2=%d\n", op_ex2);
    break;
  }
  switch (op_ex3) {
  case 0x00:
    if (op_ex1 == 0x08)
      softu64(3, ((void *)0), &ex2_outd, d, r1, r2, r3, r4);
    else
      if (d) *d = ex2_outd;
    break;
  case 0x01:
    t1 = (Ull)(ex2_outd &0xffffffff00000000LL)<<r5;
    t0 = (Ull)(ex2_outd<<r5&0x00000000ffffffffLL);
    if (d) *d = t1 | t0;
    break;
  case 0x02:
    t1 = (Ull)(ex2_outd>>r5&0xffffffff00000000LL);
    t0 = (Ull)(ex2_outd &0x00000000ffffffffLL)>>r5;
    if (d) *d = t1 | t0;
    break;
  case 0x03:
    t1 = (Sll)(ex2_outd )>>r5&0xffffffff00000000LL;
    t0 = (Sll)(ex2_outd<<32)>>r5&0xffffffff00000000LL;
    if (d) *d = t1 | (t0>>32);
    break;
  case 0x04:
    t1 = (Sll)(ex2_outd<< 8)>>(r5+8)&0xffffffff00000000LL;
    t0 = (Sll)(ex2_outd<<40)>>(r5+8)&0xffffffff00000000LL;
    if (d) *d = t1 | (t0>>32);
    break;
  case 0x07:
    t3 = (Ull)(ex2_outd )>>r5&0xffff000000000000LL;
    t2 = (Ull)(ex2_outd<<16)>>r5&0xffff000000000000LL;
    t1 = (Ull)(ex2_outd<<32)>>r5&0xffff000000000000LL;
    t0 = (Ull)(ex2_outd<<48)>>r5&0xffff000000000000LL;
    if (d) *d = t3 | (t2>>16) | (t1>>32) | (t0>>48);
    break;
  default:
    printf("emax7lib: exe: undefined op_ex3=%d\n", op_ex3);
    break;
  }
  return (retval);
}
void
mex(Uint op_mex2, Uchar **d2, Uchar *base2, Ull ofs2, Uint op_mex1, Uchar **d1, Uchar *base1, Ull ofs1, Ull limit, Ull s2, Ull s1)
{
  Uint limit2 = limit*2;
  Uint ss2 = s2>>32;
  Uint ss1 = s1>>32;
  switch (op_mex1) {
  case 0x00:
    *d1 = base1;
    break;
  case 1:
    *d1 = base1 + ofs1;
    break;
  case 3:
    if (!limit)
      *d1 = base1 + ((ss1!=0xffffffff && ss2>=ss1) ? ofs1:0);
    else {
      if ((base2==limit && base1+ofs1==limit2)||(base2+ofs2==limit && base1==limit2))
 *d1 = limit;
      else
 *d1 = base1 + (base1!=limit2 && ((base2!=limit && ss2>=ss1)||base2==limit ) ? ofs1:0);
    }
    break;
  default:
    printf("emax7lib: mex: undefined op_mex1=%d\n", op_mex1);
    break;
  }
  switch (op_mex2) {
  case 0x00:
    *d2 = base2;
    break;
  case 1:
    *d2 = base2 + ofs2;
    break;
  case 2:
    if (!limit)
      *d2 = base2 + ((ss2!=0xffffffff && ss2<=ss1) ? ofs2:0);
    else {
      if ((base2==limit && base1+ofs1==limit2)||(base2+ofs2==limit && base1==limit2))
 *d2 = 0;
      else
 *d2 = base2 + (base2!=limit && ((base1!=limit2 && ss2<=ss1)||base1==limit2) ? ofs2:0);
    }
    break;
  default:
    printf("emax7lib: mex: undefined op_mex2=%d\n", op_mex2);
    break;
  }
}
Ull __attribute__((always_inline))
eam(Ull ofs, Uchar msk)
{
  switch (msk) {
  case 14: return (ofs);
  case 13: return (ofs>>32);
  case 12: return (ofs&0x00000000ffffffffLL);
  case 11: return (ofs>>48&0x000000000000ffffLL);
  case 10: return (ofs>>32&0x000000000000ffffLL);
  case 9: return (ofs>>16&0x000000000000ffffLL);
  case 8: return (ofs&0x000000000000ffffLL);
  case 7: return (ofs>>56&0x00000000000000ffLL);
  case 6: return (ofs>>48&0x00000000000000ffLL);
  case 5: return (ofs>>40&0x00000000000000ffLL);
  case 4: return (ofs>>32&0x00000000000000ffLL);
  case 3: return (ofs>>24&0x00000000000000ffLL);
  case 2: return (ofs>>16&0x00000000000000ffLL);
  case 1: return (ofs>>8&0x00000000000000ffLL);
  case 0: return (ofs&0x00000000000000ffLL);
  default: printf("emax7lib: eag: undefined msk=%d\n", msk); return (0LL);;
  }
}
void
eag(Ull *adr, Ull base, Ull ofs)
{
  *adr = base + ofs;
}
void
mop(Uint op_mm, Ull ex, Ull *d, Ull base, Ull offset, Uchar msk, Ull top, Uint len, Uint blk, Uchar force, Ull ptop, Uint plen)
{
  Ull adr, ofs;
  eag(&adr, base, eam(offset, msk));
  mmp(op_mm, ex, d, adr, top, len, blk);
}
void
mo4(Uint op_mm, Ull ex, Ull *d, Ull base, Ull offset, Uchar msk, Ull top, Uint len, Uint blk, Uchar force, Ull ptop, Uint plen)
{
  Ull adr, ofs;
  eag(&adr, base, eam(offset, msk));
  mmp(op_mm, ex, d, adr, top, len, blk);
}
int emax7_unaligned_load_valid;
Ull emax7_unaligned_load_high;
void
mmp(Uint op_mm, Ull ex, Ull *d, Ull adr, Ull top, Uint len, Uint blk)
{
  Ull c1, c0, load64;
  if (!((op_mm==0x08 && blk) || op_mm==0x19 || op_mm==0x1a) && (!adr || !top)) return;
  if (!((op_mm==0x08 && blk) || op_mm==0x19 || op_mm==0x1a) && ex && len && (adr < top || adr >= top+len*sizeof(Uint)+12)) {
    printf("mmp: adr=%08.8x_%08.8x out of range (top=%08.8x_%08.8x len=%dB)\n", (Uint)(adr>>32), (Uint)adr, (Uint)(top>>32), (Uint)top, len*sizeof(Uint));
    fflush(stdout);
  }
  c1 = ex>>1&1;
  c0 = ex &1;
  switch (op_mm) {
  case 0x00:
    break;
  case 0x01:
    load64 = *(Ull*)(adr&~7LL);
    if ((adr&7) == 0)
      *d = load64;
    else if (!emax7_unaligned_load_valid) {
      emax7_unaligned_load_valid = 1;
      emax7_unaligned_load_high = load64;
      *d = load64 >> (adr&7)*8;
    }
    else {
      emax7_unaligned_load_valid = 0;
      *d = emax7_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
    }
    break;
  case 0x02:
    *d = (Ull)*(Uint*)(adr&~3LL);
    break;
  case 0x04:
    *d = (Ull)(Uint)*(Uchar*)adr;
    break;
  case 0x11:
    if (c1) *((Uint*)(adr&~7LL)+1) = *d>>32;
    if (c0) *((Uint*)(adr&~7LL) ) = *d;
    break;
  case 0x12:
    if (c0) *(Uint*)(adr&~3LL) = *d;
    break;
  case 0x14:
    if (c0) *(Uchar*)adr = *d;
    break;
  case 0x08:
    switch (blk) {
    case 0:
      *(d+0) = *((Ull*)(adr&~31LL)+0);
      *(d+1) = *((Ull*)(adr&~31LL)+1);
      *(d+2) = *((Ull*)(adr&~31LL)+2);
      *(d+3) = *((Ull*)(adr&~31LL)+3);
      break;
    case 1:
      *(d+0) = *(*(Ull**)(top + (adr/32/16*sizeof(Ull*))) + (adr/32&15)*4 + 0);
      *(d+1) = *(*(Ull**)(top + (adr/32/16*sizeof(Ull*))) + (adr/32&15)*4 + 1);
      *(d+2) = *(*(Ull**)(top + (adr/32/16*sizeof(Ull*))) + (adr/32&15)*4 + 2);
      *(d+3) = *(*(Ull**)(top + (adr/32/16*sizeof(Ull*))) + (adr/32&15)*4 + 3);
      break;
    case 2:
      *(d+0) = *(*(Ull**)(top + (adr/32/32*sizeof(Ull*))) + (adr/32&31)*4 + 0);
      *(d+1) = *(*(Ull**)(top + (adr/32/32*sizeof(Ull*))) + (adr/32&31)*4 + 1);
      *(d+2) = *(*(Ull**)(top + (adr/32/32*sizeof(Ull*))) + (adr/32&31)*4 + 2);
      *(d+3) = *(*(Ull**)(top + (adr/32/32*sizeof(Ull*))) + (adr/32&31)*4 + 3);
      break;
    default:
      *(d+0) = *(*(Ull**)(top + (adr/32/64*sizeof(Ull*))) + (adr/32&63)*4 + 0);
      *(d+1) = *(*(Ull**)(top + (adr/32/64*sizeof(Ull*))) + (adr/32&63)*4 + 1);
      *(d+2) = *(*(Ull**)(top + (adr/32/64*sizeof(Ull*))) + (adr/32&63)*4 + 2);
      *(d+3) = *(*(Ull**)(top + (adr/32/64*sizeof(Ull*))) + (adr/32&63)*4 + 3);
      break;
    }
    break;
  case 0x19:
    if (c0) {
      *(d+0) = *((Ull*)(adr&~31LL)+0);
      *(d+1) = *((Ull*)(adr&~31LL)+1);
      *(d+2) = *((Ull*)(adr&~31LL)+2);
      *(d+3) = *((Ull*)(adr&~31LL)+3);
    }
    break;
  case 0x18:
    *((Ull*)(adr&~31LL)+0) = *(d+0);
    *((Ull*)(adr&~31LL)+1) = *(d+1);
    *((Ull*)(adr&~31LL)+2) = *(d+2);
    *((Ull*)(adr&~31LL)+3) = *(d+3);
    break;
  case 0x1a:
    if (c0) {
      Ull (*trans)() = top;
      (trans)(*(d+0), *(d+1), *(d+2), *(d+3));
    }
    break;
  default:
    printf("emax7lib: mmp: undefined op_mm=%d\n", op_mm);
    break;
  }
}
struct iovec
  {
    void *iov_base;
    size_t iov_len;
  };
enum __socket_type
{
  SOCK_STREAM = 1,
  SOCK_DGRAM = 2,
  SOCK_RAW = 3,
  SOCK_RDM = 4,
  SOCK_SEQPACKET = 5,
  SOCK_DCCP = 6,
  SOCK_PACKET = 10,
  SOCK_CLOEXEC = 02000000,
  SOCK_NONBLOCK = 00004000
};
typedef unsigned short int sa_family_t;
struct sockaddr
  {
    sa_family_t sa_family;
    char sa_data[14];
  };
struct sockaddr_storage
  {
    sa_family_t ss_family;
    char __ss_padding[(128 - (sizeof (unsigned short int)) - sizeof (unsigned long int))];
    unsigned long int __ss_align;
  };
enum
  {
    MSG_OOB = 0x01,
    MSG_PEEK = 0x02,
    MSG_DONTROUTE = 0x04,
    MSG_CTRUNC = 0x08,
    MSG_PROXY = 0x10,
    MSG_TRUNC = 0x20,
    MSG_DONTWAIT = 0x40,
    MSG_EOR = 0x80,
    MSG_WAITALL = 0x100,
    MSG_FIN = 0x200,
    MSG_SYN = 0x400,
    MSG_CONFIRM = 0x800,
    MSG_RST = 0x1000,
    MSG_ERRQUEUE = 0x2000,
    MSG_NOSIGNAL = 0x4000,
    MSG_MORE = 0x8000,
    MSG_WAITFORONE = 0x10000,
    MSG_BATCH = 0x40000,
    MSG_ZEROCOPY = 0x4000000,
    MSG_FASTOPEN = 0x20000000,
    MSG_CMSG_CLOEXEC = 0x40000000
  };
struct msghdr
  {
    void *msg_name;
    socklen_t msg_namelen;
    struct iovec *msg_iov;
    size_t msg_iovlen;
    void *msg_control;
    size_t msg_controllen;
    int msg_flags;
  };
struct cmsghdr
  {
    size_t cmsg_len;
    int cmsg_level;
    int cmsg_type;
    __extension__ unsigned char __cmsg_data [];
  };
extern struct cmsghdr *__cmsg_nxthdr (struct msghdr *__mhdr,
          struct cmsghdr *__cmsg) __attribute__ ((__nothrow__ , __leaf__));
enum
  {
    SCM_RIGHTS = 0x01
  };
struct linger
  {
    int l_onoff;
    int l_linger;
  };
struct osockaddr
{
  unsigned short int sa_family;
  unsigned char sa_data[14];
};
enum
{
  SHUT_RD = 0,
  SHUT_WR,
  SHUT_RDWR
};
extern int socket (int __domain, int __type, int __protocol) __attribute__ ((__nothrow__ , __leaf__));
extern int socketpair (int __domain, int __type, int __protocol,
         int __fds[2]) __attribute__ ((__nothrow__ , __leaf__));
extern int bind (int __fd, const struct sockaddr * __addr, socklen_t __len)
     __attribute__ ((__nothrow__ , __leaf__));
extern int getsockname (int __fd, struct sockaddr *__restrict __addr,
   socklen_t *__restrict __len) __attribute__ ((__nothrow__ , __leaf__));
extern int connect (int __fd, const struct sockaddr * __addr, socklen_t __len);
extern int getpeername (int __fd, struct sockaddr *__restrict __addr,
   socklen_t *__restrict __len) __attribute__ ((__nothrow__ , __leaf__));
extern ssize_t send (int __fd, const void *__buf, size_t __n, int __flags);
extern ssize_t recv (int __fd, void *__buf, size_t __n, int __flags);
extern ssize_t sendto (int __fd, const void *__buf, size_t __n,
         int __flags, const struct sockaddr * __addr,
         socklen_t __addr_len);
extern ssize_t recvfrom (int __fd, void *__restrict __buf, size_t __n,
    int __flags, struct sockaddr *__restrict __addr,
    socklen_t *__restrict __addr_len);
extern ssize_t sendmsg (int __fd, const struct msghdr *__message,
   int __flags);
extern ssize_t recvmsg (int __fd, struct msghdr *__message, int __flags);
extern int getsockopt (int __fd, int __level, int __optname,
         void *__restrict __optval,
         socklen_t *__restrict __optlen) __attribute__ ((__nothrow__ , __leaf__));
extern int setsockopt (int __fd, int __level, int __optname,
         const void *__optval, socklen_t __optlen) __attribute__ ((__nothrow__ , __leaf__));
extern int listen (int __fd, int __n) __attribute__ ((__nothrow__ , __leaf__));
extern int accept (int __fd, struct sockaddr *__restrict __addr,
     socklen_t *__restrict __addr_len);
extern int shutdown (int __fd, int __how) __attribute__ ((__nothrow__ , __leaf__));
extern int sockatmark (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern int isfdtype (int __fd, int __fdtype) __attribute__ ((__nothrow__ , __leaf__));
typedef uint32_t in_addr_t;
struct in_addr
  {
    in_addr_t s_addr;
  };
struct ip_opts
  {
    struct in_addr ip_dst;
    char ip_opts[40];
  };
struct in_pktinfo
  {
    int ipi_ifindex;
    struct in_addr ipi_spec_dst;
    struct in_addr ipi_addr;
  };
enum
  {
    IPPROTO_IP = 0,
    IPPROTO_ICMP = 1,
    IPPROTO_IGMP = 2,
    IPPROTO_IPIP = 4,
    IPPROTO_TCP = 6,
    IPPROTO_EGP = 8,
    IPPROTO_PUP = 12,
    IPPROTO_UDP = 17,
    IPPROTO_IDP = 22,
    IPPROTO_TP = 29,
    IPPROTO_DCCP = 33,
    IPPROTO_IPV6 = 41,
    IPPROTO_RSVP = 46,
    IPPROTO_GRE = 47,
    IPPROTO_ESP = 50,
    IPPROTO_AH = 51,
    IPPROTO_MTP = 92,
    IPPROTO_BEETPH = 94,
    IPPROTO_ENCAP = 98,
    IPPROTO_PIM = 103,
    IPPROTO_COMP = 108,
    IPPROTO_SCTP = 132,
    IPPROTO_UDPLITE = 136,
    IPPROTO_MPLS = 137,
    IPPROTO_ETHERNET = 143,
    IPPROTO_RAW = 255,
    IPPROTO_MPTCP = 262,
    IPPROTO_MAX
  };
enum
  {
    IPPROTO_HOPOPTS = 0,
    IPPROTO_ROUTING = 43,
    IPPROTO_FRAGMENT = 44,
    IPPROTO_ICMPV6 = 58,
    IPPROTO_NONE = 59,
    IPPROTO_DSTOPTS = 60,
    IPPROTO_MH = 135
  };
typedef uint16_t in_port_t;
enum
  {
    IPPORT_ECHO = 7,
    IPPORT_DISCARD = 9,
    IPPORT_SYSTAT = 11,
    IPPORT_DAYTIME = 13,
    IPPORT_NETSTAT = 15,
    IPPORT_FTP = 21,
    IPPORT_TELNET = 23,
    IPPORT_SMTP = 25,
    IPPORT_TIMESERVER = 37,
    IPPORT_NAMESERVER = 42,
    IPPORT_WHOIS = 43,
    IPPORT_MTP = 57,
    IPPORT_TFTP = 69,
    IPPORT_RJE = 77,
    IPPORT_FINGER = 79,
    IPPORT_TTYLINK = 87,
    IPPORT_SUPDUP = 95,
    IPPORT_EXECSERVER = 512,
    IPPORT_LOGINSERVER = 513,
    IPPORT_CMDSERVER = 514,
    IPPORT_EFSSERVER = 520,
    IPPORT_BIFFUDP = 512,
    IPPORT_WHOSERVER = 513,
    IPPORT_ROUTESERVER = 520,
    IPPORT_RESERVED = 1024,
    IPPORT_USERRESERVED = 5000
  };
struct in6_addr
  {
    union
      {
 uint8_t __u6_addr8[16];
 uint16_t __u6_addr16[8];
 uint32_t __u6_addr32[4];
      } __in6_u;
  };
extern const struct in6_addr in6addr_any;
extern const struct in6_addr in6addr_loopback;
struct sockaddr_in
  {
    sa_family_t sin_family;
    in_port_t sin_port;
    struct in_addr sin_addr;
    unsigned char sin_zero[sizeof (struct sockaddr)
      - (sizeof (unsigned short int))
      - sizeof (in_port_t)
      - sizeof (struct in_addr)];
  };
struct sockaddr_in6
  {
    sa_family_t sin6_family;
    in_port_t sin6_port;
    uint32_t sin6_flowinfo;
    struct in6_addr sin6_addr;
    uint32_t sin6_scope_id;
  };
struct ip_mreq
  {
    struct in_addr imr_multiaddr;
    struct in_addr imr_interface;
  };
struct ip_mreqn
  {
    struct in_addr imr_multiaddr;
    struct in_addr imr_address;
    int imr_ifindex;
  };
struct ip_mreq_source
  {
    struct in_addr imr_multiaddr;
    struct in_addr imr_interface;
    struct in_addr imr_sourceaddr;
  };
struct ipv6_mreq
  {
    struct in6_addr ipv6mr_multiaddr;
    unsigned int ipv6mr_interface;
  };
struct group_req
  {
    uint32_t gr_interface;
    struct sockaddr_storage gr_group;
  };
struct group_source_req
  {
    uint32_t gsr_interface;
    struct sockaddr_storage gsr_group;
    struct sockaddr_storage gsr_source;
  };
struct ip_msfilter
  {
    struct in_addr imsf_multiaddr;
    struct in_addr imsf_interface;
    uint32_t imsf_fmode;
    uint32_t imsf_numsrc;
    struct in_addr imsf_slist[1];
  };
struct group_filter
  {
    uint32_t gf_interface;
    struct sockaddr_storage gf_group;
    uint32_t gf_fmode;
    uint32_t gf_numsrc;
    struct sockaddr_storage gf_slist[1];
};
extern uint32_t ntohl (uint32_t __netlong) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern uint16_t ntohs (uint16_t __netshort)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern uint32_t htonl (uint32_t __hostlong)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern uint16_t htons (uint16_t __hostshort)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int bindresvport (int __sockfd, struct sockaddr_in *__sock_in) __attribute__ ((__nothrow__ , __leaf__));
extern int bindresvport6 (int __sockfd, struct sockaddr_in6 *__sock_in)
     __attribute__ ((__nothrow__ , __leaf__));
extern int WD, HT, BITMAP, SCRWD, SCRHT, VECWD, VECHT, VECSTEP;
typedef struct {
  unsigned int width;
  unsigned int height;
  unsigned char *data;
} Image;
typedef struct {
  int numseg;
  XSegment *seg;
} Vector;
typedef struct {
  Display *disp;
  int scrn;
  int depth;
  int dpixlen;
  Drawable drawable;
  Colormap cmap;
  GC gc;
  XImage *ximage;
} XImageInfo;
typedef struct {
  Window win;
  Display *dpy;
  char *dname;
  long fg, bg;
  GC gc;
  Atom kill_atom, protocol_atom;
} XVectorInfo;
union {
  XEvent event;
  XAnyEvent any;
  XButtonEvent button;
  XExposeEvent expose;
  XMotionEvent motion;
  XResizeRequestEvent resize;
  XClientMessageEvent message;
} event;
unsigned int redvalue[256], greenvalue[256], bluevalue[256];
XImageInfo ximageinfo;
Image imageinfo;
unsigned int bitsPerPixelAtDepth();
void imageInWindow();
void vectorInWindow();
void bestVisual();
XVectorInfo xvectorinfo;
Vector vectorinfo;
XdbeBackBuffer backBuffer;
XdbeBackBufferAttributes *backAttr;
XdbeSwapInfo swapInfo;
void x11_open(int spike_mode)
{
  if (!(ximageinfo.disp = XOpenDisplay(((void *)0)))) {
    printf("%s: Cannot open display\n", XDisplayName(((void *)0)));
    exit(1);
  }
  ximageinfo.scrn = (((_XPrivDisplay)(ximageinfo.disp))->default_screen);
  imageinfo.width = WD*SCRWD;
  imageinfo.height= HT*SCRHT;
  imageInWindow(&ximageinfo, &imageinfo);
  if (spike_mode) {
    xvectorinfo.dname = ((void *)0);
    if (!(xvectorinfo.dpy = XOpenDisplay(xvectorinfo.dname))) {
      fprintf(stderr, "Cannot open displays %s\n", xvectorinfo.dname);
      exit(-1);
    }
    vectorinfo.numseg = WD*VECWD * HT*VECHT;
    vectorinfo.seg = malloc(sizeof(int)*4 * vectorinfo.numseg);
    vectorInWindow(&xvectorinfo, &vectorinfo);
  }
}
void x11_update()
{
  XPutImage(ximageinfo.disp, ximageinfo.drawable, ximageinfo.gc,
            ximageinfo.ximage, 0, 0, 0, 0, imageinfo.width, imageinfo.height);
}
int weight2color(int in)
{
  float w;
  int color;
  w = in/100.0;
  if (w < -1.0)
    color = 0xff0000;
  else if (w < -0.25)
    color = 0xff8000;
  else if (w < -0.125)
    color = 0xffff00;
  else if (w < 0.0)
    color = 0x80ff00;
  else if (w < 0.125)
    color = 0x008000;
  else if (w < 0.25)
    color = 0x0080ff;
  else if (w < 1.0)
    color = 0x00ffff;
  else
    color = 0xffffff;
  return (color);
}
void x11_vector_add(int row, int col, int param, float *data1, float *data2, int m, int n)
{
  int ofs, x, y;
  if (col >= VECWD) {
    printf("x11_vector_add: col exceeds %d\n", VECWD);
    return;
  }
  switch (row) {
  case 0:
  case 1:
  case 2:
    ofs = WD*HT*(row*VECWD+col)+WD*HT/VECSTEP*0;
    for (y=0; y<HT/VECSTEP; y++) {
      if (y<m*n) {
 for (x=0; x<WD-1; x++) {
   vectorinfo.seg[ofs+y*WD+x].y1 = vectorinfo.seg[ofs+y*WD+x+1].y1;
   vectorinfo.seg[ofs+y*WD+x].y2 = vectorinfo.seg[ofs+y*WD+x+1].y2;
 }
 vectorinfo.seg[ofs+y*WD+WD-2].y1 = vectorinfo.seg[ofs+y*WD+WD-3].y2;
 vectorinfo.seg[ofs+y*WD+WD-2].y2 = row*HT+y*VECSTEP+(VECSTEP-1)-(data1[y]*param);
      }
      else {
 for (x=0; x<WD; x++) {
   vectorinfo.seg[ofs+y*WD+x].x1 = 0;
   vectorinfo.seg[ofs+y*WD+x].y1 = 0;
   vectorinfo.seg[ofs+y*WD+x].x2 = 0;
   vectorinfo.seg[ofs+y*WD+x].y2 = 0;
 }
      }
    }
    if (data1) {
      ofs = WD*HT*(row*VECWD+col)+WD*HT/VECSTEP*2;
      for (y=0; y<HT/VECSTEP; y++) {
 for (x=0; x<WD; x++)
   vectorinfo.seg[ofs+y*WD+x].x2 = col*WD;
      }
      for (x=0; x<m*n; x++) {
 int d = data1[x]*40, idx;
 if (d < -HT/VECSTEP) idx = HT/VECSTEP-1;
 else if (-HT/VECSTEP/2 < d && d < HT/VECSTEP/2) idx = HT/VECSTEP/2-d;
 else idx = 0;
 int magni;
 switch (row) {
 case 0: magni = 2; break;
 case 1: magni = 2; break;
 case 2: magni = 1; break;
 }
 if (WD < m*n)
   vectorinfo.seg[ofs+idx*WD].x2 += magni;
 else
   vectorinfo.seg[ofs+idx*WD].x2 += WD/(m*n)*magni;
      }
    }
    if (data2) {
      ofs = WD*HT*(row*VECWD+col)+WD*HT/VECSTEP*3;
      for (y=0; y<HT/VECSTEP; y++) {
 for (x=0; x<WD; x++)
   vectorinfo.seg[ofs+y*WD+x].x2 = col*WD;
      }
      for (x=0; x<m*n; x++) {
 int d = data2[x]*40, idx;
 if (d < -HT/VECSTEP) idx = HT/VECSTEP-1;
 else if (-HT/VECSTEP/2 < d && d < HT/VECSTEP/2) idx = HT/VECSTEP/2-d;
 else idx = 0;
 int magni;
 switch (row) {
 case 0: magni = 2; break;
 case 1: magni = 2; break;
 case 2: magni = 1; break;
 }
 if (WD < m*n)
   vectorinfo.seg[ofs+idx*WD].x2 += magni;
 else
   vectorinfo.seg[ofs+idx*WD].x2 += WD/(m*n)*magni;
      }
    }
    break;
  case 3:
    ofs = WD*HT*(row*VECWD+col)+WD*HT/VECSTEP*0;
    for (y=0; y<HT/VECSTEP && y<m; y++) {
      for (x=0; x<WD/VECSTEP && x<n; x++) {
 vectorinfo.seg[ofs+y*WD+x*VECSTEP ].y1 = row*HT+y*VECSTEP;
 vectorinfo.seg[ofs+y*WD+x*VECSTEP ].y2 = data1[y*n+x]*100.0;
 vectorinfo.seg[ofs+y*WD+x*VECSTEP+1].x1 = m;
 vectorinfo.seg[ofs+y*WD+x*VECSTEP+1].x2 = n;
      }
    }
    break;
  }
}
void x11_vector_update()
{
  unsigned int fc, col, x, y, x0, y0;
  XSetFont(xvectorinfo.dpy, xvectorinfo.gc, XLoadFont(xvectorinfo.dpy, "-adobe-*-medium-r-normal--24-*-iso8859-1"));
  fc = 0xc00000;
  XSetForeground(xvectorinfo.dpy, xvectorinfo.gc, fc);
  for (col=0; col<VECWD; col++)
    XDrawSegments(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, vectorinfo.seg+(WD*HT*(0*VECWD+col)+WD*HT/VECSTEP*0), WD*HT/VECSTEP);
  fc = 0xffff00;
  XSetForeground(xvectorinfo.dpy, xvectorinfo.gc, fc);
  for (col=0; col<VECWD; col++)
    XDrawSegments(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, vectorinfo.seg+(WD*HT*(0*VECWD+col)+WD*HT/VECSTEP*2), WD*HT/VECSTEP);
  fc = 0xffffff;
  XSetForeground(xvectorinfo.dpy, xvectorinfo.gc, fc);
  XDrawString(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, WD/3, HT*0+HT/2+13, "nflat", strlen("nflat"));
  fc = 0x008000;
  XSetForeground(xvectorinfo.dpy, xvectorinfo.gc, fc);
  for (col=0; col<VECWD; col++)
    XDrawSegments(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, vectorinfo.seg+(WD*HT*(1*VECWD+col)+WD*HT/VECSTEP*0), WD*HT/VECSTEP);
  fc = 0x00ff00;
  XSetForeground(xvectorinfo.dpy, xvectorinfo.gc, fc);
  for (col=0; col<VECWD; col++)
    XDrawSegments(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, vectorinfo.seg+(WD*HT*(1*VECWD+col)+WD*HT/VECSTEP*2), WD*HT/VECSTEP);
  fc = 0xff8000;
  XSetForeground(xvectorinfo.dpy, xvectorinfo.gc, fc);
  for (col=0; col<VECWD; col++)
    XDrawSegments(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, vectorinfo.seg+(WD*HT*(1*VECWD+col)+WD*HT/VECSTEP*3), WD*HT/VECSTEP);
  fc = 0x00ff00;
  XSetForeground(xvectorinfo.dpy, xvectorinfo.gc, fc);
  XDrawString(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, WD/3, HT*1+HT/2-13, "spike-nout", strlen("spike-nout"));
  fc = 0xff8000;
  XSetForeground(xvectorinfo.dpy, xvectorinfo.gc, fc);
  XDrawString(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, WD/3, HT*1+HT/2+13, "orig-noutbak", strlen("orig-noutbak"));
  fc = 0x0000ff;
  XSetForeground(xvectorinfo.dpy, xvectorinfo.gc, fc);
  for (col=0; col<VECWD; col++)
    XDrawSegments(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, vectorinfo.seg+(WD*HT*(2*VECWD+col)+WD*HT/VECSTEP*0), WD*HT/VECSTEP);
  fc = 0xff00ff;
  XSetForeground(xvectorinfo.dpy, xvectorinfo.gc, fc);
  for (col=0; col<VECWD; col++)
    XDrawSegments(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, vectorinfo.seg+(WD*HT*(2*VECWD+col)+WD*HT/VECSTEP*2), WD*HT/VECSTEP);
  fc = 0xffffff;
  XSetForeground(xvectorinfo.dpy, xvectorinfo.gc, fc);
  XDrawString(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, WD/3, HT*2+HT/2+13, "Wh2o", strlen("Wh2o"));
  XDrawString(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, 0, HT*0+18, "+1.0", strlen("+1.0"));
  XDrawString(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, 0, HT*0+HT/2+13, " 0.0", strlen(" 0.0"));
  XDrawString(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, 0, HT*0+HT, "-1.0", strlen("-1.0"));
  XDrawString(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, 0, HT*1+18, "+1.0", strlen("+1.0"));
  XDrawString(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, 0, HT*1+HT/2+13, " 0.0", strlen(" 0.0"));
  XDrawString(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, 0, HT*1+HT, "-1.0", strlen("-1.0"));
  XDrawString(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, 0, HT*2+18, "+1.0", strlen("+1.0"));
  XDrawString(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, 0, HT*2+HT/2+13, " 0.0", strlen(" 0.0"));
  XDrawString(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, 0, HT*2+HT, "-1.0", strlen("-1.0"));
  for (col=0; col<VECWD; col++) {
    int base = WD*HT*(3*VECWD+col);
    int m = vectorinfo.seg[base+1].x1;
    int n = vectorinfo.seg[base+1].x2;
    for (y=0; y<HT/VECSTEP && y<m; y++) {
      for (x=0; x<WD/VECSTEP && x<n; x++) {
 int x0 = vectorinfo.seg[base+y*WD+x*VECSTEP].x1;
 int y0 = vectorinfo.seg[base+y*WD+x*VECSTEP].y1;
 int size = vectorinfo.seg[base+y*WD+x*VECSTEP].y2;
 XSetForeground(xvectorinfo.dpy, xvectorinfo.gc, weight2color(size));
 XDrawRectangle(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, x0, y0, 4, 4);
      }
    }
  }
  fc = 0xffffff;
  XSetForeground(xvectorinfo.dpy, xvectorinfo.gc, fc);
  XDrawString(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, WD/3, HT*3+HT/2, "Wh2o", strlen("Wh2o"));
  XSetForeground(xvectorinfo.dpy, xvectorinfo.gc, 0xff0000);
  XDrawLine(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, 0, HT*(VECHT-1)+HT, WD, HT*(VECHT-1));
  XSetForeground(xvectorinfo.dpy, xvectorinfo.gc, 0xffffff);
  XDrawLine(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, 0, HT*(VECHT-1)+HT/2, WD, HT*(VECHT-1)+HT/2);
  XSetForeground(xvectorinfo.dpy, xvectorinfo.gc, 0xffffff);
  XDrawLine(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, WD/2, HT*(VECHT-1), WD/2, HT*(VECHT-1)+HT);
  XdbeSwapBuffers(xvectorinfo.dpy, &swapInfo, 1);
  XSync(xvectorinfo.dpy, 0);
  XSetForeground(xvectorinfo.dpy, xvectorinfo.gc, 0);
  XFillRectangle(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, 0, 0, WD*VECWD, HT*VECHT);
}
int x11_checkevent()
{
  static int stop = 0;
  x11_update();
  while (XPending(ximageinfo.disp)) {
    XNextEvent(ximageinfo.disp, &event.event);
    switch (event.any.type) {
    case 2:
      stop = 1-stop;
      if (stop) printf("-stopped- (type any key to continue)\n");
      else printf("-running-\n");
      break;
    default:
      break;
    }
  }
  return (stop);
}
void x11_close()
{
  XCloseDisplay(ximageinfo.disp);
}
void imageInWindow(ximageinfo, image)
     XImageInfo *ximageinfo;
     Image *image;
{
  Window ViewportWin;
  Visual *visual;
  unsigned int depth;
  unsigned int dpixlen;
  XSetWindowAttributes swa_view;
  XSizeHints sh;
  unsigned int pixval;
  unsigned int redcolors, greencolors, bluecolors;
  unsigned int redstep, greenstep, bluestep;
  unsigned int redbottom, greenbottom, bluebottom;
  unsigned int redtop, greentop, bluetop;
  XColor xcolor;
  unsigned int a;
  XGCValues gcv;
  bestVisual(ximageinfo->disp, ximageinfo->scrn, &visual, &depth);
  dpixlen = (bitsPerPixelAtDepth(ximageinfo->disp, depth) + 7) / 8;
  ximageinfo->depth = depth;
  ximageinfo->dpixlen = dpixlen;
  ximageinfo->drawable= 0L;
  ximageinfo->gc = ((void *)0);
  ximageinfo->ximage = XCreateImage(ximageinfo->disp, visual, depth, 2, 0,
                                     ((void *)0), image->width, image->height,
                                     8, 0);
  ximageinfo->ximage->data= (char*)malloc(image->width * image->height * dpixlen);
  ximageinfo->ximage->byte_order= 1;
  if (visual == ((&((_XPrivDisplay)(ximageinfo->disp))->screens[ximageinfo->scrn])->root_visual))
    ximageinfo->cmap= ((&((_XPrivDisplay)(ximageinfo->disp))->screens[ximageinfo->scrn])->cmap);
  else
    ximageinfo->cmap= XCreateColormap(ximageinfo->disp, ((&((_XPrivDisplay)(ximageinfo->disp))->screens[ximageinfo->scrn])->root), visual, 0);
  redcolors= greencolors= bluecolors= 1;
  for (pixval= 1; pixval; pixval <<= 1) {
    if (pixval & visual->red_mask)
      redcolors <<= 1;
    if (pixval & visual->green_mask)
      greencolors <<= 1;
    if (pixval & visual->blue_mask)
      bluecolors <<= 1;
  }
  redtop = 0;
  greentop = 0;
  bluetop = 0;
  redstep = 256 / redcolors;
  greenstep= 256 / greencolors;
  bluestep = 256 / bluecolors;
  redbottom= greenbottom= bluebottom= 0;
  for (a= 0; a < visual->map_entries; a++) {
    if (redbottom < 256)
      redtop= redbottom + redstep;
    if (greenbottom < 256)
      greentop= greenbottom + greenstep;
    if (bluebottom < 256)
      bluetop= bluebottom + bluestep;
    xcolor.flags= (1<<0) | (1<<1) | (1<<2);
    xcolor.red = (redtop - 1) << 8;
    xcolor.green= (greentop - 1) << 8;
    xcolor.blue = (bluetop - 1) << 8;
    XAllocColor(ximageinfo->disp, ximageinfo->cmap, &xcolor);
    while ((redbottom < 256) && (redbottom < redtop))
      redvalue[redbottom++]= xcolor.pixel & visual->red_mask;
    while ((greenbottom < 256) && (greenbottom < greentop))
      greenvalue[greenbottom++]= xcolor.pixel & visual->green_mask;
    while ((bluebottom < 256) && (bluebottom < bluetop))
      bluevalue[bluebottom++]= xcolor.pixel & visual->blue_mask;
  }
  swa_view.background_pixel= ((&((_XPrivDisplay)(ximageinfo->disp))->screens[ximageinfo->scrn])->white_pixel);
  swa_view.backing_store= 1;
  swa_view.cursor= XCreateFontCursor(ximageinfo->disp, 150);
  swa_view.event_mask= (1L<<2) | (1L<<8) | (1L<<0) |
    (1L<<17) | (1L<<4) | (1L<<5) | (1L<<15);
  swa_view.save_under= 0;
  swa_view.bit_gravity= 1;
  swa_view.save_under= 0;
  swa_view.colormap= ximageinfo->cmap;
  swa_view.border_pixel= 0;
  ViewportWin= XCreateWindow(ximageinfo->disp, ((&((_XPrivDisplay)(ximageinfo->disp))->screens[ximageinfo->scrn])->root), 0, 0,
                             image->width, image->height, 0,
                             ((&((_XPrivDisplay)(ximageinfo->disp))->screens[ximageinfo->scrn])->root_depth), 1,
                             ((&((_XPrivDisplay)(ximageinfo->disp))->screens[ximageinfo->scrn])->root_visual),
                             (1L<<6) | (1L<<1) |
                             (1L<<11) | (1L<<10),
                             &swa_view);
  ximageinfo->drawable= ViewportWin;
  gcv.function= 0x3;
  ximageinfo->gc= XCreateGC(ximageinfo->disp, ximageinfo->drawable, (1L<<0), &gcv);
  sh.width= image->width;
  sh.height= image->height;
  sh.min_width= image->width;
  sh.min_height= image->height;
  sh.max_width= image->width;
  sh.max_height= image->height;
  sh.width_inc= 1;
  sh.height_inc= 1;
  sh.flags= (1L << 4) | (1L << 5) | (1L << 6) | (1L << 3);
  XSetNormalHints(ximageinfo->disp, ViewportWin, &sh);
  XStoreName(ximageinfo->disp, ViewportWin, "ssim");
  XMapWindow(ximageinfo->disp, ViewportWin);
  XSync(ximageinfo->disp, 0);
}
void vectorInWindow(xvectorinfo, vectorinfo)
     XVectorInfo *xvectorinfo;
     Vector *vectorinfo;
{
  char wname[32];
  int winX, winY, winW, winH;
  XSizeHints sizehint;
  XSetWindowAttributes xswa;
  int i, j, x, y;
  for (i=0; i<VECHT; i++) {
    for (j=0; j<VECWD; j++) {
      for (y=0; y<HT/VECSTEP; y++) {
 for (x=0; x<WD-1; x++) {
   vectorinfo->seg[WD*HT*(i*VECWD+j)+WD*HT/VECSTEP*0+y*WD+x].x1 = j*WD+x;
   vectorinfo->seg[WD*HT*(i*VECWD+j)+WD*HT/VECSTEP*0+y*WD+x].y1 = i*HT+y*VECSTEP+0+(VECSTEP-1);
   vectorinfo->seg[WD*HT*(i*VECWD+j)+WD*HT/VECSTEP*0+y*WD+x].x2 = j*WD+x+1;
   vectorinfo->seg[WD*HT*(i*VECWD+j)+WD*HT/VECSTEP*0+y*WD+x].y2 = i*HT+y*VECSTEP+0+(VECSTEP-1);
 }
      }
      for (y=0; y<HT/VECSTEP; y++) {
 for (x=0; x<WD-1; x++) {
   vectorinfo->seg[WD*HT*(i*VECWD+j)+WD*HT/VECSTEP*2+y*WD+x].x1 = j*WD+0;
   vectorinfo->seg[WD*HT*(i*VECWD+j)+WD*HT/VECSTEP*2+y*WD+x].y1 = i*HT+y*VECSTEP+1+(VECSTEP-1);
   vectorinfo->seg[WD*HT*(i*VECWD+j)+WD*HT/VECSTEP*2+y*WD+x].x2 = j*WD+WD/16;
   vectorinfo->seg[WD*HT*(i*VECWD+j)+WD*HT/VECSTEP*2+y*WD+x].y2 = i*HT+y*VECSTEP+1+(VECSTEP-1);
 }
      }
      for (y=0; y<HT/VECSTEP; y++) {
 for (x=0; x<WD-1; x++) {
   vectorinfo->seg[WD*HT*(i*VECWD+j)+WD*HT/VECSTEP*3+y*WD+x].x1 = j*WD+0;
   vectorinfo->seg[WD*HT*(i*VECWD+j)+WD*HT/VECSTEP*3+y*WD+x].y1 = i*HT+y*VECSTEP+3+(VECSTEP-1);
   vectorinfo->seg[WD*HT*(i*VECWD+j)+WD*HT/VECSTEP*3+y*WD+x].x2 = j*WD+WD/16;
   vectorinfo->seg[WD*HT*(i*VECWD+j)+WD*HT/VECSTEP*3+y*WD+x].y2 = i*HT+y*VECSTEP+3+(VECSTEP-1);
 }
      }
    }
  }
  xvectorinfo->fg =((&((_XPrivDisplay)(xvectorinfo->dpy))->screens[(((_XPrivDisplay)(xvectorinfo->dpy))->default_screen)])->white_pixel);
  xvectorinfo->bg =((&((_XPrivDisplay)(xvectorinfo->dpy))->screens[(((_XPrivDisplay)(xvectorinfo->dpy))->default_screen)])->black_pixel);
  winX = 0;
  winY = 0;
  winW = WD*VECWD;
  winH = HT*VECHT;
  xswa.event_mask = 0;
  xswa.background_pixel = xvectorinfo->bg;
  xswa.border_pixel = xvectorinfo->fg;
  xvectorinfo->win = XCreateWindow(xvectorinfo->dpy,
      ((&((_XPrivDisplay)(xvectorinfo->dpy))->screens[(((_XPrivDisplay)(xvectorinfo->dpy))->default_screen)])->root),
      winX, winY, winW, winH, 0,
      24,
      1, ((&((_XPrivDisplay)(xvectorinfo->dpy))->screens[(((_XPrivDisplay)(xvectorinfo->dpy))->default_screen)])->root_visual),
      (1L<<11) | (1L<<1) | (1L<<3), &xswa);
  sizehint.flags = (1L << 2) | (1L << 3);
  XSetNormalHints(xvectorinfo->dpy, xvectorinfo->win, &sizehint);
  xvectorinfo->protocol_atom = XInternAtom(xvectorinfo->dpy, "WM_PROTOCOLS", 0);
  xvectorinfo->kill_atom = XInternAtom(xvectorinfo->dpy, "WM_DELETE_WINDOW", 0);
  XSetWMProtocols(xvectorinfo->dpy, xvectorinfo->win, &xvectorinfo->kill_atom, 1);
  sprintf(wname, "vector");
  XChangeProperty(xvectorinfo->dpy, xvectorinfo->win, ((Atom) 39), ((Atom) 31), 8, 0, (unsigned char*)wname, strlen(wname));
  XMapWindow(xvectorinfo->dpy, xvectorinfo->win);
  xvectorinfo->gc = XCreateGC(xvectorinfo->dpy, xvectorinfo->win, 0, ((void *)0));
  XSetForeground(xvectorinfo->dpy, xvectorinfo->gc, xvectorinfo->fg);
  XSetBackground(xvectorinfo->dpy, xvectorinfo->gc, xvectorinfo->bg);
  backBuffer = XdbeAllocateBackBufferName(xvectorinfo->dpy, xvectorinfo->win, 0);
  backAttr = XdbeGetBackBufferAttributes(xvectorinfo->dpy, backBuffer);
  swapInfo.swap_window = backAttr->window;
  swapInfo.swap_action = 0;
  XFree(backAttr);
  XClearArea(xvectorinfo->dpy, xvectorinfo->win, winX, winY, winW, winH, 0);
  XSync(xvectorinfo->dpy, 0);
}
void bestVisual(disp, scrn, rvisual, rdepth)
     Display *disp;
     int scrn;
     Visual **rvisual;
     unsigned int *rdepth;
{
  unsigned int depth, a;
  Screen *screen;
  XVisualInfo template, *info;
  int nvisuals;
  depth = 0;
  screen= (&((_XPrivDisplay)(disp))->screens[scrn]);
  for (a= 0; a < screen->ndepths; a++) {
    if (screen->depths[a].nvisuals &&
        ((!depth ||
          ((depth < 24) && (screen->depths[a].depth > depth)) ||
          ((screen->depths[a].depth >= 24) &&
           (screen->depths[a].depth < depth)))))
      depth= screen->depths[a].depth;
  }
  template.screen= scrn;
  template.class= 4;
  template.depth= depth;
  if (! (info= XGetVisualInfo(disp, 0x2 | 0x8 | 0x4, &template, &nvisuals)))
    *rvisual= ((void *)0);
  else {
    *rvisual= info->visual;
    XFree((char *)info);
  }
  *rdepth= depth;
}
unsigned int bitsPerPixelAtDepth(disp, depth)
     Display *disp;
     unsigned int depth;
{
  XPixmapFormatValues *xf;
  unsigned int nxf, a;
  xf = XListPixmapFormats(disp, (int *)&nxf);
  for (a = 0; a < nxf; a++)
    if (xf[a].depth == depth)
      return(xf[a].bits_per_pixel);
  fprintf(stderr, "bitsPerPixelAtDepth: Can't find pixmap depth info!\n");
  exit(1);
}
void BGR_to_X(int id, Uint *from)
{
  int i, j;
  Uint *to;
  to = (Uint*)(ximageinfo.ximage->data)+BITMAP*SCRWD*(id/SCRWD)+WD*(id%SCRWD);
  for (i=0; i<HT; i++,to+=WD*(SCRWD-1)) {
    for (j=0; j<WD; j++)
      *to++ = *from++;
  }
}
void x11_softu64_dist(float x, float y)
{
  static int count, color;
  count++;
  color = (count/1024)%7+1;
  switch(color) {
  case 1: color=0x0000ff; break;
  case 2: color=0x00ff00; break;
  case 3: color=0x00ffff; break;
  case 4: color=0xff0000; break;
  case 5: color=0xff00ff; break;
  case 6: color=0xffff00; break;
  case 7: color=0xffffff; break;
  }
  XSetForeground(xvectorinfo.dpy, xvectorinfo.gc, color);
  XDrawArc(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, WD/2+(int)(x*WD/8), HT*(VECHT-1)+HT/2-(int)(y*HT/8), 2, 2, 0, 360*64);
}
void x11_softu64_update()
{
  XSetForeground(xvectorinfo.dpy, xvectorinfo.gc, 0xff0000);
  XDrawLine(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, 0, HT*(VECHT-1)+HT, WD, HT*(VECHT-1));
  XSetForeground(xvectorinfo.dpy, xvectorinfo.gc, 0xffffff);
  XDrawLine(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, 0, HT*(VECHT-1)+HT/2, WD, HT*(VECHT-1)+HT/2);
  XSetForeground(xvectorinfo.dpy, xvectorinfo.gc, 0xffffff);
  XDrawLine(xvectorinfo.dpy, backBuffer, xvectorinfo.gc, WD/2, HT*(VECHT-1), WD/2, HT*(VECHT-1)+HT);
  XdbeSwapBuffers(xvectorinfo.dpy, &swapInfo, 1);
  XSync(xvectorinfo.dpy, 0);
}
void FP_to_X(int id, float *from)
{
  int i, j;
  Uint *to;
  to = (Uint*)(ximageinfo.ximage->data)+BITMAP*SCRWD*(id/SCRWD)+WD*(id%SCRWD);
  for (i=0; i<HT; i++,to+=WD*(SCRWD-1)) {
    for (j=0; j<WD; j++,to++,from++) {
      Uint color;
      if (fabsf(*from) < 0.000)
 color = 0x00000000;
      else if (fabsf(*from) < 0.063)
 color = 0x80000000;
      else if (fabsf(*from) < 0.125)
 color = 0xff000000;
      else if (fabsf(*from) < 0.188)
 color = 0x00008000;
      else if (fabsf(*from) < 0.250)
 color = 0x0000ff00;
      else if (fabsf(*from) < 0.313)
 color = 0x80008000;
      else if (fabsf(*from) < 0.375)
 color = 0xff00ff00;
      else if (fabsf(*from) < 0.437)
 color = 0x00800000;
      else if (fabsf(*from) < 0.500)
 color = 0x00ff0000;
      else if (fabsf(*from) < 0.563)
 color = 0x00808000;
      else if (fabsf(*from) < 0.625)
 color = 0x00ffff00;
      else if (fabsf(*from) < 0.688)
 color = 0x80800000;
      else if (fabsf(*from) < 0.750)
 color = 0xc0c00000;
      else if (fabsf(*from) < 0.813)
 color = 0xffff0000;
      else if (fabsf(*from) < 0.875)
 color = 0x80808000;
      else if (fabsf(*from) < 0.938)
 color = 0xc0c0c000;
      else
 color = 0xffffff00;
      *to = color;
    }
  }
}
void BOX_to_X(int id, int nx, int ny, int boxsize)
{
  int x, y;
  Uint *top;
  if (boxsize * nx > WD) {
    printf("in xdisp.c BOX_to_X: boxsize * nx > WD\n");
    return;
  }
  if (boxsize * ny > HT) {
    printf("in xdisp.c BOX_to_X: boxsize * ny > HT\n");
    return;
  }
  top = (Uint*)(ximageinfo.ximage->data)+BITMAP*SCRWD*(id/SCRWD)+WD*(id%SCRWD)
      + (HT-boxsize*ny)/2*WD*SCRWD+(WD-boxsize*nx)/2;
  for (y=0; y<=ny; y++) {
    for (x=0; x<=nx*boxsize; x++)
      top[y*boxsize*WD*SCRWD+x] = 0xffffff00;
  }
  for (y=0; y<=ny*boxsize; y++) {
    for (x=0; x<=nx; x++)
      top[y*WD*SCRWD+x*boxsize] = 0xffffff00;
  }
}
Uchar* membase;
sysinit(memsize, alignment) Uint memsize, alignment;
{
  if ((NLANE = emax7_open(2)) == ((void *)0))
    exit(1);
  membase = emax_info[0].ddr_mmap;
  {volatile int i; for (i=0; i<(memsize+sizeof(Dll)-1)/sizeof(Dll); i++) *((Dll*)membase+i)=0;}
  { int i;
    for (i=0; i<NLANE; i++) {
      emax7[i].dma_ctrl = emax_info[i].dma_mmap;
      emax7[i].reg_ctrl = emax_info[i].reg_mmap;
      ((struct reg_ctrl*)emax7[i].reg_ctrl)->i[0].cmd = CMD_RESET;
      usleep(1);
      ((struct reg_ctrl*)emax7[i].reg_ctrl)->i[0].adtr = emax_info[i].ddr_mmap - emax_info[i].lmm_phys;
      ((struct reg_ctrl*)emax7[i].reg_ctrl)->i[0].dmrp = 0LL;
      switch (((struct reg_ctrl*)emax7[0].reg_ctrl)->i[0].stat>>8 & 0xf) {
      case 3:EMAX_DEPTH = 64;break;
      case 2:EMAX_DEPTH = 32;break;
      case 1:EMAX_DEPTH = 16;break;
      case 0:EMAX_DEPTH = 8;break;
      default:
 printf("init_xmax: illegal stat=%x for setting EMAX_DEPTH\n",((struct reg_ctrl*)emax7[i].reg_ctrl)->i[0].stat>>8 & 0xf);
 exit(1);
      }
      printf("EMAX7[%d].DEPTH=%d\n", i, EMAX_DEPTH);
    }
  }
  printf("EMAX7: NLANE=%d DEPTH=%d\n", NLANE, EMAX_DEPTH);
}
Uint *in;
Uint *ker;
Uint *out0;
Uint *out1;
Uint *ip0, *ip1, *ip2, *ip3, *ip4, *ip5, *kp, *op;
int ic, dep, row, col, oc, z, y, x;
int ztop, top, iset;
int w, kidx;
int count0, count1, count2;
Uint Z[(320*240)];
main()
{
  printf("CONV_SELECT= %d\n", 1);
  printf("check1 IC %d OC %d D %d H %d W %d K %d\n", 1, 64, 20, 269, 244, 3);
  printf("check2 RMGRP %d NCHIP %d IMAP %d\n", 122, 1, 2);
  sysinit(1*20*269*244*sizeof(int)
         +1*64*3*3*3*sizeof(int)
         +64*20*269*244*sizeof(int)
         +64*20*269*244*sizeof(int),32);
  printf("membase: %08.8x\n", (Uint)membase);
  in = (Uint*)membase;
  ker = (Uint*)((Uchar*)in + 1*20*269*244*sizeof(int));
  out0 = (Uint*)((Uchar*)ker + 1*64*3*3*3*sizeof(int));
  out1 = (Uint*)((Uchar*)out0 + 64*20*269*244*sizeof(int));
  printf("in  : %08.8x\n", in);
  printf("ker : %08.8x\n", ker);
  printf("out0: %08.8x\n", out0);
  printf("out1: %08.8x\n", out1);
    printf("sizeof(int)=%d\n", sizeof(int));
    printf("sizeof(float)=%d\n", sizeof(float));
    FILE *file;
    int *array_load_temp;
    int array_length = 1*20*269*244;
    file = fopen("cnn3d_bins/befo_conv1.bin", "rb");
    array_load_temp = (int*) malloc(array_length * sizeof(float));
    fread(array_load_temp, sizeof(float), array_length, file);
    fclose(file);
  for (ic=0; ic<1; ic++) {
    for (dep=0; dep<20; dep++) {
      for (row=0; row<269; row++) {
       for (col=0; col<244; col++) {
   *(float*)&in[ic*20*269*244 +dep*269*244 +row*244 +col] = *(float*)&array_load_temp[ic*20*269*244 +dep*269*244 +row*244 +col];
  }}}}
    printf("input is: \n");
    for (int i = 0; i < 10; ++i) {
        printf("%f ", *(float*)&in[i]);
    }
    printf("\n");
    free(array_load_temp);
    array_length = 64*1*3*3*3;
    file = fopen("cnn3d_bins/conv1_weight.bin", "rb");
    if (file == ((void *)0)) {
        printf("Unable to open the file.\n");
        return 1;
    }
    array_load_temp = (int*) malloc(array_length * sizeof(float));
    if (array_load_temp == ((void *)0)) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    fread(array_load_temp, sizeof(float), array_length, file);
    fclose(file);
  for (oc=0; oc<64; oc++) {
    for (ic=0; ic<1; ic++) {
      for (z=0; z<3; z++) {
        for (y=0; y<3; y++) {
          for (x=0; x<3; x++) {
            *(float*)&ker[ic*64*3*3*3 +oc*3*3*3 +z*3*3 +y*3 +x] = *(float*)&array_load_temp[ic*64*3*3*3 +oc*3*3*3 +z*3*3 +y*3 +x];
          }}}}}
    printf("ker is: \n");
    for (int i = 0; i < 10; ++i) {
        printf("%f ", *(float*)&ker[i]);
    }
    printf("\n");
    free(array_load_temp);
      clock_t start_time, end_time;
      double elapsed_time;
  x11_open(0);
  reset_nanosec(0);
  get_nanosec(0,0);
  show_nanosec(0);
  printf("start_time: %ld\n", start_time);
  reset_nanosec(0);
  imax(0);
  get_nanosec(0,0);
  show_nanosec(0);
  printf("out1 is: \n");
      for (int i = 0, j = 0; i < 10; j++) {
        if ((double)*(float*)&out1[j]==0.0){
          continue;
        }
        printf("%d:%e ", j, (double)*(float*)&out1[j]);
        i++;
      }
      printf("\n");
printf("Num of MULT: orig=%d imax=%d\n", count0, count1);
FILE *fileout = fopen("imax_out/imax_conv1.bin", "wb");
if (fileout != ((void *)0)) {
    printf("OC*D*H*W=%d\n", 64*20*269*244);
    printf("sizeof(float)=%d\n", sizeof(float));
    fwrite(out1, sizeof(float), 64*20*269*244, fileout);
    fclose(fileout);
    printf("Wrote file out\n");
} else {
    printf("Failed to open file for out writing.\n");
}
  show_nanosec(0);
  return 0;
  printf("==== Normal end. Type any in ImageWin ====\n");
  while (!x11_checkevent());
}
imax(int LANE) {
  Ull CHIP;
  Ull LOOP1, LOOP0;
  Ull INIT1, INIT0;
  Ull AR[64][4];
  Ull BR[64][4][4];
  Ull r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15;
  Ull r16, r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31;
  Ull cc0, cc1, cc2, cc3, ex0, ex1;
  Ull cofs, rofs, oofs, k;
  printf("<<<IMAX>>>\n");
  for (ztop=1; ztop<20 -1; ztop++) {
    for (top=1; top<269 -1; top+=122) {
      for (iset=0; iset<1; iset+=2) {
 Uint *ip[2], *it[3][2], *ip0[2][3*3*3], *ip1[2][3*3*3];
 for (k=0; k<2; k++) {
   ip[k] = &in[(iset+k)*20*269*244];
   it[0][k] = ip[k]+(ztop-1)*269*244 +(top-1)*244 +1-1;
   it[1][k] = ip[k]+(ztop+0)*269*244 +(top-1)*244 +1-1;
   it[2][k] = ip[k]+(ztop+1)*269*244 +(top-1)*244 +1-1;
   ip0[k][ 0] = ip[k]+(ztop-1)*269*244 +(top-1)*244 +1-1;
    ip0[k][ 1] = ip[k]+(ztop-1)*269*244 +(top-1)*244 +1+0;
    ip0[k][ 2] = ip[k]+(ztop-1)*269*244 +(top-1)*244 +1+1;
   ip0[k][ 3] = ip[k]+(ztop-1)*269*244 +(top+0)*244 +1-1;
    ip0[k][ 4] = ip[k]+(ztop-1)*269*244 +(top+0)*244 +1+0;
    ip0[k][ 5] = ip[k]+(ztop-1)*269*244 +(top+0)*244 +1+1;
   ip0[k][ 6] = ip[k]+(ztop-1)*269*244 +(top+1)*244 +1-1;
    ip0[k][ 7] = ip[k]+(ztop-1)*269*244 +(top+1)*244 +1+0;
    ip0[k][ 8] = ip[k]+(ztop-1)*269*244 +(top+1)*244 +1+1;
   ip0[k][ 9] = ip[k]+(ztop+0)*269*244 +(top-1)*244 +1-1;
    ip0[k][10] = ip[k]+(ztop+0)*269*244 +(top-1)*244 +1+0;
    ip0[k][11] = ip[k]+(ztop+0)*269*244 +(top-1)*244 +1+1;
   ip0[k][12] = ip[k]+(ztop+0)*269*244 +(top+0)*244 +1-1;
    ip0[k][13] = ip[k]+(ztop+0)*269*244 +(top+0)*244 +1+0;
    ip0[k][14] = ip[k]+(ztop+0)*269*244 +(top+0)*244 +1+1;
   ip0[k][15] = ip[k]+(ztop+0)*269*244 +(top+1)*244 +1-1;
    ip0[k][16] = ip[k]+(ztop+0)*269*244 +(top+1)*244 +1+0;
    ip0[k][17] = ip[k]+(ztop+0)*269*244 +(top+1)*244 +1+1;
   ip0[k][18] = ip[k]+(ztop+1)*269*244 +(top-1)*244 +1-1;
    ip0[k][19] = ip[k]+(ztop+1)*269*244 +(top-1)*244 +1+0;
    ip0[k][20] = ip[k]+(ztop+1)*269*244 +(top-1)*244 +1+1;
   ip0[k][21] = ip[k]+(ztop+1)*269*244 +(top+0)*244 +1-1;
    ip0[k][22] = ip[k]+(ztop+1)*269*244 +(top+0)*244 +1+0;
    ip0[k][23] = ip[k]+(ztop+1)*269*244 +(top+0)*244 +1+1;
   ip0[k][24] = ip[k]+(ztop+1)*269*244 +(top+1)*244 +1-1;
    ip0[k][25] = ip[k]+(ztop+1)*269*244 +(top+1)*244 +1+0;
    ip0[k][26] = ip[k]+(ztop+1)*269*244 +(top+1)*244 +1+1;
   ip1[k][ 0] = ip[k]+(ztop-1)*269*244 +(top-1)*244 +1+1;
    ip1[k][ 1] = ip[k]+(ztop-1)*269*244 +(top-1)*244 +1+2;
    ip1[k][ 2] = ip[k]+(ztop-1)*269*244 +(top-1)*244 +1+3;
   ip1[k][ 3] = ip[k]+(ztop-1)*269*244 +(top+0)*244 +1+1;
    ip1[k][ 4] = ip[k]+(ztop-1)*269*244 +(top+0)*244 +1+2;
    ip1[k][ 5] = ip[k]+(ztop-1)*269*244 +(top+0)*244 +1+3;
   ip1[k][ 6] = ip[k]+(ztop-1)*269*244 +(top+1)*244 +1+1;
    ip1[k][ 7] = ip[k]+(ztop-1)*269*244 +(top+1)*244 +1+2;
    ip1[k][ 8] = ip[k]+(ztop-1)*269*244 +(top+1)*244 +1+3;
   ip1[k][ 9] = ip[k]+(ztop+0)*269*244 +(top-1)*244 +1+1;
    ip1[k][10] = ip[k]+(ztop+0)*269*244 +(top-1)*244 +1+2;
    ip1[k][11] = ip[k]+(ztop+0)*269*244 +(top-1)*244 +1+3;
   ip1[k][12] = ip[k]+(ztop+0)*269*244 +(top+0)*244 +1+1;
    ip1[k][13] = ip[k]+(ztop+0)*269*244 +(top+0)*244 +1+2;
    ip1[k][14] = ip[k]+(ztop+0)*269*244 +(top+0)*244 +1+3;
   ip1[k][15] = ip[k]+(ztop+0)*269*244 +(top+1)*244 +1+1;
    ip1[k][16] = ip[k]+(ztop+0)*269*244 +(top+1)*244 +1+2;
    ip1[k][17] = ip[k]+(ztop+0)*269*244 +(top+1)*244 +1+3;
   ip1[k][18] = ip[k]+(ztop+1)*269*244 +(top-1)*244 +1+1;
    ip1[k][19] = ip[k]+(ztop+1)*269*244 +(top-1)*244 +1+2;
    ip1[k][20] = ip[k]+(ztop+1)*269*244 +(top-1)*244 +1+3;
   ip1[k][21] = ip[k]+(ztop+1)*269*244 +(top+0)*244 +1+1;
    ip1[k][22] = ip[k]+(ztop+1)*269*244 +(top+0)*244 +1+2;
    ip1[k][23] = ip[k]+(ztop+1)*269*244 +(top+0)*244 +1+3;
   ip1[k][24] = ip[k]+(ztop+1)*269*244 +(top+1)*244 +1+1;
    ip1[k][25] = ip[k]+(ztop+1)*269*244 +(top+1)*244 +1+2;
    ip1[k][26] = ip[k]+(ztop+1)*269*244 +(top+1)*244 +1+3;
 }
 for (oc=0; oc<64/1; oc+=4) {
   Uint *kp0[2][1], *kp1[2][1], *kp2[2][1], *kp3[2][1];
   Uint *op0[1], *op1[1], *op2[1], *op3[1];
   Uint *ot0[1], *ot1[1], *ot2[1], *ot3[1];
   for (CHIP=0; CHIP<1; CHIP++) {
     Uint choc = CHIP*64/1 +oc;
     for (k=0; k<2; k++) {
       kp0[k][CHIP] = ker+((choc+0)*1 +iset+k)*3*3*3;
       kp1[k][CHIP] = ker+((choc+1)*1 +iset+k)*3*3*3;
       kp2[k][CHIP] = ker+((choc+2)*1 +iset+k)*3*3*3;
       kp3[k][CHIP] = ker+((choc+3)*1 +iset+k)*3*3*3;
     }
     op0[CHIP] = out1+(choc+0)*20*269*244 +ztop*269*244 +top*244 +0; op1[CHIP] = out1+(choc+1)*20*269*244 +ztop*269*244 +top*244 +0; op2[CHIP] = out1+(choc+2)*20*269*244 +ztop*269*244 +top*244 +0; op3[CHIP] = out1+(choc+3)*20*269*244 +ztop*269*244 +top*244 +0;
     ot0[CHIP] = out1+(choc+0)*20*269*244 +ztop*269*244 +top*244 +0; ot1[CHIP] = out1+(choc+1)*20*269*244 +ztop*269*244 +top*244 +0; ot2[CHIP] = out1+(choc+2)*20*269*244 +ztop*269*244 +top*244 +0; ot3[CHIP] = out1+(choc+3)*20*269*244 +ztop*269*244 +top*244 +0;
   }
#ifndef EMAXSC
volatile emax7_conf_cnn();
#endif
#ifndef EMAXSC
	((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].mcid = 0; // NCHIP-1
#endif
	LOOP1 = ((122));
	rofs = ((0-269*4));
	LOOP0 = (((244 -2)/2));
	cofs = ((0-4));
#ifdef EMAXSC
/* EMAXSC start */
SCBR[63].r[0][0][0] = LOOP1;
SCBR[63].r[0][1][0] = LOOP1;
SCBR[63].r[0][0][1] = -1LL;
SCBR[63].r[0][1][1] = -1LL;
SCBR[63].r[0][0][2] = LOOP0;
SCBR[63].r[0][1][2] = LOOP0;
SCBR[63].r[0][0][3] = cofs;
SCBR[63].r[0][1][3] = cofs;
SCBR[63].r[0][0][4] = 8;
SCBR[63].r[0][1][4] = 8;
SCBR[63].r[0][0][5] = rofs;
SCBR[63].r[0][1][5] = rofs;
SCBR[63].r[0][0][6] = (269)*(4);
SCBR[63].r[0][1][6] = (269)*(4);
SCM0[2].b[0][0] = (Ull)kp1[0][0];
SCM0[2].o[0][0] = (Ull)0LL;
SCM1[2].b[0][0] = (Ull)kp0[0][0];
SCM1[2].o[0][0] = (Ull)0LL;
SCM0[2].b[0][1] = (Ull)kp3[0][0];
SCM0[2].o[0][1] = (Ull)0LL;
SCM1[2].b[0][1] = (Ull)kp2[0][0];
SCM1[2].o[0][1] = (Ull)0LL;
SCM0[2].b[0][2] = (Ull)ip0[0][0];
SCM1[2].b[0][2] = (Ull)ip1[0][0];
SCM0[3].b[0][0] = (Ull)kp1[0][0];
SCM0[3].o[0][0] = (Ull)4LL;
SCM1[3].b[0][0] = (Ull)kp0[0][0];
SCM1[3].o[0][0] = (Ull)4LL;
SCM0[3].b[0][1] = (Ull)kp3[0][0];
SCM0[3].o[0][1] = (Ull)4LL;
SCM1[3].b[0][1] = (Ull)kp2[0][0];
SCM1[3].o[0][1] = (Ull)4LL;
SCM0[3].b[0][2] = (Ull)ip0[0][1];
SCM1[3].b[0][2] = (Ull)ip1[0][1];
SCM0[4].b[0][0] = (Ull)kp1[0][0];
SCM0[4].o[0][0] = (Ull)8LL;
SCM1[4].b[0][0] = (Ull)kp0[0][0];
SCM1[4].o[0][0] = (Ull)8LL;
SCM0[4].b[0][1] = (Ull)kp3[0][0];
SCM0[4].o[0][1] = (Ull)8LL;
SCM1[4].b[0][1] = (Ull)kp2[0][0];
SCM1[4].o[0][1] = (Ull)8LL;
SCM0[4].b[0][2] = (Ull)ip0[0][2];
SCM1[4].b[0][2] = (Ull)ip1[0][2];
SCM0[5].b[0][0] = (Ull)kp1[0][0];
SCM0[5].o[0][0] = (Ull)12LL;
SCM1[5].b[0][0] = (Ull)kp0[0][0];
SCM1[5].o[0][0] = (Ull)12LL;
SCM0[5].b[0][1] = (Ull)kp3[0][0];
SCM0[5].o[0][1] = (Ull)12LL;
SCM1[5].b[0][1] = (Ull)kp2[0][0];
SCM1[5].o[0][1] = (Ull)12LL;
SCM0[5].b[0][2] = (Ull)ip0[0][3];
SCM1[5].b[0][2] = (Ull)ip1[0][3];
SCM0[6].b[0][0] = (Ull)kp1[0][0];
SCM0[6].o[0][0] = (Ull)16LL;
SCM1[6].b[0][0] = (Ull)kp0[0][0];
SCM1[6].o[0][0] = (Ull)16LL;
SCM0[6].b[0][1] = (Ull)kp3[0][0];
SCM0[6].o[0][1] = (Ull)16LL;
SCM1[6].b[0][1] = (Ull)kp2[0][0];
SCM1[6].o[0][1] = (Ull)16LL;
SCM0[6].b[0][2] = (Ull)ip0[0][4];
SCM1[6].b[0][2] = (Ull)ip1[0][4];
SCM0[7].b[0][0] = (Ull)kp1[0][0];
SCM0[7].o[0][0] = (Ull)20LL;
SCM1[7].b[0][0] = (Ull)kp0[0][0];
SCM1[7].o[0][0] = (Ull)20LL;
SCM0[7].b[0][1] = (Ull)kp3[0][0];
SCM0[7].o[0][1] = (Ull)20LL;
SCM1[7].b[0][1] = (Ull)kp2[0][0];
SCM1[7].o[0][1] = (Ull)20LL;
SCM0[7].b[0][2] = (Ull)ip0[0][5];
SCM1[7].b[0][2] = (Ull)ip1[0][5];
SCM0[8].b[0][0] = (Ull)kp1[0][0];
SCM0[8].o[0][0] = (Ull)24LL;
SCM1[8].b[0][0] = (Ull)kp0[0][0];
SCM1[8].o[0][0] = (Ull)24LL;
SCM0[8].b[0][1] = (Ull)kp3[0][0];
SCM0[8].o[0][1] = (Ull)24LL;
SCM1[8].b[0][1] = (Ull)kp2[0][0];
SCM1[8].o[0][1] = (Ull)24LL;
SCM0[8].b[0][2] = (Ull)ip0[0][6];
SCM1[8].b[0][2] = (Ull)ip1[0][6];
SCM0[9].b[0][0] = (Ull)kp1[0][0];
SCM0[9].o[0][0] = (Ull)28LL;
SCM1[9].b[0][0] = (Ull)kp0[0][0];
SCM1[9].o[0][0] = (Ull)28LL;
SCM0[9].b[0][1] = (Ull)kp3[0][0];
SCM0[9].o[0][1] = (Ull)28LL;
SCM1[9].b[0][1] = (Ull)kp2[0][0];
SCM1[9].o[0][1] = (Ull)28LL;
SCM0[9].b[0][2] = (Ull)ip0[0][7];
SCM1[9].b[0][2] = (Ull)ip1[0][7];
SCM0[10].b[0][0] = (Ull)kp1[0][0];
SCM0[10].o[0][0] = (Ull)32LL;
SCM1[10].b[0][0] = (Ull)kp0[0][0];
SCM1[10].o[0][0] = (Ull)32LL;
SCM0[10].b[0][1] = (Ull)kp3[0][0];
SCM0[10].o[0][1] = (Ull)32LL;
SCM1[10].b[0][1] = (Ull)kp2[0][0];
SCM1[10].o[0][1] = (Ull)32LL;
SCM0[10].b[0][2] = (Ull)ip0[0][8];
SCM1[10].b[0][2] = (Ull)ip1[0][8];
SCM0[11].b[0][0] = (Ull)kp1[0][0];
SCM0[11].o[0][0] = (Ull)36LL;
SCM1[11].b[0][0] = (Ull)kp0[0][0];
SCM1[11].o[0][0] = (Ull)36LL;
SCM0[11].b[0][1] = (Ull)kp3[0][0];
SCM0[11].o[0][1] = (Ull)36LL;
SCM1[11].b[0][1] = (Ull)kp2[0][0];
SCM1[11].o[0][1] = (Ull)36LL;
SCM0[11].b[0][2] = (Ull)ip0[0][9];
SCM1[11].b[0][2] = (Ull)ip1[0][9];
SCM0[12].b[0][0] = (Ull)kp1[0][0];
SCM0[12].o[0][0] = (Ull)40LL;
SCM1[12].b[0][0] = (Ull)kp0[0][0];
SCM1[12].o[0][0] = (Ull)40LL;
SCM0[12].b[0][1] = (Ull)kp3[0][0];
SCM0[12].o[0][1] = (Ull)40LL;
SCM1[12].b[0][1] = (Ull)kp2[0][0];
SCM1[12].o[0][1] = (Ull)40LL;
SCM0[12].b[0][2] = (Ull)ip0[0][10];
SCM1[12].b[0][2] = (Ull)ip1[0][10];
SCM0[13].b[0][0] = (Ull)kp1[0][0];
SCM0[13].o[0][0] = (Ull)44LL;
SCM1[13].b[0][0] = (Ull)kp0[0][0];
SCM1[13].o[0][0] = (Ull)44LL;
SCM0[13].b[0][1] = (Ull)kp3[0][0];
SCM0[13].o[0][1] = (Ull)44LL;
SCM1[13].b[0][1] = (Ull)kp2[0][0];
SCM1[13].o[0][1] = (Ull)44LL;
SCM0[13].b[0][2] = (Ull)ip0[0][11];
SCM1[13].b[0][2] = (Ull)ip1[0][11];
SCM0[14].b[0][0] = (Ull)kp1[0][0];
SCM0[14].o[0][0] = (Ull)48LL;
SCM1[14].b[0][0] = (Ull)kp0[0][0];
SCM1[14].o[0][0] = (Ull)48LL;
SCM0[14].b[0][1] = (Ull)kp3[0][0];
SCM0[14].o[0][1] = (Ull)48LL;
SCM1[14].b[0][1] = (Ull)kp2[0][0];
SCM1[14].o[0][1] = (Ull)48LL;
SCM0[14].b[0][2] = (Ull)ip0[0][12];
SCM1[14].b[0][2] = (Ull)ip1[0][12];
SCM0[15].b[0][0] = (Ull)kp1[0][0];
SCM0[15].o[0][0] = (Ull)52LL;
SCM1[15].b[0][0] = (Ull)kp0[0][0];
SCM1[15].o[0][0] = (Ull)52LL;
SCM0[15].b[0][1] = (Ull)kp3[0][0];
SCM0[15].o[0][1] = (Ull)52LL;
SCM1[15].b[0][1] = (Ull)kp2[0][0];
SCM1[15].o[0][1] = (Ull)52LL;
SCM0[15].b[0][2] = (Ull)ip0[0][13];
SCM1[15].b[0][2] = (Ull)ip1[0][13];
SCM0[16].b[0][0] = (Ull)kp1[0][0];
SCM0[16].o[0][0] = (Ull)56LL;
SCM1[16].b[0][0] = (Ull)kp0[0][0];
SCM1[16].o[0][0] = (Ull)56LL;
SCM0[16].b[0][1] = (Ull)kp3[0][0];
SCM0[16].o[0][1] = (Ull)56LL;
SCM1[16].b[0][1] = (Ull)kp2[0][0];
SCM1[16].o[0][1] = (Ull)56LL;
SCM0[16].b[0][2] = (Ull)ip0[0][14];
SCM1[16].b[0][2] = (Ull)ip1[0][14];
SCM0[17].b[0][0] = (Ull)kp1[0][0];
SCM0[17].o[0][0] = (Ull)60LL;
SCM1[17].b[0][0] = (Ull)kp0[0][0];
SCM1[17].o[0][0] = (Ull)60LL;
SCM0[17].b[0][1] = (Ull)kp3[0][0];
SCM0[17].o[0][1] = (Ull)60LL;
SCM1[17].b[0][1] = (Ull)kp2[0][0];
SCM1[17].o[0][1] = (Ull)60LL;
SCM0[17].b[0][2] = (Ull)ip0[0][15];
SCM1[17].b[0][2] = (Ull)ip1[0][15];
SCM0[18].b[0][0] = (Ull)kp1[0][0];
SCM0[18].o[0][0] = (Ull)64LL;
SCM1[18].b[0][0] = (Ull)kp0[0][0];
SCM1[18].o[0][0] = (Ull)64LL;
SCM0[18].b[0][1] = (Ull)kp3[0][0];
SCM0[18].o[0][1] = (Ull)64LL;
SCM1[18].b[0][1] = (Ull)kp2[0][0];
SCM1[18].o[0][1] = (Ull)64LL;
SCM0[18].b[0][2] = (Ull)ip0[0][16];
SCM1[18].b[0][2] = (Ull)ip1[0][16];
SCM0[19].b[0][0] = (Ull)kp1[0][0];
SCM0[19].o[0][0] = (Ull)68LL;
SCM1[19].b[0][0] = (Ull)kp0[0][0];
SCM1[19].o[0][0] = (Ull)68LL;
SCM0[19].b[0][1] = (Ull)kp3[0][0];
SCM0[19].o[0][1] = (Ull)68LL;
SCM1[19].b[0][1] = (Ull)kp2[0][0];
SCM1[19].o[0][1] = (Ull)68LL;
SCM0[19].b[0][2] = (Ull)ip0[0][17];
SCM1[19].b[0][2] = (Ull)ip1[0][17];
SCM0[20].b[0][0] = (Ull)kp1[0][0];
SCM0[20].o[0][0] = (Ull)72LL;
SCM1[20].b[0][0] = (Ull)kp0[0][0];
SCM1[20].o[0][0] = (Ull)72LL;
SCM0[20].b[0][1] = (Ull)kp3[0][0];
SCM0[20].o[0][1] = (Ull)72LL;
SCM1[20].b[0][1] = (Ull)kp2[0][0];
SCM1[20].o[0][1] = (Ull)72LL;
SCM0[20].b[0][2] = (Ull)ip0[0][18];
SCM1[20].b[0][2] = (Ull)ip1[0][18];
SCM0[21].b[0][0] = (Ull)kp1[0][0];
SCM0[21].o[0][0] = (Ull)76LL;
SCM1[21].b[0][0] = (Ull)kp0[0][0];
SCM1[21].o[0][0] = (Ull)76LL;
SCM0[21].b[0][1] = (Ull)kp3[0][0];
SCM0[21].o[0][1] = (Ull)76LL;
SCM1[21].b[0][1] = (Ull)kp2[0][0];
SCM1[21].o[0][1] = (Ull)76LL;
SCM0[21].b[0][2] = (Ull)ip0[0][19];
SCM1[21].b[0][2] = (Ull)ip1[0][19];
SCM0[22].b[0][0] = (Ull)kp1[0][0];
SCM0[22].o[0][0] = (Ull)80LL;
SCM1[22].b[0][0] = (Ull)kp0[0][0];
SCM1[22].o[0][0] = (Ull)80LL;
SCM0[22].b[0][1] = (Ull)kp3[0][0];
SCM0[22].o[0][1] = (Ull)80LL;
SCM1[22].b[0][1] = (Ull)kp2[0][0];
SCM1[22].o[0][1] = (Ull)80LL;
SCM0[22].b[0][2] = (Ull)ip0[0][20];
SCM1[22].b[0][2] = (Ull)ip1[0][20];
SCM0[23].b[0][0] = (Ull)kp1[0][0];
SCM0[23].o[0][0] = (Ull)84LL;
SCM1[23].b[0][0] = (Ull)kp0[0][0];
SCM1[23].o[0][0] = (Ull)84LL;
SCM0[23].b[0][1] = (Ull)kp3[0][0];
SCM0[23].o[0][1] = (Ull)84LL;
SCM1[23].b[0][1] = (Ull)kp2[0][0];
SCM1[23].o[0][1] = (Ull)84LL;
SCM0[23].b[0][2] = (Ull)ip0[0][21];
SCM1[23].b[0][2] = (Ull)ip1[0][21];
SCM0[24].b[0][0] = (Ull)kp1[0][0];
SCM0[24].o[0][0] = (Ull)88LL;
SCM1[24].b[0][0] = (Ull)kp0[0][0];
SCM1[24].o[0][0] = (Ull)88LL;
SCM0[24].b[0][1] = (Ull)kp3[0][0];
SCM0[24].o[0][1] = (Ull)88LL;
SCM1[24].b[0][1] = (Ull)kp2[0][0];
SCM1[24].o[0][1] = (Ull)88LL;
SCM0[24].b[0][2] = (Ull)ip0[0][22];
SCM1[24].b[0][2] = (Ull)ip1[0][22];
SCM0[25].b[0][0] = (Ull)kp1[0][0];
SCM0[25].o[0][0] = (Ull)92LL;
SCM1[25].b[0][0] = (Ull)kp0[0][0];
SCM1[25].o[0][0] = (Ull)92LL;
SCM0[25].b[0][1] = (Ull)kp3[0][0];
SCM0[25].o[0][1] = (Ull)92LL;
SCM1[25].b[0][1] = (Ull)kp2[0][0];
SCM1[25].o[0][1] = (Ull)92LL;
SCM0[25].b[0][2] = (Ull)ip0[0][23];
SCM1[25].b[0][2] = (Ull)ip1[0][23];
SCM0[26].b[0][0] = (Ull)kp1[0][0];
SCM0[26].o[0][0] = (Ull)96LL;
SCM1[26].b[0][0] = (Ull)kp0[0][0];
SCM1[26].o[0][0] = (Ull)96LL;
SCM0[26].b[0][1] = (Ull)kp3[0][0];
SCM0[26].o[0][1] = (Ull)96LL;
SCM1[26].b[0][1] = (Ull)kp2[0][0];
SCM1[26].o[0][1] = (Ull)96LL;
SCM0[26].b[0][2] = (Ull)ip0[0][24];
SCM1[26].b[0][2] = (Ull)ip1[0][24];
SCM0[27].b[0][0] = (Ull)kp1[0][0];
SCM0[27].o[0][0] = (Ull)100LL;
SCM1[27].b[0][0] = (Ull)kp0[0][0];
SCM1[27].o[0][0] = (Ull)100LL;
SCM0[27].b[0][1] = (Ull)kp3[0][0];
SCM0[27].o[0][1] = (Ull)100LL;
SCM1[27].b[0][1] = (Ull)kp2[0][0];
SCM1[27].o[0][1] = (Ull)100LL;
SCM0[27].b[0][2] = (Ull)ip0[0][25];
SCM1[27].b[0][2] = (Ull)ip1[0][25];
SCM0[28].b[0][0] = (Ull)kp1[0][0];
SCM0[28].o[0][0] = (Ull)104LL;
SCM1[28].b[0][0] = (Ull)kp0[0][0];
SCM1[28].o[0][0] = (Ull)104LL;
SCM0[28].b[0][1] = (Ull)kp3[0][0];
SCM0[28].o[0][1] = (Ull)104LL;
SCM1[28].b[0][1] = (Ull)kp2[0][0];
SCM1[28].o[0][1] = (Ull)104LL;
SCM0[28].b[0][2] = (Ull)ip0[0][26];
SCM1[28].b[0][2] = (Ull)ip1[0][26];
SCM0[29].b[0][0] = (Ull)kp1[1][0];
SCM0[29].o[0][0] = (Ull)0LL;
SCM1[29].b[0][0] = (Ull)kp0[1][0];
SCM1[29].o[0][0] = (Ull)0LL;
SCM0[29].b[0][1] = (Ull)kp3[1][0];
SCM0[29].o[0][1] = (Ull)0LL;
SCM1[29].b[0][1] = (Ull)kp2[1][0];
SCM1[29].o[0][1] = (Ull)0LL;
SCM0[29].b[0][2] = (Ull)ip0[1][0];
SCM1[29].b[0][2] = (Ull)ip1[1][0];
SCM0[30].b[0][0] = (Ull)kp1[1][0];
SCM0[30].o[0][0] = (Ull)4LL;
SCM1[30].b[0][0] = (Ull)kp0[1][0];
SCM1[30].o[0][0] = (Ull)4LL;
SCM0[30].b[0][1] = (Ull)kp3[1][0];
SCM0[30].o[0][1] = (Ull)4LL;
SCM1[30].b[0][1] = (Ull)kp2[1][0];
SCM1[30].o[0][1] = (Ull)4LL;
SCM0[30].b[0][2] = (Ull)ip0[1][1];
SCM1[30].b[0][2] = (Ull)ip1[1][1];
SCM0[31].b[0][0] = (Ull)kp1[1][0];
SCM0[31].o[0][0] = (Ull)8LL;
SCM1[31].b[0][0] = (Ull)kp0[1][0];
SCM1[31].o[0][0] = (Ull)8LL;
SCM0[31].b[0][1] = (Ull)kp3[1][0];
SCM0[31].o[0][1] = (Ull)8LL;
SCM1[31].b[0][1] = (Ull)kp2[1][0];
SCM1[31].o[0][1] = (Ull)8LL;
SCM0[31].b[0][2] = (Ull)ip0[1][2];
SCM1[31].b[0][2] = (Ull)ip1[1][2];
SCM0[32].b[0][0] = (Ull)kp1[1][0];
SCM0[32].o[0][0] = (Ull)12LL;
SCM1[32].b[0][0] = (Ull)kp0[1][0];
SCM1[32].o[0][0] = (Ull)12LL;
SCM0[32].b[0][1] = (Ull)kp3[1][0];
SCM0[32].o[0][1] = (Ull)12LL;
SCM1[32].b[0][1] = (Ull)kp2[1][0];
SCM1[32].o[0][1] = (Ull)12LL;
SCM0[32].b[0][2] = (Ull)ip0[1][3];
SCM1[32].b[0][2] = (Ull)ip1[1][3];
SCM0[33].b[0][0] = (Ull)kp1[1][0];
SCM0[33].o[0][0] = (Ull)16LL;
SCM1[33].b[0][0] = (Ull)kp0[1][0];
SCM1[33].o[0][0] = (Ull)16LL;
SCM0[33].b[0][1] = (Ull)kp3[1][0];
SCM0[33].o[0][1] = (Ull)16LL;
SCM1[33].b[0][1] = (Ull)kp2[1][0];
SCM1[33].o[0][1] = (Ull)16LL;
SCM0[33].b[0][2] = (Ull)ip0[1][4];
SCM1[33].b[0][2] = (Ull)ip1[1][4];
SCM0[34].b[0][0] = (Ull)kp1[1][0];
SCM0[34].o[0][0] = (Ull)20LL;
SCM1[34].b[0][0] = (Ull)kp0[1][0];
SCM1[34].o[0][0] = (Ull)20LL;
SCM0[34].b[0][1] = (Ull)kp3[1][0];
SCM0[34].o[0][1] = (Ull)20LL;
SCM1[34].b[0][1] = (Ull)kp2[1][0];
SCM1[34].o[0][1] = (Ull)20LL;
SCM0[34].b[0][2] = (Ull)ip0[1][5];
SCM1[34].b[0][2] = (Ull)ip1[1][5];
SCM0[35].b[0][0] = (Ull)kp1[1][0];
SCM0[35].o[0][0] = (Ull)24LL;
SCM1[35].b[0][0] = (Ull)kp0[1][0];
SCM1[35].o[0][0] = (Ull)24LL;
SCM0[35].b[0][1] = (Ull)kp3[1][0];
SCM0[35].o[0][1] = (Ull)24LL;
SCM1[35].b[0][1] = (Ull)kp2[1][0];
SCM1[35].o[0][1] = (Ull)24LL;
SCM0[35].b[0][2] = (Ull)ip0[1][6];
SCM1[35].b[0][2] = (Ull)ip1[1][6];
SCM0[36].b[0][0] = (Ull)kp1[1][0];
SCM0[36].o[0][0] = (Ull)28LL;
SCM1[36].b[0][0] = (Ull)kp0[1][0];
SCM1[36].o[0][0] = (Ull)28LL;
SCM0[36].b[0][1] = (Ull)kp3[1][0];
SCM0[36].o[0][1] = (Ull)28LL;
SCM1[36].b[0][1] = (Ull)kp2[1][0];
SCM1[36].o[0][1] = (Ull)28LL;
SCM0[36].b[0][2] = (Ull)ip0[1][7];
SCM1[36].b[0][2] = (Ull)ip1[1][7];
SCM0[37].b[0][0] = (Ull)kp1[1][0];
SCM0[37].o[0][0] = (Ull)32LL;
SCM1[37].b[0][0] = (Ull)kp0[1][0];
SCM1[37].o[0][0] = (Ull)32LL;
SCM0[37].b[0][1] = (Ull)kp3[1][0];
SCM0[37].o[0][1] = (Ull)32LL;
SCM1[37].b[0][1] = (Ull)kp2[1][0];
SCM1[37].o[0][1] = (Ull)32LL;
SCM0[37].b[0][2] = (Ull)ip0[1][8];
SCM1[37].b[0][2] = (Ull)ip1[1][8];
SCM0[38].b[0][0] = (Ull)kp1[1][0];
SCM0[38].o[0][0] = (Ull)36LL;
SCM1[38].b[0][0] = (Ull)kp0[1][0];
SCM1[38].o[0][0] = (Ull)36LL;
SCM0[38].b[0][1] = (Ull)kp3[1][0];
SCM0[38].o[0][1] = (Ull)36LL;
SCM1[38].b[0][1] = (Ull)kp2[1][0];
SCM1[38].o[0][1] = (Ull)36LL;
SCM0[38].b[0][2] = (Ull)ip0[1][9];
SCM1[38].b[0][2] = (Ull)ip1[1][9];
SCM0[39].b[0][0] = (Ull)kp1[1][0];
SCM0[39].o[0][0] = (Ull)40LL;
SCM1[39].b[0][0] = (Ull)kp0[1][0];
SCM1[39].o[0][0] = (Ull)40LL;
SCM0[39].b[0][1] = (Ull)kp3[1][0];
SCM0[39].o[0][1] = (Ull)40LL;
SCM1[39].b[0][1] = (Ull)kp2[1][0];
SCM1[39].o[0][1] = (Ull)40LL;
SCM0[39].b[0][2] = (Ull)ip0[1][10];
SCM1[39].b[0][2] = (Ull)ip1[1][10];
SCM0[40].b[0][0] = (Ull)kp1[1][0];
SCM0[40].o[0][0] = (Ull)44LL;
SCM1[40].b[0][0] = (Ull)kp0[1][0];
SCM1[40].o[0][0] = (Ull)44LL;
SCM0[40].b[0][1] = (Ull)kp3[1][0];
SCM0[40].o[0][1] = (Ull)44LL;
SCM1[40].b[0][1] = (Ull)kp2[1][0];
SCM1[40].o[0][1] = (Ull)44LL;
SCM0[40].b[0][2] = (Ull)ip0[1][11];
SCM1[40].b[0][2] = (Ull)ip1[1][11];
SCM0[41].b[0][0] = (Ull)kp1[1][0];
SCM0[41].o[0][0] = (Ull)48LL;
SCM1[41].b[0][0] = (Ull)kp0[1][0];
SCM1[41].o[0][0] = (Ull)48LL;
SCM0[41].b[0][1] = (Ull)kp3[1][0];
SCM0[41].o[0][1] = (Ull)48LL;
SCM1[41].b[0][1] = (Ull)kp2[1][0];
SCM1[41].o[0][1] = (Ull)48LL;
SCM0[41].b[0][2] = (Ull)ip0[1][12];
SCM1[41].b[0][2] = (Ull)ip1[1][12];
SCM0[42].b[0][0] = (Ull)kp1[1][0];
SCM0[42].o[0][0] = (Ull)52LL;
SCM1[42].b[0][0] = (Ull)kp0[1][0];
SCM1[42].o[0][0] = (Ull)52LL;
SCM0[42].b[0][1] = (Ull)kp3[1][0];
SCM0[42].o[0][1] = (Ull)52LL;
SCM1[42].b[0][1] = (Ull)kp2[1][0];
SCM1[42].o[0][1] = (Ull)52LL;
SCM0[42].b[0][2] = (Ull)ip0[1][13];
SCM1[42].b[0][2] = (Ull)ip1[1][13];
SCM0[43].b[0][0] = (Ull)kp1[1][0];
SCM0[43].o[0][0] = (Ull)56LL;
SCM1[43].b[0][0] = (Ull)kp0[1][0];
SCM1[43].o[0][0] = (Ull)56LL;
SCM0[43].b[0][1] = (Ull)kp3[1][0];
SCM0[43].o[0][1] = (Ull)56LL;
SCM1[43].b[0][1] = (Ull)kp2[1][0];
SCM1[43].o[0][1] = (Ull)56LL;
SCM0[43].b[0][2] = (Ull)ip0[1][14];
SCM1[43].b[0][2] = (Ull)ip1[1][14];
SCM0[44].b[0][0] = (Ull)kp1[1][0];
SCM0[44].o[0][0] = (Ull)60LL;
SCM1[44].b[0][0] = (Ull)kp0[1][0];
SCM1[44].o[0][0] = (Ull)60LL;
SCM0[44].b[0][1] = (Ull)kp3[1][0];
SCM0[44].o[0][1] = (Ull)60LL;
SCM1[44].b[0][1] = (Ull)kp2[1][0];
SCM1[44].o[0][1] = (Ull)60LL;
SCM0[44].b[0][2] = (Ull)ip0[1][15];
SCM1[44].b[0][2] = (Ull)ip1[1][15];
SCM0[45].b[0][0] = (Ull)kp1[1][0];
SCM0[45].o[0][0] = (Ull)64LL;
SCM1[45].b[0][0] = (Ull)kp0[1][0];
SCM1[45].o[0][0] = (Ull)64LL;
SCM0[45].b[0][1] = (Ull)kp3[1][0];
SCM0[45].o[0][1] = (Ull)64LL;
SCM1[45].b[0][1] = (Ull)kp2[1][0];
SCM1[45].o[0][1] = (Ull)64LL;
SCM0[45].b[0][2] = (Ull)ip0[1][16];
SCM1[45].b[0][2] = (Ull)ip1[1][16];
SCM0[46].b[0][0] = (Ull)kp1[1][0];
SCM0[46].o[0][0] = (Ull)68LL;
SCM1[46].b[0][0] = (Ull)kp0[1][0];
SCM1[46].o[0][0] = (Ull)68LL;
SCM0[46].b[0][1] = (Ull)kp3[1][0];
SCM0[46].o[0][1] = (Ull)68LL;
SCM1[46].b[0][1] = (Ull)kp2[1][0];
SCM1[46].o[0][1] = (Ull)68LL;
SCM0[46].b[0][2] = (Ull)ip0[1][17];
SCM1[46].b[0][2] = (Ull)ip1[1][17];
SCM0[47].b[0][0] = (Ull)kp1[1][0];
SCM0[47].o[0][0] = (Ull)72LL;
SCM1[47].b[0][0] = (Ull)kp0[1][0];
SCM1[47].o[0][0] = (Ull)72LL;
SCM0[47].b[0][1] = (Ull)kp3[1][0];
SCM0[47].o[0][1] = (Ull)72LL;
SCM1[47].b[0][1] = (Ull)kp2[1][0];
SCM1[47].o[0][1] = (Ull)72LL;
SCM0[47].b[0][2] = (Ull)ip0[1][18];
SCM1[47].b[0][2] = (Ull)ip1[1][18];
SCM0[48].b[0][0] = (Ull)kp1[1][0];
SCM0[48].o[0][0] = (Ull)76LL;
SCM1[48].b[0][0] = (Ull)kp0[1][0];
SCM1[48].o[0][0] = (Ull)76LL;
SCM0[48].b[0][1] = (Ull)kp3[1][0];
SCM0[48].o[0][1] = (Ull)76LL;
SCM1[48].b[0][1] = (Ull)kp2[1][0];
SCM1[48].o[0][1] = (Ull)76LL;
SCM0[48].b[0][2] = (Ull)ip0[1][19];
SCM1[48].b[0][2] = (Ull)ip1[1][19];
SCM0[49].b[0][0] = (Ull)kp1[1][0];
SCM0[49].o[0][0] = (Ull)80LL;
SCM1[49].b[0][0] = (Ull)kp0[1][0];
SCM1[49].o[0][0] = (Ull)80LL;
SCM0[49].b[0][1] = (Ull)kp3[1][0];
SCM0[49].o[0][1] = (Ull)80LL;
SCM1[49].b[0][1] = (Ull)kp2[1][0];
SCM1[49].o[0][1] = (Ull)80LL;
SCM0[49].b[0][2] = (Ull)ip0[1][20];
SCM1[49].b[0][2] = (Ull)ip1[1][20];
SCM0[50].b[0][0] = (Ull)kp1[1][0];
SCM0[50].o[0][0] = (Ull)84LL;
SCM1[50].b[0][0] = (Ull)kp0[1][0];
SCM1[50].o[0][0] = (Ull)84LL;
SCM0[50].b[0][1] = (Ull)kp3[1][0];
SCM0[50].o[0][1] = (Ull)84LL;
SCM1[50].b[0][1] = (Ull)kp2[1][0];
SCM1[50].o[0][1] = (Ull)84LL;
SCM0[50].b[0][2] = (Ull)ip0[1][21];
SCM1[50].b[0][2] = (Ull)ip1[1][21];
SCM0[51].b[0][0] = (Ull)kp1[1][0];
SCM0[51].o[0][0] = (Ull)88LL;
SCM1[51].b[0][0] = (Ull)kp0[1][0];
SCM1[51].o[0][0] = (Ull)88LL;
SCM0[51].b[0][1] = (Ull)kp3[1][0];
SCM0[51].o[0][1] = (Ull)88LL;
SCM1[51].b[0][1] = (Ull)kp2[1][0];
SCM1[51].o[0][1] = (Ull)88LL;
SCM0[51].b[0][2] = (Ull)ip0[1][22];
SCM1[51].b[0][2] = (Ull)ip1[1][22];
SCM0[52].b[0][0] = (Ull)kp1[1][0];
SCM0[52].o[0][0] = (Ull)92LL;
SCM1[52].b[0][0] = (Ull)kp0[1][0];
SCM1[52].o[0][0] = (Ull)92LL;
SCM0[52].b[0][1] = (Ull)kp3[1][0];
SCM0[52].o[0][1] = (Ull)92LL;
SCM1[52].b[0][1] = (Ull)kp2[1][0];
SCM1[52].o[0][1] = (Ull)92LL;
SCM0[52].b[0][2] = (Ull)ip0[1][23];
SCM1[52].b[0][2] = (Ull)ip1[1][23];
SCM0[53].b[0][0] = (Ull)kp1[1][0];
SCM0[53].o[0][0] = (Ull)96LL;
SCM1[53].b[0][0] = (Ull)kp0[1][0];
SCM1[53].o[0][0] = (Ull)96LL;
SCM0[53].b[0][1] = (Ull)kp3[1][0];
SCM0[53].o[0][1] = (Ull)96LL;
SCM1[53].b[0][1] = (Ull)kp2[1][0];
SCM1[53].o[0][1] = (Ull)96LL;
SCM0[53].b[0][2] = (Ull)ip0[1][24];
SCM1[53].b[0][2] = (Ull)ip1[1][24];
SCM0[54].b[0][0] = (Ull)kp1[1][0];
SCM0[54].o[0][0] = (Ull)100LL;
SCM1[54].b[0][0] = (Ull)kp0[1][0];
SCM1[54].o[0][0] = (Ull)100LL;
SCM0[54].b[0][1] = (Ull)kp3[1][0];
SCM0[54].o[0][1] = (Ull)100LL;
SCM1[54].b[0][1] = (Ull)kp2[1][0];
SCM1[54].o[0][1] = (Ull)100LL;
SCM0[54].b[0][2] = (Ull)ip0[1][25];
SCM1[54].b[0][2] = (Ull)ip1[1][25];
SCM0[55].b[0][0] = (Ull)kp1[1][0];
SCM0[55].o[0][0] = (Ull)104LL;
SCM1[55].b[0][0] = (Ull)kp0[1][0];
SCM1[55].o[0][0] = (Ull)104LL;
SCM0[55].b[0][1] = (Ull)kp3[1][0];
SCM0[55].o[0][1] = (Ull)104LL;
SCM1[55].b[0][1] = (Ull)kp2[1][0];
SCM1[55].o[0][1] = (Ull)104LL;
SCM0[55].b[0][2] = (Ull)ip0[1][26];
SCM1[55].b[0][2] = (Ull)ip1[1][26];
SCM0[57].o[0][0] = (Ull)op0[0];
SCM1[57].b[0][0] = (Ull)op0[0];
SCM0[57].o[0][1] = (Ull)op1[0];
SCM1[57].b[0][1] = (Ull)op1[0];
SCM0[57].o[0][2] = (Ull)op2[0];
SCM1[57].b[0][2] = (Ull)op2[0];
SCM0[57].o[0][3] = (Ull)op3[0];
SCM1[57].b[0][3] = (Ull)op3[0];
sc_param[0].LOOP0=LOOP0; sc_param[0].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[0], 0, emax7sc_pth_cnn_00, &sc_param[0]);
sc_param[1].LOOP0=LOOP0; sc_param[1].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[1], 0, emax7sc_pth_cnn_01, &sc_param[1]);
sc_param[2].LOOP0=LOOP0; sc_param[2].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[2], 0, emax7sc_pth_cnn_02, &sc_param[2]);
sc_param[3].LOOP0=LOOP0; sc_param[3].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[3], 0, emax7sc_pth_cnn_03, &sc_param[3]);
sc_param[4].LOOP0=LOOP0; sc_param[4].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[4], 0, emax7sc_pth_cnn_04, &sc_param[4]);
sc_param[5].LOOP0=LOOP0; sc_param[5].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[5], 0, emax7sc_pth_cnn_05, &sc_param[5]);
sc_param[6].LOOP0=LOOP0; sc_param[6].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[6], 0, emax7sc_pth_cnn_06, &sc_param[6]);
sc_param[7].LOOP0=LOOP0; sc_param[7].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[7], 0, emax7sc_pth_cnn_07, &sc_param[7]);
sc_param[8].LOOP0=LOOP0; sc_param[8].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[8], 0, emax7sc_pth_cnn_08, &sc_param[8]);
sc_param[9].LOOP0=LOOP0; sc_param[9].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[9], 0, emax7sc_pth_cnn_09, &sc_param[9]);
sc_param[10].LOOP0=LOOP0; sc_param[10].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[10], 0, emax7sc_pth_cnn_10, &sc_param[10]);
sc_param[11].LOOP0=LOOP0; sc_param[11].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[11], 0, emax7sc_pth_cnn_11, &sc_param[11]);
sc_param[12].LOOP0=LOOP0; sc_param[12].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[12], 0, emax7sc_pth_cnn_12, &sc_param[12]);
sc_param[13].LOOP0=LOOP0; sc_param[13].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[13], 0, emax7sc_pth_cnn_13, &sc_param[13]);
sc_param[14].LOOP0=LOOP0; sc_param[14].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[14], 0, emax7sc_pth_cnn_14, &sc_param[14]);
sc_param[15].LOOP0=LOOP0; sc_param[15].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[15], 0, emax7sc_pth_cnn_15, &sc_param[15]);
sc_param[16].LOOP0=LOOP0; sc_param[16].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[16], 0, emax7sc_pth_cnn_16, &sc_param[16]);
sc_param[17].LOOP0=LOOP0; sc_param[17].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[17], 0, emax7sc_pth_cnn_17, &sc_param[17]);
sc_param[18].LOOP0=LOOP0; sc_param[18].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[18], 0, emax7sc_pth_cnn_18, &sc_param[18]);
sc_param[19].LOOP0=LOOP0; sc_param[19].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[19], 0, emax7sc_pth_cnn_19, &sc_param[19]);
sc_param[20].LOOP0=LOOP0; sc_param[20].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[20], 0, emax7sc_pth_cnn_20, &sc_param[20]);
sc_param[21].LOOP0=LOOP0; sc_param[21].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[21], 0, emax7sc_pth_cnn_21, &sc_param[21]);
sc_param[22].LOOP0=LOOP0; sc_param[22].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[22], 0, emax7sc_pth_cnn_22, &sc_param[22]);
sc_param[23].LOOP0=LOOP0; sc_param[23].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[23], 0, emax7sc_pth_cnn_23, &sc_param[23]);
sc_param[24].LOOP0=LOOP0; sc_param[24].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[24], 0, emax7sc_pth_cnn_24, &sc_param[24]);
sc_param[25].LOOP0=LOOP0; sc_param[25].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[25], 0, emax7sc_pth_cnn_25, &sc_param[25]);
sc_param[26].LOOP0=LOOP0; sc_param[26].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[26], 0, emax7sc_pth_cnn_26, &sc_param[26]);
sc_param[27].LOOP0=LOOP0; sc_param[27].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[27], 0, emax7sc_pth_cnn_27, &sc_param[27]);
sc_param[28].LOOP0=LOOP0; sc_param[28].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[28], 0, emax7sc_pth_cnn_28, &sc_param[28]);
sc_param[29].LOOP0=LOOP0; sc_param[29].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[29], 0, emax7sc_pth_cnn_29, &sc_param[29]);
sc_param[30].LOOP0=LOOP0; sc_param[30].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[30], 0, emax7sc_pth_cnn_30, &sc_param[30]);
sc_param[31].LOOP0=LOOP0; sc_param[31].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[31], 0, emax7sc_pth_cnn_31, &sc_param[31]);
sc_param[32].LOOP0=LOOP0; sc_param[32].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[32], 0, emax7sc_pth_cnn_32, &sc_param[32]);
sc_param[33].LOOP0=LOOP0; sc_param[33].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[33], 0, emax7sc_pth_cnn_33, &sc_param[33]);
sc_param[34].LOOP0=LOOP0; sc_param[34].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[34], 0, emax7sc_pth_cnn_34, &sc_param[34]);
sc_param[35].LOOP0=LOOP0; sc_param[35].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[35], 0, emax7sc_pth_cnn_35, &sc_param[35]);
sc_param[36].LOOP0=LOOP0; sc_param[36].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[36], 0, emax7sc_pth_cnn_36, &sc_param[36]);
sc_param[37].LOOP0=LOOP0; sc_param[37].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[37], 0, emax7sc_pth_cnn_37, &sc_param[37]);
sc_param[38].LOOP0=LOOP0; sc_param[38].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[38], 0, emax7sc_pth_cnn_38, &sc_param[38]);
sc_param[39].LOOP0=LOOP0; sc_param[39].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[39], 0, emax7sc_pth_cnn_39, &sc_param[39]);
sc_param[40].LOOP0=LOOP0; sc_param[40].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[40], 0, emax7sc_pth_cnn_40, &sc_param[40]);
sc_param[41].LOOP0=LOOP0; sc_param[41].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[41], 0, emax7sc_pth_cnn_41, &sc_param[41]);
sc_param[42].LOOP0=LOOP0; sc_param[42].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[42], 0, emax7sc_pth_cnn_42, &sc_param[42]);
sc_param[43].LOOP0=LOOP0; sc_param[43].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[43], 0, emax7sc_pth_cnn_43, &sc_param[43]);
sc_param[44].LOOP0=LOOP0; sc_param[44].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[44], 0, emax7sc_pth_cnn_44, &sc_param[44]);
sc_param[45].LOOP0=LOOP0; sc_param[45].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[45], 0, emax7sc_pth_cnn_45, &sc_param[45]);
sc_param[46].LOOP0=LOOP0; sc_param[46].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[46], 0, emax7sc_pth_cnn_46, &sc_param[46]);
sc_param[47].LOOP0=LOOP0; sc_param[47].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[47], 0, emax7sc_pth_cnn_47, &sc_param[47]);
sc_param[48].LOOP0=LOOP0; sc_param[48].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[48], 0, emax7sc_pth_cnn_48, &sc_param[48]);
sc_param[49].LOOP0=LOOP0; sc_param[49].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[49], 0, emax7sc_pth_cnn_49, &sc_param[49]);
sc_param[50].LOOP0=LOOP0; sc_param[50].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[50], 0, emax7sc_pth_cnn_50, &sc_param[50]);
sc_param[51].LOOP0=LOOP0; sc_param[51].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[51], 0, emax7sc_pth_cnn_51, &sc_param[51]);
sc_param[52].LOOP0=LOOP0; sc_param[52].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[52], 0, emax7sc_pth_cnn_52, &sc_param[52]);
sc_param[53].LOOP0=LOOP0; sc_param[53].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[53], 0, emax7sc_pth_cnn_53, &sc_param[53]);
sc_param[54].LOOP0=LOOP0; sc_param[54].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[54], 0, emax7sc_pth_cnn_54, &sc_param[54]);
sc_param[55].LOOP0=LOOP0; sc_param[55].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[55], 0, emax7sc_pth_cnn_55, &sc_param[55]);
sc_param[56].LOOP0=LOOP0; sc_param[56].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[56], 0, emax7sc_pth_cnn_56, &sc_param[56]);
sc_param[57].LOOP0=LOOP0; sc_param[57].LOOP1=LOOP1; pthread_create((pthread_t*)&sc_pth[57], 0, emax7sc_pth_cnn_57, &sc_param[57]);
pthread_join(*(pthread_t*)&sc_pth[0], 0);
pthread_join(*(pthread_t*)&sc_pth[1], 0);
pthread_join(*(pthread_t*)&sc_pth[2], 0);
pthread_join(*(pthread_t*)&sc_pth[3], 0);
pthread_join(*(pthread_t*)&sc_pth[4], 0);
pthread_join(*(pthread_t*)&sc_pth[5], 0);
pthread_join(*(pthread_t*)&sc_pth[6], 0);
pthread_join(*(pthread_t*)&sc_pth[7], 0);
pthread_join(*(pthread_t*)&sc_pth[8], 0);
pthread_join(*(pthread_t*)&sc_pth[9], 0);
pthread_join(*(pthread_t*)&sc_pth[10], 0);
pthread_join(*(pthread_t*)&sc_pth[11], 0);
pthread_join(*(pthread_t*)&sc_pth[12], 0);
pthread_join(*(pthread_t*)&sc_pth[13], 0);
pthread_join(*(pthread_t*)&sc_pth[14], 0);
pthread_join(*(pthread_t*)&sc_pth[15], 0);
pthread_join(*(pthread_t*)&sc_pth[16], 0);
pthread_join(*(pthread_t*)&sc_pth[17], 0);
pthread_join(*(pthread_t*)&sc_pth[18], 0);
pthread_join(*(pthread_t*)&sc_pth[19], 0);
pthread_join(*(pthread_t*)&sc_pth[20], 0);
pthread_join(*(pthread_t*)&sc_pth[21], 0);
pthread_join(*(pthread_t*)&sc_pth[22], 0);
pthread_join(*(pthread_t*)&sc_pth[23], 0);
pthread_join(*(pthread_t*)&sc_pth[24], 0);
pthread_join(*(pthread_t*)&sc_pth[25], 0);
pthread_join(*(pthread_t*)&sc_pth[26], 0);
pthread_join(*(pthread_t*)&sc_pth[27], 0);
pthread_join(*(pthread_t*)&sc_pth[28], 0);
pthread_join(*(pthread_t*)&sc_pth[29], 0);
pthread_join(*(pthread_t*)&sc_pth[30], 0);
pthread_join(*(pthread_t*)&sc_pth[31], 0);
pthread_join(*(pthread_t*)&sc_pth[32], 0);
pthread_join(*(pthread_t*)&sc_pth[33], 0);
pthread_join(*(pthread_t*)&sc_pth[34], 0);
pthread_join(*(pthread_t*)&sc_pth[35], 0);
pthread_join(*(pthread_t*)&sc_pth[36], 0);
pthread_join(*(pthread_t*)&sc_pth[37], 0);
pthread_join(*(pthread_t*)&sc_pth[38], 0);
pthread_join(*(pthread_t*)&sc_pth[39], 0);
pthread_join(*(pthread_t*)&sc_pth[40], 0);
pthread_join(*(pthread_t*)&sc_pth[41], 0);
pthread_join(*(pthread_t*)&sc_pth[42], 0);
pthread_join(*(pthread_t*)&sc_pth[43], 0);
pthread_join(*(pthread_t*)&sc_pth[44], 0);
pthread_join(*(pthread_t*)&sc_pth[45], 0);
pthread_join(*(pthread_t*)&sc_pth[46], 0);
pthread_join(*(pthread_t*)&sc_pth[47], 0);
pthread_join(*(pthread_t*)&sc_pth[48], 0);
pthread_join(*(pthread_t*)&sc_pth[49], 0);
pthread_join(*(pthread_t*)&sc_pth[50], 0);
pthread_join(*(pthread_t*)&sc_pth[51], 0);
pthread_join(*(pthread_t*)&sc_pth[52], 0);
pthread_join(*(pthread_t*)&sc_pth[53], 0);
pthread_join(*(pthread_t*)&sc_pth[54], 0);
pthread_join(*(pthread_t*)&sc_pth[55], 0);
pthread_join(*(pthread_t*)&sc_pth[56], 0);
pthread_join(*(pthread_t*)&sc_pth[57], 0);
/* EMAXSC end */
#endif
#ifndef EMAXSC
	emax7[LANE].lmmio = emax7[LANE].lmmic;
	emax7[LANE].lmmic = 1-emax7[LANE].lmmic;
	emax7[LANE].mapdist = 0;
	*(Uint*)&emax7[LANE].lmmi[0][10][2][emax7[LANE].lmmic] = 0x0ec5e001|(0<<2);
	emax7[LANE].lmmi[0][10][2][emax7[LANE].lmmic].ofs = 0;
	emax7[LANE].lmmi[0][10][2][emax7[LANE].lmmic].top = it[0][0];
	*(Uint*)&emax7[LANE].lmmi[0][19][2][emax7[LANE].lmmic] = 0x0ec5e001|(0<<2);
	emax7[LANE].lmmi[0][19][2][emax7[LANE].lmmic].ofs = 0;
	emax7[LANE].lmmi[0][19][2][emax7[LANE].lmmic].top = it[1][0];
	*(Uint*)&emax7[LANE].lmmi[0][28][2][emax7[LANE].lmmic] = 0x0ec5e001|(0<<2);
	emax7[LANE].lmmi[0][28][2][emax7[LANE].lmmic].ofs = 0;
	emax7[LANE].lmmi[0][28][2][emax7[LANE].lmmic].top = it[2][0];
	*(Uint*)&emax7[LANE].lmmi[0][37][2][emax7[LANE].lmmic] = 0x0ec5e001|(0<<2);
	emax7[LANE].lmmi[0][37][2][emax7[LANE].lmmic].ofs = 0;
	emax7[LANE].lmmi[0][37][2][emax7[LANE].lmmic].top = it[0][1];
	*(Uint*)&emax7[LANE].lmmi[0][46][2][emax7[LANE].lmmic] = 0x0ec5e001|(0<<2);
	emax7[LANE].lmmi[0][46][2][emax7[LANE].lmmic].ofs = 0;
	emax7[LANE].lmmi[0][46][2][emax7[LANE].lmmic].top = it[1][1];
	*(Uint*)&emax7[LANE].lmmi[0][55][0][emax7[LANE].lmmic] = 0x00d7e021|(0<<2);
	emax7[LANE].lmmi[0][55][0][emax7[LANE].lmmic].ofs = 0;
	emax7[LANE].lmmi[0][55][0][emax7[LANE].lmmic].top = ker;
	*(Uint*)&emax7[LANE].lmmi[0][55][2][emax7[LANE].lmmic] = 0x0ec5e001|(0<<2);
	emax7[LANE].lmmi[0][55][2][emax7[LANE].lmmic].ofs = 0;
	emax7[LANE].lmmi[0][55][2][emax7[LANE].lmmic].top = it[2][1];
	*(Uint*)&emax7[LANE].lmmi[0][57][0][emax7[LANE].lmmic] = 0x0e88f003|(1<<2);
	emax7[LANE].lmmi[0][57][0][emax7[LANE].lmmic].ofs = 0;
	emax7[LANE].lmmi[0][57][0][emax7[LANE].lmmic].top = ot0[0];
	*(Uint*)&emax7[LANE].lmmi[0][57][1][emax7[LANE].lmmic] = 0x0e88f003|(1<<2);
	emax7[LANE].lmmi[0][57][1][emax7[LANE].lmmic].ofs = 0;
	emax7[LANE].lmmi[0][57][1][emax7[LANE].lmmic].top = ot1[0];
	*(Uint*)&emax7[LANE].lmmi[0][57][2][emax7[LANE].lmmic] = 0x0e88f003|(1<<2);
	emax7[LANE].lmmi[0][57][2][emax7[LANE].lmmic].ofs = 0;
	emax7[LANE].lmmi[0][57][2][emax7[LANE].lmmic].top = ot2[0];
	*(Uint*)&emax7[LANE].lmmi[0][57][3][emax7[LANE].lmmic] = 0x0e88f003|(1<<2);
	emax7[LANE].lmmi[0][57][3][emax7[LANE].lmmic].ofs = 0;
	emax7[LANE].lmmi[0][57][3][emax7[LANE].lmmic].top = ot3[0];
	emax7[LANE].lmmi_bitmap[0] = 0x0280000000000000LL;
	emax7[LANE].lmmi_bitmap[1] = 0x0200000000000000LL;
	emax7[LANE].lmmi_bitmap[2] = 0x0280402010080400LL;
	emax7[LANE].lmmi_bitmap[3] = 0x0200000000000000LL;
	emax7_pre_with_drain_cache();
	get_nanosec(LANE, NANOS_ARM);
	if (emax7[LANE].last_conf == emax7_conf_cnn) {
	  emax7[LANE].status = STATUS_DRAIN;
	  emax7_check_lmmi_and_dma(LANE, 0, 1, 0, 0, 57, 0);/*drain*/
	  emax7_check_lmmi_and_dma(LANE, 0, 1, 0, 0, 57, 1);/*drain*/
	  emax7_check_lmmi_and_dma(LANE, 0, 1, 0, 0, 57, 2);/*drain*/
	  emax7_check_lmmi_and_dma(LANE, 0, 1, 0, 0, 57, 3);/*drain*/
	}
	get_nanosec(LANE, NANOS_DRAIN);
	if (emax7[LANE].last_conf != emax7_conf_cnn) {
	  Dll *dst, *src;
	  int i,j,hard_stat,hard_depth;
	  emax7[LANE].status = STATUS_CONF;
	  hard_stat  = ((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].stat>>8 & 0xffffff0f;
	  hard_depth = (hard_stat==3)?64:(hard_stat==2)?32:(hard_stat==1)?16:8;
	  if (hard_depth != 64) {
	    printf("EMAX_DEPTH mismatch in emax7_conf_cnn. hard_depth=%d code_depth=64\n", hard_depth);
	    exit(1);
	  }
	  emax7[LANE].last_conf = emax7_conf_cnn;
	  emax7[LANE].lastdist = 0;
	  dst = (Dll*)(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].conf);
	  src = (Dll*)emax7_conf_cnn;
	  for (i=0; i<(sizeof(struct conf)*64*4)/sizeof(Dll); i++)
	    *dst++ = *src++;
	  for (i=0; i<64; i++) {
	    for (j=0; j<4; j++)
	      emax7[LANE].lmmi[0][i][j][emax7[LANE].lmmio].v = 0;
	  }
	  while (((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].stat & 0xffff00f0); //LMRING_BUSY 
	}
	get_nanosec(LANE, NANOS_CONF);
	//pthread_mutex_lock(&axi_dma_mutex);
	emax7[LANE].status = STATUS_REGV;
	{ union { Dll dll; Ull br[2];} br128[2];
	br128[0/2].br[0%2] = LOOP1;
	br128[1/2].br[1%2] = -1LL;
	br128[2/2].br[2%2] = LOOP0;
	br128[3/2].br[3%2] = cofs;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].breg[63][0].br[0]) = br128[0].dll;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].breg[63][0].br[2]) = br128[1].dll;
	br128[0/2].br[0%2] = 8;
	br128[1/2].br[1%2] = rofs;
	br128[2/2].br[2%2] = (269)*(4);
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].breg[63][1].br[0]) = br128[0].dll;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].breg[63][1].br[2]) = br128[1].dll;
	}
	{ union { Dll dll; struct {Uint ea0b; Uint ea0o; Uint ea1b; Uint ea1o;} ea4;} ea128;
	ea128.ea4.ea0b = (Ull)kp1[0][0];
	ea128.ea4.ea0o = (Ull)0LL;
	ea128.ea4.ea1b = (Ull)kp0[0][0];
	ea128.ea4.ea1o = (Ull)0LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[2][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[0][0];
	ea128.ea4.ea0o = (Ull)0LL;
	ea128.ea4.ea1b = (Ull)kp2[0][0];
	ea128.ea4.ea1o = (Ull)0LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[2][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[0][0];
	ea128.ea4.ea1b = (Ull)ip1[0][0];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[2][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[0][0];
	ea128.ea4.ea0o = (Ull)4LL;
	ea128.ea4.ea1b = (Ull)kp0[0][0];
	ea128.ea4.ea1o = (Ull)4LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[3][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[0][0];
	ea128.ea4.ea0o = (Ull)4LL;
	ea128.ea4.ea1b = (Ull)kp2[0][0];
	ea128.ea4.ea1o = (Ull)4LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[3][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[0][1];
	ea128.ea4.ea1b = (Ull)ip1[0][1];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[3][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[0][0];
	ea128.ea4.ea0o = (Ull)8LL;
	ea128.ea4.ea1b = (Ull)kp0[0][0];
	ea128.ea4.ea1o = (Ull)8LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[4][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[0][0];
	ea128.ea4.ea0o = (Ull)8LL;
	ea128.ea4.ea1b = (Ull)kp2[0][0];
	ea128.ea4.ea1o = (Ull)8LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[4][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[0][2];
	ea128.ea4.ea1b = (Ull)ip1[0][2];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[4][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[0][0];
	ea128.ea4.ea0o = (Ull)12LL;
	ea128.ea4.ea1b = (Ull)kp0[0][0];
	ea128.ea4.ea1o = (Ull)12LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[5][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[0][0];
	ea128.ea4.ea0o = (Ull)12LL;
	ea128.ea4.ea1b = (Ull)kp2[0][0];
	ea128.ea4.ea1o = (Ull)12LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[5][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[0][3];
	ea128.ea4.ea1b = (Ull)ip1[0][3];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[5][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[0][0];
	ea128.ea4.ea0o = (Ull)16LL;
	ea128.ea4.ea1b = (Ull)kp0[0][0];
	ea128.ea4.ea1o = (Ull)16LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[6][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[0][0];
	ea128.ea4.ea0o = (Ull)16LL;
	ea128.ea4.ea1b = (Ull)kp2[0][0];
	ea128.ea4.ea1o = (Ull)16LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[6][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[0][4];
	ea128.ea4.ea1b = (Ull)ip1[0][4];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[6][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[0][0];
	ea128.ea4.ea0o = (Ull)20LL;
	ea128.ea4.ea1b = (Ull)kp0[0][0];
	ea128.ea4.ea1o = (Ull)20LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[7][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[0][0];
	ea128.ea4.ea0o = (Ull)20LL;
	ea128.ea4.ea1b = (Ull)kp2[0][0];
	ea128.ea4.ea1o = (Ull)20LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[7][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[0][5];
	ea128.ea4.ea1b = (Ull)ip1[0][5];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[7][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[0][0];
	ea128.ea4.ea0o = (Ull)24LL;
	ea128.ea4.ea1b = (Ull)kp0[0][0];
	ea128.ea4.ea1o = (Ull)24LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[8][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[0][0];
	ea128.ea4.ea0o = (Ull)24LL;
	ea128.ea4.ea1b = (Ull)kp2[0][0];
	ea128.ea4.ea1o = (Ull)24LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[8][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[0][6];
	ea128.ea4.ea1b = (Ull)ip1[0][6];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[8][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[0][0];
	ea128.ea4.ea0o = (Ull)28LL;
	ea128.ea4.ea1b = (Ull)kp0[0][0];
	ea128.ea4.ea1o = (Ull)28LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[9][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[0][0];
	ea128.ea4.ea0o = (Ull)28LL;
	ea128.ea4.ea1b = (Ull)kp2[0][0];
	ea128.ea4.ea1o = (Ull)28LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[9][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[0][7];
	ea128.ea4.ea1b = (Ull)ip1[0][7];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[9][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[0][0];
	ea128.ea4.ea0o = (Ull)32LL;
	ea128.ea4.ea1b = (Ull)kp0[0][0];
	ea128.ea4.ea1o = (Ull)32LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[10][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[0][0];
	ea128.ea4.ea0o = (Ull)32LL;
	ea128.ea4.ea1b = (Ull)kp2[0][0];
	ea128.ea4.ea1o = (Ull)32LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[10][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[0][8];
	ea128.ea4.ea1b = (Ull)ip1[0][8];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[10][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[0][0];
	ea128.ea4.ea0o = (Ull)36LL;
	ea128.ea4.ea1b = (Ull)kp0[0][0];
	ea128.ea4.ea1o = (Ull)36LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[11][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[0][0];
	ea128.ea4.ea0o = (Ull)36LL;
	ea128.ea4.ea1b = (Ull)kp2[0][0];
	ea128.ea4.ea1o = (Ull)36LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[11][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[0][9];
	ea128.ea4.ea1b = (Ull)ip1[0][9];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[11][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[0][0];
	ea128.ea4.ea0o = (Ull)40LL;
	ea128.ea4.ea1b = (Ull)kp0[0][0];
	ea128.ea4.ea1o = (Ull)40LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[12][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[0][0];
	ea128.ea4.ea0o = (Ull)40LL;
	ea128.ea4.ea1b = (Ull)kp2[0][0];
	ea128.ea4.ea1o = (Ull)40LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[12][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[0][10];
	ea128.ea4.ea1b = (Ull)ip1[0][10];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[12][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[0][0];
	ea128.ea4.ea0o = (Ull)44LL;
	ea128.ea4.ea1b = (Ull)kp0[0][0];
	ea128.ea4.ea1o = (Ull)44LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[13][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[0][0];
	ea128.ea4.ea0o = (Ull)44LL;
	ea128.ea4.ea1b = (Ull)kp2[0][0];
	ea128.ea4.ea1o = (Ull)44LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[13][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[0][11];
	ea128.ea4.ea1b = (Ull)ip1[0][11];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[13][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[0][0];
	ea128.ea4.ea0o = (Ull)48LL;
	ea128.ea4.ea1b = (Ull)kp0[0][0];
	ea128.ea4.ea1o = (Ull)48LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[14][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[0][0];
	ea128.ea4.ea0o = (Ull)48LL;
	ea128.ea4.ea1b = (Ull)kp2[0][0];
	ea128.ea4.ea1o = (Ull)48LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[14][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[0][12];
	ea128.ea4.ea1b = (Ull)ip1[0][12];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[14][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[0][0];
	ea128.ea4.ea0o = (Ull)52LL;
	ea128.ea4.ea1b = (Ull)kp0[0][0];
	ea128.ea4.ea1o = (Ull)52LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[15][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[0][0];
	ea128.ea4.ea0o = (Ull)52LL;
	ea128.ea4.ea1b = (Ull)kp2[0][0];
	ea128.ea4.ea1o = (Ull)52LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[15][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[0][13];
	ea128.ea4.ea1b = (Ull)ip1[0][13];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[15][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[0][0];
	ea128.ea4.ea0o = (Ull)56LL;
	ea128.ea4.ea1b = (Ull)kp0[0][0];
	ea128.ea4.ea1o = (Ull)56LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[16][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[0][0];
	ea128.ea4.ea0o = (Ull)56LL;
	ea128.ea4.ea1b = (Ull)kp2[0][0];
	ea128.ea4.ea1o = (Ull)56LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[16][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[0][14];
	ea128.ea4.ea1b = (Ull)ip1[0][14];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[16][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[0][0];
	ea128.ea4.ea0o = (Ull)60LL;
	ea128.ea4.ea1b = (Ull)kp0[0][0];
	ea128.ea4.ea1o = (Ull)60LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[17][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[0][0];
	ea128.ea4.ea0o = (Ull)60LL;
	ea128.ea4.ea1b = (Ull)kp2[0][0];
	ea128.ea4.ea1o = (Ull)60LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[17][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[0][15];
	ea128.ea4.ea1b = (Ull)ip1[0][15];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[17][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[0][0];
	ea128.ea4.ea0o = (Ull)64LL;
	ea128.ea4.ea1b = (Ull)kp0[0][0];
	ea128.ea4.ea1o = (Ull)64LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[18][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[0][0];
	ea128.ea4.ea0o = (Ull)64LL;
	ea128.ea4.ea1b = (Ull)kp2[0][0];
	ea128.ea4.ea1o = (Ull)64LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[18][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[0][16];
	ea128.ea4.ea1b = (Ull)ip1[0][16];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[18][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[0][0];
	ea128.ea4.ea0o = (Ull)68LL;
	ea128.ea4.ea1b = (Ull)kp0[0][0];
	ea128.ea4.ea1o = (Ull)68LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[19][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[0][0];
	ea128.ea4.ea0o = (Ull)68LL;
	ea128.ea4.ea1b = (Ull)kp2[0][0];
	ea128.ea4.ea1o = (Ull)68LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[19][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[0][17];
	ea128.ea4.ea1b = (Ull)ip1[0][17];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[19][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[0][0];
	ea128.ea4.ea0o = (Ull)72LL;
	ea128.ea4.ea1b = (Ull)kp0[0][0];
	ea128.ea4.ea1o = (Ull)72LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[20][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[0][0];
	ea128.ea4.ea0o = (Ull)72LL;
	ea128.ea4.ea1b = (Ull)kp2[0][0];
	ea128.ea4.ea1o = (Ull)72LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[20][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[0][18];
	ea128.ea4.ea1b = (Ull)ip1[0][18];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[20][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[0][0];
	ea128.ea4.ea0o = (Ull)76LL;
	ea128.ea4.ea1b = (Ull)kp0[0][0];
	ea128.ea4.ea1o = (Ull)76LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[21][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[0][0];
	ea128.ea4.ea0o = (Ull)76LL;
	ea128.ea4.ea1b = (Ull)kp2[0][0];
	ea128.ea4.ea1o = (Ull)76LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[21][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[0][19];
	ea128.ea4.ea1b = (Ull)ip1[0][19];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[21][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[0][0];
	ea128.ea4.ea0o = (Ull)80LL;
	ea128.ea4.ea1b = (Ull)kp0[0][0];
	ea128.ea4.ea1o = (Ull)80LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[22][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[0][0];
	ea128.ea4.ea0o = (Ull)80LL;
	ea128.ea4.ea1b = (Ull)kp2[0][0];
	ea128.ea4.ea1o = (Ull)80LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[22][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[0][20];
	ea128.ea4.ea1b = (Ull)ip1[0][20];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[22][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[0][0];
	ea128.ea4.ea0o = (Ull)84LL;
	ea128.ea4.ea1b = (Ull)kp0[0][0];
	ea128.ea4.ea1o = (Ull)84LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[23][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[0][0];
	ea128.ea4.ea0o = (Ull)84LL;
	ea128.ea4.ea1b = (Ull)kp2[0][0];
	ea128.ea4.ea1o = (Ull)84LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[23][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[0][21];
	ea128.ea4.ea1b = (Ull)ip1[0][21];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[23][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[0][0];
	ea128.ea4.ea0o = (Ull)88LL;
	ea128.ea4.ea1b = (Ull)kp0[0][0];
	ea128.ea4.ea1o = (Ull)88LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[24][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[0][0];
	ea128.ea4.ea0o = (Ull)88LL;
	ea128.ea4.ea1b = (Ull)kp2[0][0];
	ea128.ea4.ea1o = (Ull)88LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[24][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[0][22];
	ea128.ea4.ea1b = (Ull)ip1[0][22];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[24][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[0][0];
	ea128.ea4.ea0o = (Ull)92LL;
	ea128.ea4.ea1b = (Ull)kp0[0][0];
	ea128.ea4.ea1o = (Ull)92LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[25][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[0][0];
	ea128.ea4.ea0o = (Ull)92LL;
	ea128.ea4.ea1b = (Ull)kp2[0][0];
	ea128.ea4.ea1o = (Ull)92LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[25][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[0][23];
	ea128.ea4.ea1b = (Ull)ip1[0][23];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[25][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[0][0];
	ea128.ea4.ea0o = (Ull)96LL;
	ea128.ea4.ea1b = (Ull)kp0[0][0];
	ea128.ea4.ea1o = (Ull)96LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[26][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[0][0];
	ea128.ea4.ea0o = (Ull)96LL;
	ea128.ea4.ea1b = (Ull)kp2[0][0];
	ea128.ea4.ea1o = (Ull)96LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[26][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[0][24];
	ea128.ea4.ea1b = (Ull)ip1[0][24];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[26][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[0][0];
	ea128.ea4.ea0o = (Ull)100LL;
	ea128.ea4.ea1b = (Ull)kp0[0][0];
	ea128.ea4.ea1o = (Ull)100LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[27][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[0][0];
	ea128.ea4.ea0o = (Ull)100LL;
	ea128.ea4.ea1b = (Ull)kp2[0][0];
	ea128.ea4.ea1o = (Ull)100LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[27][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[0][25];
	ea128.ea4.ea1b = (Ull)ip1[0][25];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[27][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[0][0];
	ea128.ea4.ea0o = (Ull)104LL;
	ea128.ea4.ea1b = (Ull)kp0[0][0];
	ea128.ea4.ea1o = (Ull)104LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[28][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[0][0];
	ea128.ea4.ea0o = (Ull)104LL;
	ea128.ea4.ea1b = (Ull)kp2[0][0];
	ea128.ea4.ea1o = (Ull)104LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[28][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[0][26];
	ea128.ea4.ea1b = (Ull)ip1[0][26];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[28][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[1][0];
	ea128.ea4.ea0o = (Ull)0LL;
	ea128.ea4.ea1b = (Ull)kp0[1][0];
	ea128.ea4.ea1o = (Ull)0LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[29][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[1][0];
	ea128.ea4.ea0o = (Ull)0LL;
	ea128.ea4.ea1b = (Ull)kp2[1][0];
	ea128.ea4.ea1o = (Ull)0LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[29][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[1][0];
	ea128.ea4.ea1b = (Ull)ip1[1][0];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[29][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[1][0];
	ea128.ea4.ea0o = (Ull)4LL;
	ea128.ea4.ea1b = (Ull)kp0[1][0];
	ea128.ea4.ea1o = (Ull)4LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[30][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[1][0];
	ea128.ea4.ea0o = (Ull)4LL;
	ea128.ea4.ea1b = (Ull)kp2[1][0];
	ea128.ea4.ea1o = (Ull)4LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[30][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[1][1];
	ea128.ea4.ea1b = (Ull)ip1[1][1];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[30][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[1][0];
	ea128.ea4.ea0o = (Ull)8LL;
	ea128.ea4.ea1b = (Ull)kp0[1][0];
	ea128.ea4.ea1o = (Ull)8LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[31][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[1][0];
	ea128.ea4.ea0o = (Ull)8LL;
	ea128.ea4.ea1b = (Ull)kp2[1][0];
	ea128.ea4.ea1o = (Ull)8LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[31][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[1][2];
	ea128.ea4.ea1b = (Ull)ip1[1][2];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[31][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[1][0];
	ea128.ea4.ea0o = (Ull)12LL;
	ea128.ea4.ea1b = (Ull)kp0[1][0];
	ea128.ea4.ea1o = (Ull)12LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[32][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[1][0];
	ea128.ea4.ea0o = (Ull)12LL;
	ea128.ea4.ea1b = (Ull)kp2[1][0];
	ea128.ea4.ea1o = (Ull)12LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[32][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[1][3];
	ea128.ea4.ea1b = (Ull)ip1[1][3];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[32][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[1][0];
	ea128.ea4.ea0o = (Ull)16LL;
	ea128.ea4.ea1b = (Ull)kp0[1][0];
	ea128.ea4.ea1o = (Ull)16LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[33][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[1][0];
	ea128.ea4.ea0o = (Ull)16LL;
	ea128.ea4.ea1b = (Ull)kp2[1][0];
	ea128.ea4.ea1o = (Ull)16LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[33][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[1][4];
	ea128.ea4.ea1b = (Ull)ip1[1][4];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[33][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[1][0];
	ea128.ea4.ea0o = (Ull)20LL;
	ea128.ea4.ea1b = (Ull)kp0[1][0];
	ea128.ea4.ea1o = (Ull)20LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[34][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[1][0];
	ea128.ea4.ea0o = (Ull)20LL;
	ea128.ea4.ea1b = (Ull)kp2[1][0];
	ea128.ea4.ea1o = (Ull)20LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[34][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[1][5];
	ea128.ea4.ea1b = (Ull)ip1[1][5];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[34][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[1][0];
	ea128.ea4.ea0o = (Ull)24LL;
	ea128.ea4.ea1b = (Ull)kp0[1][0];
	ea128.ea4.ea1o = (Ull)24LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[35][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[1][0];
	ea128.ea4.ea0o = (Ull)24LL;
	ea128.ea4.ea1b = (Ull)kp2[1][0];
	ea128.ea4.ea1o = (Ull)24LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[35][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[1][6];
	ea128.ea4.ea1b = (Ull)ip1[1][6];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[35][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[1][0];
	ea128.ea4.ea0o = (Ull)28LL;
	ea128.ea4.ea1b = (Ull)kp0[1][0];
	ea128.ea4.ea1o = (Ull)28LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[36][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[1][0];
	ea128.ea4.ea0o = (Ull)28LL;
	ea128.ea4.ea1b = (Ull)kp2[1][0];
	ea128.ea4.ea1o = (Ull)28LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[36][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[1][7];
	ea128.ea4.ea1b = (Ull)ip1[1][7];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[36][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[1][0];
	ea128.ea4.ea0o = (Ull)32LL;
	ea128.ea4.ea1b = (Ull)kp0[1][0];
	ea128.ea4.ea1o = (Ull)32LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[37][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[1][0];
	ea128.ea4.ea0o = (Ull)32LL;
	ea128.ea4.ea1b = (Ull)kp2[1][0];
	ea128.ea4.ea1o = (Ull)32LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[37][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[1][8];
	ea128.ea4.ea1b = (Ull)ip1[1][8];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[37][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[1][0];
	ea128.ea4.ea0o = (Ull)36LL;
	ea128.ea4.ea1b = (Ull)kp0[1][0];
	ea128.ea4.ea1o = (Ull)36LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[38][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[1][0];
	ea128.ea4.ea0o = (Ull)36LL;
	ea128.ea4.ea1b = (Ull)kp2[1][0];
	ea128.ea4.ea1o = (Ull)36LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[38][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[1][9];
	ea128.ea4.ea1b = (Ull)ip1[1][9];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[38][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[1][0];
	ea128.ea4.ea0o = (Ull)40LL;
	ea128.ea4.ea1b = (Ull)kp0[1][0];
	ea128.ea4.ea1o = (Ull)40LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[39][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[1][0];
	ea128.ea4.ea0o = (Ull)40LL;
	ea128.ea4.ea1b = (Ull)kp2[1][0];
	ea128.ea4.ea1o = (Ull)40LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[39][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[1][10];
	ea128.ea4.ea1b = (Ull)ip1[1][10];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[39][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[1][0];
	ea128.ea4.ea0o = (Ull)44LL;
	ea128.ea4.ea1b = (Ull)kp0[1][0];
	ea128.ea4.ea1o = (Ull)44LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[40][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[1][0];
	ea128.ea4.ea0o = (Ull)44LL;
	ea128.ea4.ea1b = (Ull)kp2[1][0];
	ea128.ea4.ea1o = (Ull)44LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[40][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[1][11];
	ea128.ea4.ea1b = (Ull)ip1[1][11];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[40][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[1][0];
	ea128.ea4.ea0o = (Ull)48LL;
	ea128.ea4.ea1b = (Ull)kp0[1][0];
	ea128.ea4.ea1o = (Ull)48LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[41][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[1][0];
	ea128.ea4.ea0o = (Ull)48LL;
	ea128.ea4.ea1b = (Ull)kp2[1][0];
	ea128.ea4.ea1o = (Ull)48LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[41][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[1][12];
	ea128.ea4.ea1b = (Ull)ip1[1][12];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[41][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[1][0];
	ea128.ea4.ea0o = (Ull)52LL;
	ea128.ea4.ea1b = (Ull)kp0[1][0];
	ea128.ea4.ea1o = (Ull)52LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[42][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[1][0];
	ea128.ea4.ea0o = (Ull)52LL;
	ea128.ea4.ea1b = (Ull)kp2[1][0];
	ea128.ea4.ea1o = (Ull)52LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[42][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[1][13];
	ea128.ea4.ea1b = (Ull)ip1[1][13];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[42][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[1][0];
	ea128.ea4.ea0o = (Ull)56LL;
	ea128.ea4.ea1b = (Ull)kp0[1][0];
	ea128.ea4.ea1o = (Ull)56LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[43][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[1][0];
	ea128.ea4.ea0o = (Ull)56LL;
	ea128.ea4.ea1b = (Ull)kp2[1][0];
	ea128.ea4.ea1o = (Ull)56LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[43][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[1][14];
	ea128.ea4.ea1b = (Ull)ip1[1][14];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[43][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[1][0];
	ea128.ea4.ea0o = (Ull)60LL;
	ea128.ea4.ea1b = (Ull)kp0[1][0];
	ea128.ea4.ea1o = (Ull)60LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[44][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[1][0];
	ea128.ea4.ea0o = (Ull)60LL;
	ea128.ea4.ea1b = (Ull)kp2[1][0];
	ea128.ea4.ea1o = (Ull)60LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[44][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[1][15];
	ea128.ea4.ea1b = (Ull)ip1[1][15];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[44][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[1][0];
	ea128.ea4.ea0o = (Ull)64LL;
	ea128.ea4.ea1b = (Ull)kp0[1][0];
	ea128.ea4.ea1o = (Ull)64LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[45][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[1][0];
	ea128.ea4.ea0o = (Ull)64LL;
	ea128.ea4.ea1b = (Ull)kp2[1][0];
	ea128.ea4.ea1o = (Ull)64LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[45][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[1][16];
	ea128.ea4.ea1b = (Ull)ip1[1][16];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[45][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[1][0];
	ea128.ea4.ea0o = (Ull)68LL;
	ea128.ea4.ea1b = (Ull)kp0[1][0];
	ea128.ea4.ea1o = (Ull)68LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[46][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[1][0];
	ea128.ea4.ea0o = (Ull)68LL;
	ea128.ea4.ea1b = (Ull)kp2[1][0];
	ea128.ea4.ea1o = (Ull)68LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[46][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[1][17];
	ea128.ea4.ea1b = (Ull)ip1[1][17];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[46][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[1][0];
	ea128.ea4.ea0o = (Ull)72LL;
	ea128.ea4.ea1b = (Ull)kp0[1][0];
	ea128.ea4.ea1o = (Ull)72LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[47][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[1][0];
	ea128.ea4.ea0o = (Ull)72LL;
	ea128.ea4.ea1b = (Ull)kp2[1][0];
	ea128.ea4.ea1o = (Ull)72LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[47][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[1][18];
	ea128.ea4.ea1b = (Ull)ip1[1][18];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[47][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[1][0];
	ea128.ea4.ea0o = (Ull)76LL;
	ea128.ea4.ea1b = (Ull)kp0[1][0];
	ea128.ea4.ea1o = (Ull)76LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[48][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[1][0];
	ea128.ea4.ea0o = (Ull)76LL;
	ea128.ea4.ea1b = (Ull)kp2[1][0];
	ea128.ea4.ea1o = (Ull)76LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[48][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[1][19];
	ea128.ea4.ea1b = (Ull)ip1[1][19];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[48][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[1][0];
	ea128.ea4.ea0o = (Ull)80LL;
	ea128.ea4.ea1b = (Ull)kp0[1][0];
	ea128.ea4.ea1o = (Ull)80LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[49][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[1][0];
	ea128.ea4.ea0o = (Ull)80LL;
	ea128.ea4.ea1b = (Ull)kp2[1][0];
	ea128.ea4.ea1o = (Ull)80LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[49][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[1][20];
	ea128.ea4.ea1b = (Ull)ip1[1][20];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[49][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[1][0];
	ea128.ea4.ea0o = (Ull)84LL;
	ea128.ea4.ea1b = (Ull)kp0[1][0];
	ea128.ea4.ea1o = (Ull)84LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[50][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[1][0];
	ea128.ea4.ea0o = (Ull)84LL;
	ea128.ea4.ea1b = (Ull)kp2[1][0];
	ea128.ea4.ea1o = (Ull)84LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[50][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[1][21];
	ea128.ea4.ea1b = (Ull)ip1[1][21];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[50][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[1][0];
	ea128.ea4.ea0o = (Ull)88LL;
	ea128.ea4.ea1b = (Ull)kp0[1][0];
	ea128.ea4.ea1o = (Ull)88LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[51][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[1][0];
	ea128.ea4.ea0o = (Ull)88LL;
	ea128.ea4.ea1b = (Ull)kp2[1][0];
	ea128.ea4.ea1o = (Ull)88LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[51][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[1][22];
	ea128.ea4.ea1b = (Ull)ip1[1][22];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[51][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[1][0];
	ea128.ea4.ea0o = (Ull)92LL;
	ea128.ea4.ea1b = (Ull)kp0[1][0];
	ea128.ea4.ea1o = (Ull)92LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[52][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[1][0];
	ea128.ea4.ea0o = (Ull)92LL;
	ea128.ea4.ea1b = (Ull)kp2[1][0];
	ea128.ea4.ea1o = (Ull)92LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[52][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[1][23];
	ea128.ea4.ea1b = (Ull)ip1[1][23];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[52][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[1][0];
	ea128.ea4.ea0o = (Ull)96LL;
	ea128.ea4.ea1b = (Ull)kp0[1][0];
	ea128.ea4.ea1o = (Ull)96LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[53][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[1][0];
	ea128.ea4.ea0o = (Ull)96LL;
	ea128.ea4.ea1b = (Ull)kp2[1][0];
	ea128.ea4.ea1o = (Ull)96LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[53][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[1][24];
	ea128.ea4.ea1b = (Ull)ip1[1][24];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[53][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[1][0];
	ea128.ea4.ea0o = (Ull)100LL;
	ea128.ea4.ea1b = (Ull)kp0[1][0];
	ea128.ea4.ea1o = (Ull)100LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[54][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[1][0];
	ea128.ea4.ea0o = (Ull)100LL;
	ea128.ea4.ea1b = (Ull)kp2[1][0];
	ea128.ea4.ea1o = (Ull)100LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[54][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[1][25];
	ea128.ea4.ea1b = (Ull)ip1[1][25];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[54][2]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp1[1][0];
	ea128.ea4.ea0o = (Ull)104LL;
	ea128.ea4.ea1b = (Ull)kp0[1][0];
	ea128.ea4.ea1o = (Ull)104LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[55][0]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)kp3[1][0];
	ea128.ea4.ea0o = (Ull)104LL;
	ea128.ea4.ea1b = (Ull)kp2[1][0];
	ea128.ea4.ea1o = (Ull)104LL;
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[55][1]) = ea128.dll;
	ea128.ea4.ea0b = (Ull)ip0[1][26];
	ea128.ea4.ea1b = (Ull)ip1[1][26];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[55][2]) = ea128.dll;
	ea128.ea4.ea0o = (Ull)op0[0];
	ea128.ea4.ea1b = (Ull)op0[0];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[57][0]) = ea128.dll;
	ea128.ea4.ea0o = (Ull)op1[0];
	ea128.ea4.ea1b = (Ull)op1[0];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[57][1]) = ea128.dll;
	ea128.ea4.ea0o = (Ull)op2[0];
	ea128.ea4.ea1b = (Ull)op2[0];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[57][2]) = ea128.dll;
	ea128.ea4.ea0o = (Ull)op3[0];
	ea128.ea4.ea1b = (Ull)op3[0];
	*(Dll*)&(((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].addr[57][3]) = ea128.dll;
	}
	//pthread_mutex_unlock(&axi_dma_mutex);
	get_nanosec(LANE, NANOS_REGV);
	//pthread_mutex_lock(&axi_dma_mutex);
	emax7[LANE].status = STATUS_RANGE;
	{struct reg_ctrl *reg_ctrl = emax7[LANE].reg_ctrl;
	 Uint            lmmic     = emax7[LANE].lmmic;
	*(Ull*)&(reg_ctrl->i[0].addr[2][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[2][2].top) = ((Ull)(emax7[LANE].lmmi[0][10][2][lmmic].top+emax7[LANE].lmmi[0][10][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][10][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[3][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[3][2].top) = ((Ull)(emax7[LANE].lmmi[0][10][2][lmmic].top+emax7[LANE].lmmi[0][10][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][10][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[4][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[4][2].top) = ((Ull)(emax7[LANE].lmmi[0][10][2][lmmic].top+emax7[LANE].lmmi[0][10][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][10][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[5][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[5][2].top) = ((Ull)(emax7[LANE].lmmi[0][10][2][lmmic].top+emax7[LANE].lmmi[0][10][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][10][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[6][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[6][2].top) = ((Ull)(emax7[LANE].lmmi[0][10][2][lmmic].top+emax7[LANE].lmmi[0][10][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][10][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[7][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[7][2].top) = ((Ull)(emax7[LANE].lmmi[0][10][2][lmmic].top+emax7[LANE].lmmi[0][10][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][10][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[8][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[8][2].top) = ((Ull)(emax7[LANE].lmmi[0][10][2][lmmic].top+emax7[LANE].lmmi[0][10][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][10][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[9][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[9][2].top) = ((Ull)(emax7[LANE].lmmi[0][10][2][lmmic].top+emax7[LANE].lmmi[0][10][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][10][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[10][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[10][2].top) = ((Ull)(emax7[LANE].lmmi[0][10][2][lmmic].top+emax7[LANE].lmmi[0][10][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][10][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[11][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[11][2].top) = ((Ull)(emax7[LANE].lmmi[0][19][2][lmmic].top+emax7[LANE].lmmi[0][19][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][19][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[12][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[12][2].top) = ((Ull)(emax7[LANE].lmmi[0][19][2][lmmic].top+emax7[LANE].lmmi[0][19][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][19][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[13][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[13][2].top) = ((Ull)(emax7[LANE].lmmi[0][19][2][lmmic].top+emax7[LANE].lmmi[0][19][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][19][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[14][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[14][2].top) = ((Ull)(emax7[LANE].lmmi[0][19][2][lmmic].top+emax7[LANE].lmmi[0][19][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][19][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[15][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[15][2].top) = ((Ull)(emax7[LANE].lmmi[0][19][2][lmmic].top+emax7[LANE].lmmi[0][19][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][19][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[16][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[16][2].top) = ((Ull)(emax7[LANE].lmmi[0][19][2][lmmic].top+emax7[LANE].lmmi[0][19][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][19][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[17][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[17][2].top) = ((Ull)(emax7[LANE].lmmi[0][19][2][lmmic].top+emax7[LANE].lmmi[0][19][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][19][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[18][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[18][2].top) = ((Ull)(emax7[LANE].lmmi[0][19][2][lmmic].top+emax7[LANE].lmmi[0][19][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][19][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[19][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[19][2].top) = ((Ull)(emax7[LANE].lmmi[0][19][2][lmmic].top+emax7[LANE].lmmi[0][19][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][19][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[20][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[20][2].top) = ((Ull)(emax7[LANE].lmmi[0][28][2][lmmic].top+emax7[LANE].lmmi[0][28][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][28][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[21][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[21][2].top) = ((Ull)(emax7[LANE].lmmi[0][28][2][lmmic].top+emax7[LANE].lmmi[0][28][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][28][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[22][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[22][2].top) = ((Ull)(emax7[LANE].lmmi[0][28][2][lmmic].top+emax7[LANE].lmmi[0][28][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][28][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[23][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[23][2].top) = ((Ull)(emax7[LANE].lmmi[0][28][2][lmmic].top+emax7[LANE].lmmi[0][28][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][28][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[24][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[24][2].top) = ((Ull)(emax7[LANE].lmmi[0][28][2][lmmic].top+emax7[LANE].lmmi[0][28][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][28][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[25][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[25][2].top) = ((Ull)(emax7[LANE].lmmi[0][28][2][lmmic].top+emax7[LANE].lmmi[0][28][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][28][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[26][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[26][2].top) = ((Ull)(emax7[LANE].lmmi[0][28][2][lmmic].top+emax7[LANE].lmmi[0][28][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][28][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[27][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[27][2].top) = ((Ull)(emax7[LANE].lmmi[0][28][2][lmmic].top+emax7[LANE].lmmi[0][28][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][28][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[28][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[28][2].top) = ((Ull)(emax7[LANE].lmmi[0][28][2][lmmic].top+emax7[LANE].lmmi[0][28][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][28][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[29][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[29][2].top) = ((Ull)(emax7[LANE].lmmi[0][37][2][lmmic].top+emax7[LANE].lmmi[0][37][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][37][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[30][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[30][2].top) = ((Ull)(emax7[LANE].lmmi[0][37][2][lmmic].top+emax7[LANE].lmmi[0][37][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][37][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[31][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[31][2].top) = ((Ull)(emax7[LANE].lmmi[0][37][2][lmmic].top+emax7[LANE].lmmi[0][37][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][37][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[32][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[32][2].top) = ((Ull)(emax7[LANE].lmmi[0][37][2][lmmic].top+emax7[LANE].lmmi[0][37][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][37][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[33][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[33][2].top) = ((Ull)(emax7[LANE].lmmi[0][37][2][lmmic].top+emax7[LANE].lmmi[0][37][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][37][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[34][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[34][2].top) = ((Ull)(emax7[LANE].lmmi[0][37][2][lmmic].top+emax7[LANE].lmmi[0][37][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][37][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[35][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[35][2].top) = ((Ull)(emax7[LANE].lmmi[0][37][2][lmmic].top+emax7[LANE].lmmi[0][37][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][37][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[36][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[36][2].top) = ((Ull)(emax7[LANE].lmmi[0][37][2][lmmic].top+emax7[LANE].lmmi[0][37][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][37][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[37][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[37][2].top) = ((Ull)(emax7[LANE].lmmi[0][37][2][lmmic].top+emax7[LANE].lmmi[0][37][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][37][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[38][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[38][2].top) = ((Ull)(emax7[LANE].lmmi[0][46][2][lmmic].top+emax7[LANE].lmmi[0][46][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[39][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[39][2].top) = ((Ull)(emax7[LANE].lmmi[0][46][2][lmmic].top+emax7[LANE].lmmi[0][46][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[40][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[40][2].top) = ((Ull)(emax7[LANE].lmmi[0][46][2][lmmic].top+emax7[LANE].lmmi[0][46][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[41][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[41][2].top) = ((Ull)(emax7[LANE].lmmi[0][46][2][lmmic].top+emax7[LANE].lmmi[0][46][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[42][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[42][2].top) = ((Ull)(emax7[LANE].lmmi[0][46][2][lmmic].top+emax7[LANE].lmmi[0][46][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[43][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[43][2].top) = ((Ull)(emax7[LANE].lmmi[0][46][2][lmmic].top+emax7[LANE].lmmi[0][46][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[44][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[44][2].top) = ((Ull)(emax7[LANE].lmmi[0][46][2][lmmic].top+emax7[LANE].lmmi[0][46][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[45][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[45][2].top) = ((Ull)(emax7[LANE].lmmi[0][46][2][lmmic].top+emax7[LANE].lmmi[0][46][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[46][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[46][2].top) = ((Ull)(emax7[LANE].lmmi[0][46][2][lmmic].top+emax7[LANE].lmmi[0][46][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][46][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[47][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[47][2].top) = ((Ull)(emax7[LANE].lmmi[0][55][2][lmmic].top+emax7[LANE].lmmi[0][55][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[48][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[48][2].top) = ((Ull)(emax7[LANE].lmmi[0][55][2][lmmic].top+emax7[LANE].lmmi[0][55][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[49][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[49][2].top) = ((Ull)(emax7[LANE].lmmi[0][55][2][lmmic].top+emax7[LANE].lmmi[0][55][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[50][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[50][2].top) = ((Ull)(emax7[LANE].lmmi[0][55][2][lmmic].top+emax7[LANE].lmmi[0][55][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[51][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[51][2].top) = ((Ull)(emax7[LANE].lmmi[0][55][2][lmmic].top+emax7[LANE].lmmi[0][55][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[52][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[52][2].top) = ((Ull)(emax7[LANE].lmmi[0][55][2][lmmic].top+emax7[LANE].lmmi[0][55][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[53][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[53][2].top) = ((Ull)(emax7[LANE].lmmi[0][55][2][lmmic].top+emax7[LANE].lmmi[0][55][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[54][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[54][2].top) = ((Ull)(emax7[LANE].lmmi[0][55][2][lmmic].top+emax7[LANE].lmmi[0][55][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[55][0].top) = ((Ull)(emax7[LANE].lmmi[0][55][0][lmmic].top+emax7[LANE].lmmi[0][55][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[55][2].top) = ((Ull)(emax7[LANE].lmmi[0][55][2][lmmic].top+emax7[LANE].lmmi[0][55][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][55][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[57][0].top) = ((Ull)(emax7[LANE].lmmi[0][57][0][lmmic].top+emax7[LANE].lmmi[0][57][0][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][57][0][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[57][1].top) = ((Ull)(emax7[LANE].lmmi[0][57][1][lmmic].top+emax7[LANE].lmmi[0][57][1][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][57][1][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[57][2].top) = ((Ull)(emax7[LANE].lmmi[0][57][2][lmmic].top+emax7[LANE].lmmi[0][57][2][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][57][2][lmmic].top;
	*(Ull*)&(reg_ctrl->i[0].addr[57][3].top) = ((Ull)(emax7[LANE].lmmi[0][57][3][lmmic].top+emax7[LANE].lmmi[0][57][3][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[0][57][3][lmmic].top;
	}
	//pthread_mutex_unlock(&axi_dma_mutex);
	get_nanosec(LANE, NANOS_RANGE);
	emax7[LANE].status = STATUS_LOAD;
	emax7_check_lmmi_and_dma(LANE, 0, 2, emax7[LANE].lastdist, 0, 55, 0);/*load*/
	emax7_check_lmmi_and_dma(LANE, 0, 2, emax7[LANE].lastdist, 0, 57, 0);/*load*/
	emax7_check_lmmi_and_dma(LANE, 0, 2, emax7[LANE].lastdist, 0, 57, 1);/*load*/
	emax7_check_lmmi_and_dma(LANE, 0, 2, emax7[LANE].lastdist, 0, 10, 2);/*load*/
	emax7_check_lmmi_and_dma(LANE, 0, 2, emax7[LANE].lastdist, 0, 19, 2);/*load*/
	emax7_check_lmmi_and_dma(LANE, 0, 2, emax7[LANE].lastdist, 0, 28, 2);/*load*/
	emax7_check_lmmi_and_dma(LANE, 0, 2, emax7[LANE].lastdist, 0, 37, 2);/*load*/
	emax7_check_lmmi_and_dma(LANE, 0, 2, emax7[LANE].lastdist, 0, 46, 2);/*load*/
	emax7_check_lmmi_and_dma(LANE, 0, 2, emax7[LANE].lastdist, 0, 55, 2);/*load*/
	emax7_check_lmmi_and_dma(LANE, 0, 2, emax7[LANE].lastdist, 0, 57, 2);/*load*/
	emax7_check_lmmi_and_dma(LANE, 0, 2, emax7[LANE].lastdist, 0, 57, 3);/*load*/
	get_nanosec(LANE, NANOS_LOAD);
	{struct reg_ctrl *reg_ctrl = emax7[LANE].reg_ctrl;
	 Uint            lmmic     = emax7[LANE].lmmic;
	}
	((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].cmd = 3LL; // EXEC
	emax7[LANE].lmmd[57][0] = 0xff>>7;
	emax7[LANE].lmmd[57][1] = 0xff>>7;
	emax7[LANE].lmmd[57][2] = 0xff>>7;
	emax7[LANE].lmmd[57][3] = 0xff>>7;
	{ int stat; static int step;
	do {
	  if      (step <   0) step = 0;
	  else if (step > 100) step = 100;
	  if (step>1) sleep_nanosec(step*100);
	  stat = ((struct reg_ctrl*)emax7[LANE].reg_ctrl)->i[0].stat & 0xffff00ff;
	  if (stat) step++; else step--;
	} while (stat); }//LMRING_BUSY|EXRING_BUSY
	get_nanosec(LANE, NANOS_EXEC);
asm volatile("b emax7_conf_end_cnn\n"
".align 5\n"
".global emax7_conf_cnn\n"
"emax7_conf_cnn:\n"
"	.word	0x00224005, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00220005, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x008260af, 0x00001000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0xffffffff, 0x00000000\n"
"	.word	0x00c2a02f, 0x00002000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0141c0af, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0xffffffff, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00200200, 0x0003005e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003001e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x20c81c81\n"
"	.word	0x00000000, 0x0003001e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000001, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x02210025, 0x00000000\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00802000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x02010025, 0x00000000\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x02a10025, 0x00000000\n"
"	.word	0xffff0000, 0x20c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x02810025, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00803000, 0x0003017e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00e02e02\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x30c81c81\n"
"	.word	0x00000000, 0x0003007e\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x11004021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00020003, 0x00000064\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x0100c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x51014021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x4101c021, 0x00000001\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000060\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00200027, 0x00004000\n"
"	.word	0xffff0000, 0x08c81e51\n"
"	.word	0xab826002, 0x0007811c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00a06027, 0x00004000\n"
"	.word	0xffff0000, 0x08c81e51\n"
"	.word	0xab82e00a, 0x0007811c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x01208027, 0x00004000\n"
"	.word	0xffff0000, 0x08c81e51\n"
"	.word	0xab020000, 0x0007801c\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x01a0e027, 0x00004000\n"
"	.word	0xffff0000, 0x08c81e51\n"
"	.word	0xab000000, 0x00078018\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0xffff0000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
"	.word	0x00000000, 0x00000000\n"
".global emax7_conf_end_cnn\n"
"emax7_conf_end_cnn:\n"
);
#endif
        }
      }
    }
  }
#ifndef EMAXSC
	emax7_pre_with_drain_cache();
	get_nanosec(LANE, NANOS_ARM);
	{
	  struct reg_ctrl *reg_ctrl = emax7[LANE].reg_ctrl;
	  Uint   lmmic              = emax7[LANE].lmmic;
	  Uint   mapdist            = emax7[LANE].mapdist;
	  int    c,i,j;
	  emax7[LANE].status = STATUS_DRAIN;
	  for (j=0; j<4; j++) {
	    for (i=0; i<64; i++) {
	      if (emax7[LANE].lmmi_bitmap[j] & (1LL<<i) && emax7[LANE].lmmi[0][i][j][lmmic].rw) {
	        for (c=0; c<1; c++) {
	          if (emax7[LANE].lmmi[0][i][j][lmmic].ofs)
	            *(Ull*)&(reg_ctrl->i[c].addr[i][j].top) = ((Ull)(emax7[LANE].lmmi[c][i][j][lmmic].top+emax7[LANE].lmmi[c][i][j][lmmic].len*sizeof(Uint)+(sizeof(Uint)-1))<<32) | (Ull)(Uint)emax7[LANE].lmmi[c][i][j][lmmic].top;
	          emax7_check_lmmi_and_dma(LANE, 1, 1, mapdist, c, i, j);/*drain*/
	        }
	      }
	    }
	  }
	}
	get_nanosec(LANE, NANOS_DRAIN);
#endif
}
