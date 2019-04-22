#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.
*/

vector<vector<int>> result;

//backtrack
void combinationSum2Helper(vector<int>& candidates, int target, int current, vector<int> chosen) {
	if (target < 0) {
		return;
	}
	else if (target == 0) {
		result.push_back(chosen);
		return;
	}
	else {
		for (int i = current; i < candidates.size(); i++) {

			if (i > current && candidates[i] == candidates[i - 1]) continue; //avoid repetition

			chosen.push_back(candidates[i]);                            //choose

			combinationSum2Helper(candidates, target - candidates[i], i + 1, chosen);    //explore

			chosen.pop_back();                                          //unchoose
		}
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<int> chosen;

	sort(candidates.begin(), candidates.end());

	combinationSum2Helper(candidates, target, 0, chosen);

	return result;
}

