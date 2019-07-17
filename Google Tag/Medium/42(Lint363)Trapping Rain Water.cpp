#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<unordered_map>

using namespace std;

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
*/

/**
 * @param heights: a list of integers
 * @return: a integer
 */

//stack
int trapRainWater(vector<int> &heights) {
    // write your code here
    
    stack<int> store;
    
    int i = 0, result = 0, length = heights.size();
    //loop each height
    while (i < length) {
        //the current height height is lower than the left edge
        if (store.empty() || heights[i] <= heights[store.top()]) {
            store.push(i++);
        } else {
            //get the current low height
            int t = store.top();
            store.pop();
            
            if (store.empty()){
                continue;
            } 
            //update the result
            result += (min(heights[i], heights[store.top()]) - heights[t]) * (i - store.top() - 1);
        }
    }
    return result;
}

//two pointers  
int trapRainWater(vector<int> &heights) {
    // write your code here
    
    int left = 0, right = heights.size()-1;
    
    int leftEdge = -1,rightEdge = -1;
    
    int result = 0;
    
    while(left<=right){
        if(heights[left]>=leftEdge){
            leftEdge = heights[left];
            left++;
            continue;
        }
        
        if(heights[right]>=rightEdge){
            rightEdge = heights[right];
            right--;
            continue;
        }
        
        if(leftEdge<=rightEdge){
            result+=(leftEdge-heights[left]);
            left++;
        }
        else{
            result+=(rightEdge-heights[right]);
            right--;                
        }
    }
    
    return result;
}