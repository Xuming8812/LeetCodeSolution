    
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
You're now a baseball game point recorder.

Given a list of strings, each string can be one of the 4 following types:

Integer (one round's score): Directly represents the number of points you get in this round.
"+" (one round's score): Represents that the points you get in this round are the sum of the last two valid round's points.
"D" (one round's score): Represents that the points you get in this round are the doubled data of the last valid round's points.
"C" (an operation, which isn't a round's score): Represents the last valid round's points you get were invalid and should be removed.
Each round's operation is permanent and could have an impact on the round before and the round after.
You need to return the sum of the points you could get in all the rounds.
*/
    
/**
 * @param ops: the list of operations
 * @return:  the sum of the points you could get in all the rounds
 */
int calPoints(vector<string> &ops) {
    // Write your code here
    vector<int> store;
    
    for(auto item:ops){
        if(item == "C"){
            if(store.empty()){
                return -1;
            }
            store.pop_back();
        }
        else if(item == "D"){
            if(store.empty()){
                return -1;
            }
            int temp = store.back();
            store.push_back(2*temp);
        }
        else if(item == "+"){
            if(store.size()<2){
                return -1;
            }
            int last1 = store.back();
            int last2 = store[store.size()-2];
            store.push_back(last1+last2);
        }
        else{
            store.push_back(stoi(item));
        }
    }
    
    int result{0};
    
    for(auto item : store){
        result+=item;
    }
    
    return result;
}