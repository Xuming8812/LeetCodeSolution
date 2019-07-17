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
Given a List of intervals, the length of each interval is 1000, such as [500,1500], [2100,3100].
Give a number arbitrarily and determine if the number belongs to any of the intervals.return True or False.
*/

/**
 * @param intervalList: 
 * @param number: 
 * @return: return True or False
 */
string isInterval(vector<vector<int>> &intervalList, int number) {
    // Write your code here
    //just loop all intervals
    for(auto item : intervalList){
        if(number>=item[0]&&number<=item[1]){
            return "True";
        }
    }
    
    return "False";
}