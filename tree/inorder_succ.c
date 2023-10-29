
#include "tree.h"

/* Inorder successor in binary saarch tree is get_next of current node */

struct _node* get_next_tree (struct _node *t, int value, int *found)
{
   struct _node *n = NULL;
   if (!t) return NULL;

   if (DATA(t) == value) {
       *found = 1 ;
   }

   n = get_next_tree (t->left, value , found);
   if (!n)
      n = get_next_tree (t->right, value, found);

   if (DATA(t) > value && *found) return t;

   return n;
}

struct _node * get_prev_tree (struct _node *t, int value, struct _node **prev)
{
   struct _node *n;

   if (!t) return NULL;

   if (t->data == value){
      if (t->left){
          return t->left;
      }
      else {
          return *prev;
      }
   }


   if (t->data < value) {
       *prev = t;
   }
  
   if (t->data < value) {
      return get_prev_tree (t->right, value , prev);
   } else {
      return get_prev_tree (t->left, value , prev);
   }
}

int in_order_successor (struct _node *t, int value)
{
   struct _node *n;
   int found = 0;
   struct _node *prev = NULL;

   if (t->data == value) return -1;
   n = get_prev_tree (t, value, &prev);
   if (n) return DATA(n);

   else return -1;
}

