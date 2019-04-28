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
Given a binary tree, find the subtree with maximum sum. Return the root of the subtree.
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//traverse to find k and record parent node for each node
TreeNode *dfs(TreeNode *rt, int k, map<TreeNode *, TreeNode *> &parents)
    {
        TreeNode *res = rt, *tmp = NULL;

        if (rt->left != NULL)
        {
            parents[rt->left] = rt;
            tmp = dfs(rt->left, k, parents);
            res = tmp->val == k ? tmp : res;
        }

        if (rt->right != NULL)
        {
            parents[rt->right] = rt;
            tmp = dfs(rt->right, k, parents);
            res = tmp->val == k ? tmp : res;
        }

        return res;
}

/**
 * @param root: the root
 * @param k: an integer
 * @return: the value of the nearest leaf node to target k in the tree
 */
int findClosestLeaf(TreeNode *root, int k)
{
    map<TreeNode *, TreeNode *> parents;
    TreeNode *pValK = dfs(root, k, parents); // find k and set parents

    queue<TreeNode *> q;
    set<TreeNode *> vis;
    q.push(pValK);
    vis.insert(pValK);
    while (!q.empty()){
        TreeNode *t = q.front();
        q.pop();
        //the nearest root
        if (t->left == NULL && t->right == NULL){
            return t->val;
        }
        //priority 1: left substree
        if (t->left != NULL && vis.find(t->left) == vis.end()){
            q.push(t->left);
            vis.insert(t->left);
        }
        //priority 2: right substree
        if (t->right != NULL && vis.find(t->right) == vis.end()){
            q.push(t->right);
            vis.insert(t->right);
        }
        //priority 2: not substree
        if (parents.find(t) != parents.end() && vis.find(parents[t]) == vis.end()){
            q.push(parents[t]);
            vis.insert(parents[t]);
        }
    }

    return 0;
}