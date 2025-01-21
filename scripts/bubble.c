#include <stdio.h>
#include <omp.h>
#include "bubble.h"

void bubble_sort_parallel(int *arr, int n)
{
    // Laço externo para o número de passos do Bubble Sort
    for (int step = 0; step < n - 1; step++)
    {
        int swap_flag = 0; // Flag para verificar se houve troca

        // Comparações em índices pares
        if (step % 2 == 0)
        {
            #pragma omp parallel for reduction(| : swap_flag)
            for (int i = 0; i < n - 1; i += 2)
            {
                if (arr[i] > arr[i + 1])
                {
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    swap_flag = 1; // Marca que houve troca
                }
            }
        }

        // Sincronização das threads após a fase de comparações pares
        #pragma omp barrier

        // Comparações em índices ímpares
        if (step % 2 == 1)
        {
            #pragma omp parallel for reduction(| : swap_flag)
            for (int i = 1; i < n - 1; i += 2)
            {
                if (arr[i] > arr[i + 1])
                {
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    swap_flag = 1; // Marca que houve troca
                }
            }
        }

        // Sincronização das threads após a fase de comparações ímpares
        #pragma omp barrier

        // Se não houve troca em nenhuma fase, o array já está ordenado
        if (!swap_flag)
        {
            break; // Finaliza o algoritmo, pois o array está ordenado
        }
    }
}

double medeTempoBubble(int *arr, int tamanho) {
    double inicio = omp_get_wtime();
    bubble_sort_parallel(arr, tamanho);
    double fim = omp_get_wtime();

    return fim - inicio;
}