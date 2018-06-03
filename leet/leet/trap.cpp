#include <iostream>

int trap(int* height, int heightSize) {
	int left = 0, right = 0, res = 0, tmp = 0;
	right = heightSize - 1;

	while (left < right)
	{
		if (height[left] < height[right])
		{
			tmp = left + 1;
			while (height[left] > height[tmp])
			{
				res += (height[left] - height[tmp]);
				tmp++;
			}
			left = tmp;
		}
		else
		{
			tmp = right - 1;
			while (height[right] > height[tmp])
			{
				res += (height[right] - height[tmp]);
				tmp--;
			}
			right = tmp;
		}
	}

	return res;
}

int trap2(int* height, int heightSize) {
	int i, j, sum1 = 0, sum2 = 0, max = 0, *b, *e, n;
	for (i = 0; i < heightSize; ++i)
	{
		sum1 += height[i];
		if (height[i] > max)
			max = height[i];
	}
	b = (int *)malloc(sizeof(int)*max);
	e = (int *)malloc(sizeof(int)*max);
	n = 0;
	for (i = 0; n < max; ++i)
		if (height[i] > n)
		{
			for (j = n; j < height[i]; ++j)
				b[j] = i;
			n = j;
		}
	n = 0;
	for (i = heightSize - 1; n < max; --i)
		if (height[i] > n)
		{
			for (j = n; j < height[i]; ++j)
				e[j] = i;
			n = j;
		}
	for (i = 0; i < max; ++i)
		sum2 += e[i] - b[i] + 1;
	return sum2 - sum1;
}

int trap3(int* height, int heightSize) {
	int left = 0, right = 0, res = 0, maxleft = 0, maxright = 0;
	right = heightSize - 1;

	while (left <= right)
	{
		if (height[left] <= height[right]) {
			if (height[left] >= maxleft) maxleft = height[left];
			else res += maxleft - height[left];
			left++;
		}
		else
		{
			if (height[right] >= maxright) maxright = height[right];
			else res += maxright - height[right];
			right--;
		}
	}
	return res;
}