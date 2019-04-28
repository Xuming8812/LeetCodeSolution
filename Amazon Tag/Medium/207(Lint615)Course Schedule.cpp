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
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
*/

/*
* @param numCourses: a total of n courses
* @param prerequisites: a list of prerequisite pairs
* @return: true if can finish all courses or false
*/
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<set<int>> graph(numCourses);
    vector<int> visited(numCourses);
    
    for(auto item : prerequisites){
        graph[item.second].insert(item.first);
        visited[item.first]++;
    }
    
    queue<int> bfs;
    
    for(int i = 0;i<numCourses;i++){
        if(visited[i] == 0){
            bfs.push(i);
        }
    }
    
    int result{0};
    
    while(!bfs.empty()){
        int cur = bfs.front();bfs.pop();
        
        result++;
        
        for(auto item : graph[cur]){
            
            visited[item]--;
            
            if(visited[item] == 0){
                bfs.push(item);
            }
            
        }
    }
    
    return result == numCourses;  
}