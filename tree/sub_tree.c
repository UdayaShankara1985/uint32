#include "tree.h"


int is_trees_identical (struct node *t1, struct node* t2)
{
   if (!t1 && !t2) return true;

   if (!t1 || !t2) return false;

   if (t1->data != t2->data )  return false;
     if ((is_trees_identical (t1->left, t2->left) == true ) && is_trees_identical (t1->right, t2->right))
         return true;

   return false;
}

bool is_subTree (struct _node *t, struct _node *st)
{
    if (st == NULL) 
         return true;

    if (!t) return false;

    if (t == st){
       if (is_trees_identical (t, st) == true)
           return true;
    }

    return (is_subTree (t->left, st) || is_subTree (t->right, st));
}
