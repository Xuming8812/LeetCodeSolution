
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
Given a binary tree, find the leftmost value in the last row of the tree.
*/

/**
 * @param root: a root of tree
 * @return: return a integer
 */
int findBottomLeftValue(TreeNode * root) {
    // write your code here
    if(root == nullptr){
        return 0;
    }
    queue<TreeNode*> bfs;
    
    int result{0};
    
    bfs.push(root);
    
    while(!bfs.empty()){
        TreeNode* current = bfs.front();
        int size = bfs.size();
        result = current->val;
        
        for(int i = 0;i<size;i++){
            current= bfs.front();
            bfs.pop();
            
            if(current->left){
                bfs.push(current->left);
            }
            
            if(current->right){
                bfs.push(current->right);
            }
        }
    }
    
    return result;
}