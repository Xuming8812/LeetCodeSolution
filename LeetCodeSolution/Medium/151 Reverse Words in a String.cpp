#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord,
such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
*/


void reverseWords(string &s) {
	stringstream ss;

	ss << s;
	string temp;
	string result;
	while (ss >> temp) {
		result = temp + " " + result;
	}

	s = result.substr(0, result.size() - 1);
}