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
You're given strings J representing the types of stones that are jewels, and S representing the stones you have. 
Each character in S is a type of stone you have. You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. 
Letters are case sensitive, so "a" is considered a different type of stone from "A".
*/


/**
 * @param J: the types of stones that are jewels
 * @param S: representing the stones you have
 * @return: how many of the stones you have are also jewels
 */
int numJewelsInStones(string &J, string &S) {
    // Write your code here
    
    //construct a set by vector
    set<char>jewels(J.begin(),J.end());
    
    int result{0};
    for(auto c : S){
        if(jewels.find(c)!=jewels.end()){
            result++;
        }
    }
    
    return result;
}