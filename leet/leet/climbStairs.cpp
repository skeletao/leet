#include <iostream>

int climbStairs(int n) {
	int i = 0;
	int *dp;

	dp = (int *)malloc((n+1) * sizeof(int));
	dp[n] = 1;
	dp[n - 1] = 1;

	for (i = n-2; i >= 0; i--)
	{
		dp[i] = dp[i + 1] + dp[i + 2];
	}

	return dp[0];
}