#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.
*/

int singleNumber(vector<int>& nums) {
	int result{ 0 };

	for (int i = 0; i < nums.size(); i++) {
		result = result ^ nums[i];
	}

	return result;
}