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
There is a list of sorted integers from 1 to n. Starting from left to right, 
remove the first number and every other number afterward until you reach the end of the list.

Repeat the previous step again, but this time from right to left, remove the right most number 
and every other number from the remaining numbers.

We keep repeating the steps again, alternating left to right and right to left, until a single number remains.

Find the last number that remains starting with a list of length n.
*/

int lastRemaining(int n) {
	return leftRight(n);

}

int leftRight(int n) {
	if (n <= 2) return n;
	return 2 * rightLeft(n / 2);
}

int rightLeft(int n) {
	if (n <= 2) return 1;
	if (n % 2 == 1) {
		return 2 * leftRight(n / 2);
	}
	else {
		return 2 * leftRight(n / 2) - 1;
	}

}

