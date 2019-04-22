#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

/*
Given a roman numeral, convert it to an integer.
*/    

/**
 * @param s: Roman representation
 * @return: an integer
 */

vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    // events,   x,   h,   id,  type (1=entering, -1=leaving)
    vector<Event> events;
    
    int id = 0;
    for (const auto& b : buildings) {
        events.push_back(Event{id, b[0], b[2], 1});
        events.push_back(Event{id, b[1], b[2], -1});
        ++id;
    }
    
        
    // Sort events by x
    sort(events.begin(), events.end());
    
    // Init the multiset
    hs_.clear();
    
    vector<pair<int, int>> ans;
    
    // Process all the events
    for (const auto& event: events) {            
        int x = event.x;
        int h = event.h;
        int id = event.id;
        int type = event.type;            
        
        if (type == 1) {
            if (h > this->maxHeight()) 
                ans.emplace_back(x, h);
            hs_.insert(h);
        } else {
            hs_.erase(hs_.equal_range(h).first);
            if (h > this->maxHeight())
                ans.emplace_back(x, this->maxHeight());
        }            
    }
    
    return ans;
}


int maxHeight() const {
    if (hs_.empty()) return 0;
    return *hs_.rbegin();
}

multiset<int> hs_;

struct Event {
    int id;
    int x;       
    int h;
    int type;
    
    // sort by x+, type-, h, 
    bool operator<(const Event& e) const {
        if (x == e.x)                
            // Entering event h from large to small
            // Leaving event h from small to large
            return type * h > e.type * e.h;
        
        return x < e.x;
    }
};