#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <malloc.h>

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

void printArray(int arr[], int x) {
    for (int i = 0; i < x; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}


// int filling_array(int *a, int min, int max, int x)
// {
//     // Заполнение массива случайными числами
//     for (int i = 0; i < x; i++)
//         a[i] = getrand( min, max);
//     return a;
// }


// Функция для заполнения массива порядковыми числами, идущими по убыванию
void  fillingArray(int arr[], int x) {
    for (int i = 0; i < x; i++) {
        arr[i] = x - i;
    }
}

// // Функция для заполнения массива порядковыми числами, идущими по возрастанию
// void  fillingArray(int arr[], int x) {
//     for (int i = 0; i < x; i++) {
//         arr[i] = i + 1;
//     }
// }




void Sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int insertionsort(int x)
{
    int min = 0, max = 100000;

    double v = wtime();
    int *a = (int*)malloc(x * sizeof(int));
    
    //заполнение массива 
    // filling_array(a, min, max, x);

    fillingArray(a, x);
    
    // Вывод элементов массива до сортировки
    // printArray(a, x);

    int n = sizeof(a) / sizeof(a[0]);
    
    Sort(a, n);

    // Вывод элементов массива после сортировки
    // printArray(a, x);
    
    double m = wtime();
    printf("%lf\n", m - v);
    return 0;
}