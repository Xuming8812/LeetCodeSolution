#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).
*/

int search(vector<int>& nums, int target) {
	if (nums.empty()) {
		return -1;
	}

	int pivotIndex = findPivot(nums);

	int result = binarySearch(nums, 0, pivotIndex, target);

	if (result != -1) return result;

	result = binarySearch(nums, pivotIndex + 1, nums.size() - 1, target);

	if (result != -1) return result;

	return -1;
}

int findPivot(vector<int>& nums) {
	int left = 0, right = nums.size() - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (nums[mid] > nums[mid + 1]) {
			return mid;
		}
		else {
			if (nums[mid] < nums[left]) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
	}

	return 0;
}

int binarySearch(vector<int>& nums, int start, int end, int target) {
	int left = start, right = end;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (nums[mid] == target) {
			return mid;
		}

		if (nums[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return -1;
}