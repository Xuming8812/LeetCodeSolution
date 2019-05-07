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
The code base version is an integer start from 1 to n. One day, someone committed a bad version in the code case, 
so it caused this version and the following versions are all failed in the unit tests. Find the first bad version.

You can call isBadVersion to help you determine which version is the first bad one. 
The details interface can be found in the code's annotation part.
*/    


class SVNRepo {
    public:
    static bool isBadVersion(int k);
};    
    
/**
 * @param n: An integer
 * @return: An integer which is the first bad version.
 */
int findFirstBadVersion(int n) {
    // write your code here
    
    int left = 1;
    int right = n;
    //[left,right)
    while(left<right){
        int mid = left + (right-left)/2;
        
        if(SVNRepo::isBadVersion(mid)){
            right = mid;
        }
        else{
            left = mid+1;
        }
    }
    //finally, the left is the smallest element that satisfies the condition
    return left;
}