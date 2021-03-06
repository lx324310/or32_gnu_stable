/* { dg-do run } */
/* { dg-options "-fdump-tree-alias" } */
/* { dg-skip-if "" { *-*-* } { "-O0" } { "" } } */

int *p;
void __attribute__((noinline,noclone))
bar (void)
{
  *p = 1;
}
int __attribute__((noinline,noclone))
foo (__SIZE_TYPE__ addr)
{
  int i;
  /* q points to ANYTHING */
  int **q = (int **)addr;
  /* this store needs to cause i to escape */
  *q = &i;
  i = 0;
  /* and thus be clobbered by this function call */
  bar ();
  return i;
}
extern void abort (void);
int
main()
{
  if (foo ((__SIZE_TYPE__)&p) != 1)
    abort ();
  return 0;
}

/* { dg-final { scan-tree-dump "ESCAPED = { ESCAPED NONLOCAL i }" "alias" } } */
/* { dg-final { cleanup-tree-dump "alias" } } */
