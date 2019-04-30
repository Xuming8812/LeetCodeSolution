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
Given a digit string excluded '0' and '1', return all possible letter combinations that the number could represent.
*/    
    
/**
 * @param digits: A digital string
 * @return: all posible letter combinations
 */
vector<string> letterCombinations(string &digits) {
    // write your code here
    
    if(digits.empty()){
        return result;
    }
    
    string temp;
    
    helper(digits,temp,0);
    
    return result;
}

vector<string> result;

map<char,string> dict{{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};

void helper(string &digits, string& current, int index){
    if(index == digits.size()){
        result.push_back(current);
        return;
    }
    
    for(auto item : dict[digits[index]]){
        current = current + string(1,item);
        
        helper(digits, current, index+1);
        
        current = current.substr(0,current.size()-1);
    }
}