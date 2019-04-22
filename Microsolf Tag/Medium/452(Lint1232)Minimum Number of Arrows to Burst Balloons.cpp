#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

/*
There are a number of spherical balloons spread in two-dimensional space. 
For each balloon, provided input is the start and end coordinates of the horizontal diameter. 
Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice. 
Start is always smaller than end. There will be at most 10^4 balloons.

An arrow can be shot up exactly vertically from different points along the x-axis. 
A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. 
There is no limit to the number of arrows that can be shot. An arrow once shot keeps travelling up infinitely. 
The problem is to find the minimum number of arrows that must be shot to burst all balloons.
*/      

/**
 * @param points: a 2D array
 * @return: the minimum number of arrows that must be shot to burst all balloons
 */
int findMinArrowShots(vector<vector<int>> &points) {
    // Write your code here
    if (points.size() == 0) {
        return 0;
    }
    //sort points by its end 
    sort(points.begin(), points.end(), cmp);
    
    int ans = 1;
    //use a variable to store the current right edge
    int lastEnd = points[0][1];
    for (int i = 1; i < points.size(); i++) {
        //if the current start is greater than the edge, update the right edge, result++
        if (points[i][0] > lastEnd) {
            ans++;
            lastEnd = points[i][1];
        }
    }
    return ans;
}

//compare funtion for points to sort
static bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[1] < b[1];
}