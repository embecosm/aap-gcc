/* { dg-require-effective-target vect_int } */
/* { dg-additional-options "-fno-ipa-icf" } */

#include "tree-vect.h"
#include <stdlib.h>

#define N 32

__attribute__ ((noinline)) void 
foo (unsigned int *__restrict a,
     unsigned short *__restrict b,
     int n)
{
  int i;

  for (i = 0; i < n; i++)
    a[i] = b[i] * 2333;

  for (i = 0; i < n; i++)
    if (a[i] != b[i] * 2333)
      abort ();
}

__attribute__ ((noinline)) void
bar (unsigned int *__restrict a,
     unsigned short *__restrict b,
     int n)
{
  int i;

  for (i = 0; i < n; i++)
    a[i] = (unsigned short) 2333 * b[i];

  for (i = 0; i < n; i++)
    if (a[i] != b[i] * (unsigned short) 2333)
      abort ();
}

__attribute__ ((noinline)) void
baz (unsigned int *__restrict a,
     unsigned short *__restrict b,
     int n)
{
  int i;

  for (i = 0; i < n; i++)
    a[i] = b[i] * 233333333;

  for (i = 0; i < n; i++)
    if (a[i] != b[i] * 233333333)
      abort ();
}


int main (void)
{
  int i;
  unsigned int a[N];
  unsigned short b[N];

  for (i = 0; i < N; i++)
    {
      a[i] = 0;
      b[i] = i;
      __asm__ volatile ("");
    }

  foo (a, b, N);
  bar (a, b, N);
  baz (a, b, N);
  return 0;
}

/* { dg-final { scan-tree-dump-times "vectorized 1 loops" 3 "vect" { target vect_widen_mult_hi_to_si } } } */
/* { dg-final { scan-tree-dump-times "vect_recog_widen_mult_pattern: detected" 2 "vect" { target vect_widen_mult_hi_to_si_pattern } } } */
/* { dg-final { scan-tree-dump-times "pattern recognized" 2 "vect" { target vect_widen_mult_hi_to_si_pattern } } } */
