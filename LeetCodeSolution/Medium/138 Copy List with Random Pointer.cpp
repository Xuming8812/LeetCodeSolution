#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

 struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
	
};


 RandomListNode *copyRandomList(RandomListNode *head) {
	 if (head == nullptr) return nullptr;

	 map<RandomListNode*, RandomListNode*> dict;
	 RandomListNode* oldCur = head;

	 RandomListNode* dummy = new RandomListNode(-1);
	 RandomListNode* newCur = dummy;

	 while (oldCur) {
		 RandomListNode* temp = new RandomListNode(oldCur->label);
		 dict[oldCur] = temp;

		 newCur->next = temp;
		 newCur = newCur->next;

		 oldCur = oldCur->next;
	 }

	 oldCur = head;

	 RandomListNode* result = dict[head];

	 while (oldCur) {
		 if (oldCur->random) {
			 dict[oldCur]->random = dict[oldCur->random];
		 }
		 oldCur = oldCur->next;
	 }

	 return dict[head];
 }