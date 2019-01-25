#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.
*/

 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumNumbers(TreeNode* root, int partialSum) {
	if (!root) return 0;
	partialSum = partialSum * 10 + root->val;
	if (!root->left && !root->right) return partialSum;
	return sumNumbers(root->left, partialSum) + sumNumbers(root->right, partialSum);
}

int sumNumbers(TreeNode* root) {
	return sumNumbers(root, 0);
}