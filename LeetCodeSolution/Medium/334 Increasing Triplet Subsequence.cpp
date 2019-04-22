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
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ¡Ü i < j < k ¡Ü n-1 else return false.
*/

bool increasingTriplet(vector<int>& nums) {
	if (nums.size() < 3) return false;

	int num1{ INT_MAX }, num2{ INT_MAX };

	for (int i = 0; i < nums.size(); i++) {

		if (nums[i] <= num1) {
			num1 = nums[i];
		}
		else if (nums[i] <= num2) {
			num2 = nums[i];
		}
		else {
			return true;
		}

	}

	return false;
}