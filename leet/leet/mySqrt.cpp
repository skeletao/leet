#include <iostream>


int mySqrt(int x) {
	long ans = 0, res = 0;
	int i = 0;
	for (i = 15; i >= 0; i--)
	{
		ans = (res | (1 << i)) * (res | (1 << i));
		if (ans <= x)
		{
			res |= (1 << i);
		}
	}
	return res;
}


int mySqrt2(int x) {
	int res = x, i = 0, j =0, ss = x, m = x;
	while ((1<<i) <= res)
	{
		i++;
		res = x >> i;
	}

	if (res == (1<<i))
	{
		return res;
	}
	
	for (j = res; j <= (x >> (i - 1)); j++)
	{
		if (ss > (x -j*j) && (x -j*j) >= 0 )
		{
			ss = x - j*j;
			m = j;
		}
	}
	return m;
}