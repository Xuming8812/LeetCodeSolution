#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given an array, rotate the array to the right by k steps, where k is non-negative.
*/

void rotate(vector<int>& nums, int k) {
	vector<int> store{ nums };

	k = k % nums.size();

	for (int i{ 0 }; i < k; i++){
		store[i] = nums[nums.size() - k + i];
	}

	for (int i = k; i < nums.size(); i++){
		store[i] = nums[i - k];
	}

	nums = store;
}

//the in-place solution
/**
* @param nums: an array
* @param k: an integer
* @return: rotate the array to the right by k steps
*/
void rotate(vector<int> &nums, int k) {
	// Write your code here

	if (nums.size() < 2) {
		return;
	}

	k = k % nums.size();

	reverse(nums, 0, nums.size() - k - 1);
	reverse(nums, nums.size() - k, nums.size() - 1);

	reverse(nums, 0, nums.size() - 1);
}

void reverse(vector<int> &nums, int start, int end) {
	while (start < end) {
		swap(nums[start], nums[end]);
		start++;
		end--;
	}
}