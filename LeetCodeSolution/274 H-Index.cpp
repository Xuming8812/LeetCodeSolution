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
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, 
and the other N − h papers have no more than h citations each."
*/

int hIndex(vector<int>& citations) {
	int n = citations.size();

	int num[n + 1];

	memset(num, 0, sizeof(num));

	for (int i = 0; i < citations.size(); i++) {
		if (citations[i] >= n) {
			num[n] ++;
		}
		else {
			num[citations[i]] ++;
		}
	}


	int sum = 0;

	for (int i = n; i >= 0; i--) {
		sum += num[i];
		if (sum >= i)
			return i;
	}
	return 0;
}