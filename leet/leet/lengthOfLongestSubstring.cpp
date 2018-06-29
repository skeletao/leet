#include <iostream>
using namespace std;

/*
 *Given a string, find the length of the longest substring without repeating characters.
 *
 *Examples:
 *Given "abcabcbb", the answer is "abc", which the length is 3.
 *Given "bbbbb", the answer is "b", with the length of 1.
 *Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

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