

#include "tree.h"


int is_trees_identical (struct _node *t1, struct _node *t2)
{
  
    if (!t1 && !t2) return 1;

    if (!t1 || !t2) return 0;


    if (t1->data != t2->data) return 0;

    if (!is_trees_identical (t1->left, t2->left) || 
         !is_trees_identical (t1->right, t2->right)) {
        return 0;
    }

    return 1;
}

struct _node* inverse_a_tree (struct _node *t)
{

    if (!t) return NULL;

    struct _node *temp;

    inverse_a_tree (t->left); 
    inverse_a_tree (t->right); 

    temp = t->left;
    t->left = t->right;
    t->right = temp;

    return t;

}
