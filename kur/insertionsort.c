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

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

void insertion_sort(int arr[], int n)
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

int main()
{
    int min = 0, max = 100000;
    int *a;
    int x;
    scanf("%d", &x);
    double v = wtime();
    a = (int*)malloc(x * sizeof(int));
    // Заполнение массива случайными числами
    for (int i = 0; i < x; i++)
        a[i] = getrand(min, max);
    // Вывод элементов массива до сортировки
    for (int i = 0; i < x; i++)
        printf("%d ", a[i]);
    printf("\n");
    int n = sizeof(a) / sizeof(a[0]);
    insertion_sort(a, n);
    // Вывод элементов массива после сортировки
    for (int i = 0; i < x; i++)
        printf("%d ", a[i]);
    double m = wtime();
    printf("%lf\n", m - v);
    return 0;
}