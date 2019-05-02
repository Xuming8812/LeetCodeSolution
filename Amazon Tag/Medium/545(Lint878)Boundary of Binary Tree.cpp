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
Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root. 
Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes.

Left boundary is defined as the path from root to the left-most node. 
Right boundary is defined as the path from root to the right-most node. If the root doesn't have left subtree or right subtree, 
then the root itself is left boundary or right boundary. Note this definition only applies to the input binary tree, and not applies to any subtrees.

The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if exists. 
If not, travel to the right subtree. Repeat until you reach a leaf node.

The right-most node is also defined by the same way with left and right exchanged.
*/

/**
 * @param root: a TreeNode
 * @return: a list of integer
 */
vector<int> boundaryOfBinaryTree(TreeNode * root) {
    // write your code here
    vector<int> result;
    if(root == nullptr){
        return result;
    }
    
    result.push_back(root->val);
    
    if(root->left == nullptr && root->right == nullptr){
        return result;
    }
    
    dfsLeft(root->left,result);
    dfsLeaves(root,result);
    dfsRight(root->right,result);
    
    return result;
}

void dfsLeft(TreeNode * root,vector<int> &result){
    if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
        return;
    }
    
    result.push_back(root->val);
    
    if(root->left){
        dfsLeft(root->left,result);
    }
    else{
        dfsLeft(root->right,result);
    }
}

void dfsLeaves(TreeNode * root,vector<int> &result){
    if(root == nullptr){
        return;
    }
    
    if(root->left == nullptr && root->right == nullptr){
        result.push_back(root->val);
        return;
    }
    
    dfsLeaves(root->left,result);
    dfsLeaves(root->right,result);
}

void dfsRight(TreeNode * root,vector<int> &result){
    if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
        return;
    }
    
    if(root->right){
        dfsRight(root->right,result);
    }
    else{
        dfsRight(root->left,result);
    }
    
    result.push_back(root->val);
}