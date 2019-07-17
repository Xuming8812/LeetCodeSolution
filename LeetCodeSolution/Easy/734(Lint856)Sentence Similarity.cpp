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
Given two sentences words1, words2 (each represented as an array of strings), 
and a list of similar word pairs pairs, determine if two sentences are similar.

For example, words1 = great acting skills and words2 = fine drama talent are similar, 
if the similar word pairs are pairs = [["great", "fine"], ["acting","drama"], ["skills","talent"]].

Note that the similarity relation is not transitive. For example, if "great" and "fine" are similar, 
and "fine" and "good" are similar, "great" and "good" are not necessarily similar.

However, similarity is symmetric. For example, "great" and "fine" being similar is the same as "fine" and "great" being similar.

Also, a word is always similar with itself. For example, the sentences words1 = ["great"], 
words2 = ["great"], pairs = [] are similar, even though there are no specified similar word pairs.

Finally, sentences can only be similar if they have the same number of words. 
So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].
*/    

/**
 * @param words1: a list of string
 * @param words2: a list of string
 * @param pairs: a list of string pairs
 * @return: return a boolean, denote whether two sentences are similar or not
 */
bool isSentenceSimilarity(vector<string> &words1, vector<string> &words2, vector<vector<string>> &pairs) {
    // write your code here
    //corner case
    if(words2.size()!=words1.size()){
        return false;
    }
    //the hashmap to store all similar words of a given word
    map<string,set<string>> dict;
    
    //fill the dict of similar words
    for(auto item : pairs){
        dict[item[0]].insert(item[1]);
        dict[item[1]].insert(item[0]);
    }
    //loop all words in the two vectors
    for(int i = 0;i<words1.size();i++){
        //if the two words are same, continue
        if(words1[i]==words2[i]){
            continue;
        }
        //see if these two words are similar
        if(dict[words1[i]].count(words2[i])==0){
            return false;
        }
    }
    
    return true;

}