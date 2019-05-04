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
Compute and return the square root of x.
*/

/**
 * @param x: An integer
 * @return: The sqrt of x
 */
int sqrt(int x) {
    // write your code here
    //corner case
    if(x<0){
        return -1;
    }
    
    if(x <2){
        return x;
    }
    
    //binary search
    int left = 0;
    int right = x;
    //in this version, finally the left is the smallest value that satisfies the equation mid*mid>x
    while(left<right){
        long mid = left + (right-left)/2;
        
        if(mid*mid == x){
            return mid;
        }
        else if(mid*mid>x){
            right = mid;
        }
        else{
            left = mid+1;
        }
    }
    
    return left-1;
}