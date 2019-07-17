#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;


/*
Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 
and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. 
This continues until all the scores have been chosen. The player with the maximum score wins.

Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.
*/


//recursive
bool PredictTheWinner(vector<int>& nums) {
    return canWin(nums, 0, 0, 1);
}

//helper function to do recursive search
bool canWin(vector<int>& nums, int sum1, int sum2, int player) {
    //base condition, when size(nums)=0
    if (nums.empty()){
        return sum1 >= sum2;
    } 
    //base condition,, when size(nums)=1
    if (nums.size() == 1) {
        if (player == 1){
            return sum1 + nums[0] >= sum2;
        } 
        else if(player == 2){
            return sum2 + nums[0] > sum1;
        } 
    }
    //get two possible moves
    vector<int> va(nums.begin()+1, nums.end());
    vector<int> vb(nums.begin(), nums.end() - 1);
    //explore
    if (player == 1) {
        return !canWin(va, sum1 + nums[0], sum2, 2) || !canWin(vb, sum1 + nums.back(), sum2, 2);
    } else if (player == 2) {
        return !canWin(va, sum1, sum2 + nums[0], 1) || !canWin(vb, sum1, sum2 + nums.back(), 1);
    }
}