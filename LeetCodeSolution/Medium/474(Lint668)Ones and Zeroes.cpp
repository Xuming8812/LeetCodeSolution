#include<map>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


/*
In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.

For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, there is an array with strings consisting of only 0s and 1s.

Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most once.
*/

/**
 * @param strs: an array with strings include only 0 and 1
 * @param m: An integer
 * @param n: An integer
 * @return: find the maximum number of strings
 */
int findMaxForm(vector<string>& strs, int m, int n) {
    
    vector<pair<int,int>> count;
    //get the number of 0 and 1 of each string
    for(auto str:strs){
        count.push_back(cal(str)); 
    }
        
    //actually it is a 0-1 bag question now
    //initialize the dp vector
    vector<vector<int>> dp(m+1,vector<int>(n+1,0)); 
    
    //loop for each string
    for(int k=0;k<count.size();++k){
        //loop for each total number of 0s and 1s
        for(int i=m;i>=count[k].first;--i){
            for(int j=n;j>=count[k].second;--j){
                dp[i][j]=max(dp[i][j],dp[i-count[k].first][j-count[k].second]+1);   
            }           
        }
    
    } //0-1 bag question, we should do the reverse loop for the volume

    return dp[m][n];
}

//helper function to count the number of 0 and 1
pair<int,int> cal(string str){
    int num0=0,num1=0;
    for(auto cur:str){
        if(cur=='1')
            num1++;
        else
            num0++;
    }
    return {num0,num1};
}