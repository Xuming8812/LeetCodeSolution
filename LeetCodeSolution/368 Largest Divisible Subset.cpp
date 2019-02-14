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
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) 
of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.
*/

vector<int> largestDivisibleSubset(vector<int>& nums) {
	vector<int> result;
	if (nums.empty()) return result;
	if (nums.size() == 1) return nums;

	int length = nums.size();

	vector<int> dp(length, 1);
	vector<int> parent(length);

	sort(nums.begin(), nums.end());

	int maxLength{ 0 };
	int maxLengthIndex{ 0 };


	for (int i = 1; i < length; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				parent[i] = j;
			}

			if (dp[i] > maxLength) {
				maxLength = dp[i];
				maxLengthIndex = i;
			}
		}
	}

	for (int i = 0; i < maxLength; i++) {
		result.push_back(nums[maxLengthIndex]);
		maxLengthIndex = parent[maxLengthIndex];
	}

	sort(result.begin(), result.end());

	return result;
}