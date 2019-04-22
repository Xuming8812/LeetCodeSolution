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

int findMin(vector<int>& nums) {
	if (nums.empty()) return 0;
	if (nums.size() == 1) return nums[0];

	int left = 0, right = nums.size() - 1;

	while (left < right) {
		int mid = left + (right - left) / 2;

		if (nums[mid] < nums.back()) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	return nums[left];
}