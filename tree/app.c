
#include "tree.h"


int main()
{
   struct _node * t = NULL;

   t = insert_into_tree (t, 3);
   t = insert_into_tree (t, 2);
   t = insert_into_tree (t, 9);
   t = insert_into_tree (t, 1);
   t = insert_into_tree (t, 15);
   t = insert_into_tree (t, 71);


   show_tree (t, t);
}
