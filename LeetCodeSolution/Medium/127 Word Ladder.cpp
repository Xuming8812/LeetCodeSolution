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

void addNeighborWords(string word, set<string>& dict, queue<string>& bfs) {
	dict.erase(word);

	for (int i = 0; i < word.size(); i++) {
		char cur = word[i];

		for (int k = 0; k < 26; k++) {
			char temp = 'a' + k;

			word[i] = temp;

			if (dict.find(word) != dict.end()) {
				bfs.push(word);
				dict.erase(word);
			}
		}

		word[i] = cur;
	}
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	set<string> dict;

	for (auto item : wordList) dict.insert(item);

	if (dict.find(endWord) == dict.end()) return 0;

	queue<string> bfs;

	addNeighborWords(beginWord, dict, bfs);

	int result{ 2 };

	while (!bfs.empty()) {
		int length = bfs.size();

		for (int i = 0; i < length; i++) {
			string temp = bfs.front(); bfs.pop();

			if (temp == endWord) return result;

			addNeighborWords(temp, dict, bfs);

		}

		result++;


	}

	return 0;
}