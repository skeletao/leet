#include <iostream>

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* merge2Lists(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *tmp = head;
	if (!l1)
	{
		return l2;
	}

	if (!l2)
	{
		return l1;
	}

	while (l1 && l2)
	{
		if (l1->val <= l2->val)
		{
			head->next = l1;
			head = head->next;
			l1 = l1->next;
		}
		else
		{
			head->next = l2;
			head = head->next;
			l2 = l2->next;
		}
	}

	head->next = l1 ? l1 : l2;
	return tmp->next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {

	int i = 0;

	if (listsSize == 0)
	{
		return NULL;
	}

	if (listsSize == 1)
	{
		return *lists;
	}
	for (i = 0; i < listsSize / 2; i++)
	{
		*(lists + i) = merge2Lists(*(lists + i * 2), *(lists + i * 2 + 1));
	}
	if (listsSize % 2)
	{
		*(lists + i) = *(lists + listsSize - 1);
		i++;
	}
	return mergeKLists(lists, i);
}