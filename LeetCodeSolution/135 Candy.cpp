#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/

int candy(vector<int>& ratings) {
	vector<int> candies(ratings.size());

	candies[0] = 1;

	//from left to right
	for (int i = 1; i < ratings.size(); i++) {
		if (ratings[i] > ratings[i - 1]) {
			candies[i] = candies[i - 1] + 1;
		}
		else {
			candies[i] = 1;
		}
	}

	//from right to left
	for (int i = ratings.size() - 2; i >= 0; i--) {
		if (ratings[i] > ratings[i + 1]) {
			candies[i] = max(candies[i], candies[i + 1] + 1);
		}
	}

	int sum = 0;
	for (int i = 0; i < candies.size(); i++) {
		sum += candies[i];
	}

	return sum;
}