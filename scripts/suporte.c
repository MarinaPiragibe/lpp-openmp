#include "suporte.h"
#include <stdlib.h>
#include <stdio.h>

int *gerarArrayAleatorio(int tamanho)
{
    int *arr = (int *)malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++)
    {
        arr[i] = rand() % 1000000;
    }

    return arr;
}

void printArray(int arr[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sort_verify(int *list, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (list[i] > list[i + 1])
        {
            printf("\n----------- Array DESordenado :( -----------\n\n");
            return;
        }
    }
    printf("\n----------- Array Ordenado! :) -----------\n\n");
}