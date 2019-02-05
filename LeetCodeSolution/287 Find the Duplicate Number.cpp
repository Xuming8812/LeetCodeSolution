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
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. 
Assume that there is only one duplicate number, find the duplicate one.
*/

int findDuplicate(vector<int>& nums) {
	// Write your code here
	int start = 1;
	int end = nums.size() - 1;
	while (start + 1 < end) {
		int mid = start + (end - start) / 2;
		if (check_smaller_num(mid, nums) <= mid) {
			start = mid;
		}
		else {
			end = mid;
		}
	}

	if (check_smaller_num(start, nums) <= start) {
		return end;
	}
	return start;
}

int check_smaller_num(int mid, vector<int>& nums) {
	int cnt = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] <= mid) {
			cnt++;
		}
	}
	return cnt;
}