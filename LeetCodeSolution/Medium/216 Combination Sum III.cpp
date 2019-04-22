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
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
*/

vector<vector<int>> result;

void helper(vector<int> chosen, int current, int target, int start) {
	if (current == 0) {
		if (target == 0) {
			result.push_back(chosen);

			return;
		}
	}

	for (int i = start; i <= 9; i++) {
		auto pos = find(chosen.begin(), chosen.end(), i);

		if (pos == chosen.end()) {
			chosen.push_back(i);

			helper(chosen, current - 1, target - i, i + 1);

			chosen.pop_back();
		}
	}
}

vector<vector<int>> combinationSum3(int k, int n) {
	if (n < k || n>45) return result;

	helper({}, k, n, 1);

	return result;
}