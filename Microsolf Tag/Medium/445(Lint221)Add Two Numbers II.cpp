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
You have two numbers represented by a linked list, where each node contains a single digit. 
The digits are stored in forward order, such that the 1's digit is at the head of the list. 
Write a function that adds the two numbers and returns the sum as a linked list.
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
 * @param l1: The first list.
 * @param l2: The second list.
 * @return: the sum list of l1 and l2.
 */
ListNode * addLists2(ListNode * l1, ListNode * l2) {
    // write your code here
    if(l1 == nullptr){
        return l2;
    }
    
    if(l2 == nullptr){
        return l1;
    }
    
    
    l1 = reverse(l1);
    l2 = reverse(l2);
    
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    
    int carry = 0;
    
    //both has l1 and l2
    
    while(l1!=nullptr || l2!=nullptr){
        int addOne=0,addTwo=0;
        if(l1!=nullptr){
            addOne = l1->val;
            l1=l1->next;
        }
        if(l2!=nullptr){
            addTwo = l2->val;
            l2=l2->next;
        }
        
        int sum = addTwo+addOne+carry;
        carry = sum/10;
        sum = sum%10;
        
        ListNode* temp = new ListNode(sum);
        current->next = temp;
        current = current->next;            
        
    }
    
    if(carry == 1){
        ListNode* temp = new ListNode(1);
        current->next = temp;
    }
    
    return reverse(dummy->next);
}

ListNode * reverse(ListNode * head){
    if(head == nullptr) return nullptr;
    
    ListNode* previous{nullptr};
    
    ListNode* current = head;
    
    while(current!=nullptr){
        ListNode* temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }
    
    return previous;
}