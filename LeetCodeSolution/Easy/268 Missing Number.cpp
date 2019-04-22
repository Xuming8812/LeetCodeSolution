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
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
*/

int missingNumber(vector<int>& nums) {
	int result{ 0 };
	if (nums.empty()) return result;

	int length = nums.size();

	nums.push_back(length);

	for (int i = 0; i < length; i++) {

		if (nums[i] == 0) {
			result = i;
		}

		int index = abs(nums[i]);

		nums[index] = -nums[index];

	}

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] > 0) {
			return i;
		}
	}

	return result;
}