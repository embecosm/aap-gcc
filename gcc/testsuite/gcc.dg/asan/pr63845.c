/* PR sanitizer/63845 */
/* { dg-do compile } */
/* { dg-options "-fPIC" { target fpic }  } */
/* { dg-require-effective-target noclone } */

int __attribute__ ((noinline, noclone))
foo (void *p)
{
  return *(int*)p;
}

int main ()
{
  char a = 0;
  foo (&a);
  return 0;
}

