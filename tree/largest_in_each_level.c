
#include "tree.h"

int array[MAX_LEVEL];

void print_lar_in_level (struct _node *n, int level, int *max_level)
{
  if (!n) return;

  if (n->data > array[level])
        array[level] = n->data;

  *max_level = max (*max_level, level);

  level ++;
  print_lar_in_level (n->left, level);
  print_lar_in_level (n->left, level);

  return ;
}

void print_max_level (struct _node *t)
{
   int max_level = 1;

   print_lar_in_level (t, 1, &max_level);

   for (idx = 0; idx < max_level; idx++){
       printf ("%d ", array[idx]);
   }

}
