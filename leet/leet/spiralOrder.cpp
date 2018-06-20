/**
* Note: The returned array must be malloced, assume caller calls free().
*/
#include <iostream>

int* spiralOrder(int (*matrix)[3], int matrixRowSize, int matrixColSize) {
	int i = 0, j = 0, t = 0, m = matrixRowSize, n = matrixColSize;
	int *res = (int *)malloc(sizeof(int) * matrixRowSize * matrixColSize);
	while (m > 0 || n > 0)
	{
		for (i = 0; i <n -1; i++)
		{
			res[t] = matrix[(matrixRowSize - m) / 2 * matrixColSize + (matrixColSize - n) / 2 + i];
			res[m + n - 2 + t++] = matrix[(matrixRowSize - (matrixRowSize - m) / 2) * matrixColSize - 1 - (matrixColSize - n) / 2 - i];
		}

		for (j = 0; j < m - 1; j++)
		{
			res[t] = matrix[((matrixRowSize - m) / 2 + 1 + i) * matrixColSize - 1 - (matrixColSize - n) / 2];
			res[m + n - 2 + t++] = matrix[(matrixRowSize - (matrixRowSize - m) / 2 - 1 - i) * matrixColSize + (matrixColSize - n) / 2];
		}

		m -= 2;
		n -= 2;
	}

	return res;
}