#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/    
    
    
/**
 * @param s: The first string
 * @param t: The second string
 * @return: true or false
 */
bool anagram(string &s, string &t) {
    // write your code here
    
    if(s.size()!=t.size()){
        return false;
    }
    
    vector<int> dict(256,0);
    
    for(auto c : s){
        dict[c] ++;
    }
    
    for(auto c : t){
        dict[c]--;
    }
    
    for(auto item : dict){
        if(item != 0 ){
            return false;
        }
    }
    
    return true;
}