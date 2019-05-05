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
Given a collection of intervals, merge all overlapping intervals.
*/

/**
 * @param str: a string containing uppercase alphabets and integer digits
 * @return: the alphabets in the order followed by the sum of digits
 */
string rearrange(string &str) {
    // Write your code here

    int sum=0;
    
    string result;
    //loop each element to check 
    for(int i = 0;i<str.size();i++){
        if(isdigit(str[i])){
            sum +=str[i]-'0';
        }
        else{
            result = result+string(1,str[i]);
        }
    }
    //sort the letter part
    sort(result.begin(),result.end());
    //add the number part
    if(sum!=0){
        result = result + to_string(sum);
    }
    
    return result;
}