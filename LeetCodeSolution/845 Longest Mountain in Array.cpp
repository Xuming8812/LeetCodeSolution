#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:

B.length >= 3
There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
(Note that B could be any subarray of A, including the entire array A.)

Given an array A of integers, return the length of the longest mountain.

Return 0 if there is no mountain.
*/

int longestMountain(vector<int>& A) {

	int len = A.size();

	if (len == 0) {
		return 0;
	}

	//use two dp arrays to store leftward and rightward increasing results;
	vector<int> left(len, 0);
	vector<int> right(len, 0);

	for (int i = 1; i < len; i++)
	{
		if (A[i] > A[i - 1])
		{
			left[i] = left[i - 1] + 1;
		}
		else
		{
			left[i] = 0;
		}
	}

	for (int i = len - 2; i >= 0; i--)
	{
		if (A[i] > A[i + 1])
		{
			right[i] = right[i + 1] + 1;
		}
		else
		{
			right[i] = 0;
		}
	}

	int result{ 0 };

	for (int i = 0; i < len; i++)
	{
		//if the mountain exists, update the answer
		if (left[i] != 0 && right[i] != 0)
		{
			result = max(result, left[i] + right[i] + 1);
		}

	}

	if (result < 3)
	{
		return 0;
	}
	else
	{
		return result;
	}
}