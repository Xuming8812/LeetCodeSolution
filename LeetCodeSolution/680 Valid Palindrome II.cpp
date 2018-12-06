#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a non - empty string s, you may delete at most one character.Judge whether you can make it a palindrome.
*/

bool validPalindrome(string s) {
	if (s.empty()) return false;
	if (s.size() == 1) return true;

	int i = 0;
	int j = s.size() - 1;

	while (i < j) {
		if (s[i] != s[j]) {
			return isPalindrome(s, i, j - 1) || isPalindrome(s, i + 1, j);
		}
		else {
			i++;
			j--;
		}
	}

	return true;
}

bool isPalindrome(string s, int i, int j) {
	while (i < j) {
		if (s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}
