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
Given a binary tree, find the subtree with maximum sum. Return the root of the subtree.
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
    
/**
 * @param root: the root of binary tree
 * @return: the maximum weight node
 */
TreeNode * findSubtree(TreeNode * root) {
    // write your code here
    if(root == nullptr) return nullptr;
    
    helper(root);
    
    return maxNode;
}
//the helper function to return the sum of a tree
int helper(TreeNode * root){
    //base condition
    if(root==nullptr) return 0;
    //post order traversal
    int left = helper(root->left);
    int right = helper(root->right);
    //get the sum of this tree
    int sum = left+right+root->val;
    
    if(maxNode==nullptr || sum>maxValue){
        maxValue = sum;
        maxNode = root;
    }
    
    return sum;
}

int maxValue{INT_MIN};
TreeNode* maxNode{nullptr};