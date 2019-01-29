#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a binary tree, return the preorder traversal of its nodes' values.
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode* root) {
	vector<int> result;
	stack<TreeNode*> store;

	if (!root)
	{
		return result;
	}

	store.push(root);

	while (!store.empty())
	{
		TreeNode* current = store.top();
		store.pop();

		if (current->right)
		{
			store.push(current->right);
		}

		if (current->left)
		{
			store.push(current->left);
		}

		result.push_back(current->val);
	}

	return result;
}