#ifndef BITONIC_H
#define BITONIC_H

void bitonicCompare(int *arr, int i, int j, int dir);

void bitonicMerge(int *arr, int low, int count, int dir);

void bitonicSort(int *arr, int low, int count, int dir);

double medeTempoBitonic(int *arr, int tamanho);

#endif