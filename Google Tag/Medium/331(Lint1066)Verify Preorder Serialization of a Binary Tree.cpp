#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<bitset>

using namespace std;

/*
One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. 
If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. 
Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".
*/



/**
 * @param preorder: a string
 * @return: return a bool
 */
bool isValidSerialization(string& preorder) {
    //split the string by ','
    vector<string> strings = split(preorder);
    //use a stack to store nodes
    stack<string> store;
    //loop each node
    for (auto item : strings) {
        //basic idea is to push in a null node, and wait for the second null node, then pop out the first null node and the root node
        if (item == "#") {
            while (!store.empty() && store.top() == "#") {
                store.pop();
                //invalid condition
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
//helper function to split the given string by ','
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

//another approach
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