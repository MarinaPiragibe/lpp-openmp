#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include "bubblev2.h"

void bubbleSortParallel(int *arr, int n) {
    int i, j;
    int first;
    
    // Flag para verificar se houve trocas
    int trocou;
    
    // Loop principal do bubble sort
    for (i = 0; i < n-1; i++) {
        trocou = 0;
        
        // Fase par
        #pragma omp parallel for shared(arr, n) private(j) reduction(|:trocou)
        for (j = 0; j < n-1; j += 2) {
            if (arr[j] > arr[j+1]) {
                // Troca os elementos
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                trocou = 1;
            }
        }
        
        // Fase ímpar
        #pragma omp parallel for shared(arr, n) private(j) reduction(|:trocou)
        for (j = 1; j < n-1; j += 2) {
            if (arr[j] > arr[j+1]) {
                // Troca os elementos
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                trocou = 1;
            }
        }
        
        // Se não houve trocas, o array está ordenado
        if (!trocou) {
            break;
        }
    }
}

double medeTempoBubblev2(int *arr, int tamanho) {
    double inicio = omp_get_wtime();
    bubbleSortParallel(arr, tamanho);
    double fim = omp_get_wtime();

    return fim - inicio;
}