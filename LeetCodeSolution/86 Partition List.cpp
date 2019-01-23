#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

ListNode* partition(ListNode* head, int x) {

	if (!head) return nullptr;
	ListNode* left{ nullptr }, *right{ nullptr }, *leftHead{ nullptr }, *rightHead{ nullptr };

	ListNode* current{ head };

	while (current != nullptr) {
		if (current->val < x) {
			if (left == nullptr) {
				left = current;
				leftHead = current;
			}
			else
			{
				left->next = current;
				left = left->next;
			}
		}
		else {
			if (right == nullptr) {
				right = current;
				rightHead = current;
			}
			else {
				right->next = current;
				right = right->next;
			}
		}

		current = current->next;
	}

	if (left != nullptr) {
		left->next = rightHead;
	}

	if (right != nullptr) {
		right->next = nullptr;
	}

	if (leftHead) {
		return leftHead;
	}
	else {
		return rightHead;

	}
}