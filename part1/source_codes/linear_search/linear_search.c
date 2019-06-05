#include "../_help_library/help_library.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[]) {
	
    if(argc != 2) { // no file selected
		printf("\n---\nplease give file location!!!\n---\n");
		return -1;
	}

    int N;
    int *arr = fill_array(argv[1], &N);

    int i, key, flag = 0;
    printf("Give key: ");
    scanf("%d", &key);

    clock_t begin = clock();

    for (i = 0; i < N; i++)
        if (key == arr[i]) {
            printf("Key found! Position: %d\n", i);
            flag = 1;
        }

    if (flag == 0)
        printf("Key NOT found!\n", i);

    clock_t end = clock();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n%lf\n\n", time_spent);

    free(arr);

    return 0;
}
