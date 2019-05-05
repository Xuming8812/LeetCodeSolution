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

    //corner case
    if(lists.empty()) return nullptr;
    //declare the compare function
    auto cmp = [&](ListNode* a, ListNode* b){
        return a->val>b->val;
    };
    
    int k = lists.size();
    //declare the priority queue
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
    //push all head nodes of lists into the priority queue
    for(auto item : lists){
        if(item){
            pq.push(item);
        }  
    }
    //the head of the final result
    ListNode* result = new ListNode(-1);
    ListNode* current = result;
    //pop the top of priority queue and add it to the final linklist
    while(!pq.empty()){
        //get the top of the priority queue
        ListNode* temp = pq.top();
        pq.pop();
        //attach it to the final link list
        current->next = temp;
        current = current->next;
        //push the next node of the node that popped out from the priority queue into it
        if(temp && temp->next){
            pq.push(temp->next);
        }
    }
    
    return result->next;
}