#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given an array A of integers, return true if and only if it is a valid mountain array.

Recall that A is a mountain array if and only if:

A.length >= 3
There exists some i with 0 < i < A.length - 1 such that:
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[B.length - 1]
*/

bool validMountainArray(vector<int>& A) {
	if (A.empty())
	{
		return false;
	}
	

	int left = 0, right = A.size() - 1;
	//climb from left
	while (left + 1 < A.size() && A[left + 1] > A[left])
	{
		left++;
	}

	//climb from right
	while (right - 1 >= 0 && A[right - 1] > A[right])
	{
		right--;
	}
	//make sure both side moves and meet at the summit
	return left > 0 && left == right && right < A.size() - 1;;


}