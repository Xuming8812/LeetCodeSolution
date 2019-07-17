#include<map>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


/*
Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Initialize your data structure here.
        for (int i = nestedList.size() - 1; i >= 0; i--){
            store.push(&(nestedList[i]));
        }
			
    }

    // @return {int} the next element in the iteration
    int next() {
        // Write your code here
        int result = 0;
        
        if(hasNext()){
            result = store.top()->getInteger();
            store.pop();
        }
        
        return result;
    }

    // @return {boolean} true if the iteration has more element or false
    bool hasNext() {
        // Write your code here
        if (store.empty()){
            return false;
        }
        //get the top of the stack
		const NestedInteger* pTop = store.top();
		//loop if the top is also a NestedInteger, not a integer
		while (!pTop->isInteger()){
		    //push all the NestedInteger into the stack
			store.pop();
			//get NestedInteger
			auto &list = pTop->getList();
			//store each NestedInteger
			for (int i = list.size() - 1; i >= 0; i--)
				store.push(&(list[i]));
			
			if (store.empty())
				break;
			pTop = store.top();
		}
		
		return !store.empty();
    }
    
private:
	stack<const NestedInteger*> store;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */