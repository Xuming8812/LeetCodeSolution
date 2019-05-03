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
Given the root of a tree, you are asked to find the most frequent subtree sum. 
The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). 
So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.
*/    


/**
 * @param root: the root
 * @return: all the values with the highest frequency in any order
 */


vector<int> findFrequentTreeSum(TreeNode * root) {
    // Write your code here
    vector<int> result;
    
    if(root == nullptr){
        return result;
    }
    
    helper(root);
    
    for(auto item : dict){
        if(item.second == maxFreq){
            result.push_back(item.first);
        }
    }
    
    return result;
}

map<int,int> dict;
int maxFreq{INT_MIN};

int helper(TreeNode * root){
    if(root == nullptr){
        return 0;
    }
    
    int left = helper(root->left);
    int right = helper(root->right);
    
    int sum = left + right + root->val;
    
    dict[sum]++;
    
    maxFreq = max(maxFreq,dict[sum]);
    
    return sum;
}