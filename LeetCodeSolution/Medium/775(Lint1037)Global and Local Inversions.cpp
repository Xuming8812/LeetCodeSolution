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
Given a permutation A of [0, 1, ..., N - 1], where N is the length of A.

The number of global inversions is the number of i < j with 0 <= i < j < N and A[i] > A[j].

The number of local inversions is the number of i with 0 <= i < N and A[i] > A[i+1].

Return true if and only if the number of global inversions is equal to the number of local inversions, otherwise returh false.
*/   
    
/**
 * @param A: an array
 * @return: is the number of global inversions is equal to the number of local inversions
 */
bool isIdealPermutation(vector<int>& A) {
    for (int i = 2, max_value = 0; i < A.size(); ++i) {
        max_value = max(max_value, A[i - 2]);
        if (max_value > A[i]) {
            return false;
        }
    }
    return true;
}