#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<unordered_set>

using namespace std;

/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), 
write a function to check whether these edges make up a valid tree.
*/


/**
 * @param n: An integer
 * @param edges: a list of undirected edges
 * @return: true if it's a valid tree, or false
 */
bool validTree(int n, vector<vector<int>> &edges) {
    // write your code here
    
    //use this to store the graph
    vector<unordered_set<int>> g(n, unordered_set<int>());
    //the visited set
    unordered_set<int> visited;
    
    //bfs
    queue<int> q;
    //start with 0
    q.push(0);
    visited.insert(0);
    //undirected map
    for (auto a : edges) {
        g[a[0]].insert(a[1]);
        g[a[1]].insert(a[0]);
    }
    //bfs
    while (!q.empty()) {
        
        int t = q.front(); q.pop();
        //loop all neighbors
        for (auto a : g[t]) {
            //if make a circle
            if (visited.find(a) != visited.end()) return false;
            //store 
            visited.insert(a);
            q.push(a);
            g[a].erase(t);
        }
    }
    return visited.size() == n;
}