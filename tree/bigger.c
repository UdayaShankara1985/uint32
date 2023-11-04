


struct node 
{
  struct node *left;
  struct node *right;
  int data;
  int elected;
};



int max_sum (struct node *head, int *myself)
{
  if (!head) return 0;


  if (!head->left || !head->right){
       head->elected = true;
  }

  if (head->left){
    if (
  }




}

