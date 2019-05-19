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
Design a data structure that supports the following two operations: addWord(word) and search(word)

search(word) can search a literal word or a regular expression string containing only letters a-z or ..

A . means it can represent any one letter.
*/

class WordDictionary {
public:
    /*
     * @param word: Adds a word into the data structure.
     * @return: nothing
     */
    void addWord(string &word) {
        // write your code here
        TrieNode* p = root;
        
        for(auto c : word){
            if(p->children[c-'a']==nullptr){
                p->children[c-'a'] = new TrieNode();
            }
            
            p = p->children[c-'a'];
        }
        p->isWord = true;
    }

    /*
     * @param word: A word could contain the dot character '.' to represent any one letter.
     * @return: if the word is in the data structure.
     */
    bool search(string &word) {
        // write your code here
        return searchHelper(word,root);
    }
    
    //constructor
    WordDictionary() {
        root = new TrieNode();
    }
    
private:
    //the node of Trie
    struct TrieNode{
        //constructor of trie
        TrieNode():isWord(false),children(26,nullptr){};
        //destructor of trienode
        ~TrieNode(){
            for(auto item : children){
                if(item!=nullptr){
                    delete item;
                }
            }
        }
        //vector to store children node`s address
        vector<TrieNode*> children;
        bool isWord;
    };
    
    TrieNode* root;
    //helper function to search for a word
    bool searchHelper(string word, TrieNode* root){
        //get the root node as current node
        TrieNode* p = root;
        //loop all character in the string               
        for(int i = 0;i<word.size()&&p;i++){
            //if not '.', just look for the current char
            if(word[i] !='.'){
                //get children node
                p = p->children[word[i]-'a'];
                if(p==nullptr){
                    return false;
                }
            }
            else{
                //if the current char is '.'
                TrieNode* temp = p;
                //loop all children nodes for possible result     
                for(int j= 0;j<26;j++){
                    p = temp->children[j];
                    //dfs
                    if(searchHelper(word.substr(i+1),p)){
                        return true;
                    }
                }
            }
        }
        
        return p && p->isWord;
    }
};