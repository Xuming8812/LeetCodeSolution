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
Implement double sqrt(double x) and x >= 0.

Compute and return the square root of x.
*/

/**
 * @param x: a double
 * @return: the square root of x
 */
double sqrt(double x) {
    // write your code here
    //binary search
    double left = 0.0;
    double right = x;
    double eps = 1e-12;
    
    //corner case of x<1.0
    if(right < 1.0) {
        right = 1.0;
    }
    //error bigger than defined
    while(right - left > eps) {
        //get mid
        double mid = (right + left) / 2;
        
        //increase left
        if(mid * mid < x) {
            left = mid;
        }
        else {
            //decrease right
            right = mid;
        }
    }

    return left;
}