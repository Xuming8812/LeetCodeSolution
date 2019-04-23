#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 2^31 - 1.
*/ 
    

/**
 * @param num: a non-negative integer
 * @return: english words representation
 */
string numberToWords(int num) {
    // Write your code here
    
    if(num == 0){
        return "Zero";
    }
    
    string result = covertThousand(num%1000);
    
    vector<string> v3 = {"Thousand","Million","Billion"};
    
    for(int i = 0;i<3;i++){
        num = num/1000;
        
        if(num%1000!=0){
            result =  covertThousand(num%1000) + " "+v3[i] +" "+ result;
        }
    }
    
    while(result.back() == ' '){
        result.pop_back();
    }
    
    return result;
    
}

string covertThousand(int num){
    vector<string> v1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> v2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    //get hundreds
    int hundred = num/100;
    //get tens and bits
    int ten = num % 100;
    //get unit bits
    int bit = num % 10;
    
    string result;
    
    if(ten<20){
        result = v1[ten];
    }
    else{
        if(bit){
            result = v2[ten/10] + " " + v1[bit];
        }
        else{
            result = v2[ten/10];
        }
    }
    
    if(hundred!=0){
        if(result.empty()){
            result = v1[hundred] +" Hundred";
        }
        else{
            result = v1[hundred] + " Hundred" + " " + result;
        }
    }
    
    return result;
}