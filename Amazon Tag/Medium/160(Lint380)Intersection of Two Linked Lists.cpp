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
Write a program to find the node at which the intersection of two singly linked lists begins.
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

/**
 * @param headA: the first list
 * @param headB: the second list
 * @return: a ListNode
 */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA==nullptr||headB==nullptr){
        return nullptr;
    }
    
    int lenA = getLength(headA);
    int lenB = getLength(headB);
    
    ListNode* ptrA{headA};
    ListNode* ptrB{headB};
    
    if(lenA>lenB){
        for(int i = 0;i<lenA-lenB;i++){
            ptrA = ptrA->next;
        }
    }
    else {
        for(int i = 0;i<lenB-lenA;i++){
            ptrB = ptrB->next;
        }
    }
    
    while(ptrA!=ptrB){
        ptrA=ptrA->next;
        ptrB=ptrB->next;
    }
    
    return ptrA;
    
}



int getLength(ListNode* head){
    int result{0};
    
    ListNode* ptr{head};
    
    while(ptr!=nullptr){
        ptr = ptr->next;
        result++;
    }
    
    return result;
}