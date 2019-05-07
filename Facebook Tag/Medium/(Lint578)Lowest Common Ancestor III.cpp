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
Given a binary tree, return all root-to-leaf paths.
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

/*
    * @param root: The root of the binary tree.
    * @param A: A TreeNode
    * @param B: A TreeNode
    * @return: Return the LCA of the two nodes.
    */
TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B) {
    // write your code here

    TreeNode * result = helper(root, A,B);
    //see if the two given node are really in this tree
    if(foundA&&foundB){
        return result;
    }
    else{
        return nullptr;
    }
}

TreeNode* helper(TreeNode * root, TreeNode * A, TreeNode * B){
    //base case
    if(root == nullptr){
        return nullptr;
    }
    //dfs
    TreeNode* left = helper(root->left,A,B);
    TreeNode* right = helper(root->right,A,B); 
    
    //see if A and B are nodes in this tree
    if(root == A || root == B){
        foundA = A==root || foundA;
        foundB = B==root || foundB;
        return root;
    }
    
    //find A and B in both subtrees, then current node is our result
    if(left!=nullptr && right!=nullptr){
        return root;
    }
    //find A/B in left subtree, but not find another in right subtree
    else if(left != nullptr){
        return left;
    }
    //find A/B in right subtree, but not find another in left subtree
    else if(right != nullptr){
        return right;
    }
    //find nothing in both subtrees
    else{
        return nullptr;
    }
    
}


bool foundA{false},foundB{false};