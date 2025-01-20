#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "./scripts/bitonic.h"
#include "./scripts/suporte.h"

int main() {
    int tamanho = 8;
    int* arr = gerarArrayAleatorio(tamanho);
    
    printf("Array original: ");
    printArray(arr, tamanho);
    
    omp_set_num_threads(4);
    
    bitonicSort(arr, 0, tamanho, 1);
    
    printf("\nArray ordenado: ");
    printArray(arr, tamanho);
    
    free(arr);
    return 0;
}