/* { dg-do compile } */
/* { dg-options "-O -fprofile-generate=. -fdump-tree-tree_profile" } */
/* { dg-final { scan-tree-dump " ./profile-dir-1.gcda" "tree_profile" } } */

int
main(void)
{
  return 0;
}

/* { dg-final { cleanup-tree-dump "tree_profile" } } */
