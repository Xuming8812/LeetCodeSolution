#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<unordered_set>

using namespace std;

/*
Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and 
is decoded back to the original list of strings.

Please implement encode and decode
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * @param root: a root of integer
 * @return: return a integer
 */
vector<int> findMode(TreeNode* root){
    map<int, int>count;
    
    int maxTime{ 0 };

    if (root == nullptr){
        return {};
    }

    helperFindMode(root, count, maxTime);

    vector<int> results;

    for (auto item : count){
        if (item.second == maxTime){
            results.push_back(item.first);
        }
    }

    return results;
}
//helper function to count the ocurrence of each node
void helperFindMode(TreeNode* root, map<int, int>& count, int & maxTime){
    //base condition
    if (root == nullptr){
        return;
    }
    //inorder traversal
    helperFindMode(root->left, count, maxTime);

    count[root->val]++;

    maxTime = max(maxTime, count[root->val]);

    helperFindMode(root->right, count, maxTime);
}