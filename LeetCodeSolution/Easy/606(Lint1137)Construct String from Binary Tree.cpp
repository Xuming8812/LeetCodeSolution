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
You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.

The null node needs to be represented by empty parenthesis pair "()". 
And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping relationship between 
the string and the original binary tree
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
    
/**
 * @param t: the root of tree
 * @return: return a string
 */
string tree2str(TreeNode * t) {
    // write your code here
    if(t==nullptr) return "";
    
    string result = to_string(t->val);
    
    bool hasLeftNode=false;
    
    if(t->left){
        hasLeftNode = true;
        result = result + "("+tree2str(t->left)+")";
    }
    if(t->right){
        if(!hasLeftNode){
            result+="()";
        }
        result = result+"("+tree2str(t->right)+")";
    }
    
    return result;
}