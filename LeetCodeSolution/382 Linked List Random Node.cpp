#include <vector>
#include <map>
#include <string>
#include <queue>
#include <sstream>
#include <stack>
#include <set>
#include <bitset>

using namespace std;

/*
Given a singly linked list, return a random node's value from the linked list.
Each node must have the same probability of being chosen.
*/
 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};

class Solution {
public:
	/** @param head The linked list's head.
		Note that the head is guaranteed to be not null, so it contains at least one node. */
	ListNode* u;
	Solution(ListNode* head) {
		u = head;
	}

	int getRandom() {
		int res, len = 1;

		ListNode* v = u;

		while (v) {
			if (rand() % len == 0) {
				res = v->val;
			}
			len++;
			v = v->next;
		}
		return res;
	}
};