
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

