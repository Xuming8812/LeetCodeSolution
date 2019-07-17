
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
Given two binary trees and imagine that when you put one of them to cover the other, 
some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap,
 then sum node values up as the new value of the merged node. 
Otherwise, the NOT null node will be used as the node of new tree.
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/**
 * @param t1: the root of the first tree
 * @param t2: the root of the second tree
 * @return: the new binary tree after merge
 */
TreeNode * mergeTrees(TreeNode * t1, TreeNode * t2) {
    // Write your code here
    //base condition
    if(t1 == nullptr){
        return t2;
    }
    
    if(t2 == nullptr){
        return t1;
    }
    //update the current node
    TreeNode* root = new TreeNode(t1->val+t2->val);
    //get the left and right children
    root->left = mergeTrees(t1->left,t2->left);
    root->right = mergeTrees(t1->right,t2->right);
    
    return root;
}