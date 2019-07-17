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

//another version of sliding window
vector<int> findAnagrams(string s, string p){
	if (s.size() < p.size()||p.empty()){
		return {};
	}

	map<char, int> dict;
	vector<int> result;
	//count number of each char
	for (auto c : p){
		dict[c]++;
	}
	//the number of unique characters
	int count = dict.size();

	//left and right pointer of the window
	int left = 0, right = 0;
    //slide window
	while (right < s.size()){
		char rightChar = s[right];
		//move right
        dict[rightChar]--;
        if (dict[rightChar] == 0){
            count--;
        }
		right++;
		//the string within the window has same numbers of chars with p
		while (count == 0){
            //the anargram
			if (right - left == p.size()){
				result.push_back(left);
			}

			char leftChar = s[left];

			if (dict.find(leftChar) != dict.end()){
				dict[leftChar]++;
				if (dict[leftChar] == 1){
					count++;
				}
			}
			//move the left side of the window to right
			left++;
		}
	}

	return result;
}