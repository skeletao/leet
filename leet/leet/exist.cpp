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

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
	int i = 0, j = 0;
	int *f = (int *)calloc(boardRowSize * boardColSize,  sizeof(int));

}

bool dfs