#include <iostream>

/**
* Return an array of arrays of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int** permute(int* nums, int numsSize, int* returnSize) {
	int i = 0, j = 0, tmpNum = 0, tmpSize = 1;
	int **res, **tmpRes;

	for (i = 1; i <= numsSize; i++)
	{
		tmpSize *= i;
	}

	res = (int **)malloc(sizeof(int *) * tmpSize);

	if (numsSize == 1)
	{
		*res = (int *)malloc(sizeof(int));
		**res = *nums;
		*returnSize = 1;
		return res;
	}
	
	for (i = 0; i < numsSize; i++)
	{
		tmpNum  = nums[i];
		nums[i] = nums[0];
		nums[0] = tmpNum;

		tmpRes = permute(nums + 1, numsSize - 1, returnSize);
		for (j = 0; j < *returnSize; j++)
		{
			res[i*(*returnSize)+j] = (int *)realloc(tmpRes[j], sizeof(int)*numsSize);
			res[i*(*returnSize)+j][numsSize - 1] = nums[0];
		}

		tmpNum = nums[i];
		nums[i] = nums[0];
		nums[0] = tmpNum;
	}
	*returnSize = tmpSize;
	return res;
}