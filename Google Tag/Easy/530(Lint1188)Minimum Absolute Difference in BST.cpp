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
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
*/

class TreeNode {
    public:
        int val;
        TreeNode *left, *right;
        TreeNode(int val) {
            this->val = val;
            this->left = this->right = NULL;
        }
};




TreeNode* prev{nullptr};
int result{INT_MAX};

//helper function to in order traverse
void inorder(TreeNode* root) {
    if(!root) return;
    //lefttree
    inorder(root->left);
    //current
    if(prev) {
        result = min(result, abs(root->val - prev->val));
    }
    //set prev as current node
    prev = root;
    //right subtree
    inorder(root->right);
}
 /**
 * @param root: the root
 * @return: the minimum absolute difference between values of any two nodes
 */   
int getMinimumDifference(TreeNode* root) {
    if(!root) return 0;
    
    inorder(root);
    
    return result;
}