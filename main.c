#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "./scripts/bitonic.h"

int main()
{
    int arr[] = {12, 4, 7, 3, 9, 6, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array original: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    omp_set_num_threads(4);
    
    bitonicSort(arr, 0, n, 1);
    
    printf("\nArray ordenado: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}