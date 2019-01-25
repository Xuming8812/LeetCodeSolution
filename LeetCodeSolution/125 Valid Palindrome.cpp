#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.
*/

bool isAlphaNum(char input) {
	if ((input >= '0'&&input <= '9') || (input >= 'a'&&input <= 'z')) {
		return true;
	}

	return false;
}

bool isPalindrome(string s) {
	if (s.empty()) return true;

	//s= tolower(s);

	transform(s.begin(), s.end(), s.begin(), ::tolower);

	int left{ 0 }, right = s.size() - 1;

	while (left < right) {
		if (!isAlphaNum(s[left])) {
			left++;
			continue;
		}
		if (!isAlphaNum(s[right])) {
			right--;
			continue;
		}

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