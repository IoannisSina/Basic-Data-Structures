#include "../_file_open/file_open.h"
#include <stdio.h>
#include <stdlib.h>


void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int get_min_pos(int start, int *arr, int N) {

    int position = start;
    int min = arr[start];

    int i;
    for(i=start+1;i<N;i++)
        if(min > arr[i]) {
            min = arr[i];
            position = i;
        }

    return position;
}


int main(int argc, char* argv[]) {
	
	int N;
	int *arr = fill_array(argv[1], &N);

    int i, j, k;


    for(i=0; i<N-1; i++) {  // N-1 because the last element will be the max
        int min_pos = get_min_pos(i, arr, N);    // find the min for the unsorted array

        swap(&arr[i], &arr[min_pos]);

        /*for(k=0;k<N;k++)
            printf("%d ", arr[k]);
		
        printf("\n");*/

    }

	for(k=0;k<N;k++)
		printf("%d ", arr[k]);

	free(arr);
	
    return 0;
}

