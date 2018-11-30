//
// Created by Alexandru Becheru on 13/03/2018.
//
#include "sort.h"
#include "basic.h"
#include "vectors.h"

void selection_sort( int *vector, int vector_length ){
    int iterator_1;
    int iterator_2;
    int min_elem_index;

    for ( iterator_1 = 0; iterator_1 < vector_length - 1; iterator_1++ ) {
        min_elem_index = iterator_1;

        for ( iterator_2 = iterator_1 + 1; iterator_2 < vector_length; iterator_2++ ) {
            if ( vector[iterator_2] < vector[min_elem_index] ) {
                min_elem_index = iterator_2;
            }
        }
        if ( min_elem_index != iterator_1 ) {
            interchange_values( &vector[iterator_1], &vector[min_elem_index] );
        }
    }
}
