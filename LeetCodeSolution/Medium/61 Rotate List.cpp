#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.
*/

 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};

int getLength(ListNode* head) {
	int length{ 0 };
	ListNode *cur{ head };

	while (cur) {
		cur = cur->next;
		length++;
	}

	return length;
}

ListNode* rotateRight(ListNode* head, int k) {
	if (!head) return nullptr;

	int length = getLength(head);

	if (length == 1 || k % length == 0) return head;

	if (k > length) k = k % length;

	ListNode *cur{ head }, *newEnd, *newHead, *curEnd;

	int count{ 0 };

	for (int i = 1; i < length; i++) {
		count++;

		if (count == length - k) {
			newEnd = cur;
			newHead = cur->next;
		}

		cur = cur->next;
	}

	curEnd = cur;

	curEnd->next = head;
	newEnd->next = nullptr;

	return newHead;

}
