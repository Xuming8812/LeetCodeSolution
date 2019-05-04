#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/


//brutal force
int strStr(string haystack, string needle) {
	//corner case
	if (needle.empty()) {
		return 0;
	}

	if (haystack.size() < needle.size()) {
		return -1;
	}
	//loop all possible positions in haystack
	for (int i = 0; i < haystack.size() - needle.size() + 1; i++) {

		if (haystack[i] == needle[0]) {
			bool isFound{ true };
			//check for all chars in needle
			for (int j = 0; j < needle.size(); j++){
				if (needle[j] != haystack[i + j]){
					isFound = false;
					break;
				}
			}

			if (isFound){
				return i;
			}
		}
	}

	return -1;
}