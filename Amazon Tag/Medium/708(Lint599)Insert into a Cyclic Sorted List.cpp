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
Given a node from a cyclic linked list which has been sorted, write a function to insert a value into the list such that it remains a cyclic sorted list. 
The given node can be any single node in the list. Return the inserted new node.
*/

class ListNode {
public:
     int val;
     ListNode *next;
     ListNode(int val) {
        this->val = val;
        this->next = NULL;
     }
}

/*
* @param node: a list node in the list
* @param x: An integer
* @return: the inserted new list node
*/
ListNode * insert(ListNode * node, int x) {
    // write your code here
    
    if(node == nullptr){
        ListNode * result = new ListNode(x);
        result->next = result;
        return result;
    }
    
    ListNode * minNode = node;
    ListNode * maxNode = node;
    
    int minValue = INT_MAX;
    int maxValue = INT_MIN;
    
    ListNode* head = node;
    ListNode* current = node;
    while(current->next!=head){
        if(current->val>=maxValue){
            maxValue = current->val;
            maxNode = current;
        }
        
        if(current->val < minValue){
            minValue = current->val;
            minNode = current;
        }
        
        current = current->next;
    }
    
    //if x smaller than min value, then insert it after the max node
    if(minValue>=x || x>=maxValue){
        ListNode * newNode = new ListNode(x);
        newNode->next = maxNode->next;
        maxNode->next = newNode;
        
        return head;
    }
    
    //if x is between min and max loop again
    current = node;
    
    while(current->next!=head){
        if(current->val <=x && current->next->val>=x){
            ListNode * newNode = new ListNode(x);
            newNode->next = current->next;
            current->next = newNode;
            return head;
        }
        
        current = current->next;
    }
    
    return head;
}