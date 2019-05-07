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
Implement pow(x, n). (n is an integer.)
*/    
    
/**
 * @param x: the base number
 * @param n: the power number
 * @return: the result
 */
double myPow(double x, int n) {
    //base condition
    if (x == 0) {
        return 0;
    }
    
    if (n == 0) {
        return 1;
    }
    //when n is smaller than 0, return 1/result
    if(n<0){
        if(n==INT_MIN){
            return 1.0 / (myPow(x,INT_MAX)*x);
        }
            
        return 1.0/myPow(x,-n);
    }
    //get result of n/2, 
    double half = myPow(x, n / 2);
    //when n is odd
    if (n % 2 == 1 ) {
        return half * half * x;
    }
    else{
        //when n is even
        return half * half;
    }
}