#include <iostream>

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
	int i = 0, left = 0, right = numsSize - 1;
	*returnSize = 2;
	int *res = (int *)malloc(sizeof(int) * 2);
	res[0] = -1;
	res[1] = -1;
	int *tmp1, *tmp2;
	while (left <= right)
	{
		i = (left + right) / 2;
		if (target < nums[i])
		{
			right = i-1;
		} 
		else if (target > nums[i])
		{
			left = i+1;
		}
		else
		{
			res[0] = i;
			res[1] = i;
   			tmp1 = searchRange(nums + left, i - left, target, returnSize);
			tmp2 = searchRange(nums + i + 1, right - i, target, returnSize);
			if (tmp1[0] != -1 && (tmp1[0]+left) < res[0])
			{
				res[0] = tmp1[0]+left;
			}
			if (tmp2[1] != -1 && (tmp2[1]+i+1) > res[1])
			{
				res[1] = tmp2[1]+i+1;
			}
			break;
		}
	}
	return res;
}