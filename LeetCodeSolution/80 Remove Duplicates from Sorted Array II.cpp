#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
*/

int removeDuplicates(vector<int>& nums) {
	if (nums.empty()) return 0;

	int index{ 1 }, count{ 1 };

	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] == nums[i - 1]) {
			count++;
			if (count > 2) {
				continue;
			}
			else {
				nums[index++] = nums[i];
			}
		}
		else {
			count = 1;
			nums[index++] = nums[i];
		}
	}

	return index;
}
