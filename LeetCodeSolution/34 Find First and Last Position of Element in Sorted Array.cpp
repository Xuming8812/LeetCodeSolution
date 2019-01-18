#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].
*/

vector<int> searchRange(vector<int>& nums, int target) {
	if (nums.empty()) {
		return vector<int>{-1, -1};
	}

	int left = 0, right = nums.size() - 1;

	//look for left boundary
	int result1{ 0 }, result2{ 0 };
	while (left < right) {
		int mid = left + (right - left) / 2;

		if (nums[mid] > target - 1) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	result1 = (left < nums.size() && nums[left] == target) ? left : -1;

	//look for right boundary
	left = 0, right = nums.size() - 1;

	while (left < right) {
		int mid = left + (right - left) / 2;

		if (nums[mid] > target) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	if (left == nums.size() - 1 && nums[left] == target) {
		result2 = left;
	}
	else if (left > 0 && nums[left - 1] == target) {
		result2 = left - 1;
	}
	else {
		result2 = -1;
	}

	return vector<int>{result1, result2};
}