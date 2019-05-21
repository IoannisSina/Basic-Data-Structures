#include "file_open.h"


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
