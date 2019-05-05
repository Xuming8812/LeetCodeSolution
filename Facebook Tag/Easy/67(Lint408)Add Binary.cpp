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
   
    int i = a.size()-1,j = b.size()-1;
    
    int carry = 0;
    
    while(i>=0 || j >=0){
        int num1 = (i>=0)?(a[i--]-'0') : 0;
        int num2 = (j>=0)?(b[j--]-'0') : 0;
        int sum = num1 + num2 + carry;
        carry = sum/2;
        sum = sum%2;
        result = to_string(sum)+result;
    }
    
    if(carry){
        result = "1"+result;
    }
    
    return result;    
}