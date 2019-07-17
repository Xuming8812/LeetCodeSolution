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
Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. 
If no such solution, return -1.
*/  

/**
 * @param A: a string
 * @param B: a string
 * @return: return an integer
 */
int repeatedStringMatch(string &A, string &B) {
    // write your code here
    //corner case
    if(A.empty() || B.empty()){
        return -1;
    }
    //no repeatition
    string temp  = A;
    //emumenate each possible repeatition time
    for(int i=1;i<=B.size() / A.size() + 2;i++){
        //find the substring by calling the stl
        if (temp.find(B) != string::npos){
            return i;
        }
        //repeat
        temp += A;
    }
    
    return -1;
}