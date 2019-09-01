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
Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
*/

class TreeNode {
    public:
        int val;
        TreeNode *left, *right;
        TreeNode(int val) {
            this->val = val;
            this->left = this->right = NULL;
        }
};

/**
 * @param nums: an array
 * @return: the maximum tree
 */
TreeNode* constructMaximumBinaryTree(vector<int> &nums) {
    // Write your code here
    if(nums.size()==1){
        return  new TreeNode(nums[0]);
    }
    
    if(nums.size()==0){
        return nullptr;
    }
    
    return helper(nums,0,nums.size()-1);
    
}

TreeNode * helper(vector<int> &nums, int left, int right){
    if(left == right){
        return new TreeNode(nums[left]);
    }
    
    if(left>right){
        return nullptr;
    }
    
    int maxValue{INT_MIN};
    int index{0};
    
    for(int i = left;i<=right;i++){
        if(nums[i]>maxValue){
            maxValue = nums[i];
            index = i;
        }
    }
    
    TreeNode *root = new TreeNode(maxValue);
    
    root->left = helper(nums,left,index-1);
    root->right = helper(nums,index+1,right);
    
    return root;
}