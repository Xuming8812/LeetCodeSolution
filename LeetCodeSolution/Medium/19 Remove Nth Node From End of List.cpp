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

//in one pass
ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode* previous{ new ListNode(INT_MAX) }, *current{ head };

	previous->next = head;

	while (current) {
		ListNode *kthNext{ current };
		
		//get the nth next
		for (int i = 0; i < n; i++) {
			kthNext = kthNext->next;
		}

		if (kthNext == nullptr) {
			previous->next = current->next;

			if (current == head)
			{
				return previous->next;
			}
			else
			{
				return head;
			}
		}
		else {
			previous = current;
			current = current->next;
		}

	}

	return head;

}

//use fast and slow pointer
ListNode* removeNthFromEnd(ListNode* head, int n) {

	ListNode* node{ head };
	ListNode* remove{ head };
	int cnt{ 0 };

	while (node->next != NULL){
		cnt++;
		if (cnt > n)
			remove = remove->next;
		node = node->next;
	}

	if (cnt == n){
		head->next = head->next->next;
	}
	else{
		if (remove == head){
			head = head->next;
		}
		else{
			remove->next = remove->next->next;
		}
	}

	return head;
}