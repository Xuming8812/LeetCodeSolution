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
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.
*/

void inQueue(deque<int>& store, int input) {
	while (!store.empty() && store.back() < input) {
		store.pop_back();
	}
	store.push_back(input);
}

void outQueue(deque<int>& store, int input) {
	if (store.front() == input) {
		store.pop_front();
	}
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	deque<int> store;
	vector<int> result;

	for (int i = 0; i < k - 1; i++) {
		inQueue(store, nums[i]);
	}

	for (int i = k - 1; i < nums.size(); i++) {
		inQueue(store, nums[i]);
		result.push_back(store.front());
		outQueue(store, nums[i + 1 - k]);

	}

	return result;

}