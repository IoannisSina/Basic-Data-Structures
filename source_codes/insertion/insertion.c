#include "../_file_open/file_open.h"
#include <stdio.h>
#include <stdlib.h>


void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}


int main(int argc, char* argv[]) {
	
	int N;
	int *arr = fill_array(argv[1], &N);

    int i, j, k;


    for(i=1; i<N; i++) {
        int to_insert = arr[i];
        for(j=i-1; j>=0 && to_insert<arr[j]; j--) {
            arr[j+1] = arr[j];  // right shift
        }
        arr[j+1] = to_insert;

		// show array for every iteration
        /*for(k=0;k<N;k++)
            printf("%d ", arr[k]);
        
        printf("\n");*/

    }
	
	for(k=0;k<N;k++)
		printf("%d ", arr[k]);

	free(arr);
	
    return 0;
}
