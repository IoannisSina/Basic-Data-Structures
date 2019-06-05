#include "../_help_library/help_library.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void heapify_up(int *arr, int i) {

    int parent = (i - 1)/2;
    if (parent < 0) //base
        return;

    if (arr[parent] < arr[i]) {
        swap(&arr[i], &arr[parent]);
        heapify_up(arr, parent);
    }
}

void heapify_down(int *arr, int i, int size) {

    if (size < 2 * i + 1) //base
        return;

    int j;
    if (size > 2 * i + 1) {
        int left = 2 * i + 1, right = 2 * i + 2;
        j = arr[left] > arr[right] ? left : right;
    } else // if(size == 2*i + 1)
        j = 2 * i + 1; // left child
    if (arr[j] > arr[i]) {
        swap(&arr[i], &arr[j]);
        heapify_down(arr, j, size);
    }
}

void create_heap(int *arr, int N) {
    int i;
    for (i = 1; i < N; i++) // O(n)
        heapify_up(arr, i); // O(logn)
}

void sort_array(int *arr, int N) {
    int i;
    for (i = N - 1; i >= 1; i--) { // O(n)
        swap(&arr[0], &arr[i]);
        heapify_down(arr, 0, i - 1); // O(logn)
    }
}

int main(int argc, char *argv[]) {
	
    if(argc != 2) { // no file selected
		printf("\n---\nplease give file location!!!\n---\n");
		return -1;
	}

    int *arr = fill_array(argv[1], &N);

    int i;

    clock_t begin = clock();
    create_heap(arr); // O(nlong)
    sort_array(arr); // O(nlong)
    clock_t end = clock();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n%lf\n\n", time_spent);

    is_sorted(arr, N);

    free(arr);

    return 0;
}
