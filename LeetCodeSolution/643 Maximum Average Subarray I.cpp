#include<vector>
#include<algorithm>
using namespace std;

/*
Given an array consisting of n integers, 
find the contiguous subarray of given length k that has the maximum average value.
And you need to output the maximum average value

1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].
*/


double findMaxAverage(vector<int>& nums, int k) {

	//calculate the prefixSum vector
	vector<double> prefixSum(nums.size());
	prefixSum[0] = nums[0];

	for (int i = 1; i < nums.size(); i++)
	{
		prefixSum[i] = prefixSum[i - 1] + nums[i];
	}

	double result = prefixSum[k - 1];


	//find the max sum of k elements by comparing prefixSum[i] - prefixSum[i - k]
	for (int i = k; i < nums.size(); i++)
	{
		result = max(result, (prefixSum[i] - prefixSum[i - k]));
	}

	return result / k;
}