#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.
*/

vector<vector<string>> result;

bool isPalindrome(string s, int start, int end) {
	int left = start, right = end;

	while (left < right) {
		if (s[left] == s[right]) {
			left++;
			right--;
		}
		else {
			return false;
		}
	}

	return true;
}

void partitionHelper(string s, int start, vector<string> chosen) {
	if (start == s.size()) { result.push_back(chosen); }

	for (int i = start; i < s.size(); i++) {
		if (isPalindrome(s, start, i)) {
			chosen.push_back(s.substr(start, i - start + 1));

			partitionHelper(s, i + 1, chosen);

			chosen.pop_back();
		}
	}
}

vector<vector<string>> partition(string s) {
	if (s.empty()) return result;

	partitionHelper(s, 0, {});

	return result;
}