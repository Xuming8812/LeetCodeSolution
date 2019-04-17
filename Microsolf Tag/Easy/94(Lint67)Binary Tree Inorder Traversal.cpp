#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

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
 * @return: Inorder in ArrayList which contains node values.
 */
vector<int> inorderTraversal(TreeNode * root) {
    // write your code here
    
    //declare the vector to return
    vector<int> result;
    //the stack to store the nodes
    stack<TreeNode*> inorder;
    //get the current node
    TreeNode* current = root;
    //dfs
    while(!inorder.empty() || current!=nullptr){
        //put all left children into stack
        while(current!=nullptr){
            inorder.push(current);
            current = current->left;
        }
        
        //get the left most node
        current = inorder.top();
        //save the current node`s value
        result.push_back(current->val);
        //pop the top of the stack
        inorder.pop();
        //set the current by its right child
        current = current->right;
    }
    
    return result;
}