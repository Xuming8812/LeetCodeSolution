#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.
*/

int climbStairs(int n) {

	vector<int> results{ 1,2 };

	for (size_t i{ 2 }; i < n; i++)
	{
		results.push_back(results[i - 1] + results[i - 2]);
	}

	return results[n - 1];

}
