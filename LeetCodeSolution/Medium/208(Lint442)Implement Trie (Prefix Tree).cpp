#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

/*
Implement a Trie with insert, search, and startsWith methods.
*/

class Trie {
public:
    Trie() {
        // do intialization if necessary
        //initialize the root node
        root = new TrieNode();
    }

    /*
     * @param word: a word
     * @return: nothing
     */
    void insert(string &word) {
        // write your code here
        //get the root node
    	TrieNode* p = root;
        //loop each letter in the word
		for (auto c : word) {
		    //if the node of this letter doesn't exist, create it
			if (p->children[c - 'a'] == nullptr) {
				p->children[c - 'a'] = new TrieNode();
			}
            //update the pointer
			p = p->children[c - 'a'];
		}
        //set the last node of the letter to be the end of the word
		p->isWord = true;
    }

    /*
     * @param word: A string
     * @return: if the word is in the trie.
     */
    bool search(string &word) {
        // write your code here
        //get the last node in this word
    	TrieNode* p = searchHelper(word);
        //see if it's valid and is the end of the word
		return p != nullptr && p->isWord;
    }

    /*
     * @param prefix: A string
     * @return: if there is any word in the trie that starts with the given prefix.
     */
    bool startsWith(string &prefix) {
        // write your code here
        //get the last node in this word
    	TrieNode* p = searchHelper(prefix);
    	//see if it's valid
		return p != nullptr;
    }
    
private:
    struct TrieNode {
    	TrieNode() :isWord(false), children(26, nullptr) {}
        //the destructor of a TrieNode
    	~TrieNode() {
    	    //delete each children`s node
    		for (auto item : children) {
    			if (item != nullptr) {
    				delete item;
    			}
    		}
    	}
        //if the current node is an end of word
    	bool isWord;
    	//the vector to save the children, has the length of 26
    	vector<TrieNode*> children;
    };
    //the helper function to search the trie
	TrieNode* searchHelper(string word) {
		//get the root of the trie
		TrieNode* p = root;
        //loop each letter of the word
		for (auto c : word) {
		    //if the letter doesn`t store in the trie, return
			if (p->children[c - 'a'] == nullptr) {
				return nullptr;
			}
            //set the pointer to the children node
			p = p->children[c - 'a'];
		}
        //the node point to the last letter of the word
		return p;
	}

		TrieNode* root;
};