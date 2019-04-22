#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* first{ nullptr };
TreeNode* second{ nullptr };
TreeNode* last{ new TreeNode(INT_MIN) };

void inOrderTraversal(TreeNode* root) {
	if (root == nullptr) return;

	inOrderTraversal(root->left);

	if (first == nullptr && root->val < last->val) {
		first = last;
	}

	if (first != nullptr && root->val < last->val) {
		second = root;
	}

	last = root;

	inOrderTraversal(root->right);
}

void recoverTree(TreeNode* root) {
	inOrderTraversal(root);

	int temp = first->val;
	first->val = second->val;
	second->val = temp;
}