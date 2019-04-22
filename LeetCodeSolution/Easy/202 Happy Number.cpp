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
A happy number is a number defined by the following process: Starting with any positive integer, 
replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), 
or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
*/

bool isHappy(int n) {
	set<int> store;

	while (store.count(n) == 0) {
		store.insert(n);

		int result{ 0 };

		while (n) {
			result = result + (n % 10)*(n % 10);
			n = n / 10;
		}

		n = result;
	}

	return store.find(1) != store.end();
}