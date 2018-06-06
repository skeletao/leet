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
	int ** res = permute(nums, sizeof(nums)/sizeof(int), returnSize);
	return 0;
}