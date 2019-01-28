#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given the head of a graph, return a deep copy (clone) of the graph. Each node in the graph contains a label (int)
and a list (List[UndirectedGraphNode]) of its neighbors. There is an edge between the given node and each of the nodes in its neighbors.
*/

 struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};	
};


 UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	 if (!node) return nullptr;

	 map<UndirectedGraphNode *, UndirectedGraphNode *>dict;

	 UndirectedGraphNode* copy = new UndirectedGraphNode(node->label);

	 dict[node] = copy;

	 queue<UndirectedGraphNode *> bfs;

	 bfs.push(node);

	 while (!bfs.empty()) {
		 UndirectedGraphNode * cur = bfs.front(); bfs.pop();

		 for (auto item : cur->neighbors) {
			 if (dict.find(item) == dict.end()) {
				 UndirectedGraphNode * neighbor = new UndirectedGraphNode(item->label);
				 dict[item] = neighbor;
				 bfs.push(item);
			 }

			 dict[cur]->neighbors.push_back(dict[item]);

		 }
	 }

	 return dict[node];
 }