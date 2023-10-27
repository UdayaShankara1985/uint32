

#ifndef __TREE_H_
#define __TREE_H_

#include <stdio.h>

/*                left -- 0 --right
                   |             |
                   0             0
*/

struct _node
{
    struct  _node *left;              // left node
    struct  _node *right;             // right node 
    int           data;               // data
    int           height;             // height of tree 
};

struct _node* insert_into_tree (struct _node *t_head, int data);

int delete_from_tree (struct _node *t_head, int data);

int close_tree (struct _node *t_head);

void show_tree (struct _node *t_head, struct _node *parent);

static inline int get_data (struct _node *n)
{
   return n->data;
}

static int max (int a , int b)
{
   return (a > b) ? a: b ;
}

struct _node* rotate_right (struct _node *t);
struct _node * rotate_left (struct _node *t);

#define LEFT(n)       (n)->left
#define RIGHT(n)      (n)->right
#define HEIGHT(n)     get_height(n)
#define DATA(n)       get_data(n)

#endif
