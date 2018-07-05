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
	char strs4[][6] = { {'b','a','a','b','a','b'},{'a','b','a','a','a','a'},{'a','b','a','a','a','b'},{'a','b','a','b','b','a'},{'a','a','b','b','a','b'},{'a','a','b','b','b','a'},{'a','a','b','a','a','b'} };
	char strs5[][5] = {"abce", "bfcs", "cdef"};
	char strs6[][3] = { "ab" };
	int *returnSize = (int *)malloc(sizeof(int));
	int **columnSizes = (int **)malloc(sizeof(int *));
	struct Interval	intervals[3] = { { 1, 4 }, {0, 2}, {3, 5} };
	exist((char **)strs5, 1, 3, "ba");
	int m = 1;
	printf("%d", &m);
	return 0;
}


