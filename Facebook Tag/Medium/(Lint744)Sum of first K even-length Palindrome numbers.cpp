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
Given a integer k, find the sum of first k even-length palindrome numbers.
Even length here refers to the number of digits of a number is even.
*/    

/**
 * @param k: Write your code here
 * @return: the sum of first k even-length palindrome numbers
 */
int sumKEven(int k) {
    // 
    
    int result{0};
    if(k<=0){
        return result;
    }
    
    // the i th palindrome is i+(reverse)i
    for(int i = 1;i<=k;i++){
        result += palindrome(i);
    }
    
    return result;
    
}
//helper function to calculate the n th palindrome numbers
int palindrome(int n){
    string result = to_string(n);
    
    string reversed = result;
    
    reverse(reversed.begin(),reversed.end());
    
    result+=reversed;
    
    return stoi(result);
}