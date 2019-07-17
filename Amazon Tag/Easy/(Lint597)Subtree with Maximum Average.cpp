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

//define a class to record the sum and total number of nodes of a tree
class Record{
public:
    Record():size(0),sum(0){};
    Record(int inputSize, int inputSum):size(inputSize),sum(inputSum){};
    int size;
    int sum;
};

TreeNode * findSubtree2(TreeNode * root) {
    // write your code here
    //corner case
    if(root == nullptr){
        return nullptr;
    }
    //call the helper function
    findHelper(root);
    
    return maxNode;
}
//the helper function to record the sum and number of children nodes of a given node
Record findHelper(TreeNode* root){
    if(root == nullptr){
        return Record();
    }
    //post order traversal
    Record left = findHelper(root->left);
    Record right = findHelper(root->right);
    //create the record for the current node
    Record current(left.size+right.size+1,left.sum+right.sum+root->val);
    //see if the node with max average, use multiplication instead of division
    if(maxNode == nullptr || (maxRecord.sum*current.size)<(current.sum*maxRecord.size)){
        maxNode = root;
        maxRecord = current;
    }
    
    return current;
}

TreeNode* maxNode{nullptr};