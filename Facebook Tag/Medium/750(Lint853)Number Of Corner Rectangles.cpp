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
Given a grid with only 0 and 1, find the number of corner rectangles.

Note that only the corners need to have the value 1. Also, all four 1s used must be distinct.
*/

/**
 * @param grid: the grid
 * @return: the number of corner rectangles
 */
int countCornerRectangles(vector<vector<int>> &grid) {
    // Write your code here
    
    int result{0};
    //corner case
    if(grid.empty()||grid[0].empty()){
        return result;
    }
    //loop every two rows
    for(int i = 0;i<grid.size();i++){
        for(int j = i+1;j<grid.size();j++){
            //count the number of 1 on same column
            int count{0};
            
            for(int k = 0;k<grid[0].size();k++){
                if(grid[i][k]==1 && grid[j][k] == 1){
                    count++;
                }
            }
            //combination
            result += count*(count-1)/2;
        }
    }
    
    return result;    
}