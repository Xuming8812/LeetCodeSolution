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