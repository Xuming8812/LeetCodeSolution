#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
*/

 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

 bool hasPathSum(TreeNode* root, int sum)
 {
	 //base condition
	 if (root == nullptr)
	 {
		 return false;
	 }
	 //if it`s leaf node and value equals to sum
	 if (root->left == nullptr && root->right == nullptr)
	 {
		 if(root->val == sum)
		 {
			 return true;
		 }
		 else
		 {
			 return false;
		 }
	 }

	 return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
 }