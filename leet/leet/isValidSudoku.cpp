#include <iostream>

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
	int row = 0, col = 0;
	int frow[9][9] = { 0 };
	int fcol[9][9] = { 0 };
	int fblock[9][9] = { 0 };
	int tmp = 0;

	for (row = 0; row < boardRowSize; row++)
	{
		for (col = 0; col < boardColSize; col++)
		{
			if (board[row][col] == '.')
			{
				continue;
			}

			tmp = board[row][col] - '0';

			if (fcol[row][tmp - 1] || frow[tmp - 1][col] || fblock[row / 3 * 3 + col / 3][tmp - 1])
			{
				return false;
			}
			else
			{
				fcol[row][tmp - 1] = frow[tmp - 1][col] = fblock[row / 3 * 3 + col / 3][tmp - 1] = tmp;
			}
		}
	}

	return true;
}