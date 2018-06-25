#include <iostream>

int uniquePaths(int m, int n) {
	int i = 0, j = 0;
	int **dp = (int **)malloc(sizeof(int *)*n);
	for (i = 0; i < n; i++)
	{
		dp[i] = (int *)(malloc)(sizeof(int)*m);
	}

	for (i = 0; i < n; i++)
	{
		dp[i][m - 1] = 1;
	}

	for (i = 0; i < m; i++)
	{
		dp[n-1][i] = 1;
	}


	for (i = n - 2 ; i >= 0; i--)
	{
		for (j = m - 2; j >= 0; j--)
		{
			dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
		}
	}
	return dp[0][0];
}