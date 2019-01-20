#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<iostream>

using namespace std;

/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
*/

//O(n)
int maxSubArray(vector<int>& nums) {

	if (nums.empty()){
		return 0;
	}

	if (nums.size() == 1){
		return nums[0];
	}

	int result{ nums[0] };
	int localMax{ nums[0] };


	for (size_t i{ 1 }; i < nums.size(); i++)
	{
		localMax = max(nums[i], localMax + nums[i]);
		result = max(localMax, result);
	}

	return result;
}