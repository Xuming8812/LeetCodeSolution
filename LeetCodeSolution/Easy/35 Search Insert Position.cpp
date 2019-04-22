#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.
*/

int searchInsert(vector<int>& nums, int target) {
	if (nums.empty()) {
		return 0;
	}

	int left{ 0 }, right = nums.size() - 1;

	if (target <= nums[0]) {
		return 0;
	}

	if (target > nums[nums.size() - 1]) {
		return nums.size();
	}

	while (left < right)
	{
		int mid = left + (right - left) / 2;

		if (nums[mid] >= target) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	return left;

}