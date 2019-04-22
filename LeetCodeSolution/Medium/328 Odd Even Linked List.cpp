#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<bitset>
using namespace std;

/*
Given a singly linked list, group all odd nodes together followed by the even nodes. 
Please note here we are talking about the node number and not the value in the nodes.
*/

 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode* oddEvenList(ListNode* head)
{
	if (!head) return head;

	ListNode *odd = head, *evenhead = head->next, *even = evenhead;

	while (even && even->next)
	{
		odd->next = odd->next->next;
		even->next = even->next->next;
		odd = odd->next;
		even = even->next;
	}

	odd->next = evenhead;
	return head;
}
