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
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 40,000.
The order of output does not matter.
*/   

/**
 * @param s: a string
 * @param p: a string
 * @return: a list of index
 */
vector<int> findAnagrams(string &s, string &p) {
    // write your code here
    vector<int> result;
    
    if(s.empty() || s.size()<p.size()){
        return result;
    }
    
    map<int,int>dict;
    
    for(auto item : p){
        dict[item]++;
    }
    
    int start=0,end=0,matched=0;
    
    while(end<s.size()){
        if(dict[s[end]]>=1){
            matched++;
        }
        
        dict[s[end]]--;
        
        end++;
        
        if(matched == p.size()){
            result.push_back(start);
        }
        
        if(end-start==p.size()){
            if(dict[s[start]]>=0){
                matched--;
            }
            
            dict[s[start]]++;
            
            start++;
        }        
    }
    
    return result;
}