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
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the 
original key plus sum of all keys greater than the original key in BST.
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * @param root: the root of binary tree
 * @return: the new root
 */
TreeNode * convertBST(TreeNode * root) {
    // write your code here
    helper(root);
    
    return root;
}

void helper(TreeNode * root){
    if(root == nullptr) return;
    
    if(root->right){
        helper(root->right);
    }
    
    root->val = root->val + sum;
    sum = root->val;
    
    if(root->left){
        helper(root->left);
    }
}

int sum{0};