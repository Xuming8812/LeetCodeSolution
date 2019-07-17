#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;


/*
Given an array, If the same number exists in the array, 
and the minimum distance the same number is less than the given value k, output YES, otherwise output NO.
*/

/**
 * @param nums: the arrays
 * @param k: the distance of the same number
 * @return: the ans of this question
 */
string sameNumber(vector<int> &nums, int k) {
    // Write your code here
    //corner case
    if(nums.size()<=k){
        return "NO";
    }
    //use a map to store the last index of a element
    map<int,int> record;
    //one pass
    for(int i=0;i<nums.size();i++){
        //if the element already exists
        if(record.find(nums[i])!=record.end()){
            //calculate distance
            if(i-record[nums[i]]<k){
                return "YES";
            }
        }
        //update the map
        record[nums[i]] = i;
    }
    
    return "NO";
}