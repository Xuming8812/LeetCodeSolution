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



/**
 * @param root: the root of binary tree
 * @return: the root of the minimum subtree
 */
TreeNode* findSubtree(TreeNode * root) {
    // write your code here
    if(root == nullptr){
        return nullptr;
    }
    
    helper(root);
    
    return minNode;
}
//the helper function to find the minimum sum and return the current sum
int helper(TreeNode* root){
    if(root == nullptr){
        return 0;
    }
    
    int sum = root->val;
    sum+=helper(root->left);
    sum+=helper(root->right);
    
    if(minNode == nullptr || sum<minimumValue){
        minNode = root;
        minimumValue = sum;
    }
    
    return sum;
}
//the global value to record the current minimum and the corresponding node
int minimumValue{INT_MIN};
TreeNode * minNode{nullptr};