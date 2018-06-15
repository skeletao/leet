#include <iostream>
/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *columnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/


int calStrHash(char *str)
{
	int i = 0, j = 0, n = strlen(str);
	int ff[26] = { 0 };
	int hash = 0;
	
	for (i = 0; i < n; i++)
	{
		ff[*(str + i) - 'a']++;
	}

	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < ff[i]; j++)
		{
			hash = (hash << 7) + (hash << 1) + i + 'a';
		}
	}
	return hash;
}


char*** groupAnagrams(char (*strs)[4], int strsSize, int** columnSizes, int* returnSize) {
	int i = 0, j = 0;
	char ***res = 0;
	*columnSizes = 0;
	*returnSize = 0;

	char*** result;
	result = (char***)malloc(sizeof(char**));
	result[0] = (char**)malloc(sizeof(char*));
	result[0][0] = strs[0];

	*columnSizes = (int*)malloc(sizeof(int));
	(*columnSizes)[0] = 1;

	*returnSize = 0;

	int *f = (int *)malloc(strsSize * sizeof(int));
	int *hashList = (int *)malloc(strsSize * sizeof(int));

	for (i = 0; i < strsSize; i++)
	{
		f[i] = 0;
		hashList[i] = calStrHash(strs[i]);
	}

	for (i = 0; i < strsSize; i++)
	{
		if (f[i])
		{
			continue;
		}
		f[i] = 1;

		if (i > 0)
		{
			*returnSize += 1;
			result = (char ***)realloc(result, (*returnSize + 1) * sizeof(char**));
			result[*returnSize] = (char**)malloc(sizeof(char*));
			*columnSizes = (int *)realloc(*columnSizes, (*returnSize + 1) * sizeof(int));
			(*columnSizes)[*returnSize] = 0;

			(*columnSizes)[*returnSize] += 1;
			result[*returnSize] = (char **)realloc(result[*returnSize], ((*columnSizes)[*returnSize] + 1) * sizeof(char*));
			result[*returnSize][(*columnSizes)[*returnSize] - 1] = strs[i];
		}

		for (j = i + 1; j < strsSize; j++)
		{
			if (f[j])
			{
				continue;
			}

			if (hashList[i] == hashList[j])
			{
				f[j] = 1;
				(*columnSizes)[*returnSize] += 1;
				result[*returnSize] = (char **)realloc(result[*returnSize], ((*columnSizes)[*returnSize] + 1) * sizeof(char*));
				result[*returnSize][(*columnSizes)[*returnSize] - 1] = strs[j];
			}
		}
	}

	*returnSize += 1;
	return result;
}
