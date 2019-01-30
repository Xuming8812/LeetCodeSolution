#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.

The . character does not represent a decimal point and is used to separate number sequences.

For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

You may assume the default revision number for each level of a version number to be 0. For example,
version number 3.4 has a revision number of 3 and 4 for its first and second level revision number. Its third and fourth level revision number are both 0.
*/

void getVersion(string version1, vector<int>&versions) {
	string temp;

	int index{ 0 };

	while (index < version1.size()) {
		if (version1[index] == '.') {
			versions.push_back(stoi(temp));
			temp = "";
			index++;
		}

		temp += version1[index++];
	}

	if (!temp.empty()) {
		versions.push_back(stoi(temp));
	}
}

int compareVersion(string version1, string version2) {
	vector<int> v1, v2;

	getVersion(version1, v1);
	getVersion(version2, v2);

	if (v1.size() < v2.size()) {
		while (v1.size() != v2.size()) {
			v1.push_back(0);
		}
	}
	else {
		while (v1.size() != v2.size()) {
			v2.push_back(0);
		}
	}

	int index{ 0 };

	while (index < v1.size()) {
		if (v1[index] < v2[index]) {
			return -1;
		}
		else if (v1[index] > v2[index]) {
			return 1;
		}
		else {
			index++;
		}
	}

	return 0;
}