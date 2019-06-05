#include "../_help_library/help_library.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int interpolation(int *arr, int N, int key) {
    int low = 0, high = N - 1, next;

    while (arr[high] >= key && key > arr[low]) {
        next = low + ((key - arr[low]) / (arr[high] - arr[low])) * (high - low);

        if (key > arr[next])
            low = next + 1;
        else if (key < arr[next])
            high = next - 1;
        else
            low = next;
    }

    if (key == arr[low])
        return low;

    return -1;
}

int main(int argc, char *argv[]) {
	
	if(argc != 2) { // no file selected
		printf("\n---\nplease give file location!!!\n---\n");
		return -1;
	}

    int N;
    int * arr = fill_array(argv[1], &N);

    int key;
    printf("Give key: ");
    scanf("%d", &key);

    clock_t begin = clock();
    int result = interpolation(arr, N, key);
    clock_t end = clock();

    if (pos == -1)
        printf("Key NOT found");
    else
        printf("Key FOUND! Position: %d", pos);
	
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n%lf\n\n", time_spent);

    free(arr);

    return 0;
}