#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

/*
Given an integer array nums, find the sum of the elements between indices i and j (i ¡Ü j), inclusive.
*/

class NumArray {
public:
	NumArray(vector<int> nums) {
		prefixSum.resize(nums.size()+1);
		if (!nums.empty())
		{
			prefixSum[0] = 0;
			prefixSum[1] = nums[0];

			for (int i = 1; i < nums.size(); i++)
			{
				prefixSum[i+1] = prefixSum[i] + nums[i];
			}
		}
	}

	int sumRange(int i, int j) {
		if (j < i)
		{
			return -1;
		}

		if (i < 0 || j >= prefixSum.size())
		{
			return -1;
		}

		return prefixSum[j+1] - prefixSum[i];
	}

private:
	vector<int> prefixSum;
};
