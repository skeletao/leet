#include <iostream>

int removeDuplicates(int* nums, int numsSize) {

	int i = 0, j = 0;

	for (i = 1, j = 0; i < numsSize; i++)
	{
		if (nums[i - 1] != nums[i])
		{
			nums[++j] = nums[i];
		}
	}
	return (numsSize > 0 ? j + 1 : j);
}