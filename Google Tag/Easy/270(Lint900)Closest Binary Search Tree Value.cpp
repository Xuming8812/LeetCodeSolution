#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/**
 * @param root: the given BST
 * @param target: the given target
 * @return: the value in the BST that is closest to the target
 */
int closestValue(TreeNode * root, double target) {
    // write your code here
    if(root == nullptr){
        return -1;
    }
    
    helper(root,target);
    
    return value;
}

double distance{INT_MAX};
int value{INT_MAX};


//helper function to find the closest distance
void helper(TreeNode * root, double target){
    if(root == nullptr){
        return;
    }
    
    helper(root->left,target);
    //update distance and result
    if(abs(root->val-target)<=distance){
        distance = abs(root->val-target);
        value = root->val;
    }
    
    helper(root->right,target);
}

