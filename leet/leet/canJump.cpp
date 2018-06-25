#include <iostream>

bool canJump(int* nums, int numsSize) {
	int farthest = 0;
	for (int i = 0; i < numsSize; i++) {
		if (i > farthest)
		{
			return false;
		}
		farthest = (i + nums[i] > farthest) ? i + nums[i] : farthest;
	}
	return true;
}


// DP
bool canJump2(int* nums, int numsSize) {
	int i = 0, j = 0;
	int *dp = (int *)malloc(sizeof(int)*numsSize);

	for (i = 0; i < numsSize; i++)
	{
		dp[i] = -1;
	}
	dp[numsSize - 1] = 1;

	for (i = numsSize -2; i >= 0; i--)
	{
		for (j = 1; j <= nums[i] && (i+j) < numsSize; j++)
		{
			dp[i] = dp[i + j];
			if (dp[i] > 0)
			{
				break;
			}
		}
	}
	return dp[0] > 0 ? true : false;
}


