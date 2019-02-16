#include <vector>
#include <map>
#include <string>
#include <queue>
#include <sstream>
#include <stack>
#include <set>
#include <bitset>

using namespace std;

/*
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). 
Given some queries, return the answers. If the answer does not exist, return -1.0.
*/

vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
	vector<double> answers; //our finalized quotients

	map<string, vector<pair<string, double>>> dict; //the graph

	for (int i = 0; i < equations.size(); i++) //create the graph
	{
		dict[equations[i].first].push_back(pair<string, double>(equations[i].second, values[i]));
		dict[equations[i].second].push_back(pair<string, double>(equations[i].first, 1 / values[i]));
	}

	for (int j = 0; j < queries.size(); j++)
	{
		string n = queries[j].first; //numerator 
		string d = queries[j].second; //denominator 
		//if we don't know the value of one of the variables, we can't find the quotient
		if (dict.find(n) == dict.end() || dict.find(d) == dict.end()) {
			answers.push_back(-1);
		}
		else if (n == d) {
			answers.push_back(1);
		}
		else {
			//use BFS to traverse from numerator to denominator
			map<string, bool> visited;
			double ans = 1;
			queue<pair<string, double>> q; //will keep track of nodes and their relative quotients
			q.push(pair<string, double>(n, ans));
			visited[n] = true;
			while (!q.empty())
			{
				pair<string, double> front = q.front();
				for (int c = 0; c < dict[front.first].size(); c++)
				{
					double quotient = front.second;
					pair<string, double> v = dict[front.first][c];
					if (!visited[v.first])
					{
						visited[v.first] = true;
						quotient *= v.second;
						q.push(pair<string, double>(v.first, quotient));
						if (v.first == d) //once we reach the denominator, stop traversing and save the quotient 
						{
							answers.push_back(quotient);
							break;
						}
					}
				}
				q.pop();
			}
			if (!visited[d])
			{
				answers.push_back(-1);
			}
		}
	}
	return answers;

}
