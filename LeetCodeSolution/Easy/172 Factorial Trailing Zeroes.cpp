#include<map>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
/*
Given an integer n, return the number of trailing zeroes in n!.
*/

//the main goal is to count how many 10 and 5 smaller than n
int trailingZeroes(int n) {
	if (n < 5)
	{
		return 0;
	}

	
	return n / 5 + trailingZeroes(n / 5);
}