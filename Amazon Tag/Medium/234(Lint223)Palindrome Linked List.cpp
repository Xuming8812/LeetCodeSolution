#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<unordered_map>

using namespace std;

/*
Implement a function to check if a linked list is a palindrome.
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/**
 * @param head: A ListNode.
 * @return: A boolean.
 */
bool isPalindrome(ListNode * head) {
    // write your code here
    
    if(head == nullptr){
        return true;
    }
    
    ListNode* middle = findMiddle(head);
    middle = reverse(middle);
    
    while(head && middle){
        if(head->val != middle->val){
            return false;
        }
        head = head->next;
        middle = middle->next;
    }
    
    return true;
}


ListNode * reverse(ListNode * head){
    ListNode * previous = nullptr;
    ListNode * current = head;
    while(current){
        ListNode * temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }
    
    return previous;
}

ListNode * findMiddle(ListNode * head){
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}