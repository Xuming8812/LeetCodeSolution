#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;


/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

int romanToInt(string s) {

	map<char, int> value{ {'0',0}, {'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000} };

	int ans = 0;

	for (int i = 0; i < s.length(); i++) {
		if (i < s.length() && value[s[i]] >= value[s[i + 1]]) {
			ans += value[s[i]];
		}
		else {
			ans -= value[s[i]];
		}
	}

	return ans;
}