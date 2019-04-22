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
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
*/

class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		store.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {

		int result;

		stack<int> temp;

		while (!store.empty()){
			result = store.top();

			store.pop();

			temp.push(result);
		}

		temp.pop();

		if (temp.empty()){
			return result;
		}

		int tempValue;

		while (!temp.empty()){
			tempValue = temp.top();
			store.push(tempValue);
			temp.pop();
		}

		return result;
	}

	/** Get the front element. */
	int peek() {
		int result;
		stack<int> temp;

		while (!store.empty()){
			result = store.top();

			store.pop();

			temp.push(result);
		}

		int tempValue;
		while (!temp.empty()){
			tempValue = temp.top();
			store.push(tempValue);
			temp.pop();
		}

		return result;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return store.empty();
	}

private:
	stack<int> store;
};