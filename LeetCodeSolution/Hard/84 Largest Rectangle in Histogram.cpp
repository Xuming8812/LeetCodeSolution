#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
*/

int largestRectangleArea(vector<int>& heights) {

	stack<int> indexes; //µ¥µ÷Õ»

	int maxArea = 0;

	heights.push_back(0);

	indexes.push(0);

	for (int i = 1; i < heights.size(); i++) {
		while (!indexes.empty() && heights[i] < heights[indexes.top()]) {
			int h = heights[indexes.top()];
			indexes.pop();
			int prev = indexes.empty() ? -1 : indexes.top();
			maxArea = max(maxArea, (i - prev - 1) * h);
		}
		indexes.push(i);
	}
	return maxArea;
}