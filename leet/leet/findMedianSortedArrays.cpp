#include <iostream>
using namespace std;

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	double median = 0.0;
	int *A, *B, m, n, i, j, left, right;
	int low = 0;
	int high = 0;

	if (nums1Size < nums2Size)
	{
		A = nums1;
		B = nums2;
		m = nums1Size;
		n = nums2Size;
	}
	else
	{
		A = nums2;
		B = nums1;
		m = nums2Size;
		n = nums1Size;
	}

	high = m;
	while (low <= high)
	{
		i = (low + high) / 2;
		j = (m + n + 1) / 2 - i;

		if (i > 0 && A[i - 1] > B[j])
			high = i - 1;
		else if (i < m && B[j - 1] > A[i])
			low = i + 1;
		else
		{
			if (i == 0)
			{
				left = B[j - 1];
			}
			else if (j == 0)
			{
				left = A[i - 1];
			}
			else
			{
				left = (A[i - 1] > B[j - 1]) ? A[i - 1] : B[j - 1];
			}

			if (i == m)
			{
				right = B[j];
			}
			else if (j == n)
			{
				right = A[i];
			}
			else
			{
				right = (A[i] < B[j]) ? A[i] : B[j];
			}

			median = (m + n) % 2 ? left : (left + right) / 2.0;
			break;
		}

	}
	return median;
}