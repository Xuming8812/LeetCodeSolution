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
Given a complete binary tree, count the number of nodes.
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

int countNodes(TreeNode* root) {

	if (!root) return 0;

	int hl = 0, hr = 0;

	TreeNode *l = root, *r = root;

	while (l) {
		hl++;
		l = l->left;
	}

	while (r) {
		hr++;
		r = r->right;
	}

	if (hl == hr) return pow(2, hl) - 1;

	return 1 + countNodes(root->left) + countNodes(root->right);

}