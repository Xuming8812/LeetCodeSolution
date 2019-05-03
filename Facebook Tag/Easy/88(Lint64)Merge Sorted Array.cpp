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
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
*/

void mergeSortedArray(int A[], int m, int B[], int n) {
    // write your code here
    int index = m+n-1;
    int indexA = m-1;
    int indexB = n-1;
    
    while(indexA>=0 && indexB>=0){
        if(A[indexA]>B[indexB]){
            A[index--] = A[indexA--];
        }
        else{
            A[index--] = B[indexB--];
        }
    }
    
    while(indexA>=0){
        A[index--] = A[indexA--];
    }
    
    while(indexB>=0){
        A[index--] = B[indexB--];
    }
}

