#include <stdio.h>
#include <stdlib.h>

#define N 9


void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void merge(int *arr, int start, int end)
{
  int mid = (start+end)/2;
  int size = end - start + 1;
  int *temp_array = (int*)malloc(sizeof(int)*size);
  
  int i=0, a=start, b=mid+1; // a index of the first part - b index of the second
  while(a<=mid && b<=end)
  {
    if(arr[a]<arr[b])
    {
      temp_array[i] = arr[a];
      a++;
    }
    else
    {
      temp_array[i] = arr[b];
      b++;
    }
    i++;
  }
  
  while(a<=mid)
  {
    temp_array[i] = arr[a];
    a++;
    i++;
  }
  
  while(b<=end)
  {
    temp_array[i] = arr[b];
    b++;
    i++;
  }
  
  //temp_array taksinomimenos
  // 0 1 2 3 4  5
  // 3 4 7 9 10 11
  
  // arr
  // start+0 start+1 2  3 4  5
  // 7        9        10 3
  
  for(i=0;i<size;i++)
    arr[start+i] = temp_array[i];
  
  
  //free(temp_array);
  
  return;

}


void merge_sort(int *arr,int start,int end)
{
  if(end==start)
    return;
  
  int mid = (start+end)/2;
  
  merge_sort(arr, start, mid);
  merge_sort(arr, mid+1, end);
  
  merge(arr, start, end);
  
}







int main()
{
    //diavasma arxeiou

    
    //int arr[N] = {100, 58 ,30 ,99,5,6,7,50,10};
    int arr[N] = {9,8,7,6,5,4,3,2,1};
   // int arr[N] = {1,2,3,4,5,6,7,8,9};


    int k;


    merge_sort(arr,0,N-1);
        
      
      
    for(k=0;k<N;k++) {
      printf("%d ", arr[k]);
    }
    
    printf("\n");


    return 0;
}
