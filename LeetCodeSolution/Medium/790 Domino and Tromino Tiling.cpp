#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
We have two types of tiles: a 2x1 domino shape, and an "L" tromino shape. These shapes may be rotated.

XX  <- domino

XX  <- "L" tromino
X
Given N, how many ways are there to tile a 2 x N board? Return your answer modulo 10^9 + 7.

(In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on 
the board such that exactly one of the tilings has both squares occupied by a tile.)
*/


//use dp[i][0] indicate full condition of ith place, such as XXXX
//															 XXXX
//use dp[i][1] indicate the following condition of ith place, such as XXXX
//																	  XXX
//use dp[i][2] indicate the following condition of ith place, such as XXX
//															          XXXX
int numTilings(int N) {
	vector<vector<long>> dp(N + 1, vector<long>(3, 0));

	dp[0][0] = 1;			//set initial values of dp matrix	
	dp[1][0] = 1;

	for (int i = 2; i <= N; i++)
	{
		dp[i][0] = (dp[i - 1][0] + dp[i - 2][0] + dp[i - 1][1] + dp[i - 1][2]) % 1000000007;
		dp[i][1] = (dp[i - 2][0] + dp[i - 1][2]) % 1000000007;
		dp[i][2] = (dp[i - 2][0] + dp[i - 1][1]) % 1000000007;
	}

	return dp[N][0];
}