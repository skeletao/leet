#include <iostream>

int divide(int dividend, int divisor) {

	int res = 0, i = 0;

	unsigned int dvd = 0, dvs = 0;

	int sign = (dividend < 0) ^ (divisor < 0);

	if (dividend == INT_MIN && divisor == -1)
	{
		return INT_MAX;
	}

	dvd = abs(dividend);
	dvs = abs(divisor);

	for (i = 31; i >= 0; i--)
	{
		if ((dvd >> i) >= dvs)
		{
			dvd -= (dvs << i);
			res |= (1 << i);
		}
	}

	return sign > 0 ? -res : res;
}