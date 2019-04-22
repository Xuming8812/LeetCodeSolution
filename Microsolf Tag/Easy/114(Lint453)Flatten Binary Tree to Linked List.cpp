#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode *left, *right;
        TreeNode(int val) {
            this->val = val;
            this->left = this->right = NULL;
        }
};

/*
Flatten a binary tree to a fake "linked list" in pre-order traversal.

Here we use the right pointer in TreeNode as the next pointer in ListNode.
*/


/**
 * @param root: a TreeNode, the root of the binary tree
 * @return: nothing
 */
void flatten(TreeNode * root) {
    // write your code here
    if(root == nullptr){
        return;
    }
    
    if(last!=nullptr){
        last->left = nullptr;
        last->right = root;
    }
    
    last = root;
    TreeNode * right = root->right;
    flatten(root->left);
    flatten(right);
}

TreeNode* last{nullptr};


//second version
void flatten(TreeNode* root) {
    
    if(root == nullptr) return;
    
    flatten(root->right);
    flatten(root->left);
    
    root->right = lastNode;
    root->left = nullptr;
    lastNode = root;           
}