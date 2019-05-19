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
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.
*/

//helper function to turn bst to a sorted vector

void inOrder(TreeNode* node,vector<int> &vec){
    if(node == nullptr){
        return;
    }
        
    if(node->left != nullptr){
        inOrder(node->left,vec);
    }
        
    vec.push_back(node->val);
    
    if(node->right != nullptr){
        inOrder(node->right,vec);
    }
        
}

/*
 * @param : the root of tree
 * @param : the target sum
 * @return: two number from tree witch sum is n
 */    
vector<int> twoSum(TreeNode * root, int n) {
    vector<int> vec;
    vector<int> res;
    //get the vector of numbers stored in the bst
    inOrder(root,vec);
    //two pointer to find the sum
    int left = 0;
    int right = vec.size() - 1;
    
    while(left <= right){
        int leftVal = vec[left];
        int rightVal = vec[right];
        
        if(leftVal + rightVal == n){
            res.push_back(leftVal);
            res.push_back(rightVal);
            return res;
        }
        else if(leftVal + rightVal < n){
            left++;
        }
        else{
            right--;
        }
    }
    
    return res;
}