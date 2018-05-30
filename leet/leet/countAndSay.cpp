#include <iostream>

char* countAndSay(int n) {
	char ss, *res =NULL;
	int i = 0, j = 0;
	if (n == 1)
	{
		res = (char *)malloc(2);
		res[0] = '1';
		res[1] = '\0';
	}
	else
	{
		char *tmp = countAndSay(n - 1);
		char *tmp2 = tmp;
		ss = *tmp;

		while (*(tmp++))
		{
			if (ss == *tmp)
			{
				i++;
			}
			else
			{
				if (!res)
				{
					res = (char *)malloc(2);
				}
				else
				{
					res = (char *)realloc(res, j + 2);
				}
				res[j++] = i + 1 + '0';
				res[j++] = ss;
				i = 0;
				ss = *tmp;
			}
		}
		res = (char *)realloc(res, j + 1);
		res[j] = '\0';
		free(tmp2);
	}
	return res;
}