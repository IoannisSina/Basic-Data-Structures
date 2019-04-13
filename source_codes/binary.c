#include <stdio.h>
#include <stdlib.h>

#define N 9


int binary_search(int start, int end, int *arr, int key) {

    if(start>end)
        return -1;

    int mid = (start+end)/2;

    if(arr[mid] == key)
        return mid;
    else if(arr[mid] < key)
        return binary_search(mid+1, end, arr, key);
    else
        return binary_search(start, mid-1, arr, key);

}

int main()
{
    //diavasma arxeiou

    //int arr[N] = {100, 58 ,30 ,99,5,6,7,50,10};
    //int arr[N] = {9,8,7,6,5,4,3,2,1};
    int arr[N] = {1,2,3,4,5,6,7,8,9};

    int key = 20;

    int pos = binary_search(0, N-1, arr, key);
    printf("%d", pos);

    return 0;
}
