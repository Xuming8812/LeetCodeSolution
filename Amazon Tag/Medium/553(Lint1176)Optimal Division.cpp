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
Given a list of positive integers, the adjacent integers will perform the float division. For example, [2,3,4] -> 2 / 3 / 4.

However, you can add any number of parenthesis at any position to change the priority of operations. 
You should find out how to add parenthesis to get the maximum result, and return the corresponding expression in string format. 
Your expression should NOT contain redundant parenthesis.
*/

/**
 * @param nums: an array
 * @return: the corresponding expression in string format
 */
string optimalDivision(vector<int>& nums) {

    string r; //result

    if (nums.size() == 0)
        return r;

    r = to_string(nums[0]);

    if (nums.size() == 1)
        return r;

    if (nums.size() == 2)
        return r + "/" + to_string(nums[1]);

    r += "/(";

    for (int i = 1; i < nums.size(); i++)
    {
        r += to_string(nums[i]) + "/";
    }

    // replace last '/' with a ')'
    r.pop_back();
    r += ")";

    return r;        

}