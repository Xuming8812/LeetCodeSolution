#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<bitset>
using namespace std;

/*
Reverse a singly linked list.

*/

 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};

ListNode* reverseList(ListNode* head) {

	ListNode* previous{ nullptr };

	ListNode* cur = head;

	while (cur) {
		ListNode* temp = cur->next;

		cur->next = previous;

		previous = cur;

		cur = temp;
	}

	return previous;
}