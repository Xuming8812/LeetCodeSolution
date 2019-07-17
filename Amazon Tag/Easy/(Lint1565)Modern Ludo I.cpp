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
There is a one-dimensional board with a starting point on the far left side of the board and an end point on the far right side of the board. 
There are several positions on the board that are connected to other positions, ie if A is connected to B, then when chess falls at position A, 
you can choose whether to move the chess from A to B. And the connection is one way, which means that the chess cannot move from B to A. 
Now given the length and connections of the board, and you have a six-sided dice(1-6), output the minimum steps to reach the end point.
*/

/**
 * @param length: the length of board
 * @param connections: the connections of the positions
 * @return: the minimum steps to reach the end
 */
int modernLudo(int length, vector<vector<int>> &connections) {
    // Write your code here

    //corner case
    if(length<=7) return 1;
    
    //the vector the store the connections
    vector<int> link(length+1);
    //initial the connection vector, each position connects to itself
    for(int i = 0;i<=length;i++){
        link[i] = i;
    }
    //dp vector
    vector<int> dp(length+1,INT_MAX);
    //update connection vector
    for(auto item : connections){
        link[item[0]] = link[item[1]];
    }
    //start from 1
    dp[1] =0;
    //loop each position
    for(int i = 2;i<=length;i++){

        if(i<7){
            dp[i] = 1;
        }
        else{
            //loop all previous 6 positions
            for(int j = i-1;j>=i-6;j--){
                dp[i] = min(dp[i],dp[j]+1);
            }
        }
        //see if links to some position
        dp[link[i]] = min(dp[i],dp[link[i]]);
    }
    
    return dp[length];

}