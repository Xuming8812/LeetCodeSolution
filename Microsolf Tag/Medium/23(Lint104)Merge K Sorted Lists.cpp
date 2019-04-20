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
Merge k sorted linked lists and return it as one sorted list.
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
 * @param lists: a list of ListNode
 * @return: The head of one sorted list.
 */
ListNode *mergeKLists(vector<ListNode *> &lists) {
    // write your code here
    if(lists.empty()) return nullptr;
    
    auto cmp = [&](ListNode* a, ListNode* b){
        return a->val>b->val;
    };
    
    int k = lists.size();
    
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
    
    for(auto item : lists){
        if(item){
            pq.push(item);
        }
        
    }
    
    ListNode* result = new ListNode(-1);
    ListNode* current = result;

    while(!pq.empty()){
        ListNode* temp = pq.top();
        pq.pop();
        current->next = temp;
        current = current->next;
        
        if(temp && temp->next){
            pq.push(temp->next);
        }
    }
    
    return result->next;
}