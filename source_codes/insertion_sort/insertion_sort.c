#include "../_help_library/help_library.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char* argv[]) {
	
	int N;
	int *arr = fill_array(argv[1], &N);

    int i, j, k;

	clock_t begin = clock();

    for(i=1; i<N; i++) {
        int to_insert = arr[i];
		
        for(j=i-1; j>=0 && to_insert<arr[j]; j--)
            arr[j+1] = arr[j];  // right shift
		
        arr[j+1] = to_insert;
    }
	
	clock_t end = clock();
	
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n%lf\n\n", time_spent);
	is_sorted(arr, N);
	
	free(arr);
	
    return 0;
}
