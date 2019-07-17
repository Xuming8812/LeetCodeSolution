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
 * @param root: A Tree
 * @return: Level order a list of lists of integer
 */
vector<vector<int>> levelOrder(TreeNode * root) {
    // write your code here
    vector<vector<int>> result;
    //corner case
    if(root == nullptr){
        return result;
    }
    //bfs
    queue<TreeNode*> bfs;
    bfs.push(root);
    
    while(!bfs.empty()){
        //get the length of current level
        int nums = bfs.size();
        vector<int> temp;
        //get the children nodes
        for(int i = 0;i<nums;i++){
            TreeNode* current = bfs.front();
            bfs.pop();
            
            temp.push_back(current->val);
            
            if(current->left){
                bfs.push(current->left);
            }
            
            if(current->right){
                bfs.push(current->right);
            }
            
        }
        
        result.push_back(temp);
    }
    
    return result;
}