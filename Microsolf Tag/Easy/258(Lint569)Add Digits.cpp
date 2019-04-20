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
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
*/

/**
 * @param num: a non-negative integer
 * @return: one digit
 */
int addDigits(int num) {
    // write your code here
    if(num<10) return num;
    
    int result = 0;
    
    while(num>=10){
        while(num){
            result += num%10;
            num = num/10;
        }
        
        num = result;
        result = 0;
    }
    
    return num;
}