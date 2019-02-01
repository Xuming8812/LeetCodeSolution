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
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
*/

 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

 TreeNode* invertTree(TreeNode* root) {

	 if (root == nullptr) {
		 return nullptr;
	 }

	 if (root->left == nullptr && root->right == nullptr) {
		 return root;
	 }

	 TreeNode* left;
	 TreeNode* right;


	 left = invertTree(root->left);

	 right = invertTree(root->right);


	 root->left = right;
	 root->right = left;

	 return root;
 }