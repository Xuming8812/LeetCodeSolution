#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.
*/

vector<vector<int>> result;


//backtrack
void combinationSumHelper(vector<int>& candidates, int target, int current, vector<int> chosen) {
	if (target < 0)
	{
		return;
	}
	else if (target == 0) {
		result.push_back(chosen);                       //save result
	}
	else {
		for (int i = current; i < candidates.size(); i++) {
			chosen.push_back(candidates[i]);            //choose

			combinationSumHelper(candidates, target - candidates[i], i, chosen);        //explore

			chosen.pop_back();                          //unchoose
		}
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

	vector<int> chosen;

	combinationSumHelper(candidates, target, 0, chosen);

	return result;
}