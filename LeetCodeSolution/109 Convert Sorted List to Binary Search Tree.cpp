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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* curNode;

TreeNode* sortedListToBST(ListNode* head, int n)
{
	if (n <= 0) return nullptr;

	TreeNode* left = sortedListToBST(head, n / 2);


	TreeNode* root = new TreeNode(curNode->val);

	curNode = curNode->next;

	TreeNode* right = sortedListToBST(curNode, n - 1 - n / 2);

	root->left = left;
	root->right = right;

	return root;
}

int getLength(ListNode* head)
{
	int length{ 0 };
	ListNode* cur = head;

	while (cur) {
		length++;
		cur = cur->next;
	}

	return length;
}

TreeNode* sortedListToBST(ListNode* head) {

	int length = getLength(head);

	curNode = head;

	return sortedListToBST(head, length);
}

