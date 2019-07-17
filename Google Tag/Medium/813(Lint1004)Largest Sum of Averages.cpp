#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<unordered_set>

using namespace std;

/*
We partition a row of numbers A into at most K adjacent (non-empty) groups, then our score is the sum of the average of each group. 
What is the largest score we can achieve?

Note that our partition must use every number in A, and that scores are not necessarily integers.
*/

/**
 * @param A: an array
 * @param K: an integer
 * @return: the largest score
 */
double largestSumOfAverages(vector<int> &A, int K) {
    // Write your code here
    //get length
    int n = A.size();
    
    //dp[i][j] is the largestSumOfAverages of first j elements with i partitions
    vector<vector<double>> dp(K + 1,vector<double>(n + 1));
    //prefix sum vector
    vector<double>sum(n + 1,0);

    for (int i = 1; i <= n; i++){
        //sum up
        sum[i] = sum[i - 1] + A[i - 1];
        //the sum of average value with no partitions
        dp[1][i] = sum[i] / i;
    }
    
    //loop all possible partitions
    for (int i = 2; i <= K; i++) {
        //loop all possible number of elements to be partitioned 
        for (int j = i; j <= n; j++) {
            for (int k = i - 1; k < j; k++){
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + (sum[j]-sum[k]) / (j-k));
            }
        }
    }
    return dp[K][n];
}