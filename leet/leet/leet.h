#pragma once
extern int divide(int dividend, int divisor);
extern int search(int* nums, int numsSize, int target);
extern int* searchRange(int* nums, int numsSize, int target, int* returnSize);
extern char* countAndSay(int n);
extern int trap(int* height, int heightSize);
extern bool isMatchByWildcard(char* s, char* p);
extern bool isMatchByWildcard3(char* s, char* p);
extern int** permute(int* nums, int numsSize, int* returnSize);
extern void rotate(int** matrix, int matrixRowSize, int *matrixColSizes);
extern char*** groupAnagrams(char (*strs)[4], int strsSize, int** columnSizes, int* returnSize);

