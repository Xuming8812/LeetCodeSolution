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
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
determine if a person could attend all meetings.
*/  

class Interval {
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};
    
    
/**
 * @param intervals: an array of meeting time intervals
 * @return: if a person could attend all meetings
 */
bool canAttendMeetings(vector<Interval>&intervals) {
    // Write your code here
    if(intervals.empty()){
        return true;
    }
    
    //use a ordered map to store event
    map<int,int> store;
    
    for(int i = 0;i<intervals.size();i++){
        store[intervals[i].start]++;
        store[intervals[i].end]--;
    }
    
    //check all events, return if count>1
    int count{0};
    for(auto item : store){
        count+=item.second;
        if(count >1){
            return false;
        }
    }
    
    return true;
}