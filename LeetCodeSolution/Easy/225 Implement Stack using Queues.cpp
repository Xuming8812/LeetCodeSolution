#include<vector>
#include<map>
#include<string>
#include<queue>

using namespace std;

/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
*/


//basic idea is to use two queues to store data
class MyStack {
public:
	/* Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		data.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {

		queue<int> temp;
		while (data.size() > 1)
		{
			int top = data.front();
			data.pop();
			temp.push(top);
		}

		int result = data.front();
		data.pop();

		while (!temp.empty())
		{
			int top = temp.front();
			temp.pop();
			data.push(top);
		}

		return result;
	}

	/** Get the top element. */
	int top() {
		queue<int> temp;
		while (data.size() > 1)
		{
			int top = data.front();
			data.pop();
			temp.push(top);
		}

		int result = data.front();
		data.pop();

		while (!temp.empty())
		{
			int top = temp.front();
			temp.pop();
			data.push(top);
		}
		data.push(result);

		return result;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return data.empty();
	}
private:
	queue<int> data;
};