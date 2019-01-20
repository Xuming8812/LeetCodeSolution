#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given a collection of distinct integers, return all possible permutations.
*/


vector<vector<int>> result;

void permuteHelper(vector<int>& nums, vector<int> chosen) {
	if (chosen.size() == nums.size()) {
		result.push_back(chosen);
		return;
	}

	for (int i = 0; i < nums.size(); i++) {

		auto pos = find(chosen.begin(), chosen.end(), nums[i]);		//all available choice

		if (pos == chosen.end()) {
			chosen.push_back(nums[i]);          //choose

			permuteHelper(nums, chosen);        //choose

			chosen.pop_back();                  //unchoose
		}
	}
}

vector<vector<int>> permute(vector<int>& nums) {

	vector<int> chosen;

	permuteHelper(nums, chosen);

	return result;

}