#include <stdio.h>
#include "vector.h"

int read_number() {
	int number = 0;

	printf( "Enter a number: " );
	scanf( "%d", &number );

	return number;
}

void read_vector( int vector[], int vector_length ) {
	int iterator = 0;
	
	printf( "Elements separated by spaces:\n" );

	for ( iterator = 0; iterator < vector_length; iterator++ ) {
		scanf( "%d", &vector[iterator] );
	}
	printf( "\n" );
}

void write_vector( int vector[], int vector_length ) {
	int iterator = 0;

	for ( iterator = 0; iterator < vector_length; iterator++ ) {
		printf( "%d ", vector[iterator] );
	}
	printf( "\n" );
}