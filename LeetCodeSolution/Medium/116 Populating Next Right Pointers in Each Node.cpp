#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
Recursive approach is fine, implicit stack space does not count as extra space for this problem.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
*/

struct TreeLinkNode {
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
};

void connectHelper(TreeLinkNode *root, TreeLinkNode *next) {
	if (root == nullptr) return;

	root->next = next;

	connectHelper(root->left, root->right);
	if (next != nullptr) {
		connectHelper(root->right, next->left);
	}
	else {
		connectHelper(root->right, nullptr);
	}
}

void connect(TreeLinkNode *root) {
	if (root == nullptr) return;

	connectHelper(root, nullptr);
}



