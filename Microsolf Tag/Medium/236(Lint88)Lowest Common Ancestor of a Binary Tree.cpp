
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
Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.
*/

/*
    * @param root: The root of the binary search tree.
    * @param A: A TreeNode in a Binary.
    * @param B: A TreeNode in a Binary.
    * @return: Return the least common ancestor(LCA) of the two nodes.
    */

TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
    // write your code here
    if(root == nullptr || root == A || root == B){
        return root;
    }
    
    TreeNode* left = lowestCommonAncestor(root->left,A,B);
    TreeNode* right = lowestCommonAncestor(root->right,A,B);
    
    if(left!=nullptr && right!=nullptr){
        return root;
    }
    
    if(left!=nullptr){
        return left;
    }
    
    if(right!=nullptr){
        return right;
    }
    
    return nullptr;
}