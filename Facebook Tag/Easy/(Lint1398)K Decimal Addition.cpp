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
Give k, a, b, which means a and b are all k base numbers, and output a + b.
*/

/**
 * @param k: The k
 * @param a: The A
 * @param b: The B
 * @return: The answer
 */
string addition(int k, string &a, string &b) {
    // Write your code here
    string result;
    
    //corner case
    if(a.empty()){
        return b;
    }
    
    if(b.empty()){
        return a;
    }

    //deal with leading zeros of string a
    int index = 0;
    while(index<a.size()-1 && a[index] == '0'){
        index++;
    }
    a = a.substr(index);
    
    //deal with leading zeros of string B
    index = 0;
    while(index<b.size()-1 && b[index] == '0'){
        index++;
    }
    b = b.substr(index);        
    
    //the carry number
    int carry = 0;
    int indexA = a.size()-1,indexB = b.size()-1;
    
    while(indexA>=0 || indexB>=0){
        //if the current digit doesn`t exist, replace it by zero
        int numA = indexA>=0?(a[indexA--]-'0'):0;
        int numB = indexB>=0?(b[indexB--]-'0'):0;
        
        int sum = numA+numB+carry;
        //update carry
        carry = sum/k;
        //update result
        result = to_string(sum%k)+result;
        
        
    }
    //see whether carry is non-zero after all calculation
    if(carry!=0){
        result = to_string(carry)+result;
    }
    
    return result;
}