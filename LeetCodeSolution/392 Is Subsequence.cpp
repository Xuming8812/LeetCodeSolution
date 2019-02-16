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
Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. 
t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting 
some (can be none) of the characters without disturbing the relative positions of the remaining characters. 
(ie, "ace" is a subsequence of "abcde" while "aec" is not).
*/

bool isSubsequence(string s, string t) {
	int indexS{ 0 }, indexT{ 0 };

	while (indexS < s.size() && indexT < t.size()) {
		if (s[indexS] == t[indexT]) {
			indexS++;
			indexT++;
			continue;
		}

		indexT++;
	}

	return indexS == s.size();
}