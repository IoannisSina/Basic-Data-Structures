#include <stdio.h>
#include <stdlib.h>

#define N 7

int interpolation(int* arr, float key) {
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



int main()
{
    int arr[N] = {1, 2, 3, 4, 5, 9, 10};
    float key = 5;

    int result = interpolation(arr, key);
    printf("%d", result);


    return 0;
}
