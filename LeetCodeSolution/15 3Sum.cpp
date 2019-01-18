#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.
*/


vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> result;

	sort(nums.begin(), nums.end());

	int left{ 0 }, right{ 0 }, sum{ 0 };

	for (int i = 0; i < nums.size(); i++)
	{
		if (i > 0 && nums[i] == nums[i - 1]) { continue; }

		left = i + 1;
		right = nums.size() - 1;

		while (left < right)
		{
			sum = nums[i] + nums[left] + nums[right];

			if (sum > 0) {
				right--;
			}
			else if (sum < 0) {
				left++;
			}
			else {
				result.push_back(vector<int>{nums[i], nums[left], nums[right]});
				while (left + 1 < right && nums[left] == nums[left + 1]) {
					left++;
				}
				while (left + 1 < right && nums[right] == nums[right - 1]) {
					right--;
				}

				left++;
				right--;
			}

		}
	}

	return result;
}