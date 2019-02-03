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
Write a program to check whether a given number is an ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5
*/

bool isUglyHelper(int num) {
	if (num % 2 == 0) {
		return isUglyHelper(num / 2);
	}
	else if (num % 3 == 0) {
		return isUglyHelper(num / 3);
	}
	else if (num % 5 == 0) {
		return isUglyHelper(num / 5);
	}
	else if (num == 1) {
		return true;
	}
	else {
		return false;
	}
}

bool isUgly(int num) {
	vector<int> store{ 2,3,5 };

	if (num <= 0) {
		return false;
	}
	if (num == 1) {
		return true;
	}

	return isUglyHelper(num);
}