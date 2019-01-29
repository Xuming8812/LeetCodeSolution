#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­

You may not modify the values in the list's nodes, only nodes itself may be changed.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

int getLength(ListNode* head) {
	int result{ 0 };
	ListNode* cur = head;

	while (cur) {
		result += 1;
		cur = cur->next;
	}

	return result;
}

void reorderList(ListNode* head) {
	if (!head) return;

	int length = getLength(head);

	ListNode* cur = head;

	for (int i = 0; i < (length + 1) / 2; i++) {
		cur = cur->next;
	}

	stack<ListNode*> store;

	while (cur) {
		store.push(cur);
		cur = cur->next;
	}

	cur = head;

	for (int i = 0; i < (length + 1) / 2; i++) {
		if (store.empty()) {
			cur->next = nullptr;
		}
		else {
			ListNode* temp = store.top(); store.pop();

			temp->next = cur->next;
			cur->next = temp;
			cur = temp->next;
		}
	}

	cur->next = nullptr;
}