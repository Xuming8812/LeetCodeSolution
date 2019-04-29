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
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
*/

/**
 * @param numbers: Give an array numbers of n integer
 * @return: Find all unique triplets in the array which gives the sum of zero.
 */
vector<vector<int>> threeSum(vector<int> &numbers) {
    // write your code here
    vector<vector<int>> result;
    
    sort(numbers.begin(),numbers.end());
    
    for(int i = 0;i<numbers.size();i++){
        //skip for duplicates
        if(i>0 && numbers[i] == numbers[i-1]){
            continue;
        }
        
        int start = i+1;
        int end = numbers.size()-1;
        int target = -numbers[i];
        while(start<end){
            if(start>i+1&&numbers[start] == numbers[start-1]){
                start++;
                continue;
            }
            
            if(numbers[start]+numbers[end] == target){
                result.push_back({numbers[i],numbers[start],numbers[end]});
                start++;
            }
            else if(numbers[start]+numbers[end]>target){
                end--;
            }
            else{
                start++;
            }
        }
    }
    
    return result;
}