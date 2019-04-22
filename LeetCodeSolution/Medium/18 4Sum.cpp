#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target?
Find all unique quadruplets in the array which gives the sum of target.
*/

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> result;

	int left{ 0 }, right{ 0 }, sum{ 0 };

	sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size(); i++) {
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		for (int j = i + 1; j < nums.size(); j++) {

			if (j > i + 1 && nums[j] == nums[j - 1]) {
				continue;
			}

			left = j + 1;
			right = nums.size() - 1;

			while (left < right) {
				sum = nums[i] + nums[j] + nums[left] + nums[right];
				if (sum > target) {
					right--;
				}
				else if (sum < target) {
					left++;
				}
				else {
					result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});

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
	}

	return result;
}