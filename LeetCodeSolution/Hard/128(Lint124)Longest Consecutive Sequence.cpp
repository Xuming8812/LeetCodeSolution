#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<unordered_map>
#include<unordered_set>

using namespace std;

/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
*/ 

/**
 * @param num: A list of integers
 * @return: An integer
 */
int longestConsecutive(vector<int> &num) {
    // write your code here
    int result{0};
    
    //store the numbers in a hashset
    unordered_set<int> store(num.begin(),num.end());

    //loop all numbers
    for(auto item:num){
        //if unvisited
        if(store.count(item) == 1){
            //remove from the set
            store.erase(item);
            //search the left and right neighbor
            int left = item-1;
            int right = item+1;
            //move left
            while(store.count(left)){
                store.erase(left);
                left = left-1;
            }
            //move right
            while(store.count(right)){
                store.erase(right);
                right = right+1;

            }
            //get the max length of consecutive sequence
            result = max(result,right-left-1);
        }
    }
    
    return result;
}