
/* Check the sum of left + right = node return true */

int is_sum_equal_to_childrens (struct _node* t)
{
   if (!t) return true; 

   if (DATA(LEFT(t)) == DATA(RIGHT(t)) && is_sum_equal_to_childrens (LEFT(t))
                   && is_sum_equal_to_childrens (RIGHT(t))){
       
       return true;
   }
 
   return false;
}


static inline int get_data(struct node *n)
{
   return n->data;
}


static inline struct node* get_next( struct node *n)
{
   return n ? n->next : n;
}

#define  DATA(n)    get_data(n) 
#define  RIGHT(n)   n->right
#define  LEFT(n)    n->left

int is_sum_eq (struct node *head)
{
   if (!head) return true;

   if (is_leaf (head)) return true;

   if (!head->left || !head->right) return false;

   if (head->left->data != left->right->data){
        return false;
   }

   if (is_sum_eq (head->left) &&  is_sum_eq(head->right)){
       return true;
   }

   return false;
}

