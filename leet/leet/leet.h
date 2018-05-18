#pragma once
extern struct ListNode {
	int val;
	struct ListNode *next;
};
extern struct ListNode* mergeTwoSortedLists(struct ListNode* l1, struct ListNode* l2);