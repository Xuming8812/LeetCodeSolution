#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Count the number of prime numbers less than a non-negative number, n.
*/    
    

/**
 * @param n: a integer
 * @return: return a integer
 */
int countPrimes(int n) {
    // write your code here
    //vector to store if all numbers smaller than n are prime
    vector<bool> isPrime(n,true);
    
    int result{0};
    //start from 2
    for(int index = 2;index<n;index++){
        //if the current number is prime
        if(isPrime[index]){
            //update result
            result++;

            //set all n*index as non prime
            for(int times = 0;times*index<n;times++){
                isPrime[times*index] = false;
            }
        }
    }
    
    return result;
}