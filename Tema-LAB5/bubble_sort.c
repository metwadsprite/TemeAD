#include "basic.h"

void bubble_sort( int *vector, int vector_length ) {
    int l_vector_length = vector_length;
    int new_length;
    int iterator;

    do {
        new_length = 0;

        for ( iterator = 1; iterator < vector_length; iterator++ ) {
            if ( vector[iterator - 1] > vector[iterator] ) {
                interchange_values( &vector[iterator - 1], &vector[iterator] );
                new_length = iterator;
            }
        }
        l_vector_length = new_length;
    } while ( l_vector_length != 0 );
}