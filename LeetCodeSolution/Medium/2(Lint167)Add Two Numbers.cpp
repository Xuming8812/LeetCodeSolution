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
The digits are stored in reverse order, such that the 1's digit is at the head of the list. 
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
 * @param l1: the first list
 * @param l2: the second list
 * @return: the sum list of l1 and l2 
 */
ListNode* addLists(ListNode * l1, ListNode * l2) {
    // write your code here
    //the head of the result list
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    //initialize the carry variable
    int carry = 0;
    
    //either has l1 or l2
    while(l1!=nullptr || l2!=nullptr){
        //two numbers, default as 0
        int addOne=0,addTwo=0;
        //get current number in l1 and move on
        if(l1!=nullptr){
            addOne = l1->val;
            l1=l1->next;
        }
        //get current number in l2 and move on
        if(l2!=nullptr){
            addTwo = l2->val;
            l2=l2->next;
        }
        //calculate sum and carry
        int sum = addTwo+addOne+carry;
        carry = sum/10;
        sum = sum%10;
        //save the current result
        ListNode* temp = new ListNode(sum);
        //connect to the list
        current->next = temp;
        //set it as current node
        current = current->next;                
    }
    //if carry is not 0
    if(carry == 1){
        ListNode* temp = new ListNode(1);
        current->next = temp;
    }
    
    return dummy->next;
}