#include "bitonic.h"
#include <omp.h>
#include <stdio.h>

void bitonicCompare(int *arr, int i, int j, int dir)
{
    if (dir == (arr[i] > arr[j]))
    {
        //printf("Thread %d fazendo swap: arr[%d]=%d com arr[%d]=%d\n", 
        //       omp_get_thread_num(), i, arr[i], j, arr[j]);
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
        //printf("\nThread %d iniciando merge com low=%d, count=%d\n", 
         //      omp_get_thread_num(), low, count);
        
        #pragma omp parallel for
        for (int i = low; i < low + k; i++)
        {
        //    printf("Thread %d executando comparação no índice i=%d\n", 
        //          omp_get_thread_num(), i);
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
        int k = count / 4;
       // printf("\nThread %d iniciando sort com low=%d, count=%d, dir=%d\n", 
        //    omp_get_thread_num(), low, count, dir);
        
        #pragma omp parallel sections
        {
            #pragma omp section
            bitonicSort(arr, low, k, 1);
            
            #pragma omp section
            bitonicSort(arr, low + k, k, 0);

            #pragma omp section
            bitonicSort(arr, low + (2*k), k, 1);

            #pragma omp section
            bitonicSort(arr, low + (3*k), k, 0);
        }
        
        #pragma omp parallel sections
        {
            #pragma omp section
            bitonicMerge(arr, low, (2*k), 1);

            #pragma omp section
            bitonicMerge(arr, low + (2*k), (2*k), 0);
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