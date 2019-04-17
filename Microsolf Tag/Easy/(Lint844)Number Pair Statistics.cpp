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
Given a List <Point> p, find the number of (i,j) pairs that satisfy both p[i].x + p[j].x and p[i].y + p[j].y(i < j) can be divisible by 2.
*/


/**
 * @param p: the point List
 * @return: the numbers of pairs which meet the requirements
 */
int pairNumbers(vector<Point> &p) {
    // Write your code here
    vector<int> count(4);
    
    for(auto item : p){
        //both even
        if(item.x%2==0 && item.y%2 == 0){
            count[0]++;
        }
        else if(item.x%2==1 && item.y%2 == 1){
            count[1]++;
        }
        else if(item.x%2==0 && item.y%2 == 1){
            count[2]++;
        }
        else{
            count[3]++;
        }
    }
    
    int result{0};
    
    for(int i = 0;i<4;i++){
        result += count[i]*(count[i]-1)/2;
    }
    
    return result;
}