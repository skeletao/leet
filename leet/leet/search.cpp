#include <iostream>

int search(int* nums, int numsSize, int target) {
	int i = 0, res = -1;
	int left = 0, right = numsSize - 1;

	if (numsSize == 0)
	{
		return -1;
	}

	if (nums[left] <= nums[right])
	{
		while (left <= right)
		{
			i = (left + right) / 2;
			if (target < nums[i])
			{
				right = i - 1;
			}
			else if (target > nums[i])
			{
				left = i + 1;
			}
			else
			{
				return i;
			}
		}
		return -1;
	}
	else
	{

		if ((res = search(nums, numsSize / 2, target)) > -1)
		{
			return res;
		}

		if ((res = search(nums + numsSize / 2, numsSize - numsSize / 2, target)) > -1)
		{
			return res + numsSize / 2;
		}

		return -1;
	}
}