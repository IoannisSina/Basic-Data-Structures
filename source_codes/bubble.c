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

    int arr[N] = {1, 2 ,3 ,4,5,6,7,8,10};

    int i, j, k;

    int did_swap = 0;

    for(i=1; i<N; i++) {
        for(j=0; j<N-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                did_swap = 1;   //swap happened
            }
        }

        for(k=0;k<N;k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");

        if(did_swap == 0)
            break;

        did_swap = 0;

    }

    return 0;
}

