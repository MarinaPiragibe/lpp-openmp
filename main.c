#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
// #include "./scripts/bitonic.h"
#include "./scripts/bubble.h"
#include "./scripts/suporte.h"

int main()
{
    int tamanho = 10;
    int *arr = gerarArrayAleatorio(tamanho);

    printf("Array original: ");
    printArray(arr, tamanho);

    omp_set_num_threads(4);

    bubble_sort_parallel(arr, tamanho);
    sort_verify(arr, tamanho);

    printf("\nArray ordenado: ");
    printArray(arr, tamanho);

    free(arr);
    return 0;
}