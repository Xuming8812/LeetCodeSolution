#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *lastNode = nullptr;

void flatten(TreeNode* root) {

	if (root == nullptr) return;

	flatten(root->right);
	flatten(root->left);

	root->right = lastNode;
	root->left = nullptr;
	lastNode = root;
}