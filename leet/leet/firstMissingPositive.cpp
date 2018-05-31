#include <iostream>

int firstMissingPositive(int* nums, int numsSize) {
	int i = 0, pick = 0;

	for (i = 0; i < numsSize; i++)
	{
		pick = nums[i];
		if ((pick > 0) && (pick <= numsSize) && (nums[pick - 1] != pick))
		{
			nums[i] = nums[pick - 1];
			nums[pick - 1] = pick;
			i--;
		}
	}

	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] != i + 1)
		{
			return (i + 1);
		}
	}
	return (i + 1);
}