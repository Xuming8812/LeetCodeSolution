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
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
*/

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
	vector<set<int>> graph(numCourses);

	vector<int> pre(numCourses);

	vector<int> result;

	for (auto item : prerequisites) {
		graph[item.second].insert(item.first);
		pre[item.first]++;
	}

	queue<int>bfs;

	for (int i = 0; i < numCourses; i++) {
		if (pre[i] == 0)bfs.push(i);
	}

	while (!bfs.empty()) {
		int cur = bfs.front(); bfs.pop();
		result.push_back(cur);

		for (auto item : graph[cur]) {
			pre[item]--;
			if (pre[item] == 0) {
				bfs.push(item);
			}
		}
	}

	if (result.size() == numCourses) {
		return result;
	}
	else {
		return {};
	}

}