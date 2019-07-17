#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<set>

using namespace std;

/*
Two strings are given and you have to modify 1st string such that all the common 
characters of the 2nd strings have to be removed and the uncommon characters of 
the 2nd string have to be concatenated with uncommon characters of the 1st string.
*/

/**
 * @param s1: the 1st string
 * @param s2: the 2nd string
 * @return: uncommon characters of given strings
 */
string concatenetedString(string &s1, string &s2) {
	// write your code here
	set<char> dict1;
	set<char> dict2;

	//save all chars in set dict1
	for (auto c : s1) {
		dict1.insert(c);
	}
	//save all chars in set dict2
	for (auto c : s2) {
		dict2.insert(c);
	}

	//declare result
	string result;
	//check whether the current char in s1 exsits in dict2
	for (auto item : s1) {
		if (dict2.find(item) == dict2.end()) {
			result = result + string(1, item);
		}
	}
	//check whether the current char in s2 exsits in dict1
	for (auto item : s2) {
		if (dict1.find(item) == dict1.end()) {
			result = result + string(1, item);
		}
	}

	return result;
}