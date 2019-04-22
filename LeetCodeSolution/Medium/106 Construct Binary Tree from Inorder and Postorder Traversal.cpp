#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given inorder and postorder traversal of a tree, construct the binary tree.
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* buildTreeHelper(vector<int>& inorder, int i, int j, vector<int>& postorder, int ii, int jj) {
	if (j < i || jj < ii) return nullptr;

	TreeNode* root = new TreeNode(postorder[jj]);

	auto pos = find(inorder.begin() + i, inorder.begin() + j + 1, postorder[jj]);

	int dis = pos - inorder.begin() - i;

	root->left = buildTreeHelper(inorder, i, i + dis - 1, postorder, ii, ii + dis - 1);
	root->right = buildTreeHelper(inorder, i + dis + 1, j, postorder, ii + dis, jj - 1);


	return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	return buildTreeHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}