#include <iostream>
using namespace std;
bool isMatch(char* s, char* p) {
	int lens = strlen(s);
	int lenp = strlen(p);
	bool flag[1000][1000] = { true };
	int i = 0, j = 0;
	flag[0][0] = true;

	for (j = 1; j < lenp + 1; j++)
	{
		flag[0][j] = j > 1 && p[j - 1] == '*' && flag[0][j - 2];
	}

	for (i = 1; i < (lens + 1); i++)
	{
		flag[i][0] = false;
	}

	for (i = 1; i <= lens; i++)
	{
		for (j = 1; j <= lenp; j++)
		{
			if (p[j - 1] == '*')
			{
				flag[i][j] = (j > 1 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && flag[i - 1][j]) || flag[i][j - 2];
			}
			else
			{
				flag[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '.') && flag[i - 1][j - 1];
			}

		}
	}
	return flag[lens][lenp];
}