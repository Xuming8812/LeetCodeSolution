#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
In a deck of cards, each card has an integer written on it.

Return true if and only if you can choose X >= 2 such that it is possible to split the entire deck into 1 or more groups of cards, where:

Each group has exactly X cards.
All the cards in each group have the same integer.
*/

int greatCommonDivisor(int a, int b)
{
	int h = max(a, b);
	int l = min(a, b);

	if (l == 0) return h;

	int m = h % l;

	while (m) {
		h = l;
		l = m;
		m = h % l;
	}

	return l;
}

//use a map to count each number and then find the gcd of those numbers
bool hasGroupsSizeX(vector<int>& deck)
{
	if (deck.size() < 2)
	{
		return false;
	}

	map<int, int>store;

	for (auto item : deck)
	{
		store[item]++;
	}

	int result{ 0 };

	for (auto item : store)
	{
		result = greatCommonDivisor(result, item.second);
	}

	
	return result>1;
}

