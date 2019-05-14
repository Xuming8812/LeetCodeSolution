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
Given a non-overlapping interval list which is sorted by start point.

Insert a new interval into it, make sure the list is still in order and non-overlapping (merge intervals if necessary).
*/

class Interval {
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

/**
 * @param intervals: Sorted interval list.
 * @param newInterval: new interval.
 * @return: A new interval list.
 */
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    // write your code here
    
    int index = 0;
    
    vector<Interval> result;
    
    //find all intervals that has a start smaller the given interval
    for(index = 0; index < intervals.size() && intervals[index].start<newInterval.start;index++){
        result.push_back(intervals[index]);
    }
    //try to merge the given interval with last one in the final vector, otherwise save the given interval in the final vector
    if(!result.empty() && result.back().end>=newInterval.start){
        result.back().end = max(result.back().end,newInterval.end);
    }
    else{
        result.push_back(newInterval);
    }
    
    //merge each one from the origal interval vector
    for(;index < intervals.size();index ++){
        //if overlap with last interval, merge interval
        if(result.back().end>=intervals[index].start){
            result.back().end = max(result.back().end,intervals[index].end);
        }
        else{
            //not overlapped, save it directly
            result.push_back(intervals[index]);
        }
    }
    
    return result;
}