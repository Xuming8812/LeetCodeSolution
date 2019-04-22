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
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.
*/

 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

 void binaryTreePathsHelper(TreeNode* root, vector<string>& results, string path) {
	 string currentPath = path + to_string(root->val);

	 if (root->left == nullptr && root->right == nullptr) {
		 results.push_back(currentPath);
	 }

	 currentPath += "->";

	 if (root->left) {
		 binaryTreePathsHelper(root->left, results, currentPath);
	 }

	 if (root->right) {
		 binaryTreePathsHelper(root->right, results, currentPath);
	 }
 }

 vector<string> binaryTreePaths(TreeNode* root) {
	 vector<string> result;

	 if (root == nullptr) {
		 return result;
	 }

	 binaryTreePathsHelper(root, result, "");

	 return result;
 }