
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "tree.h"

void show_tree (struct _node *t, struct _node *parent)
{
    if (!t) { 
       printf ("\n");
       return;
    }

    printf ("(%d)->%d ", DATA(t), DATA(parent));

    show_tree (LEFT(t), t);
    show_tree (RIGHT(t), t);
}

int get_height(struct _node *t)
{
   if (!t) return 0;
 
   return t->height;
}

#define ADJUST_HEIGHT(t)     (max(HEIGHT(LEFT(t)), HEIGHT(RIGHT(t))) + 1)

struct _node * create_node (int data)
{
   struct _node * n ;
   n = (struct _node*) malloc (sizeof(*n));
   if (!n) return n;
  
   memset (n, 0, sizeof(*n));
   n->left = n->right = NULL;
   n->data = data;
   n->height = 1;
   
   return n;
   
}

static int check_balance (struct _node *left, struct _node *right)
{
    return (HEIGHT(left) - HEIGHT(right));
}

/*
 * rotate right operation 
 *    (a) move left node to top   n->left ->right = node;
      (b) node->left = n->left->right
 */

struct _node* rotate_right (struct _node *t)
{
    if (!t || LEFT(t) == NULL) return t;

    struct _node *n_head = t->left;
    struct _node *left = LEFT(t)->right;

    LEFT(t)->right = t;
    t->left = left;

    t->height = ADJUST_HEIGHT(t);
    n_head->height = ADJUST_HEIGHT(n_head);

    return n_head;
}

struct _node * rotate_left (struct _node *t)
{
   
   if (!t || RIGHT(t) == NULL) return t;
  
   struct _node *new_head = RIGHT(t);
   struct _node *right = RIGHT(t)->left;
  
   RIGHT(t)->left = t;
   t->right = right;

   t->height = ADJUST_HEIGHT(t);
   new_head->height = ADJUST_HEIGHT(new_head); 

   return new_head;
}

/* insert into AVL tree
       (a) insert as a binary tree 
       (b) adjust the height
       (c) check the balance between left and right
       (d) rotate the tree 
*/

struct _node* insert_into_tree ( struct _node *t, int data)
{
    int balance;
    if (!t) return create_node (data);
 
    if (data < DATA(t)){
        LEFT(t) = insert_into_tree (LEFT(t), data);
    } else if (data > DATA(t)){
        RIGHT(t) = insert_into_tree (RIGHT(t), data);
    } else return t;

    t->height = ADJUST_HEIGHT(t);

    balance = check_balance (LEFT(t), RIGHT(t));

    if (balance > 1){   /* LEFT HEAVY TREE */
        LEFT(t) = (data > DATA(LEFT(t))) ? rotate_left(LEFT(t)) : LEFT(t);
        return rotate_right ((t));
    } else if (balance < -1){    /* RIGHT HEAVY */
        RIGHT(t) = (data < DATA(RIGHT(t))) ? rotate_right(RIGHT(t)) : RIGHT(t);
        return rotate_left ((t));
    }

    return t;
}
