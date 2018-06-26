/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/

#include <iostream>

int* plusOne(int* digits, int digitsSize, int* returnSize) 
{
	int i = 0, m = 1;
	int *res = (int *)malloc(digitsSize * sizeof(int));
	for (i = digitsSize - 1; i >= 0; i--)
	{
		res[i] = (digits[i] + m) % 10;
		m = (digits[i] + m) / 10;
	}
	if (m == 1)
	{
		free(res);
		res = (int *)calloc((digitsSize + 1), sizeof(int));
		res[0] = 1;
	}
	*returnSize = digitsSize + m;
	return res;
}

int* plusOne2(int* digits, int digitsSize, int* returnSize) 
{
	for (int i = digitsSize - 1; i >= 0; i--) {
		if (digits[i] + 1 <= 9) {
			digits[i]++;
			*returnSize = digitsSize;
			return digits;
		}
		else {
			digits[i] = 0;
		}
	}

	*returnSize = digitsSize + 1;
	int *result = (int *)calloc(*returnSize, sizeof(int));
	result[0] = 1;
	return result;
}


