#include <vector>
#include <map>
#include <string>
#include <queue>
#include <sstream>
#include <stack>
#include <set>
#include <bitset>

using namespace std;

/*
Given an array of integers A and let n to be its length.

Assume Bk to be an array obtained by rotating the array A k positions clock-wise,
we define a "rotation function" F on A as follow:

F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].

Calculate the maximum value of F(0), F(1), ..., F(n-1).
*/


	int minReplacement = INT_MAX;

	int integerReplacement(int n) {

		helper(n, 0);
		return minReplacement;
	}

	void helper(long n, int times) {

		if (n == 1) {
			minReplacement = min(minReplacement, times);
			return;
		}
		if (n % 2 == 0) {
			helper(n / 2, times + 1);
		}
		else {
			helper(n + 1, times + 1);
			helper(n - 1, times + 1);
		}
	}
