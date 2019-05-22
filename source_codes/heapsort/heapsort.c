#include "../_file_open/file_open.h"
#include <stdio.h>
#include <stdlib.h>


void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}


void heapify_up(int* arr, int i) {

	int parent = (int)((i/2.0 + 0.5)-1.0);
	if(parent < 0)	//base
		return;

	if(arr[parent] < arr[i]) {
		swap(&arr[i], &arr[parent]);
		heapify_up(arr, parent);
	}
}


void heapify_down(int* arr, int i, int size) {

	if(size < 2*i + 1)	//base
		return;

	int j;
	if(size > 2*i + 1) {
		int left = 2*i + 1, right = 2*i + 2;
		j = arr[left] > arr[right] ? left : right;
	}
	else// if(size == 2*i + 1)
		j = 2*i + 1;	// left child
	if(arr[j] > arr[i]) {
		swap(&arr[i], &arr[j]);
		heapify_down(arr, j, size);
	}
}



void create_heap(int* arr) {
	int i;
	for(i=1;i<N;i++) // O(n)
		heapify_up(arr, i);  // O(logn)
}

void sort_array(int* arr) {
	int i;
	for(i=N-1;i>=1;i--) { // O(n)
		swap(&arr[0], &arr[i]);
		heapify_down(arr, 0, i-1);  // O(logn)
	}
}



int main(int argc, char* argv[]) {
	int N;
	int *arr = fill_array(argv[1], &N);

	int i;
	int arr[N] = {8,9,6,1,18,7};

	create_heap(arr); // O(nlong)
	sort_array(arr); // O(nlong)

	for(i=0;i<N;i++)
		printf("%d ", arr[i]);


	free(arr);

	return 0;
}
