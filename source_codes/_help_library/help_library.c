#include "help_library.h"


void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int* fill_array(char* filename, int *size) {
	
	FILE* fp;
    fp = fopen(filename, "r");

	int N;
    fscanf(fp, "%d", &N);
	
	int *arr = (int*)malloc(N*sizeof(int));

	int index;
    for (index = 0; index < N; index++)
        fscanf(fp, "%d", &arr[index]);
	
	fclose(fp);
	
	*size = N;
	
	return arr;
}

void is_sorted(int *arr, int N) {
	
	int i, flag = 0;
	for(i=1;i<N;i++)
		if(arr[i-1] > arr[i]) {
			flag = 1;
			break;
		}
	
	if(flag == 1)
		printf("\n---\nNOT SORTED\n---\n");
	else
		printf("\n---\nSORTED\n---\n");
}
