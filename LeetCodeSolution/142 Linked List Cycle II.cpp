#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

To represent a cycle in the given linked list, we use an integer pos which represents the position 
(0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

Note: Do not modify the linked list.
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head) {

	if (!head) return nullptr;

	set<ListNode *> store;

	ListNode* cur = head;
	store.insert(head);

	while (cur->next) {
		if (store.find(cur->next) == store.end()) {
			store.insert(cur->next);
		}
		else {
			return cur->next;
		}

		cur = cur->next;

	}

	return nullptr;
}