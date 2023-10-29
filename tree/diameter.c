
/* Diameter of a tree is number of max nodes between 2 leafs of a tree
 * ie max depth of left and max depth of right 
 */


#include "tree.h"

int tree_height(struct _node *t)
{
   if (!t) return 0;

   return 1 + max (tree_height(LEFT(t)) , tree_height(RIGHT(t)));
}

int diameter_tree (struct _node *t)
{
   if (!t) return 0;

   return tree_height(LEFT(t)) + tree_height(RIGHT(t));
}
