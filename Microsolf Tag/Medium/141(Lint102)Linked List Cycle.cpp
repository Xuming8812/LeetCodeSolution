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
Given a linked list, determine if it has a cycle in it.
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
 * @param head: The first node of linked list.
 * @return: True if it has a cycle, or false
 */
bool hasCycle(ListNode * head) {
    // write your code here
    if (head == nullptr)
    {
        return false;
    }
    ListNode* slow = head;
    ListNode* fast = head;

    while (slow&&fast&&fast->next)
    {

        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
    }


    return false;
}