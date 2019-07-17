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
You have two numbers represented by a linked list, where each node contains a single digit. 
The digits are stored in reverse order, such that the 1's digit is at the head of the list. 
Write a function that adds the two numbers and returns the sum as a linked list.
*/

/**
 * @param length: the length of the array
 * @param updates: update operations
 * @return: the modified array after all k operations were executed
 */
vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
    // Write your code here
    vector<int> res;
    vector<int> nums(length + 1, 0);
    //在开头坐标startIndex位置加上inc，而在结束位置加1的地方加上-inc
    for (int i = 0; i < updates.size(); ++i) {
        nums[updates[i][0]] += updates[i][2];
        nums[updates[i][1] + 1] -= updates[i][2];
    }
    
    int sum = 0;
    //对所有位置求前n项和
    for (int i = 0; i < length; ++i) {
        sum += nums[i];
        res.push_back(sum);
    }
    
    return res;
}
