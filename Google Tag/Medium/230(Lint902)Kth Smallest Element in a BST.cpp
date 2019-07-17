#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * @param root: the given BST
 * @param k: the given k
 * @return: the kth smallest element in BST
 */
int kthSmallest(TreeNode* root, int k) {
    int result{0};
    
    helper(root,k,result);
    
    return result;
}
//helper function
void helper(TreeNode* root, int &k, int & result){
    //base condition
    if(k == 0 || root == nullptr){
        return;
    }
    //inorder traversal
    helper(root->left,k,result);
    
    if(k>0){
        result = root->val;
        k--;
    }
    
    helper(root->right,k,result);
}