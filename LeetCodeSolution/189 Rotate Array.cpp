#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given an array, rotate the array to the right by k steps, where k is non-negative.
*/

void rotate(int nums[], int n, int k)
{
	if ((n == 0) || (k <= 0))
	{
		return;
	}

	// Make a copy of nums
	vector<int> numsCopy(n);
	for (int i = 0; i < n; i++)
	{
		numsCopy[i] = nums[i];
	}

	// Rotate the elements.
	for (int i = 0; i < n; i++)
	{
		nums[(i + k) % n] = numsCopy[i];
	}
}