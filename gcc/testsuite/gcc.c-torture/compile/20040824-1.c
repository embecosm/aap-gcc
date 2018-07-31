/* This caused an out-of-range address on the MIPS port.  */
/* { dg-require-effective-target builtin_prefetch } */
void foo (char *x) { __builtin_prefetch (x + 0x8000); }
