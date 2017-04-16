#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode head = { 0,NULL };
	struct ListNode *temp = &head;
	struct ListNode *newNode;
	int data = 0;
	int carry = 0;
	while (l1 != NULL || l2 != NULL || carry)
	{
		int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;

		data = sum % 10;
		carry = sum / 10;

		newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
		newNode->val = data;
		newNode->next = NULL;
		temp->next = newNode;
		temp = newNode;
		l1 = l1 ? l1->next : l1;
		l2 = l2 ? l2->next : l2;
	}
	return head.next;
}