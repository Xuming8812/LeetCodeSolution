#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;


/*
Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) 
such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points 
are all in the range [-10000, 10000] (inclusive).
*/

/**
 * @param points: a 2D array
 * @return: the number of boomerangs
 */
int numberOfBoomerangs(vector<vector<int>> &points) {
    // Write your code here
    
    int result = 0;
    //loop all points
    for (int i = 0; i < points.size(); i++) {
        //the number of each distance
        map<int, int> disCount;
        //loop all points
        for (int j = 0; j < points.size(); j++) {
            if (i == j) {
                continue;
            }
            //get distance of each combination
            disCount[getDistance(points[i], points[j])]++;
        }
        
        for(auto item : disCount){
            result += item.second*(item.second-1);
        }

    }
    return result;
    
    
}
//the function to get the distance between two points
int getDistance(vector<int> &a, vector<int> &b) {
    int dx = a[0] - b[0];
    int dy = a[1] - b[1];
    
    return dx * dx + dy * dy;
}