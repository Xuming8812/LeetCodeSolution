#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<unordered_set>

using namespace std;

/*
Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. 
The longest consecutive path need to be from parent to child (cannot be the reverse).
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * @param root: the root of binary tree
 * @return: the length of the longest consecutive sequence path
 */
int longestConsecutive(TreeNode* root) {
    int result = 0;
    
    if (!root){
        return result;
    } 
    
    dfs(root, root->val, 0, result);
    
    return result;
}

//helper function
void dfs(TreeNode *root, int value, int out, int &result) {
    //base condition
    if (!root) return;
    //can be connected
    if (root->val == value + 1){
        out++;
    } 
    else{
        out = 1;
    } 
    
    result = max(result, out);
    
    dfs(root->left, root->val, out, result);
    dfs(root->right, root->val, out, result);
}