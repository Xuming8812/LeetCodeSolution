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
Given a sequence of words, check whether it forms a valid word square. 
A sequence of words forms a valid word square if the k^th row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).
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


bool validWordSquare(vector<string> &words) {
    // Write your code here
    int i = 0;
    for (const string & word : words) {
        for (int j = 0; j < word.length(); ++j) {
            if (j >= words.size()) {
                return false;
            } 
            if (words[j][i] != word[j]) {
                return false;
            }
        }
        ++i;
    }
    return true;
}