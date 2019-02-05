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
Given an unsorted array of integers, find the length of longest increasing subsequence.
*/

int lengthOfLIS(vector<int>& nums) {
	if (nums.size() < 1) return 0;

	vector<int> dp(nums.size(), 1);

	int result{ 0 };
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (nums[i] > nums[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		result = max(result, dp[i]);
	}

	return result;
}