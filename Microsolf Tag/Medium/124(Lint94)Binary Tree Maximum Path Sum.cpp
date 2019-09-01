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
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. 
The path must contain at least one node and does not need to go through the root.
*/

/**
 * @param root: The root of binary tree.
 * @return: An integer
 */
int maxPathSum(TreeNode* root) {
    int result{0};
    
    if(!root) return result;
    
    result =  root->val;
    
    maxPathSumHelper(root,result);
    
    return result;
}

int maxPathSumHelper(TreeNode* root, int& result){
    if(!root) return 0;
    
    int left = maxPathSumHelper(root->left,result);
    int right = maxPathSumHelper(root->right,result);
    
    int maxLocal = max(max(left,right)+root->val,root->val);
    int maxGlobal = max(left+right+root->val, result);
    
    result = max(maxLocal, maxGlobal);
    
    return maxLocal;
}