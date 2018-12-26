#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.
*/

string largestTimeFromDigits(vector<int>& A) {
	string ans, numbers;

	vector<string> results;

	for (auto item : A)
	{
		numbers += to_string(item);
	}

	permutation(results, numbers, 4);

	for (int i = 0; i < 24; i++)
	{
		if (results[i].substr(0, 2) <= "23" && results[i].substr(2, 2) <= "59")
		{
			ans = max(ans, results[i]);
		}
	}

	return ans.empty() ? "" : (ans.substr(0, 2) + ":" + ans.substr(2, 2));
}


//use backtracking to get all permutation
void permutation(vector<string>& res, string nums, int k) {
	if (k == 1) {
		res.push_back(nums);
		return;
	}
	for (int i = 0; i < k; i++) {
		swap(nums[i], nums[k - 1]);

		permutation(res, nums, k - 1);

		swap(nums[i], nums[k - 1]);
	}
}