#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.
*/

bool isTravel(vector<int> left, int start) {
	int current{ start + 1 };
	int gas{ left[start] };
	while (gas >= 0 && start != current) {
		gas += left[current];

		if (current + 1 < left.size()) {
			current = current + 1;
		}
		else
		{
			current = 0;
		}
	}

	return current == start;
}

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	if (gas.empty() || cost.empty() || gas.size() != cost.size()) { return -1; }

	int length = gas.size();

	vector<int> left(length, 0);

	for (int i = 0; i < length; i++) {
		left[i] = gas[i] - cost[i];
	}

	vector<int> prefix(length, 0);

	prefix[0] = left[0];

	for (int i = 1; i < length; i++) {
		prefix[i] = left[i] + prefix[i - 1];
	}

	if (prefix[length - 1] < 0) return -1;

	for (int i = 0; i < length; i++) {
		if (left[i] >= 0) {
			if (isTravel(left, i)) {
				return i;
			}
		}
	}

	return -1;
}