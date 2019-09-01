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
A positive integer is a palindrome if its decimal representation (without leading zeros) is a palindromic string 
(a string that reads the same forwards and backwards). For example, the numbers 5, 77, 363, 4884, 11111, 12121 and 349943 are palindromes.

A range of integers is interesting if it contains an even number of palindromes. 
The range [L, R], with L <= R, is defined as the sequence of integers from L to R (inclusive): 
(L, L+1, L+2, …, R-1, R). L and R are the range’s first and last numbers.

The range [L1, R1] is a subrange of [L, R] if L <= L1 <= R1 <= R. Your job is to determine how many interesting subranges of [L, R] there are.
*/  

/**
 * @param L: A positive integer
 * @param R: A positive integer
 * @return:  the number of interesting subranges of [L,R]
 */
int PalindromicRanges(int L, int R) {
   
    //corner case
    if (R <= L) {
        return 0;
    }
    
    // 1. use an array to store all palindromes between L and R;
    // use R-L+2, to include 0 and len+1 (i.e. prefix sum for L and R)
    vector<int> dp(R-L+2); // accumulation of palidrome counts
    
    for (int i=L; i<=R; ++i) {
        dp[i-L+1] = dp[i-L]; // accumulate previous value
        if (isPal(i)) {
            ++dp[i-L+1];
        }
    }
    // 2. use O(n^2) to check every case
    int count = 0;
    int len = dp.size();
    for (int i=1;i<len;++i) {
        for (int j=i-1;j>=0;--j) {
            if ((dp[i] - dp[j]) % 2 == 0) {
                ++count;
            }
        }
    }
    return count;
    
}
//helper function to see if a integer is palindromic
bool isPal(int v) {
    int rev = 0;
    int temp = v;
    while (temp != 0) {
        rev = rev * 10;
        rev += temp % 10;
        temp = temp / 10;
    }
    return v == rev;
}