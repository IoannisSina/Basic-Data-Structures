# Data-Structures-Project

## How to run (binary_search)
gcc binary.c ../_file_open/file_open.c<br/>
./a.out ../_data/sorted_data.txt

## How to create new file
You need to add:
1. #include "../_file_open/file_open.h"

2. int main(int argc, char* argv[]) {
    int N;
    int *arr = fill_array(argv[1], &N);
    ...

3. ...
    free(arr);
    return 0;
  }
