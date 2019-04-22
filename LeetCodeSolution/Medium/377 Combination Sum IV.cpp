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
Given an integer array with all positive numbers and no duplicates, 
find the number of possible combinations that add up to a positive integer target.
*/

int combinationSum4(vector<int>& nums, int target) {
	if (nums.empty()) return 0;

	sort(nums.begin(), nums.end());

	vector<double> dp(target + 1);
	dp[0] = 1;

	for (int i = 1; i <= target; i++) {
		for (int j = 0; j < nums.size(); j++) {
			if (nums[j] <= i) {
				dp[i] += dp[i - nums[j]];
			}
		}
	}

	return dp[target];
}