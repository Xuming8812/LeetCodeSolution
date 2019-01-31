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
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
*/

class WordDictionary {
public:
	/** Initialize your data structure here. */
	WordDictionary() {
		root = new TrieNode();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		TrieNode* p = root;

		for (auto c : word) {
			if (p->children[c - 'a'] == nullptr) {
				p->children[c - 'a'] = new TrieNode();
			}

			p = p->children[c - 'a'];
		}
		p->isWord = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return searchHelper(word, root);
	}

private:

	struct TrieNode {
		TrieNode() :isWord(false), children(26, nullptr) {};

		~TrieNode() {
			for (auto item : children) {
				if (item != nullptr) {
					delete item;
				}
			}
		}

		vector<TrieNode*> children;
		bool isWord;
	};

	TrieNode* root;

	bool searchHelper(string word, TrieNode* root) {
		TrieNode* p = root;

		for (int i = 0; i < word.size() && p; i++) {
			if (word[i] != '.') {
				p = p->children[word[i] - 'a'];
				if (p == nullptr) {
					return false;
				}
			}
			else {
				TrieNode* temp = p;

				for (int j = 0; j < 26; j++) {
					p = temp->children[j];
					if (searchHelper(word.substr(i + 1), p)) {
						return true;
					}
				}
			}
		}

		return p && p->isWord;
	}
};