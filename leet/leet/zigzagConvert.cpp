#include <iostream>
using namespace std;
char* zigzagConvert(char* s, int numRows) {
	if (numRows < 2)
	{
		return s;
	}
	int i = 0;
	int j = 0;
	int t = 2 * (numRows - 1);
	int len = strlen(s);
	char *temp = (char *)malloc(sizeof(char) * (len + 1));
	char *ss = temp;
	while (t*j < len)
	{
		*temp++ = *(s + t*j);
		j++;
	}

	for (i = 1; i < (numRows - 1); i++)
	{
		j = 0;
		while ((t*j + i) < len)
		{
			*temp++ = *(s + t*j + i);
			if ((t*(j + 1) - i) < len)
				*temp++ = *(s + t*(j + 1) - i);
			j++;
		}
	}

	j = 0;
	while ((t *j + numRows - 1) < len)
	{
		*temp++ = *(s + t *j + numRows - 1);
		j++;
		*temp = '\0';
	}
	return ss;
}