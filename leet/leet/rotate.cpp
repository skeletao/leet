#include <iostream>

void rotate(int** matrix, int matrixRowSize, int *matrixColSizes) {
	int row = matrixRowSize;
	int i = 0, j = 0, num = 0, tmp = 0;
	*matrixColSizes = matrixRowSize;

	for (i = 0; i < row/2; i++)
	{
		num = row - 2 * i - 1;
		for (j = 0; j < num; j++)
		{
			tmp = *((int*)matrix + (row - i - 1 - j)*row + i);
			*((int*)matrix + (row - i - 1 - j)*row + i) = *((int*)matrix + (row - i)*row - 1 - i - j);
			*((int*)matrix + (row - i)*row - 1 - i - j) = *((int*)matrix + (i + j + 1)*row - i - 1);
			*((int*)matrix + (i + j + 1)*row - i - 1) = *((int*)matrix + i * row + i + j);
			*((int*)matrix + i * row + i + j) = tmp;


			//tmp = matrix[row - i - 1 - j][i];
			//matrix[row - i - 1 - j][i] = matrix[row - i - 1][row - 1 - i - j];
			//matrix[row - i - 1][row - 1 - i - j] = matrix[i + j][row - i - 1];
			//matrix[i + j][row - i - 1] = matrix[i][i + j];
			//matrix[i][i + j] = tmp;
		}
	}
}