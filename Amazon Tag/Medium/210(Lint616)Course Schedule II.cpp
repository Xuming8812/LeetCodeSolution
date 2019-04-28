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
There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
*/

/*
* @param numCourses: a total of n courses
* @param prerequisites: a list of prerequisite pairs
* @return: the course order
*/
vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
    // write your code here
    vector<int> preCount(numCourses);
    vector<set<int>> preGraph(numCourses);
    
    for(auto item : prerequisites){
        preGraph[item.second].insert(item.first);
        preCount[item.first]++;
    }
    
    queue<int> bfs;
    
    for(int i=0;i<numCourses;i++){
        if(preCount[i] == 0){
            bfs.push(i);
        }
    }
    
    vector<int> result;
    
    
    while(!bfs.empty()){
        int course = bfs.front();
        bfs.pop();
        
        result.push_back(course);
        
        for(auto item : preGraph[course]){
            preCount[item]--;
            if(preCount[item]==0){
                bfs.push(item);
            }
        }
    }
    
    if(result.size()==numCourses){
        return result;
    }
    else{
        return {};
    }        
}