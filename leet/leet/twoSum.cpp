/**
* Note: The returned array must be malloced, assume caller calls free().
*/
#include <iostream>
using namespace std;

int* twoSum(int* nums, int numsSize, int target) {

	int i = 0, min = 0, max = 0;

	for (i = 0; i < numsSize; i++)
	{
		min = min < nums[i] ? min : nums[i];
		max = max > nums[i] ? max : nums[i];
	}

	int *map = (int *)malloc(sizeof(int)*(max - min + 1));
	memset(map, -1, sizeof(int)*(max - min + 1));

	for (i = 0; i < numsSize; i++) {
		int rest = target - nums[i];
		if (rest >= min && rest <= max && map[rest - min] > -1) {
			int *ans = (int *)malloc(sizeof(int) * 2);
			ans[0] = i;
			ans[1] = map[rest - min];
			free(map);
			map = NULL;
			return ans;
		}
		else
		{
			map[nums[i] - min] = i;
		}
	}
	free(map);
	map = NULL;
	return NULL;
}