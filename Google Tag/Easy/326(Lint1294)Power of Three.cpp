#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;


/*
Given an integer, write a function to determine if it is a power of three.
*/


/**
 * @param n: an integer
 * @return: if n is a power of three
 */
bool isPowerOfThree(int n) {
    if(n<1) return false;
    //keep dividing by 3
    while(n%3 == 0){            
        n = n/3;
    }
    
    return n == 1;
}    
    
//non recursive version
bool isPowerOfThree(int n) {
    if (n <=0){
        return false;
    }
    else{
        long double log3 = log(n)/log(3);
        return is_integer(log3); 
    }
}
//helper function to see if a number is a whole number
bool is_integer(long double k) {   
    return ((std::ceil(k) - k) < 1.0e-10);   
}