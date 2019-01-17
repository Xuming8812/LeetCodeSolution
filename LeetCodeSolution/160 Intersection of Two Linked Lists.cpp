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

/*
Write a program to find the node at which the intersection of two singly linked lists begins.
*/


//get the length of a linked list
int getLength(ListNode* head)
{
	int result{ 0 };

	ListNode* ptr{ head };

	while (ptr != nullptr)
	{
		ptr = ptr->next;
		result++;
	}

	return result;
}


//get the intersection
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	if (headA == nullptr || headB == nullptr)
	{
		return nullptr;
	}
	//get length for both linked lists
	int lenA = getLength(headA);
	int lenB = getLength(headB);


	ListNode* ptrA{ headA };
	ListNode* ptrB{ headB };

	//make the two linked lists of same length
	if (lenA > lenB)
	{
		for (int i = 0; i < lenA - lenB; i++)
		{
			ptrA = ptrA->next;
		}
	}
	else
	{
		for (int i = 0; i < lenB - lenA; i++)
		{
			ptrB = ptrB->next;
		}
	}

	//find the intersection node
	while (ptrA != ptrB)
	{
		ptrA = ptrA->next;
		ptrB = ptrB->next;
	}

	return ptrA;

}