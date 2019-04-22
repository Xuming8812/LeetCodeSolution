#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ¡Ù nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -¡Þ
*/

int findPeakElement(vector<int>& nums) {
	//if(nums.size()<3) return 0;

	int left = 0, right = nums.size() - 1;

	while (left < right) {
		int mid = left + (right - left) / 2;

		if (nums[mid] > nums[mid + 1]) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	return left;
}