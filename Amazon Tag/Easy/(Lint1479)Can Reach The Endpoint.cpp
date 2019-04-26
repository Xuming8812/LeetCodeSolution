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
Given a map size of m*n, 1 means space, 0 means obstacle, 9 means the endpoint. You start at (0,0) and return whether you can reach the endpoint.
*/    
    
/**
 * @param map: the map
 * @return: can you reach the endpoint
 */
bool reachEndpoint(vector<vector<int>> &map) {
    // Write your code here
    if(map.empty()) return false;
    if(map[0][0]==0) return false;
    
    queue<vector<int>> bfs;
    
    vector<vector<int>> neighbors{{-1,0},{1,0},{0,-1},{0,1}};
    
    bfs.push({0,0});

    while(!bfs.empty()){
        int currentRow = bfs.front()[0];
        int currentColumn = bfs.front()[1];
        
        if(map[currentRow][currentColumn]==9){return true;}
        
        map[currentRow][currentColumn] = 0;
        
        bfs.pop();
        
        for(int i = 0;i<4;i++){
            int row = currentRow+neighbors[i][0];
            int col = currentColumn+neighbors[i][1];
            
            if(row>=0 && row<map.size() && col>=0 && col<map[0].size()&& map[row][col] !=0){
                bfs.push({row,col});
            }
        }
    }
    
    return false;
    
}