#include "vector.h"
#include "sort.h"

void bubble_sort( int vector[], int vector_length ) {
	int iterator = 0;
	int aux = 0;
	int new_length = 0;
	int l_vector_length = vector_length;

	do {
		new_length = 0;

		for ( iterator = 1; iterator < l_vector_length; iterator++ ) {
			if ( vector[iterator - 1] > vector[iterator] ) {
				aux = vector[iterator - 1];
				vector[iterator - 1] = vector[iterator];
				vector[iterator] = aux;

				new_length = iterator;
			}
		}

		l_vector_length = new_length;
	} while ( l_vector_length != 0 );
}