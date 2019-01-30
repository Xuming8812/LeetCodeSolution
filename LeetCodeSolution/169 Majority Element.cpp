#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
*/

int majorityElement(vector<int>& nums) {

	if (nums.empty()) return 0;

	int count{ 1 };
	int result{ nums[0] };

	for (int i = 1; i < nums.size(); i++) {
		if (count == 0) {
			count++;
			result = nums[i];
		}
		else if (result == nums[i]) {
			count++;
		}
		else {
			count--;
		}
	}

	return result;
}