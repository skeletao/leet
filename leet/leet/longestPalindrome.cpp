#include <iostream>
using namespace std;
char* longestPalindrome(char* s) {
	int i = 0;
	int j = 0;
	int k = 0;
	int len = strlen(s);
	int count = 1;
	int index = 0;
	char *sub;

	if (len < 2)
	{
		return s;
	}
	while (*(s + i))
	{
		j = k = i;
		while (j > 0 && (*(s + j)) == (*(s + j - 1)))
		{
			j--;
		}
		while (j > 0 && (k + 1) < len && (*(s + j - 1)) == (*(s + k + 1)))
		{
			j--;
			k++;
		}

		if ((k - j + 1) > count)
		{
			count = k - j + 1;
			index = j;
		}
		i++;
	}
	sub = (char *)malloc(sizeof(char) *(count + 1));
	for (j = index; j < (index + count); j++)
	{
		*sub++ = *(s + j);
	}
	*sub = '\0';
	return (sub - count);
}