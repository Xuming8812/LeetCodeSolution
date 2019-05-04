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
Given a sorted array, remove the duplicates in place such that each element appear at most twice and return the new length.
If a number appears more than two times, then keep the number appears twice in array after remove.
*/ 

/**
 * @param A: a list of integers
 * @return : return an integer
 */
int removeDuplicates(vector<int> &nums) {
    //corner case
    if(nums.empty()){
        return 0;
    }
    //the right index for a element to insert
    int size = 1;
    //count of same elements
    int count = 1;
    
    //loop all elements
    for(int i = 1;i<nums.size();i++){
        //if same with former one
        if(nums[i] == nums[i-1]){
            //check the count
            if(count<2){
                nums[size++] = nums[i];
            }
            count++;
        }
        else{
            //reset count and insert the unique element
            count =1;
            nums[size++] = nums[i];
        }
    }
    
    return size;
}