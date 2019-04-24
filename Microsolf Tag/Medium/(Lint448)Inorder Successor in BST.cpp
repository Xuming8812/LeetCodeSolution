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
Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).
*/


/*
* @param root: The root of the BST.
* @param p: You need find the successor node of p.
* @return: Successor of p.
*/
TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
    // write your code here
    
    if(root == nullptr || p == nullptr)
    {
        return nullptr;
    }
    
    if(p->val >= root->val)
    {
        return inorderSuccessor(root->right,p);
    }
    
    if(p->val < root->val)
    {
        TreeNode * leftResult = inorderSuccessor(root->left,p);
        
        if(leftResult)
        {
            return leftResult;
        }
        else
        {
            return root;
        }
    }
}