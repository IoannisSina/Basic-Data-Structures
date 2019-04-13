#include <stdio.h>
#include <stdlib.h>

#define N 9


int main()
{
    //diavasma arxeiou

    //int arr[N] = {100, 58 ,30 ,99,5,6,7,50,10};
    int arr[N] = {9,8,7,6,5,4,3,2,1};
    //int arr[N] = {1,2,3,4,5,6,7,8,9};


    int i;
    int key = 5;

    for(i=0;i<N;i++)
        if(key == arr[i])
            printf("%d", i);


    return 0;
}

