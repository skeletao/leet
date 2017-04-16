#include <iostream>
using namespace std;
/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/

char** letterCombinations(char* digits, int* returnSize)
{
	int len = strlen(digits);
	if (len == 0)
	{
		return NULL;
	}
	char** letter = (char **)malloc(sizeof(char*) * 1024);
	int i = 0, j = 0, carry = 0;
	int *index = (int *)malloc(sizeof(int)*len);
	memset(index, 0, sizeof(int)*len);
	letter[0] = (char *)malloc(sizeof(char)*(len + 1));
	for (i = 0; i < len; i++)
	{
		letter[0][i] = 'a' + (digits[i] - '2') * 3 + (digits[i] > '7');
	}
	letter[0][len] = '\0';

	do
	{
		j++;
		letter[j] = (char *)malloc(sizeof(char)*(len + 1));
		carry = 1;
		for (i = 0; i < len; i++)
		{
			//letter[j][i] = letter[0][i] + (letter[j-1][i] - letter[0][i] + carry)%(3 + (digits[i] == '7' || digits[i] == '9'));
			//carry = (letter[0][i] + letter[j-1][i] - letter[0][i] + carry)/(letter[0][i] + 3 + (digits[i] == '7' || digits[i] == '9'));

			index[i] += carry;
			carry = index[i] / (3 + (digits[i] == '7' || digits[i] == '9'));
			index[i] = index[i] % (3 + (digits[i] == '7' || digits[i] == '9'));
			letter[j][i] = letter[0][i] + index[i];
		}
		letter[j][i] = '\0';
	} while (!carry);

	*returnSize = j;
	return letter;
}