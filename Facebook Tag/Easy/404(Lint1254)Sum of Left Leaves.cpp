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
Find the sum of all left leaves in a given binary tree.
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

/**
 * @param root: t
 * @return: the sum of all left leaves
 */
int sumOfLeftLeaves(TreeNode * root) {
    // Write your code here
    //corner case
    if(root == nullptr){
        return 0;
    }
    //call helper function
    return sumHelper(root,false);
}

//helper function return the sum of left leaves of given root node, use a boolean to store whether its left or right children
int sumHelper(TreeNode * root,bool flag){
    //corner case
    if(root == nullptr){
        return 0;
    }
    //meet the leaf
    if(root->left == nullptr && root->right == nullptr){
        //if left leave
        if(flag){
            return root->val;
        }
    }
    //recursive call
    return sumHelper(root->left,true) + sumHelper(root->right,false);
}