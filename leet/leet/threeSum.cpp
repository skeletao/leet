#include <iostream>
#include <cstdio>
using namespace std;


/**
* Return an array of arrays of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/

int cmpfunc(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize)
{
	int front, back;
	int i = 0;
	int **result = 0;
	int s = 0;

	qsort(nums, numsSize, sizeof(int), cmpfunc);

	while (i < numsSize)
	{
		int target = -nums[i];
		if (target < 0)
		{
			break;
		}

		front = i + 1;
		back = numsSize - 1;

		while (front < back)
		{
			int sum = nums[front] + nums[back];
			if (sum < target)
			{
				front++;
			}
			else if (sum > target)
			{
				back--;
			}
			else
			{
				s++;
				result = (int **)realloc(result, sizeof(int *)*s);
				int *temp = (int *)malloc(sizeof(int) * 3);
				temp[0] = nums[i];
				temp[1] = nums[front];
				temp[2] = nums[back];
				result[s-1] = temp;

				while (front < back && nums[front] == temp[1])
				{
					front++;
				}
				while (front < back && nums[back] == temp[2])
				{
					back--;
				}
			}
		}
		while ((i + 1) < numsSize && nums[i] == nums[i + 1])
		{
			i++;
		}
		i++;
	}

	*returnSize = s;
	return result;

}