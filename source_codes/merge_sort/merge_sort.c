#include "../_help_library/help_library.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void merge(int * arr, int start, int end) {
    int mid = (start + end) / 2;
    int size = end - start + 1;
    int * temp_array = (int * ) malloc(sizeof(int) * size);

    int i = 0, a = start, b = mid + 1; // a index of the first part - b index of the second
    while (a <= mid && b <= end) {
        if (arr[a] < arr[b]) {
            temp_array[i] = arr[a];
            a++;
        } else {
            temp_array[i] = arr[b];
            b++;
        }
        i++;
    }

    while (a <= mid) {
        temp_array[i] = arr[a];
        a++;
        i++;
    }

    while (b <= end) {
        temp_array[i] = arr[b];
        b++;
        i++;
    }

    for (i = 0; i < size; i++)
        arr[start + i] = temp_array[i];

    //free(temp_array);

    return;

}

void merge_sort(int * arr, int start, int end) {
    if (end == start)
        return;

    int mid = (start + end) / 2;

    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);

    merge(arr, start, end);
}

int main(int argc, char * argv[]) {

    int N;
    int *arr = fill_array(argv[1], & N);

	
	clock_t begin = clock();
    merge_sort(arr, 0, N - 1);
	clock_t end = clock();


	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n%lf\n\n", time_spent);
	is_sorted(arr, N);
	
	free(arr);
	
    return 0;
}
