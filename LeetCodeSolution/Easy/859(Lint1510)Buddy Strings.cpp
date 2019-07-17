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
Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.
*/

/**
 * @param A: string A
 * @param B: string B
 * @return: bool
 */
bool buddyStrings(string &A, string &B) {
    // Write your code here
    //corner case
    if(A.size()!=B.size()){
        return false;
    }
    //vector to store the index where A[i]!=B[i]
    vector<int> indexes;
    //map to count the number of each char
    map<char,int> dict;
    //loop all chars to save indexes and count char
    for(int i=0;i<A.size();i++){
        if(A[i]!=B[i]){
            indexes.push_back(i);
        }
        
        dict[A[i]]++;
    }
    
    if(indexes.size()>2 || indexes.size()==1){
        return false;
    }
    //only two indexes don't match, swap and see if the two string equals
    if(indexes.size()==2){
        swap(A[indexes[0]],A[indexes[1]]);
        
        return A==B;
    }
    //the two strings are the same, see if there are duplicated chars in a string
    if(indexes.size()==0){
        for(auto item:dict){
            if(item.second>1){
                return true;
            }
        }
    }
    
    return false;
}

