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

int depth(TreeNode* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	return 1 + max(depth(root->left), depth(root->right));
}

bool isBalanced(TreeNode* root) {
	if (!root)
	{
		return true;
	}

	if (abs(depth(root->left) - depth(root->right)) <= 1)
	{
		return isBalanced(root->left) && isBalanced(root->right);
	}
	else
	{
		return false;
	}
}

