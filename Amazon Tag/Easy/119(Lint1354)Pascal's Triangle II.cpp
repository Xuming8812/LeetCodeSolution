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
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
*/


/**
 * @param rowIndex: a non-negative index
 * @return: the kth index row of the Pascal's triangle
 */
vector<int> getRow(int rowIndex) {
    // write your code here
    //corner case
    if(rowIndex<1) return {};
    
    vector<int> result(rowIndex+1,0);
    result[0] = 1;
    //loop each level
    for(int i = 1;i<=rowIndex;i++){
        //update from right to left
        for(int index = i; index>0;index--){
            result[index] = result[index]+result[index-1];
        }
    }
    
    return result;
}