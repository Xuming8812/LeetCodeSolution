#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;


/*
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "lintcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
*/

/**
 * @param word: a string
 * @return: return a boolean
 */
bool detectCapitalUse(string &word) {
    // write your code here
    //the number of capital letter
    int count{0};
    //bool that if the first letter is capitcal
    bool firstCaptical = (word[0]-'A'>=0&&word[0]-'A'<=25)?true:false;
    //count the number of capital number 
    for(int i = 1;i<word.size();i++){
        if(word[i]-'A'>=0&&word[i]-'A'<=25){
            count++;
        }
    }
    
    if(firstCaptical){
        //first capital or all capital
        if(count == 0 || count == word.size()-1){
            return true;
        }
    }
    else{
        //no capital
        if(count == 0){
            return true;
        }
    }
    
    return false;
}