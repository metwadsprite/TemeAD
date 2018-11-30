#include <stdio.h>
#include "io.h"
#include "mat.h"

void mat_read()
{
	int len;
	int iterator1;
	int iterator2;
	int mat1[100][100];
	int mat2[100][100];

	FILE *matIn;

	matIn = fopen("mat_in.txt", "r");
	fscanf(matIn, "%d", &len);

	for (iterator1 = 0; iterator1 < len; iterator1++) {
		for (iterator2 = 0; iterator2 < len; iterator2++) {
			fscanf(matIn, "%d", &mat1[iterator1][iterator2]);
		}
	}

	for (iterator1 = 0; iterator1 < len; iterator1++) {
		for (iterator2 = 0; iterator2 < len; iterator2++) {
			fscanf(matIn, "%d", &mat2[iterator1][iterator2]);
		}
	}

	fclose(matIn);

	mat_add(mat1, mat2, len);
}

void mat_write(int mat[100][100], int len)
{
	int iterator1;
	int iterator2;
	
	FILE *matOut;

	matOut = fopen("mat_out.txt", "w");

	for (iterator1 = 0; iterator1 < len; iterator1++) {
		for (iterator2 = 0; iterator2 < len; iterator2++) {
			fprintf(matOut, "%d ", mat[iterator1][iterator2]);
		}
		fprintf(matOut, "\n");
	}

	fclose(matOut);
}