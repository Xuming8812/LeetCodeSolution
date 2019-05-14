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
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2
*/

/**
 * @param num1: a non-negative integers
 * @param num2: a non-negative integers
 * @return: return product of num1 and num2
 */
string multiply(string &num1, string &num2) {
    // write your code here

    string result;

    //corner case
    if (num1.empty() || num2.empty()){
        return result;
    }
    //get length of both vectors
    int len1 = num1.size(), len2 = num2.size();
    //get digits for both vectors
    vector<int> num1Store(num1.size(), 0);
    vector<int> num2Store(num2.size(), 0);

    for (int i = 0; i < len1; i++){
        num1Store[i] = num1[len1 - 1 - i] - '0';
    }

    for (int i = 0; i < len2; i++){
        num2Store[i] = num2[len2 - 1 - i] - '0';
    }
    //initialize a vector to store the result
    vector<int> multiply(len1 + len2, 0);
    //calculate the multiply result
    for (int i = 0; i < len1; i++){
        for (int j = 0; j < len2; j++){
            multiply[i + j] += num1Store[i] * num2Store[j];
        }
    }
    //calculate the carry together
    int carry{ 0 };
    for (int i = 0; i < multiply.size(); i++){
        int temp = multiply[i] + carry;
        carry = temp / 10;
        multiply[i] = temp % 10;
    }
    //if there is carry left
    if (carry != 0){
        multiply.push_back(carry);
    }
    //remove all leading zeroes, if any
    while(multiply.size()>1 &&multiply[multiply.size() - 1] == 0){
        multiply.pop_back();
    }

    //turn the vector to string
    for (int i = 0; i < multiply.size(); i++){
        result = to_string(multiply[i]) + result;
    }

    return result;
}