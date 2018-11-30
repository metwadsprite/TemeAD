#include "io.h"
#include "mat.h"

void mat_add(int mat1[100][100], int mat2[100][100], int len)
{
	int iterator1;
	int iterator2;
	int mat_s[100][100];

	for (iterator1 = 0; iterator1 < len; iterator1++) {
		for (iterator2 = 0; iterator2 < len; iterator2++) {
			mat_s[iterator1][iterator2] = mat1[iterator1][iterator2] + mat2[iterator1][iterator2];
		}
	}

	mat_write(mat_s, len);
}