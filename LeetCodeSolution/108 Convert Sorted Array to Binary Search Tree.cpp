#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int start, int end) {
	if (start > end) return nullptr;

	int mid = start + (end - start) / 2;

	TreeNode* root = new TreeNode(nums[mid]);

	root->left = sortedArrayToBSTHelper(nums, start, mid - 1);
	root->right = sortedArrayToBSTHelper(nums, mid + 1, end);

	return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
	if (nums.empty()) return nullptr;

	return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
}


