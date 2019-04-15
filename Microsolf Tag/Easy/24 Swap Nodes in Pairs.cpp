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
Given a linked list, swap every two adjacent nodes and return its head.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
*/

ListNode* swapPairs(ListNode* head) {

	if (head == nullptr || head->next == nullptr) { return head; }

	ListNode *left{ head }, *right{ head->next }, *result{ head->next }, *previous{ new ListNode(INT_MAX) };

	while (left != nullptr && right != nullptr)
	{
		previous->next = right;
		left->next = right->next;
		right->next = left;

		if (left->next == nullptr || left->next->next == nullptr) { return result; }

		previous = left;
		right = left->next->next;
		left = left->next;

	}

	return result;
}

// the recursive version
ListNode* swapPairs(ListNode* head) {
	//base condition
	if (head == nullptr || head->next == nullptr) {
		return head;
	}

	//switch the first two
	ListNode * firstNode = head;
	ListNode * secondNode = head->next;
	ListNode * result = secondNode;

	firstNode->next = secondNode->next;
	secondNode->next = firstNode;

	//call this function recursively to deal with other nodes
	firstNode->next = swapPairs(firstNode->next);

	return result;
}