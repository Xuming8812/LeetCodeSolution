#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isEqual(TreeNode* node1, TreeNode* node2)
{
	if (node1 == nullptr && node2 == nullptr){
		return true;
	}
	else if (node1 == nullptr || node2 == nullptr){
		return false;
	}

	if (node1->val != node2->val){
		return false;
	}

	return isEqual(node1->left, node2->right) && isEqual(node1->right, node2->left);
}

bool isSymmetric(TreeNode* root) {
	if (!root){
		return true;
	}

	return isEqual(root->left, root->right);
}