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

vector<TreeNode*> generateTreesHelper(int start, int end) {
	vector<TreeNode*> result;

	if (start > end) {
		result.push_back(nullptr);
		return result;
	}

	for (int i = start; i <= end; i++) {
		vector<TreeNode*> left = generateTreesHelper(start, i - 1);
		vector<TreeNode*> right = generateTreesHelper(i + 1, end);

		for (auto l : left) {
			for (auto r : right) {
				TreeNode* current = new TreeNode(i);

				current->left = l;
				current->right = r;

				result.push_back(current);
			}
		}
	}

	return result;
}

vector<TreeNode*> generateTrees(int n) {
	if (n < 1) { return{}; }

	return generateTreesHelper(1, n);
}

