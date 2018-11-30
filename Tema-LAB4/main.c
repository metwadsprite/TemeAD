#include "vector.h"
#include "sort.h"

int main() {
	//reading the vector
	g_vector_length = read_number();
	read_vector( g_vector, g_vector_length );

	//sorting the vector;
	bubble_sort( g_vector, g_vector_length );

	//writing the vector
	write_vector( g_vector, g_vector_length );

	return 0;
}