#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given a linked list, determine if it has a cycle in it.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
//use fast and slow pointer to detect cycle
bool hasCycle(ListNode *head)
{
	if (head == nullptr)
	{
		return false;
	}
	ListNode* slow = head;
	ListNode* fast = head;

	while (slow&&fast&&fast->next)
	{

		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
		{
			return true;
		}
	}


	return false;
}

