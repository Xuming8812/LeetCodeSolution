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
One way to serialize a binary tree is to use pre-order traversal. 
When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.
*/

bool isValidSerialization(string preorder) {
	if (preorder.empty()) return false;
	//a comma indicates a node
	preorder += ',';

	int sz = preorder.size(), idx = 0;

	int capacity = 1;
	//loop all char
	for (idx = 0; idx < sz; idx++) {
		//jump over a node first;
		if (preorder[idx] != ',') continue;

		//after a node
		capacity--;
		if (capacity < 0) return false;
		if (preorder[idx - 1] != '#') capacity += 2;
	}
	return capacity == 0;
}

/*
//split
vector<string> split(string preorder) {
	vector<string> result;

	stringstream ss;
	ss << preorder;

	string temp;

	while (getline(ss, temp, ',')) {
		result.push_back(temp);
	}

	return result;
}
//use a stack to store nodes
bool isValidSerialization(string preorder) {
	vector<string> strings = split(preorder);
	stack<string> store;

	for (auto item : strings) {
		if (item == "#") {
			while (!store.empty() && store.top() == "#") {
				store.pop();
				if (store.empty() || store.top() == "#") {
					return false;

				}
				store.pop();
			}
		}

		store.push(item);
	}

	return store.size() == 1 && store.top() == "#";

}

*/