#include <iostream>
#include <cstdio>
#include "leet.h"
using namespace std;

int main(int argc, char **argv)
{
	int nums[] = { -1, 0, 1, 2, -1, -4 };
	int numsSize = sizeof(nums)/sizeof(nums[0]);
	int **zeroArray;
	int *returnSize = (int *)malloc(sizeof(int));
	zeroArray = threeSum(nums, numsSize, returnSize);
}