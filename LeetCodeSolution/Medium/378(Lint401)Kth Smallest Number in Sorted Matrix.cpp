#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given an array of n integers, and a moving window(size k), 
move the window at each iteration from the start of the array, find the sum of the element inside the window at each moving.
*/

/**
    * @param matrix: a matrix of integers
    * @param k: An integer
    * @return: the kth smallest number in the matrix
    */
int kthSmallest(vector<vector<int>> &matrix, int k) {
    //declare a data structure to store val and position
    struct Tuple{
        int x, y, val;
        Tuple(int _x, int _y, int _val): x(_x), y(_y), val(_val){}
    };
    //compare function
    auto cmp = [](const Tuple &left, const Tuple& right){
        return left.val > right.val;
    };
    //declare a priority_queue
    priority_queue<Tuple, vector<Tuple>, decltype(cmp)> pq(cmp);
    
    int rowNum = matrix.size();
    int colNum = matrix[0].size();
    //push first column into pq
    for(int i = 0; i < rowNum; ++i){
        pq.push(Tuple(i, 0, matrix[i][0]));
    }
    //loop k-1 times, pop out then push the next element in the same row into pq
    for (int i = 0; i < k - 1; ++i){
        Tuple t = pq.top();
        pq.pop();

        if (t.y + 1 < n){
            pq.push(Tuple(t.x, t.y + 1, matrix[t.x][t.y + 1]));
        }
    }

    return pq.top().val;
}