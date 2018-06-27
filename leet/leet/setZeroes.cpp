#include <iostream>

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
	int i = 0, j = 0, col0 = 1;
	for (i = 0; i < matrixRowSize; i++)
	{
		if (matrix[i][0] == 0)
		{
			col0 = 0;
		}
		for (j = 1; j < matrixColSize; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	for (i = matrixRowSize - 1; i >= 0; i--)
	{
		for (j = matrixColSize - 1; j >= 1; j--)
		{
			if (matrix[i][0] == 0 || matrix[0][j] == 0)
			{
				matrix[i][j] = 0;
			}
		}
		if (col0 == 0)
		{
			matrix[i][0] = 0;
		}

	}
}


void setZeroes2(int** matrix, int matrixRowSize, int matrixColSize) {
	int i = 0, j = 0;
	bool row = false, col = false;
	for (int i = 0; i < matrixRowSize; i++) 
	{
		for (int j = 0; j < matrixColSize; j++) 
		{
			if (matrix[i][j] == 0)
			{
				if (i == 0) row = true;
				if (j == 0) col = true;
				matrix[0][j] = matrix[i][0] = 0;
			}
		}
	}
	for (int i = 1; i <matrixRowSize; i++)
	{
		for (int j = 1; j < matrixColSize; j++)
		{
			if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
		}
	}
	if (col) 
	{
		for (int i = 0; i < matrixRowSize; i++) matrix[i][0] = 0;
	}
	if (row)
	{
		for (int j = 0; j < matrixColSize; j++) matrix[0][j] = 0;
	}
}