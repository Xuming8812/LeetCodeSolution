#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
	if (p == nullptr&&q == nullptr)
	{
		return true;
	}

	if (p == nullptr || q == nullptr)
	{
		return false;
	}

	if (p->val != q->val)
	{
		return false;
	}

	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

}