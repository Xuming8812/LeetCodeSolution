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

    struct Tuple{
        int x, y, val;
        Tuple(int _x, int _y, int _val): x(_x), y(_y), val(_val){}
    };

    auto cmp = [](const Tuple &left, const Tuple& right){
        return left.val > right.val;
    };

    priority_queue<Tuple, vector<Tuple>, decltype(cmp)> pq(cmp);
    int m = (int)matrix.size();
    int n = (int)matrix[0].size();

    for(int i = 0; i < m; ++i){
        pq.push(Tuple(i, 0, matrix[i][0]));
    }

    for (int i = 0; i < k - 1; ++i){
        Tuple t = pq.top();
        pq.pop();

        if (t.y + 1 < n){
            pq.push(Tuple(t.x, t.y + 1, matrix[t.x][t.y + 1]));
        }
    }

    return pq.top().val;
}