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
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]...
*/

void wiggleSort(vector<int>& nums) {
	vector<int>temp = nums;
	sort(temp.begin(), temp.end());
	int even = 0;
	int mid = temp.size() / 2 + temp.size() % 2;
	for (int i = mid - 1; i >= 0; i--) {
		nums[even] = temp[i];
		even += 2;
	}
	even = 1;
	for (int j = temp.size() - 1; j >= mid; j--) {
		nums[even] = temp[j];
		even += 2;
	}
}