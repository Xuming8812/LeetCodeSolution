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
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
*/

bool containsDuplicate(vector<int>& nums) {
	set<int> store;
	for (auto item : nums)
	{
		store.insert(item);
	}

	return nums.size() != store.size();
}