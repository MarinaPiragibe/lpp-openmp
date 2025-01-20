#include "suporte.h"
#include <stdlib.h>

int* gerarArrayAleatorio(int tamanho) {
    int* arr = (int*)malloc(tamanho * sizeof(int));
    
    for(int i = 0; i < tamanho; i++) {
        arr[i] = rand() % 1000000;
    }
    
    return arr;
}