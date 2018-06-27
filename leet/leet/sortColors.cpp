#include <iostream>

void sortColors(int* nums, int numsSize) {
	int i = 0, j = 0, last0 = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] == 0)
		{
			for (j = i; j > last0; j--)
			{
				nums[j] = nums[j - 1];
			}
			nums[last0] = 0;
			last0++;
		}
		else if (nums[i] == 1)
		{
			for (j = i; j > last0; j--)
			{
				nums[j] = nums[j - 1];
			}
			nums[last0] = 1;
		}
	}
}