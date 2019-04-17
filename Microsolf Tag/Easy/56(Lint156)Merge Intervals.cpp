#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<bitset>

using namespace std;

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

/*
Given a collection of intervals, merge all overlapping intervals.
*/

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
    
    if(intervals.empty()) return result;
    
    sort(intervals.begin(),intervals.end(),compare);
    
    Interval current = intervals[0];
    
    
    
    for(int i = 1;i<intervals.size();i++){
        if(intervals[i].start<=current.end){
            current.end = max(current.end,intervals[i].end);
        }
        else{
            result.push_back(current);
            current= intervals[i];
        }
    }
    
    result.push_back(current);
    
    return result;
}