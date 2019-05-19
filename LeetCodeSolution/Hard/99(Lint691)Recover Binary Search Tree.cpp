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
In a binary search tree, (Only) two nodes are swapped. Find out these nodes and swap them. If there no node swapped, return original root of tree.
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//two nodes to store the swapped the nodes
TreeNode *node1 = nullptr;
TreeNode *node2 = nullptr;

//the variable to store the last node visited in the binary search tree,
//in a inorder traversal, the current node should always greater than last node`s value
TreeNode *lastNode = new TreeNode(INT_MIN);
/**
 * @param root: the given tree
 * @return: the tree after swapping
 */
TreeNode * bstSwappedNode(TreeNode * root) {
    //corner case
    if(root == nullptr){
        return root;
    }
    //call the helper function to find the two swapped nodes
    find(root);
    
    //corner case that there are less than 2 nodes swapped
    if(node1 == nullptr && node2 == nullptr){
        return root;
    }
    //swap the value of the two found nodes
    int temp = node1->val;
    node1->val = node2->val;
    node2->val = temp;
    //return the current root
    return root;
}

//helper function to find the two swapped nodes
void find(TreeNode *root){
    if(root == nullptr){
        return;
    }
    //dfs left subtree
    find(root->left);
    //find the first node
    if(node1 == nullptr && root->val < lastNode->val){
        node1 = lastNode;
    }
    //find the second node
    if(node1 != nullptr && root->val < lastNode->val){
        node2 = root;
    }
    //update the root 
    lastNode = root;
    //dfs right subtree
    find(root->right);
}