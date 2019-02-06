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
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.
*/
string removeDuplicateLetters(string s) {
	//to store the number of each char
	vector<int> dict(256, 0);
	//to store whether a char is used in the final result string
	vector<bool> visited(256, false);
	//count the number of each char
	for (auto ch : s)  dict[ch]++;

	//the result string
	string result = "0";
	/** the key idea is to keep a monotically increasing sequence **/
	for (auto c : s) {
		dict[c]--;
		/** to filter the previously visited elements **/
		if (visited[c])  continue;
		//if the current char is smaller than the back() of the result
		while (c < result.back() && dict[result.back()]) {
			//reset the visited vector
			visited[result.back()] = false;

			result.pop_back();
		}
		//save the current char
		result += c;
		//set the visited vector
		visited[c] = true;
	}
	return result.substr(1);
}