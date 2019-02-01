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
Given an integer, write a function to determine if it is a power of two.
*/

bool isPowerOfTwo(int n) {

	if (n <= 0) {
		return false;
	}

	bitset<32> store(n);

	if (store.count() == 1) {
		return true;
	}
	else {
		return false;
	}
}