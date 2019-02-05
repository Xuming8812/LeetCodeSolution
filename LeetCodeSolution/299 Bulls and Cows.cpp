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
You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. 
Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both 
digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). 
Your friend will use successive guesses and hints to eventually derive the secret number.

Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows.

Please note that both secret number and friend's guess may contain duplicate digits.
*/

string getHint(string secret, string guess) {
	map<char, int> record;

	int countBull{ 0 };
	int countCow{ 0 };

	for (int i = 0; i < secret.size(); i++) {
		record[secret[i]]++;
	}

	for (int i = 0; i < secret.size(); i++) {
		if (guess[i] == secret[i]) {
			countBull++;
			record[guess[i]]--;
		}
	}

	for (int i = 0; i < secret.size(); i++) {
		if (guess[i] != secret[i]) {
			if (record.find(guess[i]) != record.end() && record[guess[i]] > 0) {
				countCow++;
				record[guess[i]]--;
			}
		}
	}

	return to_string(countBull) + "A" + to_string(countCow) + "B";
}