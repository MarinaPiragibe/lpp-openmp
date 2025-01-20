#include "bitonic.h"
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

double medeTempoBitonic(int *arr, int tamanho) {
    double inicio = omp_get_wtime();
    bitonicSort(arr, 0, tamanho, 1);
    double fim = omp_get_wtime();

    return fim - inicio;
}