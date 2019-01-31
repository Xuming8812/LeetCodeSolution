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
Given an array of n positive integers and a positive integer s, 
find the minimal length of a contiguous subarray of which the sum ¡Ý s. If there isn't one, return 0 instead.
*/

int minSubArrayLen(int s, vector<int>& nums) {
	if (nums.empty()) return 0;

	vector<int> prefix(nums.size());

	prefix[0] = nums[0];

	for (int i = 1; i < nums.size(); i++) {
		prefix[i] = nums[i] + prefix[i - 1];
	}

	int length = nums.size();

	if (prefix[length - 1] < s) return 0;

	int left = 0, right = 0, result = INT_MAX, sum = 0;

	while (right < length) {
		sum += nums[right];
		right++;
		while (sum >= s) {
			result = min(result, right - left);

			sum -= nums[left];
			left++;
		}
	}

	return result;
}
