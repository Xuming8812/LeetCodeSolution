#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j 
in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
*/
bool containsNearbyDuplicate(vector<int>& nums, int k)
{
	if (nums.empty()||k ==0)
	{
		return false;
	}
	//use hash map to store a num and its latest indice
	map<int, int> positions;

	for (int i = 0; i < nums.size(); i++)
	{
		if (positions.find(nums[i]) == positions.end())
		{
			positions[nums[i]] = i;
		}
		else
		{
			if (i - positions[nums[i]] <= k)
			{
				return true;
			}
			else
			{
				positions[nums[i]] = i;
			}
		}
	}

	return false;
}