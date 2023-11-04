#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct node 
{
  int data;
  struct node *left;
  struct node *right;
};

bool print_path (struct node *head, struct node *t)
{
   if (!head) return false;

  
   if ( head == t || (print_path (head->left, t) == true) || (print_path (head->right, t) == true)){
       printf ("%d ", head->data);
       return true;
   }

   return false;
   
}

struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int max_sum_path (struct node *root, struct node **target_node)
{
   struct node *tg1 = NULL, *tg2 = NULL;
   int l_max, r_max, max;

   if (!root) return 0;

   if (*target_node ==  NULL) *target_node = root;

   l_max = max_sum_path (root->left, &tg1);
   r_max = max_sum_path (root->right, &tg2);


   if (l_max > r_max){
      max = l_max;
      *target_node = tg1 ? tg1 : *target_node;
   } else {
      max = r_max;
      *target_node = tg2 ? tg2 : *target_node;
   }   

   return root->data + max;
}


int get_branch_sum (struct node *root)
{
   if (!root) return 0;

   return root->data + get_branch_sum (root->left) + get_branch_sum (root->right);
}

bool is_sum_tree_1 (struct node *root)
{
  
   if (get_branch_sum (root->left) + get_branch_sum (root->right) == root->data)
       return true;

   return false;
     
}


bool is_leaf_node (struct node *n)
{
  return (n->left == NULL && n->right == NULL) ? true : false;
}

bool is_sum_tree_helper (struct node *head, int *sum)
{
   int l_sum = 0, r_sum = 0;
   bool l_ret, r_ret;

   if (!head) { *sum = 0; return true; }

   if (is_leaf_node (head)){
       *sum = head->data;
       return true;
   }

   if(is_sum_tree_helper (head->left, &l_sum) == false || is_sum_tree_helper (head->right, &r_sum) == false){
      return false;
   }


   *sum = head->data  + (l_sum + r_sum);

   if (head->data == (l_sum + r_sum)){
        return true;
   } 
   return false;
}


bool is_sum_tree (struct node *head)
{
   int sum = 0;

   return  is_sum_tree_helper (head, &sum);
}


int sum_of_even_odd_v2 (struct node *head)
{
   if (!head) return 0;

   return head->data - sum_of_even_odd_v2 (head->left) - sum_of_even_odd_v2 (head->right);
}


static void sum_of_even_odd (struct node *root, int *even , int *odd, int level)
{

    if (!root) return ;

    if ((level & 0x01) == 0x00){
       *even += root->data;
    } else {
       *odd += root->data;
    }

    level ++;

    sum_of_even_odd (root->left, even, odd, level);
    sum_of_even_odd (root->right, even, odd, level);


    return ;
   
}

int sum_of_even_add_v1 (struct node *head)
{
   int even = 0, odd = 0;

   sum_of_even_odd (head, &even, &odd, 1);

   return even-odd;
}

int main()
{
 
    int even  = 0, odd = 0;

    struct node* root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(4);
    root->left->right->left = newNode(3);
    root->right->right = newNode(8);
    root->right->right->right = newNode(9);
    root->right->right->left = newNode(7);
 
    printf("Following are the nodes on the maximum "
           "sum path \n");

  //  sum_of_even_odd (root, &even, &odd, 1);
   
    //printf ("even: %d odd:%d diff:%d \n", even, odd, even -odd);

    printf ("diff %d \n", sum_of_even_odd_v2(root));

 
    getchar();
    return 0;
}
