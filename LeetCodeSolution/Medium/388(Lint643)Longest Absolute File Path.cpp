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
Suppose we abstract our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string

"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2. 
subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. 
subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system. 
For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext",
 and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path 
to file in the abstracted file system. If there is no file in the system, return 0.
*/




/**
 * @param input: an abstract file system
 * @return: return the length of the longest absolute path to file
 */
int lengthLongestPath(string &input) {
    // write your code here
    int result = 0;
    //use a stringstream to split the path by '\n'
    stringstream ss(input);
    //use a map to store the max length of a si
    unordered_map<int, int> m{{0, 0}};
    
    string line = "";
    //read in the path, 
    while (getline(ss, line)) {
        //get the level of path
        int level = line.find_last_of('\t') + 1;
        //get the size of this part of path
        int len = line.substr(level).size();
        //see if this part of part is file name
        if (line.find('.') != string::npos) {
            result = max(result, m[level] + len);
        } else {
            m[level + 1] = m[level] + len + 1;
        }
    }
    return res;
}