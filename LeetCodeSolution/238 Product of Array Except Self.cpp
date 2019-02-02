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
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product 
of all the elements of nums except nums[i].
*/

vector<int> productExceptSelf(vector<int>& nums) {
	int totalProduct{ 1 };
	int nonZero{ 1 };
	int countZero{ 0 };

	for (int i = 0; i < nums.size(); i++) {
		totalProduct *= nums[i];

		if (nums[i] == 0) {
			countZero++;
			if (countZero > 1) {
				nonZero = 0;
			}
		}
		else {
			nonZero *= nums[i];
		}

	}

	vector<int> result;

	for (auto item : nums) {
		if (item != 0) {
			result.push_back(totalProduct / item);
		}
		else {
			result.push_back(nonZero);
		}
	}

	return result;
}