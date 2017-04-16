#include <iostream>
using namespace std;
int myAtoi(char* str) {
	int sign = 1;
	int long val = 0;
	while (*str == ' ')
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '+') ? 1 : -1;
		str++;
	}
	while (*str <= '9' && *str >= '0')
	{
		val = val * 10 - '0' + *str;
		if (val*sign >= INT_MAX)
		{
			return INT_MAX;
		}
		else if (val*sign <= INT_MIN)
		{
			return INT_MIN;
		}
		else
		{
			str++;
		}
	}
	return val*sign;

}