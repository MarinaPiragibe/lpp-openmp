#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>
#include "./scripts/bitonic.h"
#include "./scripts/bubble.h"
#include "./scripts/suporte.h"

int main()
{

    double inicio, fim;

    // geração dos arrays

    //int tam_p = 16, tam_m = 64, tam_g = 256;
    int tam_p = 65536, tam_m = 131072, tam_g = 524288;

    int* arr_p = gerarArrayAleatorio(tam_p);
    int* arr_m = gerarArrayAleatorio(tam_m);
    int* arr_g = gerarArrayAleatorio(tam_g);

    // execuções bitonic
    printf("\n------------------------------------------\n");
    printf("\n-------===  Execuções Bitonic  ===-------\n");
    printf("\n------------------------------------------\n");

    // -- 1 thread

    omp_set_num_threads(1);
    printf("\n\nUtilizando 1 thread\n\n");

    // array pequeno
    int* arr_p_1 = (int *)malloc(tam_p * sizeof(int));
    memcpy(arr_p_1, arr_p, tam_p * sizeof(int));

    printf("\nOrdenando array pequeno...\n");

    double tempo_bit_p_1 = medeTempoBitonic(arr_p_1, tam_p);
    printf("Tempo bitonic pequeno 1 thread: %f\n", tempo_bit_p_1);

    sort_verify(arr_p_1, tam_p);

    free(arr_p_1);

    // array médio
    int* arr_m_1 = (int *)malloc(tam_m * sizeof(int));
    memcpy(arr_m_1, arr_m, tam_m * sizeof(int));

    printf("\nOrdenando array médio...\n");

    double tempo_bit_m_1 = medeTempoBitonic(arr_m_1, tam_m);
    printf("Tempo bitonic médio 1 thread: %f\n", tempo_bit_m_1);

    sort_verify(arr_m_1, tam_m);

    free(arr_m_1);

    // array grande
    int* arr_g_1 = (int *)malloc(tam_g * sizeof(int));
    memcpy(arr_g_1, arr_g, tam_g * sizeof(int));

    printf("\nOrdenando array grande...\n");

    double tempo_bit_g_1 = medeTempoBitonic(arr_g_1, tam_g);
    printf("Tempo bitonic grande 1 thread: %f\n", tempo_bit_g_1);

    sort_verify(arr_g_1, tam_g);

    free(arr_g_1);


    // -- 2 threads

    omp_set_num_threads(2);
    printf("\n\nUtilizando 2 threads\n\n");

    // array pequeno
    int* arr_p_2 = (int *)malloc(tam_p * sizeof(int));
    memcpy(arr_p_2, arr_p, tam_p * sizeof(int));

    printf("\nOrdenando array pequeno...\n");

    double tempo_bit_p_2 = medeTempoBitonic(arr_p_2, tam_p);
    printf("Tempo bitonic pequeno 2 threads: %f\n", tempo_bit_p_2);

    sort_verify(arr_p_2, tam_p);

    free(arr_p_2);

    // array médio
    int* arr_m_2 = (int *)malloc(tam_m * sizeof(int));
    memcpy(arr_m_2, arr_m, tam_m * sizeof(int));

    printf("\nOrdenando array médio...\n");

    double tempo_bit_m_2 = medeTempoBitonic(arr_m_2, tam_m);
    printf("Tempo bitonic médio 2 threads: %f\n", tempo_bit_m_2);

    sort_verify(arr_m_2, tam_m);

    free(arr_m_2);

    // array grande

    int* arr_g_2 = (int *)malloc(tam_g * sizeof(int));
    memcpy(arr_g_2, arr_g, tam_g * sizeof(int));

    printf("\nOrdenando array grande...\n");

    double tempo_bit_g_2 = medeTempoBitonic(arr_g_2, tam_g);
    printf("Tempo bitonic grande 2 threads: %f\n", tempo_bit_g_2);

    sort_verify(arr_g_2, tam_g);

    free(arr_g_2);


    // -- 4 threads

    omp_set_num_threads(4);
    printf("\n\nUtilizando 4 threads\n\n");

    // array pequeno
    int* arr_p_4 = (int *)malloc(tam_p * sizeof(int));
    memcpy(arr_p_4, arr_p, tam_p * sizeof(int));

    printf("\nOrdenando array pequeno...\n");

    double tempo_bit_p_4 = medeTempoBitonic(arr_p_4, tam_p);
    printf("Tempo bitonic pequeno 4 threads: %f\n", tempo_bit_p_4);

    sort_verify(arr_p_4, tam_p);

    free(arr_p_4);

    // array médio
    int* arr_m_4 = (int *)malloc(tam_m * sizeof(int));
    memcpy(arr_m_4, arr_m, tam_m * sizeof(int));

    printf("\nOrdenando array médio...\n");

    double tempo_bit_m_4 = medeTempoBitonic(arr_m_4, tam_m);
    printf("Tempo bitonic médio 4 threads: %f\n", tempo_bit_m_4);

    sort_verify(arr_m_4, tam_m);

    free(arr_m_4);

    // array grande
    int* arr_g_4 = (int *)malloc(tam_g * sizeof(int));
    memcpy(arr_g_4, arr_g, tam_g * sizeof(int));

    printf("\nOrdenando array grande...\n");

    double tempo_bit_g_4 = medeTempoBitonic(arr_g_4, tam_g);
    printf("Tempo bitonic grande 4 threads: %f\n", tempo_bit_g_4);
    
    sort_verify(arr_g_4, tam_g);

    free(arr_g_4);

    // execuções bubble
    printf("\n------------------------------------------\n");
    printf("\n -------===  Execuções Bubble  ===-------\n");
    printf("\n------------------------------------------\n");

    // -- 1 thread

    omp_set_num_threads(1);
    printf("\n\nUtilizando 1 thread\n\n");

    // array pequeno
    int* arrb_p_1 = (int *)malloc(tam_p * sizeof(int));
    memcpy(arrb_p_1, arr_p, tam_p * sizeof(int));

    printf("\nOrdenando array pequeno...\n");

    double tempo_bub_p_1 = medeTempoBubble(arrb_p_1, tam_p);
    printf("Tempo bubble pequeno 1 thread: %f\n", tempo_bub_p_1);

    sort_verify(arrb_p_1, tam_p);

    free(arrb_p_1);

    // array médio
    int* arrb_m_1 = (int *)malloc(tam_m * sizeof(int));
    memcpy(arrb_m_1, arr_m, tam_m * sizeof(int));

    printf("\nOrdenando array médio...\n");

    double tempo_bub_m_1 = medeTempoBubble(arrb_m_1, tam_m);
    printf("Tempo bubble médio 1 thread: %f\n", tempo_bub_m_1);

    sort_verify(arrb_m_1, tam_m);

    free(arrb_m_1);

    // array grande
    int* arrb_g_1 = (int *)malloc(tam_g * sizeof(int));
    memcpy(arrb_g_1, arr_g, tam_g * sizeof(int));

    printf("\nOrdenando array grande...\n");

    double tempo_bub_g_1 = medeTempoBubble(arrb_g_1, tam_g);
    printf("Tempo bubble grande 1 thread: %f\n", tempo_bub_g_1);

    sort_verify(arrb_g_1, tam_g);

    free(arrb_g_1);


    // -- 2 threads

    omp_set_num_threads(2);
    printf("\n\nUtilizando 2 threads\n\n");

    // array pequeno
    int* arrb_p_2 = (int *)malloc(tam_p * sizeof(int));
    memcpy(arrb_p_2, arr_p, tam_p * sizeof(int));

    printf("\nOrdenando array pequeno...\n");

    double tempo_bub_p_2 = medeTempoBubble(arrb_p_2, tam_p);
    printf("Tempo bubble pequeno 2 threads: %f\n", tempo_bub_p_2);

    sort_verify(arrb_p_2, tam_p);

    free(arrb_p_2);

    // array médio
    int* arrb_m_2 = (int *)malloc(tam_m * sizeof(int));
    memcpy(arrb_m_2, arr_m, tam_m * sizeof(int));

    printf("\nOrdenando array médio...\n");

    double tempo_bub_m_2 = medeTempoBubble(arrb_m_2, tam_m);
    printf("Tempo bubble médio 2 threads: %f\n", tempo_bub_m_2);

    sort_verify(arrb_m_2, tam_m);

    free(arrb_m_2);

    // array grande

    int* arrb_g_2 = (int *)malloc(tam_g * sizeof(int));
    memcpy(arrb_g_2, arr_g, tam_g * sizeof(int));

    printf("\nOrdenando array grande...\n");

    double tempo_bub_g_2 = medeTempoBubble(arrb_g_2, tam_g);
    printf("Tempo bubble grande 2 threads: %f\n", tempo_bub_g_2);

    sort_verify(arrb_g_2, tam_g);

    free(arrb_g_2);

    // -- 4 threads

    omp_set_num_threads(4);
    printf("\n\nUtilizando 4 threads\n\n");

    // array pequeno
    int* arrb_p_4 = (int *)malloc(tam_p * sizeof(int));
    memcpy(arrb_p_4, arr_p, tam_p * sizeof(int));

    printf("\nOrdenando array pequeno...\n");

    double tempo_bub_p_4 = medeTempoBubble(arrb_p_4, tam_p);
    printf("Tempo bubble pequeno 4 threads: %f\n", tempo_bub_p_4);

    sort_verify(arrb_p_4, tam_p);

    free(arrb_p_4);

    // array médio
    int* arrb_m_4 = (int *)malloc(tam_m * sizeof(int));
    memcpy(arrb_m_4, arr_m, tam_m * sizeof(int));

    printf("\nOrdenando array médio...\n");

    double tempo_bub_m_4 = medeTempoBubble(arrb_m_4, tam_m);
    printf("Tempo bubble médio 4 threads: %f\n", tempo_bub_m_4);

    sort_verify(arrb_m_4, tam_m);

    free(arrb_m_4);

    // array grande
    int* arrb_g_4 = (int *)malloc(tam_g * sizeof(int));
    memcpy(arrb_g_4, arr_g, tam_g * sizeof(int));

    printf("\nOrdenando array grande...\n");

    double tempo_bub_g_4 = medeTempoBubble(arrb_g_4, tam_g);
    printf("Tempo bubble grande 4 threads: %f\n", tempo_bub_g_4);
    
    sort_verify(arrb_g_4, tam_g);

    free(arrb_g_4);

    // liberação de memória
    free(arr_p);
    free(arr_m);
    free(arr_g);

    return 0;
}