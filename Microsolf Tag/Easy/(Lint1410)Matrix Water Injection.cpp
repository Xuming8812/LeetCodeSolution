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
Given a two-dimensional matrix, the value of each grid represents the height of the terrain. 
The flow of water will only flow up, down, right and left, and it must flow from the high ground to the low ground. 
As the matrix is surrounded by water, it is now filled with water from (R,C) and asked if water can flow out of the matrix.
*/


/**
 * @param matrix: the height matrix
 * @param R: the row of (R,C)
 * @param C: the columns of (R,C)
 * @return: Whether the water can flow outside
 */
string waterInjection(vector<vector<int>> &matrix, int R, int C) {
    // Write your code here
    
    if(matrix.empty()){
        return "YES";
    }
    
    bool result = dfs(matrix,R,C);
    if(result){
        return "YES";
    }
    else{
        return "NO";
    }
}

bool dfs(vector<vector<int>> &matrix, int R, int C){
    if(R<=0 || R>=matrix.size()-1 || C<=0 || C>=matrix[0].size()-1){
        return true;
    }
    
    vector<int> dx{-1,1,0,0};
    vector<int> dy{0,0,1,1};
    
    bool result = false;
    
    for(int i = 0;i<4;i++){
        int row = R + dy[i];
        int col = C + dx[i];
        
        if(matrix[row][col]<matrix[R][C]){
            result = result || dfs(matrix, row,col);
        }
    }
    
    return result;
}