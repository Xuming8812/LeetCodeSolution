#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

	int carry{ 0 }, a{ 0 }, b{ 0 }, sum{ 0 };

	//get the node of both link lists
	ListNode *ptr1{ l1 }, *ptr2{ l2 };

	//
	ListNode* head = new ListNode(INT_MAX);
	ListNode* previous{ head };

	while (ptr1 != nullptr || ptr2 != nullptr)
	{

		a = (ptr1 == nullptr) ? 0 : ptr1->val;
		b = (ptr2 == nullptr) ? 0 : ptr2->val;

		sum = a + b + carry;

		ListNode* current = new ListNode(sum % 10);

		if (head->val == INT_MAX)
		{
			head = current;
		}

		carry = sum / 10;

		previous->next = current;
		previous = current;

		ptr1 = (ptr1 == nullptr) ? nullptr : ptr1->next;
		ptr2 = (ptr2 == nullptr) ? nullptr : ptr2->next;

	}
	//check whether the carry is 1
	if (carry != 0)
	{
		ListNode* current = new ListNode(1);
		previous->next = current;
	}

	return head;
}