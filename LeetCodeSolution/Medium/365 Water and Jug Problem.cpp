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
You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available.
You need to determine whether it is possible to measure exactly z litres using these two jugs.

If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.

Operations allowed:

Fill any of the jugs completely with water.
Empty any of the jugs.
Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.
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
