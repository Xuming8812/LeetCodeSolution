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
Given scores of N athletes, find their relative ranks and the people with the top three highest scores, 
who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".
*/  

/**
 * @param nums: List[int]
 * @return: return List[str]
 */
vector<string> findRelativeRanks(vector<int> &nums){
    // write your code here
    //store the original score and index
    map<int, int> score;
    //save the index of each score
    for (int i = 0; i < nums.size(); i++){
        score[nums[i]] = i;
    }
    //sort in descending order
    sort(nums.rbegin(), nums.rend());
    
    vector<string> answer(nums.size());
    //sort
    for (int i = 0; i < nums.size(); i++){
        
        string res = to_string(i + 1);
        if (i == 0)
            res = "Gold Medal";
        if (i == 1)
            res = "Silver Medal";
        if (i == 2)
            res = "Bronze Medal";
        
        answer[score[nums[i]]] = res;
    }
    return answer;
}