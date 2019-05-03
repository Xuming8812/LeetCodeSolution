#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<unordered_map>

using namespace std;

/*
Given two strings representing two [complex numbers].

You need to return a string representing their multiplication. Note i^2 = -1 according to the definition.
*/     
    
/**
 * @param a: a string
 * @param b: a string
 * @return: a string representing their multiplication
 */
string complexNumberMultiply(string &a, string &b) {
    // Write your code here
    string result;
    
    if(a.empty() || b.empty()){
        return result;
    }
    
    vector<int> num1 = getNumber(a);
    vector<int> num2 = getNumber(b);
    
    result = to_string(num1[0]*num2[0]-num1[1]*num2[1])+"+"+to_string(num1[0]*num2[1]+num1[1]*num2[0])+"i";
    
    return result;
}

vector<int> getNumber(string& input){
    
    int index = 0;
    
    while(index<input.size()){
        if(input[index] == '+'){
            break;
        }
        
        index++;
    }
    
    int real = stoi(input.substr(0,index));
    string temp = input.substr(index+1);
    int imag = stoi(temp.substr(0,temp.size()-1));
    
    return {real,imag};
    
}
