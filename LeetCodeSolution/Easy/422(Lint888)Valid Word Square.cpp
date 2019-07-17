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
Given a string s which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. 
You must make sure your result is the smallest in lexicographical order among all possible results.
*/    
    
/**
 * @param words: a list of string
 * @return: a boolean
 */
bool validWordSquare(vector<string> &words) {
    // Write your code here
    //corner case
    if(words.size()!=words[0].size()){
        return false;
    }
    //loop the upper matrix
    for(int i =0;i<words.size();i++){
        for(int j = i;j<words.size();j++){
            
            if(words[i][j]!=words[j][i]){
                return false;
            }
        }
    }
    
    return true;
}