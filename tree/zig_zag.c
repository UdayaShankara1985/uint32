

/*  Traverse Tree in zig zag. 
    Create a 2 dimensinal stack 
    push the values into each level stack while visiting pre order
    display the content by poping
*/


struct stack
{
   int array[MAX];
   int st_idx;
}st[MAX_ST];

bool is_stack_empty (struct stack *st)
{
   return (st->st_idx == 0);
}

void push_data (struct stack *st, int data)
{
   st->array[st->st_idx++] = data;
}

int pop_data (struct stack *st)
{
   return st->array[--st->st_idx];
}
  

int push (int level, int data)
{
   push_data(st[level], data);
}

void print_zigZag (struct _node *t, int level, int *max_level)
{
   if (!t) return ;

   push (level, t->data);

   *max_level = max (*max_level, level);

   level ++;
   print_zigZag (t->left, level);
   print_zigZag (t->right, level);

   return
}
  
int zig_zag_t (struct _node *t)
{
   int max_level = 0;

   print_zigZag (t, 0, &max_level);

   for (int idx = 0; idx < max_level; idx ++){
        while (is_stack_empty(idx)){
             printf ("%d ", pop(idx)); 
        }
   }
}

