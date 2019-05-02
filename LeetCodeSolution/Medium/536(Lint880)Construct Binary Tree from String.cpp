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
You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. 
The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.
*/

/**
 * @param s: a string
 * @return: a root of this tree
 */
TreeNode * str2tree(string &s) {
    // write your code here
    
    if(s.empty()){
        return nullptr;
    }
    
    int length = s.size();
    
    int index = 1;
    while(index<length && isdigit(s[index])){
        index++;
    }
    
    TreeNode* root = new TreeNode(stoi(s.substr(0,index)));
    
    if(index == length){
        return root;
    }
    
    int bracket = 0;
    for(int i = index;i<length;i++){
        bracket+=(s[i] == '(');
        bracket-=(s[i] == ')');
        
        //valid parenthesis
        if(bracket == 0){
            string leftString = s.substr(index+1,i-index-1);
            root->left = str2tree(leftString);
            if(i!=length-1){
                string rightString = s.substr(i+2,length-i-3);
                root->right = str2tree(rightString);
            }
            
            break;
            
        }
    }
    
    return root;
    
}