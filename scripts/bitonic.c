#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void bitonicCompare(int *arr, int i, int j, int dir)
{
    if (dir == (arr[i] > arr[j]))
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void bitonicMerge(int *arr, int low, int count, int dir)
{
    if (count > 1)
    {
        int k = count / 2;
        
        #pragma omp parallel for
        for (int i = low; i < low + k; i++)
        {
            bitonicCompare(arr, i, i + k, dir);
        }
        
        #pragma omp parallel sections
        {
            #pragma omp section
            bitonicMerge(arr, low, k, dir);
            
            #pragma omp section
            bitonicMerge(arr, low + k, k, dir);
        }
    }
}

void bitonicSort(int *arr, int low, int count, int dir)
{
    if (count > 1)
    {
        int k = count / 2;
        
        #pragma omp parallel sections
        {
            #pragma omp section
            bitonicSort(arr, low, k, 1);
            
            #pragma omp section
            bitonicSort(arr, low + k, k, 0);
        }
        
        bitonicMerge(arr, low, count, dir);
    }
}

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