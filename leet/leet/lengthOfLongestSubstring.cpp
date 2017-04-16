#include <iostream>
using namespace std;
int lengthOfLongestSubstring(char* s) {
	int flag[255];
	memset(flag, -1, sizeof(flag));
	int len = 0;
	int start = 0;
	int i = 0;
	while (*s)
	{
		i++;
		if (flag[*s] > start)
		{
			start = flag[*s];

		}
		flag[*s] = i;
		len = (len > (i - start)) ? len : (i - start);
		s++;
	}
	return len;
}