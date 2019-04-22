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
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.
*/

int countNumbersWithUniqueDigits(int n) {
	vector<bool> used(10, false);

	return helper(n, used, 0);

}

int helper(int n, vector<bool>& used, int digits) {
	if (digits == n) {
		return 1;
	}

	int result{ 1 };

	for (int i = (digits == 0) ? 1 : 0; i < 10; i++) {
		if (!used[i]) {
			used[i] = true;

			result += helper(n, used, digits + 1);

			used[i] = false;
		}
	}

	return result;
}