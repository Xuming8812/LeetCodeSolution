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
Write a function that takes a string as input and reverse only the vowels of a string.
*/

bool isVowels(char c) {
	char temp = tolower(c);

	if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u') {
		return true;
	}

	return false;
}

string reverseVowels(string s) {
	int start = 0, end = s.size() - 1;

	while (start < end) {
		if (isVowels(s[start]) && isVowels(s[end])) {
			swap(s[start++], s[end--]);
			continue;
		}

		while (!isVowels(s[start]) && start < end) { start++; }
		while (!isVowels(s[end]) && start < end) { end--; }
	}

	return s;
}