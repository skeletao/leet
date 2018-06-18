//  -100.0 < x < 100.0
//  n is a 32 - bit signed integer, within the range[−231, 231 − 1]


#include <iostream>

double myPow(double x, int n)
{
	double res = 1.0;

	if (n == 0)
	{
		return 1;
	}

	x = n > 0 ? x : 1 / x;

	if (n % 2)
	{
		res *= x;
	}
	n = abs(n / 2);

	while (n)
	{
		x *= x;
		if (n & 1)
		{
			res *= x;
		}
		n >>= 1;
	}
	return res;
}


double myPow2(double x, int n) {
	double ans = 1;
	unsigned long long p;
	if (n < 0) {
		p = -n;
		x = 1 / x;
	}
	else p = n;
	if (p & 1) ans *= x;
	p >>= 1;
	while (p) {
		x *= x;
		if (p & 1) ans *= x;
		p >>= 1;
	}
	return ans;
}