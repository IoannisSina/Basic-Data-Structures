#include <stdio.h>
#include <stdlib.h>

#define N 9


void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}


int main()
{
    //diavasma arxeiou

    //int arr[N] = {100, 58 ,3 ,99,5,6,7,50,10};
    int arr[N] = {9,8,7,6,5,4,3,2,1};
    //int arr[N] = {1,2,3,4,5,6,7,8,9};

    int i, j, k;


    for(i=1; i<N; i++) {
        int to_insert = arr[i];
        for(j=i-1; j>=0 && to_insert<arr[j]; j--) {
            arr[j+1] = arr[j];  // right shift
        }
        arr[j+1] = to_insert;

        for(k=0;k<N;k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");

    }

    return 0;
}

