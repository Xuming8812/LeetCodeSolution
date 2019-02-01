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
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
*/
int findKthLargest(vector<int>& nums, int k) {
	map<int, int> dict;

	for (auto item : nums) {
		dict[item]++;
	}

	int result{ 0 };
	int count{ 0 };

	for (auto item : dict) {
		if (count < nums.size() - k + 1 && count + item.second >= nums.size() - k + 1) {
			result = item.first;
			break;
		}
		else {
			count += item.second;
		}
	}

	return result;
}