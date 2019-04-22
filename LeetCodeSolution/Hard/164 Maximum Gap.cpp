#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Return 0 if the array contains less than 2 elements.
*/

int maximumGap(vector<int>& nums) {
	if (nums.size() < 2) return 0;

	set<int> store;
	for (auto item : nums) store.insert(item);

	int result{ 0 };
	int current{ -1 };
	for (auto item : store) {
		if (current == -1) {
			current = item;
		}
		else {
			result = max(result, item - current);
			current = item;
		}
	}

	return result;
}