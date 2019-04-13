#include <stdio.h>
#include <stdlib.h>

     #include <time.h>
     
     clock_t start, end;
     double cpu_time_used;


#define N 9


void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort(int *arr, int start, int end)
{
    if(start == end)
      return;
    
    int left = start, right = end;
    int mid = (start+end)/2;
    int pivot = arr[mid];
    
    while(left < right)
    {
      while(arr[left]<pivot)
        left++;
      while(arr[right]>pivot)
        right--;
      
      if(left<right)
        swap(&arr[left],&arr[right]);
    }
  
  
    //left array
    if(right > start)
      quicksort(arr, start, right);
  
    //right array
    if(left < end)
      quicksort(arr, left, end);
  
    //int arr[N] = {1,2,4,5,5,6,7,8,9};

  
}


int main() {
    
    int arr[N] = {9,8,7,6,5,5,3,2,1};
    /*int arr[N] = {1,8,7,6,5,5,3,2,9};
    int arr[N] = {1,2,7,6,5,5,3,8,9};
    int arr[N] = {1,2,3,6,5,5,7,8,9};
    int arr[N] = {1,2,3,5,5,6,7,8,9};*/
    //int arr[N] = {1,2,4,5,5,6,7,8,9};
    //int arr[N]={44,66,88,100,99,77,55,33,22};
  
  
  
       
    start = clock();


    quicksort(arr,0,N-1);
    
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%f\n", cpu_time_used);
  
    
    int k;
   
    for(k=0;k<N;k++) {
      printf("%d ", arr[k]);
    }
    
    printf("\n");
  
    return 0;
}
