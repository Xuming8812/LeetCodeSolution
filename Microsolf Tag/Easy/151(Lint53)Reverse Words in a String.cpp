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
Given an input string, reverse the string word by word.
*/

/*
* @param s: A string
* @return: A string
*/
string reverseWords(string &s) {
    // write your code here
    string result;
    
    if(s.empty()){
        return result;
    }
    
    vector<string> words = split(s);
    
    if(words.empty()){
        return result;
    }
    
    while(!words.empty()){
        string temp = words.back();
        words.pop_back();
        result = result+" "+temp;
    }
    
    return result.substr(1);
}

vector<string> split(string &s){
    vector<string> result;
    
    int index=0;
    
    while(index<s.size()){
        if(s[index] == ' '){
            index++;
        }
        else{
            int current = index;
            
            while(current<s.size() && s[current]!=' '){
                current++;
            }
            
            string temp = s.substr(index,current-index);
            
            result.push_back(temp);
            
            index = current;
        }
    }
    
    return result;
}


//stringstream version
void reverseWords(string &s) {
    stringstream ss;
    
    ss<<s;
    string temp;
    string result;
    while(ss>>temp){
        result = temp+" "+result;
    }
    
    s = result.substr(0,result.size()-1);
}