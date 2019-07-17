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
//the helper function to update the tree
void helper(TreeNode * root){
    //base condition
    if(root == nullptr) return;
    //inorder traversal but from right to left
    if(root->right){
        helper(root->right);
    }
    //update the current node
    root->val = root->val + sum;
    //update the sum
    sum = root->val;
    
    if(root->left){
        helper(root->left);
    }
}
//global variable to store current sum
int sum{0};