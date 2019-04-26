#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Write a method anagram(s,t) to decide if two strings are anagrams or not.
*/   

/**
 * @param s: The first string
 * @param t: The second string
 * @return: true or false
 */

bool isAnagram(string s, string t)
{
	//check whether these two strings have the same length
	if (s.size() != t.size()){
		return false;
	}
	//use a map to store char and its number
	map<char, int> dict;
	//count chars in string s
	for (auto c : s){
		dict[c]++;
	}
	//count chars in string t
	for (auto c : t){
		dict[c]--;
	}
	//check the fina results
	for (auto item : dict){
		if (item.second != 0){
			return false;
		}
	}

	return true;
}