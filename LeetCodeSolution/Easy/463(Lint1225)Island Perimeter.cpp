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
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. 
Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, 
and there is exactly one island (i.e., one or more connected land cells).
 The island doesn't have "lakes" (water inside that isn't connected to the water around the island).
 One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. 
 Determine the perimeter of the island.
*/


/**
 * @param grid: a 2D array
 * @return: the perimeter of the island
 */
int islandPerimeter(vector<vector<int>> &grid) {
    // Write your code here
    //corner case
    if(grid.empty()){
        return 0;
    }
    //directions of neighbours
    vector<int> dx{-1,1,0,0};
    vector<int> dy{0,0,-1,1};
    //get size of the grid
    int rowNum = grid.size();
    int colNum = grid[0].size();
    
    int result = 0;
    //loop all positions
    for(int row=0;row<rowNum;row++){
        for(int col = 0;col<colNum;col++){
            //if a part of island
            if(grid[row][col] == 1){
                //add 4 edges
                result+=4;
                //check if its neighbour is also part of island, result--
                for(int i = 0;i<4;i++){
                    int y=row+dy[i];
                    int x=col+dx[i];
                    
                    if(y>=0 && y<rowNum && x>=0 && x<colNum){
                        if(grid[y][x] == 1){
                            result--;
                        }
                    }
                }
            }
        }
    }
    
    return result;
}