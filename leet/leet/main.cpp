#include <iostream>
#include <cstdio>
#include "leet.h"
using namespace std;

int main(int argc, char **argv)
{
	int nums[] = {1, 2, 3};
	int tmp1;
	int *returnSize = (int *)malloc(sizeof(int));
	char s1[] = "aa";
	char s2[] = "aa";
	int n = 4;
	int nums1[][4] = { {0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 15} };
	rotate((int **)nums1, 4, returnSize);
	return 0;
}