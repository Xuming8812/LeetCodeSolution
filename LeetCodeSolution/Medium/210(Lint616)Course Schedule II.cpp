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
    // the vector the store the number of prerequisites for each cource
    vector<int> preCount(numCourses);
    //store the graph, all neighbors that linked to this vertex, basically all courses take the current course as prerequisites
    vector<set<int>> preGraph(numCourses);
    
    //loop all edges of the graph
    for(auto item : prerequisites){
        //store the graph
        preGraph[item.second].insert(item.first);
        //record the number of prerequisites of a course
        preCount[item.first]++;
    }
    //bfs
    queue<int> bfs;
    
    //push all courses that don't need any prerequisites into queue as starting point
    for(int i=0;i<numCourses;i++){
        if(preCount[i] == 0){
            bfs.push(i);
        }
    }
    
    vector<int> result;
    //bfs
    while(!bfs.empty()){
        //get current course
        int course = bfs.front();
        bfs.pop();
        //save it in the result vector
        result.push_back(course);
        //for all courses that take this course as prerequisites, the number of prerequisites should be substracted by 1
        for(auto item : preGraph[course]){
            preCount[item]--;
            //push the course that doesn't need any prerequisites
            if(preCount[item]==0){
                bfs.push(item);
            }
        }
    }
    
    //see if all courses can be taken
    if(result.size()==numCourses){
        return result;
    }
    else{
        return {};
    }        
}