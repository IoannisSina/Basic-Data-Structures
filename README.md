# Data-Structures-Project

## How to run source codes (example with binary_search)

### Linux
```
gcc binary_search.c ../_help_library/help_library.c
./a.out ../../datasets/part1/sorted/medium_data.txt
```
### Windows
```
gcc binary_search.c ../_help_library/help_library.c
a.exe ../../datasets/part1/sorted/medium_data.txt
```

## How to run dataset generator (example with binary_search)

### Linux & Windows
```
javac main.java
java main
```

## How to link new source code file with file_open library
You need to add:
1. #include "../_file_open/file_open.h"

2. int main(int argc, char* argv[]) {
	int N;
    int *arr = fill_array(argv[1], &N);
    
	/* your code */
	
    free(arr);
    return 0;
  }
