#include "../_help_library/help_library.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int get_min_pos(int start, int *arr, int N) {

    int position = start;
    int min = arr[start];

    int i;
    for (i = start + 1; i < N; i++)
        if (min > arr[i]) {
            min = arr[i];
            position = i;
        }

    return position;
}

int main(int argc, char *argv[]) {
	
    if(argc != 2) { // no file selected
		printf("\n---\nplease give file location!!!\n---\n");
		return -1;
	}

    int N;
    int *arr = fill_array(argv[1], &N);

    int i;

    clock_t start = clock();

    for (i = 0; i < N - 1; i++) { // N-1 because the last element will be the max
        int min_pos = get_min_pos(i, arr, N); // find the min for the unsorted array
        swap(&arr[i], &arr[min_pos]);
    }

    clock_t end = clock();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n%lf\n\n", time_spent);

    is_sorted(arr, N);

    free(arr);

    return 0;
}