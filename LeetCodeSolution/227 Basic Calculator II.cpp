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
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
*/

int getNum(string s, int&index) {
	int start = index;

	while (index < s.size()) {
		if (s[index] == ' ' || (s[index] >= '0'&&s[index] <= '9')) {
			index++;
		}
		else {
			break;
		}
	}

	return stoi(s.substr(start, index - start));
}

int calculate(string s) {
	stack<int> operands;

	int index{ 0 };
	int num{ 0 };

	while (index < s.size()) {
		if (s[index] == ' ') {
			index++;
		}
		else if (s[index] == '+') {
			index++;
			num = getNum(s, index);
			operands.push(num);
		}
		else if (s[index] == '-') {
			index++;
			num = -getNum(s, index);
			operands.push(num);
		}
		else if (s[index] == '*') {
			int temp = operands.top(); operands.pop();
			index++;
			num = temp * getNum(s, index);
			operands.push(num);
		}
		else if (s[index] == '/') {
			int temp = operands.top(); operands.pop();
			index++;
			num = temp / getNum(s, index);
			operands.push(num);
		}
		else {
			num = getNum(s, index);
			operands.push(num);
		}

	}

	int result{ 0 };

	while (!operands.empty()) {
		result += operands.top();
		operands.pop();
	}

	return result;
}
