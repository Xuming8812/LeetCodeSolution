#include<map>
#include<algorithm>
#include<vector>
using namespace std;

/*
Given a binary search tree(BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


void helperFindMode(TreeNode* root, map<int, int>& count, int & maxTime);

vector<int> findMode(TreeNode* root)
{
	//use a hash map to count numbers in the BST
	map<int, int>count;
	int maxTime{ 0 };

	if (root == nullptr)
	{
		return {};
	}

	//call the helper function to count
	helperFindMode(root, count, maxTime);

	vector<int> results;
	//save mode if its count equals the maxTime
	for (auto item : count)
	{
		if (item.second == maxTime)
		{
			results.push_back(item.first);
		}
	}

	return results;


}
//count the numbers in middle traversal
void helperFindMode(TreeNode* root, map<int, int>& count, int & maxTime)
{
	if (root == nullptr)
	{
		return;
	}
	//left first
	helperFindMode(root->left, count, maxTime);
	//count
	count[root->val]++;
	//update the maxTime value
	maxTime = max(maxTime, count[root->val]);
	//right last
	helperFindMode(root->right, count, maxTime);
}


