#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given the running logs of n functions that are executed in a nonpreemptive single threaded CPU, find the exclusive time of these functions.

Each function has a unique id, start from 0 to n-1. A function may be called recursively or by another function.

A log is a string has this format : function_id:start_or_end:timestamp. For example, 0:start:0 means function 0 starts from the very 
beginning of time 0. 0:end:0 means function 0 ends to the very end of time 0.

Exclusive time of a function is defined as the time spent within this function, the time spent by calling other functions 
should not be considered as this function's exclusive time. You should return the exclusive time of each function sorted by their function id.
*/

/**
 * @param n: a integer
 * @param logs: a list of integers
 * @return: return a list of integers
 */
vector<int> exclusiveTime(int n, vector<string> &logs) {
    // write your code here
    
    stack<vector<int>> store;
    
    vector<int> result(n, 0);
    
    int last = 0;
    
    for(auto item : logs){
        //get the id, time and type of this log
        vector<int> temp = getIDandTime(item);
        //if it`s a start event
        if(temp[2] == 0){
            //add the exclusiveTime for last program
            if(!store.empty()){
                result[store.top()[0]] += temp[1] - last - 1;
            }
            //save the current start of a function into the stack
            store.push(temp);
            
            //update the start time of the current function
            last = temp[1]-1;
        }
        else{
            //get the start of this function
            vector<int>  currentStart = store.top();
            store.pop();
            //add the exclusiveTime for last program
            result[currentStart[0]]+= temp[1] - last;
            //update the start time of the current function
            last = temp[1];
            
        }
    }

    return result;
}


//helper function to get the id ,time and type, 0 for start, 1 for end
vector<int> getIDandTime(string logs){
    stringstream ss;
    ss<<logs;
    
    vector<int> result;
    
    vector<string> split;
    string temp;
    
    while(getline(ss,temp,':')){
        split.push_back(temp);
    }
    
    result.push_back(stoi(split[0]));
    result.push_back(stoi(split[2]));
    
    if(split[1] == "start"){
        result.push_back(0);
    }
    else{
        result.push_back(1);
    }
    
    return result;
}

