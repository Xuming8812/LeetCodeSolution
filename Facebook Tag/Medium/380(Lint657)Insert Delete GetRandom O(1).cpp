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
Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
*/


class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        
        if(dict.find(val) != dict.end()){
            return false;
        }
        //insert the val into the vector
        data.push_back(val);
        //save the index of this value in the dict
        dict[val] = data.size()-1;
        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        //corner case
        if(dict.find(val) == dict.end()){
            return false;
        }
        //get the index of the value
        int index = dict[val];
        //override this value by the last value of the vector
        data[index] = data[data.size()-1];
        //override the last value`s index
        dict[data[index]] = index;
        //pop back the last value
        data.pop_back();
        //remove the val from dict
        dict.erase(val);
        
        return true;
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        //corner case
        if(data.empty()) return -1;
        if(data.size() == 1) return data[0];
        //generate a random index
        int index = rand()%data.size();
        
        return data[index];
    }
    
private:
    
    vector<int> data;
    map<int,int> dict;
    
};