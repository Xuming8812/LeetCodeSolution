#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;


/*
Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.
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


int result = 110;
//the variable to store the value of last node in inorder traversal
int pre = -1;

/**
 * @param root: the root
 * @return: the minimum difference between the values of any two different nodes in the tree
 */
int minDiffInBST(TreeNode * root) {
    if (root->left != nullptr) {
        minDiffInBST(root->left);
    }
    
    if (pre != -1) {
        result = min(result, root->val - pre);
    }
    pre = root->val;
    
    if (root->right != nullptr) {
        minDiffInBST(root->right);
    }
    
    return result;
}