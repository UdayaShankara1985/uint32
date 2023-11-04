
/* 
 * EXtrace node print : This is acutally a breadth first algothrithm 
 * We push the root and then move on to get the node and print its left and right values 
 */



int bfs ( st, left)
{

   if (is_empty (st)) return ;

   while (!st_empty(st)){
     root = pop (st);
     if (left){
        if (root->left) push (root->left, left);
        if (root->left) push (root->right,left);
     } else {
        if (root->left) push (root->right,left);
        if (root->left) push (root->left, left);
     }
   }

   printf ("%d \n", root->data);

   bfs (st,!left);

}

main()
{
  push (st, root);
  bfs (st, true);
}
