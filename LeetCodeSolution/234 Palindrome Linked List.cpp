#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given a singly linked list, determine if it is a palindrome.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
//use a vector to store the values of the linked list
bool isPalindrome(ListNode* head) 
{
	if (head == nullptr)
	{
		return false;
	}

	vector<int> store;

	ListNode* current = head;

	while (current)
	{
		store.push_back(current->val);
		current = current->next;	
	}
	//check the left and right element equals or not
	int left = 0, right = store.size() - 1;

	while (left < right)
	{
		if (store[left++] != store[right--])
		{
			return false;
		}
	}

	return true;
}

//use O(1) space

bool isPalindrome(ListNode* head)
{
	if (head == nullptr)
	{
		return false;
	}
	//get the middle node of the list
	ListNode* middle = getMiddle(head);

	//reverse the right half of the list
	ListNode* current1 = head;
	ListNode* current2 = reverse(middle);

	while (current1&&current2)
	{
		if (current1->val != current2->val)
		{
			return false;
		}
		current1 = current1->next;
		current2 = current2->next;
	}

	return true;
}
//get the middle node of the link list by using slow and fast pointer
ListNode* getMiddle(ListNode* head)
{
	ListNode* slow = head;
	ListNode* fast = head;

	while (slow&&fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}
//reverse the input link list
ListNode* reverse(ListNode* head)
{
	ListNode* result = nullptr;
	while (head)
	{
		ListNode*  temp = head;
		head = head->next;
		temp->next = result;
		result = temp;
	}

	return result;
}
