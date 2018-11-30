//
// Created by Alexandru Becheru on 14/03/2018.
//
#include "vectors.h"
#include "basic.h"

int find_pivot_position(int *vector, int left, int right){
    int pivot = vector[right];
    int index = left - 1;
    int iterator;

    for ( iterator = left; iterator < right; iterator++ ) {
        if ( vector[iterator] < pivot ) {
            index++;
            interchange_values( &vector[index], &vector[iterator] );
        }
    }

    interchange_values( &vector[index + 1], &vector[right] );

    return (index + 1);
}

void quick_sort(int *vector, int left, int right){
    int pivot_position = 0;

    if (left < right){
        pivot_position = find_pivot_position(vector, left, right);
        quick_sort(vector, left, pivot_position - 1);
        quick_sort(vector, pivot_position + 1, right);
    }
}
