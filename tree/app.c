
#include "tree.h"


struct _node * get_matching_node (struct _node *t, int data)
{
   struct _node *n;

   if (!t) return NULL;

   if (data == t->data) return t;

   n = get_matching_node(t->left , data);
   if (n) return n;

   n = get_matching_node (t->right, data); 
   return n;
}


int main()
{
   struct _node * t = NULL;
int print_nodes_at_k_distance (struct _node *t, struct _node *target, int k);

   t = insert_into_tree (t, 3);
   t = insert_into_tree (t, 2);
   t = insert_into_tree (t, 9);
   t = insert_into_tree (t, 1);
   t = insert_into_tree (t, 15);
   t = insert_into_tree (t, 71);


   print_nodes_at_k_distance (t, get_matching_node (t, 9), 2);
//   show_tree (t, t);
}
