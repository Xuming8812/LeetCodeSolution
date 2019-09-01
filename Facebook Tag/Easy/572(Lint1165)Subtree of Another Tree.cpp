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
Given a binary tree, you need to compute the length of the diameter of the tree. 
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.
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
 * @param s: the s' root
 * @param t: the t' root
 * @return: whether tree t has exactly the same structure and node values with a subtree of s
 */
bool isSubtree(TreeNode* s, TreeNode* t) {
    // Write your code here
    //corner case
    if(s == nullptr){
        return t == nullptr;
    }
    
    if(t == nullptr){
        return true;
    }
    //check whether the values of current nodes are same and current tree equals to another tree
    if(s->val == t->val && isSameTree(s,t)){
        return true;
    }
    //recursively call the function to check left subtree and right subtree
    return isSubtree(s->left,t) || isSubtree(s->right,t);
}

//the helper function to see if two given trees have the same structure and node values
bool isSameTree(TreeNode* s, TreeNode* t){
    //corner case
    if(s == nullptr && t == nullptr){
        return true;
    }
    
    if(s == nullptr || t == nullptr){
        return false;
    }
    //if the values of given nodes are different
    if(s->val != t->val){
        return false;
    }
    //recursively call the function to check left subtree and right subtree
    return isSameTree(s->left,t->left)&&isSameTree(s->right,t->right);
}