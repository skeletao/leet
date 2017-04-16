#include <iostream>
using namespace std;
int maxArea(int* height, int heightSize) {
	int h = 0, water = 0;
	int *i = height, *j = i + heightSize - 1;

	while (i < j)
	{
		h = *i < *j ? *i : *j;
		water = water >(j - i)*h ? water : (j - i)*h;

		while (i < j && *i <= h)
		{
			i++;
		}
		while (i < j && *j <= h)
		{
			j--;
		}
	}
	return water;

}