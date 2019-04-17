#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

/*
Description : Implement an algorithm to delete a node in the middle of a singly linked list, given only access to that node.
Idea : overwrite the current node`s value by next node`s value and then delete the next node
*/

 class ListNode {
 public:
     int val;
     ListNode *next;
     ListNode(int val) {
         this->val = val;
         this->next = NULL;
     }
};

/*
* @param node: the node in the list should be deletedt
* @return: nothing
*/
void deleteNode(ListNode* node) {
    ListNode* temp = node->next;
    
    node->val = node->next->val;
    node->next = node->next->next;
    
    delete temp;
}