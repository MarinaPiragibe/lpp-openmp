#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <omp.h>

void generate_random_list(int *list, int size) {
    for (int i = 0; i < size; i++) {
        list[i] = rand() % 1000000; // valores aleatórios entre 0 e 999999
    }
}

void bubble_sort(int *list, int size, int num_threads) {
    for (int i = 0; i < size - 1; i++) { // Percorre N vezs a lista
        for (int j = 0; j < size - 1 - i; j++) { // Troca os elementos vizinhos da lista
            if (list[j] > list[j + 1]) {
                // Troca os elementos
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

// NÃO ESTÁ ORDEANDO NADA
void bubble_sort_parallel(int *list, int size, int num_threads) {
    #pragma omp parallel for num_threads(num_threads) 
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (list[j] > list[j + 1]) {
                // Troca os elementos
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

// Verifica se lista está ordenada
int sort_verify(int *list, int size){
    for (int i=0; i<size-1; i++){
        if(list[i]>list[i+1]) return 0;
    }
    return 1;
}

double measure_time(void (*sort_func)(int *, int, int), int *list, int size, int num_threads) {
    double start_time = omp_get_wtime();
    sort_func(list, size, num_threads);
    double end_time = omp_get_wtime();
    return end_time - start_time;
}

int main() {
    srand(time(NULL));

    // Tamanhos das listas (50k, 100k, 500k) 
    int sizes[] = {50000, 100000};  // 500K DEMORANDO MTO
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);  // Calculando o número de tamanhos dinamicamente
    
    // Número de threads a serem testados (2 e 4 threads)
    int num_threads[] = {2, 4};  
    int num_thread_configs = sizeof(num_threads) / sizeof(num_threads[0]);  // Número de configurações de threads

    for (int i = 0; i < num_sizes; i++) {  // Loop para percorrer os tamanhos da lista de sizes
        for (int j = 0; j < num_thread_configs; j++) {  // Loop para percorrer os diferentes números de threads
            // Alocando a lista do tamanho adequado
            int *list = (int *)malloc(sizes[i] * sizeof(int));  
            generate_random_list(list, sizes[i]);

            // Teste com a versão sequencial
            int *list_copy = (int *)malloc(sizes[i] * sizeof(int));
            memcpy(list_copy, list, sizes[i] * sizeof(int));
            double seq_time = measure_time(bubble_sort, list_copy, sizes[i], 1);  // 1 thread para versão sequencial
            int bool_seq = sort_verify(list_copy, sizes[i]);
            free(list_copy);

            // Teste com a versão paralela
            list_copy = (int *)malloc(sizes[i] * sizeof(int));
            memcpy(list_copy, list, sizes[i] * sizeof(int));
            double par_time = measure_time(bubble_sort_parallel, list_copy, sizes[i], num_threads[j]);
            int bool_par = sort_verify(list_copy, sizes[i]);
            free(list_copy);

            // Calcular Speedup e Eficiência
            double speedup = seq_time / par_time;
            double efficiency = speedup / num_threads[j];

            // Exibir os resultados
            printf("Tamanho da lista: %d, Threads: %d\n", sizes[i], num_threads[j]);
            printf("Sort Lista Sequencial (T/F = 1/0): %d, Sort Lista Paralela (T/F): %d\n", bool_seq, bool_par);
            printf("Tempo Sequencial: %f, Tempo Paralelo: %f\n", seq_time, par_time);
            printf("Speedup: %f, Eficiência: %f\n\n", speedup, efficiency);

            free(list);
        }
    }

    return 0;
}
