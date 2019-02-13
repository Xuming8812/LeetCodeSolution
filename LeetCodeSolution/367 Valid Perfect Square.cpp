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
Given a positive integer num, write a function which returns True if num is a perfect square else False.
*/

bool isPerfectSquare(int num) {
	if (num < 0) return false;

	long start = 0, end = num;

	while (start < end) {

		long mid = start + (end - start) / 2;

		if (mid*mid >= num) {
			end = mid;
		}
		else {
			start = mid + 1;
		}
	}

	return start * start == num;

}