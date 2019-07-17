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
Given a binary tree, find the length(number of nodes) of the longest consecutive sequence(Monotonic and adjacent node values differ by 1) path.
The path could be start and end at any node in the tree
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
int longestConsecutive2(TreeNode* root) {
    int result = 0;
    helper(root, root, result);
    return result;
}

//helper function, return the longest increasing and decreasing sequence length
pair<int, int> helper(TreeNode* node, TreeNode* parent, int& result) {
    //base condition
    if (!node){
        return {0, 0};
    } 
    //dfs
    auto left = helper(node->left, node, result);
    auto right = helper(node->right, node, result);
    
    //update result
    result = max(result, left.first + right.second + 1);
    result = max(result, left.second + right.first + 1);
    
    //get increasing and decreasing length
    int inc = 0, dec = 0;
    
    if (node->val == parent->val + 1) {
        inc = max(left.first, right.first) + 1;
    } else if (node->val + 1 == parent->val) {
        dec = max(left.second, right.second) + 1;
    }
    return {inc, dec};
}