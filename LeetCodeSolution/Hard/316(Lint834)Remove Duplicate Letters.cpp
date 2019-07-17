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
 * @param s: a string
 * @return: return a string
 */
string removeDuplicateLetters(string &s) {
    // write your code here
    vector<int> dict(26, 0);
    vector<bool> visited(26, false);
    
    //count the number of each letter
    for(auto ch : s){
        dict[ch-'a']++;
    }
    
    string result = "0";
    
    //the key idea is to keep a monotically increasing sequence
    //loop each letter
    for(auto c : s) {
        //
        dict[c-'a']--;
        /** to filter the previously visited elements **/
        if(visited[c-'a'])  continue;
        
        //if the last letter of result is bigger than the current letter and the letter will occur in the rest of the string, 
        //it's ok to remove the current letter 
        while(c < result.back() && dict[result.back()-'a']) {
            //make last letter of result available to visit again 
            visited[result.back()-'a'] = false;
            //pop the letter
            result.pop_back();
        }
        //push the current letter into result(stack)
        result += c;
        //mark the current letter as visited
        visited[c-'a'] = true;
    }
    return result.substr(1);
}