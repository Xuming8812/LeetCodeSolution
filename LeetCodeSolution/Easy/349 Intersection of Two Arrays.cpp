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
Given two arrays, write a function to compute their intersection.
*/

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	set<int> store;

	for (auto item : nums1) {
		store.insert(item);
	}

	vector<int> result;

	for (auto item : nums2) {
		if (store.find(item) != store.end()) {
			result.push_back(item);
			store.erase(item);
		}
	}

	return result;
}