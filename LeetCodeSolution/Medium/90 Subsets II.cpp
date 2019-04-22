#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.
*/


vector<vector<int>> powerset;
vector<int> subset;

void backtrack(vector<int>& nums, int start)
{
	powerset.push_back(subset);

	for (int i = start; i < nums.size(); ++i)
	{
		if (i > start && nums[i] == nums[i - 1])
		{
			continue;
		}

		subset.push_back(nums[i]);

		backtrack(nums, i + 1);

		subset.pop_back();
	}
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	backtrack(nums, 0);

	return powerset;

}