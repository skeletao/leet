/*
 *board =
 *[
 *	['A', 'B', 'C', 'E'],
 *	['S', 'F', 'C', 'S'],
 *	['A', 'D', 'E', 'E']
 *]
 *
 *Given word = "ABCCED", return true.
 *Given word = "SEE", return true.
 *Given word = "ABCB", return false.
 */

#include <iostream>

bool dfs(char **board, int boardRowSize, int boardColSize, int i, int j, char* word, int dir)
{
	bool flag = false;

	if (board[i][j] == word[0])
	{
		if (word[1] == '\0')
		{
			return true;
		}

		char tmp = board[i][j];
		board[i][j] = '\0';

		if (i + 1 < boardRowSize && dir != 3)
		{
			flag = dfs(board, boardRowSize, boardColSize, i + 1, j, word + 1, 1);
		}

		if (!flag && j + 1 < boardColSize && dir != 4)
		{
			flag = dfs(board, boardRowSize, boardColSize, i, j + 1, word + 1, 2);
		}

		if (!flag && i > 0 && dir != 1)
		{
			flag = dfs(board, boardRowSize, boardColSize, i - 1, j, word + 1, 3);
		}

		if (!flag && j > 0 && dir != 2)
		{
			flag = dfs(board, boardRowSize, boardColSize, i, j - 1, word + 1, 4);
		}

		board[i][j] = tmp;
	}

	return flag;
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
	int i = 0, j = 0;

	for (i = 0; i < boardRowSize; i++)
	{
		for (j = 0; j < boardColSize; j++)
		{
			if (dfs(board, boardRowSize, boardColSize, i, j, word, 0))
			{
				return true;
			}
		}
	}
	return false;
}