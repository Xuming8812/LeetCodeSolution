#include<map>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


/*
Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, 
count the total number of unlock patterns of the Android lock screen, 
which consist of minimum of m keys and maximum n keys.

Rules for a valid pattern:

1.Each pattern must connect at least m keys and at most n keys.
2.All the keys must be distinct.
3.If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern.
 No jumps through non selected key is allowed.
4.The order of keys used matters.
*/



/**
 * @param m: an integer
 * @param n: an integer
 * @return: the total number of unlock patterns of the Android lock screen
 */
int numberOfPatterns(int m, int n) {
    int result = 0;
    //use a vector to see if a number is visited
    vector<bool> visited(10, false);
    //use a 2D vector to decide the middle number between two numbers
    vector<vector<int>> jumps(10, vector<int>(10, 0));
    
    jumps[1][3] = jumps[3][1] = 2;
    jumps[4][6] = jumps[6][4] = 5;
    jumps[7][9] = jumps[9][7] = 8;
    jumps[1][7] = jumps[7][1] = 4;
    jumps[2][8] = jumps[8][2] = 5;
    jumps[3][9] = jumps[9][3] = 6;
    jumps[1][9] = jumps[9][1] = jumps[3][7] = jumps[7][3] = 5;
    
    //the condition of starting from 1,3,7,9
    result += dfsHelper(1, 1, 0, m, n, jumps, visited) * 4;
    //the condition of starting from 2,4,6,8
    result += dfsHelper(2, 1, 0, m, n, jumps, visited) * 4;
    //the condition of starting from 5
    result += dfsHelper(5, 1, 0, m, n, jumps, visited);
    
    return result;
}


/**
 * @param num: current starting number
 * @param length: the total length of current pattern
 * @param result: total count
 * @param m: lower bound
 * @param n: upper bound
 * @param jumps: the 2D vector saving the middle number
 * @param visited: the vector to save whether a number is visited
 * @return: the total number of unlock patterns of the Android lock screen
 */    
int dfsHelper(int num, int length, int result, int m, int n, vector<vector<int>> &jumps, vector<bool> &visited) {
    //update total count
    if (length >= m){
        result++;
    } 
    //increase the current length of the pattern
    length++;
    //the length is larger than upper bound
    if (length > n){
        return result;
    } 
    //mark this number as visited, explore
    visited[num] = true;
    
    //loop all possible moves
    for (int next = 1; next <= 9; ++next) {
        //if there is a middle number 
        int jump = jumps[num][next];
        //valid move, dfs
        if (!visited[next] && (jump == 0 || visited[jump])) {
            result = dfsHelper(next, length, result, m, n, jumps, visited);
        }
    }
    //mark this number as unvisited
    visited[num] = false;
    
    return result;
}