#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given a positive integer n (1 <= n <= 10^18). 
Check whether a number has exactly three distinct factors, return true if it has exactly three distinct factors, otherwise false.
*/ 

/**
 * @param n: the given number
 * @return:  return true if it has exactly three distinct factors, otherwise false
 */
bool isThreeDisctFactors(long long n) {
    // write your code here
    
    double eps = 0.000000001;
    
    double root = sqrt(n);
    
    int intRoot = (int)root;
    
    if(abs(intRoot-root)<eps){
        
        if(n%2 == 0){
            return false;
        }
        for(int i = 3;i<intRoot;i+=2){
            if(n%i==0){
                return false;
            }
        }
        
        return true;
    }
    else{
        return false;
    }
    
    
}