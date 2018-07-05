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

 // dfs with stack

struct cordinate
{
	int x;
	int y;
};

struct cordinate ss[INT8_MAX];
int f[INT8_MAX][INT8_MAX] = { {0} };

int move[][2] = { {1, 0}, {0 ,1}, {-1, 0}, {0, -1} };

bool dfs2(char (*board)[3], int boardRowSize, int boardColSize, int i, int j, char* word)
{
	int t = 0, m = 0, lastMove = 0;
	struct cordinate now = { i , j };
	struct cordinate tmp = now;

	if (board[i][j] != word[t])
	{
		return false;
	}
	f[i][j] = 1;

	ss[t++] = now;
	while (t > 0)
	{
		if (word[t] == '\0')
		{
			return true;
		}

		now = ss[t-1];

		for (m = f[now.x][now.y]-1; m < 4; m++)
		{
			tmp.x = now.x + move[m][0];
			tmp.y = now.y + move[m][1];
			if (tmp.x < boardRowSize && tmp.x >= 0 && tmp.y < boardColSize && tmp.y >= 0 && board[tmp.x][tmp.y] == word[t] && f[tmp.x][tmp.y] == 0)
			{
				f[now.x][now.y] = m + 2;
				f[tmp.x][tmp.y] = 1;
				ss[t++] = tmp;
				break;
			}
		}

		if (m == 4)
		{
			f[now.x][now.y] = 0;
			t--;
		}
	}
	return false;
}

// dfs with recursion
bool dfs1(char **board, int boardRowSize, int boardColSize, int i, int j, char* word, int dir)
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
			flag = dfs1(board, boardRowSize, boardColSize, i + 1, j, word + 1, 1);
		}

		if (!flag && j + 1 < boardColSize && dir != 4)
		{
			flag = dfs1(board, boardRowSize, boardColSize, i, j + 1, word + 1, 2);
		}

		if (!flag && i > 0 && dir != 1)
		{
			flag = dfs1(board, boardRowSize, boardColSize, i - 1, j, word + 1, 3);
		}

		if (!flag && j > 0 && dir != 2)
		{
			flag = dfs1(board, boardRowSize, boardColSize, i, j - 1, word + 1, 4);
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
			if (dfs2((char (*)[3])board, boardRowSize, boardColSize, i, j, word))
			{
				return true;
			}
		}
	}
	return false;
}