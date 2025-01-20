#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "./scripts/bitonic.h"
#include "./scripts/suporte.h"

int main() {
    int tamanho = 524288;
    int* arr = gerarArrayAleatorio(tamanho);
    
    printf("Array original: ");
    for (int i = 0; i < tamanho; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    omp_set_num_threads(4);
    
    bitonicSort(arr, 0, tamanho, 1);
    
    printf("\nArray ordenado: ");
    for (int i = 0; i < tamanho; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    free(arr);  // lembrar de liberar a memoria alocada
    return 0;
}