//Definition for singly-linked list
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode *temp1 = head;
	struct ListNode *temp2 = head;
	int i = n;
	while (temp1)
	{
		temp1 = temp1->next;
		if (i-- < 0)
		{
			temp2 = temp2->next;
		}
	}

	if (i == 0)
	{
		head = head->next;
	}
	else
	{
		temp2->next = temp2->next->next;
	}
	return head;
}


struct ListNode* removeNthFromEndBack(struct ListNode* head, int n) {
	struct ListNode *temp = head;
	int *p;
	struct ListNode *a[100] = { 0 };
	int i = 0;
	while (temp->next)
	{
		a[i++] = temp;
		temp = temp->next;
	}

	if (i + 1 == n)
	{
		head = head->next;
	}
	else
	{
		temp = a[i - n];
		temp->next = temp->next->next;
	}
	return head;
}