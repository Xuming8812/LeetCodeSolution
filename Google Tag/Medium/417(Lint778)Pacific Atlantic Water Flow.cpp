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
Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, 
the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.
*/


/**
 * @param matrix: the given matrix
 * @return: The list of grid coordinates
 */
vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    
    vector<vector<int>> result;
    
    //corner case
    if (matrix.empty() || matrix[0].empty()){
            return result;
    }
    
    int rowNum = matrix.size();
    int colNum = matrix[0].size();
    
    queue<pair<int, int>> q1, q2;
    
    vector<vector<bool>> pacific(rowNum, vector<bool>(colNum, false)), atlantic = pacific;
    
    //left and right
    for (int i = 0; i < rowNum; ++i) {
        q1.push({i, 0}); 
        q2.push({i, colNum - 1});
        pacific[i][0] = true;
        atlantic[i][colNum - 1] = true;
    }
    //up and bottom
    for (int i = 0; i < colNum; ++i) {
        q1.push({0, i});
        q2.push({rowNum - 1, i});
        pacific[0][i] = true;
        atlantic[colNum - 1][i] = true;
    }
    
    bfs(matrix, pacific, q1);
    bfs(matrix, atlantic, q2);
    
    for (int i = 0; i < rowNum; ++i) {
        for (int j = 0; j < colNum; ++j) {
            if (pacific[i][j] && atlantic[i][j]) {
                result.push_back({i, j});
            }
        }
    }
    
    return result;
    
}

void bfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, queue<pair<int, int>>& q) {
    
    int rowNum = matrix.size(), colNum = matrix[0].size();
    
    vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
    
    while (!q.empty()) {
        auto t = q.front(); 
        q.pop();
        
        for (auto dir : dirs) {
            int x = t.first + dir[0], y = t.second + dir[1];
            
            if (x < 0 || x >= rowNum || y < 0 || y >= colNum){
                continue;
            }
            
            if(visited[x][y] || matrix[x][y] < matrix[t.first][t.second]){
                continue;
            }
            
            visited[x][y] = true;
            q.push({x, y});
        }
    }
}