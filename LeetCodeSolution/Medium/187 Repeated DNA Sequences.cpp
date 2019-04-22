#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". 
When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
*/

vector<string> findRepeatedDnaSequences(string s) {
	vector<string> result;

	if (s.size() < 10) return result;

	map<string, int> dict;

	for (int i = 0; i <= s.size() - 10; i++) {
		dict[s.substr(i, 10)]++;
	}


	for (auto item : dict) {
		if (item.second > 1) {
			result.push_back(item.first);
		}
	}

	return result;
}

