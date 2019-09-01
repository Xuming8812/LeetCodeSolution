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
Given a collection of intervals, merge all overlapping intervals.
*/

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};



/**
 * @param intervals: interval list.
 * @return: A new interval list.
 */
static bool compare(const Interval& a, const Interval& b){
    if(a.start<b.start){
        return true;
    }else if(a.start == b.start){
        return a.end<b.end;
    }else{
        return false;
    }
        
} 

vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> result;
    //corner case
    if(intervals.empty()) return result;
    //sort the interval by start then end
    sort(intervals.begin(),intervals.end(),compare);
    //get first interval and set it as the interval to be merged
    Interval current = intervals[0];
    //merge all others
    for(int i = 1;i<intervals.size();i++){
        //if two intervals overlaps
        if(intervals[i].start<=current.end){
            //update the current interval
            current.end = max(current.end,intervals[i].end);
        }
        else{
            //save the current interval
            result.push_back(current);
            //update the interval
            current= intervals[i];
        }
    }
    //save the last interval
    result.push_back(current);
    
    return result;
}