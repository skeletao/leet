/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *columnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/

#include <iostream>

// Bit Manipulation
int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize)
{
	int i = 0, j = 0;
	int **res;

	if (numsSize == 0)
	{
		return NULL;
	}

	*returnSize = (1 << numsSize);
	*columnSizes = (int *)malloc(*returnSize * sizeof(int));
	res = (int **)malloc(*returnSize * sizeof(int *));

	for (i = 0; i < *returnSize; i++)
	{
		(*columnSizes)[i] = 0;
		res[i] = (int *)malloc(numsSize * sizeof(int));
		for (j = 0; j < numsSize; j++)
		{
			if ((i >> j) & 1)
			{
				res[i][(*columnSizes)[i]++] = nums[j];
			}
		}
	}
	return res;
}

//BT
int** subsets2(int* nums, int numsSize, int** columnSizes, int* returnSize) 
{
	int i = 0, j = 0;
	int **res;
	if (numsSize == 0)
	{
		res = (int **)malloc(sizeof(int *));
		*columnSizes = (int *)malloc(sizeof(int));
		res[0] = NULL;
		(*columnSizes)[0] = 0;
		*returnSize = 1;
		return res;
	}

	res = subsets2(nums + 1, numsSize - 1, columnSizes, returnSize);

	res = (int **)realloc(res, (*returnSize * 2) * sizeof(int *));
	*columnSizes = (int *)realloc(*columnSizes, (*returnSize * 2) * sizeof(int));

	for (i = 0; i < *returnSize; i++)
	{
		res[*returnSize + i] = (int *)malloc(((*columnSizes)[i] + 1) * sizeof(int));

		for (j = 0; j < (*columnSizes)[i]; j++)
		{
			res[*returnSize + i][j] = res[i][j];
		}
		res[*returnSize + i][(*columnSizes)[i]] = nums[0];
		(*columnSizes)[*returnSize + i] = (*columnSizes)[i] + 1;
	}
	*returnSize *= 2;
	return res;
}