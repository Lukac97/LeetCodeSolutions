#include "Includes.h"

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* result = new ListNode();
	ListNode* it = result;
	ListNode* prev_it = result;
	int leftover = 0;

	while (l1 != nullptr || l2 != nullptr)
	{
		int sum = (l1 != nullptr ? l1->val : 0) + (l2 != nullptr ? l2->val : 0) + leftover;
		leftover = sum / 10;
		it->val = sum % 10;
		it->next = new ListNode();
		prev_it = it;
		it = it->next;

		l1 = (l1 != nullptr ? l1->next : l1);
		l2 = (l2 != nullptr ? l2->next : l2);
	}

	if (leftover == 0)
	{
		delete it;
		prev_it->next = nullptr;
	}
	else
	{
		it->val = leftover;
	}

	return result;
}
