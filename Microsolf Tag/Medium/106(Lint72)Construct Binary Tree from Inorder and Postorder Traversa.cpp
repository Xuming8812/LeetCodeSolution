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
Given inorder and postorder traversal of a tree, construct the binary tree.
*/

/**
 * @param inorder: A list of integers that inorder traversal of a tree
 * @param postorder: A list of integers that postorder traversal of a tree
 * @return: Root of a tree
 */
TreeNode * buildTree(vector<int> &inorder, vector<int> &postorder) {
    // write your code here
    if(inorder.empty()||postorder.empty()){
        return nullptr;
    }
    
    return helper(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    
}


TreeNode* helper(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd){
    if(inStart>inEnd){
        return nullptr;
    }
    
    TreeNode * root = new TreeNode(postorder[postEnd]);
    
    int position = -1;
    
    for(int index = inStart; index<=inEnd;index++){
        if(inorder[index] == postorder[postEnd]){
            position = index;
            break;
        }
    }
    
    root->left = helper(inorder,inStart,position-1,postorder,postStart,postStart+position-inStart-1);
    root->right = helper(inorder, position+1,inEnd,postorder,postStart+position-inStart,postEnd-1);
    
    return root;
}
    