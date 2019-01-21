#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<iostream>

using namespace std;

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.
*/

//dp
bool canJump(vector<int>& nums) {
	if (nums.size() < 2) return true;

	vector<bool> dp(nums.size(), false);

	dp[0] = true;

	for (int i = 0; i < nums.size(); i++) {
		if (dp[i]) {
			for (int j = 1; j <= nums[i]; j++) {
				if (i + j > nums.size()) {
					return true;
				}
				dp[i + j] = true;
			}
		}
	}

	return dp[nums.size() - 1];
}


//greedy
bool canJump(vector<int>& nums) {
	int n = nums.size(), farest = 0;
	for (int i = 0; i < n; i++)
	{
		if (farest < i) return false;
		farest = max(i + nums[i], farest);
	}

	return true;
}