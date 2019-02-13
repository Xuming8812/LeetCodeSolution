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
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.
*/

bool canMeasureWater(int x, int y, int z) {
	if (x > y) {
		swap(x, y);
	}

	set<int> results;

	queue<int> bfs;

	bfs.push(0);

	while (!bfs.empty()) {
		int current = bfs.front();
		bfs.pop();

		if (current == z) {
			return true;
		}

		if (results.find(current) == results.end() && current >= 0) {
			results.insert(current);

			if (current <= x) {
				bfs.push(x + current);
				bfs.push(y + current);
				bfs.push(y - (x - current));
				bfs.push(x - (y - current));
			}
			else if (current < y) {
				bfs.push(x + current);
				bfs.push(x - (y - current));
			}
		}
	}

	return false;
}
