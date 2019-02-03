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
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
Find the two elements that appear only once.
*/

vector<int> singleNumber(vector<int>& nums) {
	int r = 0, n = nums.size(), i = 0, last = 0;
	vector<int> ret(2, 0);

	for (i = 0; i < n; ++i)			//r equals A ^ B
		r ^= nums[i];

	last = r & (~(r - 1));			//get the last digit of 1 in r, in which digit A and B are different

	for (i = 0; i < n; ++i)
	{
		if ((last & nums[i]) != 0)	//A and B will be seperated into two groups
			ret[0] ^= nums[i];
		else
			ret[1] ^= nums[i];
	}

	return ret;
}