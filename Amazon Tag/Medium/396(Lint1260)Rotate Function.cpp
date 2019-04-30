#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<unordered_map>

using namespace std;

/*
Given an input character array, reverse the array word by word. A word is defined as a sequence of non-space characters.

The input character array does not contain leading or trailing spaces and the words are always separated by a single space.
*/


//F[i]=F[i−1]+sum−n∗a[n−i]


int maxRotateFunction(vector<int>& A) {
    if(A.empty()) return 0;
    
    long sum{0}, F{0};
    
    for(int i = 0;i<A.size();i++){
        sum +=A[i];
        F += i*A[i];
    }
    
    long result = F;
    
    for(int i = A.size()-1;i>=0;i--){
        F = F+sum-A.size()*A[i];
        
        result = max(result,F);
    }
    
    return result;
}