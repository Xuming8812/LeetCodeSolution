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
Given a binary tree, you need to compute the length of the diameter of the tree. 
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.
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
 * @param root: a root of binary tree
 * @return: return a integer
 */
int diameterOfBinaryTree(TreeNode * root) {
    // write your code here
    //corner case
    if(root == nullptr){
        return 0;
    }
    //call the helper function
    helper(root);
    
    return maxDiameter;
}

//global variable to store the max diameter
int maxDiameter{INT_MIN};

int helper(TreeNode * root){
    //corner function
    if(root == nullptr){
        return 0;
    }
    //post order travesal, get result of left and right children recursively
    int left = helper(root->left);
    int right = helper(root->right);
    
    //calculate the current max diameter
    maxDiameter = max(maxDiameter,left+right);
    
    //only return the longer path not the whole path
    return 1+max(left,right);
}