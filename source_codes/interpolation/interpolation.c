#include "../_file_open/file_open.h"
#include <stdio.h>
#include <stdlib.h>

int interpolation(int* arr, int N, float key) {
    int low = 0, high = N-1, next;

    while(arr[high] >= key && key > arr[low]) {
        next = low + ((key-arr[low])/(arr[high]-arr[low]))*(high-low);
        printf("next: %d\n", next);
        printf("low: %d\n", low);
        printf("high: %d\n", high);
        printf("real: %f\n", ((key-arr[low])/(arr[high]-arr[low]))*(high-low));
        printf("\n");

        if(key > arr[next])
            low = next+1;
        else if (key < arr[next])
            high = next-1;
        else
            low = next;
    }

    if (key == arr[low])
        return low;


    return -1;

}



int main(int argc, char* argv[]) {
	
	int N;
	int *arr = fill_array(argv[1], &N);

    float key = 2015;

    int result = interpolation(arr, N, key);
    printf("%d", result);


    return 0;
}
