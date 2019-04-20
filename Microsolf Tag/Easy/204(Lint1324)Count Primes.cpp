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
Count the number of prime numbers less than a non-negative number, n
*/


/**
 * @param n: a integer
 * @return: return a integer
 */
int countPrimes(int n) {
    // write your code here
    vector<bool> isPrime(n,true);
    
    int result{0};
    
    for(int index = 2;index<n;index++){
        if(isPrime[index]){
            result++;
            for(int times = 0;times*index<n;times++){
                isPrime[times*index] = false;
            }
        }
    }
    
    return result;
}