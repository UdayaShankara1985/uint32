#include <stdio.h>


/* What is Q sort ? it is devide and conquire 
 * HOw does it works ? 

     (a)   partition based on pivotal 
     (b) 

*/

// Swap the data
void swap (int *i, int *j)
{
   int temp ;

   temp = *i;
   *i = *j;
   *j = temp;
}

// adjust the pivotal 
int get_partition (int *array, int start , int end)
{
  int piv = array[end];
  int min = start - 1;

  for ( int i = start; i < end; i ++){
      if (array[i] < piv) {
          swap (&array[++min], &array[i]);
      }
  }

  swap (&array[++min], &array[end]);
  return min;
}

// Quick sort 
void qsort (int *array, int start, int end)
{
    if (start >= end) return ;

    int piv = get_partition (array, start, end);

    qsort (array, start, piv-1);
    qsort (array, piv + 1 , end);
}

void
main()
{

   int array[] = { 1, 3 , 5, 2, 5 ,2 };

   qsort (array, 0, sizeof(array)/sizeof(array[0])-1);

   for (int idx = 0; idx < (sizeof(array)/sizeof(array[0])) ; idx ++){
       printf ("%d ", array[idx]);
   }
     
}

