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
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
*/

int nthUglyNumber(int n) {
	vector<int> result{ 1 };

	int index2{ 0 }, index3{ 0 }, index5{ 0 };

	while (result.size() < n) {
		int next = min(result[index5] * 5, min(result[index2] * 2, result[index3] * 3));

		if (next == result[index2] * 2) index2++;
		if (next == result[index3] * 3) index3++;
		if (next == result[index5] * 5) index5++;

		result.push_back(next);
	}

	return result[n - 1];
}