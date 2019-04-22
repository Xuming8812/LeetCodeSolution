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
Given a n x n matrix where each of the rows and columns are sorted in ascending order, 
find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.
*/

int kthSmallest(vector<vector<int>>& matrix, int k) {
	if (matrix.empty()) return 0;

	auto cmp = [&](pair<int, pair<int, int>>&a, pair<int, pair<int, int>>&b) {
		return a.first > b.first;
	};

	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(cmp)> pq(cmp);

	int rowNum = matrix.size(), colNum = matrix[0].size();

	for (int i = 0; i < rowNum; i++) {
		pq.push({ matrix[i][0],{i,0} });
	}

	int result;
	int count = k;

	while (k--) {
		result = pq.top().first;
		int row = pq.top().second.first;
		int col = pq.top().second.second;

		pq.pop();

		if (col + 1 < colNum) {
			pq.push({ matrix[row][col + 1],{row,col + 1} });
		}
	}

	return result;
}
