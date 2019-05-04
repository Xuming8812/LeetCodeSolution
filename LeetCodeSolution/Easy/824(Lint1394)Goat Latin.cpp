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
A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.

For example, the word 'apple' becomes 'applema'.

If a word begins with a consonant (i.e. not a vowel), remove the first letter and append
it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".

Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
Return the final sentence representing the conversion from S to Goat Latin.
*/


/**
 * @param S: 
 * @return: nothing
 */
string  toGoatLatin(string &S) {
    string result;
    
    //corner case
    if(S.empty()){
        return result;
    }
    
    vector<string> words = split(S);
    
    if(words.empty()){
        return result;
    }
    
    for(int i = 0;i<words.size();i++){
        string temp;
        
        if(isVowel(words[i][0])){
            temp = words[i]+"ma";
        }
        else{
            temp = words[i].substr(1)+string(1,words[i][0])+"ma";
        }
        
        for(int j = 0;j<=i;j++){
            temp = temp + "a";
        }
        
        result = result + " " + temp;
    }
    
    return result.substr(1);
}

//helper function to see if a char is a vowel
bool isVowel(char s){
    set<char> vowels{'a','e','i','o','u','A','E','I','O','U'};
    
    return vowels.count(s)>0;
}

//helper function to split the string by space
vector<string> split(string& s){
    stringstream ss;
    ss<<s;
    
    vector<string> result;
    string word;
    
    //use built-in getline to split each word
    while(getline(ss,word,' ')){
        result.push_back(word);
    }
    
    return result;
}