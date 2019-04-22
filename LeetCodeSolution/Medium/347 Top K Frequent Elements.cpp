#include <vector>
#include <map>
#include <string>
#include <queue>
#include <sstream>
#include <stack>
#include <set>
#include <bitset>

using namespace std;

/*
Given a non-empty array of integers, return the k most frequent elements.
*/

vector<int> topKFrequent(vector<int>& nums, int k) {
	map<int, int> mp;
	for (int n : nums) {
		mp[n]++;
	}
	priority_queue<pair<int, int>> pq;

	for (auto item : mp) {
		pq.push({ item.second, item.first });
	}

	vector<int> res;

	for (int i = 0; i < k; i++) {
		res.push_back(pq.top().second);
		pq.pop();
	}
	return res;
}
