
#include "tree.h"

bool is_tree_bst (struct _node *n)
{
   if (!n) return true;

// preorder
   if (DATA(LEFT(t)) > DATA(RIGHT(t))) 
       return false;

   if (is_tree_bst (LEFT(t)) == false || is_tree_bst (RIGHT(t)) == false){
      return false;
   }

   return true;



// post order 

   if (is_tree_bst (LEFT(t)) == true &&  is_tree_bst (RIGHT(t)) == true ){
       if (data(t) == data(right)) return true;
   }

   return false;
}
