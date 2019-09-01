#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

/*
Given an array with n integers. Splitting it into subsequences of strictly descending order.
Output the minimum number of subsequences you can get by splitting.
*/

/**
 * @param arrayIn: The original array.
 * @return: Count the minimum number of subarrays.
 */
int LeastSubsequences(vector<int> &arrayIn) {  
    //corner case
    if(arrayIn.empty()){
        return 0;
    }
    //use a vector to store each descending subsequence
    vector<vector<int>>store;
    //start with the first element of input array
    store.push_back({arrayIn[0]});
    
    //loop all elements in input array
    for(int i = 1;i<arrayIn.size();i++){
        
        //loop all subsequence
        int j = 0;
        for(;j<store.size();j++){
            if(arrayIn[i]<store[j].back()){
                store[j].push_back(arrayIn[i]);
                break;
            }
        }
        
        if(j == store.size()){
            store.push_back({arrayIn[i]});
        }
    }
<<<<<<< HEAD
    
=======
     
>>>>>>> 59b1b212aa74e7cfdcd86cd43caf30cf13d5ad60
    return store.size();
}