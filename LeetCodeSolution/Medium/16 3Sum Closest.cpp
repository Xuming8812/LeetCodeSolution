#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. 
Return the sum of the three integers. You may assume that each input would have exactly one solution.
*/


//very similar to Prob 15
int threeSumClosest(vector<int>& nums, int target) {
	int result{ 0 }, distance{ INT_MAX };
	int left{ 0 }, right{ 0 }, sum{ 0 };

	//sort the original vector
	sort(nums.begin(), nums.end());

	//choose the first number
	for (int i = 0; i < nums.size(); i++) {
		left = i + 1;
		right = nums.size() - 1;

		while (left < right) {
			sum = nums[i] + nums[left] + nums[right];

			if (abs(sum - target) < distance) {
				result = sum;
				distance = abs(sum - target);
			}

			if (sum == target) {
				return target;
			}
			else if (sum > target) {
				right--;
			}
			else {
				left++;
			}
		}
	}

	return result;
}