#include <iostream>
#include <cstdio>
#include "leet.h"
using namespace std;

int main(int argc, char **argv)
{
	int nums1[] = { 1, 2, 3 };
	int nums2[][10] = {{ 1,2,3,4,5,6,7,8,9,10 }};
	char strs1[] = "dfgalsagewqtoudgxbms";
	char strs2[][4] = { "eat","tea","tan","ate","nat","bat" };
	int *returnSize = (int *)malloc(sizeof(int));
	int **columnSizes = (int **)malloc(sizeof(int *));
	spiralOrder(nums2, 1, 10);
	return 0;
}