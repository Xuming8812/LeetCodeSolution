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
Your task is to calculate ab mod 1337 where a is a positive integer and
b is an extremely large positive integer given in the form of an array.
*/

vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
	vector<pair<int, int>> result;

	if (nums1.empty() || nums2.empty()) return result;

	auto cmp = [&](pair<int, int> a, pair<int, int>b) {
		return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
	};

	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

	for (int i = 0; i < nums1.size(); i++) {
		pq.push({ i,0 });
	}



	while (result.size() < k && !pq.empty()) {
		auto temp = pq.top();
		pq.pop();

		result.push_back({ nums1[temp.first],nums2[temp.second] });

		if (temp.second + 1 < nums2.size()) {
			pq.push({ temp.first,temp.second + 1 });
		}
	}

	return result;
}