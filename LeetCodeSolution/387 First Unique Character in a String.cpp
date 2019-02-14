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
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1
*/

int firstUniqChar(string s) {
	int list[256] = { 0 };
	for (auto i : s)
		list[i] ++;
	for (int i = 0; i < s.length(); i++)
		if (list[s[i]] == 1) return i;
	return -1;

}