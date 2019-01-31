#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<bitset>

using namespace std;

/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
*/

 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 vector<int> rightSideView(TreeNode* root) {
	 if (root == nullptr) return {};

	 vector<int> result{};

	 queue<TreeNode*> bfs;

	 bfs.push(root);

	 while (!bfs.empty()) {
		 int length = bfs.size();

		 TreeNode* temp{ nullptr };

		 for (int i = 0; i < length; i++) {
			 temp = bfs.front(); bfs.pop();

			 if (i == length - 1) {
				 result.push_back(temp->val);
			 }

			 if (temp->left) bfs.push(temp->left);
			 if (temp->right) bfs.push(temp->right);
		 }
	 }

	 return result;

 }