#include <iostream>

/*
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/

// definition for an interval.

struct Interval {
	int start;
	int end;
};

void swapInterval(struct Interval *intervals, int m, int n)
{
	if (m == n)
	{
		return;
	}
	struct Interval tmp = {(intervals + m)->start, (intervals + m)->end};
	(intervals + m)->start = (intervals + n)->start;
	(intervals + m)->end= (intervals + n)->end;
	(intervals + n)->start = tmp.start;
	(intervals + n)->end = tmp.end;
}

void quickSortInterval (struct Interval *intervals, int left, int right)
{
	int i = 0, base = 0, tail = 0;
	if (left >= right)
	{
		return;
	}

	base = (intervals + right)->start;
	tail = left;

	for (i = left; i < right; i++)
	{
		if ((intervals + i)->start <= base )
		{
			swapInterval(intervals, i, tail++);
		}
	}

	swapInterval(intervals, tail, right);

	quickSortInterval(intervals, left, tail - 1);
	quickSortInterval(intervals, tail + 1, right);
}

struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
	int i = 0;
	struct Interval *res = (struct Interval *)malloc(sizeof(struct Interval));

	if (intervalsSize == 0)
	{
		return NULL;
	}
	else
	{
		res = (struct Interval*)malloc(sizeof(struct Interval));
		*returnSize = 1;
	}

	quickSortInterval(intervals, 0, intervalsSize - 1);
	res->start = intervals->start;
	res->end = intervals->end;

	for (i = 1; i < intervalsSize; i++)
	{
		if ((intervals + i)->start <= (res + *returnSize - 1)->end)
		{
			(res + *returnSize - 1)->end = (res + *returnSize - 1)->end > (intervals + i)->end ? (res + *returnSize - 1)->end : (intervals + i)->end;
		}
		else
		{
			*returnSize += 1;
			res = (struct Interval *)(realloc(res, *returnSize * sizeof(struct Interval)));
			(res + *returnSize - 1)->start = (intervals + i)->start;
			(res + *returnSize - 1)->end = (intervals + i)->end;
		}
	}
	return res;
}