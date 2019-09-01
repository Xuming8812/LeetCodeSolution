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
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  
Return a list of all possible strings we could create.
*/ 

//helper function to turn a letter to upper case
char toUpper(char c){
    if(c>='A'&&c<='Z'){
        return c;
    }
    
    return c+'A'-'a';
}

//helper function to turn a letter to lower case
char toLower(char c){
    if(c>='a'&&c<='z'){
        return c;
    }
    
    return c+'a'-'A';        
}

vector<string> result;

/**
 * @param S: a string
 * @return: return a list of strings
 */
vector<string> letterCasePermutation(string &S) {
    // write your code here
    //corner case
    if(S.empty()){
        return {""};
    }
    
    string current;
    //case the helper function
    dfs(S,0,current);
    
    return result;
}
//helper function to do dfs search
void dfs(string &S,int start, string current){
    //base condition
    if(current.size() == S.size()){
        result.push_back(current);    
        return;
    }
    
    //see if current char is a letter
    if(!isdigit(S[start])){
        //turn it to upper case and dfs
        char c = toUpper(S[start]);
        current = current + string(1,c);
        dfs(S,start+1,current);
        
        //turn it to lower case and dfs
        c = toLower(S[start]);
        current = current.substr(0,current.size()-1);
        current = current + string(1,c);
        
        dfs(S,start+1,current);
    }
    else{
        //save current char and dfs
        current = current + string(1,S[start]);
        dfs(S, start + 1, current);
    }
    
}