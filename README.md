# Data Structures - Project :chart_with_downwards_trend:

This is our university project for Data Structures course. CEID - 2017/18

All codes were implemented in C and run successfully. The measurements were made for a big number of datasets and experimental results were compared with theory.

## Datasets:
**Part 1**: script was implemented in Java to export uniform data distributions

**Part 2**: a file was implemented containing many students with help from github.com/benkeen/generatedata

## Help Library:
Among the source codes there is also a library (help_library.c, help_library.h) that we implemented and contains three functions. The purpose is to make the codes legible by not declaring the same functions in each file. These functions are:
- void swap (int \*, int \*): swap two elements of an array
- int \* fill_array (char \*, int \*): arguments are a filename and the number of elements. Returns a pointer to the new table. (only for part1)
- void is_sorted (int \*, int): checks if an array is sorted




## Part 1 - Sorting Algorithms

We implemented:
- O(n<sup>2</sup>) | Bubble Sort - Insertion Sort - Selection Sort
- O(nlogn) | Merge Sort - Quick Sort
- O(nlogn) | Heap Sort

![sorting charts](https://user-images.githubusercontent.com/36283973/123538029-4f651900-d73b-11eb-8b89-a1a9777c94db.png)


## Part 2 - Searching Algorithms

We implemented:
- Linear Search O(n)
- Binary Search O(logn)
- Interpolation Search O(loglogn)
- Binary Interpolation Search (&& Improved)



### How was the average case time measured?
In contrast to sorting algorithms, for the searching algorithms time is as a function of the size of the dataset and the key given by the user. Therefore it is not possible with just a random key selection to find mean case complexity.

The most "fair" way to measure the time for the average case is to find the amortized complexity of the algorithm. That is, to measure the total time required to do a search taking as a search key each element of the dataset and in the end divide by the number of elements. The linear and binary search algorithms are not affected by distribution unlike interpolation search. Due to the aforementioned fact, the dataset has a uniform distribution (interpolation search has maximum performance). According to the measurements linear search can not be represented on the same graph.


![searching charts](https://user-images.githubusercontent.com/36283973/123538527-019de000-d73e-11eb-9b18-d7e2952dc6f5.png)



## How to run source codes (example with binary_search) 🏃

### Compile - Part A
```
gcc binary.c ../_help_library/help_library.c
```

### Compile - Part B
```
gcc menu.c bstA.c bstB.c hashing.c
```

## Run
```
./a.out dataset.txt
```

## How to run dataset generator (example with binary_search)
```
javac main.java
java main
```

## Team
Apostolos Kontarinis<br>
John Sinas<br>
Agisilaos Kounelis

