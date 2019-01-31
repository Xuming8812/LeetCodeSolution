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
Implement a trie with insert, search, and startsWith methods.
*/

class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode* p = root;

		for (auto c : word) {
			if (p->children[c - 'a'] == nullptr) {
				p->children[c - 'a'] = new TrieNode();
			}

			p = p->children[c - 'a'];
		}

		p->isWord = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode* p = searchHelper(word);

		return p != nullptr && p->isWord;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TrieNode* p = searchHelper(prefix);
		return p != nullptr;
	}



	struct TrieNode {
		TrieNode() :isWord(false), children(26, nullptr) {}

		~TrieNode() {
			for (auto item : children) {
				if (item != nullptr) {
					delete item;
				}
			}
		}

		bool isWord;
		vector<TrieNode*> children;
	};

	TrieNode* searchHelper(string word) {
		TrieNode* p = root;

		for (auto c : word) {
			if (p->children[c - 'a'] == nullptr) {
				return nullptr;
			}

			p = p->children[c - 'a'];
		}

		return p;
	}

	TrieNode* root;
};