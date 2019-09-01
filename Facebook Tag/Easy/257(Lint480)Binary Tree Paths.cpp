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
Given a binary tree, return all root-to-leaf paths.
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
 * @param root: the root of the binary tree
 * @return: all root-to-leaf paths
 */
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    //corner case
    if(root==nullptr){
        return result;
    }
    //call the helper function
    binaryTreePathsHelper(root,result,"");
    
    return result;
}
//the helper function
void binaryTreePathsHelper(TreeNode* root,vector<string>& results,string path)
{
    string currentPath = path + to_string(root->val);
    //meet a leaf, save the current result
    if(root->left == nullptr && root->right == nullptr){          
        results.push_back(currentPath);
    }
    
    currentPath+="->";
    
    //dfs
    if(root->left){
        binaryTreePathsHelper(root->left,results,currentPath);
    }

    if(root->right){
        binaryTreePathsHelper(root->right,results,currentPath);
    }            
}