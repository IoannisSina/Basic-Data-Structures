#include "../_file_open/file_open.h"
#include <stdio.h>
#include <stdlib.h>

/*#include <time.h>
     
clock_t start, end;
double cpu_time_used;*/



void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort(int *arr, int start, int end)
{
    if(start == end)
      return;
    
    int left = start, right = end;
    int mid = (start+end)/2;
    int pivot = arr[mid];
    
    while(left < right)
    {
	  printf("HERE ");
      while(arr[left]<pivot)
        left++;
      while(arr[right]>pivot)
        right--;
      
      if(left<right)
        swap(&arr[left],&arr[right]);
    }
  
  
    //left array
    if(right > start)
      quicksort(arr, start, right);
  
    //right array
    if(left < end)
      quicksort(arr, left, end);
  
    //int arr[N] = {1,2,4,5,5,6,7,8,9};

  
}


int main(int argc, char* argv[]) {
	
	int N;
	int *arr = fill_array(argv[1], &N);
	printf("%d",arr[0]);
	
    //start = clock();


    quicksort(arr,0,N-1);
    
    //end = clock();
    //cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    //printf("%f\n", cpu_time_used);
  
    
    int k;
   
    for(k=0;k<N;k++)
		printf("%d ", arr[k]);
    
    printf("\n");
	
	
	free(arr);
	
    return 0;
}
