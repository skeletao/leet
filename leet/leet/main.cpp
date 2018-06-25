#include <iostream>
#include <cstdio>
#include "leet.h"
using namespace std;

int main(int argc, char **argv)
{
	int nums1[] = { 2, 0, 0 };
	int nums2[][10] = {{ 1,2,3,4,5,6,7,8,9,10 }};
	char strs1[] = "dfgalsagewqtoudgxbms";
	char strs2[][4] = { "eat","tea","tan","ate","nat","bat" };
	int *returnSize = (int *)malloc(sizeof(int));
	int **columnSizes = (int **)malloc(sizeof(int *));
	canJump(nums1, sizeof(nums1)/sizeof(int));
	return 0;
}