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
    int did_swap = 0;

    for(i=1; i<N; i++) {
        for(j=0; j<N-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                did_swap = 1;   //swap happened
            }
        }

        for(k=0;k<N;k++) {
            printf("%d\n", arr[k]);
        }
        printf("\n");

        if(did_swap == 0)
            break;

        did_swap = 0;

    }
	
	free(arr);

    return 0;
}
