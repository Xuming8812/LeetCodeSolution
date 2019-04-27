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
Given two rectangles, find if the given two rectangles overlap or not.
*/  
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};    
    
/**
 * @param l1: top-left coordinate of first rectangle
 * @param r1: bottom-right coordinate of first rectangle
 * @param l2: top-left coordinate of second rectangle
 * @param r2: bottom-right coordinate of second rectangle
 * @return: true if they are overlap or false
 */
bool doOverlap(Point &l1, Point &r1, Point &l2, Point &r2) {
    // write your code here
    
    return r1.x>=l2.x && r2.x>=l1.x && l2.y>=r1.y && l1.y>=r2.y;
}