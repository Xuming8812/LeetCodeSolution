#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

/*
Given a non-negative integer. You could choose to swap two digits of it. Return the maximum valued number you could get
*/

/**
 * @param num: a non-negative intege
 * @return: the maximum valued number
 */
int maximumSwap(int num) {
    // Write your code here
    
    //get all digits
    vector<int> digits = split(num);
    //get length of digits
    int length = digits.size();
    
    //loop from high digit to low digit
    for(int i = length-1;i>=0;i--){
        //initialize the max value and its index
        int maxDigit = digits[i];
        int maxIndex = -1;
        
        //loop from low to high to find the largest digit
        for(int j = 0;j<i;j++){
            if(digits[j]>maxDigit){
                maxDigit = digits[j];
                maxIndex = j;
            }
        }
        
        //if the largest digit is bigger than the current digit, then swap them 
        if(maxDigit!=digits[i]){
            //swap
            swap(digits[i],digits[maxIndex]);
            //get the number after swap
            int result{0};
            //loop all digits and make the number
            while(!digits.empty()){
                result = result*10 + digits.back();
                digits.pop_back();
            }  
            
            return result;
        }
    }
    //if can`t swap just return the original number
    return num;
    
}

//the helper function to get all digits of a num and store them in a vector
vector<int> split(int num){
    vector<int> result;
    
    while(num){
        result.push_back(num%10);
        num = num/10;
    }
    
    return result;
}