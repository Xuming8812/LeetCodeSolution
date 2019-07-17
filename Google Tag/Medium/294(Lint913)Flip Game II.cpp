#include<map>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


/*
You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, 
you and your friend take turns to flip two consecutive "++" into "--". 
The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.
*/

/**
 * @param s: the given string
 * @return: if the starting player can guarantee a win
 */
bool canWin(string &s) {
    // write your code here
    
    //corner case
    if(s.empty()){
        return false;
    }
    
    map<string,bool> memo;
    //call the helper function
    return searchHelper(memo,s);
    
}

bool searchHelper(map<string,bool>& memo, string s){
    //if the string is already calculated
    if(memo.find(s)!=memo.end()){
        return memo[s];
    }
    //see if there is a consecutive '++'
    for(int i=0;i<s.size()-1;i++){
        if(s[i] =='+'&&s[i+1] == '+'){
            //make a move
            string temp = s;
            temp[i]='-';
            temp[i+1] = '-';
            
            //if the second player loses
            if(!searchHelper(memo,temp)){
                memo[temp] = true;
                return true;
            }        
        }
    }
    
    memo[s] = false;
    
    return false;
}