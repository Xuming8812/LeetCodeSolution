#include <vector>
#include <map>
#include <string>
#include <queue>
#include <sstream>
#include <stack>
#include <set>
#include <bitset>

using namespace std;

/*
Given an array of integers with possible duplicates, randomly output the index of a given target number. 
You can assume that the given target number must exist in the arra
*/

class Solution {
public:
	Solution(vector<int> nums) {
		for (int i = 0; i < nums.size(); i++) {
			store[nums[i]].push_back(i);
		}
	}

	int pick(int target) {
		if (store.find(target) == store.end()) return -1;

		int index = store[target].size();


		return store[target][rand() % index];
	}

	map<int, vector<int>> store;
};