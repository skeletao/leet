#include <iostream>
/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *columnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/

char strCmp(char *s1, char *s2)
{
	int ff[26] = { 0 };

	while (*s1)
	{
		ff[*s1-'a'] = 1;
		s1++;
	}

	while (*s2)
	{
		if (!ff[*s2-'a'])
		{
			return false;
		}
		s2++;
	}
	return true;
}

char*** groupAnagrams(char (*strs)[4], int strsSize, int** columnSizes, int* returnSize) {
	int i = 0, j = 0, t = 0;
	char ***res = NULL;

	int *f = (int *)malloc(strsSize);
	char *s1, *s2;

	*returnSize = 0;

	for (i = 0; i < strsSize; i++)
	{
		f[i] = 0;
	}

	for (i = 0; i < strsSize; i++)
	{
		if (f[i])
		{
			continue;
		}
		s1 = strs[i];
		f[i] = 1;
		*returnSize += 1;
		t = 1;

		if (*returnSize == 1)
		{
			*columnSizes = (int *)malloc(sizeof(int));
			res = (char ***)malloc(sizeof(char **));
		}
		else
		{
			*columnSizes = (int *)realloc(*columnSizes, sizeof(int)*(*returnSize));
			res = (char ***)realloc(res, sizeof(char **)*(*returnSize));

		}

		res[*returnSize - 1] = (char **)malloc(sizeof(char *));
		res[*returnSize - 1][0] = s1;

		for (j = i + 1; j < strsSize; j++)
		{
			if (f[j])
			{
				continue;
			}
			s2 = strs[j];

			if (strCmp(s1, s2))
			{
				f[j] = 1;
				t++;
				res[*returnSize - 1] = (char **)realloc(res[*returnSize - 1], sizeof(char *)*t);
				res[*returnSize - 1][t - 1] = s2;
			}
		}
		columnSizes[0][*returnSize - 1] = t;
	}
	return res;
}

