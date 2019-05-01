#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
There are two properties in the node student id and scores, 
to ensure that each student will have at least 5 points, find the average of 5 highest scores for each person.
*/ 

    
/**
 * @param results a list of <student_id, score>
 * @return find the average of 5 highest scores for each person
 * map<int, double> (student_id, average_score)
 */
map<int, double> highFive(vector<Record>& results) {
    // Write your code here
    map<int,priority_queue<int>> records;
    
    for(auto item : results){
        records[item.id].push(-item.score);
        
        if(records[item.id].size()>5){
            records[item.id].pop();
        }
    }
    
    map<int, double> answer;
    
    for(auto item : records){
        double sum = {0};
        
        while(!item.second.empty()){
            int temp = item.second.top();
            
            sum += temp;
            
            item.second.pop();
        }
        
        sum = -sum/5.0;
        answer[item.first] = sum;
    }
    
    return answer;
}