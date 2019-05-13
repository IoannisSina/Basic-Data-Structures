#include <stdio.h>
#include <stdlib.h>


int file_to_array(char* file_name, int* arr){

    FILE *myFile;
    myFile = fopen(file_name, "r");

	unsigned int size;
	fscanf(myFile, "%d", &size);
    arr = (int*)malloc(size*sizeof(int));

	int i;
    for (i = 0; i < size; i++)
        fscanf(myFile, "%d", &arr[i]);

	return size;
}


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

int main()
{
    //diavasma arxeiou

    //int arr[N] = {100, 58 ,30 ,99,5,6,7,50,10};
    //int arr[N] = {9,8,7,6,5,4,3,2,1};
    //int arr[N] = {1,2,3,4,5,6,7,8,9};
	int* arr;
	int N = file_to_array("data.txt", arr);

    int key = 2;

    int pos = binary_search(0, N-1, arr, key);
    printf("%d", pos);

    return 0;
}
