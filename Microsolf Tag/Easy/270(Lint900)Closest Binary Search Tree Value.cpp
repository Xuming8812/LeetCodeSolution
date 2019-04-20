#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

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
 * @param root: the given BST
 * @param target: the given target
 * @return: the value in the BST that is closest to the target
 */
int closestValue(TreeNode * root, double target) {
    if (NULL == root) {
        return 0;
    }
    
    TreeNode* lowerNode = lowerBound(root, target);
    TreeNode* upperNode = upperBound(root, target);
    
    if (NULL == lowerNode) {
        return upperNode->val;
    }
    
    if (NULL == upperNode) {
        return lowerNode->val;
    }
    
    if (target - lowerNode->val > upperNode->val - target) {
        return upperNode->val;
    }
    
    return lowerNode->val;
}

//return node->val < target
TreeNode* lowerBound(TreeNode* root, double target) {
    if (NULL == root) {
        return NULL;
    }
    
    if (target <= root->val) {
        return lowerBound(root->left, target);
    }
    
    TreeNode* lowerNode = lowerBound(root->right, target);
    if (NULL == lowerNode) {
        return root;
    }
    return lowerNode;
}

TreeNode* upperBound(TreeNode* root, double target) {
    if (NULL == root) {
        return NULL;
    }
    
    if (target > root->val) {
        return upperBound(root->right, target);
    }
    
    TreeNode* upperNode = upperBound(root->left, target);
    if (NULL == upperNode) {
        return root;
    }
    return upperNode;
}

//another O(n) solution
class Solution {
public:
    /**
     * @param root: the given BST
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
    int closestValue(TreeNode * root, double target) {
        // write your code here
        if(root == nullptr){
            return -1;
        }
        
        helper(root,target);
        
        return value;
    }
    
    void helper(TreeNode * root, double target){
        if(root == nullptr){
            return;
        }
        
        helper(root->left,target);
        
        if(abs(root->val-target)<=distance){
            distance = abs(root->val-target);
            value = root->val;
        }
        
        helper(root->right,target);
    }
    
    double distance{INT_MAX};
    int value{INT_MAX};
};