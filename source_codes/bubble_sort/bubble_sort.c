#include "../_help_library/help_library.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char* argv[]) {
	
	int N;
	int *arr = fill_array(argv[1], &N);
	
    int i, j, k;
    int did_swap = 0;

	clock_t begin = clock();

    for(i=1; i<N; i++) {
		
        for(j=0; j<N-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                did_swap = 1;   //swap happened
            }
        }

        if(did_swap == 0)
            break;

        did_swap = 0;
    }
	
	clock_t end = clock();
	
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n%lf\n\n", time_spent);

	is_sorted(arr, N);
	
	free(arr);

    return 0;
}
