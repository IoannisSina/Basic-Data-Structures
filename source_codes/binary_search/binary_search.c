#include "../_help_library/help_library.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int binary_search(int start, int end, int *arr, int key) {

    if(start > end)
        return -1;

    int mid = (start+end)/2;

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
	
	int key;
	printf("Give key: ");
	scanf("%d", &key);

	clock_t begin = clock();
    int pos = binary_search(0, N-1, arr, key);
	clock_t end = clock();
	
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n%lf\n\n", time_spent);


	if(pos == -1)
		printf("Key NOT found");
	else
		printf("Key FOUND! Position: %d", pos);
	
	free(arr);
	
    return 0;
}
