#include <iostream>
#include <cstdio>
#include "leet.h"
using namespace std;

int main(int argc, char **argv)
{
	int nums1[] = { 1, 2, 3 };
	int nums2[][4] = { { 0, 1, 2, 3 },{ 4, 5, 6, 7 },{ 8, 9, 10, 11 },{ 12, 13, 14, 15 } };
	char strs1[] = "aa";
	char strs2[][4] = { "cab","tin","pew","duh","may","ill","buy","bar","max","doc" };
	int *returnSize = (int *)malloc(sizeof(int));
	int **columnSizes = (int **)malloc(sizeof(int *));
	groupAnagrams(strs2, sizeof(strs2)/sizeof(strs2[0]), columnSizes, returnSize);
	return 0;
}