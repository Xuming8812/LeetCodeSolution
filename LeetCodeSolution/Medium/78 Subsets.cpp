#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a set of distinct integers, nums, return all possible subsets (the power set).
*/

void dfs(vector<vector<int>>& powerset, vector<int>& cur, vector<int>& nums, int length, int start)
{
	if (cur.size() == length)
	{
		powerset.push_back(cur);
		return;
	}

	for (int i = start; i < nums.size(); i++)
	{
		cur.push_back(nums[i]);
		dfs(powerset, cur, nums, length, start + 1);
		cur.pop_back();
	}
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> powerset;
	vector<int> cur;

	for (int i = 0; i <= nums.size(); i++)
	{
		dfs(powerset, cur, nums, i, 0);
	}

	return powerset;
}

int main() {
	vector<int> input{ 1,2,3 };
	subsets(input);

	return 0;
}