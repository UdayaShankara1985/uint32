
/*  programe to print all the nodes at K distances from target node */

/*   (a) travers in tree identify the subtree of target node 1) tarvers down at k and print
     (b) come back step and traverse (k - return + (right travers remaining)A
            (!) create print down all the nodes at k 
  
     (c) Same thing for right sub tree .
        
*/

#include "tree.h"



void print_forward (struct _node *t, int k)
{
    if (!t || k < 0) return ;
 
    if (k == 0) printf ("%d ", t->data);

    print_forward (t->left, k-1);
    print_forward (t->right, k-1);

}



int print_nodes_at_k_distance (struct _node *t, struct _node *target, int k)
{

   int dl, dr;
   if (t == NULL) return -1;     // return distance 
   if (k < 0) return -1;
 
   if (t == target) {
       print_forward (t , k);
       return 1;
   }

   
   dl = print_nodes_at_k_distance (t->left, target , k);
   if (dl == -1){
       goto right_side;
   } else if (dl == k){
      printf ("%d ", t->data);
   } else {
       print_forward (t->right , (k-dl));
   }

   return dl + 1;


right_side :
   
   dr = print_nodes_at_k_distance (t->right, target, k);
   if (dr == -1) return -1;

   else if  (dr == k){
      printf("%d ", t->data);
   } else {
       print_forward (t->left, (k-dr));
   }

   return dr + 1;

}
