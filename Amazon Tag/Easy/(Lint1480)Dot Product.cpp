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
Given two array, output their dot product
*/   
      
/**
 * @param A: an array
 * @param B: an array
 * @return: dot product of two array
 */
int dotProduct(vector<int> &A, vector<int> &B) {
    // Write your code here
    if(A.size()!=B.size()||A.empty()||B.empty()){
        return -1;
    }
    
    int result{0};
    
    for(int i = 0;i<A.size();i++){
        result+=A[i]*B[i];
    }
    
    return result;
}