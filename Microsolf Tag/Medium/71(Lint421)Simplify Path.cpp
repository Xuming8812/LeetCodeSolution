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
Given an absolute path for a file (Unix-style), simplify it.
*/

/**
 * @param path: the original path
 * @return: the simplified path
 */
string simplifyPath(string& path) {
    if (path.empty()) return path;
    
    vector<string> vec;
    stringstream ss(path);
    string str;
    while (getline(ss, str, '/')) {
        if (str.empty() || str == ".") {
            continue;
        } else if (str == "..") {
            if (!vec.empty()) vec.pop_back();
        } else {
            vec.push_back(str);
        }
    }
    
    if (vec.empty()) return "/";
    
    string ret;
    for (auto& str : vec) {
        ret += ("/" + str);
    }
    return ret;
}