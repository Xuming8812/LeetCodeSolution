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
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.
*/

/**
 * @param nums: the gievn integers
 * @return: the total Hamming distance between all pairs of the given numbers
 */
int totalHammingDistance(vector<int> &nums) {
    // Write your code here
    int result{0};
    
    int length = nums.size();
    
    //corner case
    if(nums.empty()){
        return result;
    }
    
    //loop each bit
    for(int i = 0;i<32;i++){
        //the number of 1
        int count = 0;
        //loop all numbers
        for(int j = 0;j<length;j++){
            //count the number of 1
            if((nums[j]&1) == 0){
                count++;
            }
            //right move 1 bit
            nums[j]= nums[j]>>1;
        }
        //update hammer distance
        result += count*(length-count);
    }
    
    return result;
}


