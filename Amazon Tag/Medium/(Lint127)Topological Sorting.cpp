#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<unordered_map>

using namespace std;

/*
Given an directed graph, a topological order of the graph nodes is defined as follow:

For each directed edge A -> B in graph, A must before B in the order list.
The first node in the order can be any node in the graph with no nodes direct to it.
Find any topological order for the given graph.
*/


struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};

/*
* @param graph: A list of Directed graph node
* @return: Any topological order for the given graph.
*/
vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
    queue<DirectedGraphNode*> q;
    unordered_map<DirectedGraphNode*, int> m;
    vector<DirectedGraphNode*> answer;
    
    // First round
    for(auto node : graph){
        for(auto neighbor : node->neighbors){
            m[neighbor] += 1;
        }
    }
    
    // Check for zero
    for(auto node : graph){
        if(m[node] == 0){
            q.push(node);
            answer.push_back(node);
        }
    }
    
    // Second round
    while(!q.empty()){
        DirectedGraphNode *curr = q.front();
        q.pop();
        for(auto neighbor : curr->neighbors){
            m[neighbor] -= 1;
            if(m[neighbor] == 0){
                q.push(neighbor);
                answer.push_back(neighbor);
            }
        }
    }
    
    return answer;
}