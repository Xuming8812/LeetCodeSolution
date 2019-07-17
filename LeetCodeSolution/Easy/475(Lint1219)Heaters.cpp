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
Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.

Now, you are given positions of houses and heaters on a horizontal line, 
find out minimum radius of heaters so that all houses could be covered by those heaters.

So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.
*/

/**
 * @param houses: positions of houses
 * @param heaters: positions of heaters
 * @return: the minimum radius standard of heaters
 */
int findRadius(vector<int> &houses, vector<int> &heaters) {
    // Write your code here
    
    int index{0};
    int result{0};
    //sort the heaters vector, so that we can use the binary search
    sort(heaters.begin(),heaters.end());
    //loop each house, and find the min radius of heater closest to this heater
    for(auto item : houses){
        result = max(result,minRadius(heaters,item));
    }
    
    return result;
}

int minRadius(vector<int> &heaters,int house){
    int left{0};
    int right = heaters.size()-1;
    
    //binary search to find the heaters closest to the current house
    while(left<right){
        int mid = (left+right)/2;
        
        if(heaters[mid] == house){
            return 0;
        }
        else if(heaters[mid]>house){
            right = mid;
        }
        else{
            left = mid+1;
        }
        
    }
    //finally, the left will the heater with smallest index that bigger than the given house
    int dist1 = left>0?house-heaters[left-1]:INT_MAX;
    int dist2 = abs(heaters[left]-house);
    
    return min(dist1,dist2);
}