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
Reverse a linked list.
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
 * @param head: n
 * @return: The new head of reversed linked list.
 */

ListNode * reverse(ListNode * head){
    //corner case
    if(head == nullptr){
        return nullptr;
    }
    //the node to store the head of the reversed linklist
    ListNode* previous{nullptr};
    //the node to store the current node
    ListNode* current = head;
    //loop each node 
    while(current!=nullptr){
        //store the next node in advance
        ListNode* temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }
    
    return previous;
}