#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<bitset>

using namespace std;

/*
Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.
*/

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
       this->val = val;
       this->next = nullptr;
    }
}

/**
 * @param head: the first Node
 * @return: the answer after plus one
 */
ListNode* plusOne(ListNode* head) {
    
    if (head == nullptr){
        return head;
    }
    //calculate recursively
    int carry = helper(head);
    //if the carry is not 0,create a new node
    if (carry == 1) {
        ListNode *res = new ListNode(1);
        res->next = head;
        return res;
    }
    
    return head;
}
//helper function to do plus one recursively
int helper(ListNode *node) {
    //base condition
    if (node == nullptr){
        return 1;
    } 
    //deal with next node
    int carry = helper(node->next);
    
    int sum = node->val + carry;
    //update the value of this node
    node->val = sum % 10;
    //return the carry
    return sum / 10;
}