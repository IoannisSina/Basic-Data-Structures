#include "../_help_library/help_library.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
     

void quicksort(int *arr, int first, int last)
{
    if(first >= last)
		return;
	
    int pivot = first;
    int left = first;
    int right = last;

    while(left < right)
    {
        while(left < last && arr[left] <= arr[pivot])
            left++;
        while(arr[right] > arr[pivot])
            right--;
        if(left < right)
			swap(&arr[left],&arr[right]);
    }

	swap(&arr[pivot],&arr[right]);
		
    quicksort(arr,first,right-1);
    quicksort(arr,right+1,last);
}


int main(int argc, char* argv[]) {
	
	int N;
	int *arr = fill_array(argv[1], &N);
	
    clock_t start = clock();
    quicksort(arr,0,N-1);
    clock_t end = clock();
	
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%f\n", cpu_time_used);
  
	is_sorted(arr, N);
	
	free(arr);
	
    return 0;
}
