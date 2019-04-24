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
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

 struct RandomListNode {
     int label;
     RandomListNode* next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };
/**
 * @param head: The head of linked list with a random pointer.
 * @return: A new head of a deep copy of the list.
 */
RandomListNode *copyRandomList(RandomListNode *head) {
    // write your code here
    
    map<RandomListNode*, RandomListNode*> store;
    
    RandomListNode* temp = head;
    RandomListNode* dummy = new RandomListNode(-1);
    
    RandomListNode* current = dummy;
    
    while(temp)
    {
        RandomListNode* newNode = new RandomListNode(temp->label);
        store[temp]= newNode;
        
        current->next = newNode;
        current = current->next;
        
        temp = temp->next;
        
    }
    
    temp = head;
    
    while(temp)
    {
        if(temp->random)
        {
            store[temp]->random = store[temp->random];
        }
        
        temp = temp->next;
    }
    
    return dummy->next;
}