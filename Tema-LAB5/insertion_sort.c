//
// Created by Alexandru Becheru on 14/03/2018.
//
#include "basic.h"


void insertion_sort(int *vector, int vector_length){
    int iterator1 = 1;
    int iterator2;

    while ( iterator1 < vector_length ) {
        iterator2 = iterator1;
        while ( iterator2 > 0 && vector[iterator2 -1] > vector[iterator2] ) {
            interchange_values( &vector[iterator2], &vector[iterator2 - 1] );
            iterator2--;
        }
        iterator1++;
    }
}
