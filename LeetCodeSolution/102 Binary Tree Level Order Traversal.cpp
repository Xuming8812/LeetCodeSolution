#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> result;
	if (!root)
	{
		return result;
	}

	queue<TreeNode*> bfsStore;

	bfsStore.push(root);

	while (!bfsStore.empty())
	{

		size_t length{ bfsStore.size() };

		vector<int> row;

		for (size_t i{ 0 }; i < length; ++i)
		{
			TreeNode* currentNode = bfsStore.front();
			bfsStore.pop();
			row.push_back(currentNode->val);

			if (currentNode->left)
			{
				bfsStore.push(currentNode->left);
			}
			if (currentNode->right)
			{
				bfsStore.push(currentNode->right);
			}

		}

		result.push_back(row);
	}

	return result;
}