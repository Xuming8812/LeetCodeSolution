#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a binary tree, return the inorder traversal of its nodes' values.
*/

 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

vector<int> inorderTraversal(TreeNode* root) {
	 stack<TreeNode*> dfs;

	 vector<int> result;

	 TreeNode *cur = root;

	 while (cur != nullptr || !dfs.empty()) {
		 while (cur) {
			 dfs.push(cur);
			 cur = cur->left;
		 }

		 cur = dfs.top();
		 dfs.pop();

		 result.push_back(cur->val);

		 cur = cur->right;
	 }

	 return result;
 }