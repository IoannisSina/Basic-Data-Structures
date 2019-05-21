#include "../_file_open/file_open.h"

#include <stdio.h>

#include <stdlib.h>


void swap(int * x, int * y) {
    int temp = * x;
    * x = * y;
    * y = temp;
}

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

    //temp_array taksinomimenos
    // 0 1 2 3 4  5
    // 3 4 7 9 10 11

    // arr
    // start+0 start+1 2  3 4  5
    // 7        9        10 3

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
    int * arr = fill_array(argv[1], & N);

    int k;

    merge_sort(arr, 0, N - 1);

    for (k = 0; k < N; k++)
        printf("%d ", arr[k]);

    printf("\n");

	free(arr);
	
    return 0;
}