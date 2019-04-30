#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<unordered_map>

using namespace std;

/*
Given a string, count number of subsequences of the form a^i b^j c^ k, i.e., it consists of i a characters, followed by j b characters, followed by k c characters where i >= 1, j >=1 and k >= 1.

Note: Two subsequences are considered different if the set of array indexes picked for the 2 subsequences are different.
*/ 

/**
 * @param source: the input string
 * @return: the number of subsequences 
 */
int countSubsequences(string &source) {
    // write your code here
    
    int length = source.size();
    
    //dp_a[i] number of subsequences that end with a
    //dp_b[i] number of subsequences that end with b
    //dp_c[i] number of subsequences that end with c
    
    vector<int> dp_a(length+1),dp_b(length+1),dp_c(length+1);
    
    for(int i = 1;i<=length;i++){
        if(source[i-1] == 'a'){
            dp_a[i] = 2*dp_a[i-1]+1;
            dp_b[i] = dp_b[i-1];
            dp_c[i] = dp_c[i-1];
        }
        else if(source[i-1] == 'b'){
            dp_a[i] = dp_a[i-1];
            dp_b[i] = 2*dp_b[i-1]+dp_a[i-1];
            dp_c[i] = dp_c[i-1];                
        }
        else if(source[i-1] == 'c'){
            dp_a[i] = dp_a[i-1];
            dp_b[i] = dp_b[i-1];
            dp_c[i] = 2*dp_c[i-1]+dp_b[i-1];
        }
    }
    
    return dp_c[length];
}