/*
 *	Input: S = "ADOBECODEBANC", T = "ABC"
 *	Output : "BANC
 */

#include <iostream>

char* minWindow(char* s, char* t) {
	int i = 0, h = -1, b = 0, d = INT_MAX, tLen = 0, map[128] = { 0 };
	char *res;

	while (t[i])
	{
		map[t[i]]++;
		i++;
	}
	tLen = i;
	i = 0;

	while (s[i])
	{
		if (map[s[i]]-- > 0)
		{
			tLen--;
		}
		i++;
		while (tLen == 0)
		{
			if (i - b < d)
			{
				d = i - b;
				h = b;
			}
			if (map[s[b]]++ == 0)
			{
				tLen++;
			}
			b++;
		}
	}

	if (h == -1)
	{
		return "";
	}

	res = (char *)malloc((d + 1) * sizeof(char));
	for (i = h; i < h + d; i++)
	{
		res[i - h] = s[i];
	}

	res[i - h] = '\0';
	return res;
}
