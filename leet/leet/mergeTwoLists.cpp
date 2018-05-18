/*
* Input:  1->2->4, 1->3->4
* Output: 1->1->2->3->4->4
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoSortedLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *tmp1, *tmp2, *head;
	int i = 0, j = 0;
	if (!l1)
	{
		return l2;
	}
	if (!l2)
	{
		return l1;
	}
	head = (l1->val <= l2->val) ? l1 : l2;
	while (l1 && l2)
	{
		if (l1->val <= l2->val)
		{
			if (!l1->next || l1->next->val > l2->val)
			{
				tmp1 = l1->next;
				tmp2 = l2->next;
				l1->next = l2;
				l2->next = tmp1;
				l1 = l2;
				l2 = tmp2;
			}	
			else
			{
				if (l1->next)
				{
					l1 = l1->next;
				}
				else
				{
					l1->next = l2;
					return head;
				}
			}
		}
		else
		{
			tmp1 = l1;
			l1 = l2;
			l2 = tmp1;
		}
	}
	return head;
}