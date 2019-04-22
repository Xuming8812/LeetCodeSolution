#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.
*/
 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

class BSTIterator {
public:
	BSTIterator(TreeNode* root) {
		while (root) {
			dfs.push(root);
			root = root->left;
		}
	}

	/** @return the next smallest number */
	int next() {
		int result = dfs.top()->val;

		TreeNode* temp = dfs.top(); dfs.pop();

		if (temp->right) {
			temp = temp->right;

			while (temp) {
				dfs.push(temp);
				temp = temp->left;
			}
		}

		return result;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !dfs.empty();
	}

	stack<TreeNode*> dfs;
};