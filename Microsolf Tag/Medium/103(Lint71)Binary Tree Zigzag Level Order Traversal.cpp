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
        this->left = nullptr;
        this->right = nullptr;
    }
};


/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).
*/



/**
 * @param root: A Tree
 * @return: A list of lists of integer include the zigzag level order traversal of its nodes' values.
 */
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    
    if(!root) return result;
    
    queue<TreeNode*> bfs;
    
    bfs.push(root);
    
    bool isRight{true};
    
    while(!bfs.empty()){
        int length = bfs.size();
        
        vector<int> row;
        
        for(int i = 0;i<length;i++){
            TreeNode* cur = bfs.front();
            bfs.pop();
            
            row.push_back(cur->val);
            
            if(cur->left) bfs.push(cur->left);
            if(cur->right) bfs.push(cur->right);
        }
        
        if(!isRight){
            reverse(row.begin(),row.end());
        }
        
        isRight = !isRight;
        
        result.push_back(row);
    }
    
    return result;
}