#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<bitset>

using namespace std;

/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

void nextPermutation(vector<int>& nums) {
    //start with second last element and search to the right
    int index = nums.size() - 2;
    //find the first pair the nums[i]<nums[i + 1] from the right side
    while (index >= 0 && nums[index + 1] <= nums[index]) {
        index--;
    }
    
    //need to find the element just bigger from the right to swap
    if (index >= 0) {
        int j = nums.size() - 1;
        while (j >= 0 && nums[j] <= nums[index]) {
            j--;
        }
        swap(nums, index, j);
    }
    
    reverse(nums, index + 1);
}

//helper function to revere the vector starting with given index
void reverse(vector<int>& nums, int start) {
    int i = start, j = nums.size() - 1;
    while (i < j) {
        swap(nums, i, j);
        i++;
        j--;
    }
}

//helper function to swap two elements in a vector
void swap(vector<int>& nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}