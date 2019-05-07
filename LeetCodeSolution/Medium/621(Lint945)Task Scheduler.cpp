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
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.
Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, 
there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.
*/    
    
/**
 * @param tasks: the given char array representing tasks CPU need to do
 * @param n: the non-negative cooling interval
 * @return: the least number of intervals the CPU will take to finish all the given tasks
 */
int leastInterval(string &tasks, int n) {
    // write your code here
    
    map<char,int>dict;
    //calculate the number of each task and find the one with largest number
    int count = 0;
    for(auto c : tasks) {
        dict[c]++;
        count = max(count, dict[c]);
    }
    
    int ans = (count - 1) * (n + 1);
    //for each task with the same number of the most task, add it to the back
    for(auto item : dict) {
        if(item.second == count) {
            ans ++;
        }
    }
    return max((int)tasks.size(), ans);
}