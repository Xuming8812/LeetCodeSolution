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
We are given two numbers A and B such that B >= A. 
We need to compute the last digit of this resulting F such that F = B! / A! where 1 <= A, B <= 10^18 (A and B are very large)
*/  

/**
 * @param A: the given number
 * @param B: another number
 * @return: the last digit of B! / A! 
 */
int computeLastDigit(long long A, long long B) {
    // write your code here
    long long result = 1;
    
    for(long long i = A+1;i<=B;i++){
        if(result == 0){
            return result;
        }
        
        result = result * i;
        //only care about the last digit
        result = result%10;
    }
    
    return result;
}