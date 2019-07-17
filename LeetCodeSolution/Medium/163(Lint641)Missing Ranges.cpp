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
Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], return its missing ranges.
*/

/*
 * @param nums: a sorted integer array
 * @param lower: An integer
 * @param upper: An integer
 * @return: a list of its missing ranges
 */
vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
    // write your code here
    //corner case
    if (lower > upper){
        return {};
    }
    
    vector<string> result;

    if (nums.empty()){
        createSection((long)lower, (long)upper, result);

        return result;
    }
    //start with lower and first number
    createSection(lower, (long)nums[0]-1, result);
    //loop each two numbers
    for (int i = 1; i < nums.size(); i++){
        createSection((long)nums[i-1]+1, (long)nums[i]-1, result);
    }
    //last number and upper bounder
    createSection((long)nums[nums.size() - 1]+1, (long)upper, result);

    return result;
}
//helper function to store a section in the final result vector
void createSection(long start, long end, vector<string>& result){
    if (start > end){
        return;
    }

    if (start == end){
        result.push_back(to_string(start));
    }
    else{
        result.push_back(to_string(start)+"->"+to_string(end));
    }
}