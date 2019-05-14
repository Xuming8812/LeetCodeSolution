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
Given an integer array nums, and then you need to implement two functions:

update(i, val) Modify the element whose index is i to val.
sumRange(l, r) Return the sum of elements whose indexes are in range of [l, r][l,r].
*/

class NumArray {
public:

    //constructor
    NumArray(vector<int> nums) {   
        if(!nums.empty()){
            //build a segment tree
            root = buildTree(nums,0,nums.size()-1);
        }
        
    }
    //update one element
    void update(int i, int val) {
        updateValue(root,i,val);
    }
    //return the sum of the range
    int sumRange(int i, int j) {
        if(i>j) return -1;
        
        return query(root,i,j);
    }
    
    
private:
    //the segment tree node
    struct SegmentTreeNode{
        //constructor
        SegmentTreeNode(int val, int a,int b):sum(val),start(a),end(b){};
        SegmentTreeNode(int val, int a,int b,SegmentTreeNode* c, SegmentTreeNode* d):sum(val),start(a),end(b),left(c),right(d){};
        //data member
        int sum{0};
        int start{0};
        int end{0};
        //left right children
        SegmentTreeNode* left{nullptr};
        SegmentTreeNode* right{nullptr};
    };
    //the root node 
    SegmentTreeNode* root{nullptr};
    //build the tree by the given vector
    SegmentTreeNode* buildTree(vector<int> nums, int start, int end){
        //base condition, the leave value
        if(start == end){
            return new SegmentTreeNode(nums[start],start,end);
        }
        //split by half
        int mid = (start+end)/2;
        //post order traversal
        SegmentTreeNode* left = buildTree(nums,start,mid);
        SegmentTreeNode* right = buildTree(nums,mid+1,end);
        //create current root
        return new SegmentTreeNode(left->sum+right->sum,start,end,left,right);
    }

    //update a value in the vector, all node affected should also be updated
    void updateValue(SegmentTreeNode* root, int index, int val){
        //corner case
        if(root==nullptr) return;
        //just find the leave node, update the value directly
        if(root->start == root->end && root->start == index){
            root->sum = val;
            return;
        }
        //split the range by half
        int mid = (root->start+root->end)/2;
        
        if(index<=mid){
            //if in the left subtree
            updateValue(root->left,index,val);
        }
        else{
            //if in the right subtree
            updateValue(root->right,index,val);
        }
        //update current sum value
        root->sum = root->left->sum + root->right->sum;
        
    }
    //query the sum of the range
    int query(SegmentTreeNode* root, int start, int end){
        //base condition
        if(root==nullptr) return -1;
        //just find the range, return the result
        if(root->start == start && root->end == end){
            return root->sum;
        }
        //split the range by half
        int mid = (root->start+root->end)/2;
        
        if(end<=mid){
            //if the given range is in left subtree
            return query(root->left,start,end);
        }
        else if(start>mid){
            //if the given range is in right subtree
            return query(root->right,start,end);
        }
        else{
            //search both the left and right subtree
            return query(root->left,start,mid) + query(root->right,mid+1,end);
        }    
    }
    
};