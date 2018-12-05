#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.
*/

//use a stack to store brackets
bool isValid(string s) {
	if (s.empty())
	{
		return true;
	}

	stack<char> store;
	
	for(int i = 0;i<s.size();i++)
	{
		//push left bracket into stack
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			store.push(s[i]);
		}
		//if the char is right bracket, check whether stack is empty and the top element is the corresponding left bracket
		else if(s[i] == ')')
		{
			if (store.empty()||store.top()!='(')
			{
				return false;
			}
			else
			{
				store.pop();
			}
		}
		else if (s[i] == ']')
		{
			if (store.empty() || store.top() != '[')
			{
				return false;
			}
			else
			{
				store.pop();
			}
		}
		else if (s[i] == '}')
		{
			if (store.empty() || store.top() != '{')
			{
				return false;
			}
			else
			{
				store.pop();
			}
		}
		else
		{
			continue;
		}

	}

	return store.empty();
}