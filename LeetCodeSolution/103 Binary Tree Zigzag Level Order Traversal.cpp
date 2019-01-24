#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>> result;

	if (!root) return result;

	queue<TreeNode*> bfs;

	bfs.push(root);

	bool isRight{ true };

	while (!bfs.empty()) {
		int length = bfs.size();

		vector<int> row;

		for (int i = 0; i < length; i++) {
			TreeNode* cur = bfs.front();
			bfs.pop();

			row.push_back(cur->val);

			if (cur->left) bfs.push(cur->left);
			if (cur->right) bfs.push(cur->right);
		}

		if (!isRight) {
			reverse(row.begin(), row.end());
		}

		isRight = !isRight;

		result.push_back(row);
	}

	return result;
}
