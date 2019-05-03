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
Solve a given equation and return the value of x in the form of string "x=#value". The equation contains only '+', '-' operation, the variable x and its coefficient.

If there is no solution for the equation, return "No solution".
If there are infinite solutions for the equation, return "Infinite solutions".
If there is exactly one solution for the equation, we ensure that the value of x is an integer.
*/   

/**
 * @param equation: a string
 * @return: return a string
 */
string solveEquation(string &equation) {
    // write your code here

    if(equation.empty()){
        return "";
    }
    
    int index = 0;
    int length = equation.size();
    
    while(index<length){
        if(equation[index] == '='){
            break;
        }
        
        index++;
    }
    
    string left = equation.substr(0,index);
    string right = equation.substr(index+1);
    
    vector<int> leftEquation = getValue(left);
    vector<int> rightEquation = getValue(right);
    
    if(leftEquation[0] == rightEquation[0] && leftEquation[1] != rightEquation[1]){
        return "No solution";
    }
    
    if(leftEquation[0] == rightEquation[0] && leftEquation[1] == rightEquation[1]){
        return "Infinite solutions";
    }
    
    int xCoff = leftEquation[0] - rightEquation[0];
    int b = rightEquation[1]-leftEquation[1];
    
    return "x="+to_string(b/xCoff);
}

vector<int> getValue(string input){
    int xCoff=0,sum = 0, num=0, sign = 1;
    
    for(int i = 0;i<input.size();i++){
        if(isNum(input[i])){
            num = num * 10 + input[i] - '0';
        }
        else if(input[i] == 'x'){
            if(num == 0){
                xCoff += sign;
            }
            else{
                xCoff += sign*num;
                num = 0;
            }
        }
        else{
            sum += sign * num;
            num = 0;
            
            sign = input[i] == '+'?1:-1;
        }
    }
    sum += sign * num;
    
    return {xCoff,sum};
}


bool isNum(char c){

    return c>='0'&&c<='9';
}