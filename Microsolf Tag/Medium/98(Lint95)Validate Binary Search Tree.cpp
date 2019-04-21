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
            this->left = nullptr;
            this->right = nullptr;
        }
};

/*
Given a binary tree, determine if it is a valid binary search tree (BST).
*/

TreeNode *lastNode = NULL;

/**
 * @param root: The root of binary tree.
 * @return: True if the binary tree is BST, or false
 */
bool isValidBST(TreeNode * root) {
    
    if(root == nullptr){
        return true;
    }

    if (!isValidBST(root->left)){
        return false;
    }
    
    if (lastNode != NULL && lastNode->val >= root->val) {
        return false;
    }
    
    lastNode = root;
    
    return isValidBST(root->right);
  
}

