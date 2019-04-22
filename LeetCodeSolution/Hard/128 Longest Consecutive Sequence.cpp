#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.
*/

int longestConsecutive(vector<int>& nums) {
	set<int> store;

	for (auto item : nums) {
		store.insert(item);
	}

	int result{ 0 };

	for (auto item : nums) {
		int right{ 1 };
		while (store.count(item + right) != 0) {
			right++;
		}

		result = max(result, right);
	}

	return result;
}
