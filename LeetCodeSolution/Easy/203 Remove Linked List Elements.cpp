#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Remove all elements from a linked list of integers that have value val.
*/

 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}	
};

 ListNode* removeElements(ListNode* head, int val)
 {
	 if (head == nullptr)
	 {
		 return nullptr;
	 }
	 if (head->next == nullptr && head->val == val)
	 {
		 return nullptr;
	 }
	 //use a node to save previous node
	 ListNode* current = head;
	 ListNode* previous(0);
	 previous->next = head;

	 //use a node the save the head of the new list
	 ListNode* result(previous);

	 while (current != nullptr)
	 {
		 if (current->val == val)
		 {
			 ListNode* temp = current;
			 previous->next = current->next;
			 current = current->next;
			 delete temp;
		 }
		 else
		 {
			 previous = current;
			 current = current->next;
		 }
	 }

	 return result->next;
 }