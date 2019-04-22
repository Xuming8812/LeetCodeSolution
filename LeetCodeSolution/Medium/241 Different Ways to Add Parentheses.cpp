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
Given a string of numbers and operators, return all possible results from computing all the different 
possible ways to group numbers and operators. The valid operators are +, - and *.
*/

vector<int> diffWaysToCompute(string input) {
	vector<int> result;

	for (int i = 0; i < input.size(); i++) {

		char ch = input[i];

		if (ispunct(ch)) {
			for (auto a : diffWaysToCompute(input.substr(0, i))) {
				for (auto b : diffWaysToCompute(input.substr(i + 1))) {
					if (ch == '+') {
						result.push_back(a + b);
					}
					else if (ch == '-') {
						result.push_back(a - b);
					}
					else if (ch == '*') {
						result.push_back(a*b);
					}
				}
			}
		}
	}

	return result.empty() ? vector<int>{stoi(input)} : result;
}