#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> result;

void pathSumHelper(TreeNode* root, int sum, vector<int> chosen) {

	chosen.push_back(root->val);

	if (root->right == nullptr && root->left == nullptr) {
		if (sum == root->val) {
			result.push_back(chosen);
		}
		return;
	}

	if (root->left) {
		pathSumHelper(root->left, sum - root->val, chosen);
	}

	if (root->right) {
		pathSumHelper(root->right, sum - root->val, chosen);
	}

	chosen.pop_back();

}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
	if (root == nullptr) {
		return result;
	}

	pathSumHelper(root, sum, {});

	return result;
}