#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
    
/**
 * @param l1: ListNode l1 is the head of the linked list
 * @param l2: ListNode l2 is the head of the linked list
 * @return: ListNode head of linked list
 */
ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
    // write your code here
    
    //base condition
    if(l1 == nullptr){
        return l2;
    }
    
    if(l2 == nullptr){
        return l1;
    }
    //recursive call the function
    if(l1->val < l2->val){
        l1->next = mergeTwoLists(l1->next,l2);
        return l1;
    }
    else{
        l2->next = mergeTwoLists(l1,l2->next);
        return l2;
    }
}