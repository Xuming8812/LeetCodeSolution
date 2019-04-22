#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
*/

vector<int> twoSum(vector<int>& numbers, int target) {
	if (numbers.empty()) return {};

	int left = 0, right = numbers.size() - 1;

	while (left < right) {
		if (numbers[left] + numbers[right] == target) {
			return vector<int>{left + 1, right + 1};
		}
		else if (numbers[left] + numbers[right] > target) {
			right--;
		}
		else {
			left++;
		}
	}

	return {};

}