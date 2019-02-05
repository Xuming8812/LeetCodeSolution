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
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. 
So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
*/

class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		if (maxHeap.empty() || num <= maxHeap.top()) {
			maxHeap.push(num);
		}
		else {
			minHeap.push(num);
		}

		if (maxHeap.size() > minHeap.size() + 1) {
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		}
		else if (minHeap.size() > maxHeap.size()) {
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
	}

	double findMedian() {
		return minHeap.size() == maxHeap.size() ? (minHeap.top() + maxHeap.top()) / 2.0 : maxHeap.top();
	}

private:
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
};