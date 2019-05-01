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
A full binary tree is defined as a binary tree in which all nodes have either zero or two child nodes. 
Conversely, there is no node in a full binary tree, which has one child node. More information about full binary trees can be found 
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * @param root: the given tree
 * @return: Whether it is a full tree
 */
bool isFullTree(TreeNode * root) {
    // write your code here
    if(root == nullptr){
        return true;
    }
    
    if(root->left == nullptr && root->right == nullptr){
        return true;
    }
    
    if(root->left != nullptr && root->right != nullptr){
        return isFullTree(root->left)&&isFullTree(root->right);
    }
    
    return false;
}