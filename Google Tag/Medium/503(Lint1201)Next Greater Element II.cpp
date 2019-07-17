#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;


/*
Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. 
The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, 
which means you could search circularly to find its next greater number. 
If it doesn't exist, output -1 for this number.
*/


/**
 * @param nums: an array
 * @return: the Next Greater Number for every element
 */

//brute force
vector<int> nextGreaterElements(vector<int>& nums) {
    int length = nums.size();
    //initialize the result vector by -1
    vector<int> result(length,-1);
    //loop each element
    for (int i = 0; i < length; ++i) {
        //loop all element from this index to its previous one by using %
        for (int j = i + 1; j < i + length; ++j) {
            if (nums[j % length] > nums[i]) {
                result[i] = nums[j % length];
                break;
            }
        }
    }
    return result;
}

//use a stack, O(n)
vector<int> nextGreaterElements(vector<int>& nums) {
    int length = nums.size();
    
    vector<int> result(length, -1);
    //use a store to store the index of each number, there may be duplicated in the vector
    stack<int> store;
    //loop twice
    for (int i = 0; i < 2 * length; ++i) {
        //get the number
        int num = nums[i % length];
        //get the next greater num of elements in the stack
        while (!store.empty() && nums[store.top()] < num) {
            result[store.top()] = num; 
            store.pop();
        }
        //push the current index in the stack
        if (i < length) store.push(i);
    }
    
    return result;
}    
