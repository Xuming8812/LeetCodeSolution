#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a binary tree, determine if it is a valid binary search tree (BST).
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBST(TreeNode* root) {
	if (root == nullptr) return true;

	if (root->left == nullptr && root->right == nullptr) {
		return true;
	}

	if (root->left && !isValidBST(root->left)) {
		return false;
	}

	if (root->right && !isValidBST(root->right)) {
		return false;
	}

	if (root->left) {
		TreeNode *cur = root->left;
		while (cur->right) {
			cur = cur->right;
		}
		if (cur->val >= root->val) {
			return false;
		}
	}

	if (root->right) {
		TreeNode *cur = root->right;
		while (cur->left) {
			cur = cur->left;
		}

		if (cur->val <= root->val) {
			return false;
		}
	}

	return true;
}