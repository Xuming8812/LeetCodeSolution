#include<map>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
/*
A quadtree is a tree data in which each internal node has exactly four children: topLeft, topRight, bottomLeft and bottomRight.
Quad trees are often used to partition a two-dimensional space by recursively subdividing it into four quadrants or regions.

We want to store True/False information in our quad tree. The quad tree is used to represent a N * N boolean grid. 
For each node, it will be subdivided into four children nodes until the values in the region it represents are all the same. 
Each node has another two boolean attributes : isLeaf and val. isLeaf is true if and only if the node is a leaf node. 
The val attribute for a leaf node contains the value of the region it represents.
*/

// Definition for a QuadTree node.
class Node {
public:
	bool val;
	bool isLeaf;
	Node* topLeft;
	Node* topRight;
	Node* bottomLeft;
	Node* bottomRight;

	Node() {}

	Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
		val = _val;
		isLeaf = _isLeaf;
		topLeft = _topLeft;
		topRight = _topRight;
		bottomLeft = _bottomLeft;
		bottomRight = _bottomRight;
	}
};


Node* intersect(Node* quadTree1, Node* quadTree2)
{
	//if one node is leaf and the value is true, return the node directedly
	if (quadTree1->isLeaf && quadTree1->val) return quadTree1;
	if (quadTree2->isLeaf && quadTree2->val) return quadTree2;

	//if one node is leaf and the value is false, return the other node directedly
	if (quadTree1->isLeaf && !quadTree1->val) return quadTree2;
	if (quadTree2->isLeaf && !quadTree2->val) return quadTree1;

	//recursively call the function to calculate values of four children`s intersection results;
	auto tl = intersect(quadTree1->topLeft, quadTree2->topLeft);
	auto tr = intersect(quadTree1->topRight, quadTree2->topRight);
	auto bl = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
	auto br = intersect(quadTree1->bottomRight, quadTree2->bottomRight);

	//if all values of children nodes equal, combine the 4 nodes to 1 leaf node
	if (tl->val == tr->val && tl->val == bl->val && tl->val == br->val && tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf)
		return new Node(tl->val, true, nullptr, nullptr, nullptr, nullptr);
	else
		return new Node(false, false, tl, tr, bl, br);
}