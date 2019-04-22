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
The thief has found himself a new place for his thievery again. There is only one entrance to this area, 
called the "root." Besides the root, each house has one and only one parent house. After a tour, 
the smart thief realized that "all houses in this place forms a binary tree". 
It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int rob(TreeNode* root) {
	vector<int> result = robHelper(root);

	return max(result[0], result[1]);
}

vector<int> robHelper(TreeNode* root) {
	if (root == nullptr) return { 0,0 };

	vector<int> left = robHelper(root->left);
	vector<int> right = robHelper(root->right);

	vector<int> result(2);

	result[0] = max(left[1], left[0]) + max(right[1], right[0]);
	result[1] = root->val + left[0] + right[0];

	return result;
}