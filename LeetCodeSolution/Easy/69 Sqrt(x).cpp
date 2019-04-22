#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
*/

int mySqrt(int x) {

	if (x == 1) {
		return 1;
	}
	long start{ 1 }, end{ x };

	while (start < end) {
		long mid = start + (end - start) / 2;

		if (mid*mid == x) {
			return mid;
		}

		if (mid*mid > x) {
			end = mid;
		}
		else {
			start = mid + 1;
		}
	}

	return start - 1;
}