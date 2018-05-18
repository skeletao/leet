#include <iostream>
using namespace std; 
bool isValid(char *s)
{
	char *pre = (char *)malloc(INT16_MAX);
	*pre = 0;
	int i = 0, j = 0;

	if (s == NULL)
	{
		return true;
	}

	while (*(s + j))
	{
		switch (*(s + j))
		{
		case '{':
		case '(':
		case '[':
			i++;
			*(pre + i) = *(s + j);
			break;
		case '}':
			if (*(pre + i) == '{')
			{
				i--;
				break;
			}
			else
			{
				return false;
			}
		case ')':
			if (*(pre + i) == '(')
			{
				i--;
				break;
			}
			else
			{
				return false;
			}
		case ']':
			if (*(pre + i) == '[')
			{
				i--;
				break;
			}
			else
			{
				return false;
			}
		default:
			break;
		}
		j++;
	}
	if (i > 0)
	{
		return false;
	}
	else
	{
		return true;
	}

}