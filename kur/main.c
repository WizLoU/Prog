#include <stdio.h>
#include "Kur_Sort.h"



int main()
{
    int x;
    scanf("%d", &x);
    insertionsort(x);
    heapsort(x);
    return 0; 
}