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
Give you an array of n email addresses.
Find the number of email groups and each group should have more than one email address(the address can be duplicated). 
If two strings have the same value after being transformed, they are in the same group.

The rules of transforming are as follows:

Ignore all the characters '.' before the character '@'.
Ignore the substring which starts with the first '+'(included) and ends with the character '@'(exclude).
*/  



/**
 * @param emails: Original email
 * @return: Return the count of groups which has more than one email address in it.
 */
int countGroups(vector<string> &emails) {
    // Write your code here
    map<string,int> group;
    //store the transformed email
    for(auto item : emails){
        group[transform(item)]++;
    }
    int result{0};
    //see the number of groups
    for(auto item : group){
        if(item.second>1){
            result++;
        }
    }
    return result;
}
//helper function to transform the email
string transform(string email){
    string result;
    
    int index = 0;
    
    while(index < email.size()){
        //find the @
        if(email[index] == '@'){
            break;
        }
        //skip .
        if(email[index]=='.'){
            index++;
            continue;
        }
        //skip the substring start with '+'
        if(email[index]=='+'){
            while(++index<email.size()&&email[index] != '@'){
                
            }
            break;
        }
        //store the transformed part
        result = result + email[index++];
    }
    //store the latter part
    for(int i = index;i<email.size();i++){
        result+=email[i];
    }
    
    return result;
}