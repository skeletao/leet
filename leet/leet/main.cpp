#include <iostream>
#include <cstdio>
#include "leet.h"
using namespace std;

int main(int argc, char **argv)
{
	int nums[] = { -1, 0, 1, 2, -1, -4 };
	int numsSize = sizeof(nums);
	int **zeroArray;
	int *returnSize = NULL;
	zeroArray = threeSum(nums, numsSize, returnSize);
}