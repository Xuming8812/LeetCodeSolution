#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;


/*
Given a string target and a string array s, 
output all strings containing target(ie target is a subsequence of s[i]) in their original order in the array s
*/

/**
 * @param target: the target string
 * @param s: 
 * @return: output all strings containing target  in s
 */
vector<string> getAns(string &target, vector<string> &s) {
    // Write your code here
    vector<string> result;
    //corner case
    if(s.empty()){
        return result;
    }
    //loop all given strings to get the result
    for(auto item : s){
        if(isContain(item,target)){
            result.push_back(item);
        }
    }
    
    return result;   
}
//helper function to see if the current string contain the target string
bool isContain(string input,string target)
{
    //corner case
    if(input.size()<target.size()){
        return false;
    }
    //the pointer for target string
    int index = 0;
    //loop each char in input string
    for(int i = 0;i<input.size();i++){
        //find the char in the target string
        if(input[i] == target[index]){
            //move the target pointer
            index++;
            //find all the chars in the target string
            if(index == target.size()){
                return true;
            }
        }
    }
    
    return false;
}