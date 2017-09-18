#include <iostream>
#include <cstdio>
using namespace std;


int romanToInt(char *s)
{
	int array[] = {0,0,100,500,0,0,0,0,1,0,0,50,1000,0,0,0,0,0,0,0,0,5,0,10};

	int v = 0;
	int len = strlen(s);

	if (len == 1)
	{
		return array[*s - 'A'];
	}
	else if (len > 1)
	{
		for (int i = 0; i < (len - 1); i++)
		{
			v += (array[*(s + i) - 'A'] < array[*(s + i + 1) - 'A'] ? -1 * array[*(s + i) - 'A'] : array[*(s + i) - 'A']);
		}
		v += array[*(s + len -1) - 'A'];
	}

	return v;	
}