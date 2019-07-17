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
Given two integers L and R, find the count of numbers in the range [L, R] (inclusive) 
having a prime number of set bits in their binary representation.
*/


/**
 * @param L: an integer
 * @param R: an integer
 * @return: the count of numbers in the range [L, R] having a prime number of set bits in their binary representation
 */
int countPrimeSetBits(int L, int R) {
    // Write your code here
    
    int result = 0;
    //loop all numbers between L and R
    for(int i = L; i<=R;i++){
        int num = i;
        //count the number of bit 1
        int count = 0;
        
        while(num){
            if(num%2 == 1){
                count++;
            }
            
            num = num>>1;
        }
        
        if(isPrime(count)){
            result++;
        }
    }
    
    return result;
}
//see if the number is prime, note that the max prime number is 19
bool isPrime(int num){
    return num == 2 || num ==3 || num == 5 || num == 7 || num == 11 || num == 13 || num == 17 || num ==19;
}