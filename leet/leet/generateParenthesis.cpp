#include <iostream>
using namespace std;
/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/

char **generate(char *s, int left, int right, int n, int *returnSize, char **list)
{
	int ii = 0;
	if (!left && !right)
	{
		char *tmp = (char *)malloc(n * 2 + 1);
		while (ii <= 2 * n)
		{
			*(tmp + ii) = *(s + ii);
			ii++;
		}
		if (!list)
		{
			list = (char **)malloc(sizeof(char *));
		}
		else
		{

			list = (char **)realloc(list, (*returnSize + 1) * sizeof(char *));
		}
		*(list + *returnSize) = tmp;
		(*returnSize)++;
	}

	if (left > 0)
	{
		*(s + 2 * n - left - right) = '(';
		list = generate(s, left - 1, right, n, returnSize, list);
	}

	if (left < right)
	{
		*(s + 2 * n - left - right) = ')';
		list = generate(s, left, right - 1, n, returnSize, list);
	}
	return list;
}
char** generateParenthesis(int n, int* returnSize) {
	char *s = (char *)malloc(2 * n + 1);
	s[2 * n] = '\0';
	char **list;
	list = generate(s, n, n, n, returnSize, NULL);
	free(s);
	return list;
}