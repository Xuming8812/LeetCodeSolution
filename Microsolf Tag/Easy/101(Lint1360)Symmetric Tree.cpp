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
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
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
 * @param root: root of the given tree
 * @return: whether it is a mirror of itself 
 */
bool isSymmetric(TreeNode * root) {
    // Write your code here
    if(root == nullptr){
        return true;
    }
    
    return helper(root->left,root->right);
}

bool helper(TreeNode * left, TreeNode * right){
    if(left == nullptr && right == nullptr){
        return true;
    }
    
    if(left == nullptr || right == nullptr){
        return false;
    }
    
    if(left->val != right->val){
        return false;
    }
    
    return helper(left->left,right->right)&&helper(left->right,right->left);
}