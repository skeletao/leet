/**
* Note: The returned array must be malloced, assume caller calls free().
*/
#include <iostream>

int* spiralOrder(int (*matrix)[10], int matrixRowSize, int matrixColSize) {
	int up = 0, right = matrixColSize - 1, dn = matrixRowSize - 1, left = 0, i = 0, t = 0;
	int *res = (int *)malloc(sizeof(int) * matrixRowSize * matrixColSize);

	while (true)
	{
		for (i = left; i <= right; i++)
		{
			res[t++] = matrix[up][i];
		}
		if (++up > dn)
		{
			break;
		}

		for (i = up; i <= dn; i++)
		{
			res[t++] = matrix[i][right];
		}
		if (--right < left)
		{
			break;
		}

		for (i = right; i >= left; i--)
		{
			res[t++] = matrix[dn][i];
		}
		if (--dn < up)
		{
			break;
		}

		for (i = dn; i >= up; i--)
		{
			res[t++] = matrix[i][left];
		}
		if (++left > right)
		{
			break;
		}
	}
	return res;
}


int* spiralOrder2(int** matrix, int matrixRowSize, int matrixColSize) {
	int i = 0, t = 0, m = matrixRowSize, n = matrixColSize;
	int *res = (int *)malloc(sizeof(int) * matrixRowSize * matrixColSize);

	if (m == 1)
	{
		for (i = 0; i < n; i++)
		{
			res[i] = matrix[0][i];
		}
		return res;
	}

	if (n == 1)
	{
		for (i = 0; i < m; i++)
		{
			res[i] = matrix[i][0];
		}
		return res;
	}

	while (m > 0 && n > 0)
	{
		if (m == 1 && n == 1)
		{
			res[matrixRowSize*matrixColSize - 1] = matrix[matrixRowSize / 2][matrixColSize / 2];
			return res;
		}

		if (m == 1)
		{
			for (i = 0; i < n; i++)
			{
				res[t++] = matrix[matrixRowSize / 2][(matrixColSize - n) / 2 + i];
			}
			return res;
		}

		if (n == 1)
		{
			for (i = 0; i < m; i++)
			{
				res[t++] = matrix[(matrixRowSize - m) / 2 + i][matrixColSize / 2];
			}
			return res;
		}

		for (i = 0; i <n - 1; i++)
		{
			res[t++] = matrix[(matrixRowSize - m) / 2][(matrixColSize - n) / 2 + i];
		}

		for (i = 0; i < m - 1; i++)
		{
			res[t++] = matrix[(matrixRowSize - m) / 2 + i][matrixColSize - 1 - (matrixColSize - n) / 2];
		}

		for (i = 0; i < n - 1; i++)
		{
			res[t++] = matrix[matrixRowSize - 1 - (matrixRowSize - m) / 2][matrixColSize - 1 - (matrixColSize - n) / 2 - i];
		}

		for (i = 0; i < m - 1; i++)
		{
			res[t++] = matrix[matrixRowSize - 1 - (matrixRowSize - m) / 2 - i][(matrixColSize - n) / 2];
		}

		m -= 2;
		n -= 2;
	}

	return res;
}