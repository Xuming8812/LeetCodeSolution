#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
*/

string convertToTitle(int n) {
	string result;

	while (n) {
		result = string(1, 'A' + (n - 1) % 26) + result;
		n = (n - 1) / 26;
	}

	return result;
}