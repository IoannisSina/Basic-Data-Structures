#include "../_help_library/help_library.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int binary_interpolation_improved(int *arr, int left, int right, int key) {

	if (key < arr[left] || key > arr[right])
		return -1;

    if (arr[right] == key)
        return right;

    if (arr[left] == key)
        return left;

    int size = right - left + 1;
	int mid = left + (((float)size / abs(arr[right] - arr[left])) * abs(key - arr[left]));

    // when the array has less than 4 elements sqrt(size) returns 1. So we can just do linear search
    if (size <= 3) {
        int i;
        for (i = left; i <= right; i++)
            if (arr[i] == key)
                return i;

        return -1;
    }
	
	// big steps ------------------------

    if (arr[mid] == key)
        return mid;
    else if (key > arr[mid]) {
        int i = 1;
        int next_mid = (int)(mid + i * sqrt(size));
        while (next_mid < right && key > arr[next_mid]) { // right steps
            i *= 2;
            next_mid = (int)(mid + i * sqrt(size));
        }

        if (next_mid > right) {
            left = mid + (i/2) * sqrt(size) + 1;
        } else {
            right = next_mid;
            left = mid + (i/2) * sqrt(size);
        }

    } else if (key < arr[mid]) {
        int i = 1;
        int next_mid = (int)(mid - i * sqrt(size));
        while (next_mid > left && key < arr[next_mid]) { // left steps
            i *= 2;
            next_mid = (int)(mid - i * sqrt(size));
        }

        if (next_mid < left) {
            right = mid - (i/2) * sqrt(size) - 1;
        } else {
            right = mid - (i/2) * sqrt(size);
            left = mid - i * sqrt(size);
        }

    }
	
	// binary search
	
    if (key < arr[left] || key > arr[right])
        return -1;

    if (arr[right] == key)
        return right;

    if (arr[left] == key)
        return left;

    size = right - left + 1;


	// when the array has less than 4 elements sqrt(size) returns 1. So we can just do linear search
    if (size <= 3) {
        int i;
        for (i = left; i <= right; i++)
            if (arr[i] == key)
                return i;

        return -1;
    }
	
	while (right - left > sqrt(size) && left <= right) {
        int m = (left + right) / 2;
		
        if (arr[m] == key)
            return m;
        if (arr[m] < key)
            left = m + 1;
        else
            right = m - 1;
	}
	
	if(left > right)
		return -1;

    return binary_interpolation_improved(arr, left, right, key);
}



int main(int argc, char *argv[]) {
	
	if(argc != 2) { // no file selected
		printf("\n---\nplease give file location!!!\n---\n");
		return -1;
	}

	int N;
	int *arr = fill_array(argv[1], &N);

    int key;
    printf("Give key:\n");
    scanf("%d", &key);
	
	clock_t begin = clock();
    int res = binary_interpolation_improved(arr, 0, N - 1, key);
	clock_t end = clock();
	
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n%lf\n\n", time_spent);

	if(res == -1)
		printf("Key NOT found!\n");
    else
		printf("Key FOUND in pos: %d\n", res);

	free(arr);
    return 0;
}
