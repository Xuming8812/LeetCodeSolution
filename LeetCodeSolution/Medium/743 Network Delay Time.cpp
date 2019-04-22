#include<map>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

/*
There are N network nodes, labelled 1 to N

Given times, a list of travel times as directed edges times[i] = (u, v, w),
where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.
*/

//use dijkstra method to find shortest path from k to each node else
int networkDelayTime(vector<vector<int>>& times, int N, int K) {
	//a vector storing each node`s distance to node K
	vector<int> distance(N + 1, INT_MAX);

	queue<int> q;
	q.push(K);
	distance[K] = 0;

	while (!q.empty())
	{
		int current = q.front(); q.pop();
		//use a vector to save the neighboring path and its weight
		vector<pair<int, int>> neighbors;

		//loop all paths to find the neighboring node for the current node
		for (int i = 0; i < times.size(); i++) {
			if (times[i][0] == current)
			{
				neighbors.push_back(make_pair(times[i][1], times[i][2]));
			}				
		}

		for (auto neighbor : neighbors) {
			//if a path through current node is near than origin distance K
			if (distance[current] + neighbor.second < distance[neighbor.first]) 
			{
				//update the distance
				distance[neighbor.first] = distance[current] + neighbor.second;
				//push this neighboring node into queue
				q.push(neighbor.first);
			}
		}
	}

	int result{ -1 };
	//loop all nodes to see whether it connects with node K
	for (int i = 1; i < distance.size(); i++)
	{
		result = max(result, distance[i]);
	}

	if (result == INT_MAX)
	{
		return -1;
	}
	else
	{
		return result;
	}
}