#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<unordered_map>

using namespace std;

/*
Given some points and an origin point in two-dimensional space, find k points which are nearest to the origin.
Return these points sorted by distance, if they are same in distance, sorted by the x-axis, and if they are same in the x-axis, sorted by y-axis.
*/

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

Point global_origin;

long long getDistance(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

struct compare {  
    bool operator()(const Point &a, const Point &b) const {  
        int diff = getDistance(a, global_origin) - getDistance(b, global_origin);
        if (diff == 0)
            diff = a.x - b.x;
        if (diff == 0)
            diff = a.y - b.y;
        return diff < 0;
    }  
};


/**
 * @param points: a list of points
 * @param origin: a point
 * @param k: An integer
 * @return: the k closest points
 */

vector<Point> kClosest(vector<Point> &points, Point &origin, int k) {
    // write your code here
        priority_queue<Point, vector<Point>, compare> pq;
        global_origin = Point(origin.x, origin.y);
        
    int n = points.size();
    
    for (int i = 0; i < n  ; i++) {
        Point p = points[i];
        pq.push(p);
        if (pq.size() > k)
            pq.pop();
    }

    vector<Point> ret;
    while (!pq.empty()) {
        Point p = pq.top();
        ret.push_back(p);
        pq.pop();
    }

    reverse(ret.begin(), ret.end());
    return ret;
    
    
}


//leetcode version

struct cmp{
    bool operator()(vector<int>&a, vector<int>&b){
        return a[0]*a[0]+a[1]*a[1]<b[0]*b[0]+b[1]*b[1];
    };
    
};


vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
    
    for(auto item : points){
        pq.push(item);
        if(pq.size()>K){
            pq.pop();
        }
    }
    
    vector<vector<int>> result;
    
    while(!pq.empty()){
        result.push_back(pq.top());
        pq.pop();
    }
    
    return result;
}  