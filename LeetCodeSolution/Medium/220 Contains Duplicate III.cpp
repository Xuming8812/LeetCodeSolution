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
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
*/

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
	set<long> window;

	for (int i = 0; i < nums.size(); i++) {

		if (i > k) window.erase(nums[i - k - 1]);

		auto pos = window.lower_bound((long)nums[i] - t);

		if (pos != window.end() && t >= *pos - nums[i]) {
			return true;
		} 

		window.insert(nums[i]);
	}
	return false;
}