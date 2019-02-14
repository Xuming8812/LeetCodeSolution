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
Shuffle a set of numbers without duplicates.
*/

class Solution {
public:
	Solution(vector<int> nums) {
		old = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return old;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> temp = old;

		for (int i = 0; i < temp.size(); i++) {
			swap(temp[i], temp[rand() % temp.size()]);
		}

		return temp;
	}

	vector<int> old;

};