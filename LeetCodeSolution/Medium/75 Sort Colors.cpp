#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, 
with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.
*/
void swap(vector<int>& nums, int a, int b) {
	int temp = nums[a];
	nums[a] = nums[b];
	nums[b] = temp;
}

void sortColors(vector<int>& nums) {
	int left{ 0 }, right = nums.size() - 1;

	int index{ 0 };

	while (index <= right) {
		if (nums[index] == 0) {
			swap(nums, left++, index++);
		}
		else if (nums[index] == 2) {
			swap(nums, right--, index);
		}
		else {
			index++;
		}
	}
}

