#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given an array, return the shortest subarray length which has duplicate elements.

If the array doesn't ha the subarray which has duplicate elements, return -1.
*/


/**
 * @param arr: The array you should find shortest subarray length which has duplicate elements.
 * @return: Return the shortest subarray length which has duplicate elements.
 */

int getLength(vector<int> &arr) {
    // Write your code here.
    //corner case
    if(arr.empty()){
        return -1;
    }
    //a map to store the last index of a element
    map<int,int>count;
    
    int result = -1;
    //loop every element to see the distance to its last position
    for(int i=0;i<arr.size();i++){
        if(count.find(arr[i])!=count.end()){
            if(result==-1){
                result = i-count[arr[i]]+1;
            }
            result = min(result,i-count[arr[i]]+1);
        }
        
        count[arr[i]] = i;
    }
    
    return result;
}