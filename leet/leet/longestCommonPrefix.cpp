#include <iostream>
using namespace std;
char* longestCommonPrefix(char** strs, int strsSize) {
	if (strsSize < 1)
	{
		return "";
	}
	int len = strlen(strs[0]);
	int i = 0, j = 0;
	char *common = strs[0];
	for (i = 1; i < strsSize; i++)
	{
		for (j = 0; j <len; j++)
		{
			if (common[j] != strs[i][j])
			{
				len = j;
				break;
			}
		}
	}
	common = malloc(sizeof(char)*len);
	for (i = 0; i < len; i++)
	{
		common[i] = strs[0][i];
	}
	common[len] = '\0';
	return common;
}