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
Given a binary tree, find the subtree with maximum average. Return the root of the subtree.
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Record{
public:
    Record():size(0),sum(0){};
    Record(int inputSize, int inputSum):size(inputSize),sum(inputSum){};
    int size;
    int sum;
};

TreeNode * findSubtree2(TreeNode * root) {
    // write your code here
    if(root == nullptr){
        return nullptr;
    }
    
    findHelper(root);
    
    return maxNode;
}

Record findHelper(TreeNode* root){
    if(root == nullptr){
        return Record();
    }
    
    Record left = findHelper(root->left);
    Record right = findHelper(root->right);
    
    Record current(left.size+right.size+1,left.sum+right.sum+root->val);
    
    if(maxNode == nullptr || (maxRecord.sum*current.size)<(current.sum*maxRecord.size)){
        maxNode = root;
        maxRecord = current;
    }
    
    return current;
}

TreeNode* maxNode{nullptr};
Record maxRecord;