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
Given a string source and a string target, find the minimum window in source which will contain all the characters in target.
*/ 

/**
 * @param source : A string
 * @param target: A string
 * @return: A string denote the minimum window, return "" if there is no such a string
 */
string minWindow(string &source , string &target) {
    // write your code here
    string result;
    
    int length = INT_MAX;
    //corner case
    if(source.empty()||target.empty()){
        return result;
    }
    //use a hashmap to store chars and their number
    map<char,int> dict;
    //count each char
    for(int i=0;i<target.size();i++){
        dict[target[i]]++;
    }
    //total number of different chars
    int count = dict.size();
    //left and right edge pointer of the window
    int left{0},right{0};
    
    //move the window to right
    while(right<source.size()){
        //get current char
        char rightChar = source[right];
        //if the current char is included in the target string
        if(dict.find(rightChar)!=dict.end()){
            //the number of this number substract 1
            dict[rightChar]--;
            //if all char appears, decrease the number of different chars
            if(dict[rightChar]==0){
                count --;
            }
        }
        //move the window to right
        right++;
        //when all chars in target string appeared in the window
        while(count == 0){
            //see if the minimum window
            if((right-left)<length){
                length = right - left;
                result = source.substr(left,length);
            }
            //get the left char of the window
            char leftChar = source[left];
            //if the left char is in target string
            if(dict.find(leftChar)!=dict.end()){
                //increase the count of the char
                dict[leftChar]++;
                //if the window is not big enough, should exit the while loop and move window to right
                if(dict[leftChar]==1){
                    count++;
                }
            }
            //move the window to right
            left++;
        }
    }
    
    return result;
}