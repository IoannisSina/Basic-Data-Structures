#include <stdio.h>
#include <stdlib.h>

#define N 9


void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int get_min_pos(int start, int *arr) {

    int position = start;
    int min = arr[start];

    int i;
    for(i=start+1;i<N;i++)
        if(min > arr[i]) {
            min = arr[i];
            position = i;
        }


    return position;

}


int main()
{
    //diavasma arxeiou

    //int arr[N] = {100, 58 ,30 ,99,5,6,7,50,10};
    int arr[N] = {9,8,7,6,5,4,3,2,1};
    //int arr[N] = {1,2,3,4,5,6,7,8,9};



    int i, j, k;


    for(i=0; i<N-1; i++) {  // N-1 because the last element will be the max
        int min_pos = get_min_pos(i, arr);    // find the min for the unsorted array

        swap(&arr[i], &arr[min_pos]);

        for(k=0;k<N;k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");

    }

    return 0;
}

