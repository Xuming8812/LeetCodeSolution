#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;


/*
A normal word never contains two or more consecutive letters. We call a substring is a twitch if three or more letters in the word are consecutive. 
Now given a word and output the start points and the end points of all the twitch from left to right.
*/

/**
 * @param str: the origin string
 * @return: the start and end of every twitch words
 */
vector<vector<int>> twitchWords(string &str) {
    // Write your code here
    
    vector<vector<int>> result;
    
    int index=0;
    //loop each char
    while(index<str.size()){
        //get current char
        char current = str[index];
        //loop for same chars
        int end = index+1;
        while(end<str.size() && str[end] == current){
            end++;
        }
        //when the length is greater than 2
        if(end>index+2){
            result.push_back({index,end-1});
        }
        
        index = end;
    }
    
    return result;
}