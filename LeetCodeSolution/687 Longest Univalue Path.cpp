#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;
/*
Given a binary tree, find the length of the longest path where each node in the path has the same value.This path may or may not pass through the root.
*/

 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

 int result = 0;

int longestUnivaluePath(TreeNode* root)
{
	longestUnivaluePathHelper(root);
	return result;
}

int longestUnivaluePathHelper(TreeNode* root) {
	if (root == nullptr)
	{
		return 0;
	}

	int left = longestUnivaluePathHelper(root->left);
	int right = longestUnivaluePathHelper(root->right);

	if (root->left != nullptr && root->val == root->left->val)
	{
		left++;
	}
	else
	{
		left = 0;
	}

	if (root->right != nullptr && root->val == root->right->val)
	{
		right++;
	}
	else
	{
		right = 0;
	}

	result = max(result, left + right);

	return max(left, right);
}


