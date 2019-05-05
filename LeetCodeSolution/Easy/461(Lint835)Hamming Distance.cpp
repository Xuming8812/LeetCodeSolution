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
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.
*/    
           
/**
 * @param x: an integer
 * @param y: an integer
 * @return: return an integer, denote the Hamming Distance between two integers
 */
int hammingDistance(int x, int y) {
    // write your code here
    int result{0};
    
    while(x!=0 || y!=0){
        
        if(x%2 !=y%2){
            result++;
        }
        
        x = x/2;
        y = y/2;
    }
    
    return result;  
}