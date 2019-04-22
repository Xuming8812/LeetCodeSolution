#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
*/

int removeDuplicates(vector<int>& nums) {
	int result{ 0 };

	if (nums.empty()) {
		return result;
	}

	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] != nums[result]) {
			result++;
			nums[result] = nums[i];
		}
	}

	return ++result;
}