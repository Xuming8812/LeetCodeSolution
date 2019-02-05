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
Given an unsorted array of integers, find the length of longest increasing subsequence.
*/
class NumArray {
public:
	NumArray(vector<int> nums) {

		if (!nums.empty()) {
			root = buildTree(nums, 0, nums.size() - 1);
		}

	}

	void update(int i, int val) {
		updateValue(root, i, val);
	}

	int sumRange(int i, int j) {
		if (i > j) return -1;

		return query(root, i, j);
	}


private:

	struct SegmentTreeNode {

		SegmentTreeNode(int val, int a, int b) :sum(val), start(a), end(b) {};
		SegmentTreeNode(int val, int a, int b, SegmentTreeNode* c, SegmentTreeNode* d) :sum(val), start(a), end(b), left(c), right(d) {};

		int sum{ 0 };
		int start{ 0 };
		int end{ 0 };
		SegmentTreeNode* left{ nullptr };
		SegmentTreeNode* right{ nullptr };
	};

	SegmentTreeNode* root{ nullptr };

	SegmentTreeNode* buildTree(vector<int> nums, int start, int end) {
		if (start == end) {
			return new SegmentTreeNode(nums[start], start, end);
		}

		int mid = (start + end) / 2;

		SegmentTreeNode* left = buildTree(nums, start, mid);
		SegmentTreeNode* right = buildTree(nums, mid + 1, end);

		return new SegmentTreeNode(left->sum + right->sum, start, end, left, right);
	}

	void updateValue(SegmentTreeNode* root, int index, int val) {
		if (root == nullptr) return;

		if (root->start == root->end && root->start == index) {
			root->sum = val;
			return;
		}

		int mid = (root->start + root->end) / 2;

		if (index <= mid) {
			updateValue(root->left, index, val);
		}
		else {
			updateValue(root->right, index, val);
		}

		root->sum = root->left->sum + root->right->sum;

	}

	int query(SegmentTreeNode* root, int start, int end) {
		if (root == nullptr) return -1;

		if (root->start == start && root->end == end) {
			return root->sum;
		}

		int mid = (root->start + root->end) / 2;

		if (end <= mid) {
			return query(root->left, start, end);
		}
		else if (start > mid) {
			return query(root->right, start, end);
		}
		else {
			return query(root->left, start, mid) + query(root->right, mid + 1, end);
		}
	}

};