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
Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.
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


//bfs version
    /**
     * @param root: the root of tree
     * @return: the vertical order traversal
     */
    vector<vector<int>> verticalOrder(TreeNode * root) {
        // write your code here
        vector<vector<int>> result;
        
        //corner case
        if(root == nullptr){
            return result;
        }
        
        map<int,vector<int>> store;
        //store node and its column
        queue<pair<TreeNode*,int> > bfsStore;
        //start with root
        bfsStore.push(make_pair(root,0));
        //bfs
        while(!bfsStore.empty()){
            //get current node
            pair<TreeNode*,int> current = bfsStore.front();
            bfsStore.pop();
            //save in an ordered map
            store[current.second].push_back(current.first->val);
            
            //left
            if(current.first->left){
                bfsStore.push(make_pair(current.first->left,current.second -1));
            }
            
            //right
            if(current.first->right){
                bfsStore.push(make_pair(current.first->right,current.second +1));
            }
        }
        //save result in a vector
        for(auto item: store){
            result.push_back(item.second);
        }
        
        return result;
    }



//dfs version

/**
 * @param root: the root of tree
 * @return: the vertical order traversal
 */
vector<vector<int>> verticalOrder(TreeNode * root) {
    // write your code here
    
    vector<vector<int>> result;
    //corner case
    if(root == nullptr){
        return result;
    }
    //call the helper function
    helper(root,0);
    //save the result in a vector
    for(auto item : store){
        result.push_back(item.second);
    }
    
    return result;
    
}
//helper function to preorder traversal to store the node and its column number
void helper(TreeNode * root, int column){
    //base condition
    if(root == nullptr){
        return;
    }
    //store the val to its corresponding row
    store[column].push_back(root->val);
    //dfs
    helper(root->left,column-1);
    helper(root->right,column+1);
}

map<int,vector<int>> store;