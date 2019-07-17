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
You are given a string representing an attendance record for a student. The record only contains the following three characters:

'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.
*/  


/**
 * @param s: a string
 * @return: whether the student could be rewarded according to his attendance record
 */
bool checkRecord(string &s) {
    // Write your code here
    int count{0};
    for(int i = 0;i<s.size();i++){
        //count the number of 'A'
        if(s[i]=='A'){
            count++;
        }
        //see if the number of continous "L"
        if(s[i]=='L'){
            if(i+2<s.size()&&s[i+1]=='L'&&s[i+2]=='L'){
                return false;
            }
        }
    }
    
    return count<=1;
}