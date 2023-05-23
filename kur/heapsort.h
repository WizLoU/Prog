#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <malloc.h>

double wtime();
void printArray(int arr[], int x);
int getrand(int min, int max);
void filling_array(int *a, int min, int max, int x);
void siftDown(int *arr, int x, int bottom);
void Sort(int *arr, int array_size);
int heapsort(int x);
void  fillingArray(int arr[], int n);