#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
*/

 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};


ListNode* deleteDuplicates(ListNode* head) {
	 if (head == nullptr) return nullptr;

	 ListNode *result = new ListNode(INT_MIN);
	 result->next = head;

	 ListNode *last{ result };
	 ListNode *cur{ head };


	 while (cur != nullptr && cur->next != nullptr) {
		 if (cur->next->val != cur->val) {
			 last = cur;
			 cur = cur->next;
		 }
		 else {
			 int dupValue = cur->val;

			 while (cur && cur->val == dupValue) {
				 last->next = cur->next;
				 //delete cur;
				 cur = last->next;
			 }
		 }
	 }

	 return result->next;
 }