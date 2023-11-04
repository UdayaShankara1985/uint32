

/* Insert Sort    :   | Sub Sorted Array |  Unsorted Array | 
          

   Move each item from unsorted array into the sorted array  
   move the sorted array content until the sorting is correct 

   that increases the sorted array block to 1 and unsorted array to -1

  | S | U U U U U |
  | S S | U U U U |

*/

#include <stdio.h>


void insertion_sort_with_gap(int *array, int len, int gap)
{
   int u_idx ;              // unsorted iindex
   int s_idx;               // sorted idx
   int key_to_sort ;

   
   for (u_idx = gap ;  u_idx < len ; u_idx += gap ){
       key_to_sort = array[u_idx];

       for (s_idx = u_idx ;  s_idx >= gap ; s_idx -= gap){
           if (key_to_sort > array[s_idx - gap]) break;
  
           array[s_idx] = array[s_idx - gap];
       }

       array[s_idx] = key_to_sort;
   }

}


void shell_sort (int *array, int len )
{

   for ( int gap = len/2; gap >0 ; gap /= 2){
       insertion_sort_with_gap ( array, len, gap);
   }
}



#define SIZE sizeof(array)/sizeof(array[0])
void
main()
{

   int array[] = { 1, 3 , 5, 2, 5 ,2 };

   shell_sort (array,  SIZE);

   for (int idx = 0; idx < (sizeof(array)/sizeof(array[0])) ; idx ++){
       printf ("%d ", array[idx]);
   }
     
}

