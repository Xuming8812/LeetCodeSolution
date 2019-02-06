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
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.
*/

int nthSuperUglyNumber(int n, vector<int>& primes) {

	vector<int> ugly(n, INT_MAX);
	vector<int> times(primes.size());

	ugly[0] = 1;

	for (int i = 1; i < n; i++) {

		for (int j = 0; j < primes.size(); j++) {
			ugly[i] = min(ugly[i], primes[j] * ugly[times[j]]);
		}

		for (int j = 0; j < primes.size(); j++) {
			if (ugly[i] == ugly[times[j]] * primes[j]) {
				times[j]++;
			}
		}
	}

	return ugly[n - 1];
}