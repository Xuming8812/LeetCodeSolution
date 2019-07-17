#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Write a program to find the nth super ugly number.

A super ugly number is a positive integer in which all prime factors are within a given set of prime numbers.

For example, given [2, 7, 13, 19], then [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the first 12 super ugly numbers.
*/

/**
 * @param n: a positive integer
 * @param primes: the given prime list
 * @return: the nth super ugly number
 */
int nthSuperUglyNumber(int n, vector<int> &primes) {
    // write your code here
    
    //initialize the dp vector
    vector<int> dp(n,INT_MAX);
    //the vector to store the occurence of each prime number
    vector<int> times(primes.size());
    
    dp[0]=1;
    
    //loop all numbers between 1 to n
    for(int i =1;i<n;i++){
        //update dp[i] by previous dp
        for(int j = 0;j<primes.size();j++){
            dp[i] = min(dp[i],primes[j]*dp[times[j]]);
        }
        
        for(int j = 0;j<primes.size();j++){
            if(dp[i] == dp[times[j]]*primes[j]){
                times[j]++;
            }
        }
    }
    
    return ugly[n-1];
}