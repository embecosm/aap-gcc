/* { dg-do run } */
/* { dg-options "-DEXPENSIVE" { target run_expensive_tests } } */
/* { dg-options "-fno-common" { target hppa*-*-hpux* } } */
/* { dg-skip-if "" { ! run_expensive_tests } { "*" } { "-O2" } } */
/* { dg-skip-if "" { ! run_expensive_tests } { "-flto" } { "" } } */
/* { dg-require-effective-target builtin_shuffle } */
/* { dg-require-effective-target noclone } */

#if __SIZEOF_DOUBLE__ == 8 && __SIZEOF_LONG_LONG__ == 8
typedef double V __attribute__((vector_size(16)));
typedef unsigned long long VI __attribute__((vector_size(16)));
#else
#define UNSUPPORTED
#endif

#include "vshuf-2.inc"
#include "vshuf-main.inc"
