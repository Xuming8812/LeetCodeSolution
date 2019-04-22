#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<bitset>
using namespace std;

/*
Given an integer, write a function to determine if it is a power of three.
*/

bool isPowerOfThree(int n) {
	if (n < 1) return false;

	while (n % 3 == 0) {
		n = n / 3;
	}

	return n == 1;
}