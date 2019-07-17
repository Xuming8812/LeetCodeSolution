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
Given two lists A and B, and B is an anagram of A. B is an anagram of A means B is made by randomizing the order of the elements in A.
We want to find an index mapping P, from A to B. A mapping P[i] = j means the ith element in A appears in B at index j.
These lists A and B may contain duplicates. If there are multiple answers, output any of them.
*/ 

/**
 * @param A: lists A
 * @param B: lists B
 * @return: the index mapping
 */
vector<int> anagramMappings(vector<int> &A, vector<int> &B) {
    // Write your code here
    //store the index of the elements in list B
    map<int, vector<int>> mapIndex;
    //store the indexes of each element
    for(int i = 0; i < B.size(); ++i) {
        mapIndex[B[i]].push_back(i);
    }
    
    vector<int> res;
    
    for(int j = 0; j < A.size(); ++j) {
        res.push_back(mapIndex[A[j]].back());
        mapIndex[A[j]].pop_back();
    }
    return res;

}