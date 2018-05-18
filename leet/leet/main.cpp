#include <iostream>
#include <cstdio>
#include "leet.h"
using namespace std;

int main(int argc, char **argv)
{
	struct ListNode l1 = {2, NULL};
	struct ListNode l2 = {1, NULL };
	mergeTwoSortedLists(&l1, &l2);
}