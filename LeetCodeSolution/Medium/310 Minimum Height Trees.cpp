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
For an undirected graph with tree characteristics, we can choose any node as the root. 
The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are 
called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of 
undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same 
as [1, 0] and thus will not appear together in edges.
*/

vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {

	vector<int> result;

	//if(edges.empty()) return result;

	vector<set<int>> graph(n);

	//create graph based on neighbors
	for (auto item : edges) {
		graph[item.first].insert(item.second);
		graph[item.second].insert(item.first);
	}
	//record numbers of neighbors of each node
	vector<int> degree(n);

	for (int i = 0; i < n; i++) {
		degree[i] = graph[i].size();
	}


	for (int i = 0, remain = n; i < n && remain>2; i++) {
		vector<int> del;

		//find all the leaves node
		for (int j = 0; j < n; j++) {
			if (degree[j] == 1) {
				remain--;
				del.push_back(j);
				degree[j] = -1;
			}
		}
		//delete the leaves node in its neighbors
		for (auto item : del) {
			for (auto neighbor : graph[item]) {
				degree[neighbor]--;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (degree[i] >= 0) {
			result.push_back(i);
		}
	}

	return result;
}