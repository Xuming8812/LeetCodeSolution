#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Determines whether a binary representation of a non-negative integer n is a palindrome
*/  

/**
 * @param n: non-negative integer n.
 * @return: return whether a binary representation of a non-negative integer n is a palindrome.
 */
bool isPalindrome(int n) {
    // Write your code here
    
    vector<int> digits;
    //get each bit of the given number and save them in a vector
    while(n){
        digits.push_back(n&1);
        n>>=1;
    }
    
    int length = digits.size();
    //compare left and right bit
    for(int i = 0;i<length/2;i++){
        if(digits[i] !=digits[length-i-1]){
            return false;
        }
    }
    
    return true;
}