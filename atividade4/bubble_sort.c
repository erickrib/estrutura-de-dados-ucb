#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

void swap(int *n1, int *n2) {
    int n_temporario = *n1;
    *n1 = *n2;
    *n2 = n_temporario;
}

void bubble_sort(int arr[], int n) {
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - 1 - j; i++)
        {

            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
            }
        }
    }
}
