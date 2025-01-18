#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void bitonicCompare(int *arr, int i, int j, int ascending)
{
    if ((arr[i] > arr[j]) == ascending)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void bitonicMerge(int *arr, int low, int count, int ascending)
{
    if (count > 1)
    {
        int mid = count / 2;
#pragma omp parallel for
        for (int i = low; i < low + mid; i++)
        {
            bitonicCompare(arr, i, i + mid, ascending);
        }
        bitonicMerge(arr, low, mid, ascending);
        bitonicMerge(arr, low + mid, mid, ascending);
    }
}

void bitonicSort(int *arr, int low, int count, int ascending)
{
    if (count > 1)
    {
        int mid = count / 2;
        bitonicSort(arr, low, mid, 1);       // Sort in ascending order
        bitonicSort(arr, low + mid, mid, 0); // Sort in descending order
        bitonicMerge(arr, low, count, ascending);
    }
}

int main()
{
    int arr[] = {12, 4, 7, 3, 9, 6, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    omp_set_num_threads(4); // Define o número de threads para 4

#pragma omp parallel
#pragma omp single
    bitonicSort(arr, 0, n, 1); // Sort entire array in ascending order

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
