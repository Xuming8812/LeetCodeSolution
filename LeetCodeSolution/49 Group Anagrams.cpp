#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given an array of strings, group anagrams together.
*/

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	map<string, vector<string>> dict;
	vector<vector<string>> result;


	//group strings with same anagrams together
	for (auto item : strs) {
		string temp{ item };
		sort(temp.begin(), temp.end());
		dict[temp].push_back(item);
	}

	//save them
	for (auto item : dict) {
		result.push_back(item.second);
	}

	return result;
}