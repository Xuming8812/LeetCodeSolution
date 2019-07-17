#include<map>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
Find all strobogrammatic numbers that are of length = n.
*/

/**
 * @param n: the length of strobogrammatic number
 * @return: All strobogrammatic numbers
 */
vector<string> findStrobogrammatic(int n) {
    // write your code here
    //basic result of n=0 and n=1
    vector<string> even{""};
    vector<string> odd{"0","1","8"};
    //loop all length
    for(int i=2;i<=n;i++){
        vector<string> temp;
        //based on previous even or odd result
        for(auto item:(i%2==0?even:odd)){
            temp.push_back("1"+item+"1");
            temp.push_back("6"+item+"9");
            temp.push_back("9"+item+"6");
            temp.push_back("8"+item+"8");
            
            if(i!=n){
                temp.push_back("0"+item+"0");
            }
        }
        //update even or odd
        if(i%2==0){
            even = temp;
        }
        else{
            odd = temp;
        }
    }
    
    if(n%2==0){
        return even;
    }
    else{
        return odd;
    }
}

