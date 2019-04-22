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
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
*/

void moveZeroes(vector<int>& nums) {
	int index = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] != 0) {
			nums[index++] = nums[i];
		}
	}

	for (int i = index; i < nums.size(); i++) {
		nums[i] = 0;
	}
}