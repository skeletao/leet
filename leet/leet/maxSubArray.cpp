int max(int a, int b)
{
	return a > b ? a : b;
}

int maxSubArray(int* nums, int numsSize) {

	int i, tmp = 0, res = nums[0];

	for (i = 0; i < numsSize; i++)
	{
		tmp += nums[i];
		if (tmp > res)
		{
			res = tmp;
		}
		if (tmp < 0)
		{
			tmp = 0;
		}
	}
	return res;
}


// DP 
int maxSubArray2(int *nums, int numsSize)
{
	int i = 0, subSum = nums[0], maxSum = nums[0];

	for (i = 1; i < numsSize; i++)
	{
		subSum = max(nums[i] + subSum, nums[i]);
		maxSum = subSum > maxSum ? subSum : maxSum;
	}
	return maxSum;
}

 // Divide and conquer
void maxSub(int *nums, int numsSize, int *maxSum, int *sumLeft, int *sumRight, int *sum)
{
	int ms1 = 0, ms2 = 0, sl1 = 0, sl2 = 0, sr1 = 0, sr2 = 0, s1 = 0, s2 = 0;
	
	if (numsSize == 1)
	{
		*maxSum = *sumLeft = *sumRight = *sum = nums[0];
	}
	else
	{
		maxSub(nums, numsSize / 2, &ms1, &sl1, &sr1, &s1);
		maxSub(nums + numsSize / 2, numsSize - numsSize / 2, &ms2, &sl2, &sr2, &s2);
		*maxSum = max(max(ms1, ms2), (sr1 + sl2));
		*sumLeft = max(sl1, s1 + sl2);
		*sumRight = max(sr2, s2 + sr1);
		*sum = s1 + s2;
	}
}

int maxSubArray3(int *nums, int numsSize)
{
	int maxSum = 0, sumLeft = 0, sumRight = 0, sum = 0;
	maxSub(nums, numsSize, &maxSum, &sumLeft, &sumRight, &sum);
	return maxSum;
}


