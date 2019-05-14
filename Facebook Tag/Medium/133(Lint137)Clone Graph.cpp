#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors. Nodes are labeled uniquely.

You need to return a deep copied graph, which has the same structure as the original graph, 
and any changes to the new graph will not have any effect on the original graph.
*/

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};


/*
 * @param node: A undirected graph node
 * @return: A undirected graph node
 */
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    //corner case
    if(!node) return nullptr;
    //save the node and its copy in a hash map
    map<UndirectedGraphNode *, UndirectedGraphNode *>dict;
    //copy the root
    UndirectedGraphNode* copy = new UndirectedGraphNode(node -> label);
    //save the copy of given node
    dict[node] = copy;
    //bfs
    queue<UndirectedGraphNode *> bfs;
    
    bfs.push(node);
    //bfs
    while(!bfs.empty()){
        //get current node in the queue
        UndirectedGraphNode * cur = bfs.front();bfs.pop();
        //search all neighbors                        
        for(auto item : cur->neighbors){
            //if not saved in the hashmap
            if(dict.find(item) == dict.end()){
                //copy this node and save in the hashmap
                UndirectedGraphNode * neighbor = new UndirectedGraphNode(item->label);
                dict[item] = neighbor;
                //push this node in the queue
                bfs.push(item);
            }
            //save the neighbor of the copied node                
            dict[cur]->neighbors.push_back(dict[item]);
            
        }
    }
    
    return dict[node];
}