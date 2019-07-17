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
Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.
*/


/**
 * @param points: n points on a 2D plane
 * @return: if there is such a line parallel to y-axis that reflect the given points
 */
bool isReflected(vector<vector<int>> &points) {
    // Write your code here
    //corner case
    if(points.empty()){
        return true;
    }
    
    map<int,set<int>> xCoor;
    
    double middle;
    //save each point's x coor and y coor
    for(auto point : points){
        middle+=point[0];
        xCoor[point[0]].insert(point[1]);
    }
    //calculate the middle coordinate
    middle = middle/points.size();
    //for each point, see if the reflected point exists
    for(auto point : points){
        int t = 2 * middle - point[0];
        
        if(xCoor.count(t)==0 || xCoor[t].count(point[1]) == 0){
            return false;
        }
    }
    
    return true;
}