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
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
*/

/**
 * @param A: an integer rotated sorted array
 * @param target: an integer to be searched
 * @return: an integer
 */
int search(vector<int> &A, int target) {
    // write your code here
    
    int left = 0;
    int right = A.size()-1;
    
    while(left<=right){
        int middle = left + (right-left)/2;
        if(A[middle] == target){
            return middle;
        }
        
        //left is ordered
        if(A[middle]>=A[left]){
            if(A[left]<=target && A[middle]>target){
                right = middle-1;
            }
            else{
                left = middle+1;
            }
        }
        else{
            if(A[middle]<target && A[right]>=target){
                left = middle +1;
            }
            else{
                right = middle - 1;
            }
        }
    }
    
    return -1;
}