#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/


//use a pair to store the value and current minimum value in the stack
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		int currentMin = values.empty() ? INT_MAX : values.top().second;
		values.push(std::pair<int, int>(x, std::min(x, currentMin)));
	}

	void pop() {
		values.pop();
	}

	int top() {
		return values.top().first;
	}

	int getMin() {
		return values.top().second;
	}

	stack<std::pair<int, int>> values;
};