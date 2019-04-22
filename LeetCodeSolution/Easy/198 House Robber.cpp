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
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and 
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of 
money you can rob tonight without alerting the police.
*/

int rob(vector<int>& nums) {

	if (nums.size() == 0)
	{
		return 0;
	}
	if (nums.size() == 1)
	{
		return nums[0];
	}
	if (nums.size() == 2)
	{
		return max(nums[0], nums[1]);
	}

	vector<int> sums(nums.size());

	sums[0] = nums[0];

	sums[1] = max(nums[0], nums[1]);

	for (size_t i{ 2 }; i < nums.size(); i++)
	{
		sums[i] = max(sums[i - 2] + nums[i], sums[i - 1]);
	}

	return sums[sums.size() - 1];
}