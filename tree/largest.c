


int print_larget ()
{
    int max = 0;
   
    if (is_st_empty ()) return 0;

    st_size = st_size(st);


    while (st_size --){
       node =  recv_msgQ(msgQ);
       max = max (node, max);
  
       send_msgQ (msgQ, node->left);
       send_msgQ (msgQ, node->right);
    }

    print_largest();
    printf ("max %d\n", max);

    return 0;

}
