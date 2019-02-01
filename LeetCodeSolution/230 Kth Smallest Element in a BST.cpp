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
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
*/

 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 void helper(TreeNode* root, int &k, int & result) {
	 if (k == 0 || root == nullptr) {
		 return;
	 }

	 helper(root->left, k, result);
	 if (k > 0) {
		 result = root->val;
		 k--;
	 }
	 helper(root->right, k, result);
 }

 int kthSmallest(TreeNode* root, int k) {
	 int result{ 0 };

	 helper(root, k, result);

	 return result;
 }