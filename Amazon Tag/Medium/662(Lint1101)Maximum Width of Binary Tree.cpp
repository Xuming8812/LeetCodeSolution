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
Given a binary tree, write a function to get the maximum width of the given tree. 
The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes 
(the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<pair<int,int>> edge;
/**
 * @param depth: 当前节点的深度(即层数), 根节点为0
 * @param idx: 当前节点在这一层的位置 (对应满二叉树的位置, 从0开始)
 */
void dfs(TreeNode * now, int depth, int idx) {
    if (now == NULL) {
        return ;
    }
    if (edge.size() <= depth) {
        edge.push_back(pair<int,int>(idx, idx));
    }
    else {
        edge[depth].first  = min(idx, edge[depth].first);
        edge[depth].second = max(idx, edge[depth].second);
    }
    dfs(now->left,  depth + 1, idx * 2);
    dfs(now->right, depth + 1, idx * 2 + 1);
}


/**
 * @param root: the root
 * @return: the maximum width of the given tree
 */
int widthOfBinaryTree(TreeNode * root) {
    edge.clear();
    dfs(root, 0, 0);
    int ans = 0;
    for (auto &i : edge) {
        ans = max(i.second - i.first + 1, ans); 
    }
    return ans;
}