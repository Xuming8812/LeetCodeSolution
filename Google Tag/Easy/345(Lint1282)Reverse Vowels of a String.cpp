#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;


/*
Write a function that takes a string as input and reverse only the vowels of a string.
*/


/**
 * @param s: a string
 * @return: reverse only the vowels of a string
 */
string reverseVowels(string s) {
    //two pointer
    int left = 0, right=s.size()-1;
    
    while(left<right){
        //if the left char and right char are both vowels
        if(isVowels(s[left]) && isVowels(s[right])){
            swap(s[left++],s[right--]);
            continue;
        }
        //move left point to next vowel
        while(!isVowels(s[left]) && left<right){
            left++;
        }
        //move right pointer to next vowel
        while(!isVowels(s[right]) && left<right){
            right--;
        }
    }
    
    return s;
}
//the helper function to see if a char is a vowel
bool isVowels(char c){
    char temp = tolower(c);
    
    if(temp == 'a' || temp == 'e' || temp == 'i'||temp == 'o'||temp == 'u'){
        return true;
    }
    
    return false;
}