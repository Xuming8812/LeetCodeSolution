#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};


 //note that the special condition that a tree is extremly unbalanced
 int minDepth(TreeNode* root) {

	 if (root == nullptr)
	 {
		 return 0;
	 }

	 if (root->left == nullptr || root->right == nullptr)
	 {
		 return maxDepthHelper(root);
	 }
	 else
	 {
		 return minDepthHelper(root);
	 }

 }

 int minDepthHelper(TreeNode* root)
 {
	 if (root == nullptr)
	 {
		 return 0;
	 }

	 return 1 + min(minDepth(root->left), minDepth(root->right));
 }

 int maxDepthHelper(TreeNode* root)
 {
	 if (root == nullptr)
	 {
		 return 0;
	 }

	 return 1 + max(minDepth(root->left), minDepth(root->right));
 }