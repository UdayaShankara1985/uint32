
#include "tree.h"


int is_tree_self_mirror (struct _node *t)
{
    if (!t) return 1;

    if (DATA(LEFT(t)) != DATA(RIGHT(t))) 
          return 0;

    if(is_tree_self_mirror(LEFT(t)) == 0 || is_tree_self_mirror(RIGHT(t)) == 0){
       return 0;
    }

    return 1;
}
