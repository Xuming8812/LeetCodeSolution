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
Given a sorted integer array without duplicates, return the summary of its ranges.
*/

vector<string> summaryRanges(vector<int>& nums) {
	vector<string> result;

	if (nums.empty()) return result;

	int cur{ nums[0] };
	int start{ nums[0] };

	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] == cur + 1) {
			cur = nums[i];
		}
		else {
			if (cur == start) {
				result.push_back(to_string(start));
			}
			else {
				result.push_back(to_string(start) + "->" + to_string(cur));
			}
			cur = nums[i];
			start = nums[i];
		}
	}

	if (cur == start) {
		result.push_back(to_string(start));
	}
	else {
		result.push_back(to_string(start) + "->" + to_string(cur));
	}

	return result;
}