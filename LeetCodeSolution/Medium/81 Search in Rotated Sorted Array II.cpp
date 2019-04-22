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

bool search(vector<int>& nums, int target) {
	int start = 0;
	int end = nums.size() - 1;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (nums[mid] == target)
			return true;
		if (nums[start] < nums[mid]) {
			if (nums[start] <= target && target < nums[mid])
				end = mid - 1;
			else
				start = mid + 1;
		}
		else if (nums[start] > nums[mid]) {
			if (nums[mid] < target && target <= nums[end])
				start = mid + 1;
			else
				end = mid - 1;
		}
		else {
			//If nums[start] == nums[mid], just move start to the next index. 
			//So the worst case, that the array's elements are same, is O(n).
			start++;
		}
	}

	return false;

}