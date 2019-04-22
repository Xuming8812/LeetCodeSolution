#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord,
such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
*/

int evalRPN(vector<string>& tokens) {
	stack<int> operand;

	for (int i = 0; i < tokens.size(); i++) {
		if (tokens[i] == "+") {
			int second = operand.top(); operand.pop();
			int first = operand.top(); operand.pop();

			operand.push(first + second);
		}
		else if (tokens[i] == "-") {
			int second = operand.top(); operand.pop();
			int first = operand.top(); operand.pop();

			operand.push(first - second);
		}
		else if (tokens[i] == "*") {
			int second = operand.top(); operand.pop();
			int first = operand.top(); operand.pop();

			operand.push(first*second);
		}
		else if (tokens[i] == "/") {
			int second = operand.top(); operand.pop();
			int first = operand.top(); operand.pop();

			operand.push(first / second);
		}
		else {
			int temp = stoi(tokens[i]);
			operand.push(temp);
		}
	}

	return operand.top();
}