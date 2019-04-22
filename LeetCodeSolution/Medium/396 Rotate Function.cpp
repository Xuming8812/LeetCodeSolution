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

int maxRotateFunction(vector<int>& A) {
	if (A.empty()) return 0;

	long sum{ 0 }, F{ 0 };

	for (int i = 0; i < A.size(); i++) {
		sum += A[i];
		F += i * A[i];
	}

	long result = F;

	for (int i = A.size() - 1; i >= 0; i--) {
		F = F + sum - A.size()*A[i];

		result = max(result, F);
	}

	return result;
}