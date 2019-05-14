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
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 2^31 - 1 = 2147483647 to represent INF 
as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a ROOM, that room should remain filled with INF
*/    


/**
 * @param rooms: m x n 2D grid
 * @return: nothing
 */
void wallsAndGates(vector<vector<int>> &rooms) {
    // write your code here
    
    int rowNum = rooms.size(), colNum = rooms[0].size();
    
    //corner case
    if(rowNum==0 || colNum == 0){
        return;
    }
    //use a queue to store the position coordinate
    queue<vector<int>> bfs;
    //push all gates coordinates into queue as start points
    for(int i = 0;i<rowNum; i++){
        for(int j = 0;j <colNum; j++ ){
            if(rooms[i][j] == 0){
                bfs.push({i,j});
            }
        }
    }
    //the neighbor directions
    vector<vector<int>> direction{{0,1},{0,-1},{1,0},{-1,0}};
    
    //bfs
    while(!bfs.empty()){
        //get the number of positions with the same distance
        int length = bfs.size();
        
        for(int i = 0;i<length;i++){
            //get current position
            vector<int> current = bfs.front();
            bfs.pop();
            
            int row = current[0], col = current[1];
            //get the distance to gate
            int dist = rooms[row][col];
            //loop all neighbors
            for(auto item : direction){
                int offsetRow = item[0];
                int offsetCol = item[1];
                //if the neighbor is a valid position
                if(row+offsetRow>=0 && row+offsetRow< rowNum && col + offsetCol>=0 && col + offsetCol< colNum){
                    //if need to update the distance
                    if(rooms[row+offsetRow][col + offsetCol]>dist){
                        //update distance
                        rooms[row+offsetRow][col + offsetCol] = dist+1;
                        //push into queue
                        bfs.push({row+offsetRow,col + offsetCol});
                    }
                }
            }
        }
    }
}