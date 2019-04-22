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
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.
*/

vector<int> majorityElement(vector<int>& nums) {
	vector<int> result;
	if (nums.empty()) return result;

	int num1{ nums[0] }, num2{ nums[0] }, count1{ 0 }, count2{ 0 };

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == num1) {
			count1++;
		}
		else if (nums[i] == num2) {
			count2++;
		}
		else if (count1 == 0) {
			num1 = nums[i];
			count1++;
		}
		else if (count2 == 0) {
			num2 = nums[i];
			count2++;
		}
		else {
			count1--;
			count2--;
		}
	}

	count1 = 0;
	count2 = 0;

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == num1) count1++;
		if (nums[i] == num2) count2++;
	}

	if (count1 > nums.size() / 3)    result.push_back(num1);
	if (count2 > nums.size() / 3 && num1 != num2)    result.push_back(num2);

	return result;
}