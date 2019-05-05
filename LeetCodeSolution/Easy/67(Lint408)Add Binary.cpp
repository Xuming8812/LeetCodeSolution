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
Given two binary strings, return their sum (also a binary string).
*/


/**
 * @param a: a number
 * @param b: a number
 * @return: the result
 */
string addBinary(string &a, string &b) {
    // write your code here

    string result;
    //use two pointer to point to string a and b`s current bit
    int i = a.size()-1,j = b.size()-1;
    
    int carry = 0;
    
    while(i>=0 || j >=0){
        //default value for bitA and bitB are zeros
        int num1 = (i>=0)?(a[i--]-'0') : 0;
        int num2 = (j>=0)?(b[j--]-'0') : 0;
        //default value for bitA and bitB are zeros
        int sum = num1 + num2 + carry;
        carry = sum/2;
        sum = sum%2;
        //update the result string
        result = to_string(sum)+result;
    }
    //if the carry is not 0, add 1 in front of the string
    if(carry){
        result = "1"+result;
    }
    
    return result;    
}