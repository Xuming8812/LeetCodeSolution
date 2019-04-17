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
Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).
*/


/**
 * @param n: an unsigned integer
 * @return: the number of â€™1' bits
 */
int hammingWeight(unsigned int n) {
    // write your code here
    int count{0};
    
    while(n!=0){
        if(n%2 == 1){
            count++;
        }
        n = n/2;
    }
    
    return count;
}