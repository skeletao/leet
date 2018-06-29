#include <iostream>
#include <cstdio>
#include "leet.h"
using namespace std;

int main(int argc, char **argv)
{
	int nums1[] = { 0 };
	int nums2[][10] = { { 1,2,3,4,5,6,7,8,9,10 } };
	char strs1[] = "ADOBECODBANC";
	char strs2[] = "ABD";
	char strs3[][4] = { "eat","tea","tan","ate","nat","bat" };
	int *returnSize = (int *)malloc(sizeof(int));
	int **columnSizes = (int **)malloc(sizeof(int *));

	struct Interval	intervals[3] = { { 1, 4 }, {0, 2}, {3, 5} };
	subsets(nums1, sizeof(nums1) / sizeof(int), columnSizes, returnSize);
	return 0;
}


