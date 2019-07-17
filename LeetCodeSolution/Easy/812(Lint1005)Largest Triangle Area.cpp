#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;


/*
You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.
*/


/**
 * @param points: List[List[int]]
 * @return: return a double
 */
double largestTriangleArea(vector<vector<int>>& points) {
    double result{0};
    //brute force
    for(int i=0;i<points.size();i++){
        for(int j = i+1;j<points.size();j++){
            for(int k = j+1;k<points.size();k++){
                
                double area = getArea(points[i],points[j],points[k]);
                
                result = max(result, area);
            }
        }
    }
    
    return result;
}
//helper function to calculate the area of a triangle
double getArea(vector<int> P, vector<int> Q, vector<int> R) {
    return 0.5 * abs(P[0]*Q[1] + Q[0]*R[1] + R[0]*P[1]-P[1]*Q[0] - Q[1]*R[0] - R[1]*P[0]);
}