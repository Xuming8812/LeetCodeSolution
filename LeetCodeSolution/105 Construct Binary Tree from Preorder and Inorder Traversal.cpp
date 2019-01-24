#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTreeHelper(vector<int>& preorder, int i, int j, vector<int>& inorder, int ii, int jj)
{
	// tree        8 4 5 3 7 3
	// preorder    8 [4 3 3 7] [5]
	// inorder     [3 3 4 7] 8 [5]

	// 每次从 preorder 头部取一个值 mid，作为树的根节点
	// 检查 mid 在 inorder 中 的位置，则 mid 前面部分将作为 树的左子树，右部分作为树的右子树

	if (i >= j || ii >= j)
		return NULL;

	int mid = preorder[i];
	auto f = find(inorder.begin() + ii, inorder.begin() + jj, mid);

	int dis = f - inorder.begin() - ii;

	TreeNode* root = new TreeNode(mid);
	root->left = buildTreeHelper(preorder, i + 1, i + 1 + dis, inorder, ii, ii + dis);
	root->right = buildTreeHelper(preorder, i + 1 + dis, j, inorder, ii + dis + 1, jj);
	return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	return buildTreeHelper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
}