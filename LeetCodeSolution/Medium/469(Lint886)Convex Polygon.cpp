#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given a list of points that form a polygon when joined sequentially, find if this polygon is convex
*/

/**
 * @param point: a list of two-tuples
 * @return: a boolean, denote whether the polygon is convex
 */
bool isConvex(vector<vector<int>> &points) {
    // write your code here
    //z = x1y2 - x2y1 = |a||b|sin(theta)
    
    int length = points.size();
    int pre = 0;
    int cur = 0;
    //loop all pointes
    for (int i = 0; i < length; ++i) {
        //get next edge
        int dx1 = points[(i + 1) % length][0] - points[i][0];
        int dy1 = points[(i + 1) % length][1] - points[i][1];
        //get next next edge
        int dx2 = points[(i + 2) % length][0] - points[i][0];
        int dy2 = points[(i + 2) % length][1] - points[i][1];
        
        //get current direction
        cur = dx1 * dy2 - dx2 * dy1;
        
        if (cur != 0) {
            //same direction
            if (cur * pre < 0){
                return false;
            } 
            else{
                pre = cur;
            } 
        }
    }
    return true;
}