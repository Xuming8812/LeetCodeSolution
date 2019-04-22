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
Write a function that reverses a string. The input string is given as an array of characters char[].
*/

void reverseString(vector<char>& s) {
	int start = 0, end = s.size() - 1;

	while (start < end) {
		swap(s[start++], s[end--]);
	}


}