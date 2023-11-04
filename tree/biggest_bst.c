

#include <stdio.h>

int max (int a, b )
{
  return (a > b) ? a : b;
}

int is_node_bst (head)
{
  if (head->left) {
     if (head->left->data > head->data) return false;
  }

  if (head->right){
     if (head->right->data < head->data) return false;
  }      

  return true;
}

int is_bst (struct node *head, int *max, struct node *max_node)
{
   int max_l = -1;
   int max_r = -1;

   if (!head) { *max = 0 ; return true;  }

   l_tree = is_bst (head->left, &max_l);
   r_tree = is_bst (head->right, &max_r);

   if (l_tree == true && r_tree == true && is_node_bst (head)){

       *max = max (max1, max2) + 1 ;
        max_node = head;
        return true;
   }

   if (l_tree == true){
       *max = max1;
        *max_node = head->left;
   } else if (r_tree == true){
       *max = max2;
       *max_node = head->right;
   }     
 
   return false;
}

int main()
{
   int max = -1;
   struct node bst_node = { 0};

   is_bsr (head, &max, &bst_node);

   if (max > 0){
      printf ("max %d \n", max);
   }
}
