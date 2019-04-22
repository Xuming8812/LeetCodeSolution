#include<map>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
/*
You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.
*/

// for 1 to kth row, the total number is (1+k)*k/2
int arrangeCoins(int n)
{
	//actually it`s to solve the equation of (1+x)*x/2 = n, then x = [-1+sqrt(1+8n)]/2
	return (int)(sqrt(2)*sqrt(n+0.125)-0.5);
}
