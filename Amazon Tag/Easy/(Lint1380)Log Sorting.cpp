#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given a list of string logs, in which each element representing a log. Each log can be separated into two parts by the first space. 
The first part is the ID of the log, while the second part is the content of the log. (The content may contain spaces as well.) 
The content is composed of only letters and spaces, or only numbers and spaces.

Now you need to sort logs by following rules:

Logs whose content is letter should be ahead of logs whose content is number.
Logs whose content is letter should be sorted by their content in lexicographic order. And when two logs have same content, 
sort them by ID in lexicographic order.
Logs whose content is number should be in their input order.
*/    

//the data structure to define a log, and override the <
struct component{
    string id;
    string content;
    int index;
    int type;
    
    friend bool operator < (component a, component b){
        if(a.type == 2 && b.type == 2){
            return a.index<b.index;
        }
        if(a.type == 1 && b.type == 1){
            if(a.content!=b.content){
                return a.content<b.content;
            }
            
            return a.id<b.id;
        }
        
        return a.type<b.type;
    }
};


/**
 * @param logs: the logs
 * @return: the log after sorting
 */
vector<string> logSort(vector<string> &logs) {
    // Write your code here
    
    vector<string> output;
    vector<component> components;
    //store each log's content type, id and index
    for(int i = 0; i<logs.size();i++){
        component temp;
        temp.index = i;
        //find the " "
        int index = 0;
        for(;index<logs[i].size();index++){
            if(logs[i][index]==' '){
                break;
            }
        }
        //get id and content
        temp.id = logs[i].substr(0,index);
        temp.content = logs[i].substr(index+1);
        //get the type
        if(logs[i][index+1]>='0' && logs[i][index+1]<='9'){
            temp.type = 2;
        }
        else{
            temp.type = 1;
        }
        
        components.push_back(temp);
        
    }
    
    //sort the log by given rules
    sort(components.begin(),components.end());
    //save the result
    for(auto item : components){
        output.push_back(item.id+" "+item.content);
    }
    
    return output;
    
}