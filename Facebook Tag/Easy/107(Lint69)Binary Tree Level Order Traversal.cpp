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
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
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
 * @param root: A Tree
 * @return: Level order a list of lists of integer
 */
vector<vector<int>> levelOrder(TreeNode * root) {
    // write your code here
    vector<vector<int>> result;
    if(root == nullptr){
        return result;
    }
    
    queue<TreeNode*> bfs;
    bfs.push(root);
    
    while(!bfs.empty()){
        int nums = bfs.size();
        vector<int> temp;
        
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