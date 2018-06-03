#include <iostream>

bool isMatchByWildcard(char* s, char* p) {
	char *pindex = NULL;
	char *sindex = s;
	
	while (*s)
	{
		if (*s == *p || *p == '?')
		{
			s++;
			p++;
			continue;
		}
		
		if (*p == '*')
		{
			sindex = s;
			pindex = ++p;
			continue;
		}

		if (pindex)
		{
			p = pindex;
			s = ++sindex;
			continue;
		}

		return false;
	}

	while (*p == '*')
	{
		p++;
	}

	return !*p;

}




bool isMatchByWildcard2(char* s, char* p) {

	int m = strlen(s);
	int n = strlen(p);
	int i = 0, j = 0;

	bool **f;

	f = (bool **)malloc(sizeof(bool*)*(m + 1));
	for (i = 0; i <= m; i++)
	{
		f[i] = (bool *)malloc(sizeof(bool)*(n + 1));
	}

	f[0][0] = true;

	for (i = 1; i <= n; i++)
	{
		f[0][i] = f[0][i - 1] && (p[i - 1] == '*');
	}

	for (i = 1; i <= m; i++)
	{
		f[i][0] = false;
	}

	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (p[j - 1] != '*')
			{
				f[i][j] = f[i - 1][j - 1] && (p[j - 1] == '?' || p[j - 1] == s[i - 1]);
			}
			else
			{
				f[i][j] = f[i][j - 1] || f[i - 1][j];
			}
		}
	}

	return f[m][n];
}


bool isMatchByWildcard3(char* s, char* p) {


	int m = strlen(s);
	int n = strlen(p);
	int i = 0, j = 0, t = 0;

	bool *pre = (bool *)malloc(sizeof(bool)*(n + 1));
	bool *cur = (bool *)malloc(sizeof(bool)*(n + 1));

	pre[0] = true;

	for (i = 1; i <= n; i++)
	{
		pre[i] = pre[i - 1] && (p[i - 1] == '*');
	}

	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (p[j - 1] != '*')
			{
				cur[j] = pre[j - 1] && (p[j - 1] == '?' || p[j - 1] == s[i - 1]);
			}
			else
			{
				cur[j] = pre[j] || cur[j - 1];
			}
		}
		
		for (t = 0; t <= n; t++)
		{
			pre[t] = cur[t];
		}
	}

	return pre[n];
}