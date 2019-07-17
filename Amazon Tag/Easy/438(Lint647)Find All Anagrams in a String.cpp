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
    //corner case
    if(s.empty() || s.size()<p.size()){
        return result;
    }
    //the hashset the store the number of each letter of given string p
    map<int,int>dict;
    //count the number of each letter in string p
    for(auto item : p){
        dict[item]++;
    }
    //sliding window pointers
    int start=0,end=0,matched=0;
    //slide window
    while(end<s.size()){
        //count the matching numbers start from "start" index
        if(dict[s[end]]>=1){
            matched++;
        }
        //move window right
        dict[s[end]]--;
        
        end++;
        //if the matching number equals to p.size(), mean the substring is a anargram of p
        if(matched == p.size()){
            result.push_back(start);
        }
        //move the window left
        if(end-start==p.size()){
            if(dict[s[start]]>=0){
                matched--;
            }
            //move the window left
            dict[s[start]]++;
            
            start++;
        }        
    }
    
    return result;
}