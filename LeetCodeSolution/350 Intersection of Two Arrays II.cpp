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

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	map<int, int> count;
	for (auto num : nums1) {
		count[num]++;
	}

	vector<int> result;

	for (auto num : nums2) {
		if (count.find(num) != count.end()) {
			if (count[num] > 0) {
				result.push_back(num);
				count[num]--;
			}
		}
	}

	return result;
}