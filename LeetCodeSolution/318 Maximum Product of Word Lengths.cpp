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
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. 
You may assume that each word will contain only lower case letters. If no such two words exist, return 0.
*/

int maxProduct(vector<string>& words) {
	//use a map to store char and number 
	map<char, int>mp;

	int result{ 0 };

	for (int i = 0; i < words.size(); i++) {//loop over words array
		mp.clear();
		for (int j = 0; j < words[i].size(); j++)//store ith word in map
			mp[words[i][j]]++;

		for (int j = i + 1; j < words.size(); j++) {//loop for remaining i+1 to n words
			bool match = false;
			for (int k = 0; k < words[j].size(); k++) {//loop over jth word
				if (mp.find(words[j][k]) != mp.end()) {//compare with ith word
					match = true;
					break;
				}
			}
			if (!match)
				result = max(result, (int)words[i].size()*(int)words[j].size());
		}
	}
	return result;
}