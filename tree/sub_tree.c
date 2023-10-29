#include "tree.h"

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
