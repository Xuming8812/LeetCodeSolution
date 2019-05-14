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
Some people will make friend requests. The list of their ages is given and ages[i] is the age of the ith person.

Person A will NOT friend request person B (B != A) if any of the following conditions are true:

age[B] <= 0.5 * age[A] + 7
age[B] > age[A]
age[B] > 100 && age[A] < 100
Otherwise, A will friend request B.
Note that if A requests B, B does not necessarily request A. Also, people will not friend request themselves.

How many total friend requests are made?
*/


/**
 * @param ages: 
 * @return: nothing
 */
int numFriendRequests(vector<int> &ages) {
    map<int,int> count;
    //count the number of each age
    for(auto item : ages){
        count[item]++;
    }
    
    int result = 0;
    //loop all possible combination
    for(auto a : count){
        for(auto b : count){
            //if can make the request
            if(request(a.first,b.first)){
                if(a.first == b.first){
                    //come from the same age
                    result += a.second*(b.second-1);
                }
                else{
                    //come from the different age
                    result += a.second*b.second;
                }
            }
        }
    }
    
    return result;
}
//helper function to see if it`s valid to make request
bool request(int a, int b){
    return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
}