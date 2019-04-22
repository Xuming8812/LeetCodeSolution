#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period . refers to the current directory. 
Furthermore, a double period .. moves the directory up a level. For more information, see: Absolute path vs relative path in Linux/Unix

Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. 
The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.
*/

string simplifyPath(string path) {
	vector<string> paths;

	int index{ 0 };
	while (index < path.size()) {
		//skip /
		if (path[index] == '/') {
			index++;
			continue;
		}
		else {
			string current;
			while (index < path.size() && path[index] != '/') {
				current += string(1, path[index]);
				index++;
			}

			if (current == ".") {
				continue;
			}
			else if (current == "..") {
				if (!paths.empty()) { paths.pop_back(); }
			}
			else {
				paths.push_back(current);
			}
		}
	}

	string result{};

	if (paths.empty()) {
		return "/";
	}

	for (auto item : paths) {
		result = result + "/" + item;
	}

	return result;
}