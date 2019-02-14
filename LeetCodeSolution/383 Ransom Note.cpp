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
Given an arbitrary ransom note string and another string containing letters from all the magazines, 
write a function that will return true if the ransom note can be constructed from the magazines ; 
otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.
*/

bool canConstruct(string ransomNote, string magazine) {
	map<char, int> dict;

	for (auto c : magazine) {
		dict[c]++;
	}

	for (auto c : ransomNote) {
		if (dict.find(c) == dict.end()) {
			return false;
		}

		if (dict[c] < 1) {
			return false;
		}

		dict[c]--;
	}

	return true;
}