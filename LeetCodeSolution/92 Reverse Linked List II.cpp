#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Reverse a linked list from position m to n. Do it in one-pass.
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

ListNode* reverseBetween(ListNode* head, int m, int n) {
	ListNode *dummy = new ListNode(0);
	dummy->next = head;

	ListNode *last{ dummy };

	for (int i = 0; i < m - 1; i++) {

		last = last->next;
	}

	ListNode* cur = last->next;

	for (int i = 0; i < n - m; i++) {
		ListNode* temp = cur->next;
		cur->next = temp->next;
		temp->next = last->next;
		last->next = temp;

	}

	return dummy->next;

}