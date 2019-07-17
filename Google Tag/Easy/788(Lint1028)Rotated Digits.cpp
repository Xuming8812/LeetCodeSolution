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
X is a good number if after rotating each digit individually by 180 degrees, we get a valid number that is different from X.  
Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. 0, 1, and 8 rotate to themselves; 
2 and 5 rotate to each other; 6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number and become invalid.

Now given a positive number N, how many numbers X from 1 to N are good?
*/  



/**
 * @param N: a positive number
 * @return: how many numbers X from 1 to N are good
 */
int rotatedDigits(int N) {
    // write your code here
    int result{0};
    //check all numbers between 1 to N
    for(int i = 1;i<=N;i++){
        result +=rotate(i);
    }
    
    return result;
}
//helper function
int rotate(int input){
    bool isSame{true};
    
    while(input){
        //get each digit
        int bit = input%10;
        input /=10;
        //unable to rotate
        if(bit == 3 || bit == 4||bit == 7){
            return 0;
        }
        else if(bit == 2 || bit == 5||bit == 6||bit == 9){
            //rotate to a different number                
            isSame = false;
        }    
    }
    
    return isSame?0:1;
}