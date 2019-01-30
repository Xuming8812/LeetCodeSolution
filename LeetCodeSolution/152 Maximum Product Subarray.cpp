#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord,
such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
*/

int maxProduct(vector<int>& nums) {
	if (nums.empty()) return 0;

	int result{ INT_MIN };

	int maxLocal{ 1 }, minLocal{ 1 };

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] < 0) {
			swap(maxLocal, minLocal);
		}

		maxLocal = max(maxLocal*nums[i], nums[i]);
		minLocal = min(minLocal*nums[i], nums[i]);

		result = max(maxLocal, result);
	}

	return result;
}