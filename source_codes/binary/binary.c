#include "../_file_open/file_open.h"
#include <stdio.h>
#include <stdlib.h>


int binary_search(int start, int end, int *arr, int key) {

    if(start > end)
        return -1;

    int mid = (start+end)/2;
	printf("%d %d\n", mid, arr[mid]);

    if(key == arr[mid])
        return mid;
    else if(key > arr[mid])
        return binary_search(mid+1, end, arr, key);
    else //key < arr[mid]
        return binary_search(start, mid-1, arr, key);

}

int main(int argc, char* argv[]) {
	
	int N;
	int *arr = fill_array(argv[1], &N);
	
    int key = 5632;

    int pos = binary_search(0, N-1, arr, key);
    printf("%d", pos);
	
	
	free(arr);
	
    return 0;
}
