#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
*/

string result;

void getPermutationHelper(int n, int & k, string chosen, vector<bool>& used) {

	if (chosen.size() == n) {

		k--;

		if (k == 0)
		{
			result = chosen;
		}

		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (!used[i] && k > 0) {
				chosen = chosen + to_string(i + 1);
				used[i] = true;

				getPermutationHelper(n, k, chosen, used);

				used[i] = false;
				chosen = chosen.substr(0, chosen.size() - 1);
			}
		}
	}
}

string getPermutation(int n, int k) {
	vector<bool> used(n, false);

	getPermutationHelper(n, k, "", used);

	return result;
}