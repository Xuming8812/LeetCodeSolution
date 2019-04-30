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
Given an list interval, which are taking off and landing time of the flight. How many airplanes are there at most at the same time in the sky?
*/ 

class Interval {
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

//sweeping line
class TPoint {
public:
    int time;
    int flag;   // 0 land, 1 take off
    
    TPoint() {}
    
    TPoint(int time, int flag)
        : time(time)
        , flag(flag) {}

    bool operator < (const TPoint& rhs) const {
        return time < rhs.time || (time == rhs.time && flag < rhs.flag); 
    }
};
/**
 * @param airplanes: An interval array
 * @return: Count of airplanes are in the sky.
 */
int countOfAirplanes(vector<Interval> &airplanes) {
    int n = airplanes.size();
    vector<TPoint> p;
    for (int i = 0; i < n; i++)
    {
        p.push_back(TPoint(airplanes[i].start, 1));
        p.push_back(TPoint(airplanes[i].end, 0));
    }
    
    sort(p.begin(), p.end());
    
    int res = 0, cnt = 0;
    for (int i = 0; i < n * 2; i++)
    {
        if (p[i].flag)
            cnt++;
        else
            cnt--;
        res = max(res, cnt);
    }
    
    return res;
}

//ordered map

int countOfAirplanes(vector<Interval> &airplanes) {
    // write your code here
    
    map<int,int>record;
    int result{0};
    
    for(auto item:airplanes){
        record[item.start]++;
        record[item.end]--;
    }
    
    int sum = 0;
    
    for(auto item : record){
        sum += item.second;
        
        if(sum>result){
            result = sum;
        }
    }
    
    return result;
    
}

