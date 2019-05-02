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
 * @param root: a TreeNode
 * @return: return a boolean
 */
bool checkEqualTree(TreeNode * root) {
    // write your code here
    
    int sum = helper(root);
    
    if(sum == 0){
        return dict[0]>1;
    }
    
    if(sum%2 == 0){
        return dict.find(sum/2)!=dict.end();
    }
    
    return false;
}

map<int,int>dict;

int helper(TreeNode * root){
    if(root == nullptr){
        return 0;
    }
    
    int sum = root->val + helper(root->left)+helper(root->right);
    
    dict[sum]++;
    
    return sum;
}