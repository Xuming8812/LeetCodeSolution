#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.
*/

int findMin(vector<int>& nums) {
	if (nums.empty()) return 0;
	if (nums.size() == 1) return nums[0];

	int left = 0, right = nums.size() - 1;

	while (nums[left] == nums[right] && left < right) {
		right--;
	}

	while (left < right) {
		int mid = left + (right - left) / 2;

		if (nums[mid] <= nums[right]) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	return nums[left];
}