#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a sorted linked list, delete all duplicates such that each element appear only once.
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

ListNode* deleteDuplicates(ListNode* head) {

	ListNode* result = new ListNode(INT_MIN);

	result->next = head;

	ListNode* cur = head, *last = result;

	while (cur && cur->next) {
		if (cur->val == cur->next->val) {
			last->next = cur->next;
			cur = cur->next;
		}
		else {
			last->next = cur;
			last = last->next;
			cur = cur->next;
		}

	}

	return result->next;
}